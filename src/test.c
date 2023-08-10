
#if !defined TEST_STACK && !defined TEST_HSON && !defined TEST_HCSV
    #define TEST_ALL
#endif


// might remove these pre-processing
#if defined TEST_ALL || defined TEST_STACK
    #include "test_stack.c"
#endif

#if defined TEST_ALL || defined TEST_HSON
    #include "test_hson.c"
#endif

#if defined TEST_ALL || defined TEST_HCSV
    #include "test_hcsv.c"
#endif

int main()
{
    #if defined TEST_ALL || defined TEST_STACK
        test_stack();
    #endif

    #if defined TEST_ALL || defined TEST_HSON
        test_hson();
    #endif

    #if defined TEST_ALL || defined TEST_HCSV
        test_hcsv();
    #endif
}
