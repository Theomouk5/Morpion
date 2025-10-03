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

void increment_score(Player *player);
void start_game();

#endif