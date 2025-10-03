#ifndef __DISP_MORP__
#define __DISP_MORP__
#include "logic.h"

void welcome_message(void);
void initialization_player(char players[2][64]);
void presentation_players(Player *player1, Player *player2);
unsigned char get_number_games(void);

#endif