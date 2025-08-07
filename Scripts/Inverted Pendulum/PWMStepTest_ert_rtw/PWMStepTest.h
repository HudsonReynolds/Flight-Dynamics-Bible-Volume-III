/*
 * PWMStepTest.h
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

#ifndef PWMStepTest_h_
#define PWMStepTest_h_
#ifndef PWMStepTest_COMMON_INCLUDES_
#define PWMStepTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* PWMStepTest_COMMON_INCLUDES_ */

#include "PWMStepTest_types.h"
#include <math.h>
#include <string.h>
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
  real_T radstoms;                     /* '<S3>/rad//s to m//s' */
  real_T PendulumAngle;                /* '<S1>/Add' */
  real_T TmpMLSysMemLayoutBufferAtMoving;
                    /* '<S1>/TmpMLSysMemLayoutBufferAtMoving AverageOutport1' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T MovingAverage;                /* '<S7>/Moving Average' */
  int32_T Encoder;                     /* '<S7>/Encoder' */
} B_PWMStepTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_k_T obj;  /* '<S7>/Moving Average' */
  dsp_simulink_MovingAverage_PW_T obj_i;/* '<S1>/Moving Average' */
  codertarget_arduinobase_inter_T obj_h;/* '<S1>/Analog Input' */
  codertarget_arduinobase_int_k_T obj_e;/* '<S3>/PWM1' */
  codertarget_arduinobase_int_k_T obj_d;/* '<S3>/PWM' */
  codertarget_arduinobase_in_kj_T obj_l;/* '<S7>/Encoder' */
  codertarget_arduinobase_block_T obj_m;/* '<S4>/Digital Output2' */
  codertarget_arduinobase_block_T obj_n;/* '<S4>/Digital Output1' */
  real_T PositionIntegration_DSTATE;   /* '<S3>/Position Integration' */
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_k;                     /* '<S3>/Scope' */

  int32_T sfEvent;                     /* '<S3>/Select PWM Direction' */
  int32_T sfEvent_e;                   /* '<S7>/Filter for data dropouts' */
  int32_T prevVal;                     /* '<S7>/Filter for data dropouts' */
  boolean_T objisempty;                /* '<S4>/Digital Output2' */
  boolean_T objisempty_j;              /* '<S4>/Digital Output1' */
  boolean_T doneDoubleBufferReInit;    /* '<S3>/Select PWM Direction' */
  boolean_T objisempty_o;              /* '<S7>/Moving Average' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S7>/Filter for data dropouts' */
  boolean_T prevVal_not_empty;         /* '<S7>/Filter for data dropouts' */
  boolean_T objisempty_m;              /* '<S7>/Encoder' */
  boolean_T objisempty_og;             /* '<S3>/PWM1' */
  boolean_T objisempty_f;              /* '<S3>/PWM' */
  boolean_T objisempty_c;              /* '<S1>/Moving Average' */
  boolean_T objisempty_i;              /* '<S1>/Analog Input' */
} DW_PWMStepTest_T;

/* Parameters (default storage) */
struct P_PWMStepTest_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S5>/UD'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T PositionIntegration_gainval;
                              /* Computed Parameter: PositionIntegration_gainval
                               * Referenced by: '<S3>/Position Integration'
                               */
  real_T PositionIntegration_IC;       /* Expression: 0
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T RPMtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S3>/RPM to rad//s'
                                        */
  real_T radstoms_Gain;                /* Expression: 6.5/1000
                                        * Referenced by: '<S3>/rad//s to m//s'
                                        */
  real_T Constant_Value;               /* Expression: pi/2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant3_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T Switch_Threshold;             /* Expression: .4
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.150750343959146
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S7>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad_Gain;              /* Computed Parameter: Volt2Rad_Gain
                                        * Referenced by: '<S1>/Volt2Rad'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWMStepTest_T {
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
extern P_PWMStepTest_T PWMStepTest_P;

/* Block signals (default storage) */
extern B_PWMStepTest_T PWMStepTest_B;

/* Block states (default storage) */
extern DW_PWMStepTest_T PWMStepTest_DW;

