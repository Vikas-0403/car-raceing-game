#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "game.h"
#include "graphics.h"

void showStartScreen() {
    system("cls");
    printf("\n\n   === CAR RACING GAME ===\n");
    printf("   Controls: A = Left | D = Right\n");
    printf("   Avoid obstacles and survive!\n\n");
    printf("   Press ENTER to Start...\n");
}

void showGameOverScreen() {
    printf("\n\n GAME OVER! Final Score: %d\n", score);
    printf(" Press R to Restart or ESC to Exit\n");
}

int main() {
    srand(time(NULL));

    while (1) {
        showStartScreen();

        // Wait for Enter
        while (_getch() != 13);

        initGame();

        while (gameRunning) {
            updateGame();
            drawTrack();

            if (checkCollision()) {
                gameRunning = 0;
                showGameOverScreen();
            }

            Sleep(gameSpeed);
        }

        // Game over input
        char choice = _getch();
        if (choice == 'r' || choice == 'R') {
            // restart the game
            resetGame();
            continue;
        } else if (choice == 27) {  // ESC key
            break;
        } else {
            break;  // anything else quits
        }
    }

    return 0;
}
