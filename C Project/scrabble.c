// Pull Libs
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Define constants
#define ALPHABET_SIZE 26
#define MAX_PLAYERS 4
#define MIN_PLAYERS 2

// Prototypes
void get_alphabet(char ALPHABET[]);
void get_player_words(int pcount, string words[]);
int get_player_count(void);
int get_player_score(char ALPHABET[], const int SCORES[], string word);
int compare_scores(int player_scores[], int playercount);

// MAIN FUNCTION
int main(void)
{
    // Var Init
    const int SCORES[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // Static scores, a-z
    char ALPHABET[ALPHABET_SIZE];
    int player_count = get_player_count(); // Get player count w/ error prevention
    string words[player_count];            // Get word count from playercount
    int word_scores[player_count];         // Player score array

    get_alphabet(ALPHABET);                // Return alphabet
    get_player_words(player_count, words); // Return player words
    for (int i = 0; i < player_count; i++) // For each player, calc scoring
    {
        word_scores[i] = get_player_score(ALPHABET, SCORES, words[i]);
    }
    int winner = compare_scores(word_scores, player_count);
    printf("Player %i is the winner! score: %i\n", winner + 1, word_scores[winner]);
    for (int i = 0; i < player_count; i++) // For each player, print scoring
    {
        printf("Player %i scored %i\n", i + 1, word_scores[i]);
    }
}

// FUNCTIONS
void get_alphabet(char ALPHABET[]) // Get alphabet
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        ALPHABET[i] = 'a' + i;
    }
}

void get_player_words(int pcount, string words[]) // Get words based on player count
{
    for (int i = 0; i < pcount; i++)
    {
        words[i] = get_string("Player %i's Word: ", i + 1);
    }
}

int get_player_count(void) // Get player count within defined min/max
{
    int i = 0;
    while (i < MIN_PLAYERS || i > MAX_PLAYERS)
    {
        i = get_int("How many players? (%i-%i): ", MIN_PLAYERS, MAX_PLAYERS);
        if (i < MIN_PLAYERS || i > MAX_PLAYERS)
        {
            printf("Wrong player count entered: %i\n", i);
        }
    }
    return i;
}

int get_player_score(char ALPHABET[], const int SCORES[], string word)
{
    int player_score = 0;
    int word_size = strlen(word);

    for (int i = 0; i < word_size; i++)
    {
        int j = 0;
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        while (word[i] != ALPHABET[j] && j < ALPHABET_SIZE)
        {
            j++;
        }
        player_score += SCORES[j];
    }
    return player_score;
}

int compare_scores(int player_scores[], int playercount) // Iterate all player scores, compare and
                                                         // replace pointer value with highest score
{
    int highscore_pointer = 0;
    for (int i = 0; i < playercount; i++)
    {
        if (player_scores[i] > player_scores[highscore_pointer])
        {
            highscore_pointer = i;
        }
        else if (i > 0 && player_scores[i] == player_scores[highscore_pointer])
        {
            printf("Tie! %i and %i\n", highscore_pointer + 1, i + 1);
        }
    }
    return highscore_pointer;
}
