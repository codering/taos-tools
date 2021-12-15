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
#include <unistd.h>
#include "CUnit/Basic.h"
#include "demo.h"
#include "demoData.h"

#define MAX_DESCRIPTION_LEN 1024
SArguments   test_g_args;
SSuperTable* test_stbInfo;

char* test_description(char* description, char* author, char* function,
                       char* text) {
    snprintf(description, MAX_DESCRIPTION_LEN,
             "%s()\n\tAuthor: %s\n\tDescription: %s\n\tResult:", function,
             author, text);
    return description;
}
int init_command_opt(void) {
    init_g_args(&test_g_args);
    return 0;
}
int clean_command_opt(void) {
    clean_g_args(&test_g_args);
    return 0;
}

void reload_g_args(void) {
    clean_g_args(&test_g_args);
    init_g_args(&test_g_args);
}
int init_data(void) {
    g_data_size = 3;
    init_rand_data();
    init_g_args(&test_g_args);
    test_stbInfo = calloc(1, sizeof(SSuperTable));
    test_stbInfo->tags[0].data_type = TSDB_DATA_TYPE_TIMESTAMP;
    test_stbInfo->tags[1].data_type = TSDB_DATA_TYPE_INT;
    test_stbInfo->tags[2].data_type = TSDB_DATA_TYPE_BIGINT;
    test_stbInfo->tags[3].data_type = TSDB_DATA_TYPE_FLOAT;
    test_stbInfo->tags[4].data_type = TSDB_DATA_TYPE_DOUBLE;
    test_stbInfo->tags[5].data_type = TSDB_DATA_TYPE_BINARY;
    test_stbInfo->tags[6].data_type = TSDB_DATA_TYPE_SMALLINT;
    test_stbInfo->tags[7].data_type = TSDB_DATA_TYPE_TINYINT;
    test_stbInfo->tags[8].data_type = TSDB_DATA_TYPE_BOOL;
    test_stbInfo->tags[9].data_type = TSDB_DATA_TYPE_NCHAR;
    test_stbInfo->tags[10].data_type = TSDB_DATA_TYPE_UTINYINT;
    test_stbInfo->tags[11].data_type = TSDB_DATA_TYPE_USMALLINT;
    test_stbInfo->tags[12].data_type = TSDB_DATA_TYPE_UINT;
    test_stbInfo->tags[13].data_type = TSDB_DATA_TYPE_UBIGINT;
    test_stbInfo->tags[0].dataLen = sizeof(int64_t);
    test_stbInfo->tags[1].dataLen = sizeof(int32_t);
    test_stbInfo->tags[2].dataLen = sizeof(int64_t);
    test_stbInfo->tags[3].dataLen = sizeof(float);
    test_stbInfo->tags[4].dataLen = sizeof(double);
    test_stbInfo->tags[5].dataLen = test_g_args.binwidth;
    test_stbInfo->tags[6].dataLen = sizeof(int16_t);
    test_stbInfo->tags[7].dataLen = sizeof(int8_t);
    test_stbInfo->tags[8].dataLen = sizeof(int8_t);
    test_stbInfo->tags[9].dataLen = test_g_args.binwidth;
    test_stbInfo->tags[10].dataLen = sizeof(int8_t);
    test_stbInfo->tags[11].dataLen = sizeof(int16_t);
    test_stbInfo->tags[12].dataLen = sizeof(int32_t);
    test_stbInfo->tags[13].dataLen = sizeof(int64_t);
    test_stbInfo->columns[0].data_type = TSDB_DATA_TYPE_TIMESTAMP;
    test_stbInfo->columns[1].data_type = TSDB_DATA_TYPE_INT;
    test_stbInfo->columns[2].data_type = TSDB_DATA_TYPE_BIGINT;
    test_stbInfo->columns[3].data_type = TSDB_DATA_TYPE_FLOAT;
    test_stbInfo->columns[4].data_type = TSDB_DATA_TYPE_DOUBLE;
    test_stbInfo->columns[5].data_type = TSDB_DATA_TYPE_BINARY;
    test_stbInfo->columns[6].data_type = TSDB_DATA_TYPE_SMALLINT;
    test_stbInfo->columns[7].data_type = TSDB_DATA_TYPE_TINYINT;
    test_stbInfo->columns[8].data_type = TSDB_DATA_TYPE_BOOL;
    test_stbInfo->columns[9].data_type = TSDB_DATA_TYPE_NCHAR;
    test_stbInfo->columns[10].data_type = TSDB_DATA_TYPE_UTINYINT;
    test_stbInfo->columns[11].data_type = TSDB_DATA_TYPE_USMALLINT;
    test_stbInfo->columns[12].data_type = TSDB_DATA_TYPE_UINT;
    test_stbInfo->columns[13].data_type = TSDB_DATA_TYPE_UBIGINT;
    test_stbInfo->columns[0].dataLen = sizeof(int64_t);
    test_stbInfo->columns[1].dataLen = sizeof(int32_t);
    test_stbInfo->columns[2].dataLen = sizeof(int64_t);
    test_stbInfo->columns[3].dataLen = sizeof(float);
    test_stbInfo->columns[4].dataLen = sizeof(double);
    test_stbInfo->columns[5].dataLen = test_g_args.binwidth;
    test_stbInfo->columns[6].dataLen = sizeof(int16_t);
    test_stbInfo->columns[7].dataLen = sizeof(int8_t);
    test_stbInfo->columns[8].dataLen = sizeof(int8_t);
    test_stbInfo->columns[9].dataLen = test_g_args.binwidth;
    test_stbInfo->columns[10].dataLen = sizeof(int8_t);
    test_stbInfo->columns[11].dataLen = sizeof(int16_t);
    test_stbInfo->columns[12].dataLen = sizeof(int32_t);
    test_stbInfo->columns[13].dataLen = sizeof(int64_t);
    return 0;
}
int clean_data(void) {
    clean_g_args(&test_g_args);
    clean_rand_data();
    tmfree(test_stbInfo);
    return 0;
}

