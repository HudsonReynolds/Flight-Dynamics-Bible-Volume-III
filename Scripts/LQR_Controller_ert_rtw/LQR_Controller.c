/*
 * LQR_Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Thu Jul 31 20:20:50 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_Controller.h"
#include "LQR_Controller_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "LQR_Controller_private.h"
#include "multiword_types.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for MATLAB Function: '<S7>/Filter for data dropouts' */
#define LQR_Controller_CALL_EVENT      (-1L)

/* Block signals (default storage) */
B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
DW_LQR_Controller_T LQR_Controller_DW;

/* Real-time model */
static RT_MODEL_LQR_Controller_T LQR_Controller_M_;
RT_MODEL_LQR_Controller_T *const LQR_Controller_M = &LQR_Controller_M_;

/* Forward declaration for local functions */
static void LQR_Controller_SystemCore_setup(dsp_simulink_MovingAverage_LQ_T *obj);
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
void LQR_Controller_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(LQR_Controller_M, 1));
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
  (LQR_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((LQR_Controller_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.02s, 0.0s] */
    LQR_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void LQR_Controller_SystemCore_setup(dsp_simulink_MovingAverage_LQ_T *obj)
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
void LQR_Controller_step0(void)        /* Sample time: [0.01s, 0.0s] */
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
  LQR_Controller_M->Timing.clockTick0++;
  if (!LQR_Controller_M->Timing.clockTick0) {
    LQR_Controller_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void LQR_Controller_step1(void)        /* Sample time: [0.02s, 0.0s] */
{
  int64m_T rtb_TickstoRPM;
  real_T csum;
  real_T cumRevIndex;
  real_T negPWM;
  real_T z;
  int32_T qY;
  uint32_T tmp;
  uint32_T tmp_0;
  uint16_T b_varargout_1;
  uint8_T tmp_1;

  /* MATLABSystem: '<S7>/Encoder' */
  if (LQR_Controller_DW.obj_l.TunablePropsChanged) {
    LQR_Controller_DW.obj_l.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderRead(LQR_Controller_DW.obj_l.Index, &LQR_Controller_B.Encoder);

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(LQR_Controller_DW.obj_l.Index);

  /* MATLAB Function: '<S7>/Filter for data dropouts' */
  LQR_Controller_DW.sfEvent_e = LQR_Controller_CALL_EVENT;
  if (!LQR_Controller_DW.prevVal_not_empty) {
    LQR_Controller_DW.prevVal = LQR_Controller_B.Encoder;
    LQR_Controller_DW.prevVal_not_empty = true;
  }

  if ((LQR_Controller_B.Encoder >= 0L) && (LQR_Controller_DW.prevVal <
       LQR_Controller_B.Encoder - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((LQR_Controller_B.Encoder < 0L) && (LQR_Controller_DW.prevVal >
              LQR_Controller_B.Encoder - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = LQR_Controller_B.Encoder - LQR_Controller_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY <= 200L) {
    LQR_Controller_DW.prevVal = LQR_Controller_B.Encoder;
  }

  /* End of MATLAB Function: '<S7>/Filter for data dropouts' */

  /* Gain: '<S7>/Ticks to RPM' */
  tmp = (uint32_T)LQR_Controller_P.TickstoRPM_Gain;
  tmp_0 = (uint32_T)LQR_Controller_DW.prevVal;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TickstoRPM.chunks[0U], 2);

  /* MATLABSystem: '<S7>/Moving Average' */
  if (LQR_Controller_DW.obj.TunablePropsChanged) {
    LQR_Controller_DW.obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* MATLABSystem: '<S7>/Moving Average' */
  LQR_Controller_B.MovingAverage = 0.0;

  /* MATLABSystem: '<S7>/Moving Average' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  csum = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    1.862645149230957E-9 + LQR_Controller_DW.obj.pCumSum;
  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    z = LQR_Controller_DW.obj.pCumSumRev[(int16_T)
      LQR_Controller_DW.obj.pCumRevIndex - 1] + csum;
  }

  LQR_Controller_DW.obj.pCumSumRev[(int16_T)LQR_Controller_DW.obj.pCumRevIndex -
    1] = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    1.862645149230957E-9;
  if (LQR_Controller_DW.obj.pCumRevIndex != 3.0) {
    cumRevIndex = LQR_Controller_DW.obj.pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    LQR_Controller_DW.obj.pCumSumRev[1] += LQR_Controller_DW.obj.pCumSumRev[2];
    LQR_Controller_DW.obj.pCumSumRev[0] += LQR_Controller_DW.obj.pCumSumRev[1];
  }

  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    /* MATLABSystem: '<S7>/Moving Average' */
    LQR_Controller_B.MovingAverage = z / 4.0;
  }

  LQR_Controller_DW.obj.pCumSum = csum;
  LQR_Controller_DW.obj.pCumRevIndex = cumRevIndex;
  if (LQR_Controller_DW.obj.pModValueRev > 0.0) {
    LQR_Controller_DW.obj.pModValueRev--;
  } else {
    LQR_Controller_DW.obj.pModValueRev = 0.0;
  }

  /* Gain: '<S3>/RPM to rad//s' */
  z = LQR_Controller_P.RPMtorads_Gain * LQR_Controller_B.MovingAverage;

  /* Gain: '<S3>/rad//s to m//s' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[1] = LQR_Controller_P.radstoms_Gain * z;

  /* MATLABSystem: '<S1>/Analog Input' */
  LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Volt2Rad'
   *  MATLABSystem: '<S1>/Analog Input'
   * */
  LQR_Controller_B.PendulumAngle = (real_T)((uint32_T)
    LQR_Controller_P.Volt2Rad_Gain * b_varargout_1) * 1.1920928955078125E-7 +
    LQR_Controller_P.Constant_Value;

  /* Sum: '<Root>/Add1' incorporates:
   *  Concatenate: '<Root>/State Vector'
   *  Constant: '<Root>/Constant2'
   */
  LQR_Controller_B.StateVector[2] = LQR_Controller_B.PendulumAngle -
    LQR_Controller_P.Constant2_Value;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  csum = LQR_Controller_B.PendulumAngle * LQR_Controller_P.TSamp_WtEt;

  /* Sum: '<S5>/Diff' incorporates:
   *  UnitDelay: '<S5>/UD'
   */
  LQR_Controller_B.Diff = csum - LQR_Controller_DW.UD_DSTATE;

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[3] = LQR_Controller_B.Diff;

  /* Abs: '<Root>/Abs' incorporates:
   *  Constant: '<Root>/Pi'
   *  Sum: '<Root>/Add'
   */
  LQR_Controller_B.Abs = fabs(LQR_Controller_B.PendulumAngle -
    LQR_Controller_P.Pi_Value);

  /* DiscreteIntegrator: '<S3>/Position Integration' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[0] = LQR_Controller_DW.PositionIntegration_DSTATE;

  /* Gain: '<Root>/LQR Gains' */
  LQR_Controller_B.LQRGains = ((LQR_Controller_P.LQRGains_Gain[0] *
    LQR_Controller_B.StateVector[0] + LQR_Controller_P.LQRGains_Gain[1] *
    LQR_Controller_B.StateVector[1]) + LQR_Controller_P.LQRGains_Gain[2] *
    LQR_Controller_B.StateVector[2]) + LQR_Controller_P.LQRGains_Gain[3] *
    LQR_Controller_B.StateVector[3];

  /* Gain: '<Root>/Gain1' */
  LQR_Controller_B.Gain1 = LQR_Controller_P.Gain1_Gain *
    LQR_Controller_B.LQRGains;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (LQR_Controller_B.Abs > LQR_Controller_P.Switch_Threshold) {
    cumRevIndex = LQR_Controller_P.Constant1_Value;
  } else {
    cumRevIndex = LQR_Controller_B.Gain1;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<S3>/Select PWM Direction' */
  LQR_Controller_DW.sfEvent = LQR_Controller_CALL_EVENT;
  if (cumRevIndex > 0.0) {
    negPWM = 0.0;
  } else {
    negPWM = -cumRevIndex;
    cumRevIndex = 0.0;
  }

  /* End of MATLAB Function: '<S3>/Select PWM Direction' */

  /* MATLABSystem: '<S3>/PWM' */
  LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S3>/PWM' */
  if (!(cumRevIndex <= 255.0)) {
    cumRevIndex = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                      cumRevIndex);

  /* MATLABSystem: '<S3>/PWM1' */
  LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!(negPWM <= 255.0)) {
    negPWM = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, negPWM);

  /* MATLABSystem: '<S4>/Digital Output1' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  cumRevIndex = rt_roundd_snf(LQR_Controller_P.Constant2_Value_i);
  if (cumRevIndex < 256.0) {
    if (cumRevIndex >= 0.0) {
      tmp_1 = (uint8_T)cumRevIndex;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_1);

  /* End of MATLABSystem: '<S4>/Digital Output1' */

  /* MATLABSystem: '<S4>/Digital Output2' */
  if (cumRevIndex < 256.0) {
    if (cumRevIndex >= 0.0) {
      tmp_1 = (uint8_T)cumRevIndex;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_1);

  /* End of MATLABSystem: '<S4>/Digital Output2' */
  /* Update for UnitDelay: '<S5>/UD' */
  LQR_Controller_DW.UD_DSTATE = csum;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE +=
    LQR_Controller_P.PositionIntegration_gainval * z;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  LQR_Controller_M->Timing.clockTick1++;
  if (!LQR_Controller_M->Timing.clockTick1) {
    LQR_Controller_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void LQR_Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LQR_Controller_M, 0,
                sizeof(RT_MODEL_LQR_Controller_T));
  rtmSetTFinal(LQR_Controller_M, -1);

  /* External mode info */
  LQR_Controller_M->Sizes.checksums[0] = (1609701125U);
  LQR_Controller_M->Sizes.checksums[1] = (1392714508U);
  LQR_Controller_M->Sizes.checksums[2] = (3304185797U);
  LQR_Controller_M->Sizes.checksums[3] = (680619959U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    LQR_Controller_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(LQR_Controller_M->extModeInfo,
      &LQR_Controller_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LQR_Controller_M->extModeInfo,
                        LQR_Controller_M->Sizes.checksums);
    rteiSetTFinalTicks(LQR_Controller_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &LQR_Controller_B), 0,
                sizeof(B_LQR_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&LQR_Controller_DW, 0,
                sizeof(DW_LQR_Controller_T));

  /* Start for MATLABSystem: '<S7>/Encoder' */
  LQR_Controller_DW.obj_l.Index = 0U;
  LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_m = true;
  LQR_Controller_DW.obj_l.isSetupComplete = false;
  LQR_Controller_DW.obj_l.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &LQR_Controller_DW.obj_l.Index);
  LQR_Controller_DW.obj_l.isSetupComplete = true;
  LQR_Controller_DW.obj_l.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S7>/Moving Average' */
  LQR_Controller_DW.obj.isInitialized = 0L;
  LQR_Controller_DW.obj.NumChannels = -1L;
  LQR_Controller_DW.obj.FrameLength = -1L;
  LQR_Controller_DW.obj.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_o = true;
  LQR_Controller_SystemCore_setup(&LQR_Controller_DW.obj);

  /* Start for MATLABSystem: '<S1>/Analog Input' */
  LQR_Controller_DW.obj_h.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_i = true;
  LQR_Controller_DW.obj_h.isInitialized = 1L;
  LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  LQR_Controller_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM' */
  LQR_Controller_DW.obj_d.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_f = true;
  LQR_Controller_DW.obj_d.isInitialized = 1L;
  LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  LQR_Controller_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  LQR_Controller_DW.obj_e.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_og = true;
  LQR_Controller_DW.obj_e.isInitialized = 1L;
  LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  LQR_Controller_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_j = true;
  LQR_Controller_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(7, 1);
  LQR_Controller_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output2' */
  LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty = true;
  LQR_Controller_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  LQR_Controller_DW.obj_m.isSetupComplete = true;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  LQR_Controller_DW.UD_DSTATE = LQR_Controller_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE =
    LQR_Controller_P.PositionIntegration_IC;

  /* SystemInitialize for MATLAB Function: '<S7>/Filter for data dropouts' */
  LQR_Controller_DW.prevVal_not_empty = false;
  LQR_Controller_DW.sfEvent_e = LQR_Controller_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S3>/Select PWM Direction' */
  LQR_Controller_DW.sfEvent = LQR_Controller_CALL_EVENT;

  /* InitializeConditions for MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(LQR_Controller_DW.obj_l.Index);

  /* InitializeConditions for MATLABSystem: '<S7>/Moving Average' */
  LQR_Controller_DW.obj.pCumSum = 0.0;
  LQR_Controller_DW.obj.pCumSumRev[0] = 0.0;
  LQR_Controller_DW.obj.pCumSumRev[1] = 0.0;
  LQR_Controller_DW.obj.pCumSumRev[2] = 0.0;
  LQR_Controller_DW.obj.pCumRevIndex = 1.0;
  LQR_Controller_DW.obj.pModValueRev = 0.0;
}

/* Model terminate function */
void LQR_Controller_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Encoder' */
  if (!LQR_Controller_DW.obj_l.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_l.isInitialized == 1L) &&
        LQR_Controller_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Encoder' */

  /* Terminate for MATLABSystem: '<S7>/Moving Average' */
  if (!LQR_Controller_DW.obj.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj.isInitialized == 1L) &&
        LQR_Controller_DW.obj.isSetupComplete) {
      LQR_Controller_DW.obj.NumChannels = -1L;
      LQR_Controller_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Moving Average' */
  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  if (!LQR_Controller_DW.obj_h.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_h.isInitialized == 1L) &&
        LQR_Controller_DW.obj_h.isSetupComplete) {
      LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input' */
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!LQR_Controller_DW.obj_d.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_d.isInitialized == 1L) &&
        LQR_Controller_DW.obj_d.isSetupComplete) {
      LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  if (!LQR_Controller_DW.obj_e.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_e.isInitialized == 1L) &&
        LQR_Controller_DW.obj_e.isSetupComplete) {
      LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM1' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!LQR_Controller_DW.obj_n.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output2' */
  if (!LQR_Controller_DW.obj_m.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output2' */
}
