/*
 * PID_Controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_Controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sat Aug  2 16:28:32 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_Controller.h"

/* Block parameters (default storage) */
P_PID_Controller_T PID_Controller_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S90>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S94>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S6>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S92>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_f
   * Referenced by: '<S97>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S104>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S100>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S102>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S104>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S1>/Constant'
   */
  1.5707963267948966,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  50.0,

  /* Expression: pi
   * Referenced by: '<Root>/Pi'
   */
  3.1415926535897931,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S97>/Integrator'
   */
  0.02,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S92>/Filter'
   */
  0.02,

  /* Expression: .3
   * Referenced by: '<Root>/Switch'
   */
  0.3,

  /* Expression: pi/30
   * Referenced by: '<S3>/RPM to rad//s'
   */
  0.10471975511965977,

  /* Expression: 6.5/1000
   * Referenced by: '<S3>/rad//s to m//s'
   */
  0.0065,

  /* Computed Parameter: PositionIntegration_gainval
   * Referenced by: '<S3>/Position Integration'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S3>/Position Integration'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant2'
   */
  1.0,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S8>/Ticks to RPM'
   */
  -1338607660L,

  /* Computed Parameter: Volt2Rad_Gain
   * Referenced by: '<S1>/Volt2Rad'
   */
  51522U
};
