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

#include <stdio.h>
#include <string.h>
#include "../inc/demo.h"
#include "CUnit/Basic.h"

SArguments test_g_args;
int        init_suite1(void) {
    test_g_args.metaFile = DEFAULT_METAFILE;
    test_g_args.test_mode = DEFAULT_TEST_MODE;
    test_g_args.host = DEFAULT_HOST;
    test_g_args.port = DEFAULT_PORT;
    test_g_args.iface = DEFAULT_IFACE;
    test_g_args.user = TSDB_DEFAULT_USER;
    strcpy(test_g_args.password, TSDB_DEFAULT_PASS);
    test_g_args.database = DEFAULT_DATABASE;
    test_g_args.replica = DEFAULT_REPLICA;
    test_g_args.tb_prefix = DEFAULT_TB_PREFIX;
    test_g_args.escapeChar = DEFAULT_ESCAPE_CHAR;
    test_g_args.sqlFile = DEFAULT_SQLFILE;
    test_g_args.use_metric = DEFAULT_USE_METRIC;
    test_g_args.drop_database = DEFAULT_DROP_DB;
    test_g_args.aggr_func = DEFAULT_AGGR_FUNC;
    test_g_args.debug_print = DEFAULT_DEBUG;
    test_g_args.verbose_print = DEFAULT_VERBOSE;
    test_g_args.performance_print = DEFAULT_PERF_STAT;
    test_g_args.answer_yes = DEFAULT_ANS_YES;
    test_g_args.output_file = DEFAULT_OUTPUT;
    test_g_args.async_mode = DEFAULT_SYNC_MODE;
    test_g_args.data_type[0] = TSDB_DATA_TYPE_FLOAT;
    test_g_args.data_type[1] = TSDB_DATA_TYPE_INT;
    test_g_args.data_type[2] = TSDB_DATA_TYPE_FLOAT;
    strcpy(test_g_args.dataType[0], "FLOAT");
    strcpy(test_g_args.dataType[1], "INT");
    strcpy(test_g_args.dataType[2], "FLOAT");
    test_g_args.data_length[0] = 4;
    test_g_args.data_length[1] = 4;
    test_g_args.data_length[2] = 4;
    test_g_args.binwidth = DEFAULT_BINWIDTH;
    test_g_args.columnCount = DEFAULT_COL_COUNT;
    test_g_args.lenOfOneRow = DEFAULT_LEN_ONE_ROW;
    test_g_args.nthreads = DEFAULT_NTHREADS;
    test_g_args.insert_interval = DEFAULT_INSERT_INTERVAL;
    test_g_args.timestamp_step = DEFAULT_TIMESTAMP_STEP;
    test_g_args.query_times = DEFAULT_QUERY_TIME;
    test_g_args.prepared_rand = DEFAULT_PREPARED_RAND;
    test_g_args.interlaceRows = DEFAULT_INTERLACE_ROWS;
    test_g_args.reqPerReq = DEFAULT_REQ_PER_REQ;
    test_g_args.max_sql_len = TSDB_MAX_ALLOWED_SQL_LEN;
    test_g_args.ntables = DEFAULT_CHILDTABLES;
    test_g_args.insertRows = DEFAULT_INSERT_ROWS;
    test_g_args.abort = DEFAULT_ABORT;
    test_g_args.disorderRatio = DEFAULT_RATIO;
    test_g_args.disorderRange = DEFAULT_DISORDER_RANGE;
    test_g_args.method_of_delete = DEFAULT_METHOD_DEL;
    test_g_args.totalInsertRows = DEFAULT_TOTAL_INSERT;
    test_g_args.totalAffectedRows = DEFAULT_TOTAL_AFFECT;
    test_g_args.demo_mode = DEFAULT_DEMO_MODE;
    test_g_args.chinese = DEFAULT_CHINESE_OPT;
    test_g_args.pressure_mode = DEFAULT_PRESSURE_MODE;
}
int  clean_suite1(void) { return 0; }
void testPARSE_ARGS(void) {
    char* args[2] = {"taosdemo", "-E"};
    CU_ASSERT_EQUAL(parse_args(2, args, &test_g_args), 0)
}

int main() {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("demoCommandOpt.c", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite, "test of parse_args()", testPARSE_ARGS))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
