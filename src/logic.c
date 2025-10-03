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

void start_game()
{
    char players[2][64];
    int random_1_player;
    int number_of_games;

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
}