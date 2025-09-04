/*
 * PID_Controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_Controller".
 *
 * Model version              : 1.17
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sat Aug 16 20:01:33 2025
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
  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S37>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S41>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S39>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_d
   * Referenced by: '<S44>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S51>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S47>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S49>/Proportional Gain'
   */
  500.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S51>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: [0.1358 0.1358]
   * Referenced by: '<S1>/Low Pass Filter'
   */
  { 0.1358, 0.1358 },

  /* Expression: [1 -0.7285]
   * Referenced by: '<S1>/Low Pass Filter'
   */
  { 1.0, -0.7285 },

  /* Expression: 0
   * Referenced by: '<S1>/Low Pass Filter'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Pi'
   */
  3.1415926535897931,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S44>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S39>/Filter'
   */
  0.01,

  /* Expression: .3
   * Referenced by: '<Root>/Switch'
   */
  0.3,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant2'
   */
  1.0,

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S7>/Ticks to RPM'
   */
  -1464193396L,

  /* Computed Parameter: Volt2Rad1_Gain
   * Referenced by: '<S1>/Volt2Rad1'
   */
  51522U
};
