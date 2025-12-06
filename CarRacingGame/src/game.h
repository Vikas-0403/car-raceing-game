#ifndef GAME_H
#define GAME_H

void initGame();
void updateGame();
void processInput();
void resetGame();
int checkCollision();
void resetGame();
void drawGameOverScreen();


extern int carPosition;
extern int obstacleCount;
extern int obstacleX[];
extern int obstacleY[];
extern int score;
extern int level;
extern int speedDelay;
extern int gameSpeed;
extern int gameRunning;
extern int isGameOver;

#endif

