#include <stdio.h>
#define SIZE 3

/*  
 * Board Coordinates 
 * 
 *    ---> X ---->
 *
 * |   0 | 0 | 0
 * |   - | - | -
 * Y   0 | 0 | 0
 * |   - | - | -
 * |   0 | 0 | 0
 *
 * */


int run = 1; // if 1 run, if 0 stop

int board[SIZE][SIZE];

void initBoard() {
  for (int outer = 0; outer < SIZE; outer++) {
    for (int inner = 0; inner < SIZE; inner++) {
      board[outer][inner] = 2;
    }
  }
}

char translate(int input) {
  char output;

  if (input == 0) {
    output = ' ';
  } else if (input == 1) {
    output = 'X';
  } else if (input == 2) {
    output = 'O';
  } else {
    printf("Error, unknown input in translate -- Given Input: %d\n", input);
  }

  return output;
}

void print_board() {
  for (int outer = 0; outer < SIZE * 2 - 1; outer++) {
    for (int inner = 0; inner < SIZE * 2; inner++) {
      if (inner % 2 == 0) {
        if (outer % 2 == 0) {
          char value = translate(board[inner / 2][outer / 2]);
          printf(" %c", value);
        } else {
          printf(" -");
        }
      } else if (inner == SIZE * 2 - 1) {
        printf("\n");
      } else {
        printf(" |");
      }
    }
  }
}

int check() {

  return 0;
}

void loop() {
  while (run) {
  }
}

int main (int argc, char *argv[])
{
  initBoard();
  board[0][1] = 1;
  print_board();

  //loop();

  return 0;
}
