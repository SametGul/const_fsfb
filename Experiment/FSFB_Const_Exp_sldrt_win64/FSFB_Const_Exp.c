/*
 * FSFB_Const_Exp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FSFB_Const_Exp".
 *
 * Model version              : 6.6
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Feb 10 13:23:33 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FSFB_Const_Exp.h"
#include "FSFB_Const_Exp_private.h"
#include "FSFB_Const_Exp_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  256000.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 2U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_FSFB_Const_Exp_T FSFB_Const_Exp_B;

/* Continuous states */
X_FSFB_Const_Exp_T FSFB_Const_Exp_X;

/* Block states (default storage) */
DW_FSFB_Const_Exp_T FSFB_Const_Exp_DW;

/* Real-time model */
static RT_MODEL_FSFB_Const_Exp_T FSFB_Const_Exp_M_;
RT_MODEL_FSFB_Const_Exp_T *const FSFB_Const_Exp_M = &FSFB_Const_Exp_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  FSFB_Const_Exp_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void FSFB_Const_Exp_output(void)
{
  real_T (*lastU)[2];
  real_T Fcn_tmp;
  real_T Fcn_tmp_0;
  real_T rtb_Gain_tmp;
  int32_T i;
  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
    /* set solver stop time */
    if (!(FSFB_Const_Exp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&FSFB_Const_Exp_M->solverInfo,
                            ((FSFB_Const_Exp_M->Timing.clockTickH0 + 1) *
        FSFB_Const_Exp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&FSFB_Const_Exp_M->solverInfo,
                            ((FSFB_Const_Exp_M->Timing.clockTick0 + 1) *
        FSFB_Const_Exp_M->Timing.stepSize0 +
        FSFB_Const_Exp_M->Timing.clockTickH0 *
        FSFB_Const_Exp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(FSFB_Const_Exp_M)) {
    FSFB_Const_Exp_M->Timing.t[0] = rtsiGetT(&FSFB_Const_Exp_M->solverInfo);
  }

  /* S-Function (sldrtpi): '<S3>/Packet Input' */
  /* S-Function Block: <S3>/Packet Input */
  {
    uint8_T indata[4U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 4U,
      &FSFB_Const_Exp_P.PacketInput_PacketID, (double*) indata, NULL);
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;
      FSFB_Const_Exp_B.PacketInput[0] = *indp.p_int16_T++;
      FSFB_Const_Exp_B.PacketInput[1] = *indp.p_int16_T++;
    }
  }

  /* TransferFcn: '<S6>/filter1' */
  FSFB_Const_Exp_B.filter1 = 0.0;
  FSFB_Const_Exp_B.filter1 += FSFB_Const_Exp_P.filter1_C[0] *
    FSFB_Const_Exp_X.filter1_CSTATE[0];
  FSFB_Const_Exp_B.filter1 += FSFB_Const_Exp_P.filter1_C[1] *
    FSFB_Const_Exp_X.filter1_CSTATE[1];

  /* Gain: '<S3>/Gain' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  FSFB_Const_Exp_B.Gain = FSFB_Const_Exp_P.Gain_Gain * (real_T)
    FSFB_Const_Exp_B.PacketInput[0];

  /* Gain: '<S3>/Gain1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  FSFB_Const_Exp_B.Gain1 = FSFB_Const_Exp_P.Gain1_Gain * (real_T)
    FSFB_Const_Exp_B.PacketInput[1];

  /* TransferFcn: '<S6>/filter2' */
  FSFB_Const_Exp_B.filter2 = 0.0;
  FSFB_Const_Exp_B.filter2 += FSFB_Const_Exp_P.filter2_C[0] *
    FSFB_Const_Exp_X.filter2_CSTATE[0];
  FSFB_Const_Exp_B.filter2 += FSFB_Const_Exp_P.filter2_C[1] *
    FSFB_Const_Exp_X.filter2_CSTATE[1];

  /* Clock: '<S5>/Clock' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Derivative: '<S5>/Derivative1'
   *  Derivative: '<S6>/Derivative'
   */
  rtb_Gain_tmp = FSFB_Const_Exp_M->Timing.t[0];

  /* Fcn: '<S5>/Fcn' incorporates:
   *  Clock: '<S5>/Clock'
   *  Fcn: '<S5>/Fcn1'
   */
  Fcn_tmp = sin(rtb_Gain_tmp);
  Fcn_tmp_0 = 1.0 - exp(-0.3 * rtb_Gain_tmp * rtb_Gain_tmp * rtb_Gain_tmp);

  /* Fcn: '<S5>/Fcn' */
  FSFB_Const_Exp_B.Fcn = Fcn_tmp_0 * (0.7 * Fcn_tmp);

  /* Fcn: '<S5>/Fcn1' */
  FSFB_Const_Exp_B.Fcn1 = Fcn_tmp_0 * (1.2 * Fcn_tmp);

  /* Derivative: '<S5>/Derivative' */
  if ((FSFB_Const_Exp_DW.TimeStampA >= rtb_Gain_tmp) &&
      (FSFB_Const_Exp_DW.TimeStampB >= rtb_Gain_tmp)) {
    /* Derivative: '<S5>/Derivative' */
    FSFB_Const_Exp_B.Derivative[0] = 0.0;
    FSFB_Const_Exp_B.Derivative[1] = 0.0;
  } else {
    Fcn_tmp = FSFB_Const_Exp_DW.TimeStampA;
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA;
    if (FSFB_Const_Exp_DW.TimeStampA < FSFB_Const_Exp_DW.TimeStampB) {
      if (FSFB_Const_Exp_DW.TimeStampB < rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB;
      }
    } else {
      if (FSFB_Const_Exp_DW.TimeStampA >= rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB;
      }
    }

    Fcn_tmp = rtb_Gain_tmp - Fcn_tmp;

    /* Derivative: '<S5>/Derivative' */
    FSFB_Const_Exp_B.Derivative[0] = (FSFB_Const_Exp_B.Fcn - (*lastU)[0]) /
      Fcn_tmp;
    FSFB_Const_Exp_B.Derivative[1] = (FSFB_Const_Exp_B.Fcn1 - (*lastU)[1]) /
      Fcn_tmp;
  }

  /* Derivative: '<S5>/Derivative1' */
  if ((FSFB_Const_Exp_DW.TimeStampA_a >= rtb_Gain_tmp) &&
      (FSFB_Const_Exp_DW.TimeStampB_i >= rtb_Gain_tmp)) {
    /* Derivative: '<S5>/Derivative1' */
    FSFB_Const_Exp_B.Derivative1[0] = 0.0;
    FSFB_Const_Exp_B.Derivative1[1] = 0.0;
  } else {
    Fcn_tmp = FSFB_Const_Exp_DW.TimeStampA_a;
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_c;
    if (FSFB_Const_Exp_DW.TimeStampA_a < FSFB_Const_Exp_DW.TimeStampB_i) {
      if (FSFB_Const_Exp_DW.TimeStampB_i < rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB_i;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_p;
      }
    } else {
      if (FSFB_Const_Exp_DW.TimeStampA_a >= rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB_i;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_p;
      }
    }

    Fcn_tmp = rtb_Gain_tmp - Fcn_tmp;

    /* Derivative: '<S5>/Derivative1' */
    FSFB_Const_Exp_B.Derivative1[0] = (FSFB_Const_Exp_B.Derivative[0] - (*lastU)
      [0]) / Fcn_tmp;
    FSFB_Const_Exp_B.Derivative1[1] = (FSFB_Const_Exp_B.Derivative[1] - (*lastU)
      [1]) / Fcn_tmp;
  }

  for (i = 0; i < 5; i++) {
    /* Integrator: '<S1>/Integrator' */
    FSFB_Const_Exp_B.Integrator[i] = FSFB_Const_Exp_X.Integrator_CSTATE[i];
  }

  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
    /* Constant: '<S4>/Constant' */
    FSFB_Const_Exp_B.Constant = FSFB_Const_Exp_P.Constant_Value;

    /* Constant: '<S4>/Constant1' */
    FSFB_Const_Exp_B.Constant1 = FSFB_Const_Exp_P.Constant1_Value;

    /* Constant: '<S4>/Constant2' */
    FSFB_Const_Exp_B.Constant2 = FSFB_Const_Exp_P.Constant2_Value;

    /* Constant: '<S4>/Constant3' */
    FSFB_Const_Exp_B.Constant3 = FSFB_Const_Exp_P.Constant3_Value;

    /* Constant: '<S4>/Constant4' */
    FSFB_Const_Exp_B.Constant4 = FSFB_Const_Exp_P.Constant4_Value;
  }

  /* S-Function (barrierIMILog): '<S1>/adaptive  controller' */

  /* Level2 S-Function Block: '<S1>/adaptive  controller' (barrierIMILog) */
  {
    SimStruct *rts = FSFB_Const_Exp_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Gain' */
  Fcn_tmp = FSFB_Const_Exp_P.Gain_Gain_k *
    FSFB_Const_Exp_B.adaptivecontroller_o1[0];

  /* Saturate: '<S2>/Saturation' */
  if (Fcn_tmp > FSFB_Const_Exp_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[0] = FSFB_Const_Exp_P.Saturation_UpperSat;
  } else if (Fcn_tmp < FSFB_Const_Exp_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[0] = FSFB_Const_Exp_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[0] = Fcn_tmp;
  }

  /* Gain: '<S2>/Gain2' */
  Fcn_tmp = FSFB_Const_Exp_P.Gain2_Gain *
    FSFB_Const_Exp_B.adaptivecontroller_o1[1];

  /* Saturate: '<S2>/Saturation' */
  if (Fcn_tmp > FSFB_Const_Exp_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[1] = FSFB_Const_Exp_P.Saturation_UpperSat;
  } else if (Fcn_tmp < FSFB_Const_Exp_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[1] = FSFB_Const_Exp_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    FSFB_Const_Exp_B.Saturation[1] = Fcn_tmp;
  }

  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
  }

  /* Sum: '<Root>/Sum' */
  FSFB_Const_Exp_B.e[0] = FSFB_Const_Exp_B.Fcn - FSFB_Const_Exp_B.Gain;
  FSFB_Const_Exp_B.e[1] = FSFB_Const_Exp_B.Fcn1 - FSFB_Const_Exp_B.Gain1;

  /* Gain: '<Root>/RadToDeg' */
  FSFB_Const_Exp_B.RadToDeg[0] = FSFB_Const_Exp_P.RadToDeg_Gain *
    FSFB_Const_Exp_B.adaptivecontroller_o3[0];
  FSFB_Const_Exp_B.RadToDeg[1] = FSFB_Const_Exp_P.RadToDeg_Gain *
    FSFB_Const_Exp_B.adaptivecontroller_o3[1];
  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
  }

  /* Sum: '<Root>/Sum1' */
  FSFB_Const_Exp_B.edot[0] = FSFB_Const_Exp_B.Derivative[0] -
    FSFB_Const_Exp_B.filter1;
  FSFB_Const_Exp_B.edot[1] = FSFB_Const_Exp_B.Derivative[1] -
    FSFB_Const_Exp_B.filter2;
  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
    /* S-Function (sldrtpo): '<S2>/Packet Output' */
    /* S-Function Block: <S2>/Packet Output */

    /* no code required */
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Gain1'
   */
  Fcn_tmp = floor(FSFB_Const_Exp_P.Gain1_Gain_k * FSFB_Const_Exp_B.Saturation[0]
                  + FSFB_Const_Exp_P.Constant_Value_k);
  if (rtIsNaN(Fcn_tmp) || rtIsInf(Fcn_tmp)) {
    Fcn_tmp = 0.0;
  } else {
    Fcn_tmp = fmod(Fcn_tmp, 65536.0);
  }

  /* Sum: '<S2>/Add' */
  FSFB_Const_Exp_B.Add[0] = (uint16_T)(Fcn_tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-Fcn_tmp : (int32_T)(uint16_T)Fcn_tmp);

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Gain1'
   */
  Fcn_tmp = floor(FSFB_Const_Exp_P.Gain1_Gain_k * FSFB_Const_Exp_B.Saturation[1]
                  + FSFB_Const_Exp_P.Constant_Value_k);
  if (rtIsNaN(Fcn_tmp) || rtIsInf(Fcn_tmp)) {
    Fcn_tmp = 0.0;
  } else {
    Fcn_tmp = fmod(Fcn_tmp, 65536.0);
  }

  /* Sum: '<S2>/Add' */
  FSFB_Const_Exp_B.Add[1] = (uint16_T)(Fcn_tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-Fcn_tmp : (int32_T)(uint16_T)Fcn_tmp);

  /* Derivative: '<S6>/Derivative' */
  if ((FSFB_Const_Exp_DW.TimeStampA_n >= rtb_Gain_tmp) &&
      (FSFB_Const_Exp_DW.TimeStampB_c >= rtb_Gain_tmp)) {
    /* Derivative: '<S6>/Derivative' */
    FSFB_Const_Exp_B.qdot[0] = 0.0;
    FSFB_Const_Exp_B.qdot[1] = 0.0;
  } else {
    Fcn_tmp = FSFB_Const_Exp_DW.TimeStampA_n;
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_e;
    if (FSFB_Const_Exp_DW.TimeStampA_n < FSFB_Const_Exp_DW.TimeStampB_c) {
      if (FSFB_Const_Exp_DW.TimeStampB_c < rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB_c;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_f;
      }
    } else {
      if (FSFB_Const_Exp_DW.TimeStampA_n >= rtb_Gain_tmp) {
        Fcn_tmp = FSFB_Const_Exp_DW.TimeStampB_c;
        lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_f;
      }
    }

    Fcn_tmp = rtb_Gain_tmp - Fcn_tmp;

    /* Derivative: '<S6>/Derivative' */
    FSFB_Const_Exp_B.qdot[0] = (FSFB_Const_Exp_B.Gain - (*lastU)[0]) / Fcn_tmp;
    FSFB_Const_Exp_B.qdot[1] = (FSFB_Const_Exp_B.Gain1 - (*lastU)[1]) / Fcn_tmp;
  }
}

