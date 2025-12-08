/*
 * PID_Controller_Test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_Controller_Test".
 *
 * Model version              : 1.1
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Oct  6 19:57:00 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PID_Controller_Test_h_
#define PID_Controller_Test_h_
#ifndef PID_Controller_Test_COMMON_INCLUDES_
#define PID_Controller_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                /* PID_Controller_Test_COMMON_INCLUDES_ */

#include "PID_Controller_Test_types.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T StateVector[4];               /* '<Root>/State Vector' */
  real_T SetPoint[4];                  /* '<Root>/Set Point' */
  real_T TmpRTBAtAdd2Inport1;          /* '<S4>/Gain1' */
  real_T TmpRTBAtSum1Inport2;          /* '<Root>/PID Controller1' */
} B_PID_Controller_Test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_PI_T obj; /* '<S1>/Moving Average' */
  dsp_simulink_MovingAverage_l_T obj_n;/* '<S15>/Moving Average' */
  codertarget_arduinobase_inter_T obj_g;/* '<S1>/Analog Input1' */
  codertarget_arduinobase_int_l_T obj_k;/* '<S3>/PWM1' */
  codertarget_arduinobase_int_l_T obj_gm;/* '<S3>/PWM' */
  codertarget_arduinobase_in_li_T obj_d;/* '<S15>/Encoder' */
  codertarget_arduinobase_block_T obj_p;/* '<S7>/Digital Output2' */
  codertarget_arduinobase_block_T obj_e;/* '<S7>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S8>/UD' */
  real_T Integrator_DSTATE;            /* '<S52>/Integrator' */
  real_T Filter_DSTATE;                /* '<S47>/Filter' */
  real_T PositionIntegration_DSTATE;   /* '<S3>/Position Integration' */
  real_T Filter_DSTATE_j;              /* '<S99>/Filter' */
  real_T Integrator_DSTATE_l;          /* '<S104>/Integrator' */
  real_T RT_Buffer0;                   /* '<Root>/RT' */
  real_T RT1_Buffer0;                  /* '<Root>/RT1' */
  real_T TmpRTBAtAdd2Inport1_Buffer0;  /* synthesized block */
  real_T TmpRTBAtSum1Inport2_Buffer0;  /* synthesized block */
  real_T sample_count;                 /* '<S1>/MATLAB Function1' */
  real_T theta_sum;                    /* '<S1>/MATLAB Function1' */
  real_T theta0;                       /* '<S1>/MATLAB Function1' */
  real_T N;                            /* '<S1>/MATLAB Function1' */
  int32_T prevVal;                     /* '<S15>/Filter for data dropouts' */
  boolean_T objisempty;                /* '<S7>/Digital Output2' */
  boolean_T objisempty_m;              /* '<S7>/Digital Output1' */
  boolean_T objisempty_c;              /* '<S15>/Moving Average' */
  boolean_T prevVal_not_empty;         /* '<S15>/Filter for data dropouts' */
  boolean_T objisempty_j;              /* '<S15>/Encoder' */
  boolean_T objisempty_l;              /* '<S3>/PWM1' */
  boolean_T objisempty_m2;             /* '<S3>/PWM' */
  boolean_T thetaMax_not_empty;        /* '<S12>/MATLAB Function1' */
  boolean_T objisempty_mp;             /* '<S1>/Moving Average' */
  boolean_T calibrated;                /* '<S1>/MATLAB Function1' */
  boolean_T objisempty_n;              /* '<S1>/Analog Input1' */
} DW_PID_Controller_Test_T;

