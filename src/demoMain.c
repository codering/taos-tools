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

#include "demo.h"
int64_t        g_totalChildTables = DEFAULT_CHILDTABLES;
int64_t        g_actualChildTables = 0;
FILE *         g_fpOfInsertResult = NULL;
char *         g_dupstr = NULL;
SDbs           g_Dbs;
SQueryMetaInfo g_queryInfo;
bool           g_fail = false;
SArguments     g_args;

int main(int argc, char *argv[]) {
    init_g_args(&g_args);
    if (parse_args(argc, argv, &g_args)) {
        exit(EXIT_FAILURE);
    }
    debugPrint("meta file: %s\n", g_args.metaFile);

    if (g_args.metaFile) {
        g_totalChildTables = 0;
        if (getInfoFromJsonFile(g_args.metaFile)) {
            exit(EXIT_FAILURE);
        }
        if (testMetaFile()) {
            exit(EXIT_FAILURE);
        }
    } else {
        memset(&g_Dbs, 0, sizeof(SDbs));
        g_Dbs.db = calloc(1, sizeof(SDataBase));
        if (NULL == g_Dbs.db) {
            errorPrint("%s", "failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }

        g_Dbs.db[0].superTbls = calloc(1, sizeof(SSuperTable));
        if (NULL == g_Dbs.db[0].superTbls) {
            errorPrint("%s", "failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }

        setParaFromArg(&g_args);

        if (NULL != g_args.sqlFile) {
            if (querySqlFile(&g_args, g_args.sqlFile)) {
                exit(EXIT_FAILURE);
            }
        } else {
            testCmdLine(&g_args);
        }
    }
    postFreeResource();

    return 0;
}