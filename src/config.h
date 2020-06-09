/*
* Copyright 2018-2020 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#pragma once

#include "redismodule.h"
#define VKEY_ENTITY_COUNT_UNLIMITED UINT64_MAX

typedef struct {
	int omp_thread_count;        // Maximum number of OpenMP threads.
	int thread_count;            // Thread count for thread pool.
	uint64_t vkey_entity_count;  // The limit of number of entities encoded at once for each RDB key.
} RG_Config;

// Set module-level configurations to defaults or to user arguments where provided.
// Returns REDISMODULE_OK on success, emits an error and returns REDISMODULE_ERR on failure.
int Config_Init(RedisModuleCtx *ctx, RedisModuleString **argv, int argc);

// Return the module thread pool size.
int Config_GetThreadCount(void);

// Return the max number of OpenMP threads or -1 if using the default value.
int Config_GetOMPThreadCount(void);

// Return the module virtual key entity limit.
uint64_t Config_GetVirtualKeyEntityCount(void);

