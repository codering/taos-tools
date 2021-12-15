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

#include "demoData.h"
#include "demo.h"

char *    g_data_buffer = NULL;
char *    g_sampleBindBatchArray = NULL;
int32_t * g_randint = NULL;
uint32_t *g_randuint = NULL;
int64_t * g_randbigint = NULL;
uint64_t *g_randubigint = NULL;
float *   g_randfloat = NULL;
double *  g_randdouble = NULL;
char *    g_randbool_buff = NULL;
char *    g_randint_buff = NULL;
char *    g_randuint_buff = NULL;
char *    g_rand_voltage_buff = NULL;
char *    g_randbigint_buff = NULL;
char *    g_randubigint_buff = NULL;
char *    g_randsmallint_buff = NULL;
char *    g_randusmallint_buff = NULL;
char *    g_randtinyint_buff = NULL;
char *    g_randutinyint_buff = NULL;
char *    g_randfloat_buff = NULL;
char *    g_rand_current_buff = NULL;
char *    g_rand_phase_buff = NULL;
char *    g_randdouble_buff = NULL;

const char charset[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

char *rand_bool_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randbool_buff + ((cursor % g_data_size) * BOOL_BUFF_LEN);
}

int32_t rand_bool() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randint[cursor % g_data_size] % TSDB_DATA_BOOL_NULL;
}

char *rand_tinyint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randtinyint_buff + ((cursor % g_data_size) * TINYINT_BUFF_LEN);
}

int32_t rand_tinyint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randint[cursor % g_data_size] % TSDB_DATA_TINYINT_NULL;
}

char *rand_utinyint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randutinyint_buff + ((cursor % g_data_size) * TINYINT_BUFF_LEN);
}

int32_t rand_utinyint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randuint[cursor % g_data_size] % TSDB_DATA_UTINYINT_NULL;
}

char *rand_smallint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randsmallint_buff + ((cursor % g_data_size) * SMALLINT_BUFF_LEN);
}

int32_t rand_smallint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randint[cursor % g_data_size] % TSDB_DATA_SMALLINT_NULL;
}

char *rand_usmallint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randusmallint_buff + ((cursor % g_data_size) * SMALLINT_BUFF_LEN);
}

int32_t rand_usmallint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randuint[cursor % g_data_size] % TSDB_DATA_USMALLINT_NULL;
}

char *rand_int_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randint_buff + ((cursor % g_data_size) * INT_BUFF_LEN);
}

int32_t rand_int() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randint[cursor % g_data_size];
}

char *rand_uint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randuint_buff + ((cursor % g_data_size) * INT_BUFF_LEN);
}

int32_t rand_uint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randuint[cursor % g_data_size];
}

char *rand_bigint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randbigint_buff + ((cursor % g_data_size) * BIGINT_BUFF_LEN);
}

int64_t rand_bigint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randbigint[cursor % g_data_size];
}

char *rand_ubigint_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randubigint_buff + ((cursor % g_data_size) * BIGINT_BUFF_LEN);
}

int64_t rand_ubigint() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randubigint[cursor % g_data_size];
}

char *rand_float_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randfloat_buff + ((cursor % g_data_size) * FLOAT_BUFF_LEN);
}

float rand_float() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randfloat[cursor % g_data_size];
}

char *demo_current_float_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_rand_current_buff + ((cursor % g_data_size) * FLOAT_BUFF_LEN);
}

char *demo_voltage_int_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_rand_voltage_buff + ((cursor % g_data_size) * INT_BUFF_LEN);
}

char *demo_phase_float_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_rand_phase_buff + ((cursor % g_data_size) * FLOAT_BUFF_LEN);
}

static int usc2utf8(char *p, int unic) {
    if (unic <= 0x0000007F) {
        *p = (unic & 0x7F);
        return 1;
    } else if (unic >= 0x00000080 && unic <= 0x000007FF) {
        *(p + 1) = (unic & 0x3F) | 0x80;
        *p = ((unic >> 6) & 0x1F) | 0xC0;
        return 2;
    } else if (unic >= 0x00000800 && unic <= 0x0000FFFF) {
        *(p + 2) = (unic & 0x3F) | 0x80;
        *(p + 1) = ((unic >> 6) & 0x3F) | 0x80;
        *p = ((unic >> 12) & 0x0F) | 0xE0;
        return 3;
    } else if (unic >= 0x00010000 && unic <= 0x001FFFFF) {
        *(p + 3) = (unic & 0x3F) | 0x80;
        *(p + 2) = ((unic >> 6) & 0x3F) | 0x80;
        *(p + 1) = ((unic >> 12) & 0x3F) | 0x80;
        *p = ((unic >> 18) & 0x07) | 0xF0;
        return 4;
    } else if (unic >= 0x00200000 && unic <= 0x03FFFFFF) {
        *(p + 4) = (unic & 0x3F) | 0x80;
        *(p + 3) = ((unic >> 6) & 0x3F) | 0x80;
        *(p + 2) = ((unic >> 12) & 0x3F) | 0x80;
        *(p + 1) = ((unic >> 18) & 0x3F) | 0x80;
        *p = ((unic >> 24) & 0x03) | 0xF8;
        return 5;
    } else if (unic >= 0x04000000) {
        *(p + 5) = (unic & 0x3F) | 0x80;
        *(p + 4) = ((unic >> 6) & 0x3F) | 0x80;
        *(p + 3) = ((unic >> 12) & 0x3F) | 0x80;
        *(p + 2) = ((unic >> 18) & 0x3F) | 0x80;
        *(p + 1) = ((unic >> 24) & 0x3F) | 0x80;
        *p = ((unic >> 30) & 0x01) | 0xFC;
        return 6;
    }
    return 0;
}

void rand_string(char *str, int size) {
    if (g_args.chinese) {
        char *pstr = str;
        int   move = 0;
        while (size > 0) {
            // Chinese Character need 3 bytes space
            if (size < 3) {
                break;
            }
            // Basic Chinese Character's Unicode is from 0x4e00 to 0x9fa5
            int unic = 0x4e00 + taosRandom() % (0x9fa5 - 0x4e00);
            move = usc2utf8(pstr, unic);
            pstr += move;
            size -= move;
        }
    } else {
        str[0] = 0;
        if (size > 0) {
            //--size;
            int n;
            for (n = 0; n < size; n++) {
                int key = abs(taosRandom()) % (int)(sizeof(charset) - 1);
                str[n] = charset[key];
            }
            str[n] = 0;
        }
    }
}

char *rand_double_str() {
    static int cursor;
    cursor++;
    if (cursor > (g_data_size - 1)) cursor = 0;
    return g_randdouble_buff + (cursor * DOUBLE_BUFF_LEN);
}

double rand_double() {
    static int cursor;
    cursor++;
    cursor = cursor % g_data_size;
    return g_randdouble[cursor];
}

int init_rand_data() {
    g_randint_buff = calloc(1, INT_BUFF_LEN * g_data_size);
    g_rand_voltage_buff = calloc(1, INT_BUFF_LEN * g_data_size);
    g_randbigint_buff = calloc(1, BIGINT_BUFF_LEN * g_data_size);
    g_randsmallint_buff = calloc(1, SMALLINT_BUFF_LEN * g_data_size);
    g_randtinyint_buff = calloc(1, TINYINT_BUFF_LEN * g_data_size);
    g_randbool_buff = calloc(1, BOOL_BUFF_LEN * g_data_size);
    g_randfloat_buff = calloc(1, FLOAT_BUFF_LEN * g_data_size);
    g_rand_current_buff = calloc(1, FLOAT_BUFF_LEN * g_data_size);
    g_rand_phase_buff = calloc(1, FLOAT_BUFF_LEN * g_data_size);
    g_randdouble_buff = calloc(1, DOUBLE_BUFF_LEN * g_data_size);
    g_randuint_buff = calloc(1, INT_BUFF_LEN * g_data_size);
    g_randutinyint_buff = calloc(1, TINYINT_BUFF_LEN * g_data_size);
    g_randusmallint_buff = calloc(1, SMALLINT_BUFF_LEN * g_data_size);
    g_randubigint_buff = calloc(1, BIGINT_BUFF_LEN * g_data_size);
    g_randint = calloc(1, sizeof(int32_t) * g_data_size);
    g_randuint = calloc(1, sizeof(uint32_t) * g_data_size);
    g_randbigint = calloc(1, sizeof(int64_t) * g_data_size);
    g_randubigint = calloc(1, sizeof(uint64_t) * g_data_size);
    g_randfloat = calloc(1, sizeof(float) * g_data_size);
    g_randdouble = calloc(1, sizeof(double) * g_data_size);

    for (int i = 0; i < g_data_size; i++) {
        g_randint[i] = (int)(taosRandom() % RAND_MAX - (RAND_MAX >> 1));
        g_randuint[i] = (int)(taosRandom());
        sprintf(g_randint_buff + i * INT_BUFF_LEN, "%d", g_randint[i]);
        sprintf(g_rand_voltage_buff + i * INT_BUFF_LEN, "%d",
                215 + g_randint[i] % 10);

        sprintf(g_randbool_buff + i * BOOL_BUFF_LEN, "%s",
                ((g_randint[i] % 2) & 1) ? "true" : "false");
        sprintf(g_randsmallint_buff + i * SMALLINT_BUFF_LEN, "%d",
                g_randint[i] % 32768);
        sprintf(g_randtinyint_buff + i * TINYINT_BUFF_LEN, "%d",
                g_randint[i] % 128);
        sprintf(g_randuint_buff + i * INT_BUFF_LEN, "%d", g_randuint[i]);
        sprintf(g_randusmallint_buff + i * SMALLINT_BUFF_LEN, "%d",
                g_randuint[i] % 65535);
        sprintf(g_randutinyint_buff + i * TINYINT_BUFF_LEN, "%d",
                g_randuint[i] % 255);

        g_randbigint[i] = (int64_t)(taosRandom() % RAND_MAX - (RAND_MAX >> 1));
        g_randubigint[i] = (uint64_t)(taosRandom());
        sprintf(g_randbigint_buff + i * BIGINT_BUFF_LEN, "%" PRId64 "",
                g_randbigint[i]);
        sprintf(g_randubigint_buff + i * BIGINT_BUFF_LEN, "%" PRId64 "",
                g_randubigint[i]);

        g_randfloat[i] =
            (float)(taosRandom() / 1000.0) * (taosRandom() % 2 > 0.5 ? 1 : -1);
        sprintf(g_randfloat_buff + i * FLOAT_BUFF_LEN, "%f", g_randfloat[i]);
        sprintf(g_rand_current_buff + i * FLOAT_BUFF_LEN, "%f",
                (float)(9.8 + 0.04 * (g_randint[i] % 10) +
                        g_randfloat[i] / 1000000000));
        sprintf(
            g_rand_phase_buff + i * FLOAT_BUFF_LEN, "%f",
            (float)((115 + g_randint[i] % 10 + g_randfloat[i] / 1000000000) /
                    360));

        g_randdouble[i] = (double)(taosRandom() / 1000000.0) *
                          (taosRandom() % 2 > 0.5 ? 1 : -1);
        sprintf(g_randdouble_buff + i * DOUBLE_BUFF_LEN, "%f", g_randdouble[i]);
    }
    return 0;
}

