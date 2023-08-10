#include <stdio.h>
#include <hson.h>

void test_hson()
{
    printf("HSON TEST START\n");
    hson json;

    json = hson_create();
    // Empty array and object
    hson_start_array(&json, "AE", 2);
    hson_end_array(&json);
    hson_start_object(&json, "OE", 2);
    hson_end_object(&json);
    // array with numbers
    hson_start_array(&json, "AN", 2);
    hson_add_u8(&json, "", 0, U8MAX);
    hson_add_u16(&json, "Ig", 2, U16MAX);
    hson_add_u32(&json, "nor", 3, U32MAX);
    hson_add_u64(&json, "ed", 2, U64MAX);
    hson_add_i8(&json, "", 0, I8MIN);
    hson_add_i16(&json, "Ig", 0, I16MIN);
    hson_add_i32(&json, "nor", 9, I32MIN);
    hson_add_i64(&json, "ed", 1, I64MIN);
    hson_add_f32(&json, "", 0, F32MAX);
    hson_add_f32(&json, "", 0, F32MIN);
    hson_add_f32(&json, "", 0, -F32MAX);
    hson_add_f32(&json, "", 0, -F32MIN);
    hson_add_f64(&json, "", 0, F64MAX);
    hson_add_f64(&json, "", 0, F64MIN);
    hson_add_f64(&json, "", 0, -F64MAX);
    hson_add_f64(&json, "", 0, -F64MIN);
    hson_end_array(&json);
    // array with different data types
    hson_start_array(&json, "AU", 2);
    hson_add_u32(&json, "", 0, 400);
    hson_add_bool(&json, "", 0, 0);
    hson_add_bool(&json, "", 0, 1);
    hson_add_null(&json, "", 0);
    hson_add_string(&json, "", 0, "cool", 4);
    hson_end_array(&json);
    // object with different data types
    hson_start_object(&json, "OU", 2);
    hson_add_u32(&json, "N", 1, 400);
    hson_add_bool(&json, "T", 1, 0);
    hson_add_bool(&json, "F", 1, 1);
    hson_add_null(&json, "N", 1);
    hson_add_string(&json, "S", 1, "cool", 4);
    hson_end_object(&json);
    // array with array
    hson_start_array(&json, "AI", 2);
    hson_start_array(&json, "Ignored", 7);
    hson_end_array(&json);
    hson_start_array(&json, "Ignored", 7);
    hson_end_array(&json);
    hson_end_array(&json);
    // object with object
    hson_start_object(&json, "OI", 2);
    hson_start_object(&json, "OE1", 3);
    hson_end_object(&json);
    hson_start_object(&json, "OE2", 3);
    hson_end_object(&json);
    hson_end_object(&json);
    // Complicated
    hson_start_object(&json, "C", 1);
    hson_add_string(&json, "NAME", 4, "hson", 4);
    hson_add_u32(&json, "AGE", 3, 32);
    hson_add_bool(&json, "HUMAN", 5, 0);
    hson_start_array(&json, "DATA", 4);
    hson_add_f32(&json, "", 0, F32MIN);
    hson_add_f32(&json, "", 0, -F32MIN);
    hson_add_f64(&json, "", 0, F64MAX);
    hson_add_f64(&json, "", 0, -F64MAX);
    hson_start_object(&json, "", 0);
    hson_add_f32(&json, "ran", 3, 21.034828);
    hson_end_object(&json);
    hson_end_array(&json);
    hson_end_object(&json);

    hson_finish(&json);
    printf("[JSON]: %s\n", json.str);
    hson_free(&json);

    // Examples of how u can mess it up
    // ...
    json = hson_create();
    //mismatch
    hson_start_array(&json, "AO", 2);
    hson_end_object(&json);

    printf("HSON TEST END\n");
}
