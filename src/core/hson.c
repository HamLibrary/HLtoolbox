#include <hson.h>
#include <stack.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// What can I do to make this I guess more maintainable?
// Add macros to things written multiple times that are needed to be the same.
#define _IS_FIRST_VALUE (hson->str[hson->len - 1] == '[' || hson->str[hson->len - 1] == '{')

hson hson_create()
{
    char *str = malloc(sizeof(char));
    str[0] = '{';

    stack stk = stack_create(sizeof(u8));
    u8 flag = HSON_FLAG_IDLE;
    stack_push(&stk, &flag);

    return (hson) {
        .len = 1,
        .str = str,
        .flags = stk
    };
}

hson hson_modify(char *hson_str)
{
    u32 len = strlen(hson_str);
    hson_str = realloc(hson_str, len - 2);

    stack stk = stack_create(sizeof(u8));
    u8 flag = HSON_FLAG_IDLE;
    stack_push(&stk, &flag);

    return (hson) {
        .len = len - 2,
        .str = hson_str,
        .flags = stk
    };
}

void hson_free(hson *hson)
{
    hson->len = 0;
    free(hson->str);
    stack_free(&hson->flags);
}

// If speed is an issue here, use a jump table.
void hson_add_u8(hson *hson, const char *key, u32 key_len, u8 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[4];
    sprintf(numstr, "%u", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

// If speed is an issue here, use a jump table.
void hson_add_u16(hson *hson, const char *key, u32 key_len, u16 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[6];
    sprintf(numstr, "%u", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_u32(hson *hson, const char *key, u32 key_len, u32 value)
{
u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[11];
    sprintf(numstr, "%u", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_u64(hson *hson, const char *key, u32 key_len, u64 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[21];
    sprintf(numstr, "%lu", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_i8(hson *hson, const char *key, u32 key_len, i8 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[5];
    sprintf(numstr, "%d", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_i16(hson *hson, const char *key, u32 key_len, i16 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[7];
    sprintf(numstr, "%d", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_i32(hson *hson, const char *key, u32 key_len, i32 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[12];
    sprintf(numstr, "%d", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_i64(hson *hson, const char *key, u32 key_len, i64 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[22];
    sprintf(numstr, "%ld", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_f32(hson *hson, const char *key, u32 key_len, f32 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[14];
    sprintf(numstr, "%E", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_f64(hson *hson, const char *key, u32 key_len, f64 value)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    char numstr[15];
    sprintf(numstr, "%E", value);
    u8 num_len = strlen(numstr);

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, numstr, num_len);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + num_len + !_IS_FIRST_VALUE;
}

void hson_add_string(hson *hson, const char *key, u32 key_len, const char *str, u32 str_len)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 2 + str_len + !_IS_FIRST_VALUE);

    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    hson->str[hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE + 1, str, str_len);
    hson->str[hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE + str_len + 1] = '"';
    
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 2 + str_len + !_IS_FIRST_VALUE;
}

void hson_add_bool(hson *hson, const char *key, u32 key_len, u32 bool)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + (bool == 0) * 5 + (bool != 0) * 4 + !_IS_FIRST_VALUE);
    
    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, (bool == 0) ? "false" : "true", (bool == 0) * 5 + (bool != 0) * 4);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + (bool == 0) * 5 + (bool != 0) * 4 + !_IS_FIRST_VALUE;
}

void hson_add_null(hson *hson, const char *key, u32 key_len)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 4 + !_IS_FIRST_VALUE);
    
    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';

    memcpy(hson->str + hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE, "null", 4);
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 4 + !_IS_FIRST_VALUE;
}

void hson_start_array(hson *hson, const char *key, u32 key_len)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 1 + !_IS_FIRST_VALUE);
    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2)  * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';
    hson->str[hson->len + (key_len + 3)  * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '[';
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 1 + !_IS_FIRST_VALUE;

    u8 flag_add = HSON_FLAG_ARRAY;
    stack_push(&hson->flags, &flag_add);
}

void hson_end_array(hson *hson)
{
    ++hson->len;
    hson->str = realloc(hson->str, hson->len);
    hson->str[hson->len - 1] = ']';
    stack_pop(&hson->flags);
}

void hson_start_object(hson *hson, const char *key, u32 key_len)
{
    u8 flag = *((u8 *)stack_peek(&hson->flags));

    hson->str = realloc(hson->str, hson->len + (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 1 + !_IS_FIRST_VALUE);
    hson->str[hson->len] = ',';
    hson->str[hson->len + !_IS_FIRST_VALUE] = '"';
    memcpy(hson->str + hson->len + 1 + !_IS_FIRST_VALUE, key, key_len * (flag != HSON_FLAG_ARRAY));
    hson->str[hson->len + (key_len + 1) * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '"';
    hson->str[hson->len + (key_len + 2)  * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = ':';
    hson->str[hson->len + (key_len + 3)  * (flag != HSON_FLAG_ARRAY) + !_IS_FIRST_VALUE] = '{';
    hson->len += (key_len + 3) * (flag != HSON_FLAG_ARRAY) + 1 + !_IS_FIRST_VALUE;

    u8 flag_add = HSON_FLAG_OBJECT;
    stack_push(&hson->flags, &flag_add);
}

void hson_end_object(hson *hson)
{
    ++hson->len;
    hson->str = realloc(hson->str, hson->len);
    hson->str[hson->len - 1] = '}';
    stack_pop(&hson->flags);
}

void hson_finish(hson *hson)
{
    ++hson->len;
    hson->str = realloc(hson->str, hson->len + 1);
    hson->str[hson->len - 1] = '}';
    hson->str[hson->len] = '\0';
    stack_free(&hson->flags);
}

void hson_beautify(hson *hson)
{

}

void hson_uglify(hson *hson)
{

}