/* Model update function */
void FSFB_Const_Exp_update(void)
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<S5>/Derivative' */
  if (FSFB_Const_Exp_DW.TimeStampA == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampA = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA;
  } else if (FSFB_Const_Exp_DW.TimeStampB == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampB = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB;
  } else if (FSFB_Const_Exp_DW.TimeStampA < FSFB_Const_Exp_DW.TimeStampB) {
    FSFB_Const_Exp_DW.TimeStampA = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA;
  } else {
    FSFB_Const_Exp_DW.TimeStampB = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB;
  }

  (*lastU)[0] = FSFB_Const_Exp_B.Fcn;
  (*lastU)[1] = FSFB_Const_Exp_B.Fcn1;

  /* End of Update for Derivative: '<S5>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative1' */
  if (FSFB_Const_Exp_DW.TimeStampA_a == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampA_a = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_c;
  } else if (FSFB_Const_Exp_DW.TimeStampB_i == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampB_i = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_p;
  } else if (FSFB_Const_Exp_DW.TimeStampA_a < FSFB_Const_Exp_DW.TimeStampB_i) {
    FSFB_Const_Exp_DW.TimeStampA_a = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_c;
  } else {
    FSFB_Const_Exp_DW.TimeStampB_i = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_p;
  }

  (*lastU)[0] = FSFB_Const_Exp_B.Derivative[0];
  (*lastU)[1] = FSFB_Const_Exp_B.Derivative[1];

  /* End of Update for Derivative: '<S5>/Derivative1' */
  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
    /* Update for S-Function (sldrtpo): '<S2>/Packet Output' */

    /* S-Function Block: <S2>/Packet Output */
    {
      uint8_T outdata[4U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        uint16_T pktout = FSFB_Const_Exp_B.Add[0];
        *outdp.p_uint16_T++ = pktout;
      }

      {
        uint16_T pktout = FSFB_Const_Exp_B.Add[1];
        *outdp.p_uint16_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 4U,
                     &FSFB_Const_Exp_P.PacketOutput_PacketID, (double*) outdata,
                     NULL);
    }
  }

  /* Update for Derivative: '<S6>/Derivative' */
  if (FSFB_Const_Exp_DW.TimeStampA_n == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampA_n = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_e;
  } else if (FSFB_Const_Exp_DW.TimeStampB_c == (rtInf)) {
    FSFB_Const_Exp_DW.TimeStampB_c = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_f;
  } else if (FSFB_Const_Exp_DW.TimeStampA_n < FSFB_Const_Exp_DW.TimeStampB_c) {
    FSFB_Const_Exp_DW.TimeStampA_n = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeA_e;
  } else {
    FSFB_Const_Exp_DW.TimeStampB_c = FSFB_Const_Exp_M->Timing.t[0];
    lastU = &FSFB_Const_Exp_DW.LastUAtTimeB_f;
  }

  (*lastU)[0] = FSFB_Const_Exp_B.Gain;
  (*lastU)[1] = FSFB_Const_Exp_B.Gain1;

  /* End of Update for Derivative: '<S6>/Derivative' */
  if (rtmIsMajorTimeStep(FSFB_Const_Exp_M)) {
    rt_ertODEUpdateContinuousStates(&FSFB_Const_Exp_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FSFB_Const_Exp_M->Timing.clockTick0)) {
    ++FSFB_Const_Exp_M->Timing.clockTickH0;
  }

  FSFB_Const_Exp_M->Timing.t[0] = rtsiGetSolverStopTime
    (&FSFB_Const_Exp_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++FSFB_Const_Exp_M->Timing.clockTick1)) {
      ++FSFB_Const_Exp_M->Timing.clockTickH1;
    }

    FSFB_Const_Exp_M->Timing.t[1] = FSFB_Const_Exp_M->Timing.clockTick1 *
      FSFB_Const_Exp_M->Timing.stepSize1 + FSFB_Const_Exp_M->Timing.clockTickH1 *
      FSFB_Const_Exp_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void FSFB_Const_Exp_derivatives(void)
{
  XDot_FSFB_Const_Exp_T *_rtXdot;
  int32_T i;
  _rtXdot = ((XDot_FSFB_Const_Exp_T *) FSFB_Const_Exp_M->derivs);

  /* Derivatives for TransferFcn: '<S6>/filter1' */
  _rtXdot->filter1_CSTATE[0] = 0.0;
  _rtXdot->filter1_CSTATE[0] += FSFB_Const_Exp_P.filter1_A[0] *
    FSFB_Const_Exp_X.filter1_CSTATE[0];
  _rtXdot->filter1_CSTATE[1] = 0.0;
  _rtXdot->filter1_CSTATE[0] += FSFB_Const_Exp_P.filter1_A[1] *
    FSFB_Const_Exp_X.filter1_CSTATE[1];
  _rtXdot->filter1_CSTATE[1] += FSFB_Const_Exp_X.filter1_CSTATE[0];
  _rtXdot->filter1_CSTATE[0] += FSFB_Const_Exp_B.qdot[0];

  /* Derivatives for TransferFcn: '<S6>/filter2' */
  _rtXdot->filter2_CSTATE[0] = 0.0;
  _rtXdot->filter2_CSTATE[0] += FSFB_Const_Exp_P.filter2_A[0] *
    FSFB_Const_Exp_X.filter2_CSTATE[0];
  _rtXdot->filter2_CSTATE[1] = 0.0;
  _rtXdot->filter2_CSTATE[0] += FSFB_Const_Exp_P.filter2_A[1] *
    FSFB_Const_Exp_X.filter2_CSTATE[1];
  _rtXdot->filter2_CSTATE[1] += FSFB_Const_Exp_X.filter2_CSTATE[0];
  _rtXdot->filter2_CSTATE[0] += FSFB_Const_Exp_B.qdot[1];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE[i] = FSFB_Const_Exp_B.adaptivecontroller_o2[i];
  }

  /* End of Derivatives for Integrator: '<S1>/Integrator' */
}

