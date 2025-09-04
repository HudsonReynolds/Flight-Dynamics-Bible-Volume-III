/*
 * LQR_Controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.58
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sun Aug 24 15:48:43 2025
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
  { -114.01754250991182, -130.5047435190543, 728.34107589609982,
    51.993866326858374 },

  /* Variable: R_motor
   * Referenced by: '<S4>/Gain2'
   */
  6.0,

  /* Variable: k_motor
   * Referenced by:
   *   '<S4>/Gain1'
   *   '<S4>/Gain2'
   */
  0.076,

  /* Variable: r
   * Referenced by:
   *   '<S4>/Gain1'
   *   '<S4>/Gain2'
   */
  0.0065,

  /* Mask Parameter: Derivative_ICPrevScaledInput
   * Referenced by: '<S6>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/RT'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/RT1'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  142.85714285714286,

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

  /* Expression: 1
   * Referenced by: '<Root>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 255/12
   * Referenced by: '<S4>/Gain4'
   */
  21.25,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant2'
   */
  1.0,

  /* Computed Parameter: PositionIntegration_gainval
   * Referenced by: '<S3>/Position Integration'
   */
  0.014,

  /* Expression: 0
   * Referenced by: '<S3>/Position Integration'
   */
  0.0,

  /* Expression: .5
   * Referenced by: '<S3>/Position Integration'
   */
  0.5,

  /* Expression: -.5
   * Referenced by: '<S3>/Position Integration'
   */
  -0.5,

  /* Expression: pi/30
   * Referenced by: '<S3>/RPM to rad//s'
   */
  0.10471975511965977,

  /* Expression: 6.5/1000
   * Referenced by: '<S3>/rad//s to m//s'
   */
  0.0065,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S13>/Ticks to RPM'
   */
  -2091704852L,

  /* Computed Parameter: Volt2Rad1_Gain
   * Referenced by: '<S1>/Volt2Rad1'
   */
  51522U
};
