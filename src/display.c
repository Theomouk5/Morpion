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

unsigned char get_number_games(void)
{
    unsigned char number = 0;
    printf("\n\nEntrez le nombre de parties que vous voulez faire : ");
    scanf("%hhu", &number);

    if (number > 0 && number < 20)
        printf("\n\nDonc c'est partie pour %d parties !\n", number);
    
    return number;
}

void display_score(Player *player1, Player *player2)
{	
    system("clear");
    printf("#####################SCORE####################\n\n");
    printf("	   %s : %hhu             %s : %hhu\n\n", player1->name, player1->score, player2->name, player2->score);
    printf("##############################################\n\n");
}

void display_morpion(char morpion[3][3])
{
    printf("Voici la position actuelle du morpion\n\n\n");

    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        printf("        ");

        for (j = 0; j < 3; j++)
        {
            printf("| %c ", morpion[i][j]);
        }

        printf("|\n");

        if (i != 2)
            printf("        -------------\n");
    }

}

unsigned char ask_new_character(Player *player)
{
    while(1) {
        unsigned char selected;
        printf("\n\nAu tour de %s pour cette manche\n", player->name);
        printf("%s, quelle case voulez-vous choisir : ", player->name);
        scanf("%hhd", &selected);

        if (selected > 9 || selected < 1)
            continue;

        return selected;
    }
}

void winner(Player *player)
{
    system("clear");
}