/* Model initialize function */
void FSFB_Const_Exp_initialize(void)
{
  /* Start for Constant: '<S4>/Constant' */
  FSFB_Const_Exp_B.Constant = FSFB_Const_Exp_P.Constant_Value;

  /* Start for Constant: '<S4>/Constant1' */
  FSFB_Const_Exp_B.Constant1 = FSFB_Const_Exp_P.Constant1_Value;

  /* Start for Constant: '<S4>/Constant2' */
  FSFB_Const_Exp_B.Constant2 = FSFB_Const_Exp_P.Constant2_Value;

  /* Start for Constant: '<S4>/Constant3' */
  FSFB_Const_Exp_B.Constant3 = FSFB_Const_Exp_P.Constant3_Value;

  /* Start for Constant: '<S4>/Constant4' */
  FSFB_Const_Exp_B.Constant4 = FSFB_Const_Exp_P.Constant4_Value;

  /* Start for S-Function (sldrtpo): '<S2>/Packet Output' */

  /* S-Function Block: <S2>/Packet Output */
  /* no initial value should be set */
  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S6>/filter1' */
    FSFB_Const_Exp_X.filter1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S6>/filter2' */
    FSFB_Const_Exp_X.filter2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S6>/filter1' */
    FSFB_Const_Exp_X.filter1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S6>/filter2' */
    FSFB_Const_Exp_X.filter2_CSTATE[1] = 0.0;

    /* InitializeConditions for Derivative: '<S5>/Derivative' */
    FSFB_Const_Exp_DW.TimeStampA = (rtInf);
    FSFB_Const_Exp_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S5>/Derivative1' */
    FSFB_Const_Exp_DW.TimeStampA_a = (rtInf);
    FSFB_Const_Exp_DW.TimeStampB_i = (rtInf);

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    for (i = 0; i < 5; i++) {
      FSFB_Const_Exp_X.Integrator_CSTATE[i] = FSFB_Const_Exp_P.initialValues[i];
    }

    /* End of InitializeConditions for Integrator: '<S1>/Integrator' */

    /* InitializeConditions for Derivative: '<S6>/Derivative' */
    FSFB_Const_Exp_DW.TimeStampA_n = (rtInf);
    FSFB_Const_Exp_DW.TimeStampB_c = (rtInf);
  }
}

