#include <libhangman/functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Function to get a random word
int compare_chars(const void* a, const void* b)
{
    char char_a = *(const char*)a;
    char char_b = *(const char*)b;
    if (char_a < char_b)
        return -1;
    if (char_a > char_b)
        return 1;
    return 0;
}

void get_word(char* word)
{
    char* word_list[] = {"bird", "home", "star", "wave", "tree", "house", "horse", "water", "apple", "cream", "orange", "flower", "banana", "system", "memory", "processor", "scripting", "dormitory", "universal", "pineapple"};
    int num_words = sizeof(word_list) / sizeof(word_list[0]);
    int index = rand() % num_words;
    strcpy(word, word_list[index]);
}

// Function to check if the player has won
int has_won(char* word, char* guesses)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (strchr(guesses, word[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}
