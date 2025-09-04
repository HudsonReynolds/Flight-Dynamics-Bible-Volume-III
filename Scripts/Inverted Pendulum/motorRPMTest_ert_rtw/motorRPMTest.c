/*
 * motorRPMTest.c
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
#include "rtwtypes.h"
#include "motorRPMTest_types.h"
#include "motorRPMTest_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>

/* Block signals (default storage) */
B_motorRPMTest_T motorRPMTest_B;

/* Block states (default storage) */
DW_motorRPMTest_T motorRPMTest_DW;

/* Real-time model */
static RT_MODEL_motorRPMTest_T motorRPMTest_M_;
RT_MODEL_motorRPMTest_T *const motorRPMTest_M = &motorRPMTest_M_;

/* Forward declaration for local functions */
static void motorRPMTest_SystemCore_setup(dsp_simulink_MovingAverage_mo_T *obj);
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

static void motorRPMTest_SystemCore_setup(dsp_simulink_MovingAverage_mo_T *obj)
{
  obj->isInitialized = 1L;

  /* Start for MATLABSystem: '<S62>/Moving Average' */
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
void motorRPMTest_MovingAverage_Init(DW_MovingAverage_motorRPMTest_T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S62>/Moving Average' */
  localDW->obj.pCumSum = 0.0;
  localDW->obj.pCumSumRev[0] = 0.0;
  localDW->obj.pCumSumRev[1] = 0.0;
  localDW->obj.pCumSumRev[2] = 0.0;
  localDW->obj.pCumRevIndex = 1.0;
  localDW->obj.pModValueRev = 0.0;
}

/* Start for atomic system: */
void motorRPMTes_MovingAverage_Start(DW_MovingAverage_motorRPMTest_T *localDW)
{
  /* Start for MATLABSystem: '<S62>/Moving Average' */
  localDW->obj.isInitialized = 0L;
  localDW->obj.NumChannels = -1L;
  localDW->obj.FrameLength = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  motorRPMTest_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void motorRPMTest_MovingAverage(real_T rtu_0, B_MovingAverage_motorRPMTest_T
  *localB, DW_MovingAverage_motorRPMTest_T *localDW)
{
  real_T csum;
  real_T cumRevIndex;
  real_T z;

  /* MATLABSystem: '<S62>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  z = 0.0;

  /* MATLABSystem: '<S62>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S62>/Moving Average' */
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
    /* MATLABSystem: '<S62>/Moving Average' */
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
void motorRPMTest_MovingAverage_Term(DW_MovingAverage_motorRPMTest_T *localDW)
{
  /* Terminate for MATLABSystem: '<S62>/Moving Average' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      localDW->obj.NumChannels = -1L;
      localDW->obj.FrameLength = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S62>/Moving Average' */
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

/* Model step function */
void motorRPMTest_step(void)
{
  real_T Product2;
  real_T Product2_0;
  int32_T qY;
  int32_T rtb_Encoder;
  uint32_T rtb_PendulumAngle;
  uint32_T tmp;
  int16_T i;
  int16_T tmp_1;
  uint16_T b_varargout_1;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  motorRPMTest_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (motorRPMTest_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Volt2Rad' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  rtb_PendulumAngle = (uint32_T)motorRPMTest_P.Volt2Rad_Gain * b_varargout_1;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  Gain: '<Root>/Volt2Rad'
   */
  if (!motorRPMTest_DW.calibrated) {
    motorRPMTest_DW.sample_count++;

    /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
     *  Gain: '<Root>/Volt2Rad'
     */
    motorRPMTest_B.theta_cal = (real_T)rtb_PendulumAngle * 1.1920928955078125E-7;
    motorRPMTest_DW.theta_sum += motorRPMTest_B.theta_cal;
    if (motorRPMTest_DW.sample_count >= motorRPMTest_DW.N) {
      motorRPMTest_DW.theta0 = motorRPMTest_DW.theta_sum / motorRPMTest_DW.N;
      motorRPMTest_DW.calibrated = true;
      motorRPMTest_B.theta_cal = (real_T)rtb_PendulumAngle *
        1.1920928955078125E-7 - motorRPMTest_DW.theta0;
    }
  } else {
    motorRPMTest_B.theta_cal = (real_T)rtb_PendulumAngle * 1.1920928955078125E-7
      - motorRPMTest_DW.theta0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Reshape: '<S2>/Reshapey' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  motorRPMTest_B.Reshapey[0] = motorRPMTest_P.Constant1_Value;
  motorRPMTest_B.Reshapey[1] = motorRPMTest_B.theta_cal;

  /* Delay: '<S2>/MemoryX' incorporates:
   *  Constant: '<S2>/X0'
   */
  if (motorRPMTest_DW.icLoad) {
    motorRPMTest_DW.MemoryX_DSTATE[0] = motorRPMTest_P.X0_Value[0];
    motorRPMTest_DW.MemoryX_DSTATE[1] = motorRPMTest_P.X0_Value[1];
    motorRPMTest_DW.MemoryX_DSTATE[2] = motorRPMTest_P.X0_Value[2];
    motorRPMTest_DW.MemoryX_DSTATE[3] = motorRPMTest_P.X0_Value[3];
  }

  /* Outputs for Enabled SubSystem: '<S27>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  /* Constant: '<S2>/Enable' */
  if (motorRPMTest_P.Enable_Value) {
    motorRPMTest_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S58>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S2>/C'
     *  Delay: '<S2>/MemoryX'
     */
    motorRPMTest_B.rtb_Add_idx_0 = 0.0;
    motorRPMTest_B.rtb_Add_idx_1 = 0.0;
    for (i = 0; i < 4; i++) {
      motorRPMTest_B.CurrenttoTorque = motorRPMTest_DW.MemoryX_DSTATE[i];
      tmp_1 = i << 1;
      motorRPMTest_B.rtb_Add_idx_0 += motorRPMTest_P.C_Value[tmp_1] *
        motorRPMTest_B.CurrenttoTorque;
      motorRPMTest_B.rtb_Add_idx_1 += motorRPMTest_P.C_Value[tmp_1 + 1] *
        motorRPMTest_B.CurrenttoTorque;
    }

    /* End of Product: '<S58>/C[k]*xhat[k|k-1]' */

    /* Sum: '<S58>/Sum' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Constant: '<S2>/D'
     *  Product: '<S58>/D[k]*u[k]'
     *  Reshape: '<S2>/Reshapey'
     *  Sum: '<S58>/Add1'
     */
    motorRPMTest_B.rtb_Reshapey_m[0] = motorRPMTest_P.Constant1_Value -
      (motorRPMTest_P.D_Value[0] * motorRPMTest_P.Constant2_Value +
       motorRPMTest_B.rtb_Add_idx_0);
    motorRPMTest_B.rtb_Reshapey_m[1] = motorRPMTest_B.theta_cal -
      (motorRPMTest_P.D_Value[1] * motorRPMTest_P.Constant2_Value +
       motorRPMTest_B.rtb_Add_idx_1);

    /* Product: '<S58>/Product3' incorporates:
     *  Constant: '<S7>/KalmanGainL'
     */
    motorRPMTest_B.rtb_Add_idx_0 = 0.0;
    motorRPMTest_B.rtb_Add_idx_1 = 0.0;
    motorRPMTest_B.rtb_Add_idx_2 = 0.0;
    motorRPMTest_B.rtb_Add_idx_3 = 0.0;
    for (i = 0; i < 2; i++) {
      motorRPMTest_B.CurrenttoTorque = motorRPMTest_B.rtb_Reshapey_m[i];
      tmp_1 = i << 2;
      motorRPMTest_B.rtb_Add_idx_0 += motorRPMTest_P.KalmanGainL_Value[tmp_1] *
        motorRPMTest_B.CurrenttoTorque;
      motorRPMTest_B.rtb_Add_idx_1 += motorRPMTest_P.KalmanGainL_Value[tmp_1 + 1]
        * motorRPMTest_B.CurrenttoTorque;
      motorRPMTest_B.rtb_Add_idx_2 += motorRPMTest_P.KalmanGainL_Value[tmp_1 + 2]
        * motorRPMTest_B.CurrenttoTorque;
      motorRPMTest_B.rtb_Add_idx_3 += motorRPMTest_P.KalmanGainL_Value[tmp_1 + 3]
        * motorRPMTest_B.CurrenttoTorque;
    }

    motorRPMTest_B.Product3[3] = motorRPMTest_B.rtb_Add_idx_3;
    motorRPMTest_B.Product3[2] = motorRPMTest_B.rtb_Add_idx_2;
    motorRPMTest_B.Product3[1] = motorRPMTest_B.rtb_Add_idx_1;
    motorRPMTest_B.Product3[0] = motorRPMTest_B.rtb_Add_idx_0;

    /* End of Product: '<S58>/Product3' */
  } else if (motorRPMTest_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S58>/Product3' incorporates:
     *  Outport: '<S58>/L*(y[k]-yhat[k|k-1])'
     */
    motorRPMTest_B.Product3[0] = motorRPMTest_P.Lykyhatkk1_Y0;
    motorRPMTest_B.Product3[1] = motorRPMTest_P.Lykyhatkk1_Y0;
    motorRPMTest_B.Product3[2] = motorRPMTest_P.Lykyhatkk1_Y0;
    motorRPMTest_B.Product3[3] = motorRPMTest_P.Lykyhatkk1_Y0;
    motorRPMTest_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S27>/MeasurementUpdate' */

  /* Product: '<S27>/B[k]*u[k]' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S2>/B'
   *  Sum: '<S34>/Add'
   */
  motorRPMTest_B.Add_i[0] = motorRPMTest_P.B_Value[0] *
    motorRPMTest_P.Constant2_Value;

  /* Product: '<S27>/A[k]*xhat[k|k-1]' */
  motorRPMTest_B.rtb_Add_idx_0 = 0.0;

  /* Product: '<S27>/B[k]*u[k]' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S2>/B'
   *  Sum: '<S34>/Add'
   */
  motorRPMTest_B.Add_i[1] = motorRPMTest_P.B_Value[1] *
    motorRPMTest_P.Constant2_Value;

  /* Product: '<S27>/A[k]*xhat[k|k-1]' */
  motorRPMTest_B.rtb_Add_idx_1 = 0.0;

  /* Product: '<S27>/B[k]*u[k]' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S2>/B'
   *  Sum: '<S34>/Add'
   */
  motorRPMTest_B.Add_i[2] = motorRPMTest_P.B_Value[2] *
    motorRPMTest_P.Constant2_Value;

  /* Product: '<S27>/A[k]*xhat[k|k-1]' */
  motorRPMTest_B.rtb_Add_idx_2 = 0.0;

  /* Product: '<S27>/B[k]*u[k]' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S2>/B'
   *  Sum: '<S34>/Add'
   */
  motorRPMTest_B.Add_i[3] = motorRPMTest_P.B_Value[3] *
    motorRPMTest_P.Constant2_Value;

  /* Product: '<S27>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S2>/A'
   *  Delay: '<S2>/MemoryX'
   */
  motorRPMTest_B.rtb_Add_idx_3 = 0.0;
  for (i = 0; i < 4; i++) {
    motorRPMTest_B.CurrenttoTorque = motorRPMTest_DW.MemoryX_DSTATE[i];
    tmp_1 = i << 2;
    motorRPMTest_B.rtb_Add_idx_0 += motorRPMTest_P.A_Value[tmp_1] *
      motorRPMTest_B.CurrenttoTorque;
    motorRPMTest_B.rtb_Add_idx_1 += motorRPMTest_P.A_Value[tmp_1 + 1] *
      motorRPMTest_B.CurrenttoTorque;
    motorRPMTest_B.rtb_Add_idx_2 += motorRPMTest_P.A_Value[tmp_1 + 2] *
      motorRPMTest_B.CurrenttoTorque;
    motorRPMTest_B.rtb_Add_idx_3 += motorRPMTest_P.A_Value[tmp_1 + 3] *
      motorRPMTest_B.CurrenttoTorque;
  }

  /* Sum: '<S27>/Add' incorporates:
   *  Product: '<S58>/Product3'
   *  Sum: '<S34>/Add'
   */
  motorRPMTest_B.rtb_Add_idx_0 = (motorRPMTest_B.Add_i[0] +
    motorRPMTest_B.rtb_Add_idx_0) + motorRPMTest_B.Product3[0];
  motorRPMTest_B.rtb_Add_idx_1 = (motorRPMTest_B.Add_i[1] +
    motorRPMTest_B.rtb_Add_idx_1) + motorRPMTest_B.Product3[1];
  motorRPMTest_B.rtb_Add_idx_2 = (motorRPMTest_B.Add_i[2] +
    motorRPMTest_B.rtb_Add_idx_2) + motorRPMTest_B.Product3[2];
  motorRPMTest_B.rtb_Add_idx_3 = (motorRPMTest_B.Add_i[3] +
    motorRPMTest_B.rtb_Add_idx_3) + motorRPMTest_B.Product3[3];

  /* Outputs for Enabled SubSystem: '<S34>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  /* Constant: '<S2>/Enable' */
  if (motorRPMTest_P.Enable_Value) {
    motorRPMTest_DW.EnabledSubsystem_MODE = true;

    /* Delay: '<S2>/MemoryX' incorporates:
     *  Constant: '<S2>/C'
     *  Product: '<S60>/Product'
     */
    motorRPMTest_B.CurrenttoTorque = motorRPMTest_DW.MemoryX_DSTATE[1];
    motorRPMTest_B.TSamp = motorRPMTest_DW.MemoryX_DSTATE[0];
    motorRPMTest_B.e = motorRPMTest_DW.MemoryX_DSTATE[2];
    motorRPMTest_B.Saturation = motorRPMTest_DW.MemoryX_DSTATE[3];

    /* Product: '<S60>/Product2' */
    motorRPMTest_B.Product2_k = 0.0;
    motorRPMTest_B.Product2_c = 0.0;
    Product2 = 0.0;
    Product2_0 = 0.0;
    for (i = 0; i < 2; i++) {
      /* Sum: '<S60>/Add1' incorporates:
       *  Constant: '<S2>/C'
       *  Delay: '<S2>/MemoryX'
       *  Product: '<S60>/Product'
       */
      motorRPMTest_B.rtb_Reshapey_c = motorRPMTest_B.Reshapey[i] -
        (((motorRPMTest_P.C_Value[i + 2] * motorRPMTest_B.CurrenttoTorque +
           motorRPMTest_P.C_Value[i] * motorRPMTest_B.TSamp) +
          motorRPMTest_P.C_Value[i + 4] * motorRPMTest_B.e) +
         motorRPMTest_P.C_Value[i + 6] * motorRPMTest_B.Saturation);

      /* Product: '<S60>/Product2' incorporates:
       *  Constant: '<S7>/KalmanGainM'
       */
      tmp_1 = i << 2;
      motorRPMTest_B.Product2_k += motorRPMTest_P.KalmanGainM_Value[tmp_1] *
        motorRPMTest_B.rtb_Reshapey_c;
      motorRPMTest_B.Product2_c += motorRPMTest_P.KalmanGainM_Value[tmp_1 + 1] *
        motorRPMTest_B.rtb_Reshapey_c;
      Product2 += motorRPMTest_P.KalmanGainM_Value[tmp_1 + 2] *
        motorRPMTest_B.rtb_Reshapey_c;
      Product2_0 += motorRPMTest_P.KalmanGainM_Value[tmp_1 + 3] *
        motorRPMTest_B.rtb_Reshapey_c;
    }

    /* Product: '<S60>/Product2' */
    motorRPMTest_B.Product2[3] = Product2_0;
    motorRPMTest_B.Product2[2] = Product2;
    motorRPMTest_B.Product2[1] = motorRPMTest_B.Product2_c;
    motorRPMTest_B.Product2[0] = motorRPMTest_B.Product2_k;
  } else if (motorRPMTest_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S60>/Product2' incorporates:
     *  Outport: '<S60>/deltax'
     */
    motorRPMTest_B.Product2[0] = motorRPMTest_P.deltax_Y0;
    motorRPMTest_B.Product2[1] = motorRPMTest_P.deltax_Y0;
    motorRPMTest_B.Product2[2] = motorRPMTest_P.deltax_Y0;
    motorRPMTest_B.Product2[3] = motorRPMTest_P.deltax_Y0;
    motorRPMTest_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S34>/Enabled Subsystem' */

  /* Sum: '<S34>/Add' incorporates:
   *  Delay: '<S2>/MemoryX'
   */
  motorRPMTest_B.Add_i[0] = motorRPMTest_B.Product2[0] +
    motorRPMTest_DW.MemoryX_DSTATE[0];
  motorRPMTest_B.Add_i[1] = motorRPMTest_B.Product2[1] +
    motorRPMTest_DW.MemoryX_DSTATE[1];
  motorRPMTest_B.Add_i[2] = motorRPMTest_B.Product2[2] +
    motorRPMTest_DW.MemoryX_DSTATE[2];
  motorRPMTest_B.Add_i[3] = motorRPMTest_B.Product2[3] +
    motorRPMTest_DW.MemoryX_DSTATE[3];

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  motorRPMTest_B.TSamp = motorRPMTest_B.theta_cal * motorRPMTest_P.TSamp_WtEt;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   */
  motorRPMTest_B.e = motorRPMTest_B.TSamp - motorRPMTest_DW.UD_DSTATE;

  /* MATLABSystem: '<S62>/Encoder' */
  if (motorRPMTest_DW.obj_k.TunablePropsChanged) {
    motorRPMTest_DW.obj_k.TunablePropsChanged = false;
  }

  MW_EncoderRead(motorRPMTest_DW.obj_k.Index, &rtb_Encoder);
  MW_EncoderReset(motorRPMTest_DW.obj_k.Index);

  /* End of MATLABSystem: '<S62>/Encoder' */

  /* MATLAB Function: '<S62>/Filter for data dropouts' */
  if (!motorRPMTest_DW.prevVal_not_empty) {
    motorRPMTest_DW.prevVal = rtb_Encoder;
    motorRPMTest_DW.prevVal_not_empty = true;
  }

  if ((rtb_Encoder >= 0L) && (motorRPMTest_DW.prevVal < rtb_Encoder -
       MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((rtb_Encoder < 0L) && (motorRPMTest_DW.prevVal > rtb_Encoder -
              MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = rtb_Encoder - motorRPMTest_DW.prevVal;
  }

  if (qY < 0L) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY <= 200L) {
    if (rtb_Encoder < 0L) {
      if (rtb_Encoder <= MIN_int32_T) {
        qY = MAX_int32_T;
      } else {
        qY = -rtb_Encoder;
      }
    } else {
      qY = rtb_Encoder;
    }

    if (qY <= 500L) {
      motorRPMTest_DW.prevVal = rtb_Encoder;
    }
  }

  /* End of MATLAB Function: '<S62>/Filter for data dropouts' */

  /* Gain: '<S62>/Ticks to RPM' */
  rtb_PendulumAngle = (uint32_T)motorRPMTest_P.TickstoRPM_Gain;
  tmp = (uint32_T)motorRPMTest_DW.prevVal;
  sMultiWordMul(&rtb_PendulumAngle, 1, &tmp, 1, &motorRPMTest_B.r.chunks[0U], 2);

  /* DataTypeConversion: '<S62>/Data Type Conversion' */
  motorRPMTest_B.DataTypeConversion = sMultiWord2Double
    (&motorRPMTest_B.r.chunks[0U], 2, 0) * 1.4901161193847656E-8;
  motorRPMTest_MovingAverage(motorRPMTest_B.DataTypeConversion,
    &motorRPMTest_B.MovingAverage, &motorRPMTest_DW.MovingAverage);

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  motorRPMTest_B.e = motorRPMTest_P.Constant_Value -
    motorRPMTest_B.MovingAverage.MovingAverage;

  /* Sum: '<S107>/Sum' incorporates:
   *  DiscreteIntegrator: '<S98>/Integrator'
   *  Gain: '<S103>/Proportional Gain'
   */
  motorRPMTest_B.CurrenttoTorque = motorRPMTest_P.PIDController_P *
    motorRPMTest_B.e + motorRPMTest_DW.Integrator_DSTATE;

  /* Saturate: '<S105>/Saturation' */
  if (motorRPMTest_B.CurrenttoTorque >
      motorRPMTest_P.PIDController_UpperSaturationLi) {
    motorRPMTest_B.Saturation = motorRPMTest_P.PIDController_UpperSaturationLi;
  } else if (motorRPMTest_B.CurrenttoTorque <
             motorRPMTest_P.PIDController_LowerSaturationLi) {
    motorRPMTest_B.Saturation = motorRPMTest_P.PIDController_LowerSaturationLi;
  } else {
    motorRPMTest_B.Saturation = motorRPMTest_B.CurrenttoTorque;
  }

  /* End of Saturate: '<S105>/Saturation' */

  /* Gain: '<S90>/Kb' incorporates:
   *  Sum: '<S90>/SumI2'
   */
  motorRPMTest_B.theta_cal = (motorRPMTest_B.Saturation -
    motorRPMTest_B.CurrenttoTorque) * motorRPMTest_P.PIDController_Kb;

  /* MATLAB Function: '<S4>/Select PWM Direction' */
  if (motorRPMTest_B.Saturation > 0.0) {
    motorRPMTest_B.CurrenttoTorque = 0.0;
  } else {
    motorRPMTest_B.CurrenttoTorque = -motorRPMTest_B.Saturation;
    motorRPMTest_B.Saturation = 0.0;
  }

  /* End of MATLAB Function: '<S4>/Select PWM Direction' */

  /* MATLABSystem: '<S4>/PWM' */
  motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S4>/PWM' */
  if (!(motorRPMTest_B.Saturation <= 255.0)) {
    motorRPMTest_B.Saturation = 255.0;
  }

  /* MATLABSystem: '<S4>/PWM' */
  MW_PWM_SetDutyCycle(motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                      motorRPMTest_B.Saturation);

  /* MATLABSystem: '<S4>/PWM1' */
  motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S4>/PWM1' */
  if (!(motorRPMTest_B.CurrenttoTorque <= 255.0)) {
    motorRPMTest_B.CurrenttoTorque = 255.0;
  }

  /* MATLABSystem: '<S4>/PWM1' */
  MW_PWM_SetDutyCycle(motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                      motorRPMTest_B.CurrenttoTorque);

  /* MATLABSystem: '<S6>/Analog Input' */
  motorRPMTest_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (motorRPMTest_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Sum: '<S6>/Bias' incorporates:
   *  Constant: '<S6>/Constant2'
   *  MATLABSystem: '<S6>/Analog Input'
   * */
  motorRPMTest_B.CurrenttoTorque = (real_T)b_varargout_1 -
    motorRPMTest_P.Constant2_Value_b;

  /* DeadZone: '<S6>/Dead Zone1' */
  if (motorRPMTest_B.CurrenttoTorque > motorRPMTest_P.DeadZone1_End) {
    motorRPMTest_B.Saturation = motorRPMTest_B.CurrenttoTorque -
      motorRPMTest_P.DeadZone1_End;
  } else if (motorRPMTest_B.CurrenttoTorque >= motorRPMTest_P.DeadZone1_Start) {
    motorRPMTest_B.Saturation = 0.0;
  } else {
    motorRPMTest_B.Saturation = motorRPMTest_B.CurrenttoTorque -
      motorRPMTest_P.DeadZone1_Start;
  }

  /* End of DeadZone: '<S6>/Dead Zone1' */

  /* MATLABSystem: '<S6>/Analog Input1' */
  motorRPMTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (motorRPMTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Sum: '<S6>/Bias1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  MATLABSystem: '<S6>/Analog Input1'
   * */
  motorRPMTest_B.CurrenttoTorque = (real_T)b_varargout_1 -
    motorRPMTest_P.Constant1_Value_m;

  /* DeadZone: '<S6>/Dead Zone' */
  if (motorRPMTest_B.CurrenttoTorque > motorRPMTest_P.DeadZone_End) {
    motorRPMTest_B.CurrenttoTorque -= motorRPMTest_P.DeadZone_End;
  } else if (motorRPMTest_B.CurrenttoTorque >= motorRPMTest_P.DeadZone_Start) {
    motorRPMTest_B.CurrenttoTorque = 0.0;
  } else {
    motorRPMTest_B.CurrenttoTorque -= motorRPMTest_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S6>/Dead Zone' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  if (motorRPMTest_B.Saturation > 0.0) {
    motorRPMTest_B.CurrenttoTorque = -motorRPMTest_B.Saturation;
  } else if (!(motorRPMTest_B.CurrenttoTorque > 0.0)) {
    motorRPMTest_B.CurrenttoTorque = 0.0;
  }

  /* Gain: '<S6>/Voltage to Current' incorporates:
   *  Gain: '<S6>/Analog to Voltage'
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  motorRPMTest_B.VoltagetoCurrent = motorRPMTest_P.AnalogtoVoltage_Gain *
    motorRPMTest_B.CurrenttoTorque * motorRPMTest_P.VoltagetoCurrent_Gain;
  motorRPMTest_MovingAverage(motorRPMTest_B.VoltagetoCurrent,
    &motorRPMTest_B.MovingAverage_p, &motorRPMTest_DW.MovingAverage_p);

  /* Gain: '<S6>/Current to Torque' */
  motorRPMTest_B.CurrenttoTorque = motorRPMTest_P.k_motor *
    motorRPMTest_B.MovingAverage_p.MovingAverage;

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  motorRPMTest_B.CurrenttoTorque = rt_roundd_snf
    (motorRPMTest_P.Constant2_Value_i);
  if (motorRPMTest_B.CurrenttoTorque < 256.0) {
    if (motorRPMTest_B.CurrenttoTorque >= 0.0) {
      tmp_0 = (uint8_T)motorRPMTest_B.CurrenttoTorque;
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
  motorRPMTest_B.CurrenttoTorque = rt_roundd_snf
    (motorRPMTest_P.Constant2_Value_i);
  if (motorRPMTest_B.CurrenttoTorque < 256.0) {
    if (motorRPMTest_B.CurrenttoTorque >= 0.0) {
      tmp_0 = (uint8_T)motorRPMTest_B.CurrenttoTorque;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S5>/Digital Output2' */

  /* Update for Delay: '<S2>/MemoryX' */
  motorRPMTest_DW.icLoad = false;
  motorRPMTest_DW.MemoryX_DSTATE[0] = motorRPMTest_B.rtb_Add_idx_0;
  motorRPMTest_DW.MemoryX_DSTATE[1] = motorRPMTest_B.rtb_Add_idx_1;
  motorRPMTest_DW.MemoryX_DSTATE[2] = motorRPMTest_B.rtb_Add_idx_2;
  motorRPMTest_DW.MemoryX_DSTATE[3] = motorRPMTest_B.rtb_Add_idx_3;

  /* Update for UnitDelay: '<S1>/UD' */
  motorRPMTest_DW.UD_DSTATE = motorRPMTest_B.TSamp;

  /* Update for DiscreteIntegrator: '<S98>/Integrator' incorporates:
   *  Gain: '<S95>/Integral Gain'
   *  Sum: '<S90>/SumI4'
   */
  motorRPMTest_DW.Integrator_DSTATE += (motorRPMTest_P.PIDController_I *
    motorRPMTest_B.e + motorRPMTest_B.theta_cal) *
    motorRPMTest_P.Integrator_gainval;
}

/* Model initialize function */
void motorRPMTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(motorRPMTest_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &motorRPMTest_B), 0,
                sizeof(B_motorRPMTest_T));

  /* states (dwork) */
  (void) memset((void *)&motorRPMTest_DW, 0,
                sizeof(DW_motorRPMTest_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  motorRPMTest_DW.obj_d.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_jr = true;
  motorRPMTest_DW.obj_d.isInitialized = 1L;
  motorRPMTest_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  motorRPMTest_DW.obj_d.isSetupComplete = true;

  /* Start for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  motorRPMTest_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S27>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S34>/Enabled Subsystem' */
  motorRPMTest_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S34>/Enabled Subsystem' */

  /* Start for MATLABSystem: '<S62>/Encoder' */
  motorRPMTest_DW.obj_k.Index = 0U;
  motorRPMTest_DW.obj_k.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_n = true;
  motorRPMTest_DW.obj_k.isSetupComplete = false;
  motorRPMTest_DW.obj_k.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &motorRPMTest_DW.obj_k.Index);
  motorRPMTest_DW.obj_k.isSetupComplete = true;
  motorRPMTest_DW.obj_k.TunablePropsChanged = false;
  motorRPMTes_MovingAverage_Start(&motorRPMTest_DW.MovingAverage);

  /* Start for MATLABSystem: '<S4>/PWM' */
  motorRPMTest_DW.obj_n.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_jg = true;
  motorRPMTest_DW.obj_n.isInitialized = 1L;
  motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  motorRPMTest_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/PWM1' */
  motorRPMTest_DW.obj_j.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_j = true;
  motorRPMTest_DW.obj_j.isInitialized = 1L;
  motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  motorRPMTest_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Analog Input' */
  motorRPMTest_DW.obj_e.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_g = true;
  motorRPMTest_DW.obj_e.isInitialized = 1L;
  motorRPMTest_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  motorRPMTest_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Analog Input1' */
  motorRPMTest_DW.obj.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty = true;
  motorRPMTest_DW.obj.isInitialized = 1L;
  motorRPMTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(16UL);
  motorRPMTest_DW.obj.isSetupComplete = true;
  motorRPMTes_MovingAverage_Start(&motorRPMTest_DW.MovingAverage_p);

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  motorRPMTest_DW.obj_c.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_c = true;
  motorRPMTest_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(7, 1);
  motorRPMTest_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output2' */
  motorRPMTest_DW.obj_k1.matlabCodegenIsDeleted = false;
  motorRPMTest_DW.objisempty_d = true;
  motorRPMTest_DW.obj_k1.isInitialized = 1L;
  digitalIOSetup(8, 1);
  motorRPMTest_DW.obj_k1.isSetupComplete = true;

  /* InitializeConditions for Delay: '<S2>/MemoryX' */
  motorRPMTest_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  motorRPMTest_DW.UD_DSTATE = motorRPMTest_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/Integrator' */
  motorRPMTest_DW.Integrator_DSTATE =
    motorRPMTest_P.PIDController_InitialConditionF;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  motorRPMTest_DW.N = 100.0;
  motorRPMTest_DW.sample_count = 0.0;
  motorRPMTest_DW.theta_sum = 0.0;
  motorRPMTest_DW.theta0 = 0.0;
  motorRPMTest_DW.calibrated = false;

  /* SystemInitialize for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S58>/Product3' incorporates:
   *  Outport: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  motorRPMTest_B.Product3[0] = motorRPMTest_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S27>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S34>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S60>/Product2' incorporates:
   *  Outport: '<S60>/deltax'
   */
  motorRPMTest_B.Product2[0] = motorRPMTest_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S34>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S58>/Product3' incorporates:
   *  Outport: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  motorRPMTest_B.Product3[1] = motorRPMTest_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S27>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S34>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S60>/Product2' incorporates:
   *  Outport: '<S60>/deltax'
   */
  motorRPMTest_B.Product2[1] = motorRPMTest_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S34>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S58>/Product3' incorporates:
   *  Outport: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  motorRPMTest_B.Product3[2] = motorRPMTest_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S27>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S34>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S60>/Product2' incorporates:
   *  Outport: '<S60>/deltax'
   */
  motorRPMTest_B.Product2[2] = motorRPMTest_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S34>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S58>/Product3' incorporates:
   *  Outport: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  motorRPMTest_B.Product3[3] = motorRPMTest_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S27>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S34>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S60>/Product2' incorporates:
   *  Outport: '<S60>/deltax'
   */
  motorRPMTest_B.Product2[3] = motorRPMTest_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S34>/Enabled Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S62>/Filter for data dropouts' */
  motorRPMTest_DW.prevVal_not_empty = false;

  /* InitializeConditions for MATLABSystem: '<S62>/Encoder' */
  MW_EncoderReset(motorRPMTest_DW.obj_k.Index);
  motorRPMTest_MovingAverage_Init(&motorRPMTest_DW.MovingAverage);
  motorRPMTest_MovingAverage_Init(&motorRPMTest_DW.MovingAverage_p);
}

/* Model terminate function */
void motorRPMTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!motorRPMTest_DW.obj_d.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj_d.isInitialized == 1L) &&
        motorRPMTest_DW.obj_d.isSetupComplete) {
      motorRPMTest_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (motorRPMTest_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<S62>/Encoder' */
  if (!motorRPMTest_DW.obj_k.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj_k.isInitialized == 1L) &&
        motorRPMTest_DW.obj_k.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S62>/Encoder' */
  motorRPMTest_MovingAverage_Term(&motorRPMTest_DW.MovingAverage);

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  if (!motorRPMTest_DW.obj_n.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj_n.isInitialized == 1L) &&
        motorRPMTest_DW.obj_n.isSetupComplete) {
      motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(motorRPMTest_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */

  /* Terminate for MATLABSystem: '<S4>/PWM1' */
  if (!motorRPMTest_DW.obj_j.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj_j.isInitialized == 1L) &&
        motorRPMTest_DW.obj_j.isSetupComplete) {
      motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(motorRPMTest_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM1' */

  /* Terminate for MATLABSystem: '<S6>/Analog Input' */
  if (!motorRPMTest_DW.obj_e.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj_e.isInitialized == 1L) &&
        motorRPMTest_DW.obj_e.isSetupComplete) {
      motorRPMTest_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (motorRPMTest_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog Input' */

  /* Terminate for MATLABSystem: '<S6>/Analog Input1' */
  if (!motorRPMTest_DW.obj.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((motorRPMTest_DW.obj.isInitialized == 1L) &&
        motorRPMTest_DW.obj.isSetupComplete) {
      motorRPMTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close(motorRPMTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog Input1' */
  motorRPMTest_MovingAverage_Term(&motorRPMTest_DW.MovingAverage_p);

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!motorRPMTest_DW.obj_c.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output2' */
  if (!motorRPMTest_DW.obj_k1.matlabCodegenIsDeleted) {
    motorRPMTest_DW.obj_k1.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output2' */
}