int clean_rand_data() {
    tmfree(g_randbool_buff);
    tmfree(g_randint_buff);
    tmfree(g_rand_voltage_buff);
    tmfree(g_randbigint_buff);
    tmfree(g_randsmallint_buff);
    tmfree(g_randtinyint_buff);
    tmfree(g_randfloat_buff);
    tmfree(g_rand_current_buff);
    tmfree(g_rand_phase_buff);
    tmfree(g_randdouble_buff);
    tmfree(g_randuint_buff);
    tmfree(g_randutinyint_buff);
    tmfree(g_randusmallint_buff);
    tmfree(g_randubigint_buff);
    tmfree(g_randint);
    tmfree(g_randuint);
    tmfree(g_randbigint);
    tmfree(g_randubigint);
    tmfree(g_randfloat);
    tmfree(g_randdouble);
    tmfree(g_data_buffer);

    for (int l = 0; l < g_args.columnCount; l++) {
        if (g_sampleBindBatchArray) {
            tmfree((char *)((uintptr_t) * (uintptr_t *)(g_sampleBindBatchArray +
                                                        sizeof(char *) * l)));
        }
    }
    tmfree(g_sampleBindBatchArray);
    return 0;
}

static void generateBinaryNCharTagValues(int64_t tableSeq, uint32_t len,
                                         char *buf) {
    if (tableSeq % 2) {
        tstrncpy(buf, "beijing", len);
    } else {
        tstrncpy(buf, "shanghai", len);
    }
    // rand_string(buf, stbInfo->tags[i].dataLen);
}

int generate_sql_tags(SSuperTable *stbInfo, int64_t tableSeq,
                      char *tagsValBuf) {
    int dataLen = 0;
    dataLen += snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen, "(");
    for (int i = 0; i < stbInfo->tagCount; i++) {
        switch (stbInfo->tags[i].data_type) {
            case TSDB_DATA_TYPE_TIMESTAMP:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%" PRId64 ",", rand_ubigint());
                break;
            case TSDB_DATA_TYPE_INT:
                if ((g_args.demo_mode) && (i == 0)) {
                    dataLen += snprintf(tagsValBuf + dataLen,
                                        TSDB_MAX_SQL_LEN - dataLen,
                                        "%" PRId64 ",", (tableSeq % 10) + 1);
                } else {
                    dataLen += snprintf(tagsValBuf + dataLen,
                                        TSDB_MAX_SQL_LEN - dataLen,
                                        "%" PRId64 ",", tableSeq);
                }
                break;
            case TSDB_DATA_TYPE_NCHAR:
            case TSDB_DATA_TYPE_BINARY: {
                char *buf = (char *)calloc(1, stbInfo->tags[i].dataLen + 1);
                if (g_args.demo_mode) {
                    generateBinaryNCharTagValues(
                        tableSeq, stbInfo->tags[i].dataLen + 1, buf);
                } else {
                    rand_string(buf, stbInfo->tags[i].dataLen);
                }

                dataLen += snprintf(tagsValBuf + dataLen,
                                    TSDB_MAX_SQL_LEN - dataLen, "\'%s\',", buf);
                tmfree(buf);
                break;
            }
            case TSDB_DATA_TYPE_BIGINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%" PRId64 ",", rand_bigint());
                break;
            case TSDB_DATA_TYPE_FLOAT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%f,", rand_float());
                break;
            case TSDB_DATA_TYPE_DOUBLE:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%f,", rand_double());
                break;
            case TSDB_DATA_TYPE_SMALLINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_smallint());
                break;
            case TSDB_DATA_TYPE_TINYINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_tinyint());
                break;
            case TSDB_DATA_TYPE_BOOL:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_bool());
                break;
            case TSDB_DATA_TYPE_UTINYINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_utinyint());
                break;
            case TSDB_DATA_TYPE_USMALLINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_usmallint());
                break;
            case TSDB_DATA_TYPE_UINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%d,", rand_uint());
                break;
            case TSDB_DATA_TYPE_UBIGINT:
                dataLen +=
                    snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen,
                             "%" PRId64 ",", rand_ubigint());
                break;
            case TSDB_DATA_TYPE_JSON:
                dataLen += snprintf(tagsValBuf + dataLen,
                                    TSDB_MAX_SQL_LEN - dataLen, "'{");
                for (int n = 0; n < stbInfo->tagCount; ++n) {
                    char *tmp_buf = calloc(1, stbInfo->tags[i].dataLen + 1);
                    rand_string(tmp_buf, stbInfo->tags[i].dataLen);
                    dataLen += snprintf(tagsValBuf + dataLen,
                                        TSDB_MAX_SQL_LEN - dataLen,
                                        "\"tag%d\":\"%s\",", n, tmp_buf);
                    tmfree(tmp_buf);
                }
                dataLen -= 1;
                dataLen += snprintf(tagsValBuf + dataLen,
                                    TSDB_MAX_SQL_LEN - dataLen, "}')");
                return 0;
            default:
                errorPrint("unsupported data type: %s\n",
                           stbInfo->tags[i].dataType);
                return -1;
        }
    }
    dataLen -= 1;
    dataLen += snprintf(tagsValBuf + dataLen, TSDB_MAX_SQL_LEN - dataLen, ")");
    return 0;
}

static int readTagFromCsvFileToMem(SSuperTable *stbInfo) {
    size_t  n = 0;
    ssize_t readLen = 0;
    char *  line = NULL;

    FILE *fp = fopen(stbInfo->tagsFile, "r");
    if (fp == NULL) {
        printf("Failed to open tags file: %s, reason:%s\n", stbInfo->tagsFile,
               strerror(errno));
        return -1;
    }

    if (stbInfo->tagDataBuf) {
        free(stbInfo->tagDataBuf);
        stbInfo->tagDataBuf = NULL;
    }

    int   tagCount = MAX_SAMPLES;
    int   count = 0;
    char *tagDataBuf = calloc(1, stbInfo->length_of_tags * tagCount);
    if (tagDataBuf == NULL) {
        printf("Failed to calloc, reason:%s\n", strerror(errno));
        fclose(fp);
        return -1;
    }

    while ((readLen = getline(&line, &n, fp)) != -1) {
        if (('\r' == line[readLen - 1]) || ('\n' == line[readLen - 1])) {
            line[--readLen] = 0;
        }

        if (readLen == 0) {
            continue;
        }

        memcpy(tagDataBuf + count * stbInfo->length_of_tags, line, readLen);
        count++;

        if (count >= tagCount - 1) {
            char *tmp = realloc(
                tagDataBuf, (size_t)(tagCount * 1.5 * stbInfo->length_of_tags));
            if (tmp != NULL) {
                tagDataBuf = tmp;
                tagCount = (int)(tagCount * 1.5);
                memset(tagDataBuf + count * stbInfo->length_of_tags, 0,
                       (size_t)((tagCount - count) * stbInfo->length_of_tags));
            } else {
                // exit, if allocate more memory failed
                printf("realloc fail for save tag val from %s\n",
                       stbInfo->tagsFile);
                tmfree(tagDataBuf);
                free(line);
                fclose(fp);
                return -1;
            }
        }
    }

    stbInfo->tagDataBuf = tagDataBuf;
    stbInfo->tagSampleCount = count;

    free(line);
    fclose(fp);
    return 0;
}

