//
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit drugs_OnGameModeInit
#if defined drugs_OnGameModeInit
	forward drugs_OnGameModeInit();
#endif