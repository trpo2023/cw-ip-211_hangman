#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ctest.h"
#include "libhangman/functions.h"

CTEST(test, compare_chars1)
{
    char* char_a = "a";
    char* char_b = "b";
    bool result = compare_chars(char_a, char_b);
    ASSERT_TRUE(result);
}

CTEST(test, compare_chars2)
{
    char* char_a = "b";
    char* char_b = "b";
    bool result = compare_chars(char_a, char_b);
    ASSERT_FALSE(result);
}

CTEST(test, is_win1)
{
    char* word_1 = "hang";
    char* guess_1 = "hang";
    bool result = is_win(word_1, guess_1);
    ASSERT_TRUE(result);
}

CTEST(test, is_win2)
{
    char* word_1 = "hangman";
    char* guess_1 = "hangdan";
    bool result = is_win(word_1, guess_1);
    ASSERT_FALSE(result);
}
