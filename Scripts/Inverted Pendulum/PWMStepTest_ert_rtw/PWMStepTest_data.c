/*
 * PWMStepTest_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PWMStepTest".
 *
 * Model version              : 1.15
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sat Aug  2 19:16:59 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWMStepTest.h"

/* Block parameters (default storage) */
P_PWMStepTest_T PWMStepTest_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S5>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<Root>/Constant2'
   */
  255.0,

  /* Computed Parameter: PositionIntegration_gainval
   * Referenced by: '<S3>/Position Integration'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S3>/Position Integration'
   */
  0.0,

  /* Expression: pi/30
   * Referenced by: '<S3>/RPM to rad//s'
   */
  0.10471975511965977,

  /* Expression: 6.5/1000
   * Referenced by: '<S3>/rad//s to m//s'
   */
  0.0065,

  /* Expression: pi/2
   * Referenced by: '<S1>/Constant'
   */
  1.5707963267948966,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S5>/TSamp'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Constant3'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Pi'
   */
  3.1415926535897931,

  /* Expression: .4
   * Referenced by: '<Root>/Switch'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 1.150750343959146
   * Referenced by: '<Root>/Gain'
   */
  1.150750343959146,

  /* Expression: 1
   * Referenced by: '<S4>/Constant2'
   */
  1.0,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S7>/Ticks to RPM'
   */
  -1338607660L,

  /* Computed Parameter: Volt2Rad_Gain
   * Referenced by: '<S1>/Volt2Rad'
   */
  51522U
};
