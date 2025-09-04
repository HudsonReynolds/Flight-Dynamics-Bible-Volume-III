/*
 * motorRPMTest.h
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

#ifndef motorRPMTest_h_
#define motorRPMTest_h_
#ifndef motorRPMTest_COMMON_INCLUDES_
#define motorRPMTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* motorRPMTest_COMMON_INCLUDES_ */

#include "motorRPMTest_types.h"
#include "multiword_types.h"
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S62>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S62>/Moving Average' */
} B_MovingAverage_motorRPMTest_T;

/* Block states (default storage) for system '<S62>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_mo_T obj; /* '<S62>/Moving Average' */
  boolean_T objisempty;                /* '<S62>/Moving Average' */
} DW_MovingAverage_motorRPMTest_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product2[4];                  /* '<S60>/Product2' */
  real_T Product3[4];                  /* '<S58>/Product3' */
  real_T Add_i[4];                     /* '<S34>/Add' */
  real_T Reshapey[2];                  /* '<S2>/Reshapey' */
  real_T rtb_Reshapey_m[2];
  real_T DataTypeConversion;           /* '<S62>/Data Type Conversion' */
  real_T VoltagetoCurrent;             /* '<S6>/Voltage to Current' */
  real_T theta_cal;                    /* '<Root>/MATLAB Function' */
  real_T TSamp;                        /* '<S1>/TSamp' */
  real_T e;                            /* '<S4>/Add1' */
  real_T CurrenttoTorque;              /* '<S6>/Current to Torque' */
  real_T Saturation;                   /* '<S105>/Saturation' */
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Add_idx_2;
  real_T rtb_Add_idx_3;
  real_T rtb_Reshapey_c;
  real_T Product2_k;
  real_T Product2_c;
  int64m_T r;
  B_MovingAverage_motorRPMTest_T MovingAverage_p;/* '<S62>/Moving Average' */
  B_MovingAverage_motorRPMTest_T MovingAverage;/* '<S62>/Moving Average' */
} B_motorRPMTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S6>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_e;/* '<S6>/Analog Input' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S4>/PWM1' */
  codertarget_arduinobase_int_m_T obj_n;/* '<S4>/PWM' */
  codertarget_arduinobase_in_mk_T obj_k;/* '<S62>/Encoder' */
  codertarget_arduinobase_block_T obj_k1;/* '<S5>/Digital Output2' */
  codertarget_arduinobase_block_T obj_c;/* '<S5>/Digital Output1' */
  real_T MemoryX_DSTATE[4];            /* '<S2>/MemoryX' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T Integrator_DSTATE;            /* '<S98>/Integrator' */
  real_T sample_count;                 /* '<Root>/MATLAB Function' */
  real_T theta_sum;                    /* '<Root>/MATLAB Function' */
  real_T theta0;                       /* '<Root>/MATLAB Function' */
  real_T N;                            /* '<Root>/MATLAB Function' */
  int32_T prevVal;                     /* '<S62>/Filter for data dropouts' */
  boolean_T icLoad;                    /* '<S2>/MemoryX' */
  boolean_T objisempty;                /* '<S6>/Analog Input1' */
  boolean_T objisempty_g;              /* '<S6>/Analog Input' */
  boolean_T objisempty_d;              /* '<S5>/Digital Output2' */
  boolean_T objisempty_c;              /* '<S5>/Digital Output1' */
  boolean_T prevVal_not_empty;         /* '<S62>/Filter for data dropouts' */
  boolean_T objisempty_n;              /* '<S62>/Encoder' */
  boolean_T objisempty_j;              /* '<S4>/PWM1' */
  boolean_T objisempty_jg;             /* '<S4>/PWM' */
  boolean_T calibrated;                /* '<Root>/MATLAB Function' */
  boolean_T objisempty_jr;             /* '<Root>/Analog Input' */
  boolean_T EnabledSubsystem_MODE;     /* '<S34>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S27>/MeasurementUpdate' */
  DW_MovingAverage_motorRPMTest_T MovingAverage_p;/* '<S62>/Moving Average' */
  DW_MovingAverage_motorRPMTest_T MovingAverage;/* '<S62>/Moving Average' */
} DW_motorRPMTest_T;

