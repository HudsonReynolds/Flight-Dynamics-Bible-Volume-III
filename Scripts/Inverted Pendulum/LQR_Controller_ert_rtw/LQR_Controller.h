/*
 * LQR_Controller.h
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

#ifndef LQR_Controller_h_
#define LQR_Controller_h_
#ifndef LQR_Controller_COMMON_INCLUDES_
#define LQR_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* LQR_Controller_COMMON_INCLUDES_ */

#include "LQR_Controller_types.h"
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

/* Block signals for system '<S9>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S9>/Moving Average' */
} B_MovingAverage_LQR_Controlle_T;

/* Block states (default storage) for system '<S9>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_LQ_T obj; /* '<S9>/Moving Average' */
  boolean_T objisempty;                /* '<S9>/Moving Average' */
} DW_MovingAverage_LQR_Controll_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtAdd2Inport1;          /* '<S3>/Gain1' */
  real_T VoltagetoCurrent;             /* '<S6>/Voltage to Current' */
  real_T DataTypeConversion;           /* '<S9>/Data Type Conversion' */
  real_T StateVector[4];               /* '<Root>/State Vector' */
  real_T MovingAverage;
  real_T csum;
  B_MovingAverage_LQR_Controlle_T MovingAverage_pn;/* '<S9>/Moving Average' */
  B_MovingAverage_LQR_Controlle_T MovingAverage_p;/* '<S9>/Moving Average' */
} B_LQR_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_p_T obj;  /* '<S1>/Moving Average' */
  codertarget_arduinobase_inter_T obj_a;/* '<S6>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_l;/* '<S6>/Analog Input' */
  codertarget_arduinobase_inter_T obj_h;/* '<S1>/Analog Input' */
  codertarget_arduinobase_int_p_T obj_e;/* '<S2>/PWM1' */
  codertarget_arduinobase_int_p_T obj_d;/* '<S2>/PWM' */
  codertarget_arduinobase_in_py_T obj_lf;/* '<S9>/Encoder' */
  codertarget_arduinobase_block_T obj_m;/* '<S5>/Digital Output2' */
  codertarget_arduinobase_block_T obj_n;/* '<S5>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S7>/UD' */
  real_T PositionIntegration_DSTATE;   /* '<S2>/Position Integration' */
  real_T TmpRTBAtStateVectorInport1_Buff;/* synthesized block */
  real_T TmpRTBAtStateVectorInport2_Buff;/* synthesized block */
  real_T TmpRTBAtAdd2Inport1_Buffer0;  /* synthesized block */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S9>/Scope' */

  int32_T prevVal;                     /* '<S9>/Filter for data dropouts' */
  boolean_T objisempty;                /* '<S6>/Analog Input1' */
  boolean_T objisempty_c;              /* '<S6>/Analog Input' */
  boolean_T objisempty_d;              /* '<S5>/Digital Output2' */
  boolean_T objisempty_j;              /* '<S5>/Digital Output1' */
  boolean_T prevVal_not_empty;         /* '<S9>/Filter for data dropouts' */
  boolean_T objisempty_m;              /* '<S9>/Encoder' */
  boolean_T objisempty_o;              /* '<S2>/PWM1' */
  boolean_T objisempty_f;              /* '<S2>/PWM' */
  boolean_T objisempty_cu;             /* '<S1>/Moving Average' */
  boolean_T objisempty_i;              /* '<S1>/Analog Input' */
  DW_MovingAverage_LQR_Controll_T MovingAverage_pn;/* '<S9>/Moving Average' */
  DW_MovingAverage_LQR_Controll_T MovingAverage_p;/* '<S9>/Moving Average' */
} DW_LQR_Controller_T;