static int getAndSetRowsFromCsvFile(SSuperTable *stbInfo) {
    int32_t code = -1;
    FILE *  fp = fopen(stbInfo->sampleFile, "r");
    int     line_count = 0;
    char *  buf;
    if (fp == NULL) {
        errorPrint("Failed to open sample file: %s, reason:%s\n",
                   stbInfo->sampleFile, strerror(errno));
        goto free_of_get_set_rows_from_csv;
    }
    buf = calloc(1, stbInfo->maxSqlLen);
    if (buf == NULL) {
        errorPrint("%s", "failed to allocate memory\n");
        goto free_of_get_set_rows_from_csv;
    }

    while (fgets(buf, (int)stbInfo->maxSqlLen, fp)) {
        line_count++;
    }
    stbInfo->insertRows = line_count;
    code = 0;
free_of_get_set_rows_from_csv:
    fclose(fp);
    tmfree(buf);
    return code;
}

int prepare_data_from_csv(SSuperTable *stbInfo) {
    size_t  n = 0;
    ssize_t readLen = 0;
    char *  line = NULL;
    int     getRows = 0;

    FILE *fp = fopen(stbInfo->sampleFile, "r");
    if (fp == NULL) {
        errorPrint("Failed to open sample file: %s, reason:%s\n",
                   stbInfo->sampleFile, strerror(errno));
        return -1;
    }
    while (1) {
        readLen = getline(&line, &n, fp);
        if (-1 == readLen) {
            if (0 != fseek(fp, 0, SEEK_SET)) {
                errorPrint("Failed to fseek file: %s, reason:%s\n",
                           stbInfo->sampleFile, strerror(errno));
                fclose(fp);
                return -1;
            }
            continue;
        }

        if (('\r' == line[readLen - 1]) || ('\n' == line[readLen - 1])) {
            line[--readLen] = 0;
        }

        if (readLen == 0) {
            continue;
        }
        memcpy(stbInfo->data_buffer + getRows * stbInfo->length_of_cols, line,
               readLen);
        getRows++;

        if (getRows == g_data_size) {
            break;
        }
    }

    fclose(fp);
    tmfree(line);
    return 0;
}

int prepareSampleData() {
    for (int i = 0; i < g_Dbs.dbCount; i++) {
        for (int j = 0; j < g_Dbs.db[i].superTblCount; j++) {
            if (g_Dbs.db[i].superTbls[j].tagsFile[0] != 0) {
                if (readTagFromCsvFileToMem(&g_Dbs.db[i].superTbls[j]) != 0) {
                    return -1;
                }
            }
        }
    }

    return 0;
}

static int getRowDataFromSample(char *dataBuf, int64_t maxLen,
                                int64_t timestamp, SSuperTable *stbInfo,
                                int64_t *sampleUsePos) {
    if ((*sampleUsePos) == MAX_SAMPLES) {
        *sampleUsePos = 0;
    }

    int dataLen = 0;
    if (stbInfo->useSampleTs) {
        dataLen += snprintf(
            dataBuf + dataLen, maxLen - dataLen, "(%s",
            stbInfo->data_buffer + stbInfo->length_of_cols * (*sampleUsePos));
    } else {
        dataLen += snprintf(dataBuf + dataLen, maxLen - dataLen,
                            "(%" PRId64 ", ", timestamp);
        dataLen += snprintf(
            dataBuf + dataLen, maxLen - dataLen, "%s",
            stbInfo->data_buffer + stbInfo->length_of_cols * (*sampleUsePos));
    }
    dataLen += snprintf(dataBuf + dataLen, maxLen - dataLen, ")");

    (*sampleUsePos)++;

    return dataLen;
}

static int64_t generateData(char *recBuf, char *data_type, int32_t *data_length,
                            int64_t timestamp) {
    memset(recBuf, 0, MAX_DATA_SIZE);
    char *pstr = recBuf;
    pstr += sprintf(pstr, "(%" PRId64 "", timestamp);

    int columnCount = g_args.columnCount;

    bool  b;
    char *s;
    for (int i = 0; i < columnCount; i++) {
        switch (data_type[i]) {
            case TSDB_DATA_TYPE_TINYINT:
                pstr += sprintf(pstr, ",%d", rand_tinyint());
                break;

            case TSDB_DATA_TYPE_SMALLINT:
                pstr += sprintf(pstr, ",%d", rand_smallint());
                break;

            case TSDB_DATA_TYPE_INT:
                pstr += sprintf(pstr, ",%d", rand_int());
                break;

            case TSDB_DATA_TYPE_BIGINT:
                pstr += sprintf(pstr, ",%" PRId64 "", rand_bigint());
                break;

            case TSDB_DATA_TYPE_TIMESTAMP:
                pstr += sprintf(pstr, ",%" PRId64 "", rand_bigint());
                break;

            case TSDB_DATA_TYPE_FLOAT:
                pstr += sprintf(pstr, ",%10.4f", rand_float());
                break;

            case TSDB_DATA_TYPE_DOUBLE:
                pstr += sprintf(pstr, ",%20.8f", rand_double());
                break;

            case TSDB_DATA_TYPE_BOOL:
                b = rand_bool() & 1;
                pstr += sprintf(pstr, ",%s", b ? "true" : "false");
                break;

            case TSDB_DATA_TYPE_BINARY:
            case TSDB_DATA_TYPE_NCHAR:
                s = calloc(1, data_length[i] + 1);
                if (NULL == s) {
                    errorPrint("%s", "failed to allocate memory\n");
                    return -1;
                }

                rand_string(s, data_length[i]);
                pstr += sprintf(pstr, ",\"%s\"", s);
                free(s);
                break;

            case TSDB_DATA_TYPE_UTINYINT:
                pstr += sprintf(pstr, ",%d", rand_utinyint());
                break;

            case TSDB_DATA_TYPE_USMALLINT:
                pstr += sprintf(pstr, ",%d", rand_usmallint());
                break;

            case TSDB_DATA_TYPE_UINT:
                pstr += sprintf(pstr, ",%d", rand_uint());
                break;

            case TSDB_DATA_TYPE_UBIGINT:
                pstr += sprintf(pstr, ",%" PRId64 "", rand_ubigint());
                break;

            case TSDB_DATA_TYPE_NULL:
                break;

            default:
                errorPrint("Unknown data type %d\n", data_type[i]);
                return -1;
        }

        if (strlen(recBuf) > MAX_DATA_SIZE) {
            errorPrint("%s", "column length too long, abort\n");
            return -1;
        }
    }

    pstr += sprintf(pstr, ")");

    verbosePrint("%s() LN%d, recBuf:\n\t%s\n", __func__, __LINE__, recBuf);

    return (int32_t)strlen(recBuf);
}

static int generateSampleFromRand(char *data_buffer, uint64_t length_of_cols,
                                  int columnCount, StrColumn *columns) {
    char data[MAX_DATA_SIZE];
    memset(data, 0, MAX_DATA_SIZE);

    char *buff = calloc(length_of_cols, 1);
    if (NULL == buff) {
        errorPrint("%s", "failed to allocate memory\n");
        return -1;
    }

    for (int i = 0; i < MAX_SAMPLES; i++) {
        uint64_t pos = 0;
        memset(buff, 0, length_of_cols);

        for (int c = 0; c < columnCount; c++) {
            char *tmp = NULL;

            uint32_t dataLen;
            char     data_type =
                (columns) ? (columns[c].data_type) : g_args.data_type[c];

            switch (data_type) {
                case TSDB_DATA_TYPE_BINARY:
                    dataLen = (columns) ? columns[c].dataLen : g_args.binwidth;
                    rand_string(data, dataLen);
                    pos += sprintf(buff + pos, "%s,", data);
                    break;

                case TSDB_DATA_TYPE_NCHAR:
                    dataLen = (columns) ? columns[c].dataLen : g_args.binwidth;
                    rand_string(data, dataLen - 1);
                    pos += sprintf(buff + pos, "%s,", data);
                    break;

                case TSDB_DATA_TYPE_INT:
                    if ((g_args.demo_mode) && (c == 1)) {
                        tmp = demo_voltage_int_str();
                    } else {
                        tmp = rand_int_str();
                    }
                    pos += sprintf(buff + pos, "%s,", tmp);
                    break;

                case TSDB_DATA_TYPE_UINT:
                    pos += sprintf(buff + pos, "%s,", rand_uint_str());
                    break;

                case TSDB_DATA_TYPE_BIGINT:
                    pos += sprintf(buff + pos, "%s,", rand_bigint_str());
                    break;

                case TSDB_DATA_TYPE_UBIGINT:
                    pos += sprintf(buff + pos, "%s,", rand_ubigint_str());
                    break;

                case TSDB_DATA_TYPE_FLOAT:
                    if (g_args.demo_mode) {
                        if (c == 0) {
                            tmp = demo_current_float_str();
                        } else {
                            tmp = demo_phase_float_str();
                        }
                    } else {
                        tmp = rand_float_str();
                    }
                    pos += sprintf(buff + pos, "%s,", tmp);
                    break;

                case TSDB_DATA_TYPE_DOUBLE:
                    pos += sprintf(buff + pos, "%s,", rand_double_str());
                    break;

                case TSDB_DATA_TYPE_SMALLINT:
                    pos += sprintf(buff + pos, "%s,", rand_smallint_str());
                    break;

                case TSDB_DATA_TYPE_USMALLINT:
                    pos += sprintf(buff + pos, "%s,", rand_usmallint_str());
                    break;

                case TSDB_DATA_TYPE_TINYINT:
                    pos += sprintf(buff + pos, "%s,", rand_tinyint_str());
                    break;

                case TSDB_DATA_TYPE_UTINYINT:
                    pos += sprintf(buff + pos, "%s,", rand_utinyint_str());
                    break;

                case TSDB_DATA_TYPE_BOOL:
                    pos += sprintf(buff + pos, "%s,", rand_bool_str());
                    break;

                case TSDB_DATA_TYPE_TIMESTAMP:
                    pos += sprintf(buff + pos, "%s,", rand_bigint_str());
                    break;

                case TSDB_DATA_TYPE_NULL:
                    break;

                default:
                    errorPrint(
                        "%s() LN%d, Unknown data type %s\n", __func__, __LINE__,
                        (columns) ? (columns[c].dataType) : g_args.dataType[c]);
                    exit(EXIT_FAILURE);
            }
        }

        *(buff + pos - 1) = 0;
        memcpy(data_buffer + i * length_of_cols, buff, pos);
    }

    free(buff);
    return 0;
}

