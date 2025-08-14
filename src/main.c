#include <time.h>
#include <stdlib.h>

#include "game.h"
int main() {
  Snake snake;
  

  setup();

  snake.length = 3;
  snake.direction = 1; 
  snake.body[0] = (Point){WIDTH / 2, HEIGHT / 2};
  snake.body[1] = (Point){WIDTH / 2 - 1, HEIGHT / 2};
  snake.body[2] = (Point){WIDTH / 2 - 2, HEIGHT / 2};
  
  generateFood();

  while(!gameOver){
    draw(snake);
    handleInput(&snake);
    updateLogic(&snake);
    usleep(150000);
  }

  printf("Game Over! Your final score was: %d\n", score);
  
  return 0;
}
