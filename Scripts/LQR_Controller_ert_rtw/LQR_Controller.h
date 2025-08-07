/*
 * LQR_Controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Thu Jul 31 20:20:50 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LQR_Controller_h_
#define LQR_Controller_h_
#ifndef LQR_Controller_COMMON_INCLUDES_
#define LQR_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* LQR_Controller_COMMON_INCLUDES_ */

#include "LQR_Controller_types.h"
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
  real_T Diff;                         /* '<S5>/Diff' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T StateVector[4];               /* '<Root>/State Vector' */
  real_T LQRGains;                     /* '<Root>/LQR Gains' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T MovingAverage;                /* '<S7>/Moving Average' */
  int32_T Encoder;                     /* '<S7>/Encoder' */
} B_LQR_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_LQ_T obj; /* '<S7>/Moving Average' */
  codertarget_arduinobase_inter_T obj_h;/* '<S1>/Analog Input' */
  codertarget_arduinobase_int_p_T obj_e;/* '<S3>/PWM1' */
  codertarget_arduinobase_int_p_T obj_d;/* '<S3>/PWM' */
  codertarget_arduinobase_in_py_T obj_l;/* '<S7>/Encoder' */
  codertarget_arduinobase_block_T obj_m;/* '<S4>/Digital Output2' */
  codertarget_arduinobase_block_T obj_n;/* '<S4>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  real_T PositionIntegration_DSTATE;   /* '<S3>/Position Integration' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S3>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

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
  boolean_T objisempty_i;              /* '<S1>/Analog Input' */
} DW_LQR_Controller_T;

/* Parameters (default storage) */
struct P_LQR_Controller_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S5>/UD'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
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
  real_T Constant2_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T PositionIntegration_gainval;
                              /* Computed Parameter: PositionIntegration_gainval
                               * Referenced by: '<S3>/Position Integration'
                               */
  real_T PositionIntegration_IC;       /* Expression: 0
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T LQRGains_Gain[4];
  /* Expression: [-1.732050807568868	-1.891851131298290	10.726317977191563	1.130247453832521]
   * Referenced by: '<Root>/LQR Gains'
   */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: .1
                                        * Referenced by: '<Root>/Switch'
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
struct tag_RTM_LQR_Controller_T {
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
extern P_LQR_Controller_T LQR_Controller_P;

/* Block signals (default storage) */
extern B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
extern DW_LQR_Controller_T LQR_Controller_DW;

/* External function called from main */
extern void LQR_Controller_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void LQR_Controller_initialize(void);
extern void LQR_Controller_step0(void);/* Sample time: [0.01s, 0.0s] */
extern void LQR_Controller_step1(void);/* Sample time: [0.02s, 0.0s] */
extern void LQR_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LQR_Controller_T *const LQR_Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
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
 * '<Root>' : 'LQR_Controller'
 * '<S1>'   : 'LQR_Controller/Angle Measurement'
 * '<S2>'   : 'LQR_Controller/Lin Vel to RPM'
 * '<S3>'   : 'LQR_Controller/Motor Controller'
 * '<S4>'   : 'LQR_Controller/Pin Setup'
 * '<S5>'   : 'LQR_Controller/Angle Measurement/Discrete Derivative'
 * '<S6>'   : 'LQR_Controller/Motor Controller/PID Controller'
 * '<S7>'   : 'LQR_Controller/Motor Controller/RPM Measurement'
 * '<S8>'   : 'LQR_Controller/Motor Controller/Select PWM Direction'
 * '<S9>'   : 'LQR_Controller/Motor Controller/PID Controller/Anti-windup'
 * '<S10>'  : 'LQR_Controller/Motor Controller/PID Controller/D Gain'
 * '<S11>'  : 'LQR_Controller/Motor Controller/PID Controller/External Derivative'
 * '<S12>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter'
 * '<S13>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter ICs'
 * '<S14>'  : 'LQR_Controller/Motor Controller/PID Controller/I Gain'
 * '<S15>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain'
 * '<S16>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator'
 * '<S18>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator ICs'
 * '<S19>'  : 'LQR_Controller/Motor Controller/PID Controller/N Copy'
 * '<S20>'  : 'LQR_Controller/Motor Controller/PID Controller/N Gain'
 * '<S21>'  : 'LQR_Controller/Motor Controller/PID Controller/P Copy'
 * '<S22>'  : 'LQR_Controller/Motor Controller/PID Controller/Parallel P Gain'
 * '<S23>'  : 'LQR_Controller/Motor Controller/PID Controller/Reset Signal'
 * '<S24>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation'
 * '<S25>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation Fdbk'
 * '<S26>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum'
 * '<S27>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum Fdbk'
 * '<S28>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode'
 * '<S29>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Integral'
 * '<S31>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'LQR_Controller/Motor Controller/PID Controller/postSat Signal'
 * '<S33>'  : 'LQR_Controller/Motor Controller/PID Controller/preInt Signal'
 * '<S34>'  : 'LQR_Controller/Motor Controller/PID Controller/preSat Signal'
 * '<S35>'  : 'LQR_Controller/Motor Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S36>'  : 'LQR_Controller/Motor Controller/PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'LQR_Controller/Motor Controller/PID Controller/External Derivative/Error'
 * '<S38>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'LQR_Controller/Motor Controller/PID Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator/Discrete'
 * '<S44>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'LQR_Controller/Motor Controller/PID Controller/N Copy/Disabled'
 * '<S46>'  : 'LQR_Controller/Motor Controller/PID Controller/N Gain/Internal Parameters'
 * '<S47>'  : 'LQR_Controller/Motor Controller/PID Controller/P Copy/Disabled'
 * '<S48>'  : 'LQR_Controller/Motor Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'LQR_Controller/Motor Controller/PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation/Enabled'
 * '<S51>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum/Sum_PID'
 * '<S53>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'LQR_Controller/Motor Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S59>'  : 'LQR_Controller/Motor Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S60>'  : 'LQR_Controller/Motor Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'LQR_Controller/Motor Controller/RPM Measurement/Filter for data dropouts'
 */
#endif                                 /* LQR_Controller_h_ */
