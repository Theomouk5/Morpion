#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/logic.h"
#include "../include/display.h"

void clear_morpion(char morpion[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            morpion[i][j] = ' ';
        }
    }
}

void increment_score(char morpion[3][3], Player *player, Bool *round_is_win)
{
    *round_is_win = True;
    clear_morpion(morpion);
    player->score++;
}

void one_round(char morpion[3][3], Player *player)
{
    unsigned char case_number = 0;
    unsigned char col = 0;
    unsigned char row = 0;
    
    while (1)
    {
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

        if (morpion[row][col] != 'X' && morpion[row][col] != 'O')
            break;
    } 

    morpion[row][col] = player->symbole;
}

void start_game()
{
    unsigned char random_1_player;
    unsigned char number_of_games;
    unsigned char who_play = 1;
    char players[2][64];
    char morpion[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    Bool round_is_win = False;
    Player player1 = { "", 'X', 1 };
    Player player2 = { "", 'O', 1 };
    
    int i;

    srand(time(NULL));
    welcome_message();
    initialization_player(players);

    random_1_player = rand() % (1 - 0 + 1) + 0;
    strcpy(player1.name, players[random_1_player]);
    strcpy(player2.name, players[!random_1_player]);

    presentation_players(&player1, &player2);
    number_of_games = get_number_games();
    
    if (number_of_games <= 0 || number_of_games >= 20) 
        return;
    
    while (player1.score + player2.score < number_of_games)
    {
        while (1)
        {
golden_round:
            if (who_play == 1)
            {
                display_score(&player1, &player2);
                one_round(morpion, &player1);
                who_play = 2;
            }
            else
            {
                display_score(&player1, &player2);
                one_round(morpion, &player2);
                who_play = 1;
            } 

            // Check rows
            for (i = 0; i < 3; i++)
            {
                if (morpion[i][0] == morpion[i][1] && morpion[i][0] == morpion[i][2] && (morpion[i][0] == player1.symbole || morpion[i][0] == player2.symbole))
                {
                    if (morpion[i][0] == player1.symbole)
                    {
                        increment_score(morpion, &player1, &round_is_win);
                    }

                    increment_score(morpion, &player2, &round_is_win);
                }
            }

            // Check columns
            for (i = 0; i < 3; i++)
            {
                if (morpion[0][i] == morpion[1][i] && morpion[0][i] == morpion[2][i] && (morpion[0][i] == player1.symbole || morpion[0][i] == player2.symbole))
                {
                    if (morpion[0][i] == player1.symbole)
                    {
                        increment_score(morpion, &player1, &round_is_win);
                    }
                    
                    increment_score(morpion, &player2, &round_is_win);
                }
            }

            // Check diagonals
            if ((morpion[1][1] == morpion[0][0] && morpion[1][1] == morpion[2][2]) || (morpion[1][1] == morpion[0][2] && morpion[1][1] == morpion[2][0]))
            {
                if (morpion[1][1] == player1.symbole)
                {
                    increment_score(morpion, &player1, &round_is_win);
                }
                else if (morpion[1][1] == player2.symbole)
                {
                    increment_score(morpion, &player2, &round_is_win);
                }
            }

            if (round_is_win == True)
            {
                round_is_win = False;
                break;
            }
        }

   }

   if (player1.score > player2.score)
   {
        winner(&player1);
   }
   else if (player2.score > player1.score)
   {
        winner(&player2);
   } 
   else 
   {
        goto golden_round;
   }
}