/* External function called from main */
extern void PWMStepTest_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void PWMStepTest_initialize(void);
extern void PWMStepTest_step0(void);   /* Sample time: [0.01s, 0.0s] */
extern void PWMStepTest_step1(void);   /* Sample time: [0.02s, 0.0s] */
extern void PWMStepTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWMStepTest_T *const PWMStepTest_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Omega (rad//s)' : Unused code path elimination
 * Block '<S2>/rad//s to rpm' : Unused code path elimination
 * Block '<S3>/Add1' : Unused code path elimination
 * Block '<S35>/Kb' : Unused code path elimination
 * Block '<S35>/SumI2' : Unused code path elimination
 * Block '<S35>/SumI4' : Unused code path elimination
 * Block '<S36>/Derivative Gain' : Unused code path elimination
 * Block '<S38>/Filter' : Unused code path elimination
 * Block '<S38>/SumD' : Unused code path elimination
 * Block '<S40>/Integral Gain' : Unused code path elimination
 * Block '<S43>/Integrator' : Unused code path elimination
 * Block '<S46>/Filter Coefficient' : Unused code path elimination
 * Block '<S48>/Proportional Gain' : Unused code path elimination
 * Block '<S50>/Saturation' : Unused code path elimination
 * Block '<S52>/Sum' : Unused code path elimination
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
 * '<Root>' : 'PWMStepTest'
 * '<S1>'   : 'PWMStepTest/Angle Measurement'
 * '<S2>'   : 'PWMStepTest/Lin Vel to RPM'
 * '<S3>'   : 'PWMStepTest/Motor Controller'
 * '<S4>'   : 'PWMStepTest/Pin Setup'
 * '<S5>'   : 'PWMStepTest/Angle Measurement/Discrete Derivative'
 * '<S6>'   : 'PWMStepTest/Motor Controller/PID Controller'
 * '<S7>'   : 'PWMStepTest/Motor Controller/RPM Measurement'
 * '<S8>'   : 'PWMStepTest/Motor Controller/Select PWM Direction'
 * '<S9>'   : 'PWMStepTest/Motor Controller/PID Controller/Anti-windup'
 * '<S10>'  : 'PWMStepTest/Motor Controller/PID Controller/D Gain'
 * '<S11>'  : 'PWMStepTest/Motor Controller/PID Controller/External Derivative'
 * '<S12>'  : 'PWMStepTest/Motor Controller/PID Controller/Filter'
 * '<S13>'  : 'PWMStepTest/Motor Controller/PID Controller/Filter ICs'
 * '<S14>'  : 'PWMStepTest/Motor Controller/PID Controller/I Gain'
 * '<S15>'  : 'PWMStepTest/Motor Controller/PID Controller/Ideal P Gain'
 * '<S16>'  : 'PWMStepTest/Motor Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'PWMStepTest/Motor Controller/PID Controller/Integrator'
 * '<S18>'  : 'PWMStepTest/Motor Controller/PID Controller/Integrator ICs'
 * '<S19>'  : 'PWMStepTest/Motor Controller/PID Controller/N Copy'
 * '<S20>'  : 'PWMStepTest/Motor Controller/PID Controller/N Gain'
 * '<S21>'  : 'PWMStepTest/Motor Controller/PID Controller/P Copy'
 * '<S22>'  : 'PWMStepTest/Motor Controller/PID Controller/Parallel P Gain'
 * '<S23>'  : 'PWMStepTest/Motor Controller/PID Controller/Reset Signal'
 * '<S24>'  : 'PWMStepTest/Motor Controller/PID Controller/Saturation'
 * '<S25>'  : 'PWMStepTest/Motor Controller/PID Controller/Saturation Fdbk'
 * '<S26>'  : 'PWMStepTest/Motor Controller/PID Controller/Sum'
 * '<S27>'  : 'PWMStepTest/Motor Controller/PID Controller/Sum Fdbk'
 * '<S28>'  : 'PWMStepTest/Motor Controller/PID Controller/Tracking Mode'
 * '<S29>'  : 'PWMStepTest/Motor Controller/PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'PWMStepTest/Motor Controller/PID Controller/Tsamp - Integral'
 * '<S31>'  : 'PWMStepTest/Motor Controller/PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'PWMStepTest/Motor Controller/PID Controller/postSat Signal'
 * '<S33>'  : 'PWMStepTest/Motor Controller/PID Controller/preInt Signal'
 * '<S34>'  : 'PWMStepTest/Motor Controller/PID Controller/preSat Signal'
 * '<S35>'  : 'PWMStepTest/Motor Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S36>'  : 'PWMStepTest/Motor Controller/PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'PWMStepTest/Motor Controller/PID Controller/External Derivative/Error'
 * '<S38>'  : 'PWMStepTest/Motor Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'PWMStepTest/Motor Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'PWMStepTest/Motor Controller/PID Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'PWMStepTest/Motor Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'PWMStepTest/Motor Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'PWMStepTest/Motor Controller/PID Controller/Integrator/Discrete'
 * '<S44>'  : 'PWMStepTest/Motor Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'PWMStepTest/Motor Controller/PID Controller/N Copy/Disabled'
 * '<S46>'  : 'PWMStepTest/Motor Controller/PID Controller/N Gain/Internal Parameters'
 * '<S47>'  : 'PWMStepTest/Motor Controller/PID Controller/P Copy/Disabled'
 * '<S48>'  : 'PWMStepTest/Motor Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'PWMStepTest/Motor Controller/PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'PWMStepTest/Motor Controller/PID Controller/Saturation/Enabled'
 * '<S51>'  : 'PWMStepTest/Motor Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'PWMStepTest/Motor Controller/PID Controller/Sum/Sum_PID'
 * '<S53>'  : 'PWMStepTest/Motor Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'PWMStepTest/Motor Controller/PID Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'PWMStepTest/Motor Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'PWMStepTest/Motor Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'PWMStepTest/Motor Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'PWMStepTest/Motor Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S59>'  : 'PWMStepTest/Motor Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S60>'  : 'PWMStepTest/Motor Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'PWMStepTest/Motor Controller/RPM Measurement/Filter for data dropouts'
 */
#endif                                 /* PWMStepTest_h_ */