/* Parameters (default storage) */
struct P_LQR_Controller_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<Root>/LQR Gains'
                                        */
  real_T R_motor;                      /* Variable: R_motor
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T k_motor;                      /* Variable: k_motor
                                        * Referenced by:
                                        *   '<S3>/Gain1'
                                        *   '<S3>/Gain2'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by:
                                        *   '<S3>/Gain1'
                                        *   '<S3>/Gain2'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S7>/UD'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant3_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 50
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 255/24
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T TmpRTBAtStateVectorInport1_Init;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtStateVectorInport2_Init;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value;               /* Expression: pi/2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real_T TmpRTBAtAdd2Inport1_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T Switch_Threshold;             /* Expression: .3
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant2_Value;              /* Expression: 407
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T DeadZone1_Start;              /* Expression: -1
                                        * Referenced by: '<S6>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: 1
                                        * Referenced by: '<S6>/Dead Zone1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 403
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T DeadZone_Start;               /* Expression: -1
                                        * Referenced by: '<S6>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 1
                                        * Referenced by: '<S6>/Dead Zone'
                                        */
  real_T AnalogtoVoltage_Gain;         /* Expression: 5/1023
                                        * Referenced by: '<S6>/Analog to Voltage'
                                        */
  real_T VoltagetoCurrent_Gain;        /* Expression: 8500/1000
                                        * Referenced by: '<S6>/Voltage to Current'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T PositionIntegration_gainval;
                              /* Computed Parameter: PositionIntegration_gainval
                               * Referenced by: '<S2>/Position Integration'
                               */
  real_T PositionIntegration_IC;       /* Expression: 0
                                        * Referenced by: '<S2>/Position Integration'
                                        */
  real_T PositionIntegration_UpperSat; /* Expression: .5
                                        * Referenced by: '<S2>/Position Integration'
                                        */
  real_T PositionIntegration_LowerSat; /* Expression: -.5
                                        * Referenced by: '<S2>/Position Integration'
                                        */
  real_T RPMtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S2>/RPM to rad//s'
                                        */
  real_T radstoms_Gain;                /* Expression: 6.5/1000
                                        * Referenced by: '<S2>/rad//s to m//s'
                                        */
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S9>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad_Gain;              /* Computed Parameter: Volt2Rad_Gain
                                        * Referenced by: '<S1>/Volt2Rad'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LQR_Controller_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
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
extern void LQR_Controller_step0(void);/* Sample time: [0.007s, 0.0s] */
extern void LQR_Controller_step1(void);/* Sample time: [0.014s, 0.0s] */
extern void LQR_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LQR_Controller_T *const LQR_Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<S2>/Add1' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S37>/Kb' : Unused code path elimination
 * Block '<S37>/SumI2' : Unused code path elimination
 * Block '<S37>/SumI4' : Unused code path elimination
 * Block '<S38>/Derivative Gain' : Unused code path elimination
 * Block '<S40>/Filter' : Unused code path elimination
 * Block '<S40>/SumD' : Unused code path elimination
 * Block '<S42>/Integral Gain' : Unused code path elimination
 * Block '<S45>/Integrator' : Unused code path elimination
 * Block '<S48>/Filter Coefficient' : Unused code path elimination
 * Block '<S50>/Proportional Gain' : Unused code path elimination
 * Block '<S52>/Saturation' : Unused code path elimination
 * Block '<S54>/Sum' : Unused code path elimination
 * Block '<S9>/Display3' : Unused code path elimination
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display4' : Unused code path elimination
 * Block '<S91>/Derivative Gain' : Unused code path elimination
 * Block '<S93>/Filter' : Unused code path elimination
 * Block '<S93>/SumD' : Unused code path elimination
 * Block '<S95>/Integral Gain' : Unused code path elimination
 * Block '<S98>/Integrator' : Unused code path elimination
 * Block '<S101>/Filter Coefficient' : Unused code path elimination
 * Block '<S103>/Proportional Gain' : Unused code path elimination
 * Block '<S105>/Saturation' : Unused code path elimination
 * Block '<S107>/Sum' : Unused code path elimination
 * Block '<Root>/Sum1' : Unused code path elimination
 * Block '<S6>/Current to Torque' : Unused code path elimination
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
 * '<S2>'   : 'LQR_Controller/Motor Controller'
 * '<S3>'   : 'LQR_Controller/Motor Dynamics Model'
 * '<S4>'   : 'LQR_Controller/PID Controller'
 * '<S5>'   : 'LQR_Controller/Pin Setup'
 * '<S6>'   : 'LQR_Controller/Torque Measurement'
 * '<S7>'   : 'LQR_Controller/Angle Measurement/Discrete Derivative'
 * '<S8>'   : 'LQR_Controller/Motor Controller/PID Controller'
 * '<S9>'   : 'LQR_Controller/Motor Controller/RPM Measurement'
 * '<S10>'  : 'LQR_Controller/Motor Controller/Select PWM Direction'
 * '<S11>'  : 'LQR_Controller/Motor Controller/PID Controller/Anti-windup'
 * '<S12>'  : 'LQR_Controller/Motor Controller/PID Controller/D Gain'
 * '<S13>'  : 'LQR_Controller/Motor Controller/PID Controller/External Derivative'
 * '<S14>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter'
 * '<S15>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter ICs'
 * '<S16>'  : 'LQR_Controller/Motor Controller/PID Controller/I Gain'
 * '<S17>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain'
 * '<S18>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S19>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator'
 * '<S20>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator ICs'
 * '<S21>'  : 'LQR_Controller/Motor Controller/PID Controller/N Copy'
 * '<S22>'  : 'LQR_Controller/Motor Controller/PID Controller/N Gain'
 * '<S23>'  : 'LQR_Controller/Motor Controller/PID Controller/P Copy'
 * '<S24>'  : 'LQR_Controller/Motor Controller/PID Controller/Parallel P Gain'
 * '<S25>'  : 'LQR_Controller/Motor Controller/PID Controller/Reset Signal'
 * '<S26>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation'
 * '<S27>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation Fdbk'
 * '<S28>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum'
 * '<S29>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum Fdbk'
 * '<S30>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode'
 * '<S31>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode Sum'
 * '<S32>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Integral'
 * '<S33>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Ngain'
 * '<S34>'  : 'LQR_Controller/Motor Controller/PID Controller/postSat Signal'
 * '<S35>'  : 'LQR_Controller/Motor Controller/PID Controller/preInt Signal'
 * '<S36>'  : 'LQR_Controller/Motor Controller/PID Controller/preSat Signal'
 * '<S37>'  : 'LQR_Controller/Motor Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S38>'  : 'LQR_Controller/Motor Controller/PID Controller/D Gain/Internal Parameters'
 * '<S39>'  : 'LQR_Controller/Motor Controller/PID Controller/External Derivative/Error'
 * '<S40>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S41>'  : 'LQR_Controller/Motor Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S42>'  : 'LQR_Controller/Motor Controller/PID Controller/I Gain/Internal Parameters'
 * '<S43>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S44>'  : 'LQR_Controller/Motor Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator/Discrete'
 * '<S46>'  : 'LQR_Controller/Motor Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S47>'  : 'LQR_Controller/Motor Controller/PID Controller/N Copy/Disabled'
 * '<S48>'  : 'LQR_Controller/Motor Controller/PID Controller/N Gain/Internal Parameters'
 * '<S49>'  : 'LQR_Controller/Motor Controller/PID Controller/P Copy/Disabled'
 * '<S50>'  : 'LQR_Controller/Motor Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S51>'  : 'LQR_Controller/Motor Controller/PID Controller/Reset Signal/Disabled'
 * '<S52>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation/Enabled'
 * '<S53>'  : 'LQR_Controller/Motor Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S54>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum/Sum_PID'
 * '<S55>'  : 'LQR_Controller/Motor Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S56>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode/Disabled'
 * '<S57>'  : 'LQR_Controller/Motor Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S59>'  : 'LQR_Controller/Motor Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'LQR_Controller/Motor Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S61>'  : 'LQR_Controller/Motor Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S62>'  : 'LQR_Controller/Motor Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S63>'  : 'LQR_Controller/Motor Controller/RPM Measurement/Filter for data dropouts'
 * '<S64>'  : 'LQR_Controller/PID Controller/Anti-windup'
 * '<S65>'  : 'LQR_Controller/PID Controller/D Gain'
 * '<S66>'  : 'LQR_Controller/PID Controller/External Derivative'
 * '<S67>'  : 'LQR_Controller/PID Controller/Filter'
 * '<S68>'  : 'LQR_Controller/PID Controller/Filter ICs'
 * '<S69>'  : 'LQR_Controller/PID Controller/I Gain'
 * '<S70>'  : 'LQR_Controller/PID Controller/Ideal P Gain'
 * '<S71>'  : 'LQR_Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S72>'  : 'LQR_Controller/PID Controller/Integrator'
 * '<S73>'  : 'LQR_Controller/PID Controller/Integrator ICs'
 * '<S74>'  : 'LQR_Controller/PID Controller/N Copy'
 * '<S75>'  : 'LQR_Controller/PID Controller/N Gain'
 * '<S76>'  : 'LQR_Controller/PID Controller/P Copy'
 * '<S77>'  : 'LQR_Controller/PID Controller/Parallel P Gain'
 * '<S78>'  : 'LQR_Controller/PID Controller/Reset Signal'
 * '<S79>'  : 'LQR_Controller/PID Controller/Saturation'
 * '<S80>'  : 'LQR_Controller/PID Controller/Saturation Fdbk'
 * '<S81>'  : 'LQR_Controller/PID Controller/Sum'
 * '<S82>'  : 'LQR_Controller/PID Controller/Sum Fdbk'
 * '<S83>'  : 'LQR_Controller/PID Controller/Tracking Mode'
 * '<S84>'  : 'LQR_Controller/PID Controller/Tracking Mode Sum'
 * '<S85>'  : 'LQR_Controller/PID Controller/Tsamp - Integral'
 * '<S86>'  : 'LQR_Controller/PID Controller/Tsamp - Ngain'
 * '<S87>'  : 'LQR_Controller/PID Controller/postSat Signal'
 * '<S88>'  : 'LQR_Controller/PID Controller/preInt Signal'
 * '<S89>'  : 'LQR_Controller/PID Controller/preSat Signal'
 * '<S90>'  : 'LQR_Controller/PID Controller/Anti-windup/Passthrough'
 * '<S91>'  : 'LQR_Controller/PID Controller/D Gain/Internal Parameters'
 * '<S92>'  : 'LQR_Controller/PID Controller/External Derivative/Error'
 * '<S93>'  : 'LQR_Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S94>'  : 'LQR_Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S95>'  : 'LQR_Controller/PID Controller/I Gain/Internal Parameters'
 * '<S96>'  : 'LQR_Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S97>'  : 'LQR_Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'LQR_Controller/PID Controller/Integrator/Discrete'
 * '<S99>'  : 'LQR_Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S100>' : 'LQR_Controller/PID Controller/N Copy/Disabled'
 * '<S101>' : 'LQR_Controller/PID Controller/N Gain/Internal Parameters'
 * '<S102>' : 'LQR_Controller/PID Controller/P Copy/Disabled'
 * '<S103>' : 'LQR_Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S104>' : 'LQR_Controller/PID Controller/Reset Signal/Disabled'
 * '<S105>' : 'LQR_Controller/PID Controller/Saturation/Enabled'
 * '<S106>' : 'LQR_Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S107>' : 'LQR_Controller/PID Controller/Sum/Sum_PID'
 * '<S108>' : 'LQR_Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S109>' : 'LQR_Controller/PID Controller/Tracking Mode/Disabled'
 * '<S110>' : 'LQR_Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'LQR_Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S112>' : 'LQR_Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'LQR_Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S114>' : 'LQR_Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S115>' : 'LQR_Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S116>' : 'LQR_Controller/Torque Measurement/MATLAB Function'
 */
#endif                                 /* LQR_Controller_h_ */
