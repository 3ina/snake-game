#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct{
  int x,y;
} Point;

typedef struct {
  Point body[100];
  int length;
  int direction; // RIGHT:1  LEFT:2 UP:3 DOWN:4
} Snake;


extern Point food;
extern int score;
extern int gameOver;

void setup();
void draw(Snake snake);
void handleInput(Snake *snake);
void updateLogic(Snake *snake);
void generateFood();

#endif

