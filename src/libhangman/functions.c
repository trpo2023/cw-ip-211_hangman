#include <libhangman/functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 9

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
    FILE* file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Failed to open dictionary file.\n");
        printf("Create the dictionary.txt file in /bin directory.\n");
        printf("Dictionary is stored 1 word per line.\n");
        exit(1);
    }
    // Count the number of words in the file
    int num_words = 0;
    char buffer[MAX_WORD_LEN + 1];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num_words++;
    }

    // Reset the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Choose a random word from the file
    int index = rand() % num_words;
    int current_word = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (current_word == index) {
            // Remove the newline character at the end
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(word, buffer);
            break;
        }
        current_word++;
    }

    fclose(file);
}

// Function to check if the player has won
int is_win(char* word, char* guesses)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (strchr(guesses, word[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}
