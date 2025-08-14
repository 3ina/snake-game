#include <stdlib.h>
#include <unistd.h>
#include "game.h"


Point food;
int score = 0;
int gameOver = 0;

void setup() {
  srand(time(0));
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr,TRUE);
  nodelay(stdscr,TRUE);

}


void draw(Snake snake){
  clear();
  
  for (int i = 0; i < WIDTH + 2;i++) {
    
    mvprintw(0,i,"#");
    mvprintw(HEIGHT+1,i,"#");
  }

  for (int i = 0;i < HEIGHT+2;i++) {
    mvprintw(i,0,"#");
    mvprintw(i,WIDTH+1,"#");
  }

  mvprintw(food.y + 1,food.x + 1,"*");

  for (int i = 0;i < snake.length;i++) {
    mvprintw(snake.body[i].y+1,snake.body[i].x+1,(i == 0) ? "O" : "o");
  }
  
  mvprintw(HEIGHT+3,0,"Score : %d",score);

  refresh();


}

void handleInput(Snake *snake){
  int ch = getch();

  switch (ch) {
    case KEY_UP:
      if (snake->direction != 4) snake->direction = 3;
      break;
    case KEY_DOWN:
      if (snake->direction != 3) snake->direction = 4;
      break;
    case KEY_LEFT:
      if (snake->direction !=1) snake->direction = 2;
      break;
    case KEY_RIGHT:
      if(snake->direction != 2) snake->direction = 1;
      break;
    case 'q':
      gameOver=1;
      break;

  }

}

void updateLogic(Snake *snake){
  for(int i = snake->length - 1; i>0 ;i--){
    snake->body[i] = snake->body[i-1];
  }

  switch(snake->direction){
    case 1 : snake->body[0].x++;break;
    case 2 : snake->body[0].x--;break;
    case 3 : snake->body[0].y--;break;
    case 4 : snake->body[0].y++;break;

  }

  if (
      snake->body[0].x < 0 || snake->body[0].x > WIDTH ||
      snake->body[0].y < 0 || snake->body[0].y > HEIGHT  
    ){
    gameOver = 1;
  }


  for(int i = 1; i < snake->length ;i++){
    if(
        snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y
      ){
      gameOver=1;
    }
  }
  
  if(food.x == snake->body[0].x && food.y == snake->body[0].y){
    score += 1;
    if(snake->length < 100){
      snake->length++;
    }
    generateFood();
  }
}

void generateFood(){
  food.x = rand() % WIDTH;
  food.y = rand() % HEIGHT;
}
