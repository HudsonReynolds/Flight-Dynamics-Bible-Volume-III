/*
 * PID_Controller.h
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

#ifndef PID_Controller_h_
#define PID_Controller_h_
#ifndef PID_Controller_COMMON_INCLUDES_
#define PID_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* PID_Controller_COMMON_INCLUDES_ */

#include "PID_Controller_types.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PendulumAngle;                /* '<S1>/Add' */
  real_T TmpMLSysMemLayoutBufferAtMoving;
                    /* '<S1>/TmpMLSysMemLayoutBufferAtMoving AverageOutport1' */
  real_T Saturation;                   /* '<S104>/Saturation' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T MovingAverage;                /* '<S8>/Moving Average' */
  real_T csum;
  real_T z;
  int32_T Encoder;                     /* '<S8>/Encoder' */
} B_PID_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_k_T obj;  /* '<S8>/Moving Average' */
  dsp_simulink_MovingAverage_PI_T obj_i;/* '<S1>/Moving Average' */
  codertarget_arduinobase_inter_T obj_h;/* '<S1>/Analog Input' */
  codertarget_arduinobase_int_k_T obj_e;/* '<S3>/PWM1' */
  codertarget_arduinobase_int_k_T obj_d;/* '<S3>/PWM' */
  codertarget_arduinobase_in_kh_T obj_l;/* '<S8>/Encoder' */
  codertarget_arduinobase_block_T obj_m;/* '<S5>/Digital Output2' */
  codertarget_arduinobase_block_T obj_n;/* '<S5>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T Integrator_DSTATE;            /* '<S97>/Integrator' */
  real_T Filter_DSTATE;                /* '<S92>/Filter' */
  real_T PositionIntegration_DSTATE;   /* '<S3>/Position Integration' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_k;                     /* '<S3>/Scope' */

  int32_T sfEvent;                     /* '<S3>/Select PWM Direction' */
  int32_T sfEvent_e;                   /* '<S8>/Filter for data dropouts' */
  int32_T prevVal;                     /* '<S8>/Filter for data dropouts' */
  boolean_T objisempty;                /* '<S5>/Digital Output2' */
  boolean_T objisempty_j;              /* '<S5>/Digital Output1' */
  boolean_T doneDoubleBufferReInit;    /* '<S3>/Select PWM Direction' */
  boolean_T objisempty_o;              /* '<S8>/Moving Average' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S8>/Filter for data dropouts' */
  boolean_T prevVal_not_empty;         /* '<S8>/Filter for data dropouts' */
  boolean_T objisempty_m;              /* '<S8>/Encoder' */
  boolean_T objisempty_og;             /* '<S3>/PWM1' */
  boolean_T objisempty_f;              /* '<S3>/PWM' */
  boolean_T objisempty_c;              /* '<S1>/Moving Average' */
  boolean_T objisempty_i;              /* '<S1>/Analog Input' */
} DW_PID_Controller_T;

/* Parameters (default storage) */
struct P_PID_Controller_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S90>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S94>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S6>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S92>/Filter'
                               */
  real_T PIDController_InitialConditio_f;
                              /* Mask Parameter: PIDController_InitialConditio_f
                               * Referenced by: '<S97>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S104>/Saturation'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S100>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S102>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S104>/Saturation'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: pi/2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S97>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S92>/Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: .3
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T RPMtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S3>/RPM to rad//s'
                                        */
  real_T radstoms_Gain;                /* Expression: 6.5/1000
                                        * Referenced by: '<S3>/rad//s to m//s'
                                        */
  real_T PositionIntegration_gainval;
                              /* Computed Parameter: PositionIntegration_gainval
                               * Referenced by: '<S3>/Position Integration'
                               */
  real_T PositionIntegration_IC;       /* Expression: 0
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S8>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad_Gain;              /* Computed Parameter: Volt2Rad_Gain
                                        * Referenced by: '<S1>/Volt2Rad'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID_Controller_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_Controller_T PID_Controller_P;

/* Block signals (default storage) */
extern B_PID_Controller_T PID_Controller_B;

/* Block states (default storage) */
extern DW_PID_Controller_T PID_Controller_DW;

