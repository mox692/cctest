#include <stdio.h>
#include <string.h>

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
#ifndef ASSERT_INT
#define ASSERT_INT(case_name, expected, got) (                                  \
    {                                                                           \
        if (expected == got)                                                    \
        {                                                                       \
            printf("-- TEST: %s ... ok\n", case_name);                          \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            fprintf(stderr, "-- TEST: %s ... err\n", case_name);                \
            CC_TEST_WRITE("%s: expected %d, got %d", case_name, expected, got); \
        }                                                                       \
    })
#else
#error macro ASSERT_INT is already defined.
#endif

// Assert an char* type variable.
// It uses memcmp internaly
#ifndef ASSERT_NSTR
#define ASSERT_NSTR(case_name, expected, got, size) (                           \
    {                                                                           \
        if (memcmp(expected, got, size) == 0)                                   \
        {                                                                       \
            printf("-- TEST: %s ... ok\n", case_name);                          \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            fprintf(stderr, "-- TEST: %s ... err\n", case_name);                \
            CC_TEST_WRITE("%s: expected %s, got %s", case_name, expected, got); \
        }                                                                       \
    })
#else
#error macro ASSERT_NSTR is already defined.
#endif

// Assert an char* type variable.
// It uses memcmp internaly and read until EOF. (Use carefully)
#ifndef ASSERT_STR
#define ASSERT_STR(case_name, str, cmp) (                                                \
    {                                                                                    \
        bool ok = 1;                                                                     \
        for (int offset = 0; *(str + offset) != '\0', *(cmp + offset) != '\0'; offset++) \
        {                                                                                \
            printf("%c, %c\n", *(str + offset), *(cmp + offset));                        \
            if (*(str + offset) != *(cmp + offset))                                      \
            {                                                                            \
                ok = 0;                                                                  \
                break;                                                                   \
            }                                                                            \
        }                                                                                \
        if (ok)                                                                          \
        {                                                                                \
            printf("-- TEST: %s ... ok\n", case_name);                                   \
        }                                                                                \
        else                                                                             \
        {                                                                                \
            fprintf(stderr, "-- TEST: %s ... err\n", case_name);                         \
            CC_TEST_WRITE("%s: expected %s, got %s", case_name, str, cmp);               \
        }                                                                                \
    })
#else
#error macro ASSERT_STR is already defined.
#endif

#if defined(__cplusplus)
template <class T>
inline bool eq(const T object1, const T object2)
{
    return T::eq(object1, object2);
}

#define EQ(case_name, obj1, obj2) (                              \
    {                                                            \
        if (eq(obj1, obj2))                                      \
        {                                                        \
            printf("-- TEST: %s ... ok\n", case_name);           \
        }                                                        \
        else                                                     \
        {                                                        \
            fprintf(stderr, "-- TEST: %s ... err\n", case_name); \
            fprintf(stderr, "%s: failed.\n", case_name);         \
        }                                                        \
    })
#endif

// Show failed test name and detailed text.
#ifndef CC_TEST_END
#define CC_TEST_END                                         \
    if (pos == 0)                                           \
    {                                                       \
        printf("==== All Test Passed ===\n");               \
    }                                                       \
    else                                                    \
    {                                                       \
        for (int i = 0; i < pos; i++)                       \
        {                                                   \
            fprintf(stderr, "**Error** %s\n", messages[i]); \
        }                                                   \
        exit(1);                                            \
    }                                                       \
    }
#else
#error macro CC_TEST_END is already defined.
#endif