/* Parameters (default storage) */
struct P_PID_Controller_Test_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S45>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S97>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S49>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S101>/Integral Gain'
                                        */
  real_T Derivative_ICPrevScaledInput;
                                 /* Mask Parameter: Derivative_ICPrevScaledInput
                                  * Referenced by: '<S8>/UD'
                                  */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S47>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S99>/Filter'
                               */
  real_T PIDController_InitialConditio_f;
                              /* Mask Parameter: PIDController_InitialConditio_f
                               * Referenced by: '<S52>/Integrator'
                               */
  real_T PIDController1_InitialConditi_g;
                              /* Mask Parameter: PIDController1_InitialConditi_g
                               * Referenced by: '<S104>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S55>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S107>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S57>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S109>/Proportional Gain'
                                        */
  real_T RT_InitialCondition;          /* Expression: 0
                                        * Referenced by: '<Root>/RT'
                                        */
  real_T RT1_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S8>/TSamp'
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
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T TmpRTBAtAdd2Inport1_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S52>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S47>/Filter'
                                        */
  real_T TmpRTBAtSum1Inport2_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain2_Gain;                   /* Expression: 0.51316
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PositionIntegration_gainval;
                              /* Computed Parameter: PositionIntegration_gainval
                               * Referenced by: '<S3>/Position Integration'
                               */
  real_T PositionIntegration_IC;       /* Expression: 0
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T PositionIntegration_UpperSat; /* Expression: .5
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T PositionIntegration_LowerSat; /* Expression: -.5
                                        * Referenced by: '<S3>/Position Integration'
                                        */
  real_T RPMtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S3>/RPM to rad//s'
                                        */
  real_T radstoms_Gain;                /* Expression: 6.5/1000
                                        * Referenced by: '<S3>/rad//s to m//s'
                                        */
  real_T Gain1_Gain;                   /* Expression: 11.692
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Filter_gainval_i;             /* Computed Parameter: Filter_gainval_i
                                        * Referenced by: '<S99>/Filter'
                                        */
  real_T Integrator_gainval_b;       /* Computed Parameter: Integrator_gainval_b
                                      * Referenced by: '<S104>/Integrator'
                                      */
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S15>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad1_Gain;             /* Computed Parameter: Volt2Rad1_Gain
                                        * Referenced by: '<S1>/Volt2Rad1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID_Controller_Test_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_Controller_Test_T PID_Controller_Test_P;

/* Block signals (default storage) */
extern B_PID_Controller_Test_T PID_Controller_Test_B;

/* Block states (default storage) */
extern DW_PID_Controller_Test_T PID_Controller_Test_DW;