/* External function called from main */
extern void PID_Controller_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void PID_Controller_initialize(void);
extern void PID_Controller_step0(void);/* Sample time: [0.01s, 0.0s] */
extern void PID_Controller_step1(void);/* Sample time: [0.02s, 0.0s] */
extern void PID_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_Controller_T *const PID_Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Omega (rad//s)' : Unused code path elimination
 * Block '<S2>/rad//s to rpm' : Unused code path elimination
 * Block '<S3>/Add1' : Unused code path elimination
 * Block '<S36>/Kb' : Unused code path elimination
 * Block '<S36>/SumI2' : Unused code path elimination
 * Block '<S36>/SumI4' : Unused code path elimination
 * Block '<S37>/Derivative Gain' : Unused code path elimination
 * Block '<S39>/Filter' : Unused code path elimination
 * Block '<S39>/SumD' : Unused code path elimination
 * Block '<S41>/Integral Gain' : Unused code path elimination
 * Block '<S44>/Integrator' : Unused code path elimination
 * Block '<S47>/Filter Coefficient' : Unused code path elimination
 * Block '<S49>/Proportional Gain' : Unused code path elimination
 * Block '<S51>/Saturation' : Unused code path elimination
 * Block '<S53>/Sum' : Unused code path elimination
 * Block '<Root>/Velocity (m//s)' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PID_Controller'
 * '<S1>'   : 'PID_Controller/Angle Measurement'
 * '<S2>'   : 'PID_Controller/Lin Vel to RPM'
 * '<S3>'   : 'PID_Controller/Motor Controller'
 * '<S4>'   : 'PID_Controller/PID Controller'
 * '<S5>'   : 'PID_Controller/Pin Setup'
 * '<S6>'   : 'PID_Controller/Angle Measurement/Discrete Derivative'
 * '<S7>'   : 'PID_Controller/Motor Controller/PID Controller'
 * '<S8>'   : 'PID_Controller/Motor Controller/RPM Measurement'
 * '<S9>'   : 'PID_Controller/Motor Controller/Select PWM Direction'
 * '<S10>'  : 'PID_Controller/Motor Controller/PID Controller/Anti-windup'
 * '<S11>'  : 'PID_Controller/Motor Controller/PID Controller/D Gain'
 * '<S12>'  : 'PID_Controller/Motor Controller/PID Controller/External Derivative'
 * '<S13>'  : 'PID_Controller/Motor Controller/PID Controller/Filter'
 * '<S14>'  : 'PID_Controller/Motor Controller/PID Controller/Filter ICs'
 * '<S15>'  : 'PID_Controller/Motor Controller/PID Controller/I Gain'
 * '<S16>'  : 'PID_Controller/Motor Controller/PID Controller/Ideal P Gain'
 * '<S17>'  : 'PID_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'PID_Controller/Motor Controller/PID Controller/Integrator'
 * '<S19>'  : 'PID_Controller/Motor Controller/PID Controller/Integrator ICs'
 * '<S20>'  : 'PID_Controller/Motor Controller/PID Controller/N Copy'
 * '<S21>'  : 'PID_Controller/Motor Controller/PID Controller/N Gain'
 * '<S22>'  : 'PID_Controller/Motor Controller/PID Controller/P Copy'
 * '<S23>'  : 'PID_Controller/Motor Controller/PID Controller/Parallel P Gain'
 * '<S24>'  : 'PID_Controller/Motor Controller/PID Controller/Reset Signal'
 * '<S25>'  : 'PID_Controller/Motor Controller/PID Controller/Saturation'
 * '<S26>'  : 'PID_Controller/Motor Controller/PID Controller/Saturation Fdbk'
 * '<S27>'  : 'PID_Controller/Motor Controller/PID Controller/Sum'
 * '<S28>'  : 'PID_Controller/Motor Controller/PID Controller/Sum Fdbk'
 * '<S29>'  : 'PID_Controller/Motor Controller/PID Controller/Tracking Mode'
 * '<S30>'  : 'PID_Controller/Motor Controller/PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'PID_Controller/Motor Controller/PID Controller/Tsamp - Integral'
 * '<S32>'  : 'PID_Controller/Motor Controller/PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'PID_Controller/Motor Controller/PID Controller/postSat Signal'
 * '<S34>'  : 'PID_Controller/Motor Controller/PID Controller/preInt Signal'
 * '<S35>'  : 'PID_Controller/Motor Controller/PID Controller/preSat Signal'
 * '<S36>'  : 'PID_Controller/Motor Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S37>'  : 'PID_Controller/Motor Controller/PID Controller/D Gain/Internal Parameters'
 * '<S38>'  : 'PID_Controller/Motor Controller/PID Controller/External Derivative/Error'
 * '<S39>'  : 'PID_Controller/Motor Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'PID_Controller/Motor Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'PID_Controller/Motor Controller/PID Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'PID_Controller/Motor Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'PID_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'PID_Controller/Motor Controller/PID Controller/Integrator/Discrete'
 * '<S45>'  : 'PID_Controller/Motor Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'PID_Controller/Motor Controller/PID Controller/N Copy/Disabled'
 * '<S47>'  : 'PID_Controller/Motor Controller/PID Controller/N Gain/Internal Parameters'
 * '<S48>'  : 'PID_Controller/Motor Controller/PID Controller/P Copy/Disabled'
 * '<S49>'  : 'PID_Controller/Motor Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'PID_Controller/Motor Controller/PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'PID_Controller/Motor Controller/PID Controller/Saturation/Enabled'
 * '<S52>'  : 'PID_Controller/Motor Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'PID_Controller/Motor Controller/PID Controller/Sum/Sum_PID'
 * '<S54>'  : 'PID_Controller/Motor Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'PID_Controller/Motor Controller/PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'PID_Controller/Motor Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'PID_Controller/Motor Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'PID_Controller/Motor Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'PID_Controller/Motor Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'PID_Controller/Motor Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S61>'  : 'PID_Controller/Motor Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'PID_Controller/Motor Controller/RPM Measurement/Filter for data dropouts'
 * '<S63>'  : 'PID_Controller/PID Controller/Anti-windup'
 * '<S64>'  : 'PID_Controller/PID Controller/D Gain'
 * '<S65>'  : 'PID_Controller/PID Controller/External Derivative'
 * '<S66>'  : 'PID_Controller/PID Controller/Filter'
 * '<S67>'  : 'PID_Controller/PID Controller/Filter ICs'
 * '<S68>'  : 'PID_Controller/PID Controller/I Gain'
 * '<S69>'  : 'PID_Controller/PID Controller/Ideal P Gain'
 * '<S70>'  : 'PID_Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S71>'  : 'PID_Controller/PID Controller/Integrator'
 * '<S72>'  : 'PID_Controller/PID Controller/Integrator ICs'
 * '<S73>'  : 'PID_Controller/PID Controller/N Copy'
 * '<S74>'  : 'PID_Controller/PID Controller/N Gain'
 * '<S75>'  : 'PID_Controller/PID Controller/P Copy'
 * '<S76>'  : 'PID_Controller/PID Controller/Parallel P Gain'
 * '<S77>'  : 'PID_Controller/PID Controller/Reset Signal'
 * '<S78>'  : 'PID_Controller/PID Controller/Saturation'
 * '<S79>'  : 'PID_Controller/PID Controller/Saturation Fdbk'
 * '<S80>'  : 'PID_Controller/PID Controller/Sum'
 * '<S81>'  : 'PID_Controller/PID Controller/Sum Fdbk'
 * '<S82>'  : 'PID_Controller/PID Controller/Tracking Mode'
 * '<S83>'  : 'PID_Controller/PID Controller/Tracking Mode Sum'
 * '<S84>'  : 'PID_Controller/PID Controller/Tsamp - Integral'
 * '<S85>'  : 'PID_Controller/PID Controller/Tsamp - Ngain'
 * '<S86>'  : 'PID_Controller/PID Controller/postSat Signal'
 * '<S87>'  : 'PID_Controller/PID Controller/preInt Signal'
 * '<S88>'  : 'PID_Controller/PID Controller/preSat Signal'
 * '<S89>'  : 'PID_Controller/PID Controller/Anti-windup/Passthrough'
 * '<S90>'  : 'PID_Controller/PID Controller/D Gain/Internal Parameters'
 * '<S91>'  : 'PID_Controller/PID Controller/External Derivative/Error'
 * '<S92>'  : 'PID_Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S93>'  : 'PID_Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S94>'  : 'PID_Controller/PID Controller/I Gain/Internal Parameters'
 * '<S95>'  : 'PID_Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S96>'  : 'PID_Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S97>'  : 'PID_Controller/PID Controller/Integrator/Discrete'
 * '<S98>'  : 'PID_Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S99>'  : 'PID_Controller/PID Controller/N Copy/Disabled'
 * '<S100>' : 'PID_Controller/PID Controller/N Gain/Internal Parameters'
 * '<S101>' : 'PID_Controller/PID Controller/P Copy/Disabled'
 * '<S102>' : 'PID_Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S103>' : 'PID_Controller/PID Controller/Reset Signal/Disabled'
 * '<S104>' : 'PID_Controller/PID Controller/Saturation/Enabled'
 * '<S105>' : 'PID_Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S106>' : 'PID_Controller/PID Controller/Sum/Sum_PID'
 * '<S107>' : 'PID_Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S108>' : 'PID_Controller/PID Controller/Tracking Mode/Disabled'
 * '<S109>' : 'PID_Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S110>' : 'PID_Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S111>' : 'PID_Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S112>' : 'PID_Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S113>' : 'PID_Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S114>' : 'PID_Controller/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PID_Controller_h_ */
