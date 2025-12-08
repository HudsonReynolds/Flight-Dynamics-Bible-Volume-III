/*
 * LQR_Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.59
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Oct 27 21:09:59 2025
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
#include <string.h>
#include <math.h>
#include "LQR_Controller_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
DW_LQR_Controller_T LQR_Controller_DW;

/* Real-time model */
static RT_MODEL_LQR_Controller_T LQR_Controller_M_;
RT_MODEL_LQR_Controller_T *const LQR_Controller_M = &LQR_Controller_M_;

/* Forward declaration for local functions */
static void LQR_Controller_SystemCore_setup(dsp_simulink_MovingAverage_LQ_T *obj);
static void LQR_Controll_SystemCore_setup_p(dsp_simulink_MovingAverage_p_T *obj);
static void rate_monotonic_scheduler(void);

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
  eventFlags[2] = ((boolean_T)rtmStepTask(LQR_Controller_M, 2));
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
  if (LQR_Controller_M->Timing.TaskCounters.TID[1] == 0) {
    LQR_Controller_M->Timing.RateInteraction.TID1_2 =
      (LQR_Controller_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LQR_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((LQR_Controller_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.007s, 0.0s] */
    LQR_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }

  (LQR_Controller_M->Timing.TaskCounters.TID[2])++;
  if ((LQR_Controller_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.014s, 0.0s] */
    LQR_Controller_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void LQR_Controller_SystemCore_setup(dsp_simulink_MovingAverage_LQ_T *obj)
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

static void LQR_Controll_SystemCore_setup_p(dsp_simulink_MovingAverage_p_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S13>/Moving Average' */
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
void LQR_Controller_step0(void)        /* Sample time: [0.0035s, 0.0s] */
{
  {                                    /* Sample time: [0.0035s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void LQR_Controller_step1(void)        /* Sample time: [0.007s, 0.0s] */
{
  real_T Diff;
  real_T csum;
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
   *  RateTransition generated from: '<S4>/Add2'
   */
  tmp = LQR_Controller_M->Timing.RateInteraction.TID1_2;
  if (tmp) {
    LQR_Controller_B.StateVector[0] = LQR_Controller_DW.RT_Buffer0;

    /* RateTransition: '<Root>/RT1' incorporates:
     *  Concatenate: '<Root>/State Vector'
     */
    LQR_Controller_B.StateVector[1] = LQR_Controller_DW.RT1_Buffer0;
  }

  /* End of RateTransition: '<Root>/RT' */

  /* MATLABSystem: '<S1>/Analog Input1' */
  LQR_Controller_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (LQR_Controller_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<S1>/Volt2Rad1' incorporates:
   *  MATLABSystem: '<S1>/Analog Input1'
   * */
  rtb_PendulumAngle = (uint32_T)LQR_Controller_P.Volt2Rad1_Gain * b_varargout_1;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  Gain: '<S1>/Volt2Rad1'
   */
  guard1 = false;
  if (!LQR_Controller_DW.calibrated) {
    LQR_Controller_DW.sample_count++;

    /* DataTypeConversion: '<S1>/Cast To Double' incorporates:
     *  Gain: '<S1>/Volt2Rad1'
     */
    rtb_theta_cal = (real_T)rtb_PendulumAngle * 1.1920928955078125E-7;
    LQR_Controller_DW.theta_sum += rtb_theta_cal;
    if (LQR_Controller_DW.sample_count >= LQR_Controller_DW.N) {
      LQR_Controller_DW.theta0 = LQR_Controller_DW.theta_sum /
        LQR_Controller_DW.N;
      LQR_Controller_DW.calibrated = true;
      guard1 = true;
    } else {
      rtb_theta_cal += 1.5707963267948966;
      rtb_cal = false;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    rtb_theta_cal = ((real_T)rtb_PendulumAngle * 1.1920928955078125E-7 -
                     LQR_Controller_DW.theta0) + 6.2831853071795862;
    rtb_cal = true;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* SignalConversion generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[2] = rtb_theta_cal;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_theta_cal *= LQR_Controller_P.TSamp_WtEt;

  /* Sum: '<S6>/Diff' incorporates:
   *  UnitDelay: '<S6>/UD'
   */
  Diff = rtb_theta_cal - LQR_Controller_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (LQR_Controller_DW.obj.TunablePropsChanged) {
    LQR_Controller_DW.obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* Concatenate: '<Root>/State Vector' incorporates:
   *  MATLABSystem: '<S1>/Moving Average'
   *  SignalConversion generated from: '<S1>/Moving Average'
   */
  LQR_Controller_B.StateVector[3] = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  csum = LQR_Controller_DW.obj.pCumSum + Diff;
  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    z = LQR_Controller_DW.obj.pCumSumRev[(int16_T)
      LQR_Controller_DW.obj.pCumRevIndex - 1] + csum;
  }

  LQR_Controller_DW.obj.pCumSumRev[(int16_T)LQR_Controller_DW.obj.pCumRevIndex -
    1] = Diff;
  if (LQR_Controller_DW.obj.pCumRevIndex != 11.0) {
    Diff = LQR_Controller_DW.obj.pCumRevIndex + 1.0;
  } else {
    Diff = 1.0;
    csum = 0.0;
    for (rtb_mode = 9; rtb_mode >= 0; rtb_mode--) {
      LQR_Controller_DW.obj.pCumSumRev[rtb_mode] +=
        LQR_Controller_DW.obj.pCumSumRev[rtb_mode + 1];
    }
  }

  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    /* Concatenate: '<Root>/State Vector' incorporates:
     *  SignalConversion generated from: '<S1>/Moving Average'
     */
    LQR_Controller_B.StateVector[3] = z / 12.0;
  }

  LQR_Controller_DW.obj.pCumSum = csum;
  LQR_Controller_DW.obj.pCumRevIndex = Diff;
  if (LQR_Controller_DW.obj.pModValueRev > 0.0) {
    LQR_Controller_DW.obj.pModValueRev--;
  } else {
    LQR_Controller_DW.obj.pModValueRev = 0.0;
  }

  /* Constant: '<Root>/Constant4' */
  LQR_Controller_B.SetPoint[0] = LQR_Controller_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  LQR_Controller_B.SetPoint[1] = LQR_Controller_P.Constant5_Value;

  /* Constant: '<Root>/Constant3' */
  LQR_Controller_B.SetPoint[2] = LQR_Controller_P.Constant3_Value;

  /* Constant: '<Root>/Constant6' */
  LQR_Controller_B.SetPoint[3] = LQR_Controller_P.Constant6_Value;

  /* Sum: '<Root>/Sum' */
  LQR_Controller_B.SetPoint[0] = LQR_Controller_B.StateVector[0] -
    LQR_Controller_B.SetPoint[0];
  LQR_Controller_B.SetPoint[1] = LQR_Controller_B.StateVector[1] -
    LQR_Controller_B.SetPoint[1];
  LQR_Controller_B.SetPoint[2] = LQR_Controller_B.StateVector[2] -
    LQR_Controller_B.SetPoint[2];
  LQR_Controller_B.SetPoint[3] = LQR_Controller_B.StateVector[3] -
    LQR_Controller_B.SetPoint[3];

  /* MATLAB Function: '<S2>/MATLAB Function' */
  if (rtb_cal) {
    if ((fabs(LQR_Controller_B.StateVector[2] - 3.1415926535897931) < 0.15) &&
        (fabs(LQR_Controller_B.StateVector[3]) < 1.5)) {
      rtb_mode = 1;
    } else {
      rtb_mode = 2;
    }
  } else {
    rtb_mode = 3;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* RateTransition generated from: '<S4>/Add2' */
  if (tmp) {
    /* RateTransition generated from: '<S4>/Add2' */
    LQR_Controller_B.TmpRTBAtAdd2Inport1 =
      LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0;
  }

  /* SwitchCase: '<S2>/Switch Case' */
  switch ((int32_T)rtb_mode) {
   case 1L:
    /* Outputs for IfAction SubSystem: '<S2>/LQR' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SignalConversion generated from: '<S8>/voltage' incorporates:
     *  Gain: '<Root>/Gain2'
     *  Gain: '<Root>/LQR Gains'
     *  Gain: '<S4>/Gain2'
     *  Gain: '<S4>/Gain4'
     *  Sum: '<S4>/Add2'
     */
    z = ((((LQR_Controller_P.LQRGains_Gain[0] * LQR_Controller_B.SetPoint[0] +
            LQR_Controller_P.LQRGains_Gain[1] * LQR_Controller_B.SetPoint[1]) +
           LQR_Controller_P.LQRGains_Gain[2] * LQR_Controller_B.SetPoint[2]) +
          LQR_Controller_P.LQRGains_Gain[3] * LQR_Controller_B.SetPoint[3]) *
         LQR_Controller_P.Gain2_Gain * (LQR_Controller_P.R_motor *
          LQR_Controller_P.r / LQR_Controller_P.k_motor) +
         LQR_Controller_B.TmpRTBAtAdd2Inport1) * LQR_Controller_P.Gain4_Gain;

    /* End of Outputs for SubSystem: '<S2>/LQR' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S2>/Swing Up' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* MATLAB Function: '<S10>/MATLAB Function1' */
    LQR_Controller_DW.thetaMax_not_empty = true;

    /* SignalConversion generated from: '<S10>/Out1' incorporates:
     *  MATLAB Function: '<S10>/MATLAB Function1'
     */
    z = 0.0;

    /* End of Outputs for SubSystem: '<S2>/Swing Up' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Uncalibrated' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/In1' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    z = LQR_Controller_P.Constant1_Value;

    /* End of Outputs for SubSystem: '<S2>/Uncalibrated' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Gain: '<S3>/Gain' */
  z *= LQR_Controller_P.Gain_Gain;

  /* MATLAB Function: '<S3>/Select PWM Direction' */
  if (z > 0.0) {
    csum = 0.0;
  } else {
    csum = -z;
    z = 0.0;
  }

  /* End of MATLAB Function: '<S3>/Select PWM Direction' */

  /* MATLABSystem: '<S3>/PWM' */
  LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S3>/PWM' */
  if (!(z <= 255.0)) {
    z = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, z);

  /* MATLABSystem: '<S3>/PWM1' */
  LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!(csum <= 255.0)) {
    csum = 255.0;
  }

  /* MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, csum);

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  z = rt_roundd_snf(LQR_Controller_P.Constant2_Value);
  if (z < 256.0) {
    if (z >= 0.0) {
      tmp_0 = (uint8_T)z;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);

  /* End of MATLABSystem: '<S5>/Digital Output1' */

  /* MATLABSystem: '<S5>/Digital Output2' */
  if (z < 256.0) {
    if (z >= 0.0) {
      tmp_0 = (uint8_T)z;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S5>/Digital Output2' */

  /* Update for UnitDelay: '<S6>/UD' */
  LQR_Controller_DW.UD_DSTATE = rtb_theta_cal;
}

/* Model step function for TID2 */
void LQR_Controller_step2(void)        /* Sample time: [0.014s, 0.0s] */
{
  real_T csum;
  real_T cumRevIndex;
  real_T rtb_Gain1;
  real_T z;
  int32_T qY;
  int32_T rtb_Encoder;

  /* MATLABSystem: '<S13>/Encoder' */
  if (LQR_Controller_DW.obj_l.TunablePropsChanged) {
    LQR_Controller_DW.obj_l.TunablePropsChanged = false;
  }

  MW_EncoderRead(LQR_Controller_DW.obj_l.Index, &rtb_Encoder);
  MW_EncoderReset(LQR_Controller_DW.obj_l.Index);

  /* End of MATLABSystem: '<S13>/Encoder' */
  /* MATLAB Function: '<S13>/Filter for data dropouts' */
  if (!LQR_Controller_DW.prevVal_not_empty) {
    LQR_Controller_DW.prevVal = rtb_Encoder;
    LQR_Controller_DW.prevVal_not_empty = true;
  }

  if ((rtb_Encoder >= 0L) && (LQR_Controller_DW.prevVal < rtb_Encoder -
       MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((rtb_Encoder < 0L) && (LQR_Controller_DW.prevVal > rtb_Encoder -
              MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = rtb_Encoder - LQR_Controller_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY > 200L) {
    rtb_Encoder = LQR_Controller_DW.prevVal;
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
      rtb_Encoder = LQR_Controller_DW.prevVal;
    } else {
      LQR_Controller_DW.prevVal = rtb_Encoder;
    }
  }

  /* End of MATLAB Function: '<S13>/Filter for data dropouts' */

  /* MATLABSystem: '<S13>/Moving Average' */
  if (LQR_Controller_DW.obj_m.TunablePropsChanged) {
    LQR_Controller_DW.obj_m.TunablePropsChanged = false;
  }

  z = 0.0;
  rtb_Gain1 = 0.0;

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Gain: '<S13>/Ticks to RPM'
   */
  cumRevIndex = (real_T)((int64_T)LQR_Controller_P.TickstoRPM_Gain * rtb_Encoder)
    * 7.4505805969238281E-9;

  /* MATLABSystem: '<S13>/Moving Average' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  csum = cumRevIndex + LQR_Controller_DW.obj_m.pCumSum;
  if (LQR_Controller_DW.obj_m.pModValueRev == 0.0) {
    z = LQR_Controller_DW.obj_m.pCumSumRev[(int16_T)
      LQR_Controller_DW.obj_m.pCumRevIndex - 1] + csum;
  }

  LQR_Controller_DW.obj_m.pCumSumRev[(int16_T)
    LQR_Controller_DW.obj_m.pCumRevIndex - 1] = cumRevIndex;
  if (LQR_Controller_DW.obj_m.pCumRevIndex != 3.0) {
    cumRevIndex = LQR_Controller_DW.obj_m.pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    LQR_Controller_DW.obj_m.pCumSumRev[1] += LQR_Controller_DW.obj_m.pCumSumRev
      [2];
    LQR_Controller_DW.obj_m.pCumSumRev[0] += LQR_Controller_DW.obj_m.pCumSumRev
      [1];
  }

  if (LQR_Controller_DW.obj_m.pModValueRev == 0.0) {
    rtb_Gain1 = z / 4.0;
  }

  LQR_Controller_DW.obj_m.pCumSum = csum;
  LQR_Controller_DW.obj_m.pCumRevIndex = cumRevIndex;
  if (LQR_Controller_DW.obj_m.pModValueRev > 0.0) {
    LQR_Controller_DW.obj_m.pModValueRev--;
  } else {
    LQR_Controller_DW.obj_m.pModValueRev = 0.0;
  }

  /* Gain: '<S3>/rad//s to m//s' incorporates:
   *  Gain: '<S3>/RPM to rad//s'
   *  MATLABSystem: '<S13>/Moving Average'
   */
  z = LQR_Controller_P.RPMtorads_Gain * rtb_Gain1 *
    LQR_Controller_P.radstoms_Gain;

  /* Gain: '<S4>/Gain1' */
  rtb_Gain1 = LQR_Controller_P.k_motor / LQR_Controller_P.r * z;

  /* RateTransition generated from: '<S4>/Add2' */
  LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0 = rtb_Gain1;

  /* RateTransition: '<Root>/RT' */
  LQR_Controller_DW.RT_Buffer0 = LQR_Controller_DW.PositionIntegration_DSTATE;

  /* RateTransition: '<Root>/RT1' */
  LQR_Controller_DW.RT1_Buffer0 = z;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE +=
    LQR_Controller_P.PositionIntegration_gainval * z;

  /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
  if (LQR_Controller_DW.PositionIntegration_DSTATE >
      LQR_Controller_P.PositionIntegration_UpperSat) {
    /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
    LQR_Controller_DW.PositionIntegration_DSTATE =
      LQR_Controller_P.PositionIntegration_UpperSat;
  } else if (LQR_Controller_DW.PositionIntegration_DSTATE <
             LQR_Controller_P.PositionIntegration_LowerSat) {
    /* Update for DiscreteIntegrator: '<S3>/Position Integration' */
    LQR_Controller_DW.PositionIntegration_DSTATE =
      LQR_Controller_P.PositionIntegration_LowerSat;
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

  /* block I/O */
  (void) memset(((void *) &LQR_Controller_B), 0,
                sizeof(B_LQR_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&LQR_Controller_DW, 0,
                sizeof(DW_LQR_Controller_T));

  /* Start for RateTransition: '<Root>/RT' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[0] = LQR_Controller_P.RT_InitialCondition;

  /* Start for RateTransition: '<Root>/RT1' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[1] = LQR_Controller_P.RT1_InitialCondition;

  /* Start for MATLABSystem: '<S1>/Analog Input1' */
  LQR_Controller_DW.obj_g.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_b = true;
  LQR_Controller_DW.obj_g.isInitialized = 1L;
  LQR_Controller_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  LQR_Controller_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  LQR_Controller_DW.obj.isInitialized = 0L;
  LQR_Controller_DW.obj.NumChannels = -1L;
  LQR_Controller_DW.obj.FrameLength = -1L;
  LQR_Controller_DW.obj.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_mm = true;
  LQR_Controller_SystemCore_setup(&LQR_Controller_DW.obj);

  /* Start for RateTransition generated from: '<S4>/Add2' */
  LQR_Controller_B.TmpRTBAtAdd2Inport1 =
    LQR_Controller_P.TmpRTBAtAdd2Inport1_InitialCond;

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

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_j = true;
  LQR_Controller_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(7, 1);
  LQR_Controller_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output2' */
  LQR_Controller_DW.obj_mo.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty = true;
  LQR_Controller_DW.obj_mo.isInitialized = 1L;
  digitalIOSetup(8, 1);
  LQR_Controller_DW.obj_mo.isSetupComplete = true;

  /* Start for MATLABSystem: '<S13>/Encoder' */
  LQR_Controller_DW.obj_l.Index = 0U;
  LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_m = true;
  LQR_Controller_DW.obj_l.isSetupComplete = false;
  LQR_Controller_DW.obj_l.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &LQR_Controller_DW.obj_l.Index);
  LQR_Controller_DW.obj_l.isSetupComplete = true;
  LQR_Controller_DW.obj_l.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S13>/Moving Average' */
  LQR_Controller_DW.obj_m.isInitialized = 0L;
  LQR_Controller_DW.obj_m.NumChannels = -1L;
  LQR_Controller_DW.obj_m.FrameLength = -1L;
  LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_o = true;
  LQR_Controll_SystemCore_setup_p(&LQR_Controller_DW.obj_m);

  /* InitializeConditions for RateTransition: '<Root>/RT' */
  LQR_Controller_DW.RT_Buffer0 = LQR_Controller_P.RT_InitialCondition;

  /* InitializeConditions for RateTransition: '<Root>/RT1' */
  LQR_Controller_DW.RT1_Buffer0 = LQR_Controller_P.RT1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  LQR_Controller_DW.UD_DSTATE = LQR_Controller_P.Derivative_ICPrevScaledInput;

  /* InitializeConditions for RateTransition generated from: '<S4>/Add2' */
  LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0 =
    LQR_Controller_P.TmpRTBAtAdd2Inport1_InitialCond;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE =
    LQR_Controller_P.PositionIntegration_IC;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  LQR_Controller_DW.N = 250.0;
  LQR_Controller_DW.sample_count = 0.0;
  LQR_Controller_DW.theta_sum = 0.0;
  LQR_Controller_DW.theta0 = 0.0;
  LQR_Controller_DW.calibrated = false;

  /* SystemInitialize for IfAction SubSystem: '<S2>/Swing Up' */
  /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function1' */
  LQR_Controller_DW.thetaMax_not_empty = false;

  /* End of SystemInitialize for SubSystem: '<S2>/Swing Up' */

  /* SystemInitialize for MATLAB Function: '<S13>/Filter for data dropouts' */
  LQR_Controller_DW.prevVal_not_empty = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  LQR_Controller_DW.obj.pCumSum = 0.0;
  memset(&LQR_Controller_DW.obj.pCumSumRev[0], 0, 11U * sizeof(real_T));
  LQR_Controller_DW.obj.pCumRevIndex = 1.0;
  LQR_Controller_DW.obj.pModValueRev = 0.0;

  /* InitializeConditions for MATLABSystem: '<S13>/Encoder' */
  MW_EncoderReset(LQR_Controller_DW.obj_l.Index);

  /* InitializeConditions for MATLABSystem: '<S13>/Moving Average' */
  LQR_Controller_DW.obj_m.pCumSum = 0.0;
  LQR_Controller_DW.obj_m.pCumSumRev[0] = 0.0;
  LQR_Controller_DW.obj_m.pCumSumRev[1] = 0.0;
  LQR_Controller_DW.obj_m.pCumSumRev[2] = 0.0;
  LQR_Controller_DW.obj_m.pCumRevIndex = 1.0;
  LQR_Controller_DW.obj_m.pModValueRev = 0.0;
}

/* Model terminate function */
void LQR_Controller_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  if (!LQR_Controller_DW.obj_g.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_g.isInitialized == 1L) &&
        LQR_Controller_DW.obj_g.isSetupComplete) {
      LQR_Controller_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (LQR_Controller_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input1' */

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!LQR_Controller_DW.obj.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj.isInitialized == 1L) &&
        LQR_Controller_DW.obj.isSetupComplete) {
      LQR_Controller_DW.obj.NumChannels = -1L;
      LQR_Controller_DW.obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */

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

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!LQR_Controller_DW.obj_n.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output2' */
  if (!LQR_Controller_DW.obj_mo.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S13>/Encoder' */
  if (!LQR_Controller_DW.obj_l.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_l.isInitialized == 1L) &&
        LQR_Controller_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Encoder' */

  /* Terminate for MATLABSystem: '<S13>/Moving Average' */
  if (!LQR_Controller_DW.obj_m.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_m.isInitialized == 1L) &&
        LQR_Controller_DW.obj_m.isSetupComplete) {
      LQR_Controller_DW.obj_m.NumChannels = -1L;
      LQR_Controller_DW.obj_m.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Moving Average' */
}
