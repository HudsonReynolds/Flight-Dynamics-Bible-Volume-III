/*
 * LQR_Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.23
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Tue Aug  5 21:08:16 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_Controller.h"
#include "rtwtypes.h"
#include "LQR_Controller_types.h"
#include "LQR_Controller_private.h"
#include <math.h>
#include <string.h>
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

/* Forward declaration for local functions */
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

  /* tid 0 shares data with slower tid rate: 1 */
  LQR_Controller_M->Timing.RateInteraction.TID0_1 =
    (LQR_Controller_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LQR_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((LQR_Controller_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.014s, 0.0s] */
    LQR_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void LQR_Controller_SystemCore_setup(dsp_simulink_MovingAverage_LQ_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S9>/Moving Average' */
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

/* System initialize for atomic system: */
void LQR_Cont_MovingAverage_Init(DW_MovingAverage_LQR_Controll_T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S9>/Moving Average' */
  localDW->obj.pCumSum = 0.0;
  localDW->obj.pCumSumRev[0] = 0.0;
  localDW->obj.pCumSumRev[1] = 0.0;
  localDW->obj.pCumSumRev[2] = 0.0;
  localDW->obj.pCumRevIndex = 1.0;
  localDW->obj.pModValueRev = 0.0;
}

/* Start for atomic system: */
void LQR_Con_MovingAverage_Start(DW_MovingAverage_LQR_Controll_T *localDW)
{
  /* Start for MATLABSystem: '<S9>/Moving Average' */
  localDW->obj.isInitialized = 0L;
  localDW->obj.NumChannels = -1L;
  localDW->obj.FrameLength = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  LQR_Controller_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void LQR_Controlle_MovingAverage(real_T rtu_0, B_MovingAverage_LQR_Controlle_T
  *localB, DW_MovingAverage_LQR_Controll_T *localDW)
{
  real_T csum;
  real_T cumRevIndex;
  real_T z;

  /* MATLABSystem: '<S9>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* MATLABSystem: '<S9>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S9>/Moving Average' */
  csum = localDW->obj.pCumSum + rtu_0;
  if (localDW->obj.pModValueRev == 0.0) {
    z = localDW->obj.pCumSumRev[(int16_T)localDW->obj.pCumRevIndex - 1] + csum;
  }

  localDW->obj.pCumSumRev[(int16_T)localDW->obj.pCumRevIndex - 1] = rtu_0;
  if (localDW->obj.pCumRevIndex != 3.0) {
    cumRevIndex = localDW->obj.pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    localDW->obj.pCumSumRev[1] += localDW->obj.pCumSumRev[2];
    localDW->obj.pCumSumRev[0] += localDW->obj.pCumSumRev[1];
  }

  if (localDW->obj.pModValueRev == 0.0) {
    /* MATLABSystem: '<S9>/Moving Average' */
    localB->MovingAverage = z / 4.0;
  }

  localDW->obj.pCumSum = csum;
  localDW->obj.pCumRevIndex = cumRevIndex;
  if (localDW->obj.pModValueRev > 0.0) {
    localDW->obj.pModValueRev--;
  } else {
    localDW->obj.pModValueRev = 0.0;
  }
}

/* Termination for atomic system: */
void LQR_Cont_MovingAverage_Term(DW_MovingAverage_LQR_Controll_T *localDW)
{
  /* Terminate for MATLABSystem: '<S9>/Moving Average' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      localDW->obj.NumChannels = -1L;
      localDW->obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Moving Average' */
}

static void LQR_Controll_SystemCore_setup_p(dsp_simulink_MovingAverage_p_T *obj)
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
void LQR_Controller_step0(void)        /* Sample time: [0.007s, 0.0s] */
{
  real_T Diff;
  real_T rtb_PendulumAngle;
  real_T rtb_TSamp;
  real_T z;
  int16_T cumRevIndex;
  uint16_T b_varargout_1;
  uint8_T tmp_0;
  boolean_T tmp;

  {                                    /* Sample time: [0.007s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   *  RateTransition generated from: '<S3>/Add2'
   */
  tmp = LQR_Controller_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    LQR_Controller_B.StateVector[0] =
      LQR_Controller_DW.TmpRTBAtStateVectorInport1_Buff;

    /* RateTransition generated from: '<Root>/State Vector' incorporates:
     *  Concatenate: '<Root>/State Vector'
     */
    LQR_Controller_B.StateVector[1] =
      LQR_Controller_DW.TmpRTBAtStateVectorInport2_Buff;
  }

  /* End of RateTransition generated from: '<Root>/State Vector' */

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
  rtb_PendulumAngle = (real_T)((uint32_T)LQR_Controller_P.Volt2Rad_Gain *
    b_varargout_1) * 1.1920928955078125E-7 + LQR_Controller_P.Constant_Value;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_PendulumAngle * LQR_Controller_P.TSamp_WtEt;

  /* Sum: '<S7>/Diff' incorporates:
   *  UnitDelay: '<S7>/UD'
   */
  Diff = rtb_TSamp - LQR_Controller_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (LQR_Controller_DW.obj.TunablePropsChanged) {
    LQR_Controller_DW.obj.TunablePropsChanged = false;
  }

  z = 0.0;
  LQR_Controller_B.MovingAverage = 0.0;
  LQR_Controller_B.csum = LQR_Controller_DW.obj.pCumSum + Diff;
  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    z = LQR_Controller_DW.obj.pCumSumRev[(int16_T)
      LQR_Controller_DW.obj.pCumRevIndex - 1] + LQR_Controller_B.csum;
  }

  LQR_Controller_DW.obj.pCumSumRev[(int16_T)LQR_Controller_DW.obj.pCumRevIndex -
    1] = Diff;
  if (LQR_Controller_DW.obj.pCumRevIndex != 2.0) {
    cumRevIndex = 2;
  } else {
    cumRevIndex = 1;
    LQR_Controller_B.csum = 0.0;
    LQR_Controller_DW.obj.pCumSumRev[0] += LQR_Controller_DW.obj.pCumSumRev[1];
  }

  if (LQR_Controller_DW.obj.pModValueRev == 0.0) {
    LQR_Controller_B.MovingAverage = z / 3.0;
  }

  LQR_Controller_DW.obj.pCumSum = LQR_Controller_B.csum;
  LQR_Controller_DW.obj.pCumRevIndex = cumRevIndex;
  if (LQR_Controller_DW.obj.pModValueRev > 0.0) {
    LQR_Controller_DW.obj.pModValueRev--;
  } else {
    LQR_Controller_DW.obj.pModValueRev = 0.0;
  }

  /* RateTransition generated from: '<S3>/Add2' */
  if (tmp) {
    /* RateTransition generated from: '<S3>/Add2' */
    LQR_Controller_B.TmpRTBAtAdd2Inport1 =
      LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Abs: '<Root>/Abs'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Pi'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/LQR Gains'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   *  Sum: '<Root>/Add'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S3>/Add2'
   */
  if (fabs(rtb_PendulumAngle - LQR_Controller_P.Pi_Value) >
      LQR_Controller_P.Switch_Threshold) {
    rtb_PendulumAngle = LQR_Controller_P.Constant1_Value;
  } else {
    /* SignalConversion generated from: '<S1>/Moving Average' incorporates:
     *  Concatenate: '<Root>/State Vector'
     *  MATLABSystem: '<S1>/Moving Average'
     */
    LQR_Controller_B.StateVector[3] = LQR_Controller_B.MovingAverage;

    /* SignalConversion generated from: '<Root>/State Vector' incorporates:
     *  Concatenate: '<Root>/State Vector'
     */
    LQR_Controller_B.StateVector[2] = rtb_PendulumAngle;
    rtb_PendulumAngle = (((((LQR_Controller_B.StateVector[0] -
      LQR_Controller_P.Constant4_Value) * LQR_Controller_P.K[0] +
      (LQR_Controller_B.StateVector[1] - LQR_Controller_P.Constant5_Value) *
      LQR_Controller_P.K[1]) + (LQR_Controller_B.StateVector[2] -
      LQR_Controller_P.Constant3_Value) * LQR_Controller_P.K[2]) +
                          (LQR_Controller_B.StateVector[3] -
      LQR_Controller_P.Constant6_Value) * LQR_Controller_P.K[3]) *
                         LQR_Controller_P.Gain2_Gain * (LQR_Controller_P.R_motor
      * LQR_Controller_P.r / LQR_Controller_P.k_motor) +
                         LQR_Controller_B.TmpRTBAtAdd2Inport1) *
      LQR_Controller_P.Gain4_Gain;
  }

  /* End of Switch: '<Root>/Switch' */
  /* MATLAB Function: '<S2>/Select PWM Direction' */
  if (rtb_PendulumAngle > 0.0) {
    Diff = 0.0;
  } else {
    Diff = -rtb_PendulumAngle;
    rtb_PendulumAngle = 0.0;
  }

  /* End of MATLAB Function: '<S2>/Select PWM Direction' */

  /* MATLABSystem: '<S2>/PWM' */
  LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(rtb_PendulumAngle <= 255.0)) {
    rtb_PendulumAngle = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_PendulumAngle);

  /* MATLABSystem: '<S2>/PWM1' */
  LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S2>/PWM1' */
  if (!(Diff <= 255.0)) {
    Diff = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM1' */
  MW_PWM_SetDutyCycle(LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, Diff);

  /* MATLABSystem: '<S6>/Analog Input' */
  LQR_Controller_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (LQR_Controller_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<S6>/Bias' incorporates:
   *  Constant: '<S6>/Constant2'
   *  MATLABSystem: '<S6>/Analog Input'
   * */
  Diff = (real_T)b_varargout_1 - LQR_Controller_P.Constant2_Value;

  /* DeadZone: '<S6>/Dead Zone1' */
  if (Diff > LQR_Controller_P.DeadZone1_End) {
    rtb_PendulumAngle = Diff - LQR_Controller_P.DeadZone1_End;
  } else if (Diff >= LQR_Controller_P.DeadZone1_Start) {
    rtb_PendulumAngle = 0.0;
  } else {
    rtb_PendulumAngle = Diff - LQR_Controller_P.DeadZone1_Start;
  }

  /* End of DeadZone: '<S6>/Dead Zone1' */

  /* MATLABSystem: '<S6>/Analog Input1' */
  LQR_Controller_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (LQR_Controller_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<S6>/Bias1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  MATLABSystem: '<S6>/Analog Input1'
   * */
  Diff = (real_T)b_varargout_1 - LQR_Controller_P.Constant1_Value_n;

  /* DeadZone: '<S6>/Dead Zone' */
  if (Diff > LQR_Controller_P.DeadZone_End) {
    Diff -= LQR_Controller_P.DeadZone_End;
  } else if (Diff >= LQR_Controller_P.DeadZone_Start) {
    Diff = 0.0;
  } else {
    Diff -= LQR_Controller_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S6>/Dead Zone' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  if (rtb_PendulumAngle > 0.0) {
    Diff = -rtb_PendulumAngle;
  } else if (!(Diff > 0.0)) {
    Diff = 0.0;
  }

  /* Gain: '<S6>/Voltage to Current' incorporates:
   *  Gain: '<S6>/Analog to Voltage'
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  LQR_Controller_B.VoltagetoCurrent = LQR_Controller_P.AnalogtoVoltage_Gain *
    Diff * LQR_Controller_P.VoltagetoCurrent_Gain;
  LQR_Controlle_MovingAverage(LQR_Controller_B.VoltagetoCurrent,
    &LQR_Controller_B.MovingAverage_pn, &LQR_Controller_DW.MovingAverage_pn);

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  rtb_PendulumAngle = rt_roundd_snf(LQR_Controller_P.Constant2_Value_i);
  if (rtb_PendulumAngle < 256.0) {
    if (rtb_PendulumAngle >= 0.0) {
      tmp_0 = (uint8_T)rtb_PendulumAngle;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);

  /* End of MATLABSystem: '<S5>/Digital Output1' */

  /* MATLABSystem: '<S5>/Digital Output2' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  rtb_PendulumAngle = rt_roundd_snf(LQR_Controller_P.Constant2_Value_i);
  if (rtb_PendulumAngle < 256.0) {
    if (rtb_PendulumAngle >= 0.0) {
      tmp_0 = (uint8_T)rtb_PendulumAngle;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S5>/Digital Output2' */

  /* Update for UnitDelay: '<S7>/UD' */
  LQR_Controller_DW.UD_DSTATE = rtb_TSamp;
}

/* Model step function for TID1 */
void LQR_Controller_step1(void)        /* Sample time: [0.014s, 0.0s] */
{
  real_T rtb_Gain1;
  real_T rtb_radstoms;
  int32_T qY;
  int32_T rtb_Encoder;

  /* RateTransition generated from: '<Root>/State Vector' */
  LQR_Controller_DW.TmpRTBAtStateVectorInport1_Buff =
    LQR_Controller_DW.PositionIntegration_DSTATE;

  /* MATLABSystem: '<S9>/Encoder' */
  if (LQR_Controller_DW.obj_lf.TunablePropsChanged) {
    LQR_Controller_DW.obj_lf.TunablePropsChanged = false;
  }

  MW_EncoderRead(LQR_Controller_DW.obj_lf.Index, &rtb_Encoder);
  MW_EncoderReset(LQR_Controller_DW.obj_lf.Index);

  /* End of MATLABSystem: '<S9>/Encoder' */
  /* MATLAB Function: '<S9>/Filter for data dropouts' */
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

  /* End of MATLAB Function: '<S9>/Filter for data dropouts' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Gain: '<S9>/Ticks to RPM'
   */
  LQR_Controller_B.DataTypeConversion = (real_T)((int64_T)
    LQR_Controller_P.TickstoRPM_Gain * rtb_Encoder) * 1.862645149230957E-9;
  LQR_Controlle_MovingAverage(LQR_Controller_B.DataTypeConversion,
    &LQR_Controller_B.MovingAverage_p, &LQR_Controller_DW.MovingAverage_p);

  /* Gain: '<S2>/rad//s to m//s' incorporates:
   *  Gain: '<S2>/RPM to rad//s'
   */
  rtb_radstoms = LQR_Controller_P.RPMtorads_Gain *
    LQR_Controller_B.MovingAverage_p.MovingAverage *
    LQR_Controller_P.radstoms_Gain;

  /* Gain: '<S3>/Gain1' */
  rtb_Gain1 = LQR_Controller_P.k_motor / LQR_Controller_P.r * rtb_radstoms;

  /* RateTransition generated from: '<S3>/Add2' */
  LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0 = rtb_Gain1;

  /* RateTransition generated from: '<Root>/State Vector' */
  LQR_Controller_DW.TmpRTBAtStateVectorInport2_Buff = rtb_radstoms;

  /* Update for DiscreteIntegrator: '<S2>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE +=
    LQR_Controller_P.PositionIntegration_gainval * rtb_radstoms;

  /* Update for DiscreteIntegrator: '<S2>/Position Integration' */
  if (LQR_Controller_DW.PositionIntegration_DSTATE >
      LQR_Controller_P.PositionIntegration_UpperSat) {
    /* Update for DiscreteIntegrator: '<S2>/Position Integration' */
    LQR_Controller_DW.PositionIntegration_DSTATE =
      LQR_Controller_P.PositionIntegration_UpperSat;
  } else if (LQR_Controller_DW.PositionIntegration_DSTATE <
             LQR_Controller_P.PositionIntegration_LowerSat) {
    /* Update for DiscreteIntegrator: '<S2>/Position Integration' */
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

  /* Start for RateTransition generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[0] =
    LQR_Controller_P.TmpRTBAtStateVectorInport1_Init;

  /* Start for RateTransition generated from: '<Root>/State Vector' incorporates:
   *  Concatenate: '<Root>/State Vector'
   */
  LQR_Controller_B.StateVector[1] =
    LQR_Controller_P.TmpRTBAtStateVectorInport2_Init;

  /* Start for MATLABSystem: '<S1>/Analog Input' */
  LQR_Controller_DW.obj_h.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_i = true;
  LQR_Controller_DW.obj_h.isInitialized = 1L;
  LQR_Controller_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  LQR_Controller_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  LQR_Controller_DW.obj.isInitialized = 0L;
  LQR_Controller_DW.obj.NumChannels = -1L;
  LQR_Controller_DW.obj.FrameLength = -1L;
  LQR_Controller_DW.obj.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_cu = true;
  LQR_Controll_SystemCore_setup_p(&LQR_Controller_DW.obj);

  /* Start for RateTransition generated from: '<S3>/Add2' */
  LQR_Controller_B.TmpRTBAtAdd2Inport1 =
    LQR_Controller_P.TmpRTBAtAdd2Inport1_InitialCond;

  /* Start for MATLABSystem: '<S2>/PWM' */
  LQR_Controller_DW.obj_d.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_f = true;
  LQR_Controller_DW.obj_d.isInitialized = 1L;
  LQR_Controller_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  LQR_Controller_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM1' */
  LQR_Controller_DW.obj_e.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_o = true;
  LQR_Controller_DW.obj_e.isInitialized = 1L;
  LQR_Controller_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  LQR_Controller_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Analog Input' */
  LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_c = true;
  LQR_Controller_DW.obj_l.isInitialized = 1L;
  LQR_Controller_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  LQR_Controller_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Analog Input1' */
  LQR_Controller_DW.obj_a.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty = true;
  LQR_Controller_DW.obj_a.isInitialized = 1L;
  LQR_Controller_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(16UL);
  LQR_Controller_DW.obj_a.isSetupComplete = true;
  LQR_Con_MovingAverage_Start(&LQR_Controller_DW.MovingAverage_pn);

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_j = true;
  LQR_Controller_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(7, 1);
  LQR_Controller_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output2' */
  LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_d = true;
  LQR_Controller_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  LQR_Controller_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Encoder' */
  LQR_Controller_DW.obj_lf.Index = 0U;
  LQR_Controller_DW.obj_lf.matlabCodegenIsDeleted = false;
  LQR_Controller_DW.objisempty_m = true;
  LQR_Controller_DW.obj_lf.isSetupComplete = false;
  LQR_Controller_DW.obj_lf.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &LQR_Controller_DW.obj_lf.Index);
  LQR_Controller_DW.obj_lf.isSetupComplete = true;
  LQR_Controller_DW.obj_lf.TunablePropsChanged = false;
  LQR_Con_MovingAverage_Start(&LQR_Controller_DW.MovingAverage_p);

  /* InitializeConditions for RateTransition generated from: '<Root>/State Vector' */
  LQR_Controller_DW.TmpRTBAtStateVectorInport1_Buff =
    LQR_Controller_P.TmpRTBAtStateVectorInport1_Init;

  /* InitializeConditions for RateTransition generated from: '<Root>/State Vector' */
  LQR_Controller_DW.TmpRTBAtStateVectorInport2_Buff =
    LQR_Controller_P.TmpRTBAtStateVectorInport2_Init;

  /* InitializeConditions for UnitDelay: '<S7>/UD' */
  LQR_Controller_DW.UD_DSTATE = LQR_Controller_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for RateTransition generated from: '<S3>/Add2' */
  LQR_Controller_DW.TmpRTBAtAdd2Inport1_Buffer0 =
    LQR_Controller_P.TmpRTBAtAdd2Inport1_InitialCond;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Position Integration' */
  LQR_Controller_DW.PositionIntegration_DSTATE =
    LQR_Controller_P.PositionIntegration_IC;

  /* SystemInitialize for MATLAB Function: '<S9>/Filter for data dropouts' */
  LQR_Controller_DW.prevVal_not_empty = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  LQR_Controller_DW.obj.pCumSum = 0.0;
  LQR_Controller_DW.obj.pCumSumRev[0] = 0.0;
  LQR_Controller_DW.obj.pCumSumRev[1] = 0.0;
  LQR_Controller_DW.obj.pCumRevIndex = 1.0;
  LQR_Controller_DW.obj.pModValueRev = 0.0;
  LQR_Cont_MovingAverage_Init(&LQR_Controller_DW.MovingAverage_pn);

  /* InitializeConditions for MATLABSystem: '<S9>/Encoder' */
  MW_EncoderReset(LQR_Controller_DW.obj_lf.Index);
  LQR_Cont_MovingAverage_Init(&LQR_Controller_DW.MovingAverage_p);
}

/* Model terminate function */
void LQR_Controller_terminate(void)
{
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

  /* Terminate for MATLABSystem: '<S2>/PWM' */
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

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/PWM1' */
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

  /* End of Terminate for MATLABSystem: '<S2>/PWM1' */

  /* Terminate for MATLABSystem: '<S6>/Analog Input' */
  if (!LQR_Controller_DW.obj_l.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_l.isInitialized == 1L) &&
        LQR_Controller_DW.obj_l.isSetupComplete) {
      LQR_Controller_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (LQR_Controller_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog Input' */

  /* Terminate for MATLABSystem: '<S6>/Analog Input1' */
  if (!LQR_Controller_DW.obj_a.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_a.isInitialized == 1L) &&
        LQR_Controller_DW.obj_a.isSetupComplete) {
      LQR_Controller_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (LQR_Controller_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog Input1' */
  LQR_Cont_MovingAverage_Term(&LQR_Controller_DW.MovingAverage_pn);

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!LQR_Controller_DW.obj_n.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output2' */
  if (!LQR_Controller_DW.obj_m.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S9>/Encoder' */
  if (!LQR_Controller_DW.obj_lf.matlabCodegenIsDeleted) {
    LQR_Controller_DW.obj_lf.matlabCodegenIsDeleted = true;
    if ((LQR_Controller_DW.obj_lf.isInitialized == 1L) &&
        LQR_Controller_DW.obj_lf.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Encoder' */
  LQR_Cont_MovingAverage_Term(&LQR_Controller_DW.MovingAverage_p);
}
