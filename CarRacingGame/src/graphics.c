#include <stdio.h>
#include <windows.h>
#include "graphics.h"
#include "game.h"

void drawTrack() {
    system("cls");

    printf(" SCORE: %d   LEVEL: %d\n", score, level);
    printf("|----------------------|\n");

    for (int i = 0; i < 10; i++) {
        // build the line buffer and place any obstacles present on this row
        char line[23];
        for (int k = 0; k < 22; k++) line[k] = ' ';
        line[22] = '\0';

        for (int o = 0; o < obstacleCount; o++) {
            if (obstacleY[o] == i && obstacleY[o] >= 0) {
                int pos = obstacleX[o];
                if (pos < 0) continue;
                if (pos >= 0 && pos < 21) {
                    line[pos] = '#';
                    line[pos+1] = '#';
                }
            }
        }

        printf("|%s|\n", line);
    }

    drawCar(carPosition);

    printf("Score: %d  Speed: %d\n", score, 60 - gameSpeed);


    printf("|----------------------|\n");
}

void drawGameOverScreen() {
    system("cls");
    printf("\n\n==== GAME OVER ====\n");
    printf("Final Score: %d\n", score);
    printf("Press R to Restart or Q to Quit\n");
}

void drawCar(int position) {
    printf("|");

    for (int i = 0; i < position; i++)
        printf(" ");

    printf("CAR");

    for (int i = position + 3; i < 22; i++)
        printf(" ");

    printf("|\n");
}
