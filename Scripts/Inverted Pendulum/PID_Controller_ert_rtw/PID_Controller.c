/*
 * PID_Controller.c
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
#include "PID_Controller_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "PID_Controller_private.h"
#include "multiword_types.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for MATLAB Function: '<S1>/MATLAB Function1' */
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

  /* Start for MATLABSystem: '<S1>/Moving Average1' */
  obj->NumChannels = 1L;
  obj->FrameLength = 1L;
  obj->pCumSum = 0.0;
  obj->pCumSumRev = 0.0;
  obj->pCumRevIndex = 1.0;
  obj->pModValueRev = 0.0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PID_Controll_SystemCore_setup_k(dsp_simulink_MovingAverage_k_T *obj)
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
void PID_Controller_step0(void)        /* Sample time: [0.01s, 0.0s] */
{
  real_T negPWM;
  real_T rtb_Add;
  real_T rtb_FilterCoefficient;
  real_T rtb_Gain;
  real_T theta_cal;
  uint32_T rtb_PendulumAngle;
  uint16_T b_varargout_1;
  uint8_T tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S1>/Analog Input1' */
  PID_Controller_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (PID_Controller_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<S1>/Volt2Rad1' incorporates:
   *  MATLABSystem: '<S1>/Analog Input1'
   * */
  rtb_PendulumAngle = (uint32_T)PID_Controller_P.Volt2Rad1_Gain * b_varargout_1;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  Gain: '<S1>/Volt2Rad1'
   */
  PID_Controller_DW.sfEvent_m = PID_Controller_CALL_EVENT;
  if (!PID_Controller_DW.calibrated) {
    PID_Controller_DW.sample_count++;

    /* DataTypeConversion: '<S1>/Cast To Double' incorporates:
     *  Gain: '<S1>/Volt2Rad1'
     */
    theta_cal = (real_T)rtb_PendulumAngle * 1.1920928955078125E-7;
    PID_Controller_DW.theta_sum += theta_cal;
    if (PID_Controller_DW.sample_count >= PID_Controller_DW.N) {
      PID_Controller_DW.theta0 = PID_Controller_DW.theta_sum /
        PID_Controller_DW.N;
      PID_Controller_DW.calibrated = true;
      theta_cal = ((real_T)rtb_PendulumAngle * 1.1920928955078125E-7 -
                   PID_Controller_DW.theta0) + 6.2831853071795862;
    }
  } else {
    theta_cal = ((real_T)rtb_PendulumAngle * 1.1920928955078125E-7 -
                 PID_Controller_DW.theta0) + 6.2831853071795862;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* DiscreteTransferFcn: '<S1>/Low Pass Filter' */
  theta_cal = (theta_cal - PID_Controller_P.LowPassFilter_DenCoef[1L] *
               PID_Controller_DW.LowPassFilter_states) /
    PID_Controller_P.LowPassFilter_DenCoef[0];

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Pi'
   *  DiscreteTransferFcn: '<S1>/Low Pass Filter'
   */
  rtb_Add = (PID_Controller_P.LowPassFilter_NumCoef[0] * theta_cal +
             PID_Controller_P.LowPassFilter_NumCoef[1L] *
             PID_Controller_DW.LowPassFilter_states) - PID_Controller_P.Pi_Value;

  /* Gain: '<S47>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Gain: '<S37>/Derivative Gain'
   *  Sum: '<S39>/SumD'
   */
  rtb_FilterCoefficient = (PID_Controller_P.PIDController1_D * rtb_Add -
    PID_Controller_DW.Filter_DSTATE) * PID_Controller_P.PIDController1_N;

  /* Sum: '<S53>/Sum' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   *  Gain: '<S49>/Proportional Gain'
   */
  PID_Controller_B.Saturation = (PID_Controller_P.PIDController1_P * rtb_Add +
    PID_Controller_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S51>/Saturation' */
  if (PID_Controller_B.Saturation >
      PID_Controller_P.PIDController1_UpperSaturationL) {
    /* Sum: '<S53>/Sum' incorporates:
     *  Saturate: '<S51>/Saturation'
     */
    PID_Controller_B.Saturation =
      PID_Controller_P.PIDController1_UpperSaturationL;
  } else if (PID_Controller_B.Saturation <
             PID_Controller_P.PIDController1_LowerSaturationL) {
    /* Sum: '<S53>/Sum' incorporates:
     *  Saturate: '<S51>/Saturation'
     */
    PID_Controller_B.Saturation =
      PID_Controller_P.PIDController1_LowerSaturationL;
  }

  /* End of Saturate: '<S51>/Saturation' */
  /* Abs: '<Root>/Abs' */
  PID_Controller_B.Abs = fabs(rtb_Add);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PID_Controller_B.Abs > PID_Controller_P.Switch_Threshold) {
    rtb_Gain = PID_Controller_P.Constant1_Value;
  } else {
    rtb_Gain = PID_Controller_B.Saturation;
  }

  /* Gain: '<S2>/Gain' incorporates:
   *  Switch: '<Root>/Switch'
   */
  rtb_Gain *= PID_Controller_P.Gain_Gain;

  /* MATLAB Function: '<S2>/Select PWM Direction' */
  PID_Controller_DW.sfEvent = PID_Controller_CALL_EVENT;
  if (rtb_Gain > 0.0) {
    negPWM = 0.0;
  } else {
    negPWM = -rtb_Gain;
    rtb_Gain = 0.0;
  }

  /* End of MATLAB Function: '<S2>/Select PWM Direction' */

  /* MATLABSystem: '<S2>/PWM' */
  PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(rtb_Gain <= 255.0)) {
    rtb_Gain = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle(PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Gain);

  /* MATLABSystem: '<S2>/PWM1' */
  PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S2>/PWM1' */
  if (!(negPWM <= 255.0)) {
    negPWM = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM1' */
  MW_PWM_SetDutyCycle(PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, negPWM);

  /* MATLABSystem: '<S1>/Moving Average1' */
  if (PID_Controller_DW.obj_i.TunablePropsChanged) {
    PID_Controller_DW.obj_i.TunablePropsChanged = false;
  }

  PID_Controller_DW.obj_i.pCumSum = 0.0;
  PID_Controller_DW.obj_i.pCumSumRev = 0.0;
  PID_Controller_DW.obj_i.pCumRevIndex = 1.0;
  if (PID_Controller_DW.obj_i.pModValueRev > 0.0) {
    PID_Controller_DW.obj_i.pModValueRev--;
  } else {
    PID_Controller_DW.obj_i.pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S1>/Moving Average1' */

  /* MATLABSystem: '<S4>/Digital Output1' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  rtb_Gain = rt_roundd_snf(PID_Controller_P.Constant2_Value);
  if (rtb_Gain < 256.0) {
    if (rtb_Gain >= 0.0) {
      tmp = (uint8_T)rtb_Gain;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<S4>/Digital Output1' */

  /* MATLABSystem: '<S4>/Digital Output2' */
  if (rtb_Gain < 256.0) {
    if (rtb_Gain >= 0.0) {
      tmp = (uint8_T)rtb_Gain;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<S4>/Digital Output2' */

  /* Update for DiscreteTransferFcn: '<S1>/Low Pass Filter' */
  PID_Controller_DW.LowPassFilter_states = theta_cal;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
   *  Gain: '<S41>/Integral Gain'
   */
  PID_Controller_DW.Integrator_DSTATE += PID_Controller_P.PIDController1_I *
    rtb_Add * PID_Controller_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  PID_Controller_DW.Filter_DSTATE += PID_Controller_P.Filter_gainval *
    rtb_FilterCoefficient;

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
  real_T csum;
  int32_T qY;
  uint32_T tmp;
  uint32_T tmp_0;

  /* MATLABSystem: '<S7>/Encoder' */
  if (PID_Controller_DW.obj_a.TunablePropsChanged) {
    PID_Controller_DW.obj_a.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderRead(PID_Controller_DW.obj_a.Index, &PID_Controller_B.Encoder);

  /* MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(PID_Controller_DW.obj_a.Index);

  /* MATLAB Function: '<S7>/Filter for data dropouts' */
  PID_Controller_DW.sfEvent_k = PID_Controller_CALL_EVENT;
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
    if (PID_Controller_B.Encoder < 0L) {
      if (PID_Controller_B.Encoder <= MIN_int32_T) {
        qY = MAX_int32_T;
      } else {
        qY = -PID_Controller_B.Encoder;
      }
    } else {
      qY = PID_Controller_B.Encoder;
    }

    if (qY <= 500L) {
      PID_Controller_DW.prevVal = PID_Controller_B.Encoder;
    }
  }

  /* End of MATLAB Function: '<S7>/Filter for data dropouts' */

  /* Gain: '<S7>/Ticks to RPM' */
  tmp = (uint32_T)PID_Controller_P.TickstoRPM_Gain;
  tmp_0 = (uint32_T)PID_Controller_DW.prevVal;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TickstoRPM.chunks[0U], 2);

  /* MATLABSystem: '<S7>/Moving Average' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  if (PID_Controller_DW.obj.TunablePropsChanged) {
    PID_Controller_DW.obj.TunablePropsChanged = false;
  }

  csum = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    7.4505805969238281E-9 + PID_Controller_DW.obj.pCumSum;
  PID_Controller_DW.obj.pCumSumRev[(int16_T)PID_Controller_DW.obj.pCumRevIndex -
    1] = sMultiWord2Double(&rtb_TickstoRPM.chunks[0U], 2, 0) *
    7.4505805969238281E-9;
  if (PID_Controller_DW.obj.pCumRevIndex != 3.0) {
    PID_Controller_DW.obj.pCumRevIndex++;
  } else {
    PID_Controller_DW.obj.pCumRevIndex = 1.0;
    csum = 0.0;
    PID_Controller_DW.obj.pCumSumRev[1] += PID_Controller_DW.obj.pCumSumRev[2];
    PID_Controller_DW.obj.pCumSumRev[0] += PID_Controller_DW.obj.pCumSumRev[1];
  }

  PID_Controller_DW.obj.pCumSum = csum;
  if (PID_Controller_DW.obj.pModValueRev > 0.0) {
    PID_Controller_DW.obj.pModValueRev--;
  } else {
    PID_Controller_DW.obj.pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S7>/Moving Average' */

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
  PID_Controller_M->Sizes.checksums[0] = (3176570211U);
  PID_Controller_M->Sizes.checksums[1] = (1874537539U);
  PID_Controller_M->Sizes.checksums[2] = (1646765576U);
  PID_Controller_M->Sizes.checksums[3] = (2006834060U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
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
    systemRan[12] = &rtAlwaysEnabled;
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

  /* Start for MATLABSystem: '<S1>/Analog Input1' */
  PID_Controller_DW.obj_j.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_ay = true;
  PID_Controller_DW.obj_j.isInitialized = 1L;
  PID_Controller_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  PID_Controller_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  PID_Controller_DW.obj_o.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_n = true;
  PID_Controller_DW.obj_o.isInitialized = 1L;
  PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  PID_Controller_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM1' */
  PID_Controller_DW.obj_c.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_c = true;
  PID_Controller_DW.obj_c.isInitialized = 1L;
  PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  PID_Controller_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average1' */
  PID_Controller_DW.obj_i.isInitialized = 0L;
  PID_Controller_DW.obj_i.NumChannels = -1L;
  PID_Controller_DW.obj_i.FrameLength = -1L;
  PID_Controller_DW.obj_i.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_k = true;
  PID_Controller_SystemCore_setup(&PID_Controller_DW.obj_i);

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  PID_Controller_DW.obj_b.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_a = true;
  PID_Controller_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(7, 1);
  PID_Controller_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output2' */
  PID_Controller_DW.obj_h.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty = true;
  PID_Controller_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(8, 1);
  PID_Controller_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Encoder' */
  PID_Controller_DW.obj_a.Index = 0U;
  PID_Controller_DW.obj_a.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_g = true;
  PID_Controller_DW.obj_a.isSetupComplete = false;
  PID_Controller_DW.obj_a.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &PID_Controller_DW.obj_a.Index);
  PID_Controller_DW.obj_a.isSetupComplete = true;
  PID_Controller_DW.obj_a.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S7>/Moving Average' */
  PID_Controller_DW.obj.isInitialized = 0L;
  PID_Controller_DW.obj.NumChannels = -1L;
  PID_Controller_DW.obj.FrameLength = -1L;
  PID_Controller_DW.obj.matlabCodegenIsDeleted = false;
  PID_Controller_DW.objisempty_f = true;
  PID_Controll_SystemCore_setup_k(&PID_Controller_DW.obj);

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Low Pass Filter' */
  PID_Controller_DW.LowPassFilter_states =
    PID_Controller_P.LowPassFilter_InitialStates;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
  PID_Controller_DW.Integrator_DSTATE =
    PID_Controller_P.PIDController1_InitialConditi_d;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
  PID_Controller_DW.Filter_DSTATE =
    PID_Controller_P.PIDController1_InitialCondition;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  PID_Controller_DW.N = 100.0;
  PID_Controller_DW.N_not_empty = true;
  PID_Controller_DW.sample_count = 0.0;
  PID_Controller_DW.sample_count_not_empty = true;
  PID_Controller_DW.theta_sum = 0.0;
  PID_Controller_DW.theta_sum_not_empty = true;
  PID_Controller_DW.theta0 = 0.0;
  PID_Controller_DW.theta0_not_empty = true;
  PID_Controller_DW.calibrated = false;
  PID_Controller_DW.calibrated_not_empty = true;
  PID_Controller_DW.sfEvent_m = PID_Controller_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S2>/Select PWM Direction' */
  PID_Controller_DW.sfEvent = PID_Controller_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S7>/Filter for data dropouts' */
  PID_Controller_DW.prevVal_not_empty = false;
  PID_Controller_DW.sfEvent_k = PID_Controller_CALL_EVENT;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average1' */
  PID_Controller_DW.obj_i.pCumSum = 0.0;
  PID_Controller_DW.obj_i.pCumSumRev = 0.0;
  PID_Controller_DW.obj_i.pCumRevIndex = 1.0;
  PID_Controller_DW.obj_i.pModValueRev = 0.0;

  /* InitializeConditions for MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(PID_Controller_DW.obj_a.Index);

  /* InitializeConditions for MATLABSystem: '<S7>/Moving Average' */
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
  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  if (!PID_Controller_DW.obj_j.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_j.isInitialized == 1L) &&
        PID_Controller_DW.obj_j.isSetupComplete) {
      PID_Controller_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (PID_Controller_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!PID_Controller_DW.obj_o.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_o.isInitialized == 1L) &&
        PID_Controller_DW.obj_o.isSetupComplete) {
      PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(PID_Controller_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/PWM1' */
  if (!PID_Controller_DW.obj_c.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_c.isInitialized == 1L) &&
        PID_Controller_DW.obj_c.isSetupComplete) {
      PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(PID_Controller_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM1' */
  /* Terminate for MATLABSystem: '<S1>/Moving Average1' */
  if (!PID_Controller_DW.obj_i.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_i.isInitialized == 1L) &&
        PID_Controller_DW.obj_i.isSetupComplete) {
      PID_Controller_DW.obj_i.NumChannels = -1L;
      PID_Controller_DW.obj_i.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!PID_Controller_DW.obj_b.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output2' */
  if (!PID_Controller_DW.obj_h.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S7>/Encoder' */
  if (!PID_Controller_DW.obj_a.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj_a.isInitialized == 1L) &&
        PID_Controller_DW.obj_a.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Encoder' */
  /* Terminate for MATLABSystem: '<S7>/Moving Average' */
  if (!PID_Controller_DW.obj.matlabCodegenIsDeleted) {
    PID_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((PID_Controller_DW.obj.isInitialized == 1L) &&
        PID_Controller_DW.obj.isSetupComplete) {
      PID_Controller_DW.obj.NumChannels = -1L;
      PID_Controller_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Moving Average' */
}
