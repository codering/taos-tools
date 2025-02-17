/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the MIT license as published by the Free Software
 * Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DEMODATA__
#define __DEMODATA__

#include "bench.h"
/***** Global variables ******/
/***** Declare functions *****/
int64_t getTSRandTail(int64_t timeStampStep, int32_t seq, int disorderRatio,
                      int disorderRange);
void    generateRandData(SSuperTable *stbInfo, char *sampleDataBuf,
                         int lenOfOneRow, Column *columns, int count, int loop,
                         bool tag);
void    generateStmtBuffer(SSuperTable *stbInfo);
int bindParamBatch(threadInfo *pThreadInfo, uint32_t batch, int64_t startTime);
int prepare_sample_data(int a, int b);
int32_t generateSmlJsonTags(cJSON *tagsList, SSuperTable *stbInfo,
                            uint64_t start_table_from, int tbSeq);
int32_t generateSmlJsonCols(cJSON *array, cJSON *tag, SSuperTable *stbInfo,
                            uint32_t time_precision, int64_t timestamp);
#endif