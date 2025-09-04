#ifndef EXT_MODE_TYPES_H
#define EXT_MODE_TYPES_H
#include "rtwtypes.h"

typedef uint16_T extmodeEventId_T;
typedef uint32_T extmodeRealTime_T;
typedef uint32_T extmodeSimulationTime_T;
typedef real_T extmodeDouble_T;
typedef real_T extmodeClassicTriggerSignal_T;

#define EXTMODE_SIMULATION_RUN_FOREVER ((extmodeSimulationTime_T) -1)
#define XCP_UINT32_MAX                 0xFFFFFFFFU
#define MAX_extmodeSimulationTime_T    XCP_UINT32_MAX
#define EXTMODE_MAX_BASE_RATE_SIMULATION_TIME XCP_UINT32_MAX
#define EXTMODE_STEP_SIZE_IN_MICROSECONDS 10000
#define EXTMODE_BASE_RATE_EVENT_ID     0
#define EXTMODE_MAX_EVENT_ID           0xFF
#endif

