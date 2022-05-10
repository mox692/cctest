#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declare error message buffer.
#ifndef CC_TEST_START
#define CC_TEST_START       \
    {                       \
        static int pos = 0; \
        printf("==== Test Start ===\n");
#else
#error macro CC_TEST_START is already defined.
#endif

#ifndef _ERROR
#define _ERROR pos++;
#else
#error macro _ERROR is already defined.
#endif

// [deplicated] build test result message and store it in messages[].
#ifndef CC_TEST_WRITE
#define CC_TEST_WRITE(message, case_name, ...) (                     \
    {                                                                \
        char str[100];                                               \
        sprintf(str, message, case_name __VA_OPT__(, ) __VA_ARGS__); \
        messages[pos] = str;                                         \
        pos++;                                                       \
    })
#else
#error macro CC_TEST_WRITE is already defined.
#endif

// Assertion an int type variable.
// The first arg `case_name` expects a char pointer.
#ifndef ASSERT_INT
#define ASSERT_INT(case_name, expected, got) (                                                          \
    {                                                                                                   \
        if (expected == got)                                                                            \
        {                                                                                               \
            printf("-- TEST: %s ... ok✅\n", case_name);                                                 \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            fprintf(stderr, "-- TEST: %s ... err❌\nexpect %d, but got %d\n", case_name, expected, got); \
            _ERROR                                                                                      \
        }                                                                                               \
    })
#else
#error macro ASSERT_INT is already defined.
#endif

// Assert an char* type variable.
// It uses memcmp internaly
#ifndef ASSERT_NSTR
#define ASSERT_NSTR(case_name, expected, got, size) (             \
    {                                                             \
        if (memcmp(expected, got, size) == 0)                     \
        {                                                         \
            printf("-- TEST: %s ... ok✅\n", case_name);           \
        }                                                         \
        else                                                      \
        {                                                         \
            fprintf(stderr, "-- TEST: %s ... err❌\n", case_name); \
            _ERROR                                                \
        }                                                         \
    })
#else
#error macro ASSERT_NSTR is already defined.
#endif

// Assert an char* type variable.
// It uses memcmp internaly and read until EOF. (Use carefully)
#ifndef ASSERT_STR
#define ASSERT_STR(case_name, str, cmp) (                                                           \
    {                                                                                               \
        int ok = 1;                                                                                 \
        int offset = 0;                                                                             \
        for (char cur_char = *str; ok == 1, cur_char != '\0'; offset++, cur_char = *(str + offset)) \
        {                                                                                           \
            if (cur_char != *(cmp + offset))                                                        \
            {                                                                                       \
                ok = 0;                                                                             \
                break;                                                                              \
            }                                                                                       \
        }                                                                                           \
        if (*(cmp + offset) != '\0')                                                                \
            ok = 0;                                                                                 \
        if (ok)                                                                                     \
        {                                                                                           \
            printf("-- TEST: %s ... ok✅\n", case_name);                                             \
        }                                                                                           \
        else                                                                                        \
        {                                                                                           \
            fprintf(stderr, "-- TEST: %s ... err❌\ngot %s, and %s\n", case_name, str, cmp);         \
            _ERROR                                                                                  \
        }                                                                                           \
    })
#else
#error macro ASSERT_STR is already defined.
#endif

#if defined(__cplusplus)
#include <iostream>
template <class T>
inline bool eq(const T object1, const T object2)
{
    return object1 == object2;
}

#define EQ(case_name, obj1, obj2) (                               \
    {                                                             \
        if (eq(obj1, obj2))                                       \
        {                                                         \
            printf("-- TEST: %s ... ok✅\n", case_name);           \
        }                                                         \
        else                                                      \
        {                                                         \
            using namespace std;                                  \
            fprintf(stderr, "-- TEST: %s ... err❌\n", case_name); \
            std::cout << "got "                                   \
                      << obj1                                     \
                      << ", and "                                 \
                      << obj2                                     \
                      << std::endl;                               \
            _ERROR                                                \
        }                                                         \
    })
#endif

// TODO: Show failed test name and detailed text.
#ifndef CC_TEST_END
#define CC_TEST_END                                 \
    if (pos == 0)                                   \
    {                                               \
        printf("==== All Test Passed 🎉===\n");      \
    }                                               \
    else                                            \
    {                                               \
        fprintf(stderr, "** Some tests failed \n"); \
        exit(1);                                    \
    }                                               \
    }
#else
#error macro CC_TEST_END is already defined.
#endif
