/*
 * PID_Controller_Test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_Controller_Test".
 *
 * Model version              : 1.1
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Oct  6 19:57:00 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_Controller_Test.h"

/* Block parameters (default storage) */
P_PID_Controller_Test_T PID_Controller_Test_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S45>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S97>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S49>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S101>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: Derivative_ICPrevScaledInput
   * Referenced by: '<S8>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S47>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S99>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_f
   * Referenced by: '<S52>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_g
   * Referenced by: '<S104>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S55>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S107>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S57>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S109>/Proportional Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/RT'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/RT1'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S8>/TSamp'
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

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S52>/Integrator'
   */
  0.007,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S47>/Filter'
   */
  0.007,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0.51316
   * Referenced by: '<S4>/Gain2'
   */
  0.51316,

  /* Expression: 255/12
   * Referenced by: '<S4>/Gain4'
   */
  21.25,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

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

  /* Expression: 11.692
   * Referenced by: '<S4>/Gain1'
   */
  11.692,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S99>/Filter'
   */
  0.014,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S104>/Integrator'
   */
  0.014,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S15>/Ticks to RPM'
   */
  -2091704852L,

  /* Computed Parameter: Volt2Rad1_Gain
   * Referenced by: '<S1>/Volt2Rad1'
   */
  51522U
};
