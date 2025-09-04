#ifndef KalmanFilterTest_private_h_
#define KalmanFilterTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "KalmanFilterTest_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

#endif
