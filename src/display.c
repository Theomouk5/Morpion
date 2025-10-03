#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/display.h"

void welcome_message(void)
{
    system("clear");
    printf("Bienvenue sur mon Jeu du Morpion !!!\n");
    printf("    ____  _                                            \n");
    printf("   / __ )(_)__  ____ _   _____  ____  __  _____        \n");
    printf("  / __  / / _ \\/ __ \\ | / / _ \\/ __ \\/ / / / _ \\       \n");
    printf(" / /_/ / /  __/ / / / |/ /  __/ / / / /_/ /  __/       \n");
    printf("/_____/_/\\___/_/_/_/|___/\\___/_/ /_/\\__,_/\\___/        \n");
    printf("   /   |     /_  __/____  __  _______                   \n");
    printf("  / /| |      / / / __ \\/ / / / ___/\n");                   
    printf(" / ___ |     / / / /_/ / /_/ (__  )\n");                    
    printf("/_/  |_|    /_/  \\____/\\__,_/____/\n");
    printf("\n\n");
    printf("Donc c'est un jeu à jouer à 2 joueurs.\n");
    printf("Donc il y a les X et les O et C'est les X qui commencent\n");
    printf("Bonne partie :)\n");
}

void initialization_player(char players[2][64])
{
    char buffer[61];
    printf("Entrez vos noms (pas d'espaces et 60 chars max)\n");

    printf("Joueur : ");
    scanf(" %60s", buffer); 
    strcpy(players[0], buffer);

    printf("Joueur : ");
    scanf(" %60s", buffer);
    strcpy(players[1], buffer);
}

void presentation_players(Player *player1, Player *player2)
{
    system("clear");
    printf("Le joueur 1 est %s\n", player1->name);
    printf("Le joueur 2 est %s\n", player2->name);
}

int get_number_games(void)
{
    int number = 0;
    printf("Entrez le nombre de parties que vous voulez faire : ");
    scanf("%d", &number);
    printf("\n\nDonc c'est partie pour %d parties !\n", number);
    return number;
}