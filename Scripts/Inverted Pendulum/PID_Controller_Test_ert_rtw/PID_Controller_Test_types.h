/*
 * PID_Controller_Test_types.h
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

#ifndef PID_Controller_Test_types_h_
#define PID_Controller_Test_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S3>/PWM1' */
#include "MW_SVD.h"
#ifndef struct_tag_pMPPJgn69ckPBhypf3vQzD
#define struct_tag_pMPPJgn69ckPBhypf3vQzD

struct tag_pMPPJgn69ckPBhypf3vQzD
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_pMPPJgn69ckPBhypf3vQzD */

#ifndef typedef_e_arduinodriver_ArduinoAnalog_T
#define typedef_e_arduinodriver_ArduinoAnalog_T

typedef struct tag_pMPPJgn69ckPBhypf3vQzD e_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_e_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_FIY6N64L77TlG9jHBRqBuB
#define struct_tag_FIY6N64L77TlG9jHBRqBuB

struct tag_FIY6N64L77TlG9jHBRqBuB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
};

#endif                                 /* struct_tag_FIY6N64L77TlG9jHBRqBuB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_FIY6N64L77TlG9jHBRqBuB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_7VFuPw0vSNrn5pRgG8Mc4C
#define struct_tag_7VFuPw0vSNrn5pRgG8Mc4C

struct tag_7VFuPw0vSNrn5pRgG8Mc4C
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_7VFuPw0vSNrn5pRgG8Mc4C */

#ifndef typedef_e_matlabshared_ioclient_perip_T
#define typedef_e_matlabshared_ioclient_perip_T

typedef struct tag_7VFuPw0vSNrn5pRgG8Mc4C e_matlabshared_ioclient_perip_T;

#endif                             /* typedef_e_matlabshared_ioclient_perip_T */

#ifndef struct_tag_RWocY1aAVmuibq0rYX5t0G
#define struct_tag_RWocY1aAVmuibq0rYX5t0G

struct tag_RWocY1aAVmuibq0rYX5t0G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_RWocY1aAVmuibq0rYX5t0G */

#ifndef typedef_codertarget_arduinobase_int_l_T
#define typedef_codertarget_arduinobase_int_l_T

typedef struct tag_RWocY1aAVmuibq0rYX5t0G codertarget_arduinobase_int_l_T;

#endif                             /* typedef_codertarget_arduinobase_int_l_T */

#ifndef struct_tag_FHZ7JioS7qem7UEAKh2LfE
#define struct_tag_FHZ7JioS7qem7UEAKh2LfE

struct tag_FHZ7JioS7qem7UEAKh2LfE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  uint8_T Index;
};

#endif                                 /* struct_tag_FHZ7JioS7qem7UEAKh2LfE */

#ifndef typedef_codertarget_arduinobase_in_li_T
#define typedef_codertarget_arduinobase_in_li_T

typedef struct tag_FHZ7JioS7qem7UEAKh2LfE codertarget_arduinobase_in_li_T;

#endif                             /* typedef_codertarget_arduinobase_in_li_T */

#ifndef struct_tag_bpMNyLZPCJBeBnOB7xlwFB
#define struct_tag_bpMNyLZPCJBeBnOB7xlwFB

struct tag_bpMNyLZPCJBeBnOB7xlwFB
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_bpMNyLZPCJBeBnOB7xlwFB */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_bpMNyLZPCJBeBnOB7xlwFB b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_ldqgYDWP5Rq6U8J4ptL7cG
#define struct_tag_ldqgYDWP5Rq6U8J4ptL7cG

struct tag_ldqgYDWP5Rq6U8J4ptL7cG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_ldqgYDWP5Rq6U8J4ptL7cG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_ldqgYDWP5Rq6U8J4ptL7cG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_PID_Controller_Test_T
#define typedef_cell_wrap_PID_Controller_Test_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_PID_Controller_Test_T;

#endif                             /* typedef_cell_wrap_PID_Controller_Test_T */

#ifndef struct_tag_laADuevm1AHrIKTY1CrXlG
#define struct_tag_laADuevm1AHrIKTY1CrXlG

struct tag_laADuevm1AHrIKTY1CrXlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PID_Controller_Test_T inputVarSize;
  int32_T NumChannels;
  int32_T FrameLength;
  real_T pCumSum;
  real_T pCumSumRev[11];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_laADuevm1AHrIKTY1CrXlG */

#ifndef typedef_dsp_simulink_MovingAverage_PI_T
#define typedef_dsp_simulink_MovingAverage_PI_T

typedef struct tag_laADuevm1AHrIKTY1CrXlG dsp_simulink_MovingAverage_PI_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_PI_T */

#ifndef struct_tag_JWcuUSYp0PvSKTyOAPxz7G
#define struct_tag_JWcuUSYp0PvSKTyOAPxz7G

struct tag_JWcuUSYp0PvSKTyOAPxz7G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PID_Controller_Test_T inputVarSize;
  int32_T NumChannels;
  int32_T FrameLength;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_JWcuUSYp0PvSKTyOAPxz7G */

#ifndef typedef_dsp_simulink_MovingAverage_l_T
#define typedef_dsp_simulink_MovingAverage_l_T

typedef struct tag_JWcuUSYp0PvSKTyOAPxz7G dsp_simulink_MovingAverage_l_T;

#endif                              /* typedef_dsp_simulink_MovingAverage_l_T */

/* Parameters (default storage) */
typedef struct P_PID_Controller_Test_T_ P_PID_Controller_Test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PID_Controller_Test_T RT_MODEL_PID_Controller_Test_T;

#endif                                 /* PID_Controller_Test_types_h_ */
