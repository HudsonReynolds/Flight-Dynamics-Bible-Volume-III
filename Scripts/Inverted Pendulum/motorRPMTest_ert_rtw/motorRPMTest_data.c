/*
 * motorRPMTest_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motorRPMTest".
 *
 * Model version              : 1.2
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Aug 11 20:31:21 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorRPMTest.h"

/* Block parameters (default storage) */
P_motorRPMTest_T motorRPMTest_P = {
  /* Variable: k_motor
   * Referenced by: '<S6>/Current to Torque'
   */
  0.076,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S95>/Integral Gain'
   */
  8.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S98>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S90>/Kb'
   */
  0.1,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S105>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S103>/Proportional Gain'
   */
  0.45,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S105>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S60>/deltax'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S2>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 2.341022727272728, 0.0,
    227.83167613636368, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S7>/KalmanGainM'
   */
  { 0.50063266582348509, 1.0062034238469439E-14, 0.10261990291743675,
    1.0343541874590793E-12, 0.0051309951458531908, 3.5005754163804528E-16,
    0.99892629597915328, 3.3275591428836839E-14 },

  /* Expression: pInitialization.C
   * Referenced by: '<S2>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S7>/KalmanGainL'
   */
  { -2.5118236393881247E-12, 0.24023552499938142, -2.4446200764293909E-10,
    23.380064486546935, 1.870335990870701E-13, 2.3385091617575404,
    1.8257844735989704E-11, 227.58705234961769 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: pInitialization.D
   * Referenced by: '<S2>/D'
   */
  { 0.0, 0.0 },

  /* Expression: pInitialization.X0
   * Referenced by: '<S2>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S2>/B'
   */
  { 0.0, 2.8409090909090913, 0.0, 53.26704545454546 },

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  100.0,

  /* Expression: pInitialization.Z
   * Referenced by: '<S7>/CovarianceZ'
   */
  { 0.0050063266582348982, 1.0062034238469036E-16, 0.0010261990291706457,
    1.0343541874590848E-14, 1.00620342384691E-16, 1.104900619121979,
    7.0011508327609916E-17, 106.55729239669257, 0.0010261990291706284,
    7.0011508327609916E-17, 0.19978525919583145, 6.6551182857673568E-15,
    1.034354187459073E-14, 106.55729239669257, 6.6551182857674144E-15,
    10370.337920749542 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S98>/Integrator'
   */
  0.01,

  /* Expression: 389
   * Referenced by: '<S6>/Constant2'
   */
  389.0,

  /* Expression: -1
   * Referenced by: '<S6>/Dead Zone1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Dead Zone1'
   */
  1.0,

  /* Expression: 388
   * Referenced by: '<S6>/Constant1'
   */
  388.0,

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

  /* Computed Parameter: TickstoRPM_Gain
   * Referenced by: '<S62>/Ticks to RPM'
   */
  -1464193396L,

  /* Computed Parameter: Volt2Rad_Gain
   * Referenced by: '<Root>/Volt2Rad'
   */
  51522U,

  /* Expression: true()
   * Referenced by: '<S2>/Enable'
   */
  true,

  /* Expression: pInitialization.isSqrtUsed
   * Referenced by: '<S56>/isSqrtUsed'
   */
  false
};