void testPARSE_ARGS(void) {
    /*file*/
    char* args_f[3] = {"taosdemo", "-f", "non-exist.json"};
    CU_ASSERT_PTR_NULL(test_g_args.metaFile);
    CU_ASSERT_EQUAL(parse_args(3, args_f, &test_g_args), 0);
    CU_ASSERT_STRING_EQUAL(test_g_args.metaFile, "non-exist.json");
    reload_g_args();
    char* args_ff[2] = {"taosdemo", "-fnon-exist.json"};
    CU_ASSERT_PTR_NULL(test_g_args.metaFile);
    CU_ASSERT_EQUAL(parse_args(2, args_ff, &test_g_args), 0);
    CU_ASSERT_STRING_EQUAL(test_g_args.metaFile, "non-exist.json");
    reload_g_args();
    char* args_file[3] = {"taosdemo", "--file", "non-exist.json"};
    CU_ASSERT_PTR_NULL(test_g_args.metaFile);
    CU_ASSERT_EQUAL(parse_args(3, args_file, &test_g_args), 0);
    CU_ASSERT_STRING_EQUAL(test_g_args.metaFile, "non-exist.json");
    reload_g_args();
    char* args_ffile[2] = {"taosdemo", "--file=non-exist.json"};
    CU_ASSERT_PTR_NULL(test_g_args.metaFile);
    CU_ASSERT_EQUAL(parse_args(2, args_ffile, &test_g_args), 0);
    CU_ASSERT_STRING_EQUAL(test_g_args.metaFile, "non-exist.json");
    reload_g_args();
    /*escape character*/
    char* args_E[2] = {"taosdemo", "-E"};
    CU_ASSERT_FALSE(test_g_args.escapeChar);
    CU_ASSERT_EQUAL(parse_args(2, args_E, &test_g_args), 0);
    CU_ASSERT_TRUE(test_g_args.escapeChar);
    reload_g_args();
    char* args_escape[2] = {"taosdemo", "--escape-character"};
    CU_ASSERT_FALSE(test_g_args.escapeChar);
    CU_ASSERT_EQUAL(parse_args(2, args_escape, &test_g_args), 0);
    CU_ASSERT_TRUE(test_g_args.escapeChar);
}

void testQUERYSQLFILE(void) {
    CU_ASSERT_EQUAL(query_sql_file(&test_g_args, "../test/correct_tmp.sql"), 0);
    CU_ASSERT_EQUAL(query_sql_file(&test_g_args, "../test/wrong_tmp.sql"), -1);
}

void testGENERATETAGS(void) {
    char* tag_buffer = calloc(1, TSDB_MAX_SQL_LEN);
    test_stbInfo->tagCount = 14;
    CU_ASSERT_EQUAL(generate_sql_tags(test_stbInfo, 0, tag_buffer), 0);
    test_stbInfo->tagCount = 15;
    test_stbInfo->tags[14].data_type = 100;
    CU_ASSERT_EQUAL(generate_sql_tags(test_stbInfo, 0, tag_buffer), -1);
    test_stbInfo->tags[0].data_type = TSDB_DATA_TYPE_JSON;
    test_stbInfo->tags[0].dataLen = 8;
    CU_ASSERT_EQUAL(generate_sql_tags(test_stbInfo, 0, tag_buffer), 0);
    tmfree(tag_buffer);
}

