#pragma once

#include <hl_type.h>
#include <stack.h>

#define HSON_FLAG_IDLE     0
#define HSON_FLAG_ARRAY    1
#define HSON_FLAG_OBJECT   2

typedef struct
{
    usize len;
    char *str;
    stack flags;
} hson;

typedef struct
{
    // TODO
} pson;

hson hson_create();
hson hson_modify(char *hson_str);
void hson_free(hson *hson);

void hson_add_u8(hson *hson, const char *key, u32 key_len, u8 value);
void hson_add_u16(hson *hson, const char *key, u32 key_len, u16 value);
void hson_add_u32(hson *hson, const char *key, u32 key_len, u32 value);
void hson_add_u64(hson *hson, const char *key, u32 key_len, u64 value);
void hson_add_i8(hson *hson, const char *key, u32 key_len, i8 value);
void hson_add_i16(hson *hson, const char *key, u32 key_len, i16 value);
void hson_add_i32(hson *hson, const char *key, u32 key_len, i32 value);
void hson_add_i64(hson *hson, const char *key, u32 key_len, i64 value);
void hson_add_f32(hson *hson, const char *key, u32 key_len, f32 value);
void hson_add_f64(hson *hson, const char *key, u32 key_len, f64 value);

void hson_add_string(hson *hson, const char *key, u32 key_len, const char *str, u32 str_len);
void hson_add_bool(hson *hson, const char *key, u32 key_len, u32 bool);
void hson_add_null(hson *hson, const char *key, u32 key_len);

void hson_start_array(hson *hson, const char *key, u32 key_len);
void hson_end_array(hson *hson);
void hson_start_object(hson *hson, const char *key, u32 key_len);
void hson_end_object(hson *hson);

void hson_finish(hson *hson);
void hson_beautify(hson *hson);
void hson_uglify(hson *hson);
