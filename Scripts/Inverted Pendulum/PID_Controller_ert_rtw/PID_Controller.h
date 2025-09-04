/*
 * PID_Controller.h
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
  real_T Saturation;                   /* '<S51>/Saturation' */
  real_T Abs;                          /* '<Root>/Abs' */
  int32_T Encoder;                     /* '<S7>/Encoder' */
} B_PID_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_k_T obj;  /* '<S7>/Moving Average' */
  dsp_simulink_MovingAverage_PI_T obj_i;/* '<S1>/Moving Average1' */
  codertarget_arduinobase_inter_T obj_j;/* '<S1>/Analog Input1' */
  codertarget_arduinobase_int_k_T obj_c;/* '<S2>/PWM1' */
  codertarget_arduinobase_int_k_T obj_o;/* '<S2>/PWM' */
  codertarget_arduinobase_in_kh_T obj_a;/* '<S7>/Encoder' */
  codertarget_arduinobase_block_T obj_h;/* '<S4>/Digital Output2' */
  codertarget_arduinobase_block_T obj_b;/* '<S4>/Digital Output1' */
  real_T LowPassFilter_states;         /* '<S1>/Low Pass Filter' */
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T sample_count;                 /* '<S1>/MATLAB Function1' */
  real_T theta_sum;                    /* '<S1>/MATLAB Function1' */
  real_T theta0;                       /* '<S1>/MATLAB Function1' */
  real_T N;                            /* '<S1>/MATLAB Function1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S7>/Scope' */

  int32_T sfEvent;                     /* '<S2>/Select PWM Direction' */
  int32_T sfEvent_k;                   /* '<S7>/Filter for data dropouts' */
  int32_T prevVal;                     /* '<S7>/Filter for data dropouts' */
  int32_T sfEvent_m;                   /* '<S1>/MATLAB Function1' */
  boolean_T objisempty;                /* '<S4>/Digital Output2' */
  boolean_T objisempty_a;              /* '<S4>/Digital Output1' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/Select PWM Direction' */
  boolean_T objisempty_f;              /* '<S7>/Moving Average' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S7>/Filter for data dropouts' */
  boolean_T prevVal_not_empty;         /* '<S7>/Filter for data dropouts' */
  boolean_T objisempty_g;              /* '<S7>/Encoder' */
  boolean_T objisempty_c;              /* '<S2>/PWM1' */
  boolean_T objisempty_n;              /* '<S2>/PWM' */
  boolean_T objisempty_k;              /* '<S1>/Moving Average1' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S1>/MATLAB Function1' */
  boolean_T sample_count_not_empty;    /* '<S1>/MATLAB Function1' */
  boolean_T theta_sum_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T theta0_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T calibrated;                /* '<S1>/MATLAB Function1' */
  boolean_T calibrated_not_empty;      /* '<S1>/MATLAB Function1' */
  boolean_T N_not_empty;               /* '<S1>/MATLAB Function1' */
  boolean_T objisempty_ay;             /* '<S1>/Analog Input1' */
} DW_PID_Controller_T;

