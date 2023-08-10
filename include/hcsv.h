#pragma once
#include <hl_type.h>

typedef struct
{
    // TODO
} hcsv;

typedef struct
{
    char *header;
    char ***records;
} pcsv;

pcsv pcsv_no_knowing(const char *csv);
pcsv pcsv_semi_knowing(const char *csv, u32 has_header);
pcsv pcsv_all_knowing(const char *csv, u32 has_header, u32 header_len);


// maybe add some functions to manually decide how and when
// to parse the csv file
