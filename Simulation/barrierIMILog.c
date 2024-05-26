/* $Date:  2017, I am back baby$
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: barrierIMILog.c
 *
 * Abstract: Barrier Lyapunov based adaptive controller 
 *            with logaritmic gain 
 *
 *
 * Copyright 2017-inf Erkan Zergeroglu.
 * $Revision: 0.99 $
 */
 
#define S_FUNCTION_NAME  barrierIMILog
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include <math.h>

#define NPARAMS            3
#define CONTROLGAIN(S)     ssGetSFcnParam(S, 0)
#define ALPHA(S)           ssGetSFcnParam(S, 1)
#define KeGAINS(S)         ssGetSFcnParam(S, 2)
#define Deg2Rad            0.017453292519943
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
ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters. */

#if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
		if (ssGetErrorStatus(S) != NULL) {
          return;   
       }
    } else {
       return; /* Parameter mismatch will be reported by Simulink */
    }
#endif

/* None of this s-functions's parameters are tunable during simulation */
 {
       int_T i;
       for (i=0; i < NPARAMS; i++) {
        ssSetSFcnParamNotTunable(S, i);
        }
  }


// input port information
    if (!ssSetNumInputPorts(S, 4)) return;
     ssSetInputPortDirectFeedThrough(S, 0, 1);
     ssSetInputPortWidth(S, 0, 4);  // qPtr 

     ssSetInputPortDirectFeedThrough(S, 1, 1);
	 ssSetInputPortWidth(S, 1, 6);  // qdPtr

	 ssSetInputPortDirectFeedThrough(S, 2, 1);
	 ssSetInputPortWidth(S, 2, 5);  // phPtr

     ssSetInputPortDirectFeedThrough(S, 3, 1);
     ssSetInputPortWidth(S, 3, 5);  // phGainPtr 
     // (adaptaion gains can be changed during the simulation ) 
	
// output port information	
    if (!ssSetNumOutputPorts(S, 4)) return;
	
    ssSetOutputPortWidth(S, 0, 2); // Tau Control output
	ssSetOutputPortWidth(S, 1, 5); // derivatives of parameter estimates
    ssSetOutputPortWidth(S, 2, 2); // Error signal
    ssSetOutputPortWidth(S, 3, 2); // Constraint gains

    
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
    InputRealPtrsType qPtr = ssGetInputPortRealSignalPtrs(S,0); 
    InputRealPtrsType qdPtr = ssGetInputPortRealSignalPtrs(S,1);  
	InputRealPtrsType thCapPtr = ssGetInputPortRealSignalPtrs(S,2);  
	InputRealPtrsType GammaPtr = ssGetInputPortRealSignalPtrs(S,3);  
	
	// output channels
    real_T   *tau      = ssGetOutputPortRealSignal(S,0); 
	real_T   *dthCap   = ssGetOutputPortRealSignal(S,1); 
    real_T   *e        = ssGetOutputPortRealSignal(S,2); 
    real_T   *constG   = ssGetOutputPortRealSignal(S,3); 

    
    const real_T      *Kr       = mxGetPr(CONTROLGAIN(S)); //2x1
	const real_T      *alpha    = mxGetPr(ALPHA(S));   //2x1
    const real_T      *Ke       = mxGetPr(KeGAINS(S)); //2x1

// tempapory variables
    real_T   q1, q2, q1dot, q2dot;
	real_T   qd1, qd2, qdotd1, qdotd2;
	real_T   qddotd1, qddotd2;

	real_T  Yd11, Yd12, Yd13, Yd14, Yd15 ; 
	real_T  Yd21, Yd22, Yd23, Yd24, Yd25 ;
    real_T  th1, th2, th3, th4, th5; 
    real_T  e1,  e2,  e1dot, e2dot, r1, r2;
    real_T  gamma[5];
    real_T deltaE1, deltaE2, ke1, ke2;
    

// assing the parameters comming from the input channels
   q1    = (*qPtr[0]);
   q2    = (*qPtr[1]);
   q1dot = (*qPtr[2]);
   q2dot = (*qPtr[3]);

   qd1     = (*qdPtr[0]);
   qd2     = (*qdPtr[1]);
   qdotd1  = (*qdPtr[2]);
   qdotd2  = (*qdPtr[3]);
   qddotd1 = (*qdPtr[4]);
   qddotd2 = (*qdPtr[5]);
  
   th1  = (*thCapPtr[0]);
   th2  = (*thCapPtr[1]);
   th3  = (*thCapPtr[2]);
   th4  = (*thCapPtr[3]);
   th5  = (*thCapPtr[4]);
   
   gamma[0] = (*GammaPtr[0]);
   gamma[1] = (*GammaPtr[1]);
   gamma[2] = (*GammaPtr[2]);
   gamma[3] = (*GammaPtr[3]);
   gamma[4] = (*GammaPtr[4]);
               
// error 
    e1 = qd1 - q1 ;
	e2 = qd2 - q2 ;
	e1dot = qdotd1 - q1dot ;
	e2dot = qdotd2 - q2dot ;

	r1 = e1dot+alpha[0]*(e1) ;
	r2 = e2dot+alpha[1]*(e2) ;

// calculate the regression matrix Yd

   Yd11 = qddotd1;
   Yd12 = qddotd2;
   Yd13 = 2*cos(qd2)*qddotd1 + cos(qd2)*qddotd2
         -sin(qd2)*((qdotd1*qdotd2)+((qdotd1+qdotd2)*qdotd2)) ;
   Yd14 = qdotd1 ;
   Yd15 = 0 ;

   Yd21 = 0 ;
   Yd22 = qddotd1 + qddotd2;
   Yd23 = cos(qd2)*qddotd1 + sin(qd2)*qdotd1*qdotd1;
   Yd24 = 0 ;
   Yd25 = qdotd2; 
   
   deltaE1 = 10 * Deg2Rad;
   deltaE2 = 10 * Deg2Rad;
   
   ke1 = Ke[0] / (deltaE1*deltaE1 - e1*e1);
   ke2 = Ke[1] / (deltaE2*deltaE2 - e2*e2);
   
   // output channel 4
   constG[0] = ke1;
   constG[1] = ke2;

   // output channel 3
   e[0] = e1;
   e[1] = e2;
   
   // output channel 2
   dthCap[0] = gamma[0]*(Yd11*r1+Yd21*r2);
   dthCap[1] = gamma[1]*(Yd12*r1+Yd22*r2);
   dthCap[2] = gamma[2]*(Yd13*r1+Yd23*r2);
   dthCap[3] = gamma[3]*(Yd14*r1+Yd24*r2);
   dthCap[4] = gamma[4]*(Yd15*r1+Yd25*r2);
   
   //output channel 1
   tau[0] = (Yd11*th1+Yd12*th2+Yd13*th3+Yd14*th4+Yd15*th5) + Kr[0]*r1 + ke1*e1;
   tau[1] = (Yd21*th1+Yd22*th2+Yd23*th3+Yd24*th4+Yd25*th5) + Kr[1]*r2 + ke2*e2;

       
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