static int generateSampleFromRandForNtb() {
    return generateSampleFromRand(g_data_buffer, g_args.length_of_cols,
                                  g_args.columnCount, NULL);
}

static int generateSampleFromRandForStb(SSuperTable *stbInfo) {
    return generateSampleFromRand(stbInfo->data_buffer, stbInfo->length_of_cols,
                                  stbInfo->columnCount, stbInfo->columns);
}

int prepare_data_from_rand(SSuperTable *stbInfo) {
    for (int64_t i = 0; i < g_data_size; ++i) {
        char *  ptr = stbInfo->data_buffer + i * stbInfo->length_of_cols;
        int64_t dataLen = 0;
        int     tmpLen;
        for (int col_index = 0; col_index < stbInfo->columnCount; col_index++) {
            char *tmp = NULL;
            if (col_index != 0) {
                tstrncpy(ptr + dataLen, ",", 2);
                dataLen += 1;
            }
            switch (stbInfo->columns[col_index].data_type) {
                case TSDB_DATA_TYPE_NCHAR:
                case TSDB_DATA_TYPE_BINARY: {
                    char *buf = (char *)calloc(
                        1, stbInfo->columns[col_index].dataLen + 1);
                    rand_string(buf, stbInfo->columns[col_index].dataLen);
                    dataLen += snprintf(ptr + dataLen,
                                        stbInfo->length_of_cols - dataLen,
                                        "\'%s\'", buf);
                    tmfree(buf);
                }
                case TSDB_DATA_TYPE_INT:
                    if ((g_args.demo_mode) && (i == 1)) {
                        tmp = demo_voltage_int_str();
                    } else {
                        tmp = rand_int_str();
                    }
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp, min(tmpLen + 1, INT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_UINT:
                    tmp = rand_uint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp, min(tmpLen + 1, INT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_BIGINT:
                    tmp = rand_bigint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, BIGINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_UBIGINT:
                    tmp = rand_ubigint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, BIGINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_FLOAT:
                    if (g_args.demo_mode) {
                        if (i == 0) {
                            tmp = demo_current_float_str();
                        } else {
                            tmp = demo_phase_float_str();
                        }
                    } else {
                        tmp = rand_float_str();
                    }
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, FLOAT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_DOUBLE:
                    tmp = rand_double_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, DOUBLE_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_SMALLINT:
                    tmp = rand_smallint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, SMALLINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_USMALLINT:
                    tmp = rand_usmallint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, SMALLINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_TINYINT:
                    tmp = rand_tinyint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, TINYINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_UTINYINT:
                    tmp = rand_utinyint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, TINYINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_BOOL:
                    tmp = rand_bool_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, BOOL_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_TIMESTAMP:
                    tmp = rand_bigint_str();
                    tmpLen = (int)strlen(tmp);
                    tstrncpy(ptr + dataLen, tmp,
                             min(tmpLen + 1, BIGINT_BUFF_LEN));
                    break;

                case TSDB_DATA_TYPE_NULL:
                    break;

                default:
                    errorPrint("Not support data type: %s\n",
                               stbInfo->columns[col_index].dataType);
                    return -1;
            }
            dataLen += tmpLen;
        }
    }
}

int prepareSampleForNtb() {
    g_data_buffer = calloc(g_args.length_of_cols * g_data_size, 1);
    if (NULL == g_data_buffer) {
        errorPrint("%s", "failed to allocate memory\n");
        return -1;
    }

    return generateSampleFromRandForNtb();
}

int prepare_data(SSuperTable *stbInfo) {
    stbInfo->data_buffer = calloc(1, stbInfo->length_of_cols * g_data_size);

    int ret;
    if (0 == strncasecmp(stbInfo->dataSource, "sample", strlen("sample"))) {
        if (stbInfo->useSampleTs) {
            if (getAndSetRowsFromCsvFile(stbInfo)) {
                tmfree(stbInfo->data_buffer);
                return -1;
            }
        }
        ret = prepare_data_from_csv(stbInfo);
    } else {
        ret = prepare_data_from_rand(stbInfo);
    }

    if (0 != ret) {
        tmfree(stbInfo->data_buffer);
        return -1;
    }

    return 0;
}

int64_t getTSRandTail(int64_t timeStampStep, int32_t seq, int disorderRatio,
                      int disorderRange) {
    int64_t randTail = timeStampStep * seq;
    if (disorderRatio > 0) {
        int rand_num = taosRandom() % 100;
        if (rand_num < disorderRatio) {
            randTail = (randTail + (taosRandom() % disorderRange + 1)) * (-1);
            debugPrint("rand data generated, back %" PRId64 "\n", randTail);
        }
    }

    return randTail;
}

static int32_t generateDataTailWithoutStb(
    uint32_t batch, char *buffer, int64_t remainderBufLen, int64_t insertRows,
    uint64_t recordFrom, int64_t startTime,
    /* int64_t *pSamplePos, */ int64_t *dataLen) {
    uint64_t len = 0;
    char *   pstr = buffer;

    verbosePrint("%s() LN%d batch=%d\n", __func__, __LINE__, batch);

    int32_t k = 0;
    for (k = 0; k < batch;) {
        char *data = pstr;
        memset(data, 0, MAX_DATA_SIZE);

        int64_t retLen = 0;

        char *   data_type = g_args.data_type;
        int32_t *data_length = g_args.data_length;

        if (g_args.disorderRatio) {
            retLen =
                generateData(data, data_type, data_length,
                             startTime + getTSRandTail(g_args.timestamp_step, k,
                                                       g_args.disorderRatio,
                                                       g_args.disorderRange));
        } else {
            retLen = generateData(data, data_type, data_length,
                                  startTime + g_args.timestamp_step * k);
        }

        if (len > remainderBufLen) break;

        pstr += retLen;
        k++;
        len += retLen;
        remainderBufLen -= retLen;

        verbosePrint("%s() LN%d len=%" PRIu64 " k=%d \nbuffer=%s\n", __func__,
                     __LINE__, len, k, buffer);

        recordFrom++;

        if (recordFrom >= insertRows) {
            break;
        }
    }

    *dataLen = len;
    return k;
}

static int generateSQLHeadWithoutStb(char *tableName, char *dbName,
                                     char *buffer, int remainderBufLen) {
    int len;

    char headBuf[HEAD_BUFF_LEN];

    len = snprintf(headBuf, HEAD_BUFF_LEN, "%s.%s values", dbName, tableName);

    if (len > remainderBufLen) return -1;

    tstrncpy(buffer, headBuf, len + 1);

    return len;
}

int64_t generateInterlaceDataWithoutStb(char *tableName, uint32_t batch,
                                        uint64_t tableSeq, char *dbName,
                                        char *buffer, int64_t insertRows,
                                        int64_t   startTime,
                                        uint64_t *pRemainderBufLen) {
    char *pstr = buffer;

    int headLen = generateSQLHeadWithoutStb(tableName, dbName, pstr,
                                            (int)(*pRemainderBufLen));

    if (headLen <= 0) {
        return 0;
    }

    pstr += headLen;
    *pRemainderBufLen -= headLen;

    int64_t dataLen = 0;

    int32_t k = generateDataTailWithoutStb(batch, pstr, *pRemainderBufLen,
                                           insertRows, 0, startTime, &dataLen);

    if (k == batch) {
        pstr += dataLen;
        *pRemainderBufLen -= dataLen;
    } else {
        debugPrint(
            "%s() LN%d, generated data tail: %d, not equal batch per "
            "table: "
            "%u\n",
            __func__, __LINE__, k, batch);
        pstr -= headLen;
        pstr[0] = '\0';
        k = 0;
    }

    return k;
}

static int32_t prepareStmtBindArrayByType(TAOS_BIND *bind, char data_type,
                                          int32_t dataLen, int32_t timePrec,
                                          char *value) {
    int32_t * bind_int;
    uint32_t *bind_uint;
    int64_t * bind_bigint;
    uint64_t *bind_ubigint;
    float *   bind_float;
    double *  bind_double;
    int8_t *  bind_bool;
    int64_t * bind_ts2;
    int16_t * bind_smallint;
    uint16_t *bind_usmallint;
    int8_t *  bind_tinyint;
    uint8_t * bind_utinyint;

    switch (data_type) {
        case TSDB_DATA_TYPE_BINARY:
            if (dataLen > TSDB_MAX_BINARY_LEN) {
                errorPrint("binary length overflow, max size:%u\n",
                           (uint32_t)TSDB_MAX_BINARY_LEN);
                return -1;
            }
            char *bind_binary;

            bind->buffer_type = TSDB_DATA_TYPE_BINARY;
            if (value) {
                bind_binary = calloc(1, strlen(value) + 1);
                tstrncpy(bind_binary, value, strlen(value));
                bind->buffer_length = strlen(bind_binary);
            } else {
                bind_binary = calloc(1, dataLen + 1);
                rand_string(bind_binary, dataLen);
                bind->buffer_length = dataLen;
            }

            bind->length = &bind->buffer_length;
            bind->buffer = bind_binary;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_NCHAR:
            if (dataLen > TSDB_MAX_BINARY_LEN) {
                errorPrint("nchar length overflow, max size:%u\n",
                           (uint32_t)TSDB_MAX_BINARY_LEN);
                return -1;
            }
            char *bind_nchar;

            bind->buffer_type = TSDB_DATA_TYPE_NCHAR;
            if (value) {
                bind_nchar = calloc(1, strlen(value) + 1);
                tstrncpy(bind_nchar, value, strlen(value));
            } else {
                bind_nchar = calloc(1, dataLen + 1);
                rand_string(bind_nchar, dataLen);
            }

            bind->buffer_length = strlen(bind_nchar);
            bind->buffer = bind_nchar;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_INT:
            bind_int = calloc(1, sizeof(int32_t));
            if (value) {
                *bind_int = atoi(value);
            } else {
                *bind_int = rand_int();
            }
            bind->buffer_type = TSDB_DATA_TYPE_INT;
            bind->buffer_length = sizeof(int32_t);
            bind->buffer = bind_int;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_UINT:
            bind_uint = malloc(sizeof(uint32_t));

            if (value) {
                *bind_uint = atoi(value);
            } else {
                *bind_uint = rand_int();
            }
            bind->buffer_type = TSDB_DATA_TYPE_UINT;
            bind->buffer_length = sizeof(uint32_t);
            bind->buffer = bind_uint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_BIGINT:
            bind_bigint = malloc(sizeof(int64_t));

            if (value) {
                *bind_bigint = atoll(value);
            } else {
                *bind_bigint = rand_bigint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_BIGINT;
            bind->buffer_length = sizeof(int64_t);
            bind->buffer = bind_bigint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_UBIGINT:
            bind_ubigint = malloc(sizeof(uint64_t));

            if (value) {
                *bind_ubigint = atoll(value);
            } else {
                *bind_ubigint = rand_bigint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_UBIGINT;
            bind->buffer_length = sizeof(uint64_t);
            bind->buffer = bind_ubigint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_FLOAT:
            bind_float = malloc(sizeof(float));

            if (value) {
                *bind_float = (float)atof(value);
            } else {
                *bind_float = rand_float();
            }
            bind->buffer_type = TSDB_DATA_TYPE_FLOAT;
            bind->buffer_length = sizeof(float);
            bind->buffer = bind_float;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_DOUBLE:
            bind_double = malloc(sizeof(double));

            if (value) {
                *bind_double = atof(value);
            } else {
                *bind_double = rand_double();
            }
            bind->buffer_type = TSDB_DATA_TYPE_DOUBLE;
            bind->buffer_length = sizeof(double);
            bind->buffer = bind_double;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_SMALLINT:
            bind_smallint = malloc(sizeof(int16_t));

            if (value) {
                *bind_smallint = (int16_t)atoi(value);
            } else {
                *bind_smallint = rand_smallint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_SMALLINT;
            bind->buffer_length = sizeof(int16_t);
            bind->buffer = bind_smallint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_USMALLINT:
            bind_usmallint = malloc(sizeof(uint16_t));

            if (value) {
                *bind_usmallint = (uint16_t)atoi(value);
            } else {
                *bind_usmallint = rand_smallint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_SMALLINT;
            bind->buffer_length = sizeof(uint16_t);
            bind->buffer = bind_usmallint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_TINYINT:
            bind_tinyint = malloc(sizeof(int8_t));

            if (value) {
                *bind_tinyint = (int8_t)atoi(value);
            } else {
                *bind_tinyint = rand_tinyint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_TINYINT;
            bind->buffer_length = sizeof(int8_t);
            bind->buffer = bind_tinyint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_UTINYINT:
            bind_utinyint = malloc(sizeof(uint8_t));

            if (value) {
                *bind_utinyint = (int8_t)atoi(value);
            } else {
                *bind_utinyint = rand_tinyint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_UTINYINT;
            bind->buffer_length = sizeof(uint8_t);
            bind->buffer = bind_utinyint;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_BOOL:
            bind_bool = malloc(sizeof(int8_t));

            if (value) {
                if (strncasecmp(value, "true", 4)) {
                    *bind_bool = true;
                } else {
                    *bind_bool = false;
                }
            } else {
                *bind_bool = rand_bool();
            }
            bind->buffer_type = TSDB_DATA_TYPE_BOOL;
            bind->buffer_length = sizeof(int8_t);
            bind->buffer = bind_bool;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_TIMESTAMP:
            bind_ts2 = malloc(sizeof(int64_t));

            if (value) {
                if (strchr(value, ':') && strchr(value, '-')) {
                    int i = 0;
                    while (value[i] != '\0') {
                        if (value[i] == '\"' || value[i] == '\'') {
                            value[i] = ' ';
                        }
                        i++;
                    }
                    int64_t tmpEpoch;
                    if (TSDB_CODE_SUCCESS !=
                        taos_parse_time(value, &tmpEpoch,
                                        (int32_t)strlen(value), timePrec, 0)) {
                        free(bind_ts2);
                        errorPrint("Input %s, time format error!\n", value);
                        return -1;
                    }
                    *bind_ts2 = tmpEpoch;
                } else {
                    *bind_ts2 = atoll(value);
                }
            } else {
                *bind_ts2 = rand_bigint();
            }
            bind->buffer_type = TSDB_DATA_TYPE_TIMESTAMP;
            bind->buffer_length = sizeof(int64_t);
            bind->buffer = bind_ts2;
            bind->length = &bind->buffer_length;
            bind->is_null = NULL;
            break;

        case TSDB_DATA_TYPE_NULL:
            break;

        default:
            errorPrint("Not support data type: %d\n", data_type);
            return -1;
    }

    return 0;
}

int32_t prepareStmtWithoutStb(threadInfo *pThreadInfo, char *tableName,
                              uint32_t batch, int64_t insertRows,
                              int64_t recordFrom, int64_t startTime) {
    TAOS_STMT *stmt = pThreadInfo->stmt;
    int        ret = taos_stmt_set_tbname(stmt, tableName);
    if (ret != 0) {
        errorPrint(
            "failed to execute taos_stmt_set_tbname(%s). return 0x%x. "
            "reason: "
            "%s\n",
            tableName, ret, taos_stmt_errstr(stmt));
        return ret;
    }

    char *data_type = g_args.data_type;

    char *bindArray = malloc(sizeof(TAOS_BIND) * (g_args.columnCount + 1));
    if (bindArray == NULL) {
        errorPrint("Failed to allocate %d bind params\n",
                   (g_args.columnCount + 1));
        return -1;
    }

    int32_t k = 0;
    for (k = 0; k < batch;) {
        /* columnCount + 1 (ts) */

        TAOS_BIND *bind = (TAOS_BIND *)(bindArray + 0);

        int64_t *bind_ts = pThreadInfo->bind_ts;

        bind->buffer_type = TSDB_DATA_TYPE_TIMESTAMP;

        if (g_args.disorderRatio) {
            *bind_ts = startTime + getTSRandTail(g_args.timestamp_step, k,
                                                 g_args.disorderRatio,
                                                 g_args.disorderRange);
        } else {
            *bind_ts = startTime + g_args.timestamp_step * k;
        }
        bind->buffer_length = sizeof(int64_t);
        bind->buffer = bind_ts;
        bind->length = &bind->buffer_length;
        bind->is_null = NULL;

        for (int i = 0; i < g_args.columnCount; i++) {
            bind = (TAOS_BIND *)((char *)bindArray +
                                 (sizeof(TAOS_BIND) * (i + 1)));
            if (-1 ==
                prepareStmtBindArrayByType(bind, data_type[i], g_args.binwidth,
                                           pThreadInfo->time_precision, NULL)) {
                free(bindArray);
                return -1;
            }
        }
        if (taos_stmt_bind_param(stmt, (TAOS_BIND *)bindArray)) {
            errorPrint("taos_stmt_bind_param() failed! reason: %s\n",
                       taos_stmt_errstr(stmt));
            break;
        }
        // if msg > 3MB, break
        if (taos_stmt_add_batch(stmt)) {
            errorPrint("taos_stmt_add_batch() failed! reason: %s\n",
                       taos_stmt_errstr(stmt));
            break;
        }

        k++;
        recordFrom++;
        if (recordFrom >= insertRows) {
            break;
        }
    }

    free(bindArray);
    return k;
}

int32_t prepareStbStmtBindTag(char *bindArray, SSuperTable *stbInfo,
                              char *tagsVal, int32_t timePrec) {
    TAOS_BIND *tag;

    for (int t = 0; t < stbInfo->tagCount; t++) {
        tag = (TAOS_BIND *)((char *)bindArray + (sizeof(TAOS_BIND) * t));
        if (prepareStmtBindArrayByType(tag, stbInfo->tags[t].data_type,
                                       stbInfo->tags[t].dataLen, timePrec,
                                       NULL)) {
            return -1;
        }
    }

    return 0;
}

int parseSamplefileToStmtBatch(SSuperTable *stbInfo) {
    int32_t columnCount = (stbInfo) ? stbInfo->columnCount : g_args.columnCount;
    char *  sampleBindBatchArray = NULL;

    if (stbInfo) {
        stbInfo->sampleBindBatchArray =
            calloc(1, sizeof(uintptr_t *) * columnCount);
        sampleBindBatchArray = stbInfo->sampleBindBatchArray;
    } else {
        g_sampleBindBatchArray = calloc(1, sizeof(uintptr_t *) * columnCount);
        sampleBindBatchArray = g_sampleBindBatchArray;
    }

    for (int c = 0; c < columnCount; c++) {
        char data_type =
            (stbInfo) ? stbInfo->columns[c].data_type : g_args.data_type[c];

        char *tmpP = NULL;

        switch (data_type) {
            case TSDB_DATA_TYPE_INT:
            case TSDB_DATA_TYPE_UINT:
                tmpP = calloc(1, sizeof(int32_t) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_TINYINT:
            case TSDB_DATA_TYPE_UTINYINT:
                tmpP = calloc(1, sizeof(char) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_SMALLINT:
            case TSDB_DATA_TYPE_USMALLINT:
                tmpP = calloc(1, sizeof(int16_t) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_BIGINT:
            case TSDB_DATA_TYPE_UBIGINT:
                tmpP = calloc(1, sizeof(int64_t) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_BOOL:
                tmpP = calloc(1, sizeof(char) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_FLOAT:
                tmpP = calloc(1, sizeof(float) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_DOUBLE:
                tmpP = calloc(1, sizeof(double) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_BINARY:
            case TSDB_DATA_TYPE_NCHAR:
                tmpP = calloc(
                    1, MAX_SAMPLES * (((stbInfo) ? stbInfo->columns[c].dataLen
                                                 : g_args.binwidth) +
                                      1));
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            case TSDB_DATA_TYPE_TIMESTAMP:
                tmpP = calloc(1, sizeof(int64_t) * MAX_SAMPLES);
                *(uintptr_t *)(sampleBindBatchArray + sizeof(uintptr_t *) * c) =
                    (uintptr_t)tmpP;
                break;

            default:
                errorPrint("Unknown data type: %s\n",
                           (stbInfo) ? stbInfo->columns[c].dataType
                                     : g_args.dataType[c]);
                exit(EXIT_FAILURE);
        }
    }

    char *  data_buffer = (stbInfo) ? stbInfo->data_buffer : g_data_buffer;
    int64_t length_of_cols =
        (stbInfo) ? stbInfo->length_of_cols : g_args.length_of_cols;

    for (int i = 0; i < MAX_SAMPLES; i++) {
        int cursor = 0;

        for (int c = 0; c < columnCount; c++) {
            char data_type =
                (stbInfo) ? stbInfo->columns[c].data_type : g_args.data_type[c];
            char *restStr = data_buffer + length_of_cols * i + cursor;
            int   lengthOfRest = (int)strlen(restStr);

            int index = 0;
            for (index = 0; index < lengthOfRest; index++) {
                if (restStr[index] == ',') {
                    break;
                }
            }

            char *tmpStr = calloc(1, index + 1);
            if (NULL == tmpStr) {
                errorPrint("%s", "failed to allocate memory\n");
                return -1;
            }

            strncpy(tmpStr, restStr, index);
            cursor += index + 1;  // skip ',' too
            char *tmpP;

            switch (data_type) {
                case TSDB_DATA_TYPE_INT:
                case TSDB_DATA_TYPE_UINT:
                    *((int32_t *)((uintptr_t) *
                                      (uintptr_t *)(sampleBindBatchArray +
                                                    sizeof(char *) * c) +
                                  sizeof(int32_t) * i)) = atoi(tmpStr);
                    break;

                case TSDB_DATA_TYPE_FLOAT:
                    *(float *)(((uintptr_t) *
                                    (uintptr_t *)(sampleBindBatchArray +
                                                  sizeof(char *) * c) +
                                sizeof(float) * i)) = (float)atof(tmpStr);
                    break;

                case TSDB_DATA_TYPE_DOUBLE:
                    *(double *)(((uintptr_t) *
                                     (uintptr_t *)(sampleBindBatchArray +
                                                   sizeof(char *) * c) +
                                 sizeof(double) * i)) = atof(tmpStr);
                    break;

                case TSDB_DATA_TYPE_TINYINT:
                case TSDB_DATA_TYPE_UTINYINT:
                    *((int8_t *)((uintptr_t) *
                                     (uintptr_t *)(sampleBindBatchArray +
                                                   sizeof(char *) * c) +
                                 sizeof(int8_t) * i)) = (int8_t)atoi(tmpStr);
                    break;

                case TSDB_DATA_TYPE_SMALLINT:
                case TSDB_DATA_TYPE_USMALLINT:
                    *((int16_t *)((uintptr_t) *
                                      (uintptr_t *)(sampleBindBatchArray +
                                                    sizeof(char *) * c) +
                                  sizeof(int16_t) * i)) = (int16_t)atoi(tmpStr);
                    break;

                case TSDB_DATA_TYPE_BIGINT:
                case TSDB_DATA_TYPE_UBIGINT:
                    *((int64_t *)((uintptr_t) *
                                      (uintptr_t *)(sampleBindBatchArray +
                                                    sizeof(char *) * c) +
                                  sizeof(int64_t) * i)) = (int64_t)atol(tmpStr);
                    break;

                case TSDB_DATA_TYPE_BOOL:
                    *((int8_t *)((uintptr_t) *
                                     (uintptr_t *)(sampleBindBatchArray +
                                                   sizeof(char *) * c) +
                                 sizeof(int8_t) * i)) = (int8_t)atoi(tmpStr);
                    break;

                case TSDB_DATA_TYPE_TIMESTAMP:
                    *((int64_t *)((uintptr_t) *
                                      (uintptr_t *)(sampleBindBatchArray +
                                                    sizeof(char *) * c) +
                                  sizeof(int64_t) * i)) = (int64_t)atol(tmpStr);
                    break;

                case TSDB_DATA_TYPE_BINARY:
                case TSDB_DATA_TYPE_NCHAR:
                    tmpP = (char *)(*(uintptr_t *)(sampleBindBatchArray +
                                                   sizeof(char *) * c));
                    strcpy(tmpP + i * (((stbInfo) ? stbInfo->columns[c].dataLen
                                                  : g_args.binwidth)),
                           tmpStr);
                    break;

                default:
                    break;
            }

            free(tmpStr);
        }
    }

    return 0;
}

static int parseSampleToStmtBatchForThread(threadInfo * pThreadInfo,
                                           SSuperTable *stbInfo,
                                           uint32_t timePrec, uint32_t batch) {
    uint32_t columnCount =
        (stbInfo) ? stbInfo->columnCount : g_args.columnCount;

    pThreadInfo->bind_ts_array = calloc(1, sizeof(int64_t) * batch);
    if (NULL == pThreadInfo->bind_ts_array) {
        errorPrint("%s", "failed to allocate memory\n");
        return -1;
    }

    pThreadInfo->bindParams =
        calloc(1, sizeof(TAOS_MULTI_BIND) * (columnCount + 1));
    if (NULL == pThreadInfo->bindParams) {
        errorPrint("%s", "failed to allocate memory\n");
        return -1;
    }

    pThreadInfo->is_null = calloc(1, batch);
    if (NULL == pThreadInfo->is_null) {
        errorPrint("%s", "failed to allocate memory\n");
        return -1;
    }

    return 0;
}

int parseStbSampleToStmtBatchForThread(threadInfo * pThreadInfo,
                                       SSuperTable *stbInfo, uint32_t timePrec,
                                       uint32_t batch) {
    return parseSampleToStmtBatchForThread(pThreadInfo, stbInfo, timePrec,
                                           batch);
}

int parseNtbSampleToStmtBatchForThread(threadInfo *pThreadInfo,
                                       uint32_t timePrec, uint32_t batch) {
    return parseSampleToStmtBatchForThread(pThreadInfo, NULL, timePrec, batch);
}

int32_t generateProgressiveDataWithoutStb(
    char *tableName, threadInfo *pThreadInfo, char *buffer, int64_t insertRows,
    uint64_t recordFrom, int64_t startTime, int64_t *pRemainderBufLen) {
    char *pstr = buffer;

    memset(buffer, 0, *pRemainderBufLen);

    int64_t headLen = generateSQLHeadWithoutStb(
        tableName, pThreadInfo->db_name, buffer, (int)(*pRemainderBufLen));

    if (headLen <= 0) {
        return 0;
    }
    pstr += headLen;
    *pRemainderBufLen -= headLen;

    int64_t dataLen;

    return generateDataTailWithoutStb(g_args.reqPerReq, pstr, *pRemainderBufLen,
                                      insertRows, recordFrom, startTime,
                                      /*pSamplePos, */ &dataLen);
}

int32_t generateSmlConstPart(char *sml, SSuperTable *stbInfo,
                             threadInfo *pThreadInfo, int tbSeq) {
    int64_t  dataLen = 0;
    uint64_t length = stbInfo->length_of_cols;
    if (stbInfo->lineProtocol == TSDB_SML_LINE_PROTOCOL) {
        dataLen +=
            snprintf(sml + dataLen, length - dataLen, "%s,id=%s%" PRIu64 "",
                     stbInfo->stbName, stbInfo->childTblPrefix,
                     tbSeq + pThreadInfo->start_table_from);
    } else if (stbInfo->lineProtocol == TSDB_SML_TELNET_PROTOCOL) {
        dataLen += snprintf(sml + dataLen, length - dataLen, "id=%s%" PRIu64 "",
                            stbInfo->childTblPrefix,
                            tbSeq + pThreadInfo->start_table_from);
    } else {
        errorPrint("unsupport schemaless protocol (%d)\n",
                   stbInfo->lineProtocol);
        return -1;
    }

    for (int j = 0; j < stbInfo->tagCount; j++) {
        tstrncpy(sml + dataLen,
                 (stbInfo->lineProtocol == TSDB_SML_LINE_PROTOCOL) ? "," : " ",
                 2);
        dataLen += 1;
        switch (stbInfo->tags[j].data_type) {
            case TSDB_DATA_TYPE_TIMESTAMP:
                errorPrint("Does not support data type %s as tag\n",
                           stbInfo->tags[j].dataType);
                return -1;
            case TSDB_DATA_TYPE_BOOL:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_bool_str());
                break;
            case TSDB_DATA_TYPE_TINYINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_tinyint_str());
                break;
            case TSDB_DATA_TYPE_UTINYINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_utinyint_str());
                break;
            case TSDB_DATA_TYPE_SMALLINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_smallint_str());
                break;
            case TSDB_DATA_TYPE_USMALLINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_usmallint_str());
                break;
            case TSDB_DATA_TYPE_INT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_int_str());
                break;
            case TSDB_DATA_TYPE_UINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_uint_str());
                break;
            case TSDB_DATA_TYPE_BIGINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_bigint_str());
                break;
            case TSDB_DATA_TYPE_UBIGINT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_ubigint_str());
                break;
            case TSDB_DATA_TYPE_FLOAT:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_float_str());
                break;
            case TSDB_DATA_TYPE_DOUBLE:
                dataLen += snprintf(sml + dataLen, length - dataLen, "t%d=%s",
                                    j, rand_double_str());
                break;
            case TSDB_DATA_TYPE_BINARY:
            case TSDB_DATA_TYPE_NCHAR:
                if (stbInfo->tags[j].dataLen > TSDB_MAX_BINARY_LEN) {
                    errorPrint("binary or nchar length overflow, maxsize:%u\n",
                               (uint32_t)TSDB_MAX_BINARY_LEN);
                    return -1;
                }
                char *buf = (char *)calloc(stbInfo->tags[j].dataLen + 1, 1);
                if (NULL == buf) {
                    errorPrint("%s", "failed to allocate memory\n");
                    return -1;
                }
                rand_string(buf, stbInfo->tags[j].dataLen);
                dataLen +=
                    snprintf(sml + dataLen, length - dataLen, "t%d=%s", j, buf);
                tmfree(buf);
                break;

            default:
                errorPrint("Unsupport data type %s\n",
                           stbInfo->tags[j].dataType);
                return -1;
        }
    }
    return 0;
}

int32_t generateSmlMutablePart(char *line, char *sml, SSuperTable *stbInfo,
                               threadInfo *pThreadInfo, int64_t timestamp) {
    int      dataLen = 0;
    uint64_t buffer = stbInfo->length_of_cols;
    if (stbInfo->lineProtocol == TSDB_SML_LINE_PROTOCOL) {
        dataLen = snprintf(line, buffer, "%s ", sml);
        for (uint32_t c = 0; c < stbInfo->columnCount; c++) {
            if (c != 0) {
                tstrncpy(line + dataLen, ",", 2);
                dataLen += 1;
            }
            switch (stbInfo->columns[c].data_type) {
                case TSDB_DATA_TYPE_TIMESTAMP:
                    errorPrint("Does not support data type %s as column\n",
                               stbInfo->columns[c].dataType);
                    return -1;
                case TSDB_DATA_TYPE_BOOL:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%s", c, rand_bool_str());
                    break;
                case TSDB_DATA_TYPE_TINYINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%si8", c, rand_tinyint_str());
                    break;
                case TSDB_DATA_TYPE_UTINYINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%su8", c, rand_utinyint_str());
                    break;
                case TSDB_DATA_TYPE_SMALLINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%si16", c, rand_smallint_str());
                    break;
                case TSDB_DATA_TYPE_USMALLINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%su16", c, rand_usmallint_str());
                    break;
                case TSDB_DATA_TYPE_INT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%si32", c, rand_int_str());
                    break;
                case TSDB_DATA_TYPE_UINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%su32", c, rand_uint_str());
                    break;
                case TSDB_DATA_TYPE_BIGINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%si64", c, rand_bigint_str());
                    break;
                case TSDB_DATA_TYPE_UBIGINT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%su64", c, rand_ubigint_str());
                    break;
                case TSDB_DATA_TYPE_FLOAT:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%sf32", c, rand_float_str());
                    break;
                case TSDB_DATA_TYPE_DOUBLE:
                    dataLen += snprintf(line + dataLen, buffer - dataLen,
                                        "c%d=%sf64", c, rand_double_str());
                    break;
                case TSDB_DATA_TYPE_BINARY:
                case TSDB_DATA_TYPE_NCHAR:
                    if (stbInfo->columns[c].dataLen > TSDB_MAX_BINARY_LEN) {
                        errorPrint(
                            "binary or nchar length overflow, "
                            "maxsize:%u\n",
                            (uint32_t)TSDB_MAX_BINARY_LEN);
                        return -1;
                    }
                    char *buf =
                        (char *)calloc(stbInfo->columns[c].dataLen + 1, 1);
                    if (NULL == buf) {
                        errorPrint("%s", "failed to allocate memory\n");
                        return -1;
                    }
                    rand_string(buf, stbInfo->columns[c].dataLen);
                    if (stbInfo->columns[c].data_type ==
                        TSDB_DATA_TYPE_BINARY) {
                        dataLen += snprintf(line + dataLen, buffer - dataLen,
                                            "c%d=\"%s\"", c, buf);
                    } else {
                        dataLen += snprintf(line + dataLen, buffer - dataLen,
                                            "c%d=L\"%s\"", c, buf);
                    }
                    tmfree(buf);
                    break;
                default:
                    errorPrint("Unsupport data type %s\n",
                               stbInfo->columns[c].dataType);
                    return -1;
            }
        }
        dataLen += snprintf(line + dataLen, buffer - dataLen, " %" PRId64 "",
                            timestamp);
        return 0;
    } else if (stbInfo->lineProtocol == TSDB_SML_TELNET_PROTOCOL) {
        switch (stbInfo->columns[0].data_type) {
            case TSDB_DATA_TYPE_BOOL:
                snprintf(line, buffer, "%s %" PRId64 " %s %s", stbInfo->stbName,
                         timestamp, rand_bool_str(), sml);
                break;
            case TSDB_DATA_TYPE_TINYINT:
                snprintf(line, buffer, "%s %" PRId64 " %si8 %s",
                         stbInfo->stbName, timestamp, rand_tinyint_str(), sml);
                break;
            case TSDB_DATA_TYPE_UTINYINT:
                snprintf(line, buffer, "%s %" PRId64 " %su8 %s",
                         stbInfo->stbName, timestamp, rand_utinyint_str(), sml);
                break;
            case TSDB_DATA_TYPE_SMALLINT:
                snprintf(line, buffer, "%s %" PRId64 " %si16 %s",
                         stbInfo->stbName, timestamp, rand_smallint_str(), sml);
                break;
            case TSDB_DATA_TYPE_USMALLINT:
                snprintf(line, buffer, "%s %" PRId64 " %su16 %s",
                         stbInfo->stbName, timestamp, rand_usmallint_str(),
                         sml);
                break;
            case TSDB_DATA_TYPE_INT:
                snprintf(line, buffer, "%s %" PRId64 " %si32 %s",
                         stbInfo->stbName, timestamp, rand_int_str(), sml);
                break;
            case TSDB_DATA_TYPE_UINT:
                snprintf(line, buffer, "%s %" PRId64 " %su32 %s",
                         stbInfo->stbName, timestamp, rand_uint_str(), sml);
                break;
            case TSDB_DATA_TYPE_BIGINT:
                snprintf(line, buffer, "%s %" PRId64 " %si64 %s",
                         stbInfo->stbName, timestamp, rand_bigint_str(), sml);
                break;
            case TSDB_DATA_TYPE_UBIGINT:
                snprintf(line, buffer, "%s %" PRId64 " %su64 %s",
                         stbInfo->stbName, timestamp, rand_ubigint_str(), sml);
                break;
            case TSDB_DATA_TYPE_FLOAT:
                snprintf(line, buffer, "%s %" PRId64 " %sf32 %s",
                         stbInfo->stbName, timestamp, rand_float_str(), sml);
                break;
            case TSDB_DATA_TYPE_DOUBLE:
                snprintf(line, buffer, "%s %" PRId64 " %sf64 %s",
                         stbInfo->stbName, timestamp, rand_double_str(), sml);
                break;
            case TSDB_DATA_TYPE_BINARY:
            case TSDB_DATA_TYPE_NCHAR:
                if (stbInfo->columns[0].dataLen > TSDB_MAX_BINARY_LEN) {
                    errorPrint("binary or nchar length overflow, maxsize:%u\n",
                               (uint32_t)TSDB_MAX_BINARY_LEN);
                    return -1;
                }
                char *buf = (char *)calloc(stbInfo->columns[0].dataLen + 1, 1);
                if (NULL == buf) {
                    errorPrint("%s", "failed to allocate memory\n");
                    return -1;
                }
                rand_string(buf, stbInfo->columns[0].dataLen);
                if (stbInfo->columns[0].data_type == TSDB_DATA_TYPE_BINARY) {
                    snprintf(line, buffer, "%s %" PRId64 " \"%s\" %s",
                             stbInfo->stbName, timestamp, buf, sml);
                } else {
                    snprintf(line, buffer, "%s %" PRId64 " L\"%s\" %s",
                             stbInfo->stbName, timestamp, buf, sml);
                }
                tmfree(buf);
                break;
            default:
                errorPrint("Unsupport data type %s\n",
                           stbInfo->columns[0].dataType);
                return -1;
        }
        return 0;
    } else {
        errorPrint("unsupport schemaless protocol(%d)\n",
                   stbInfo->lineProtocol);
        return -1;
    }
}

int32_t generateSmlJsonTags(cJSON *tagsList, SSuperTable *stbInfo,
                            threadInfo *pThreadInfo, int tbSeq) {
    int32_t code = -1;
    cJSON * tags = cJSON_CreateObject();
    char *  tbName = calloc(1, TSDB_TABLE_NAME_LEN);
    assert(tbName);
    snprintf(tbName, TSDB_TABLE_NAME_LEN, "%s%" PRIu64 "",
             stbInfo->childTblPrefix, tbSeq + pThreadInfo->start_table_from);
    cJSON_AddStringToObject(tags, "id", tbName);
    char *tagName = calloc(1, TSDB_MAX_TAGS);
    assert(tagName);
    for (int i = 0; i < stbInfo->tagCount; i++) {
        cJSON *tag = cJSON_CreateObject();
        snprintf(tagName, TSDB_MAX_TAGS, "t%d", i);
        switch (stbInfo->tags[i].data_type) {
            case TSDB_DATA_TYPE_BOOL:
                cJSON_AddNumberToObject(tag, "value", rand_bool());
                cJSON_AddStringToObject(tag, "type", "bool");
                break;
            case TSDB_DATA_TYPE_TINYINT:
                cJSON_AddNumberToObject(tag, "value", rand_tinyint());
                cJSON_AddStringToObject(tag, "type", "tinyint");
                break;
            case TSDB_DATA_TYPE_SMALLINT:
                cJSON_AddNumberToObject(tag, "value", rand_smallint());
                cJSON_AddStringToObject(tag, "type", "smallint");
                break;
            case TSDB_DATA_TYPE_INT:
                cJSON_AddNumberToObject(tag, "value", rand_int());
                cJSON_AddStringToObject(tag, "type", "int");
                break;
            case TSDB_DATA_TYPE_BIGINT:
                cJSON_AddNumberToObject(tag, "value", (double)rand_bigint());
                cJSON_AddStringToObject(tag, "type", "bigint");
                break;
            case TSDB_DATA_TYPE_FLOAT:
                cJSON_AddNumberToObject(tag, "value", rand_float());
                cJSON_AddStringToObject(tag, "type", "float");
                break;
            case TSDB_DATA_TYPE_DOUBLE:
                cJSON_AddNumberToObject(tag, "value", rand_double());
                cJSON_AddStringToObject(tag, "type", "double");
                break;
            case TSDB_DATA_TYPE_BINARY:
            case TSDB_DATA_TYPE_NCHAR:
                if (stbInfo->tags[i].dataLen > TSDB_MAX_BINARY_LEN) {
                    errorPrint("binary or nchar length overflow, maxsize:%u\n",
                               (uint32_t)TSDB_MAX_BINARY_LEN);
                    goto free_of_generate_sml_json_tag;
                }
                char *buf = (char *)calloc(stbInfo->tags[i].dataLen + 1, 1);
                if (NULL == buf) {
                    errorPrint("%s", "failed to allocate memory\n");
                    goto free_of_generate_sml_json_tag;
                }
                rand_string(buf, stbInfo->tags[i].dataLen);
                if (stbInfo->tags[i].data_type == TSDB_DATA_TYPE_BINARY) {
                    cJSON_AddStringToObject(tag, "value", buf);
                    cJSON_AddStringToObject(tag, "type", "binary");
                } else {
                    cJSON_AddStringToObject(tag, "value", buf);
                    cJSON_AddStringToObject(tag, "type", "nchar");
                }
                tmfree(buf);
                break;
            default:
                errorPrint(
                    "unsupport data type (%s) for schemaless json "
                    "protocol\n",
                    stbInfo->tags[i].dataType);
                goto free_of_generate_sml_json_tag;
        }
        cJSON_AddItemToObject(tags, tagName, tag);
    }
    cJSON_AddItemToArray(tagsList, tags);
    code = 0;
free_of_generate_sml_json_tag:
    tmfree(tagName);
    tmfree(tbName);
    return code;
}

int32_t generateSmlJsonCols(cJSON *array, cJSON *tag, SSuperTable *stbInfo,
                            threadInfo *pThreadInfo, int64_t timestamp) {
    cJSON *record = cJSON_CreateObject();
    cJSON *ts = cJSON_CreateObject();
    cJSON_AddNumberToObject(ts, "value", (double)timestamp);
    if (pThreadInfo->time_precision == TSDB_TIME_PRECISION_MILLI) {
        cJSON_AddStringToObject(ts, "type", "ms");
    } else if (pThreadInfo->time_precision == TSDB_TIME_PRECISION_MICRO) {
        cJSON_AddStringToObject(ts, "type", "us");
    } else if (pThreadInfo->time_precision == TSDB_TIME_PRECISION_NANO) {
        cJSON_AddStringToObject(ts, "type", "ns");
    } else {
        errorPrint("unsupport time precision %d\n",
                   pThreadInfo->time_precision);
        return -1;
    }
    cJSON *value = cJSON_CreateObject();
    switch (stbInfo->columns[0].data_type) {
        case TSDB_DATA_TYPE_BOOL:
            cJSON_AddNumberToObject(value, "value", rand_bool());
            cJSON_AddStringToObject(value, "type", "bool");
            break;
        case TSDB_DATA_TYPE_TINYINT:
            cJSON_AddNumberToObject(value, "value", rand_tinyint());
            cJSON_AddStringToObject(value, "type", "tinyint");
            break;
        case TSDB_DATA_TYPE_SMALLINT:
            cJSON_AddNumberToObject(value, "value", rand_smallint());
            cJSON_AddStringToObject(value, "type", "smallint");
            break;
        case TSDB_DATA_TYPE_INT:
            cJSON_AddNumberToObject(value, "value", rand_int());
            cJSON_AddStringToObject(value, "type", "int");
            break;
        case TSDB_DATA_TYPE_BIGINT:
            cJSON_AddNumberToObject(value, "value", (double)rand_bigint());
            cJSON_AddStringToObject(value, "type", "bigint");
            break;
        case TSDB_DATA_TYPE_FLOAT:
            cJSON_AddNumberToObject(value, "value", rand_float());
            cJSON_AddStringToObject(value, "type", "float");
            break;
        case TSDB_DATA_TYPE_DOUBLE:
            cJSON_AddNumberToObject(value, "value", rand_double());
            cJSON_AddStringToObject(value, "type", "double");
            break;
        case TSDB_DATA_TYPE_BINARY:
        case TSDB_DATA_TYPE_NCHAR:
            if (stbInfo->columns[0].dataLen > TSDB_MAX_BINARY_LEN) {
                errorPrint("binary or nchar length overflow, maxsize:%u\n",
                           (uint32_t)TSDB_MAX_BINARY_LEN);
                return -1;
            }
            char *buf = (char *)calloc(stbInfo->columns[0].dataLen + 1, 1);
            if (NULL == buf) {
                errorPrint("%s", "failed to allocate memory\n");
                return -1;
            }
            rand_string(buf, stbInfo->columns[0].dataLen);
            if (stbInfo->columns[0].data_type == TSDB_DATA_TYPE_BINARY) {
                cJSON_AddStringToObject(value, "value", buf);
                cJSON_AddStringToObject(value, "type", "binary");
            } else {
                cJSON_AddStringToObject(value, "value", buf);
                cJSON_AddStringToObject(value, "type", "nchar");
            }
            tmfree(buf);
            break;
        default:
            errorPrint(
                "unsupport data type (%s) for schemaless json "
                "protocol\n",
                stbInfo->columns[0].dataType);
            return -1;
    }
    cJSON_AddItemToObject(record, "timestamp", ts);
    cJSON_AddItemToObject(record, "value", value);
    cJSON_AddItemToObject(record, "tags", tag);
    cJSON_AddStringToObject(record, "metric", stbInfo->stbName);
    cJSON_AddItemToArray(array, record);
    return 0;
}
