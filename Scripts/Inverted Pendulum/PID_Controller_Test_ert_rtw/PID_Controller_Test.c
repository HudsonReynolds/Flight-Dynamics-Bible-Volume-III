/*
 * PID_Controller_Test.c
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
#include "PID_Controller_Test_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "PID_Controller_Test_private.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_PID_Controller_Test_T PID_Controller_Test_B;

/* Block states (default storage) */
DW_PID_Controller_Test_T PID_Controller_Test_DW;

/* Real-time model */
static RT_MODEL_PID_Controller_Test_T PID_Controller_Test_M_;
RT_MODEL_PID_Controller_Test_T *const PID_Controller_Test_M =
  &PID_Controller_Test_M_;

/* Forward declaration for local functions */
static void PID_Controller_SystemCore_setup(dsp_simulink_MovingAverage_PI_T *obj);
static void PID_Controll_SystemCore_setup_l(dsp_simulink_MovingAverage_l_T *obj);
static void rate_monotonic_scheduler(void);
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void PID_Controller_Test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PID_Controller_Test_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(PID_Controller_Test_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (PID_Controller_Test_M->Timing.TaskCounters.TID[1] == 0) {
    PID_Controller_Test_M->Timing.RateInteraction.TID1_2 =
      (PID_Controller_Test_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PID_Controller_Test_M->Timing.TaskCounters.TID[1])++;
  if ((PID_Controller_Test_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.007s, 0.0s] */
    PID_Controller_Test_M->Timing.TaskCounters.TID[1] = 0;
  }

  (PID_Controller_Test_M->Timing.TaskCounters.TID[2])++;
  if ((PID_Controller_Test_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.014s, 0.0s] */
    PID_Controller_Test_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void PID_Controller_SystemCore_setup(dsp_simulink_MovingAverage_PI_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  obj->NumChannels = 1L;
  obj->FrameLength = 1L;
  obj->pCumSum = 0.0;
  memset(&obj->pCumSumRev[0], 0, 11U * sizeof(real_T));
  obj->pCumRevIndex = 1.0;
  obj->pModValueRev = 0.0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PID_Controll_SystemCore_setup_l(dsp_simulink_MovingAverage_l_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S15>/Moving Average' */
  obj->NumChannels = 1L;
  obj->FrameLength = 1L;
  obj->pCumSum = 0.0;
  obj->pCumSumRev[0] = 0.0;
  obj->pCumSumRev[1] = 0.0;
  obj->pCumSumRev[2] = 0.0;
  obj->pCumRevIndex = 1.0;
  obj->pModValueRev = 0.0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void PID_Controller_Test_step0(void)   /* Sample time: [0.0035s, 0.0s] */
{
  {                                    /* Sample time: [0.0035s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void PID_Controller_Test_step1(void)   /* Sample time: [0.007s, 0.0s] */
{
  real_T Diff;
  real_T csum;
  real_T rtb_TSamp;
  real_T rtb_theta_cal;
  real_T z;
  uint32_T rtb_PendulumAngle;
  int16_T rtb_mode;
  uint16_T b_varargout_1;
  uint8_T tmp_0;
  boolean_T guard1;
  boolean_T rtb_cal;
  boolean_T tmp;

  /* RateTransition: '<Root>/RT' incorporates:
   *  Concatenate: '<Root>/State Vector'
   *  RateTransition generated from: '<Root>/Sum1'
   *  RateTransition generated from: '<S4>/Add2'
   */
  tmp = PID_Controller_Test_M->Timing.RateInteraction.TID1_2;
  if (tmp) {
    PID_Controller_Test_B.StateVector[0] = PID_Controller_Test_DW.RT_Buffer0;

    /* RateTransition: '<Root>/RT1' incorporates:
     *  Concatenate: '<Root>/State Vector'
     */
    PID_Controller_Test_B.StateVector[1] = PID_Controller_Test_DW.RT1_Buffer0;
  }

  /* End of RateTransition: '<Root>/RT' */

  /* MATLABSystem: '<S1>/Analog Input1' */
  PID_Controller_Test_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (PID_Controller_Test_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<S1>/Volt2Rad1' incorporates:
   *  MATLABSystem: '<S1>/Analog Input1'
   * */
  rtb_PendulumAngle = (uint32_T)PID_Controller_Test_P.Volt2Rad1_Gain *
    b_varargout_1;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  Gain: '<S1>/Volt2Rad1'
   */
  guard1 = false;
  if (!PID_Controller_Test_DW.calibrated) {
    PID_Controller_Test_DW.sample_count++;

    /* DataTypeConversion: '<S1>/Cast To Double' incorporates:
     *  Gain: '<S1>/Volt2Rad1'
     */
    rtb_TSamp = (real_T)rtb_PendulumAngle * 1.1920928955078125E-7;
    PID_Controller_Test_DW.theta_sum += rtb_TSamp;
    if (PID_Controller_Test_DW.sample_count >= PID_Controller_Test_DW.N) {
      PID_Controller_Test_DW.theta0 = PID_Controller_Test_DW.theta_sum /
        PID_Controller_Test_DW.N;
      PID_Controller_Test_DW.calibrated = true;
      guard1 = true;
    } else {
      rtb_theta_cal = rtb_TSamp + 1.5707963267948966;
      rtb_cal = false;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    rtb_theta_cal = ((real_T)rtb_PendulumAngle * 1.1920928955078125E-7 -
                     PID_Controller_Test_DW.theta0) + 6.2831853071795862;
    rtb_cal = true;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PID_Controller_Test_B.StateVector[2] = rtb_theta_cal;

  /* SampleTimeMath: '<S8>/TSamp'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_theta_cal * PID_Controller_Test_P.TSamp_WtEt;

  /* Sum: '<S8>/Diff' incorporates:
   *  UnitDelay: '<S8>/UD'
   */
  Diff = rtb_TSamp - PID_Controller_Test_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (PID_Controller_Test_DW.obj.TunablePropsChanged) {
    PID_Controller_Test_DW.obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* Concatenate: '<Root>/State Vector' incorporates:
   *  MATLABSystem: '<S1>/Moving Average'
   *  SignalConversion generated from: '<S1>/Moving Average'
   */
  PID_Controller_Test_B.StateVector[3] = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  csum = PID_Controller_Test_DW.obj.pCumSum + Diff;
  if (PID_Controller_Test_DW.obj.pModValueRev == 0.0) {
    z = PID_Controller_Test_DW.obj.pCumSumRev[(int16_T)
      PID_Controller_Test_DW.obj.pCumRevIndex - 1] + csum;
  }

  PID_Controller_Test_DW.obj.pCumSumRev[(int16_T)
    PID_Controller_Test_DW.obj.pCumRevIndex - 1] = Diff;
  if (PID_Controller_Test_DW.obj.pCumRevIndex != 11.0) {
    Diff = PID_Controller_Test_DW.obj.pCumRevIndex + 1.0;
  } else {
    Diff = 1.0;
    csum = 0.0;
    for (rtb_mode = 9; rtb_mode >= 0; rtb_mode--) {
      PID_Controller_Test_DW.obj.pCumSumRev[rtb_mode] +=
        PID_Controller_Test_DW.obj.pCumSumRev[rtb_mode + 1];
    }
  }

  if (PID_Controller_Test_DW.obj.pModValueRev == 0.0) {
    /* Concatenate: '<Root>/State Vector' incorporates:
     *  SignalConversion generated from: '<S1>/Moving Average'
     */
    PID_Controller_Test_B.StateVector[3] = z / 12.0;
  }

  PID_Controller_Test_DW.obj.pCumSum = csum;
  PID_Controller_Test_DW.obj.pCumRevIndex = Diff;
  if (PID_Controller_Test_DW.obj.pModValueRev > 0.0) {
    PID_Controller_Test_DW.obj.pModValueRev--;
  } else {
    PID_Controller_Test_DW.obj.pModValueRev = 0.0;
  }

  /* Constant: '<Root>/Constant4' */
  PID_Controller_Test_B.SetPoint[0] = PID_Controller_Test_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  PID_Controller_Test_B.SetPoint[1] = PID_Controller_Test_P.Constant5_Value;

  /* Constant: '<Root>/Constant3' */
  PID_Controller_Test_B.SetPoint[2] = PID_Controller_Test_P.Constant3_Value;

  /* Constant: '<Root>/Constant6' */
  PID_Controller_Test_B.SetPoint[3] = PID_Controller_Test_P.Constant6_Value;

  /* Sum: '<Root>/Sum' */
  PID_Controller_Test_B.SetPoint[0] = PID_Controller_Test_B.StateVector[0] -
    PID_Controller_Test_B.SetPoint[0];
  PID_Controller_Test_B.SetPoint[1] = PID_Controller_Test_B.StateVector[1] -
    PID_Controller_Test_B.SetPoint[1];
  PID_Controller_Test_B.SetPoint[2] = PID_Controller_Test_B.StateVector[2] -
    PID_Controller_Test_B.SetPoint[2];
  PID_Controller_Test_B.SetPoint[3] = PID_Controller_Test_B.StateVector[3] -
    PID_Controller_Test_B.SetPoint[3];

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_theta_cal = PID_Controller_Test_P.Constant_Value - rtb_theta_cal;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  if (rtb_cal) {
    if ((fabs(PID_Controller_Test_B.StateVector[2] - 3.1415926535897931) < 0.15)
        && (fabs(PID_Controller_Test_B.StateVector[3]) < 1.5)) {
      rtb_mode = 1;
    } else {
      rtb_mode = 2;
    }
  } else {
    rtb_mode = 3;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* RateTransition generated from: '<S4>/Add2' incorporates:
   *  RateTransition generated from: '<Root>/Sum1'
   */
  if (tmp) {
    /* RateTransition generated from: '<S4>/Add2' */
    PID_Controller_Test_B.TmpRTBAtAdd2Inport1 =
      PID_Controller_Test_DW.TmpRTBAtAdd2Inport1_Buffer0;

    /* RateTransition generated from: '<Root>/Sum1' */
    PID_Controller_Test_B.TmpRTBAtSum1Inport2 =
      PID_Controller_Test_DW.TmpRTBAtSum1Inport2_Buffer0;
  }

  /* Gain: '<S55>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S47>/Filter'
   *  Gain: '<S45>/Derivative Gain'
   *  Sum: '<S47>/SumD'
   */
  z = (PID_Controller_Test_P.PIDController_D * rtb_theta_cal -
       PID_Controller_Test_DW.Filter_DSTATE) *
    PID_Controller_Test_P.PIDController_N;

  /* SwitchCase: '<S2>/Switch Case' */
  switch ((int32_T)rtb_mode) {
   case 1L:
    /* Outputs for IfAction SubSystem: '<S2>/LQR' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/voltage' incorporates:
     *  DiscreteIntegrator: '<S52>/Integrator'
     *  Gain: '<S4>/Gain2'
     *  Gain: '<S4>/Gain4'
     *  Gain: '<S57>/Proportional Gain'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<S4>/Add2'
     *  Sum: '<S61>/Sum'
     */
    csum = ((((PID_Controller_Test_P.PIDController_P * rtb_theta_cal +
               PID_Controller_Test_DW.Integrator_DSTATE) + z) +
             PID_Controller_Test_B.TmpRTBAtSum1Inport2) *
            PID_Controller_Test_P.Gain2_Gain +
            PID_Controller_Test_B.TmpRTBAtAdd2Inport1) *
      PID_Controller_Test_P.Gain4_Gain;

    /* End of Outputs for SubSystem: '<S2>/LQR' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S2>/Swing Up' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* MATLAB Function: '<S12>/MATLAB Function1' */
    PID_Controller_Test_DW.thetaMax_not_empty = true;

    /* SignalConversion generated from: '<S12>/Out1' incorporates:
     *  MATLAB Function: '<S12>/MATLAB Function1'
     */
    csum = 0.0;

    /* End of Outputs for SubSystem: '<S2>/Swing Up' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Uncalibrated' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* SignalConversion generated from: '<S13>/In1' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    csum = PID_Controller_Test_P.Constant1_Value;

    /* End of Outputs for SubSystem: '<S2>/Uncalibrated' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Gain: '<S3>/Gain' */
  csum *= PID_Controller_Test_P.Gain_Gain;

  /* MATLAB Function: '<S3>/Select PWM Direction' */
  if (csum > 0.0) {
    Diff = 0.0;
  } else {
    Diff = -csum;
    csum = 0.0;
  }

  /* End of MATLAB Function: '<S3>/Select PWM Direction' */

  /* MATLABSystem: '<S3>/PWM' */
  PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (5UL);

  /* Start for MATLABSystem: '<S3>/PWM' */
  if (!(csum <= 255.0)) {
    csum = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM' */
  MW_PWM_SetDutyCycle(PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE,
                      csum);

  /* MATLABSystem: '<S3>/PWM1' */
  PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!(Diff <= 255.0)) {
    Diff = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                      Diff);

  /* MATLABSystem: '<S7>/Digital Output1' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  csum = rt_roundd_snf(PID_Controller_Test_P.Constant2_Value);
  if (csum < 256.0) {
    if (csum >= 0.0) {
      tmp_0 = (uint8_T)csum;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);

  /* End of MATLABSystem: '<S7>/Digital Output1' */

  /* MATLABSystem: '<S7>/Digital Output2' */
  if (csum < 256.0) {
    if (csum >= 0.0) {
      tmp_0 = (uint8_T)csum;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S7>/Digital Output2' */

  /* Update for UnitDelay: '<S8>/UD' */
  PID_Controller_Test_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S52>/Integrator' incorporates:
   *  Gain: '<S49>/Integral Gain'
   */
  PID_Controller_Test_DW.Integrator_DSTATE +=
    PID_Controller_Test_P.PIDController_I * rtb_theta_cal *
    PID_Controller_Test_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S47>/Filter' */
  PID_Controller_Test_DW.Filter_DSTATE += PID_Controller_Test_P.Filter_gainval *
    z;
}

/* Model step function for TID2 */
void PID_Controller_Test_step2(void)   /* Sample time: [0.014s, 0.0s] */
{
  int64m_T rtb_TickstoRPM;
  real_T csum;
  real_T cumRevIndex;
  real_T rtb_Add1;
  real_T rtb_Gain1;
  real_T z;
  int32_T qY;
  int32_T rtb_Encoder;
  uint32_T tmp;
  uint32_T tmp_0;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Add1 = PID_Controller_Test_P.Constant1_Value_c -
    PID_Controller_Test_DW.PositionIntegration_DSTATE;

  /* MATLABSystem: '<S15>/Encoder' */
  if (PID_Controller_Test_DW.obj_d.TunablePropsChanged) {
    PID_Controller_Test_DW.obj_d.TunablePropsChanged = false;
  }

  MW_EncoderRead(PID_Controller_Test_DW.obj_d.Index, &rtb_Encoder);
  MW_EncoderReset(PID_Controller_Test_DW.obj_d.Index);

  /* End of MATLABSystem: '<S15>/Encoder' */
  /* MATLAB Function: '<S15>/Filter for data dropouts' */
  if (!PID_Controller_Test_DW.prevVal_not_empty) {
    PID_Controller_Test_DW.prevVal = rtb_Encoder;
    PID_Controller_Test_DW.prevVal_not_empty = true;
  }

  if ((rtb_Encoder >= 0L) && (PID_Controller_Test_DW.prevVal < rtb_Encoder -
       MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((rtb_Encoder < 0L) && (PID_Controller_Test_DW.prevVal > rtb_Encoder
              - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = rtb_Encoder - PID_Controller_Test_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY > 200L) {
    rtb_Encoder = PID_Controller_Test_DW.prevVal;
  } else {
    if (rtb_Encoder < 0L) {
      if (rtb_Encoder <= MIN_int32_T) {
        qY = MAX_int32_T;
      } else {
        qY = -rtb_Encoder;
      }
    } else {
      qY = rtb_Encoder;
    }

    if (qY > 500L) {
      rtb_Encoder = PID_Controller_Test_DW.prevVal;
    } else {
      PID_Controller_Test_DW.prevVal = rtb_Encoder;
    }
  }

  /* End of MATLAB Function: '<S15>/Filter for data dropouts' */

  /* Gain: '<S15>/Ticks to RPM' */
  tmp = (uint32_T)PID_Controller_Test_P.TickstoRPM_Gain;
  tmp_0 = (uint32_T)rtb_Encoder;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TickstoRPM.chunks[0U], 2);

  /* MATLABSystem: '<S15>/Moving Average' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (PID_Controller_Test_DW.obj_n.TunablePropsChanged) {
    PID_Controller_Test_DW.obj_n.TunablePropsChanged = false;
  }

  z = 0.0;
  rtb_Gain1 = 0.0;
  csum = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    7.4505805969238281E-9 + PID_Controller_Test_DW.obj_n.pCumSum;
  if (PID_Controller_Test_DW.obj_n.pModValueRev == 0.0) {
    z = PID_Controller_Test_DW.obj_n.pCumSumRev[(int16_T)
      PID_Controller_Test_DW.obj_n.pCumRevIndex - 1] + csum;
  }

  PID_Controller_Test_DW.obj_n.pCumSumRev[(int16_T)
    PID_Controller_Test_DW.obj_n.pCumRevIndex - 1] = sMultiWord2Double
    (&rtb_TickstoRPM.chunks[0U], 2, 0) * 7.4505805969238281E-9;
  if (PID_Controller_Test_DW.obj_n.pCumRevIndex != 3.0) {
    cumRevIndex = PID_Controller_Test_DW.obj_n.pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    PID_Controller_Test_DW.obj_n.pCumSumRev[1] +=
      PID_Controller_Test_DW.obj_n.pCumSumRev[2];
    PID_Controller_Test_DW.obj_n.pCumSumRev[0] +=
      PID_Controller_Test_DW.obj_n.pCumSumRev[1];
  }

  if (PID_Controller_Test_DW.obj_n.pModValueRev == 0.0) {
    rtb_Gain1 = z / 4.0;
  }

  PID_Controller_Test_DW.obj_n.pCumSum = csum;
  PID_Controller_Test_DW.obj_n.pCumRevIndex = cumRevIndex;
  if (PID_Controller_Test_DW.obj_n.pModValueRev > 0.0) {
    PID_Controller_Test_DW.obj_n.pModValueRev--;
  } else {
    PID_Controller_Test_DW.obj_n.pModValueRev = 0.0;
  }

  /* Gain: '<S3>/rad//s to m//s' incorporates:
   *  Gain: '<S3>/RPM to rad//s'
   *  MATLABSystem: '<S15>/Moving Average'
   */
  z = PID_Controller_Test_P.RPMtorads_Gain * rtb_Gain1 *
    PID_Controller_Test_P.radstoms_Gain;

  /* Gain: '<S4>/Gain1' */
  rtb_Gain1 = PID_Controller_Test_P.Gain1_Gain * z;

  /* RateTransition generated from: '<S4>/Add2' */
  PID_Controller_Test_DW.TmpRTBAtAdd2Inport1_Buffer0 = rtb_Gain1;

  /* Gain: '<S107>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S99>/Filter'
   *  Gain: '<S97>/Derivative Gain'
   *  Sum: '<S99>/SumD'
   */
  rtb_Gain1 = (PID_Controller_Test_P.PIDController1_D * rtb_Add1 -
               PID_Controller_Test_DW.Filter_DSTATE_j) *
    PID_Controller_Test_P.PIDController1_N;

  /* RateTransition: '<Root>/RT' */
  PID_Controller_Test_DW.RT_Buffer0 =
    PID_Controller_Test_DW.PositionIntegration_DSTATE;

  /* RateTransition: '<Root>/RT1' */
  PID_Controller_Test_DW.RT1_Buffer0 = z;

  /* RateTransition generated from: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S104>/Integrator'
   *  Gain: '<S109>/Proportional Gain'
   *  Sum: '<S113>/Sum'
   */
  PID_Controller_Test_DW.TmpRTBAtSum1Inport2_Buffer0 =
    (PID_Controller_Test_P.PIDController1_P * rtb_Add1 +
     PID_Controller_Test_DW.Integrator_DSTATE_l) + rtb_Gain1;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  PID_Controller_Test_DW.PositionIntegration_DSTATE +=
    PID_Controller_Test_P.PositionIntegration_gainval * z;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  if (PID_Controller_Test_DW.PositionIntegration_DSTATE >
      PID_Controller_Test_P.PositionIntegration_UpperSat) {
    /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
    PID_Controller_Test_DW.PositionIntegration_DSTATE =
      PID_Controller_Test_P.PositionIntegration_UpperSat;
  } else if (PID_Controller_Test_DW.PositionIntegration_DSTATE <
             PID_Controller_Test_P.PositionIntegration_LowerSat) {
    /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
    PID_Controller_Test_DW.PositionIntegration_DSTATE =
      PID_Controller_Test_P.PositionIntegration_LowerSat;
  }

  /* Update for DiscreteIntegrator: '<S99>/Filter' */
  PID_Controller_Test_DW.Filter_DSTATE_j +=
    PID_Controller_Test_P.Filter_gainval_i * rtb_Gain1;

  /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
   *  Gain: '<S101>/Integral Gain'
   */
  PID_Controller_Test_DW.Integrator_DSTATE_l +=
    PID_Controller_Test_P.PIDController1_I * rtb_Add1 *
    PID_Controller_Test_P.Integrator_gainval_b;
}

/* Model initialize function */
void PID_Controller_Test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_Controller_Test_M, 0,
                sizeof(RT_MODEL_PID_Controller_Test_T));

  /* block I/O */
  (void) memset(((void *) &PID_Controller_Test_B), 0,
                sizeof(B_PID_Controller_Test_T));

  /* states (dwork) */
  (void) memset((void *)&PID_Controller_Test_DW, 0,
                sizeof(DW_PID_Controller_Test_T));

  /* Start for RateTransition: '<Root>/RT' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PID_Controller_Test_B.StateVector[0] =
    PID_Controller_Test_P.RT_InitialCondition;

  /* Start for RateTransition: '<Root>/RT1' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PID_Controller_Test_B.StateVector[1] =
    PID_Controller_Test_P.RT1_InitialCondition;

  /* Start for MATLABSystem: '<S1>/Analog Input1' */
  PID_Controller_Test_DW.obj_g.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_n = true;
  PID_Controller_Test_DW.obj_g.isInitialized = 1L;
  PID_Controller_Test_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  PID_Controller_Test_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  PID_Controller_Test_DW.obj.isInitialized = 0L;
  PID_Controller_Test_DW.obj.NumChannels = -1L;
  PID_Controller_Test_DW.obj.FrameLength = -1L;
  PID_Controller_Test_DW.obj.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_mp = true;
  PID_Controller_SystemCore_setup(&PID_Controller_Test_DW.obj);

  /* Start for RateTransition generated from: '<S4>/Add2' */
  PID_Controller_Test_B.TmpRTBAtAdd2Inport1 =
    PID_Controller_Test_P.TmpRTBAtAdd2Inport1_InitialCond;

  /* Start for RateTransition generated from: '<Root>/Sum1' */
  PID_Controller_Test_B.TmpRTBAtSum1Inport2 =
    PID_Controller_Test_P.TmpRTBAtSum1Inport2_InitialCond;

  /* Start for MATLABSystem: '<S3>/PWM' */
  PID_Controller_Test_DW.obj_gm.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_m2 = true;
  PID_Controller_Test_DW.obj_gm.isInitialized = 1L;
  PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL,
    0.0, 0.0);
  PID_Controller_Test_DW.obj_gm.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  PID_Controller_Test_DW.obj_k.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_l = true;
  PID_Controller_Test_DW.obj_k.isInitialized = 1L;
  PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0,
    0.0);
  PID_Controller_Test_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Output1' */
  PID_Controller_Test_DW.obj_e.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_m = true;
  PID_Controller_Test_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(7, 1);
  PID_Controller_Test_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Output2' */
  PID_Controller_Test_DW.obj_p.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty = true;
  PID_Controller_Test_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(8, 1);
  PID_Controller_Test_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S15>/Encoder' */
  PID_Controller_Test_DW.obj_d.Index = 0U;
  PID_Controller_Test_DW.obj_d.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_j = true;
  PID_Controller_Test_DW.obj_d.isSetupComplete = false;
  PID_Controller_Test_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &PID_Controller_Test_DW.obj_d.Index);
  PID_Controller_Test_DW.obj_d.isSetupComplete = true;
  PID_Controller_Test_DW.obj_d.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S15>/Moving Average' */
  PID_Controller_Test_DW.obj_n.isInitialized = 0L;
  PID_Controller_Test_DW.obj_n.NumChannels = -1L;
  PID_Controller_Test_DW.obj_n.FrameLength = -1L;
  PID_Controller_Test_DW.obj_n.matlabCodegenIsDeleted = false;
  PID_Controller_Test_DW.objisempty_c = true;
  PID_Controll_SystemCore_setup_l(&PID_Controller_Test_DW.obj_n);

  /* InitializeConditions for RateTransition: '<Root>/RT' */
  PID_Controller_Test_DW.RT_Buffer0 = PID_Controller_Test_P.RT_InitialCondition;

  /* InitializeConditions for RateTransition: '<Root>/RT1' */
  PID_Controller_Test_DW.RT1_Buffer0 =
    PID_Controller_Test_P.RT1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S8>/UD' */
  PID_Controller_Test_DW.UD_DSTATE =
    PID_Controller_Test_P.Derivative_ICPrevScaledInput;

  /* InitializeConditions for RateTransition generated from: '<S4>/Add2' */
  PID_Controller_Test_DW.TmpRTBAtAdd2Inport1_Buffer0 =
    PID_Controller_Test_P.TmpRTBAtAdd2Inport1_InitialCond;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Integrator' */
  PID_Controller_Test_DW.Integrator_DSTATE =
    PID_Controller_Test_P.PIDController_InitialConditio_f;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Filter' */
  PID_Controller_Test_DW.Filter_DSTATE =
    PID_Controller_Test_P.PIDController_InitialConditionF;

  /* InitializeConditions for RateTransition generated from: '<Root>/Sum1' */
  PID_Controller_Test_DW.TmpRTBAtSum1Inport2_Buffer0 =
    PID_Controller_Test_P.TmpRTBAtSum1Inport2_InitialCond;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Position Integration' */
  PID_Controller_Test_DW.PositionIntegration_DSTATE =
    PID_Controller_Test_P.PositionIntegration_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Filter' */
  PID_Controller_Test_DW.Filter_DSTATE_j =
    PID_Controller_Test_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  PID_Controller_Test_DW.Integrator_DSTATE_l =
    PID_Controller_Test_P.PIDController1_InitialConditi_g;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  PID_Controller_Test_DW.N = 250.0;
  PID_Controller_Test_DW.sample_count = 0.0;
  PID_Controller_Test_DW.theta_sum = 0.0;
  PID_Controller_Test_DW.theta0 = 0.0;
  PID_Controller_Test_DW.calibrated = false;

  /* SystemInitialize for IfAction SubSystem: '<S2>/Swing Up' */
  /* SystemInitialize for MATLAB Function: '<S12>/MATLAB Function1' */
  PID_Controller_Test_DW.thetaMax_not_empty = false;

  /* End of SystemInitialize for SubSystem: '<S2>/Swing Up' */

  /* SystemInitialize for MATLAB Function: '<S15>/Filter for data dropouts' */
  PID_Controller_Test_DW.prevVal_not_empty = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  PID_Controller_Test_DW.obj.pCumSum = 0.0;
  memset(&PID_Controller_Test_DW.obj.pCumSumRev[0], 0, 11U * sizeof(real_T));
  PID_Controller_Test_DW.obj.pCumRevIndex = 1.0;
  PID_Controller_Test_DW.obj.pModValueRev = 0.0;

  /* InitializeConditions for MATLABSystem: '<S15>/Encoder' */
  MW_EncoderReset(PID_Controller_Test_DW.obj_d.Index);

  /* InitializeConditions for MATLABSystem: '<S15>/Moving Average' */
  PID_Controller_Test_DW.obj_n.pCumSum = 0.0;
  PID_Controller_Test_DW.obj_n.pCumSumRev[0] = 0.0;
  PID_Controller_Test_DW.obj_n.pCumSumRev[1] = 0.0;
  PID_Controller_Test_DW.obj_n.pCumSumRev[2] = 0.0;
  PID_Controller_Test_DW.obj_n.pCumRevIndex = 1.0;
  PID_Controller_Test_DW.obj_n.pModValueRev = 0.0;
}

/* Model terminate function */
void PID_Controller_Test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  if (!PID_Controller_Test_DW.obj_g.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj_g.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj_g.isSetupComplete) {
      PID_Controller_Test_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (PID_Controller_Test_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input1' */

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!PID_Controller_Test_DW.obj.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj.isSetupComplete) {
      PID_Controller_Test_DW.obj.NumChannels = -1L;
      PID_Controller_Test_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!PID_Controller_Test_DW.obj_gm.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_gm.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj_gm.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj_gm.isSetupComplete) {
      PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close(PID_Controller_Test_DW.obj_gm.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  if (!PID_Controller_Test_DW.obj_k.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj_k.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj_k.isSetupComplete) {
      PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_SetDutyCycle
        (PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_Close(PID_Controller_Test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM1' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output1' */
  if (!PID_Controller_Test_DW.obj_e.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output2' */
  if (!PID_Controller_Test_DW.obj_p.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S15>/Encoder' */
  if (!PID_Controller_Test_DW.obj_d.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj_d.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Encoder' */

  /* Terminate for MATLABSystem: '<S15>/Moving Average' */
  if (!PID_Controller_Test_DW.obj_n.matlabCodegenIsDeleted) {
    PID_Controller_Test_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PID_Controller_Test_DW.obj_n.isInitialized == 1L) &&
        PID_Controller_Test_DW.obj_n.isSetupComplete) {
      PID_Controller_Test_DW.obj_n.NumChannels = -1L;
      PID_Controller_Test_DW.obj_n.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Moving Average' */
}
