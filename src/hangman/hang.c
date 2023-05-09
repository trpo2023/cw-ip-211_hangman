#include <libhangman/functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LEN 9

// Main function to run the game
int main()
{
    char usedlet[100];
    int usedcount = 0;
    int guessesleft;
    char word[MAX_WORD_LEN + 1];
    char guesses[MAX_WORD_LEN + 1] = "";
    char display_word[MAX_WORD_LEN * 2 + 1];
    int num_guesses = 0;
    int max_guesses = 6;
    int difficulty;
    char input[100];

    srand(time(NULL));

    printf("Welcome to Hangman!\n");

    do {
        printf("Select difficulty: (1) Easy, (2) Medium, (3) Hard, (4) Impossible\n");
        fgets(input, 10, stdin);
        difficulty = atoi(input);
    } while (difficulty < 1 || difficulty > 4);

    if (difficulty == 1) {
        max_guesses = 8;
        get_word(word);
        while (strlen(word) != 4) {
            get_word(word);
        }
    } else if (difficulty == 2) {
        max_guesses = 7;
        get_word(word);
        while (strlen(word) != 5) {
            get_word(word);
        }
    } else if (difficulty == 3) {
        max_guesses = 5;
        get_word(word);
        while (strlen(word) != 6) {
            get_word(word);
        }
    } else {
        max_guesses = 3;
        get_word(word);
        while (strlen(word) != 9) {
            get_word(word);
        }
    }

    printf("The word has %ld letters. You have %d guesses.\n", strlen(word), max_guesses);

    // initialize display_word with underscores
    for (unsigned i = 0; i < strlen(word) * 2; i += 2) {
        display_word[i] = '_';
        display_word[i + 1] = ' ';
    }
    display_word[strlen(word) * 2 - 1] = '\0';

    while (num_guesses < max_guesses) {
        char guess;
        printf("\nWord: %s\n", display_word);
        printf("Guess a letter: ");
        fgets(input, 100, stdin);
        guess = input[0];
        // Check if the letter has already been guessed
        if (strchr(guesses, guess) != NULL) {
            printf("You already guessed that letter. Try again.\n");
            printf("Used letters: %s\n", usedlet);
            continue;
        }

        guesses[strlen(guesses)] = guess;

        // Check if the guess is correct
        if (strchr(word, guess) != NULL) {
            printf("Correct!\n");
            usedlet[usedcount] = guess;
            usedcount += 1;
            qsort(usedlet, usedcount, sizeof(char), compare_chars);
            printf("Used letters: %s\n", usedlet);
            for (unsigned i = 0; i < strlen(word); i++) {
                if (word[i] == guess) {
                    display_word[i * 2] = guess;
                }
            }
        } else {
            num_guesses++;
            guessesleft = (max_guesses - num_guesses);
            printf("Incorrect! You have %d guesses left!\n", guessesleft);
            usedlet[usedcount] = guess;
            usedcount += 1;
            qsort(usedlet, usedcount, sizeof(char), compare_chars);
            printf("Used letters: %s\n", usedlet);
        }

        // Check if the player has won
        if (has_won(word, guesses)) {
            printf("Congratulations! You won!\n");
            printf("The word was: %s\n", word);
            return 0;
        }
    }

    printf("\nSorry, you ran out of guesses. The word was '%s'.\n", word);
    return 0;
}
