/*
 * LQR_Controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.58
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sun Aug 24 15:48:43 2025
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

/* Block signals (default storage) */
typedef struct {
  real_T StateVector[4];               /* '<Root>/State Vector' */
  real_T SetPoint[4];                  /* '<Root>/Set Point' */
  real_T TmpRTBAtAdd2Inport1;          /* '<S4>/Gain1' */
} B_LQR_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_LQ_T obj; /* '<S1>/Moving Average' */
  dsp_simulink_MovingAverage_p_T obj_m;/* '<S13>/Moving Average' */
  codertarget_arduinobase_inter_T obj_g;/* '<S1>/Analog Input1' */
  codertarget_arduinobase_int_p_T obj_e;/* '<S3>/PWM1' */
  codertarget_arduinobase_int_p_T obj_d;/* '<S3>/PWM' */
  codertarget_arduinobase_in_py_T obj_l;/* '<S13>/Encoder' */
  codertarget_arduinobase_block_T obj_mo;/* '<S5>/Digital Output2' */
  codertarget_arduinobase_block_T obj_n;/* '<S5>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T PositionIntegration_DSTATE;   /* '<S3>/Position Integration' */
  real_T RT_Buffer0;                   /* '<Root>/RT' */
  real_T RT1_Buffer0;                  /* '<Root>/RT1' */
  real_T TmpRTBAtAdd2Inport1_Buffer0;  /* synthesized block */
  real_T sample_count;                 /* '<S1>/MATLAB Function1' */
  real_T theta_sum;                    /* '<S1>/MATLAB Function1' */
  real_T theta0;                       /* '<S1>/MATLAB Function1' */
  real_T N;                            /* '<S1>/MATLAB Function1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S13>/Scope' */

  int32_T prevVal;                     /* '<S13>/Filter for data dropouts' */
  boolean_T objisempty;                /* '<S5>/Digital Output2' */
  boolean_T objisempty_j;              /* '<S5>/Digital Output1' */
  boolean_T objisempty_o;              /* '<S13>/Moving Average' */
  boolean_T prevVal_not_empty;         /* '<S13>/Filter for data dropouts' */
  boolean_T objisempty_m;              /* '<S13>/Encoder' */
  boolean_T objisempty_og;             /* '<S3>/PWM1' */
  boolean_T objisempty_f;              /* '<S3>/PWM' */
  boolean_T thetaMax_not_empty;        /* '<S10>/MATLAB Function1' */
  boolean_T objisempty_mm;             /* '<S1>/Moving Average' */
  boolean_T calibrated;                /* '<S1>/MATLAB Function1' */
  boolean_T objisempty_b;              /* '<S1>/Analog Input1' */
} DW_LQR_Controller_T;

/* Parameters (default storage) */
struct P_LQR_Controller_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<Root>/LQR Gains'
                                        */
  real_T R_motor;                      /* Variable: R_motor
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T k_motor;                      /* Variable: k_motor
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S4>/Gain2'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S4>/Gain2'
                                        */
  real_T Derivative_ICPrevScaledInput;
                                 /* Mask Parameter: Derivative_ICPrevScaledInput
                                  * Referenced by: '<S6>/UD'
                                  */
  real_T RT_InitialCondition;          /* Expression: 0
                                        * Referenced by: '<Root>/RT'
                                        */
  real_T RT1_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
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
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T TmpRTBAtAdd2Inport1_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain4_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
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
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S13>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad1_Gain;             /* Computed Parameter: Volt2Rad1_Gain
                                        * Referenced by: '<S1>/Volt2Rad1'
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
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
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
extern void LQR_Controller_step0(void);/* Sample time: [0.0035s, 0.0s] */
extern void LQR_Controller_step1(void);/* Sample time: [0.007s, 0.0s] */
extern void LQR_Controller_step2(void);/* Sample time: [0.014s, 0.0s] */
extern void LQR_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LQR_Controller_T *const LQR_Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Display3' : Unused code path elimination
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
 * '<S2>'   : 'LQR_Controller/Mode Selection'
 * '<S3>'   : 'LQR_Controller/Motor Controller'
 * '<S4>'   : 'LQR_Controller/Motor Dynamics Model'
 * '<S5>'   : 'LQR_Controller/Pin Setup'
 * '<S6>'   : 'LQR_Controller/Angle Measurement/Derivative'
 * '<S7>'   : 'LQR_Controller/Angle Measurement/MATLAB Function1'
 * '<S8>'   : 'LQR_Controller/Mode Selection/LQR'
 * '<S9>'   : 'LQR_Controller/Mode Selection/MATLAB Function'
 * '<S10>'  : 'LQR_Controller/Mode Selection/Swing Up'
 * '<S11>'  : 'LQR_Controller/Mode Selection/Uncalibrated'
 * '<S12>'  : 'LQR_Controller/Mode Selection/Swing Up/MATLAB Function1'
 * '<S13>'  : 'LQR_Controller/Motor Controller/RPM Measurement'
 * '<S14>'  : 'LQR_Controller/Motor Controller/Select PWM Direction'
 * '<S15>'  : 'LQR_Controller/Motor Controller/RPM Measurement/Filter for data dropouts'
 */
#endif                                 /* LQR_Controller_h_ */
