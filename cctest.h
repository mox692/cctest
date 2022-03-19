#include <stdio.h>

#define MAX_MSG_SIZE 1000
#define MAX_MSG_CHAR_SIZE 100

// declare error message buffer.
#ifndef CC_TEST_START
#define CC_TEST_START                 \
    {                                 \
        char *messages[MAX_MSG_SIZE]; \
        int pos = 0;                  \
        printf("==== Test Start ===\n");
#else
#error macro CC_TEST_START is already defined.
#endif

// build test result message and store it in messages[].
#ifndef CC_TEST_WRITE
#define CC_TEST_WRITE(message, case_name, a, b) ( \
    {                                             \
        char str[MAX_MSG_CHAR_SIZE];              \
        sprintf(str, message, case_name, a, b);   \
        messages[pos] = str;                      \
        pos++;                                    \
    })
#else
#error macro CC_TEST_WRITE is already defined.
#endif

// Assertion an int type variable.
// The first arg `case_name` expects a char pointer.
#ifndef CC_TEST_ASSERT_INT
#define ASSERT_INT(case_name, expected, got) (                                  \
    {                                                                           \
        if (expected == got)                                                    \
        {                                                                       \
            printf("-- TEST: %s ... ok\n", case_name);                          \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            printf("-- TEST: %s ... err\n", case_name);                         \
            CC_TEST_WRITE("%s: expected %d, got %d", case_name, expected, got); \
        }                                                                       \
    })
#else
#error macro CC_TEST_ASSERT_INT is already defined.
#endif

// Show failed test name and detailed text.
#ifndef CC_TEST_END
#define CC_TEST_END                                \
    if (pos == 0)                                  \
    {                                              \
        printf("==== All Test Passed ===\n");      \
    }                                              \
    else                                           \
    {                                              \
        for (int i = 0; i < pos; i++)              \
        {                                          \
            printf("**Error** %s\n", messages[i]); \
        }                                          \
    }                                              \
    }
#else
#error macro CC_TEST_END is already defined.
#endif