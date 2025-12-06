#include "game.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OBSTACLES 5

int carPosition;
int obstacleCount;
int obstacleX[MAX_OBSTACLES];
int obstacleY[MAX_OBSTACLES];

int level;
int speedDelay;
int gameRunning;
int score = 0;
int gameSpeed = 50;

// Reset everything
void resetGame() {
    carPosition = 10;

    obstacleCount = 2;
    obstacleX[0] = 5;
    obstacleY[0] = 0;
    obstacleX[1] = 15;
    obstacleY[1] = -5;

    score = 0;
    level = 1;
    speedDelay = 150;
    gameRunning = 1;
    gameSpeed = 50;
}

void initGame() {
    srand(time(NULL));
    resetGame();
}

// Movement (input)
void processInput() {
    if (_kbhit()) {
        char key = _getch();

        if ((key == 'a' || key == 'A') && carPosition > 1)
            carPosition--;

        else if ((key == 'd' || key == 'D') && carPosition < 18)
            carPosition++;
    }
}

// Game update
void updateGame() {
    processInput();

    // Random obstacle spawn
    if (rand() % 10 == 0 && obstacleCount < MAX_OBSTACLES) {
        obstacleX[obstacleCount] = rand() % 18 + 1;
        obstacleY[obstacleCount] = 0;
        obstacleCount++;
    }

    // Move obstacles
    for (int i = 0; i < obstacleCount; i++) {
        if (obstacleY[i] >= 0) {
            obstacleY[i]++;

            // Collision detection
            if (obstacleY[i] == 9 && 
               (carPosition >= obstacleX[i] && carPosition <= obstacleX[i] + 2)) {
                gameRunning = 0;
                return;
            }

            // Out of bounds
            if (obstacleY[i] > 11) {
                obstacleY[i] = -1;
                score += 5;
            }
        }
    }

    score++;

    if (score % 50 == 0 && gameSpeed > 10) {
        gameSpeed -= 5;
    }
}

// Separate collision check (used by main)
int checkCollision() {
    for (int i = 0; i < obstacleCount; i++) {
        if (obstacleY[i] == 9 &&
            (carPosition >= obstacleX[i] && carPosition <= obstacleX[i] + 2))
            return 1;
    }
    return 0;
}
