#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/logic.h"
#include "../include/display.h"

void increment_score(Player *player)
{
    player->score += 1;
}

void one_game(char morpion[3][3], Player *player)
{
    unsigned char case_number = 0;
    unsigned char col = 0;
    unsigned char row = 0;
    
    display_morpion(morpion);
    case_number = ask_new_character(player);

    if (case_number > 6)
    {
        row = 2;
        col = case_number - 7;
    }
    else if (case_number > 3)
    {
        row = 1;
        col = case_number - 4;
    }
    else
    {
        col = case_number - 1;
    }

    morpion[row][col] = player->symbole;
}

void start_game()
{
    unsigned char random_1_player;
    unsigned char number_of_games;
    char players[2][64];
    char morpion[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    Player player1 = { "", 'X', 0 };
    Player player2 = { "", 'O', 0 };

    srand(time(NULL));
    welcome_message();
    initialization_player(players);

    random_1_player = rand() % (1 - 0 + 1) + 0;
    strcpy(player1.name, players[random_1_player]);
    strcpy(player2.name, players[!random_1_player]);

    presentation_players(&player1, &player2);
    number_of_games = get_number_games();
    
    if (number_of_games <= 0 && number_of_games >= 20) 
        return;
    
    one_game(morpion, &player1);
    display_morpion(morpion);
}