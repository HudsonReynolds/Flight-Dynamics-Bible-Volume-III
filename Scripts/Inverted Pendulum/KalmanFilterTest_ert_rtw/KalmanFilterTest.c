#include "KalmanFilterTest.h"
#include "rtwtypes.h"
#include "KalmanFilterTest_private.h"
#include <string.h>
#include <math.h>
#define KalmanFilterTest_CALL_EVENT    (-1L)

B_KalmanFilterTest_T KalmanFilterTest_B;
DW_KalmanFilterTest_T KalmanFilterTest_DW;
ExtY_KalmanFilterTest_T KalmanFilterTest_Y;
static RT_MODEL_KalmanFilterTest_T KalmanFilterTest_M_;
RT_MODEL_KalmanFilterTest_T *const KalmanFilterTest_M = &KalmanFilterTest_M_;
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

void KalmanFilterTest_step(void)
{
  real_T MemoryX_DSTATE;
  real_T Product2;
  real_T Product2_0;
  real_T Product2_1;
  real_T Product3;
  real_T rtb_Reshapey_0;
  real_T tmp;
  int16_T i;
  int16_T tmp_1;
  uint16_T b_varargout_1;
  uint8_T tmp_0;
  srClearBC(KalmanFilterTest_DW.MeasurementUpdate_SubsysRanBC);
  srClearBC(KalmanFilterTest_DW.EnabledSubsystem_SubsysRanBC);
  KalmanFilterTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (KalmanFilterTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);
  KalmanFilterTest_B.PendulumAngle = KalmanFilterTest_P.Volt2Rad1_Gain * (real_T)
    b_varargout_1;
  KalmanFilterTest_B.Reshapey[0] = KalmanFilterTest_P.Constant_Value;
  KalmanFilterTest_B.Reshapey[1] = KalmanFilterTest_B.PendulumAngle;
  if (KalmanFilterTest_DW.icLoad) {
    KalmanFilterTest_DW.MemoryX_DSTATE[0] = KalmanFilterTest_P.X0_Value[0];
    KalmanFilterTest_DW.MemoryX_DSTATE[1] = KalmanFilterTest_P.X0_Value[1];
    KalmanFilterTest_DW.MemoryX_DSTATE[2] = KalmanFilterTest_P.X0_Value[2];
    KalmanFilterTest_DW.MemoryX_DSTATE[3] = KalmanFilterTest_P.X0_Value[3];
  }

  if (KalmanFilterTest_P.Enable_Value) {
    KalmanFilterTest_DW.MeasurementUpdate_MODE = true;
    KalmanFilterTest_B.unnamed_idx_0 = 0.0;
    tmp = 0.0;
    for (i = 0; i < 4; i++) {
      MemoryX_DSTATE = KalmanFilterTest_DW.MemoryX_DSTATE[i];
      tmp_1 = i << 1;
      KalmanFilterTest_B.unnamed_idx_0 += KalmanFilterTest_P.C_Value[tmp_1] *
        MemoryX_DSTATE;
      tmp += KalmanFilterTest_P.C_Value[tmp_1 + 1] * MemoryX_DSTATE;
    }

    KalmanFilterTest_B.rtb_Reshapey_m[0] = KalmanFilterTest_P.Constant_Value -
      (KalmanFilterTest_P.D_Value[0] * KalmanFilterTest_P.Constant_Value +
       KalmanFilterTest_B.unnamed_idx_0);
    KalmanFilterTest_B.rtb_Reshapey_m[1] = KalmanFilterTest_B.PendulumAngle -
      (KalmanFilterTest_P.D_Value[1] * KalmanFilterTest_P.Constant_Value + tmp);
    KalmanFilterTest_B.unnamed_idx_0 = 0.0;
    tmp = 0.0;
    KalmanFilterTest_B.TSamp = 0.0;
    Product3 = 0.0;
    for (i = 0; i < 2; i++) {
      MemoryX_DSTATE = KalmanFilterTest_B.rtb_Reshapey_m[i];
      tmp_1 = i << 2;
      KalmanFilterTest_B.unnamed_idx_0 +=
        KalmanFilterTest_P.KalmanGainL_Value[tmp_1] * MemoryX_DSTATE;
      tmp += KalmanFilterTest_P.KalmanGainL_Value[tmp_1 + 1] * MemoryX_DSTATE;
      KalmanFilterTest_B.TSamp += KalmanFilterTest_P.KalmanGainL_Value[tmp_1 + 2]
        * MemoryX_DSTATE;
      Product3 += KalmanFilterTest_P.KalmanGainL_Value[tmp_1 + 3] *
        MemoryX_DSTATE;
    }

    KalmanFilterTest_B.Product3[3] = Product3;
    KalmanFilterTest_B.Product3[2] = KalmanFilterTest_B.TSamp;
    KalmanFilterTest_B.Product3[1] = tmp;
    KalmanFilterTest_B.Product3[0] = KalmanFilterTest_B.unnamed_idx_0;
    srUpdateBC(KalmanFilterTest_DW.MeasurementUpdate_SubsysRanBC);
    KalmanFilterTest_DW.EnabledSubsystem_MODE = true;
    MemoryX_DSTATE = KalmanFilterTest_DW.MemoryX_DSTATE[1];
    KalmanFilterTest_B.unnamed_idx_0 = KalmanFilterTest_DW.MemoryX_DSTATE[0];
    tmp = KalmanFilterTest_DW.MemoryX_DSTATE[2];
    KalmanFilterTest_B.TSamp = KalmanFilterTest_DW.MemoryX_DSTATE[3];
    Product3 = 0.0;
    Product2 = 0.0;
    Product2_0 = 0.0;
    Product2_1 = 0.0;
    for (i = 0; i < 2; i++) {
      rtb_Reshapey_0 = KalmanFilterTest_B.Reshapey[i] -
        (((KalmanFilterTest_P.C_Value[i + 2] * MemoryX_DSTATE +
           KalmanFilterTest_P.C_Value[i] * KalmanFilterTest_B.unnamed_idx_0) +
          KalmanFilterTest_P.C_Value[i + 4] * tmp) +
         KalmanFilterTest_P.C_Value[i + 6] * KalmanFilterTest_B.TSamp);
      tmp_1 = i << 2;
      Product3 += KalmanFilterTest_P.KalmanGainM_Value[tmp_1] * rtb_Reshapey_0;
      Product2 += KalmanFilterTest_P.KalmanGainM_Value[tmp_1 + 1] *
        rtb_Reshapey_0;
      Product2_0 += KalmanFilterTest_P.KalmanGainM_Value[tmp_1 + 2] *
        rtb_Reshapey_0;
      Product2_1 += KalmanFilterTest_P.KalmanGainM_Value[tmp_1 + 3] *
        rtb_Reshapey_0;
    }

    KalmanFilterTest_B.Product2[3] = Product2_1;
    KalmanFilterTest_B.Product2[2] = Product2_0;
    KalmanFilterTest_B.Product2[1] = Product2;
    KalmanFilterTest_B.Product2[0] = Product3;
    srUpdateBC(KalmanFilterTest_DW.EnabledSubsystem_SubsysRanBC);
  } else {
    if (KalmanFilterTest_DW.MeasurementUpdate_MODE) {
      KalmanFilterTest_B.Product3[0] = KalmanFilterTest_P.Lykyhatkk1_Y0;
      KalmanFilterTest_B.Product3[1] = KalmanFilterTest_P.Lykyhatkk1_Y0;
      KalmanFilterTest_B.Product3[2] = KalmanFilterTest_P.Lykyhatkk1_Y0;
      KalmanFilterTest_B.Product3[3] = KalmanFilterTest_P.Lykyhatkk1_Y0;
      KalmanFilterTest_DW.MeasurementUpdate_MODE = false;
    }

    if (KalmanFilterTest_DW.EnabledSubsystem_MODE) {
      KalmanFilterTest_B.Product2[0] = KalmanFilterTest_P.deltax_Y0;
      KalmanFilterTest_B.Product2[1] = KalmanFilterTest_P.deltax_Y0;
      KalmanFilterTest_B.Product2[2] = KalmanFilterTest_P.deltax_Y0;
      KalmanFilterTest_B.Product2[3] = KalmanFilterTest_P.deltax_Y0;
      KalmanFilterTest_DW.EnabledSubsystem_MODE = false;
    }
  }

  KalmanFilterTest_B.Reshapexhat[0] = KalmanFilterTest_B.Product2[0] +
    KalmanFilterTest_DW.MemoryX_DSTATE[0];
  KalmanFilterTest_B.Reshapexhat[1] = KalmanFilterTest_B.Product2[1] +
    KalmanFilterTest_DW.MemoryX_DSTATE[1];
  KalmanFilterTest_B.Reshapexhat[2] = KalmanFilterTest_B.Product2[2] +
    KalmanFilterTest_DW.MemoryX_DSTATE[2];
  KalmanFilterTest_B.Reshapexhat[3] = KalmanFilterTest_B.Product2[3] +
    KalmanFilterTest_DW.MemoryX_DSTATE[3];
  KalmanFilterTest_Y.Thetarad = KalmanFilterTest_B.PendulumAngle;
  KalmanFilterTest_B.TSamp = KalmanFilterTest_B.PendulumAngle *
    KalmanFilterTest_P.TSamp_WtEt;
  KalmanFilterTest_B.Diff = KalmanFilterTest_B.TSamp -
    KalmanFilterTest_DW.UD_DSTATE;
  KalmanFilterTest_Y.Theta_dotrads = KalmanFilterTest_B.Diff;
  KalmanFilterTest_DW.sfEvent = KalmanFilterTest_CALL_EVENT;
  MemoryX_DSTATE = rt_roundd_snf(KalmanFilterTest_P.Constant2_Value);
  if (MemoryX_DSTATE < 256.0) {
    if (MemoryX_DSTATE >= 0.0) {
      tmp_0 = (uint8_T)MemoryX_DSTATE;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);
  if (MemoryX_DSTATE < 256.0) {
    if (MemoryX_DSTATE >= 0.0) {
      tmp_0 = (uint8_T)MemoryX_DSTATE;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);
  KalmanFilterTest_DW.icLoad = false;
  KalmanFilterTest_B.unnamed_idx_0 = 0.0;
  tmp = 0.0;
  Product3 = 0.0;
  Product2 = 0.0;
  for (i = 0; i < 4; i++) {
    MemoryX_DSTATE = KalmanFilterTest_DW.MemoryX_DSTATE[i];
    tmp_1 = i << 2;
    KalmanFilterTest_B.unnamed_idx_0 += KalmanFilterTest_P.A_Value[tmp_1] *
      MemoryX_DSTATE;
    tmp += KalmanFilterTest_P.A_Value[tmp_1 + 1] * MemoryX_DSTATE;
    Product3 += KalmanFilterTest_P.A_Value[tmp_1 + 2] * MemoryX_DSTATE;
    Product2 += KalmanFilterTest_P.A_Value[tmp_1 + 3] * MemoryX_DSTATE;
  }

  KalmanFilterTest_DW.MemoryX_DSTATE[0] = (KalmanFilterTest_P.B_Value[0] *
    KalmanFilterTest_P.Constant_Value + KalmanFilterTest_B.unnamed_idx_0) +
    KalmanFilterTest_B.Product3[0];
  KalmanFilterTest_DW.MemoryX_DSTATE[1] = (KalmanFilterTest_P.B_Value[1] *
    KalmanFilterTest_P.Constant_Value + tmp) + KalmanFilterTest_B.Product3[1];
  KalmanFilterTest_DW.MemoryX_DSTATE[2] = (KalmanFilterTest_P.B_Value[2] *
    KalmanFilterTest_P.Constant_Value + Product3) + KalmanFilterTest_B.Product3
    [2];
  KalmanFilterTest_DW.MemoryX_DSTATE[3] = (KalmanFilterTest_P.B_Value[3] *
    KalmanFilterTest_P.Constant_Value + Product2) + KalmanFilterTest_B.Product3
    [3];
  KalmanFilterTest_DW.UD_DSTATE = KalmanFilterTest_B.TSamp;
  KalmanFilterTest_M->Timing.clockTick0++;
  if (!KalmanFilterTest_M->Timing.clockTick0) {
    KalmanFilterTest_M->Timing.clockTickH0++;
  }
}

void KalmanFilterTest_initialize(void)
{
  (void) memset((void *)KalmanFilterTest_M, 0,
                sizeof(RT_MODEL_KalmanFilterTest_T));
  rtmSetTFinal(KalmanFilterTest_M, -1);
  KalmanFilterTest_M->Sizes.checksums[0] = (2283224492U);
  KalmanFilterTest_M->Sizes.checksums[1] = (2242423486U);
  KalmanFilterTest_M->Sizes.checksums[2] = (2533186717U);
  KalmanFilterTest_M->Sizes.checksums[3] = (181721983U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    KalmanFilterTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &KalmanFilterTest_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &KalmanFilterTest_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(KalmanFilterTest_M->extModeInfo,
      &KalmanFilterTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(KalmanFilterTest_M->extModeInfo,
                        KalmanFilterTest_M->Sizes.checksums);
    rteiSetTFinalTicks(KalmanFilterTest_M->extModeInfo, -1);
  }

  (void) memset(((void *) &KalmanFilterTest_B), 0,
                sizeof(B_KalmanFilterTest_T));
  (void) memset((void *)&KalmanFilterTest_DW, 0,
                sizeof(DW_KalmanFilterTest_T));
  (void)memset(&KalmanFilterTest_Y, 0, sizeof(ExtY_KalmanFilterTest_T));
  KalmanFilterTest_DW.obj.matlabCodegenIsDeleted = false;
  KalmanFilterTest_DW.objisempty_n = true;
  KalmanFilterTest_DW.obj.isInitialized = 1L;
  KalmanFilterTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  KalmanFilterTest_DW.obj.isSetupComplete = true;
  KalmanFilterTest_DW.MeasurementUpdate_MODE = false;
  KalmanFilterTest_DW.EnabledSubsystem_MODE = false;
  KalmanFilterTest_DW.obj_m.matlabCodegenIsDeleted = false;
  KalmanFilterTest_DW.objisempty_d = true;
  KalmanFilterTest_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(7, 1);
  KalmanFilterTest_DW.obj_m.isSetupComplete = true;
  KalmanFilterTest_DW.obj_i.matlabCodegenIsDeleted = false;
  KalmanFilterTest_DW.objisempty = true;
  KalmanFilterTest_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(8, 1);
  KalmanFilterTest_DW.obj_i.isSetupComplete = true;
  KalmanFilterTest_DW.icLoad = true;
  KalmanFilterTest_DW.UD_DSTATE =
    KalmanFilterTest_P.DiscreteDerivative1_ICPrevScale;
  KalmanFilterTest_B.Product3[0] = KalmanFilterTest_P.Lykyhatkk1_Y0;
  KalmanFilterTest_B.Product2[0] = KalmanFilterTest_P.deltax_Y0;
  KalmanFilterTest_B.Product3[1] = KalmanFilterTest_P.Lykyhatkk1_Y0;
  KalmanFilterTest_B.Product2[1] = KalmanFilterTest_P.deltax_Y0;
  KalmanFilterTest_B.Product3[2] = KalmanFilterTest_P.Lykyhatkk1_Y0;
  KalmanFilterTest_B.Product2[2] = KalmanFilterTest_P.deltax_Y0;
  KalmanFilterTest_B.Product3[3] = KalmanFilterTest_P.Lykyhatkk1_Y0;
  KalmanFilterTest_B.Product2[3] = KalmanFilterTest_P.deltax_Y0;
  KalmanFilterTest_DW.sfEvent = KalmanFilterTest_CALL_EVENT;
}

void KalmanFilterTest_terminate(void)
{
  if (!KalmanFilterTest_DW.obj.matlabCodegenIsDeleted) {
    KalmanFilterTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((KalmanFilterTest_DW.obj.isInitialized == 1L) &&
        KalmanFilterTest_DW.obj.isSetupComplete) {
      KalmanFilterTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (KalmanFilterTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  if (!KalmanFilterTest_DW.obj_m.matlabCodegenIsDeleted) {
    KalmanFilterTest_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  if (!KalmanFilterTest_DW.obj_i.matlabCodegenIsDeleted) {
    KalmanFilterTest_DW.obj_i.matlabCodegenIsDeleted = true;
  }
}