/* External function called from main */
extern void PID_Controller_Test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void PID_Controller_Test_initialize(void);
extern void PID_Controller_Test_step0(void);/* Sample time: [0.0035s, 0.0s] */
extern void PID_Controller_Test_step1(void);/* Sample time: [0.007s, 0.0s] */
extern void PID_Controller_Test_step2(void);/* Sample time: [0.014s, 0.0s] */
extern void PID_Controller_Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_Controller_Test_T *const PID_Controller_Test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Display3' : Unused code path elimination
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
 * '<Root>' : 'PID_Controller_Test'
 * '<S1>'   : 'PID_Controller_Test/Angle Measurement'
 * '<S2>'   : 'PID_Controller_Test/Mode Selection'
 * '<S3>'   : 'PID_Controller_Test/Motor Controller'
 * '<S4>'   : 'PID_Controller_Test/Motor Dynamics Model'
 * '<S5>'   : 'PID_Controller_Test/PID Controller'
 * '<S6>'   : 'PID_Controller_Test/PID Controller1'
 * '<S7>'   : 'PID_Controller_Test/Pin Setup'
 * '<S8>'   : 'PID_Controller_Test/Angle Measurement/Derivative'
 * '<S9>'   : 'PID_Controller_Test/Angle Measurement/MATLAB Function1'
 * '<S10>'  : 'PID_Controller_Test/Mode Selection/LQR'
 * '<S11>'  : 'PID_Controller_Test/Mode Selection/MATLAB Function'
 * '<S12>'  : 'PID_Controller_Test/Mode Selection/Swing Up'
 * '<S13>'  : 'PID_Controller_Test/Mode Selection/Uncalibrated'
 * '<S14>'  : 'PID_Controller_Test/Mode Selection/Swing Up/MATLAB Function1'
 * '<S15>'  : 'PID_Controller_Test/Motor Controller/RPM Measurement'
 * '<S16>'  : 'PID_Controller_Test/Motor Controller/Select PWM Direction'
 * '<S17>'  : 'PID_Controller_Test/Motor Controller/RPM Measurement/Filter for data dropouts'
 * '<S18>'  : 'PID_Controller_Test/PID Controller/Anti-windup'
 * '<S19>'  : 'PID_Controller_Test/PID Controller/D Gain'
 * '<S20>'  : 'PID_Controller_Test/PID Controller/External Derivative'
 * '<S21>'  : 'PID_Controller_Test/PID Controller/Filter'
 * '<S22>'  : 'PID_Controller_Test/PID Controller/Filter ICs'
 * '<S23>'  : 'PID_Controller_Test/PID Controller/I Gain'
 * '<S24>'  : 'PID_Controller_Test/PID Controller/Ideal P Gain'
 * '<S25>'  : 'PID_Controller_Test/PID Controller/Ideal P Gain Fdbk'
 * '<S26>'  : 'PID_Controller_Test/PID Controller/Integrator'
 * '<S27>'  : 'PID_Controller_Test/PID Controller/Integrator ICs'
 * '<S28>'  : 'PID_Controller_Test/PID Controller/N Copy'
 * '<S29>'  : 'PID_Controller_Test/PID Controller/N Gain'
 * '<S30>'  : 'PID_Controller_Test/PID Controller/P Copy'
 * '<S31>'  : 'PID_Controller_Test/PID Controller/Parallel P Gain'
 * '<S32>'  : 'PID_Controller_Test/PID Controller/Reset Signal'
 * '<S33>'  : 'PID_Controller_Test/PID Controller/Saturation'
 * '<S34>'  : 'PID_Controller_Test/PID Controller/Saturation Fdbk'
 * '<S35>'  : 'PID_Controller_Test/PID Controller/Sum'
 * '<S36>'  : 'PID_Controller_Test/PID Controller/Sum Fdbk'
 * '<S37>'  : 'PID_Controller_Test/PID Controller/Tracking Mode'
 * '<S38>'  : 'PID_Controller_Test/PID Controller/Tracking Mode Sum'
 * '<S39>'  : 'PID_Controller_Test/PID Controller/Tsamp - Integral'
 * '<S40>'  : 'PID_Controller_Test/PID Controller/Tsamp - Ngain'
 * '<S41>'  : 'PID_Controller_Test/PID Controller/postSat Signal'
 * '<S42>'  : 'PID_Controller_Test/PID Controller/preInt Signal'
 * '<S43>'  : 'PID_Controller_Test/PID Controller/preSat Signal'
 * '<S44>'  : 'PID_Controller_Test/PID Controller/Anti-windup/Passthrough'
 * '<S45>'  : 'PID_Controller_Test/PID Controller/D Gain/Internal Parameters'
 * '<S46>'  : 'PID_Controller_Test/PID Controller/External Derivative/Error'
 * '<S47>'  : 'PID_Controller_Test/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S48>'  : 'PID_Controller_Test/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S49>'  : 'PID_Controller_Test/PID Controller/I Gain/Internal Parameters'
 * '<S50>'  : 'PID_Controller_Test/PID Controller/Ideal P Gain/Passthrough'
 * '<S51>'  : 'PID_Controller_Test/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S52>'  : 'PID_Controller_Test/PID Controller/Integrator/Discrete'
 * '<S53>'  : 'PID_Controller_Test/PID Controller/Integrator ICs/Internal IC'
 * '<S54>'  : 'PID_Controller_Test/PID Controller/N Copy/Disabled'
 * '<S55>'  : 'PID_Controller_Test/PID Controller/N Gain/Internal Parameters'
 * '<S56>'  : 'PID_Controller_Test/PID Controller/P Copy/Disabled'
 * '<S57>'  : 'PID_Controller_Test/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S58>'  : 'PID_Controller_Test/PID Controller/Reset Signal/Disabled'
 * '<S59>'  : 'PID_Controller_Test/PID Controller/Saturation/Passthrough'
 * '<S60>'  : 'PID_Controller_Test/PID Controller/Saturation Fdbk/Disabled'
 * '<S61>'  : 'PID_Controller_Test/PID Controller/Sum/Sum_PID'
 * '<S62>'  : 'PID_Controller_Test/PID Controller/Sum Fdbk/Disabled'
 * '<S63>'  : 'PID_Controller_Test/PID Controller/Tracking Mode/Disabled'
 * '<S64>'  : 'PID_Controller_Test/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S65>'  : 'PID_Controller_Test/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S66>'  : 'PID_Controller_Test/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S67>'  : 'PID_Controller_Test/PID Controller/postSat Signal/Forward_Path'
 * '<S68>'  : 'PID_Controller_Test/PID Controller/preInt Signal/Internal PreInt'
 * '<S69>'  : 'PID_Controller_Test/PID Controller/preSat Signal/Forward_Path'
 * '<S70>'  : 'PID_Controller_Test/PID Controller1/Anti-windup'
 * '<S71>'  : 'PID_Controller_Test/PID Controller1/D Gain'
 * '<S72>'  : 'PID_Controller_Test/PID Controller1/External Derivative'
 * '<S73>'  : 'PID_Controller_Test/PID Controller1/Filter'
 * '<S74>'  : 'PID_Controller_Test/PID Controller1/Filter ICs'
 * '<S75>'  : 'PID_Controller_Test/PID Controller1/I Gain'
 * '<S76>'  : 'PID_Controller_Test/PID Controller1/Ideal P Gain'
 * '<S77>'  : 'PID_Controller_Test/PID Controller1/Ideal P Gain Fdbk'
 * '<S78>'  : 'PID_Controller_Test/PID Controller1/Integrator'
 * '<S79>'  : 'PID_Controller_Test/PID Controller1/Integrator ICs'
 * '<S80>'  : 'PID_Controller_Test/PID Controller1/N Copy'
 * '<S81>'  : 'PID_Controller_Test/PID Controller1/N Gain'
 * '<S82>'  : 'PID_Controller_Test/PID Controller1/P Copy'
 * '<S83>'  : 'PID_Controller_Test/PID Controller1/Parallel P Gain'
 * '<S84>'  : 'PID_Controller_Test/PID Controller1/Reset Signal'
 * '<S85>'  : 'PID_Controller_Test/PID Controller1/Saturation'
 * '<S86>'  : 'PID_Controller_Test/PID Controller1/Saturation Fdbk'
 * '<S87>'  : 'PID_Controller_Test/PID Controller1/Sum'
 * '<S88>'  : 'PID_Controller_Test/PID Controller1/Sum Fdbk'
 * '<S89>'  : 'PID_Controller_Test/PID Controller1/Tracking Mode'
 * '<S90>'  : 'PID_Controller_Test/PID Controller1/Tracking Mode Sum'
 * '<S91>'  : 'PID_Controller_Test/PID Controller1/Tsamp - Integral'
 * '<S92>'  : 'PID_Controller_Test/PID Controller1/Tsamp - Ngain'
 * '<S93>'  : 'PID_Controller_Test/PID Controller1/postSat Signal'
 * '<S94>'  : 'PID_Controller_Test/PID Controller1/preInt Signal'
 * '<S95>'  : 'PID_Controller_Test/PID Controller1/preSat Signal'
 * '<S96>'  : 'PID_Controller_Test/PID Controller1/Anti-windup/Passthrough'
 * '<S97>'  : 'PID_Controller_Test/PID Controller1/D Gain/Internal Parameters'
 * '<S98>'  : 'PID_Controller_Test/PID Controller1/External Derivative/Error'
 * '<S99>'  : 'PID_Controller_Test/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S100>' : 'PID_Controller_Test/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S101>' : 'PID_Controller_Test/PID Controller1/I Gain/Internal Parameters'
 * '<S102>' : 'PID_Controller_Test/PID Controller1/Ideal P Gain/Passthrough'
 * '<S103>' : 'PID_Controller_Test/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S104>' : 'PID_Controller_Test/PID Controller1/Integrator/Discrete'
 * '<S105>' : 'PID_Controller_Test/PID Controller1/Integrator ICs/Internal IC'
 * '<S106>' : 'PID_Controller_Test/PID Controller1/N Copy/Disabled'
 * '<S107>' : 'PID_Controller_Test/PID Controller1/N Gain/Internal Parameters'
 * '<S108>' : 'PID_Controller_Test/PID Controller1/P Copy/Disabled'
 * '<S109>' : 'PID_Controller_Test/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S110>' : 'PID_Controller_Test/PID Controller1/Reset Signal/Disabled'
 * '<S111>' : 'PID_Controller_Test/PID Controller1/Saturation/Passthrough'
 * '<S112>' : 'PID_Controller_Test/PID Controller1/Saturation Fdbk/Disabled'
 * '<S113>' : 'PID_Controller_Test/PID Controller1/Sum/Sum_PID'
 * '<S114>' : 'PID_Controller_Test/PID Controller1/Sum Fdbk/Disabled'
 * '<S115>' : 'PID_Controller_Test/PID Controller1/Tracking Mode/Disabled'
 * '<S116>' : 'PID_Controller_Test/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S117>' : 'PID_Controller_Test/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S118>' : 'PID_Controller_Test/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S119>' : 'PID_Controller_Test/PID Controller1/postSat Signal/Forward_Path'
 * '<S120>' : 'PID_Controller_Test/PID Controller1/preInt Signal/Internal PreInt'
 * '<S121>' : 'PID_Controller_Test/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* PID_Controller_Test_h_ */
