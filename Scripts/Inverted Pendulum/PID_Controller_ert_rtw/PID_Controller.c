/*
 * PID_Controller.c
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
#include "PID_Controller_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "PID_Controller_private.h"
#include "multiword_types.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for MATLAB Function: '<S8>/Filter for data dropouts' */
#define PID_Controller_CALL_EVENT      (-1L)

/* Block signals (default storage) */
B_PID_Controller_T PID_Controller_B;

/* Block states (default storage) */
DW_PID_Controller_T PID_Controller_DW;

/* Real-time model */
static RT_MODEL_PID_Controller_T PID_Controller_M_;
RT_MODEL_PID_Controller_T *const PID_Controller_M = &PID_Controller_M_;

/* Forward declaration for local functions */
static void PID_Controller_SystemCore_setup(dsp_simulink_MovingAverage_PI_T *obj);
static void PID_Controll_SystemCore_setup_k(dsp_simulink_MovingAverage_k_T *obj);
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
void PID_Controller_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PID_Controller_M, 1));
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
  (PID_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((PID_Controller_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.02s, 0.0s] */
    PID_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void PID_Controller_SystemCore_setup(dsp_simulink_MovingAverage_PI_T *obj)
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

static void PID_Controll_SystemCore_setup_k(dsp_simulink_MovingAverage_k_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S8>/Moving Average' */
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
void PID_Controller_step0(void)        /* Sample time: [0.01s, 0.0s] */
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
  PID_Controller_M->Timing.clockTick0++;
  if (!PID_Controller_M->Timing.clockTick0) {
    PID_Controller_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void PID_Controller_step1(void)        /* Sample time: [0.02s, 0.0s] */
{
  int64m_T rtb_TickstoRPM;
  real_T Diff;
  real_T cumRevIndex_0;
  real_T rtb_FilterCoefficient;
  real_T rtb_TSamp;
  int32_T qY;
  uint32_T tmp;
  uint32_T tmp_0;
  int16_T cumRevIndex;
  uint16_T b_varargout_1;
  uint8_T tmp_1;

  /* MATLABSystem: '<S1>/Analog Input' */
  PID_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (PID_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Volt2Rad'
   *  MATLABSystem: '<S1>/Analog Input'
   * */
  PID_Controller_B.PendulumAngle = (real_T)((uint32_T)
    PID_Controller_P.Volt2Rad_Gain * b_varargout_1) * 1.1920928955078125E-7 +
    PID_Controller_P.Constant_Value;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = PID_Controller_B.PendulumAngle * PID_Controller_P.TSamp_WtEt;

  /* Sum: '<S6>/Diff' incorporates:
   *  UnitDelay: '<S6>/UD'
   */
  Diff = rtb_TSamp - PID_Controller_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (PID_Controller_DW.obj_i.TunablePropsChanged) {
    PID_Controller_DW.obj_i.TunablePropsChanged = false;
  }

  PID_Controller_B.z = 0.0;

  /* SignalConversion generated from: '<S1>/Moving Average' incorporates:
   *  MATLABSystem: '<S1>/Moving Average'
   */
  PID_Controller_B.TmpMLSysMemLayoutBufferAtMoving = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  PID_Controller_B.csum = PID_Controller_DW.obj_i.pCumSum + Diff;
  if (PID_Controller_DW.obj_i.pModValueRev == 0.0) {
    PID_Controller_B.z = PID_Controller_DW.obj_i.pCumSumRev[(int16_T)
      PID_Controller_DW.obj_i.pCumRevIndex - 1] + PID_Controller_B.csum;
  }

  PID_Controller_DW.obj_i.pCumSumRev[(int16_T)
    PID_Controller_DW.obj_i.pCumRevIndex - 1] = Diff;
  if (PID_Controller_DW.obj_i.pCumRevIndex != 2.0) {
    cumRevIndex = 2;
  } else {
    cumRevIndex = 1;
    PID_Controller_B.csum = 0.0;
    PID_Controller_DW.obj_i.pCumSumRev[0] += PID_Controller_DW.obj_i.pCumSumRev
      [1];
  }

  if (PID_Controller_DW.obj_i.pModValueRev == 0.0) {
    /* SignalConversion generated from: '<S1>/Moving Average' */
    PID_Controller_B.TmpMLSysMemLayoutBufferAtMoving = PID_Controller_B.z / 3.0;
  }

  PID_Controller_DW.obj_i.pCumSum = PID_Controller_B.csum;
  PID_Controller_DW.obj_i.pCumRevIndex = cumRevIndex;
  if (PID_Controller_DW.obj_i.pModValueRev > 0.0) {
    PID_Controller_DW.obj_i.pModValueRev--;
  } else {
    PID_Controller_DW.obj_i.pModValueRev = 0.0;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Pi'
   */
  Diff = PID_Controller_B.PendulumAngle - PID_Controller_P.Pi_Value;

  /* Gain: '<S100>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S92>/Filter'
   *  Gain: '<S90>/Derivative Gain'
   *  Sum: '<S92>/SumD'
   */
  rtb_FilterCoefficient = (PID_Controller_P.PIDController_D * Diff -
    PID_Controller_DW.Filter_DSTATE) * PID_Controller_P.PIDController_N;

  /* Sum: '<S106>/Sum' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   *  Gain: '<S102>/Proportional Gain'
   */
  PID_Controller_B.Saturation = (PID_Controller_P.PIDController_P * Diff +
    PID_Controller_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S104>/Saturation' */
  if (PID_Controller_B.Saturation >
      PID_Controller_P.PIDController_UpperSaturationLi) {
    /* Sum: '<S106>/Sum' incorporates:
     *  Saturate: '<S104>/Saturation'
     */
    PID_Controller_B.Saturation =
      PID_Controller_P.PIDController_UpperSaturationLi;
  } else if (PID_Controller_B.Saturation <
             PID_Controller_P.PIDController_LowerSaturationLi) {
    /* Sum: '<S106>/Sum' incorporates:
     *  Saturate: '<S104>/Saturation'
     */
    PID_Controller_B.Saturation =
      PID_Controller_P.PIDController_LowerSaturationLi;
  }

  /* End of Saturate: '<S104>/Saturation' */
  /* Abs: '<Root>/Abs' */
  PID_Controller_B.Abs = fabs(Diff);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PID_Controller_B.Abs > PID_Controller_P.Switch_Threshold) {
    PID_Controller_B.z = PID_Controller_P.Constant1_Value;
  } else {
    PID_Controller_B.z = PID_Controller_B.Saturation;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<S3>/Select PWM Direction' */
  PID_Controller_DW.sfEvent = PID_Controller_CALL_EVENT;
  if (PID_Controller_B.z > 0.0) {
    PID_Controller_B.csum = 0.0;
  } else {
    PID_Controller_B.csum = -PID_Controller_B.z;
    PID_Controller_B.z = 0.0;
  }

  /* End of MATLAB Function: '<S3>/Select PWM Direction' */

  /* MATLABSystem: '<S3>/PWM' */
  PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S3>/PWM' */
  if (!(PID_Controller_B.z <= 255.0)) {
    PID_Controller_B.z = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM' */
  MW_PWM_SetDutyCycle(PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                      PID_Controller_B.z);

  /* MATLABSystem: '<S3>/PWM1' */
  PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!(PID_Controller_B.csum <= 255.0)) {
    PID_Controller_B.csum = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      PID_Controller_B.csum);

  /* MATLABSystem: '<S8>/Encoder' */
  if (PID_Controller_DW.obj_l.TunablePropsChanged) {
    PID_Controller_DW.obj_l.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S8>/Encoder' */
  MW_EncoderRead(PID_Controller_DW.obj_l.Index, &PID_Controller_B.Encoder);

  /* MATLABSystem: '<S8>/Encoder' */
  MW_EncoderReset(PID_Controller_DW.obj_l.Index);

  /* MATLAB Function: '<S8>/Filter for data dropouts' */
  PID_Controller_DW.sfEvent_e = PID_Controller_CALL_EVENT;
  if (!PID_Controller_DW.prevVal_not_empty) {
    PID_Controller_DW.prevVal = PID_Controller_B.Encoder;
    PID_Controller_DW.prevVal_not_empty = true;
  }

  if ((PID_Controller_B.Encoder >= 0L) && (PID_Controller_DW.prevVal <
       PID_Controller_B.Encoder - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((PID_Controller_B.Encoder < 0L) && (PID_Controller_DW.prevVal >
              PID_Controller_B.Encoder - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = PID_Controller_B.Encoder - PID_Controller_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY <= 200L) {
    PID_Controller_DW.prevVal = PID_Controller_B.Encoder;
  }

  /* End of MATLAB Function: '<S8>/Filter for data dropouts' */

  /* Gain: '<S8>/Ticks to RPM' */
  tmp = (uint32_T)PID_Controller_P.TickstoRPM_Gain;
  tmp_0 = (uint32_T)PID_Controller_DW.prevVal;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TickstoRPM.chunks[0U], 2);

  /* MATLABSystem: '<S8>/Moving Average' */
  if (PID_Controller_DW.obj.TunablePropsChanged) {
    PID_Controller_DW.obj.TunablePropsChanged = false;
  }

  PID_Controller_B.z = 0.0;

  /* MATLABSystem: '<S8>/Moving Average' */
  PID_Controller_B.MovingAverage = 0.0;

  /* MATLABSystem: '<S8>/Moving Average' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  PID_Controller_B.csum = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    1.862645149230957E-9 + PID_Controller_DW.obj.pCumSum;
  if (PID_Controller_DW.obj.pModValueRev == 0.0) {
    PID_Controller_B.z = PID_Controller_DW.obj.pCumSumRev[(int16_T)
      PID_Controller_DW.obj.pCumRevIndex - 1] + PID_Controller_B.csum;
  }

  PID_Controller_DW.obj.pCumSumRev[(int16_T)PID_Controller_DW.obj.pCumRevIndex -
    1] = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    1.862645149230957E-9;
  if (PID_Controller_DW.obj.pCumRevIndex != 3.0) {
    cumRevIndex_0 = PID_Controller_DW.obj.pCumRevIndex + 1.0;
  } else {
    cumRevIndex_0 = 1.0;
    PID_Controller_B.csum = 0.0;
    PID_Controller_DW.obj.pCumSumRev[1] += PID_Controller_DW.obj.pCumSumRev[2];
    PID_Controller_DW.obj.pCumSumRev[0] += PID_Controller_DW.obj.pCumSumRev[1];
  }

  if (PID_Controller_DW.obj.pModValueRev == 0.0) {
    /* MATLABSystem: '<S8>/Moving Average' */
    PID_Controller_B.MovingAverage = PID_Controller_B.z / 4.0;
  }

  PID_Controller_DW.obj.pCumSum = PID_Controller_B.csum;
  PID_Controller_DW.obj.pCumRevIndex = cumRevIndex_0;
  if (PID_Controller_DW.obj.pModValueRev > 0.0) {
    PID_Controller_DW.obj.pModValueRev--;
  } else {
    PID_Controller_DW.obj.pModValueRev = 0.0;
  }

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  PID_Controller_B.z = rt_roundd_snf(PID_Controller_P.Constant2_Value);
  if (PID_Controller_B.z < 256.0) {
    if (PID_Controller_B.z >= 0.0) {
      tmp_1 = (uint8_T)PID_Controller_B.z;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_1);

  /* End of MATLABSystem: '<S5>/Digital Output1' */

  /* MATLABSystem: '<S5>/Digital Output2' */
  if (PID_Controller_B.z < 256.0) {
    if (PID_Controller_B.z >= 0.0) {
      tmp_1 = (uint8_T)PID_Controller_B.z;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_1);

  /* End of MATLABSystem: '<S5>/Digital Output2' */
  /* Update for UnitDelay: '<S6>/UD' */
  PID_Controller_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Gain: '<S94>/Integral Gain'
   */
  PID_Controller_DW.Integrator_DSTATE += PID_Controller_P.PIDController_I * Diff
    * PID_Controller_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S92>/Filter' */
  PID_Controller_DW.Filter_DSTATE += PID_Controller_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' incorporates:
   *  Gain: '<S3>/RPM to rad//s'
   *  Gain: '<S3>/rad//s to m//s'
   */
  PID_Controller_DW.PositionIntegration_DSTATE +=
    PID_Controller_P.RPMtorads_Gain * PID_Controller_B.MovingAverage *
    PID_Controller_P.radstoms_Gain *
    PID_Controller_P.PositionIntegration_gainval;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  PID_Controller_M->Timing.clockTick1++;
  if (!PID_Controller_M->Timing.clockTick1) {
    PID_Controller_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void PID_Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_Controller_M, 0,
                sizeof(RT_MODEL_PID_Controller_T));
  rtmSetTFinal(PID_Controller_M, -1);

  /* External mode info */
  PID_Controller_M->Sizes.checksums[0] = (397075946U);
  PID_Controller_M->Sizes.checksums[1] = (672643039U);
  PID_Controller_M->Sizes.checksums[2] = (1141968893U);
  PID_Controller_M->Sizes.checksums[3] = (4236111869U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    PID_Controller_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(PID_Controller_M->extModeInfo,
      &PID_Controller_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PID_Controller_M->extModeInfo,
                        PID_Controller_M->Sizes.checksums);
    rteiSetTFinalTicks(PID_Controller_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &PID_Controller_B), 0,
                sizeof(B_PID_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&PID_Controller_DW, 0,
                sizeof(DW_PID_Controller_T));

  /* Start for MATLABSystem: '<S1>/Analog Input' */
  PID_Controller_DW.obj_h.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_i = true;
  PID_Controller_DW.obj_h.isInitialized = 1L;
  PID_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  PID_Controller_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  PID_Controller_DW.obj_i.isInitialized = 0L;
  PID_Controller_DW.obj_i.NumChannels = -1L;
  PID_Controller_DW.obj_i.FrameLength = -1L;
  PID_Controller_DW.obj_i.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_c = true;
  PID_Controller_SystemCore_setup(&PID_Controller_DW.obj_i);

  /* Start for MATLABSystem: '<S3>/PWM' */
  PID_Controller_DW.obj_d.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_f = true;
  PID_Controller_DW.obj_d.isInitialized = 1L;
  PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  PID_Controller_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  PID_Controller_DW.obj_e.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_og = true;
  PID_Controller_DW.obj_e.isInitialized = 1L;
  PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  PID_Controller_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Encoder' */
  PID_Controller_DW.obj_l.Index = 0U;
  PID_Controller_DW.obj_l.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_m = true;
  PID_Controller_DW.obj_l.isSetupComplete = false;
  PID_Controller_DW.obj_l.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &PID_Controller_DW.obj_l.Index);
  PID_Controller_DW.obj_l.isSetupComplete = true;
  PID_Controller_DW.obj_l.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S8>/Moving Average' */
  PID_Controller_DW.obj.isInitialized = 0L;
  PID_Controller_DW.obj.NumChannels = -1L;
  PID_Controller_DW.obj.FrameLength = -1L;
  PID_Controller_DW.obj.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_o = true;
  PID_Controll_SystemCore_setup_k(&PID_Controller_DW.obj);

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  PID_Controller_DW.obj_n.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_j = true;
  PID_Controller_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(7, 1);
  PID_Controller_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output2' */
  PID_Controller_DW.obj_m.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty = true;
  PID_Controller_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  PID_Controller_DW.obj_m.isSetupComplete = true;

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  PID_Controller_DW.UD_DSTATE = PID_Controller_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Integrator' */
  PID_Controller_DW.Integrator_DSTATE =
    PID_Controller_P.PIDController_InitialConditio_f;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Filter' */
  PID_Controller_DW.Filter_DSTATE =
    PID_Controller_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Position Integration' */
  PID_Controller_DW.PositionIntegration_DSTATE =
    PID_Controller_P.PositionIntegration_IC;

  /* SystemInitialize for MATLAB Function: '<S8>/Filter for data dropouts' */
  PID_Controller_DW.prevVal_not_empty = false;
  PID_Controller_DW.sfEvent_e = PID_Controller_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S3>/Select PWM Direction' */
  PID_Controller_DW.sfEvent = PID_Controller_CALL_EVENT;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  PID_Controller_DW.obj_i.pCumSum = 0.0;
  PID_Controller_DW.obj_i.pCumSumRev[0] = 0.0;
  PID_Controller_DW.obj_i.pCumSumRev[1] = 0.0;
  PID_Controller_DW.obj_i.pCumRevIndex = 1.0;
  PID_Controller_DW.obj_i.pModValueRev = 0.0;

  /* InitializeConditions for MATLABSystem: '<S8>/Encoder' */
  MW_EncoderReset(PID_Controller_DW.obj_l.Index);

  /* InitializeConditions for MATLABSystem: '<S8>/Moving Average' */
  PID_Controller_DW.obj.pCumSum = 0.0;
  PID_Controller_DW.obj.pCumSumRev[0] = 0.0;
  PID_Controller_DW.obj.pCumSumRev[1] = 0.0;
  PID_Controller_DW.obj.pCumSumRev[2] = 0.0;
  PID_Controller_DW.obj.pCumRevIndex = 1.0;
  PID_Controller_DW.obj.pModValueRev = 0.0;
}

/* Model terminate function */
void PID_Controller_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  if (!PID_Controller_DW.obj_h.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_h.isInitialized == 1L) &&
        PID_Controller_DW.obj_h.isSetupComplete) {
      PID_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (PID_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input' */

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!PID_Controller_DW.obj_i.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_i.isInitialized == 1L) &&
        PID_Controller_DW.obj_i.isSetupComplete) {
      PID_Controller_DW.obj_i.NumChannels = -1L;
      PID_Controller_DW.obj_i.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!PID_Controller_DW.obj_d.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_d.isInitialized == 1L) &&
        PID_Controller_DW.obj_d.isSetupComplete) {
      PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(PID_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  if (!PID_Controller_DW.obj_e.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_e.isInitialized == 1L) &&
        PID_Controller_DW.obj_e.isSetupComplete) {
      PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(PID_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM1' */
  /* Terminate for MATLABSystem: '<S8>/Encoder' */
  if (!PID_Controller_DW.obj_l.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_l.isInitialized == 1L) &&
        PID_Controller_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Encoder' */

  /* Terminate for MATLABSystem: '<S8>/Moving Average' */
  if (!PID_Controller_DW.obj.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj.isInitialized == 1L) &&
        PID_Controller_DW.obj.isSetupComplete) {
      PID_Controller_DW.obj.NumChannels = -1L;
      PID_Controller_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Moving Average' */
  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!PID_Controller_DW.obj_n.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output2' */
  if (!PID_Controller_DW.obj_m.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output2' */
}
