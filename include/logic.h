#ifndef __LOGIC__
#define __LOGIC__

typedef enum Bool {
    False,
    True,
} Bool;

typedef struct Player {
    char name[64];
    char symbole;
    unsigned char score;
} Player;

void clear_morpion(char morpion[3][3]);
void increment_score(char morpion[3][3], Player *player, Bool *round_is_win);
void one_round(char morpion[3][3], Player *player);
void start_game();

#endif