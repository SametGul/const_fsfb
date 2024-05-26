/*
 * FSFB_Const_Exp_data.c
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

/* Block parameters (default storage) */
P_FSFB_Const_Exp_T FSFB_Const_Exp_P = {
  /* Variable: initialValues
   * Referenced by: '<S1>/Integrator'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: PacketInput_MaxMissedTicks
   * Referenced by: '<S3>/Packet Input'
   */
  1.0,

  /* Mask Parameter: PacketOutput_MaxMissedTicks
   * Referenced by: '<S2>/Packet Output'
   */
  1.0,

  /* Mask Parameter: PacketInput_YieldWhenWaiting
   * Referenced by: '<S3>/Packet Input'
   */
  1.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<S2>/Packet Output'
   */
  1.0,

  /* Mask Parameter: PacketInput_PacketID
   * Referenced by: '<S3>/Packet Input'
   */
  1,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<S2>/Packet Output'
   */
  1,

  /* Expression: 2*pi/4096
   * Referenced by: '<S3>/Gain'
   */
  0.0015339807878856412,

  /* Expression: pi/4096
   * Referenced by: '<S3>/Gain1'
   */
  0.00076699039394282058,

  /* Computed Parameter: filter1_A
   * Referenced by: '<S6>/filter1'
   */
  { -1000.0, -250000.0 },

  /* Computed Parameter: filter1_C
   * Referenced by: '<S6>/filter1'
   */
  { 0.0, 250000.0 },

  /* Computed Parameter: filter2_A
   * Referenced by: '<S6>/filter2'
   */
  { -1000.0, -250000.0 },

  /* Computed Parameter: filter2_C
   * Referenced by: '<S6>/filter2'
   */
  { 0.0, 250000.0 },

  /* Expression: 6
   * Referenced by: '<S4>/Constant'
   */
  6.0,

  /* Expression: 0.5
   * Referenced by: '<S4>/Constant1'
   */
  0.5,

  /* Expression: 0.4
   * Referenced by: '<S4>/Constant2'
   */
  0.4,

  /* Expression: 24
   * Referenced by: '<S4>/Constant3'
   */
  24.0,

  /* Expression: 4.5
   * Referenced by: '<S4>/Constant4'
   */
  4.5,

  /* Computed Parameter: adaptivecontroller_P1_Size
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 1.0, 2.0 },

  /* Expression: [Kr1, Kr2]
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 180.0, 50.0 },

  /* Computed Parameter: adaptivecontroller_P2_Size
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 1.0, 2.0 },

  /* Expression: [alpha1, alpha2]
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 10.0, 20.0 },

  /* Computed Parameter: adaptivecontroller_P3_Size
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 1.0, 2.0 },

  /* Expression: [Ke1, Ke2]
   * Referenced by: '<S1>/adaptive  controller'
   */
  { 12.0, 24.0 },

  /* Expression: 10/287
   * Referenced by: '<S2>/Gain'
   */
  0.03484320557491289,

  /* Expression: -10/52
   * Referenced by: '<S2>/Gain2'
   */
  -0.19230769230769232,

  /* Expression: 9.6
   * Referenced by: '<S2>/Saturation'
   */
  9.6,

  /* Expression: -9.6
   * Referenced by: '<S2>/Saturation'
   */
  -9.6,

  /* Expression: 180/pi
   * Referenced by: '<Root>/RadToDeg'
   */
  57.295779513082323,

  /* Expression: 2048
   * Referenced by: '<S2>/Constant'
   */
  2048.0,

  /* Expression: 2048/10
   * Referenced by: '<S2>/Gain1'
   */
  204.8
};
