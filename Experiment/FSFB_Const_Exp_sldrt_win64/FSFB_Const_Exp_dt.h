/*
 * FSFB_Const_Exp_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&FSFB_Const_Exp_B.Gain), 0, 0, 39 },

  { (char_T *)(&FSFB_Const_Exp_B.Add[0]), 5, 0, 2 },

  { (char_T *)(&FSFB_Const_Exp_B.PacketInput[0]), 4, 0, 2 }
  ,

  { (char_T *)(&FSFB_Const_Exp_DW.TimeStampA), 0, 0, 18 },

  { (char_T *)(&FSFB_Const_Exp_DW.PacketInput_PWORK), 11, 0, 9 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&FSFB_Const_Exp_P.initialValues[0]), 0, 0, 9 },

  { (char_T *)(&FSFB_Const_Exp_P.PacketInput_PacketID), 6, 0, 2 },

  { (char_T *)(&FSFB_Const_Exp_P.Gain_Gain), 0, 0, 34 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] FSFB_Const_Exp_dt.h */
