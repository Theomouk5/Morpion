#ifndef __DISP_MORP__
#define __DISP_MORP__
#include "logic.h"

void welcome_message(void);
void initialization_player(char players[2][64]);
void presentation_players(Player *player1, Player *player2);
unsigned char get_number_games(void);
void display_score(Player *player1, Player *player2);
void display_morpion(char morpion[3][3]);
unsigned char ask_new_character(Player *player);
void winner(Player *player);

#endif
