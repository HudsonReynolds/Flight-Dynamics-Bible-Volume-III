#ifndef KalmanFilterTest_h_
#define KalmanFilterTest_h_
#ifndef KalmanFilterTest_COMMON_INCLUDES_
#define KalmanFilterTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif

#include "KalmanFilterTest_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

typedef struct {
  real_T PendulumAngle;
  real_T Reshapexhat[4];
  real_T Diff;
  real_T Product2[4];
  real_T Product3[4];
  real_T Reshapey[2];
  real_T rtb_Reshapey_m[2];
  real_T TSamp;
  real_T unnamed_idx_0;
} B_KalmanFilterTest_T;

typedef struct {
  codertarget_arduinobase_inter_T obj;
  codertarget_arduinobase_block_T obj_i;
  codertarget_arduinobase_block_T obj_m;
  real_T MemoryX_DSTATE[4];
  real_T UD_DSTATE;
  struct {
    void *LoggedData;
  } Scope_PWORK;

  int32_T sfEvent;
  int8_T EnabledSubsystem_SubsysRanBC;
  int8_T MeasurementUpdate_SubsysRanBC;
  boolean_T icLoad;
  boolean_T objisempty;
  boolean_T objisempty_d;
  boolean_T doneDoubleBufferReInit;
  boolean_T objisempty_n;
  boolean_T EnabledSubsystem_MODE;
  boolean_T MeasurementUpdate_MODE;
} DW_KalmanFilterTest_T;

typedef struct {
  real_T Thetarad;
  real_T Theta_dotrads;
} ExtY_KalmanFilterTest_T;

struct P_KalmanFilterTest_T_ {
  real_T DiscreteDerivative1_ICPrevScale;
  real_T Lykyhatkk1_Y0;
  real_T deltax_Y0;
  real_T A_Value[16];
  real_T KalmanGainM_Value[8];
  real_T C_Value[8];
  real_T KalmanGainL_Value[8];
  real_T Constant_Value;
  real_T Volt2Rad1_Gain;
  real_T D_Value[2];
  real_T X0_Value[4];
  real_T B_Value[4];
  real_T TSamp_WtEt;
  real_T CovarianceZ_Value[16];
  real_T Constant2_Value;
  boolean_T Enable_Value;
  boolean_T isSqrtUsed_Value;
};

struct tag_RTM_KalmanFilterTest_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  struct {
    uint32_T checksums[4];
  } Sizes;

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

extern P_KalmanFilterTest_T KalmanFilterTest_P;
extern B_KalmanFilterTest_T KalmanFilterTest_B;
extern DW_KalmanFilterTest_T KalmanFilterTest_DW;
extern ExtY_KalmanFilterTest_T KalmanFilterTest_Y;
extern void KalmanFilterTest_initialize(void);
extern void KalmanFilterTest_step(void);
extern void KalmanFilterTest_terminate(void);
extern RT_MODEL_KalmanFilterTest_T *const KalmanFilterTest_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#endif
