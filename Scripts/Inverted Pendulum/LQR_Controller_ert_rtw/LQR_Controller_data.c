/*
 * LQR_Controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.23
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Tue Aug  5 21:08:16 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_Controller.h"

/* Block parameters (default storage) */
P_LQR_Controller_T LQR_Controller_P = {
  /* Variable: K
   * Referenced by: '<Root>/LQR Gains'
   */
  { -0.22360679774997747, -0.58066550388712113, 11.086644646302014,
    1.5627823493698714 },

  /* Variable: R_motor
   * Referenced by: '<S3>/Gain2'
   */
  9.6,

  /* Variable: k_motor
   * Referenced by:
   *   '<S3>/Gain1'
   *   '<S3>/Gain2'
   */
  0.43243243243243246,

  /* Variable: r
   * Referenced by:
   *   '<S3>/Gain1'
   *   '<S3>/Gain2'
   */
  0.0065,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S7>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Constant3'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Gain2'
   */
  50.0,

  /* Expression: 255/24
   * Referenced by: '<S3>/Gain4'
   */
  10.625,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S1>/Constant'
   */
  1.5707963267948966,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S7>/TSamp'
   */
  142.85714285714286,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Pi'
   */
  3.1415926535897931,

  /* Expression: .3
   * Referenced by: '<Root>/Switch'
   */
  0.3,

  /* Expression: 407
   * Referenced by: '<S6>/Constant2'
   */
  407.0,

  /* Expression: -1
   * Referenced by: '<S6>/Dead Zone1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Dead Zone1'
   */
  1.0,

  /* Expression: 403
   * Referenced by: '<S6>/Constant1'
   */
  403.0,

  /* Expression: -1
   * Referenced by: '<S6>/Dead Zone'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Dead Zone'
   */
  1.0,

  /* Expression: 5/1023
   * Referenced by: '<S6>/Analog to Voltage'
   */
  0.0048875855327468231,

  /* Expression: 8500/1000
   * Referenced by: '<S6>/Voltage to Current'
   */
  8.5,

  /* Expression: 1
   * Referenced by: '<S5>/Constant2'
   */
  1.0,

  /* Computed Parameter: PositionIntegration_gainval
   * Referenced by: '<S2>/Position Integration'
   */
  0.014,

  /* Expression: 0
   * Referenced by: '<S2>/Position Integration'
   */
  0.0,

  /* Expression: .5
   * Referenced by: '<S2>/Position Integration'
   */
  0.5,

  /* Expression: -.5
   * Referenced by: '<S2>/Position Integration'
   */
  -0.5,

  /* Expression: pi/30
   * Referenced by: '<S2>/RPM to rad//s'
   */
  0.10471975511965977,

  /* Expression: 6.5/1000
   * Referenced by: '<S2>/rad//s to m//s'
   */
  0.0065,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S9>/Ticks to RPM'
   */
  -1912296657L,

  /* Computed Parameter: Volt2Rad_Gain
   * Referenced by: '<S1>/Volt2Rad'
   */
  51522U
};
