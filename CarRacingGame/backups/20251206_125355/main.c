#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "graphics.h"

int main() {
    // Initialize game
    initGame();
    drawTrack();

    printf("Console Car Racing Game Started!\n");
    printf("Press 'A' to move left, 'D' to move right.\n");

    // Game Loop (placeholder)
    while (1) {
        // Later we add input, movement, collision, scoring
        updateGame();
        drawTrack();
    }

    return 0;
}