void testPREPAREDATAFROMCSV(void) {
    test_stbInfo->length_of_cols = 3 * INT_BUFF_LEN;
    test_stbInfo->sampleDataBuf =
        calloc(1, test_stbInfo->length_of_cols * g_data_size);
    strncpy(test_stbInfo->sampleFile, "non-exist.csv", MAX_FILE_NAME_LEN);
    CU_ASSERT_EQUAL(prepare_data_from_csv(test_stbInfo), -1);
    memset(test_stbInfo->sampleFile, 0, MAX_FILE_NAME_LEN);
    strncpy(test_stbInfo->sampleFile, "../test/test.csv", MAX_FILE_NAME_LEN);
    CU_ASSERT_EQUAL(prepare_data_from_csv(test_stbInfo), 0);
    CU_ASSERT_STRING_EQUAL(test_stbInfo->sampleDataBuf, "1,2,3");
    CU_ASSERT_STRING_EQUAL(
        test_stbInfo->sampleDataBuf + test_stbInfo->length_of_cols, "1,2,3");
    CU_ASSERT_STRING_EQUAL(
        test_stbInfo->sampleDataBuf + 2 * test_stbInfo->length_of_cols,
        "1,2,3");
    tmfree(test_stbInfo->sampleDataBuf);
}

void testCALCULATEROWLENGTH(void ) {
    test_stbInfo->tagCount = 14;
    test_stbInfo->columnCount = 14;
    CU_ASSERT_EQUAL(calculate_row_length(test_stbInfo), 0);
    test_stbInfo->tagCount = 15;
    test_stbInfo->tags[14].data_type = 100;
    CU_ASSERT_EQUAL(calculate_row_length(test_stbInfo), -1);
    test_stbInfo->tagCount = 14;
    test_stbInfo->columnCount = 15;
    test_stbInfo->columns[14].data_type = 100;
    CU_ASSERT_EQUAL(calculate_row_length(test_stbInfo), -1);
}
int main() {
    CU_pSuite demoCommandOpt = NULL;
    CU_pSuite demoData = NULL;
    CU_pSuite demoInsert = NULL;
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
    demoCommandOpt =
        CU_add_suite("demoCommandOpt.c", init_command_opt, clean_command_opt);
    demoData = CU_add_suite("demoData.c", init_data, clean_data);
    demoInsert = CU_add_suite("demoInsert.c", init_data, clean_data);
    if ((NULL == demoCommandOpt) || (NULL == demoData) || (NULL == demoInsert)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    /* add the tests to the suite */
    char parse_args_description[MAX_DESCRIPTION_LEN];
    char query_sql_file[MAX_DESCRIPTION_LEN];
    char generate_sql_tags[MAX_DESCRIPTION_LEN];
    // char generate_sql_cols[MAX_DESCRIPTION_LEN];
    char prepare_data_from_csv[MAX_DESCRIPTION_LEN];
    char calculate_row_length[MAX_DESCRIPTION_LEN];
    if ((NULL ==
         CU_add_test(
             demoCommandOpt,
             test_description(
                 parse_args_description, "zhaoyang", "parse_args",
                 "This function read options from cmdline, verified and set "
                 "up"),
             testPARSE_ARGS)) ||
        (NULL ==
         CU_add_test(demoCommandOpt,
                     test_description(
                         query_sql_file, "zhaoyang", "query_sql_file",
                         "This function read sql file and execute the command"),
                     testQUERYSQLFILE)) ||
        (NULL ==
         CU_add_test(demoData,
                     test_description(
                         generate_sql_tags, "zhaoyang", "generate_sql_tags",
                         "This function generate random tag field"),
                     testGENERATETAGS)) ||
        (NULL ==
         CU_add_test(
             demoData,
             test_description(
                 prepare_data_from_csv, "zhaoyang", "prepare_data_from_csv",
                 "This function read and set data source from csv"),
             testPREPAREDATAFROMCSV))||
        (NULL ==
         CU_add_test(
             demoInsert,
             test_description(
                 calculate_row_length, "zhaoyang", "calculate_row_length",
                 "This function calculate both cols and tags length"),
             testCALCULATEROWLENGTH))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