/* Parameters (default storage) */
struct P_motorRPMTest_T_ {
  real_T k_motor;                      /* Variable: k_motor
                                        * Referenced by: '<S6>/Current to Torque'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S95>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S98>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S90>/Kb'
                                        */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S105>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S103>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S105>/Saturation'
                               */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S58>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S60>/deltax'
                                        */
  real_T A_Value[16];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S2>/A'
                                        */
  real_T KalmanGainM_Value[8];         /* Expression: pInitialization.M
                                        * Referenced by: '<S7>/KalmanGainM'
                                        */
  real_T C_Value[8];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S2>/C'
                                        */
  real_T KalmanGainL_Value[8];         /* Expression: pInitialization.L
                                        * Referenced by: '<S7>/KalmanGainL'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T D_Value[2];                   /* Expression: pInitialization.D
                                        * Referenced by: '<S2>/D'
                                        */
  real_T X0_Value[4];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S2>/X0'
                                        */
  real_T B_Value[4];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S2>/B'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T CovarianceZ_Value[16];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S7>/CovarianceZ'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S98>/Integrator'
                                        */
  real_T Constant2_Value_b;            /* Expression: 389
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T DeadZone1_Start;              /* Expression: -1
                                        * Referenced by: '<S6>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: 1
                                        * Referenced by: '<S6>/Dead Zone1'
                                        */
  real_T Constant1_Value_m;            /* Expression: 388
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
  int32_T TickstoRPM_Gain;             /* Computed Parameter: TickstoRPM_Gain
                                        * Referenced by: '<S62>/Ticks to RPM'
                                        */
  uint16_T Volt2Rad_Gain;              /* Computed Parameter: Volt2Rad_Gain
                                        * Referenced by: '<Root>/Volt2Rad'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S2>/Enable'
                                        */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S56>/isSqrtUsed'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motorRPMTest_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_motorRPMTest_T motorRPMTest_P;

/* Block signals (default storage) */
extern B_motorRPMTest_T motorRPMTest_B;

/* Block states (default storage) */
extern DW_motorRPMTest_T motorRPMTest_DW;

/* Model entry point functions */
extern void motorRPMTest_initialize(void);
extern void motorRPMTest_step(void);
extern void motorRPMTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motorRPMTest_T *const motorRPMTest_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Diplay1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Conversion' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Conversion' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/G' : Unused code path elimination
 * Block '<S2>/H' : Unused code path elimination
 * Block '<S2>/N' : Unused code path elimination
 * Block '<S2>/P0' : Unused code path elimination
 * Block '<S2>/Q' : Unused code path elimination
 * Block '<S2>/R' : Unused code path elimination
 * Block '<S48>/CheckSignalProperties' : Unused code path elimination
 * Block '<S49>/CheckSignalProperties' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Position Integration' : Unused code path elimination
 * Block '<S4>/RPM to rad//s' : Unused code path elimination
 * Block '<S4>/rad//s to m//s' : Unused code path elimination
 * Block '<S50>/Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Reshape' : Reshape block reduction
 * Block '<S2>/ReshapeX0' : Reshape block reduction
 * Block '<S2>/Reshapeu' : Reshape block reduction
 * Block '<S2>/Reshapexhat' : Reshape block reduction
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
 * '<Root>' : 'motorRPMTest'
 * '<S1>'   : 'motorRPMTest/Discrete Derivative'
 * '<S2>'   : 'motorRPMTest/Kalman Filter'
 * '<S3>'   : 'motorRPMTest/MATLAB Function'
 * '<S4>'   : 'motorRPMTest/Motor Controller'
 * '<S5>'   : 'motorRPMTest/Pin Setup'
 * '<S6>'   : 'motorRPMTest/Torque Measurement'
 * '<S7>'   : 'motorRPMTest/Kalman Filter/CalculatePL'
 * '<S8>'   : 'motorRPMTest/Kalman Filter/CalculateYhat'
 * '<S9>'   : 'motorRPMTest/Kalman Filter/CovarianceOutputConfigurator'
 * '<S10>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionA'
 * '<S11>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionB'
 * '<S12>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionC'
 * '<S13>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionD'
 * '<S14>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionEnable'
 * '<S15>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionG'
 * '<S16>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionH'
 * '<S17>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionN'
 * '<S18>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionP'
 * '<S19>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionP0'
 * '<S20>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionQ'
 * '<S21>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionR'
 * '<S22>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionReset'
 * '<S23>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionX'
 * '<S24>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionX0'
 * '<S25>'  : 'motorRPMTest/Kalman Filter/DataTypeConversionu'
 * '<S26>'  : 'motorRPMTest/Kalman Filter/MemoryP'
 * '<S27>'  : 'motorRPMTest/Kalman Filter/Observer'
 * '<S28>'  : 'motorRPMTest/Kalman Filter/ReducedQRN'
 * '<S29>'  : 'motorRPMTest/Kalman Filter/Reset'
 * '<S30>'  : 'motorRPMTest/Kalman Filter/Reshapeyhat'
 * '<S31>'  : 'motorRPMTest/Kalman Filter/ScalarExpansionP0'
 * '<S32>'  : 'motorRPMTest/Kalman Filter/ScalarExpansionQ'
 * '<S33>'  : 'motorRPMTest/Kalman Filter/ScalarExpansionR'
 * '<S34>'  : 'motorRPMTest/Kalman Filter/UseCurrentEstimator'
 * '<S35>'  : 'motorRPMTest/Kalman Filter/checkA'
 * '<S36>'  : 'motorRPMTest/Kalman Filter/checkB'
 * '<S37>'  : 'motorRPMTest/Kalman Filter/checkC'
 * '<S38>'  : 'motorRPMTest/Kalman Filter/checkD'
 * '<S39>'  : 'motorRPMTest/Kalman Filter/checkEnable'
 * '<S40>'  : 'motorRPMTest/Kalman Filter/checkG'
 * '<S41>'  : 'motorRPMTest/Kalman Filter/checkH'
 * '<S42>'  : 'motorRPMTest/Kalman Filter/checkN'
 * '<S43>'  : 'motorRPMTest/Kalman Filter/checkP0'
 * '<S44>'  : 'motorRPMTest/Kalman Filter/checkQ'
 * '<S45>'  : 'motorRPMTest/Kalman Filter/checkR'
 * '<S46>'  : 'motorRPMTest/Kalman Filter/checkReset'
 * '<S47>'  : 'motorRPMTest/Kalman Filter/checkX0'
 * '<S48>'  : 'motorRPMTest/Kalman Filter/checku'
 * '<S49>'  : 'motorRPMTest/Kalman Filter/checky'
 * '<S50>'  : 'motorRPMTest/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S51>'  : 'motorRPMTest/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S52>'  : 'motorRPMTest/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S53>'  : 'motorRPMTest/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S54>'  : 'motorRPMTest/Kalman Filter/CalculatePL/Ground'
 * '<S55>'  : 'motorRPMTest/Kalman Filter/CalculateYhat/Ground'
 * '<S56>'  : 'motorRPMTest/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S57>'  : 'motorRPMTest/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S58>'  : 'motorRPMTest/Kalman Filter/Observer/MeasurementUpdate'
 * '<S59>'  : 'motorRPMTest/Kalman Filter/ReducedQRN/Ground'
 * '<S60>'  : 'motorRPMTest/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S61>'  : 'motorRPMTest/Motor Controller/PID Controller'
 * '<S62>'  : 'motorRPMTest/Motor Controller/RPM Measurement'
 * '<S63>'  : 'motorRPMTest/Motor Controller/Select PWM Direction'
 * '<S64>'  : 'motorRPMTest/Motor Controller/PID Controller/Anti-windup'
 * '<S65>'  : 'motorRPMTest/Motor Controller/PID Controller/D Gain'
 * '<S66>'  : 'motorRPMTest/Motor Controller/PID Controller/External Derivative'
 * '<S67>'  : 'motorRPMTest/Motor Controller/PID Controller/Filter'
 * '<S68>'  : 'motorRPMTest/Motor Controller/PID Controller/Filter ICs'
 * '<S69>'  : 'motorRPMTest/Motor Controller/PID Controller/I Gain'
 * '<S70>'  : 'motorRPMTest/Motor Controller/PID Controller/Ideal P Gain'
 * '<S71>'  : 'motorRPMTest/Motor Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S72>'  : 'motorRPMTest/Motor Controller/PID Controller/Integrator'
 * '<S73>'  : 'motorRPMTest/Motor Controller/PID Controller/Integrator ICs'
 * '<S74>'  : 'motorRPMTest/Motor Controller/PID Controller/N Copy'
 * '<S75>'  : 'motorRPMTest/Motor Controller/PID Controller/N Gain'
 * '<S76>'  : 'motorRPMTest/Motor Controller/PID Controller/P Copy'
 * '<S77>'  : 'motorRPMTest/Motor Controller/PID Controller/Parallel P Gain'
 * '<S78>'  : 'motorRPMTest/Motor Controller/PID Controller/Reset Signal'
 * '<S79>'  : 'motorRPMTest/Motor Controller/PID Controller/Saturation'
 * '<S80>'  : 'motorRPMTest/Motor Controller/PID Controller/Saturation Fdbk'
 * '<S81>'  : 'motorRPMTest/Motor Controller/PID Controller/Sum'
 * '<S82>'  : 'motorRPMTest/Motor Controller/PID Controller/Sum Fdbk'
 * '<S83>'  : 'motorRPMTest/Motor Controller/PID Controller/Tracking Mode'
 * '<S84>'  : 'motorRPMTest/Motor Controller/PID Controller/Tracking Mode Sum'
 * '<S85>'  : 'motorRPMTest/Motor Controller/PID Controller/Tsamp - Integral'
 * '<S86>'  : 'motorRPMTest/Motor Controller/PID Controller/Tsamp - Ngain'
 * '<S87>'  : 'motorRPMTest/Motor Controller/PID Controller/postSat Signal'
 * '<S88>'  : 'motorRPMTest/Motor Controller/PID Controller/preInt Signal'
 * '<S89>'  : 'motorRPMTest/Motor Controller/PID Controller/preSat Signal'
 * '<S90>'  : 'motorRPMTest/Motor Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S91>'  : 'motorRPMTest/Motor Controller/PID Controller/D Gain/Disabled'
 * '<S92>'  : 'motorRPMTest/Motor Controller/PID Controller/External Derivative/Disabled'
 * '<S93>'  : 'motorRPMTest/Motor Controller/PID Controller/Filter/Disabled'
 * '<S94>'  : 'motorRPMTest/Motor Controller/PID Controller/Filter ICs/Disabled'
 * '<S95>'  : 'motorRPMTest/Motor Controller/PID Controller/I Gain/Internal Parameters'
 * '<S96>'  : 'motorRPMTest/Motor Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S97>'  : 'motorRPMTest/Motor Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'motorRPMTest/Motor Controller/PID Controller/Integrator/Discrete'
 * '<S99>'  : 'motorRPMTest/Motor Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S100>' : 'motorRPMTest/Motor Controller/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S101>' : 'motorRPMTest/Motor Controller/PID Controller/N Gain/Disabled'
 * '<S102>' : 'motorRPMTest/Motor Controller/PID Controller/P Copy/Disabled'
 * '<S103>' : 'motorRPMTest/Motor Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S104>' : 'motorRPMTest/Motor Controller/PID Controller/Reset Signal/Disabled'
 * '<S105>' : 'motorRPMTest/Motor Controller/PID Controller/Saturation/Enabled'
 * '<S106>' : 'motorRPMTest/Motor Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S107>' : 'motorRPMTest/Motor Controller/PID Controller/Sum/Sum_PI'
 * '<S108>' : 'motorRPMTest/Motor Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S109>' : 'motorRPMTest/Motor Controller/PID Controller/Tracking Mode/Disabled'
 * '<S110>' : 'motorRPMTest/Motor Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'motorRPMTest/Motor Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S112>' : 'motorRPMTest/Motor Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'motorRPMTest/Motor Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S114>' : 'motorRPMTest/Motor Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S115>' : 'motorRPMTest/Motor Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S116>' : 'motorRPMTest/Motor Controller/RPM Measurement/Filter for data dropouts'
 * '<S117>' : 'motorRPMTest/Torque Measurement/MATLAB Function'
 */
#endif                                 /* motorRPMTest_h_ */
