/*
 * PWMStepTest.c
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
#include "PWMStepTest_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "PWMStepTest_private.h"
#include "multiword_types.h"
#include <string.h>

/* Named constants for MATLAB Function: '<S7>/Filter for data dropouts' */
#define PWMStepTest_CALL_EVENT         (-1L)

/* Block signals (default storage) */
B_PWMStepTest_T PWMStepTest_B;

/* Block states (default storage) */
DW_PWMStepTest_T PWMStepTest_DW;

/* Real-time model */
static RT_MODEL_PWMStepTest_T PWMStepTest_M_;
RT_MODEL_PWMStepTest_T *const PWMStepTest_M = &PWMStepTest_M_;

/* Forward declaration for local functions */
static void PWMStepTest_SystemCore_setup_k(dsp_simulink_MovingAverage_k_T *obj);
static void PWMStepTest_SystemCore_setup(dsp_simulink_MovingAverage_PW_T *obj);
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
void PWMStepTest_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PWMStepTest_M, 1));
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PWMStepTest_M->Timing.TaskCounters.TID[1])++;
  if ((PWMStepTest_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.02s, 0.0s] */
    PWMStepTest_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void PWMStepTest_SystemCore_setup_k(dsp_simulink_MovingAverage_k_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S7>/Moving Average' */
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

static void PWMStepTest_SystemCore_setup(dsp_simulink_MovingAverage_PW_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  obj->NumChannels = 1L;
  obj->FrameLength = 1L;
  obj->pCumSum = 0.0;
  obj->pCumSumRev[0] = 0.0;
  obj->pCumSumRev[1] = 0.0;
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
void PWMStepTest_step0(void)           /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  PWMStepTest_M->Timing.clockTick0++;
  if (!PWMStepTest_M->Timing.clockTick0) {
    PWMStepTest_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void PWMStepTest_step1(void)           /* Sample time: [0.02s, 0.0s] */
{
  int64m_T rtb_TickstoRPM;
  real_T Diff;
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int32_T qY;
  uint32_T tmp;
  uint32_T tmp_0;
  int16_T cumRevIndex_0;
  uint16_T b_varargout_1;
  uint8_T tmp_1;

  /* DiscreteIntegrator: '<S3>/Position Integration' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PWMStepTest_B.Sum[0] = PWMStepTest_DW.PositionIntegration_DSTATE;

  /* MATLABSystem: '<S7>/Encoder' */
  if (PWMStepTest_DW.obj_l.TunablePropsChanged) {
    PWMStepTest_DW.obj_l.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderRead(PWMStepTest_DW.obj_l.Index, &PWMStepTest_B.Encoder);

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(PWMStepTest_DW.obj_l.Index);

  /* MATLAB Function: '<S7>/Filter for data dropouts' */
  PWMStepTest_DW.sfEvent_e = PWMStepTest_CALL_EVENT;
  if (!PWMStepTest_DW.prevVal_not_empty) {
    PWMStepTest_DW.prevVal = PWMStepTest_B.Encoder;
    PWMStepTest_DW.prevVal_not_empty = true;
  }

  if ((PWMStepTest_B.Encoder >= 0L) && (PWMStepTest_DW.prevVal <
       PWMStepTest_B.Encoder - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((PWMStepTest_B.Encoder < 0L) && (PWMStepTest_DW.prevVal >
              PWMStepTest_B.Encoder - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = PWMStepTest_B.Encoder - PWMStepTest_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY <= 200L) {
    PWMStepTest_DW.prevVal = PWMStepTest_B.Encoder;
  }

  /* End of MATLAB Function: '<S7>/Filter for data dropouts' */

  /* Gain: '<S7>/Ticks to RPM' */
  tmp = (uint32_T)PWMStepTest_P.TickstoRPM_Gain;
  tmp_0 = (uint32_T)PWMStepTest_DW.prevVal;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TickstoRPM.chunks[0U], 2);

  /* MATLABSystem: '<S7>/Moving Average' */
  if (PWMStepTest_DW.obj.TunablePropsChanged) {
    PWMStepTest_DW.obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* MATLABSystem: '<S7>/Moving Average' */
  PWMStepTest_B.MovingAverage = 0.0;

  /* MATLABSystem: '<S7>/Moving Average' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  csum = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    1.862645149230957E-9 + PWMStepTest_DW.obj.pCumSum;
  if (PWMStepTest_DW.obj.pModValueRev == 0.0) {
    z = PWMStepTest_DW.obj.pCumSumRev[(int16_T)PWMStepTest_DW.obj.pCumRevIndex -
      1] + csum;
  }

  PWMStepTest_DW.obj.pCumSumRev[(int16_T)PWMStepTest_DW.obj.pCumRevIndex - 1] =
    sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) * 1.862645149230957E-9;
  if (PWMStepTest_DW.obj.pCumRevIndex != 3.0) {
    cumRevIndex = PWMStepTest_DW.obj.pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    PWMStepTest_DW.obj.pCumSumRev[1] += PWMStepTest_DW.obj.pCumSumRev[2];
    PWMStepTest_DW.obj.pCumSumRev[0] += PWMStepTest_DW.obj.pCumSumRev[1];
  }

  if (PWMStepTest_DW.obj.pModValueRev == 0.0) {
    /* MATLABSystem: '<S7>/Moving Average' */
    PWMStepTest_B.MovingAverage = z / 4.0;
  }

  PWMStepTest_DW.obj.pCumSum = csum;
  PWMStepTest_DW.obj.pCumRevIndex = cumRevIndex;
  if (PWMStepTest_DW.obj.pModValueRev > 0.0) {
    PWMStepTest_DW.obj.pModValueRev--;
  } else {
    PWMStepTest_DW.obj.pModValueRev = 0.0;
  }

  /* Gain: '<S3>/rad//s to m//s' incorporates:
   *  Gain: '<S3>/RPM to rad//s'
   */
  PWMStepTest_B.radstoms = PWMStepTest_P.RPMtorads_Gain *
    PWMStepTest_B.MovingAverage * PWMStepTest_P.radstoms_Gain;

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PWMStepTest_B.Sum[1] = PWMStepTest_B.radstoms;

  /* MATLABSystem: '<S1>/Analog Input' */
  PWMStepTest_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (PWMStepTest_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Volt2Rad'
   *  MATLABSystem: '<S1>/Analog Input'
   * */
  PWMStepTest_B.PendulumAngle = (real_T)((uint32_T)PWMStepTest_P.Volt2Rad_Gain *
    b_varargout_1) * 1.1920928955078125E-7 + PWMStepTest_P.Constant_Value;

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PWMStepTest_B.Sum[2] = PWMStepTest_B.PendulumAngle;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  cumRevIndex = PWMStepTest_B.PendulumAngle * PWMStepTest_P.TSamp_WtEt;

  /* Sum: '<S5>/Diff' incorporates:
   *  UnitDelay: '<S5>/UD'
   */
  Diff = cumRevIndex - PWMStepTest_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (PWMStepTest_DW.obj_i.TunablePropsChanged) {
    PWMStepTest_DW.obj_i.TunablePropsChanged = false;
  }

  z = 0.0;

  /* SignalConversion generated from: '<S1>/Moving Average' incorporates:
   *  MATLABSystem: '<S1>/Moving Average'
   */
  PWMStepTest_B.TmpMLSysMemLayoutBufferAtMoving = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  csum = PWMStepTest_DW.obj_i.pCumSum + Diff;
  if (PWMStepTest_DW.obj_i.pModValueRev == 0.0) {
    z = PWMStepTest_DW.obj_i.pCumSumRev[(int16_T)
      PWMStepTest_DW.obj_i.pCumRevIndex - 1] + csum;
  }

  PWMStepTest_DW.obj_i.pCumSumRev[(int16_T)PWMStepTest_DW.obj_i.pCumRevIndex - 1]
    = Diff;
  if (PWMStepTest_DW.obj_i.pCumRevIndex != 2.0) {
    cumRevIndex_0 = 2;
  } else {
    cumRevIndex_0 = 1;
    csum = 0.0;
    PWMStepTest_DW.obj_i.pCumSumRev[0] += PWMStepTest_DW.obj_i.pCumSumRev[1];
  }

  if (PWMStepTest_DW.obj_i.pModValueRev == 0.0) {
    /* SignalConversion generated from: '<S1>/Moving Average' */
    PWMStepTest_B.TmpMLSysMemLayoutBufferAtMoving = z / 3.0;
  }

  PWMStepTest_DW.obj_i.pCumSum = csum;
  PWMStepTest_DW.obj_i.pCumRevIndex = cumRevIndex_0;
  if (PWMStepTest_DW.obj_i.pModValueRev > 0.0) {
    PWMStepTest_DW.obj_i.pModValueRev--;
  } else {
    PWMStepTest_DW.obj_i.pModValueRev = 0.0;
  }

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  PWMStepTest_B.Sum[3] = PWMStepTest_B.TmpMLSysMemLayoutBufferAtMoving;

  /* Sum: '<Root>/Sum' incorporates:
   *  Concatenate: '<Root>/State Vector'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   */
  PWMStepTest_B.Sum[0] -= PWMStepTest_P.Constant4_Value;
  PWMStepTest_B.Sum[1] -= PWMStepTest_P.Constant5_Value;
  PWMStepTest_B.Sum[2] -= PWMStepTest_P.Constant3_Value;
  PWMStepTest_B.Sum[3] -= PWMStepTest_P.Constant6_Value;

  /* Abs: '<Root>/Abs' incorporates:
   *  Constant: '<Root>/Pi'
   *  Sum: '<Root>/Add'
   */
  PWMStepTest_B.Abs = fabs(PWMStepTest_B.PendulumAngle - PWMStepTest_P.Pi_Value);

  /* Switch: '<Root>/Switch' */
  if (PWMStepTest_B.Abs > PWMStepTest_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    PWMStepTest_B.Switch = PWMStepTest_P.Constant1_Value;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    PWMStepTest_B.Switch = PWMStepTest_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch' */
  /* MATLAB Function: '<S3>/Select PWM Direction' */
  PWMStepTest_DW.sfEvent = PWMStepTest_CALL_EVENT;
  if (PWMStepTest_B.Switch > 0.0) {
    csum = PWMStepTest_B.Switch;
    z = 0.0;
  } else {
    z = -PWMStepTest_B.Switch;
    csum = 0.0;
  }

  /* End of MATLAB Function: '<S3>/Select PWM Direction' */

  /* MATLABSystem: '<S3>/PWM' */
  PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S3>/PWM' */
  if (!(csum <= 255.0)) {
    csum = 255.0;
  }

  if (!(csum >= 0.0)) {
    csum = 0.0;
  }

  /* MATLABSystem: '<S3>/PWM' */
  MW_PWM_SetDutyCycle(PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, csum);

  /* MATLABSystem: '<S3>/PWM1' */
  PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!(z <= 255.0)) {
    z = 255.0;
  }

  if (!(z >= 0.0)) {
    z = 0.0;
  }

  /* MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, z);

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   */
  PWMStepTest_B.Gain = PWMStepTest_P.Gain_Gain * PWMStepTest_P.Constant_Value_l;

  /* MATLABSystem: '<S4>/Digital Output1' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  z = rt_roundd_snf(PWMStepTest_P.Constant2_Value_i);
  if (z < 256.0) {
    if (z >= 0.0) {
      tmp_1 = (uint8_T)z;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_1);

  /* End of MATLABSystem: '<S4>/Digital Output1' */

  /* MATLABSystem: '<S4>/Digital Output2' */
  if (z < 256.0) {
    if (z >= 0.0) {
      tmp_1 = (uint8_T)z;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_1);

  /* End of MATLABSystem: '<S4>/Digital Output2' */

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  PWMStepTest_DW.PositionIntegration_DSTATE +=
    PWMStepTest_P.PositionIntegration_gainval * PWMStepTest_B.radstoms;

  /* Update for UnitDelay: '<S5>/UD' */
  PWMStepTest_DW.UD_DSTATE = cumRevIndex;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  PWMStepTest_M->Timing.clockTick1++;
  if (!PWMStepTest_M->Timing.clockTick1) {
    PWMStepTest_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void PWMStepTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PWMStepTest_M, 0,
                sizeof(RT_MODEL_PWMStepTest_T));
  rtmSetTFinal(PWMStepTest_M, -1);

  /* External mode info */
  PWMStepTest_M->Sizes.checksums[0] = (3590208948U);
  PWMStepTest_M->Sizes.checksums[1] = (3897952172U);
  PWMStepTest_M->Sizes.checksums[2] = (1103410657U);
  PWMStepTest_M->Sizes.checksums[3] = (209781470U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    PWMStepTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PWMStepTest_M->extModeInfo,
      &PWMStepTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PWMStepTest_M->extModeInfo,
                        PWMStepTest_M->Sizes.checksums);
    rteiSetTFinalTicks(PWMStepTest_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &PWMStepTest_B), 0,
                sizeof(B_PWMStepTest_T));

  /* states (dwork) */
  (void) memset((void *)&PWMStepTest_DW, 0,
                sizeof(DW_PWMStepTest_T));

  /* Start for MATLABSystem: '<S7>/Encoder' */
  PWMStepTest_DW.obj_l.Index = 0U;
  PWMStepTest_DW.obj_l.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_m = true;
  PWMStepTest_DW.obj_l.isSetupComplete = false;
  PWMStepTest_DW.obj_l.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &PWMStepTest_DW.obj_l.Index);
  PWMStepTest_DW.obj_l.isSetupComplete = true;
  PWMStepTest_DW.obj_l.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S7>/Moving Average' */
  PWMStepTest_DW.obj.isInitialized = 0L;
  PWMStepTest_DW.obj.NumChannels = -1L;
  PWMStepTest_DW.obj.FrameLength = -1L;
  PWMStepTest_DW.obj.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_o = true;
  PWMStepTest_SystemCore_setup_k(&PWMStepTest_DW.obj);

  /* Start for MATLABSystem: '<S1>/Analog Input' */
  PWMStepTest_DW.obj_h.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_i = true;
  PWMStepTest_DW.obj_h.isInitialized = 1L;
  PWMStepTest_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  PWMStepTest_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  PWMStepTest_DW.obj_i.isInitialized = 0L;
  PWMStepTest_DW.obj_i.NumChannels = -1L;
  PWMStepTest_DW.obj_i.FrameLength = -1L;
  PWMStepTest_DW.obj_i.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_c = true;
  PWMStepTest_SystemCore_setup(&PWMStepTest_DW.obj_i);

  /* Start for MATLABSystem: '<S3>/PWM' */
  PWMStepTest_DW.obj_d.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_f = true;
  PWMStepTest_DW.obj_d.isInitialized = 1L;
  PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  PWMStepTest_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  PWMStepTest_DW.obj_e.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_og = true;
  PWMStepTest_DW.obj_e.isInitialized = 1L;
  PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  PWMStepTest_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  PWMStepTest_DW.obj_n.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty_j = true;
  PWMStepTest_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(7, 1);
  PWMStepTest_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output2' */
  PWMStepTest_DW.obj_m.matlabCodegenIsDeleted = false;
  PWMStepTest_DW.objisempty = true;
  PWMStepTest_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  PWMStepTest_DW.obj_m.isSetupComplete = true;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Position Integration' */
  PWMStepTest_DW.PositionIntegration_DSTATE =
    PWMStepTest_P.PositionIntegration_IC;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  PWMStepTest_DW.UD_DSTATE = PWMStepTest_P.DiscreteDerivative_ICPrevScaled;

  /* SystemInitialize for MATLAB Function: '<S7>/Filter for data dropouts' */
  PWMStepTest_DW.prevVal_not_empty = false;
  PWMStepTest_DW.sfEvent_e = PWMStepTest_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S3>/Select PWM Direction' */
  PWMStepTest_DW.sfEvent = PWMStepTest_CALL_EVENT;

  /* InitializeConditions for MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(PWMStepTest_DW.obj_l.Index);

  /* InitializeConditions for MATLABSystem: '<S7>/Moving Average' */
  PWMStepTest_DW.obj.pCumSum = 0.0;
  PWMStepTest_DW.obj.pCumSumRev[0] = 0.0;
  PWMStepTest_DW.obj.pCumSumRev[1] = 0.0;
  PWMStepTest_DW.obj.pCumSumRev[2] = 0.0;
  PWMStepTest_DW.obj.pCumRevIndex = 1.0;
  PWMStepTest_DW.obj.pModValueRev = 0.0;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  PWMStepTest_DW.obj_i.pCumSum = 0.0;
  PWMStepTest_DW.obj_i.pCumSumRev[0] = 0.0;
  PWMStepTest_DW.obj_i.pCumSumRev[1] = 0.0;
  PWMStepTest_DW.obj_i.pCumRevIndex = 1.0;
  PWMStepTest_DW.obj_i.pModValueRev = 0.0;
}

/* Model terminate function */
void PWMStepTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Encoder' */
  if (!PWMStepTest_DW.obj_l.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj_l.isInitialized == 1L) &&
        PWMStepTest_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Encoder' */

  /* Terminate for MATLABSystem: '<S7>/Moving Average' */
  if (!PWMStepTest_DW.obj.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj.isInitialized == 1L) &&
        PWMStepTest_DW.obj.isSetupComplete) {
      PWMStepTest_DW.obj.NumChannels = -1L;
      PWMStepTest_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Moving Average' */

  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  if (!PWMStepTest_DW.obj_h.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj_h.isInitialized == 1L) &&
        PWMStepTest_DW.obj_h.isSetupComplete) {
      PWMStepTest_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (PWMStepTest_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input' */

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!PWMStepTest_DW.obj_i.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj_i.isInitialized == 1L) &&
        PWMStepTest_DW.obj_i.isSetupComplete) {
      PWMStepTest_DW.obj_i.NumChannels = -1L;
      PWMStepTest_DW.obj_i.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!PWMStepTest_DW.obj_d.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj_d.isInitialized == 1L) &&
        PWMStepTest_DW.obj_d.isSetupComplete) {
      PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(PWMStepTest_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  if (!PWMStepTest_DW.obj_e.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((PWMStepTest_DW.obj_e.isInitialized == 1L) &&
        PWMStepTest_DW.obj_e.isSetupComplete) {
      PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(PWMStepTest_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM1' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!PWMStepTest_DW.obj_n.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output2' */
  if (!PWMStepTest_DW.obj_m.matlabCodegenIsDeleted) {
    PWMStepTest_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output2' */
}
