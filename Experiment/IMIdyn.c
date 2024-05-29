#define S_FUNCTION_NAME  IMIdyn
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include <math.h>


/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{

// input port information
    if (!ssSetNumInputPorts(S, 3)) return;

	ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortWidth(S, 0, 2);  // q 

    ssSetInputPortDirectFeedThrough(S, 1, 1);
	ssSetInputPortWidth(S, 1, 2);  // dq

	ssSetInputPortDirectFeedThrough(S, 2, 1);
	ssSetInputPortWidth(S, 2, 2);  // Tau

	
// output port information	
    if (!ssSetNumOutputPorts(S,1)) return;
	
    ssSetOutputPortWidth(S, 0, 2); // qdoubledot
    ssSetNumSampleTimes(S, 1);
    
     /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE));

} /* end mdlInitializeSizes */


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    S-function is comprised of only continuous sample time elements
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}


/* Function: mdlOutputs =======================================================
 * Abstract:
 *      calculate the kinematic control output v(t) from the 
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    
	// input channels 
    InputRealPtrsType posPtr = ssGetInputPortRealSignalPtrs(S,0); 
    InputRealPtrsType velPtr = ssGetInputPortRealSignalPtrs(S,1);  
	InputRealPtrsType tauPtr = ssGetInputPortRealSignalPtrs(S,2);  
	

	
    real_T   *qdoubledot     = ssGetOutputPortRealSignal(S,0); 
    
    
// tempapory variables
    real_T  p1, p2, p3, fd1, fd2;
    real_T m11, m22, m12, mdelta, Vm11, Vm12, Vm21, Vm22;
    real_T q1, q2, dq1, dq2, tau1, tau2;
    real_T N1, N2;

 
        p1 = 3.473;
        p2 = 0.193;
        p3 = 0.242;

        fd1 = 5.3;
        fd2 = 1.1;
	

// assing the parameters comming from the input channels
   q1  = (*posPtr[0]);
   q2  = (*posPtr[1]);
   
   dq1 = (*velPtr[0]);
   dq2 = (*velPtr[1]);

   tau1  = (*tauPtr[0]);
   tau2  = (*tauPtr[1]);
   
       /* System Equation for Two Link Robot
        * Inertia Matrix
        */
        
        m11 = p1 + 2*p3*cos(q2); 
        m12 = p2 + p3*cos(q2);
        m22 = p2;
        mdelta = m11*m22 - m12*m12;

        /* Coriolis and centripedal matrix
        */
        Vm11 =-p3*sin(q2)*dq2;
        Vm12 =-p3*sin(q2)*(dq1 +dq2);
        Vm21 = p3*sin(q2)*dq1;
        Vm22 = 0;
        
        N1 = tau1 - (Vm11*dq1 + Vm12*dq2) - (fd1*dq1); 
        N2 = tau2 - (Vm21*dq1 + Vm22*dq2) - (fd2*dq2);
 
    //output channel
	qdoubledot[0] = (m22*N1 - m12*N2)/mdelta;
	qdoubledot[1] = (m11*N2 - m12*N1)/mdelta;

         
}

   
/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)
{

}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif



/* END function Outher Loop Control */