/* Model terminate function */
void FSFB_Const_Exp_terminate(void)
{
  /* Terminate for S-Function (barrierIMILog): '<S1>/adaptive  controller' */
  /* Level2 S-Function Block: '<S1>/adaptive  controller' (barrierIMILog) */
  {
    SimStruct *rts = FSFB_Const_Exp_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sldrtpo): '<S2>/Packet Output' */

  /* S-Function Block: <S2>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  FSFB_Const_Exp_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  FSFB_Const_Exp_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  FSFB_Const_Exp_initialize();
}

void MdlTerminate(void)
{
  FSFB_Const_Exp_terminate();
}

/* Registration function */
RT_MODEL_FSFB_Const_Exp_T *FSFB_Const_Exp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FSFB_Const_Exp_M, 0,
                sizeof(RT_MODEL_FSFB_Const_Exp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FSFB_Const_Exp_M->solverInfo,
                          &FSFB_Const_Exp_M->Timing.simTimeStep);
    rtsiSetTPtr(&FSFB_Const_Exp_M->solverInfo, &rtmGetTPtr(FSFB_Const_Exp_M));
    rtsiSetStepSizePtr(&FSFB_Const_Exp_M->solverInfo,
                       &FSFB_Const_Exp_M->Timing.stepSize0);
    rtsiSetdXPtr(&FSFB_Const_Exp_M->solverInfo, &FSFB_Const_Exp_M->derivs);
    rtsiSetContStatesPtr(&FSFB_Const_Exp_M->solverInfo, (real_T **)
                         &FSFB_Const_Exp_M->contStates);
    rtsiSetNumContStatesPtr(&FSFB_Const_Exp_M->solverInfo,
      &FSFB_Const_Exp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&FSFB_Const_Exp_M->solverInfo,
      &FSFB_Const_Exp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&FSFB_Const_Exp_M->solverInfo,
      &FSFB_Const_Exp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&FSFB_Const_Exp_M->solverInfo,
      &FSFB_Const_Exp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&FSFB_Const_Exp_M->solverInfo, (&rtmGetErrorStatus
      (FSFB_Const_Exp_M)));
    rtsiSetRTModelPtr(&FSFB_Const_Exp_M->solverInfo, FSFB_Const_Exp_M);
  }

  rtsiSetSimTimeStep(&FSFB_Const_Exp_M->solverInfo, MAJOR_TIME_STEP);
  FSFB_Const_Exp_M->intgData.f[0] = FSFB_Const_Exp_M->odeF[0];
  FSFB_Const_Exp_M->contStates = ((real_T *) &FSFB_Const_Exp_X);
  rtsiSetSolverData(&FSFB_Const_Exp_M->solverInfo, (void *)
                    &FSFB_Const_Exp_M->intgData);
  rtsiSetSolverName(&FSFB_Const_Exp_M->solverInfo,"ode1");
  FSFB_Const_Exp_M->solverInfoPtr = (&FSFB_Const_Exp_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = FSFB_Const_Exp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    FSFB_Const_Exp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    FSFB_Const_Exp_M->Timing.sampleTimes =
      (&FSFB_Const_Exp_M->Timing.sampleTimesArray[0]);
    FSFB_Const_Exp_M->Timing.offsetTimes =
      (&FSFB_Const_Exp_M->Timing.offsetTimesArray[0]);

    /* task periods */
    FSFB_Const_Exp_M->Timing.sampleTimes[0] = (0.0);
    FSFB_Const_Exp_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    FSFB_Const_Exp_M->Timing.offsetTimes[0] = (0.0);
    FSFB_Const_Exp_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(FSFB_Const_Exp_M, &FSFB_Const_Exp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = FSFB_Const_Exp_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    FSFB_Const_Exp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(FSFB_Const_Exp_M, 90.0);
  FSFB_Const_Exp_M->Timing.stepSize0 = 0.001;
  FSFB_Const_Exp_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  FSFB_Const_Exp_M->Sizes.checksums[0] = (4183878578U);
  FSFB_Const_Exp_M->Sizes.checksums[1] = (499556337U);
  FSFB_Const_Exp_M->Sizes.checksums[2] = (3930033813U);
  FSFB_Const_Exp_M->Sizes.checksums[3] = (2389889923U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    FSFB_Const_Exp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FSFB_Const_Exp_M->extModeInfo,
      &FSFB_Const_Exp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FSFB_Const_Exp_M->extModeInfo,
                        FSFB_Const_Exp_M->Sizes.checksums);
    rteiSetTPtr(FSFB_Const_Exp_M->extModeInfo, rtmGetTPtr(FSFB_Const_Exp_M));
  }

  FSFB_Const_Exp_M->solverInfoPtr = (&FSFB_Const_Exp_M->solverInfo);
  FSFB_Const_Exp_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&FSFB_Const_Exp_M->solverInfo, 0.001);
  rtsiSetSolverMode(&FSFB_Const_Exp_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  FSFB_Const_Exp_M->blockIO = ((void *) &FSFB_Const_Exp_B);
  (void) memset(((void *) &FSFB_Const_Exp_B), 0,
                sizeof(B_FSFB_Const_Exp_T));

  /* parameters */
  FSFB_Const_Exp_M->defaultParam = ((real_T *)&FSFB_Const_Exp_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &FSFB_Const_Exp_X;
    FSFB_Const_Exp_M->contStates = (x);
    (void) memset((void *)&FSFB_Const_Exp_X, 0,
                  sizeof(X_FSFB_Const_Exp_T));
  }

  /* states (dwork) */
  FSFB_Const_Exp_M->dwork = ((void *) &FSFB_Const_Exp_DW);
  (void) memset((void *)&FSFB_Const_Exp_DW, 0,
                sizeof(DW_FSFB_Const_Exp_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    FSFB_Const_Exp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &FSFB_Const_Exp_M->NonInlinedSFcns.sfcnInfo;
    FSFB_Const_Exp_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(FSFB_Const_Exp_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &FSFB_Const_Exp_M->Sizes.numSampTimes);
    FSFB_Const_Exp_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (FSFB_Const_Exp_M)[0]);
    FSFB_Const_Exp_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (FSFB_Const_Exp_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,FSFB_Const_Exp_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(FSFB_Const_Exp_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(FSFB_Const_Exp_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (FSFB_Const_Exp_M));
    rtssSetStepSizePtr(sfcnInfo, &FSFB_Const_Exp_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(FSFB_Const_Exp_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &FSFB_Const_Exp_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &FSFB_Const_Exp_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &FSFB_Const_Exp_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &FSFB_Const_Exp_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &FSFB_Const_Exp_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &FSFB_Const_Exp_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &FSFB_Const_Exp_M->solverInfoPtr);
  }

  FSFB_Const_Exp_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&FSFB_Const_Exp_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    FSFB_Const_Exp_M->childSfunctions =
      (&FSFB_Const_Exp_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    FSFB_Const_Exp_M->childSfunctions[0] =
      (&FSFB_Const_Exp_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: FSFB_Const_Exp/<S1>/adaptive  controller (barrierIMILog) */
    {
      SimStruct *rts = FSFB_Const_Exp_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FSFB_Const_Exp_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FSFB_Const_Exp_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FSFB_Const_Exp_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FSFB_Const_Exp_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FSFB_Const_Exp_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FSFB_Const_Exp_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FSFB_Const_Exp_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &FSFB_Const_Exp_B.Gain;
          sfcnUPtrs[1] = &FSFB_Const_Exp_B.Gain1;
          sfcnUPtrs[2] = &FSFB_Const_Exp_B.filter1;
          sfcnUPtrs[3] = &FSFB_Const_Exp_B.filter2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &FSFB_Const_Exp_B.Fcn;
          sfcnUPtrs[1] = &FSFB_Const_Exp_B.Fcn1;
          sfcnUPtrs[2] = &FSFB_Const_Exp_B.Derivative[0];
          sfcnUPtrs[3] = &FSFB_Const_Exp_B.Derivative[1];
          sfcnUPtrs[4] = &FSFB_Const_Exp_B.Derivative1[0];
          sfcnUPtrs[5] = &FSFB_Const_Exp_B.Derivative1[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 6);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = FSFB_Const_Exp_B.Integrator;
            for (i1=0; i1 < 5; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 5);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &FSFB_Const_Exp_B.Constant;
          sfcnUPtrs[1] = &FSFB_Const_Exp_B.Constant1;
          sfcnUPtrs[2] = &FSFB_Const_Exp_B.Constant2;
          sfcnUPtrs[3] = &FSFB_Const_Exp_B.Constant3;
          sfcnUPtrs[4] = &FSFB_Const_Exp_B.Constant4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            FSFB_Const_Exp_B.adaptivecontroller_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            FSFB_Const_Exp_B.adaptivecontroller_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 2);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            FSFB_Const_Exp_B.adaptivecontroller_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "adaptive \ncontroller");
      ssSetPath(rts, "FSFB_Const_Exp/Adaptive Controller/adaptive  controller");
      ssSetRTModel(rts,FSFB_Const_Exp_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FSFB_Const_Exp_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FSFB_Const_Exp_P.adaptivecontroller_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FSFB_Const_Exp_P.adaptivecontroller_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FSFB_Const_Exp_P.adaptivecontroller_P3_Size);
      }

      /* registration */
      barrierIMILog(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }
  }

  /* Initialize Sizes */
  FSFB_Const_Exp_M->Sizes.numContStates = (9);/* Number of continuous states */
  FSFB_Const_Exp_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  FSFB_Const_Exp_M->Sizes.numY = (0);  /* Number of model outputs */
  FSFB_Const_Exp_M->Sizes.numU = (0);  /* Number of model inputs */
  FSFB_Const_Exp_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  FSFB_Const_Exp_M->Sizes.numSampTimes = (2);/* Number of sample times */
  FSFB_Const_Exp_M->Sizes.numBlocks = (34);/* Number of blocks */
  FSFB_Const_Exp_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  FSFB_Const_Exp_M->Sizes.numBlockPrms = (45);/* Sum of parameter "widths" */
  return FSFB_Const_Exp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
