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

#define MAX_DESCRIPTION_LEN 1024
SArguments test_g_args;

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
    CU_ASSERT_EQUAL(querySqlFile(&test_g_args, "../test/correct_tmp.sql"), 0);
    CU_ASSERT_EQUAL(querySqlFile(&test_g_args, "../test/wrong_tmp.sql"), -1);
}

int main() {
    CU_pSuite demoCommandOpt = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
    demoCommandOpt =
        CU_add_suite("demoCommandOpt.c", init_command_opt, clean_command_opt);
    if (NULL == demoCommandOpt) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    char parse_args_description[MAX_DESCRIPTION_LEN];
    if ((NULL ==
         CU_add_test(demoCommandOpt,
                     test_description(
                         parse_args_description, "zhaoyang", "parse_args",
                         "This function read arguments from cmdline and save "
                         "the argument info to the global variable g_args"),
                     testPARSE_ARGS))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