/* Parameters (default storage) */
struct P_PID_Controller_T_ {
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S37>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S41>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S39>/Filter'
                               */
  real_T PIDController1_InitialConditi_d;
                              /* Mask Parameter: PIDController1_InitialConditi_d
                               * Referenced by: '<S44>/Integrator'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S51>/Saturation'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S47>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S49>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S51>/Saturation'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T LowPassFilter_NumCoef[2];     /* Expression: [0.1358 0.1358]
                                        * Referenced by: '<S1>/Low Pass Filter'
                                        */
  real_T LowPassFilter_DenCoef[2];     /* Expression: [1 -0.7285]
                                        * Referenced by: '<S1>/Low Pass Filter'
                                        */
  real_T LowPassFilter_InitialStates;  /* Expression: 0
                                        * Referenced by: '<S1>/Low Pass Filter'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S44>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S39>/Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: .3
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S7>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad1_Gain;             /* Computed Parameter: Volt2Rad1_Gain
                                        * Referenced by: '<S1>/Volt2Rad1'
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
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Diff' : Unused code path elimination
 * Block '<S5>/TSamp' : Unused code path elimination
 * Block '<S5>/UD' : Unused code path elimination
 * Block '<S2>/Position Integration' : Unused code path elimination
 * Block '<S2>/RPM to rad//s' : Unused code path elimination
 * Block '<S2>/rad//s to m//s' : Unused code path elimination
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
 * '<S2>'   : 'PID_Controller/Motor Controller'
 * '<S3>'   : 'PID_Controller/PID Controller1'
 * '<S4>'   : 'PID_Controller/Pin Setup'
 * '<S5>'   : 'PID_Controller/Angle Measurement/Discrete Derivative1'
 * '<S6>'   : 'PID_Controller/Angle Measurement/MATLAB Function1'
 * '<S7>'   : 'PID_Controller/Motor Controller/RPM Measurement'
 * '<S8>'   : 'PID_Controller/Motor Controller/Select PWM Direction'
 * '<S9>'   : 'PID_Controller/Motor Controller/RPM Measurement/Filter for data dropouts'
 * '<S10>'  : 'PID_Controller/PID Controller1/Anti-windup'
 * '<S11>'  : 'PID_Controller/PID Controller1/D Gain'
 * '<S12>'  : 'PID_Controller/PID Controller1/External Derivative'
 * '<S13>'  : 'PID_Controller/PID Controller1/Filter'
 * '<S14>'  : 'PID_Controller/PID Controller1/Filter ICs'
 * '<S15>'  : 'PID_Controller/PID Controller1/I Gain'
 * '<S16>'  : 'PID_Controller/PID Controller1/Ideal P Gain'
 * '<S17>'  : 'PID_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S18>'  : 'PID_Controller/PID Controller1/Integrator'
 * '<S19>'  : 'PID_Controller/PID Controller1/Integrator ICs'
 * '<S20>'  : 'PID_Controller/PID Controller1/N Copy'
 * '<S21>'  : 'PID_Controller/PID Controller1/N Gain'
 * '<S22>'  : 'PID_Controller/PID Controller1/P Copy'
 * '<S23>'  : 'PID_Controller/PID Controller1/Parallel P Gain'
 * '<S24>'  : 'PID_Controller/PID Controller1/Reset Signal'
 * '<S25>'  : 'PID_Controller/PID Controller1/Saturation'
 * '<S26>'  : 'PID_Controller/PID Controller1/Saturation Fdbk'
 * '<S27>'  : 'PID_Controller/PID Controller1/Sum'
 * '<S28>'  : 'PID_Controller/PID Controller1/Sum Fdbk'
 * '<S29>'  : 'PID_Controller/PID Controller1/Tracking Mode'
 * '<S30>'  : 'PID_Controller/PID Controller1/Tracking Mode Sum'
 * '<S31>'  : 'PID_Controller/PID Controller1/Tsamp - Integral'
 * '<S32>'  : 'PID_Controller/PID Controller1/Tsamp - Ngain'
 * '<S33>'  : 'PID_Controller/PID Controller1/postSat Signal'
 * '<S34>'  : 'PID_Controller/PID Controller1/preInt Signal'
 * '<S35>'  : 'PID_Controller/PID Controller1/preSat Signal'
 * '<S36>'  : 'PID_Controller/PID Controller1/Anti-windup/Passthrough'
 * '<S37>'  : 'PID_Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S38>'  : 'PID_Controller/PID Controller1/External Derivative/Error'
 * '<S39>'  : 'PID_Controller/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'PID_Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'PID_Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S42>'  : 'PID_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S43>'  : 'PID_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'PID_Controller/PID Controller1/Integrator/Discrete'
 * '<S45>'  : 'PID_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S46>'  : 'PID_Controller/PID Controller1/N Copy/Disabled'
 * '<S47>'  : 'PID_Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S48>'  : 'PID_Controller/PID Controller1/P Copy/Disabled'
 * '<S49>'  : 'PID_Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'PID_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S51>'  : 'PID_Controller/PID Controller1/Saturation/Enabled'
 * '<S52>'  : 'PID_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S53>'  : 'PID_Controller/PID Controller1/Sum/Sum_PID'
 * '<S54>'  : 'PID_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S55>'  : 'PID_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S56>'  : 'PID_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'PID_Controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'PID_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'PID_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S60>'  : 'PID_Controller/PID Controller1/preInt Signal/Internal PreInt'
 * '<S61>'  : 'PID_Controller/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* PID_Controller_h_ */
