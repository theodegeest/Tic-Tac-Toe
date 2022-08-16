#include <stdio.h>
#define SIZE 3
#define WIN_SIZE 3

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
int current_player = 1; // player 1 and 2
int status = 0; // 0 = no winner yet, 1 = player 1 has won, 2 = player 2 has won, 3 = no more free tiles
int used_tiles = 0; 

int board[SIZE][SIZE];

void initBoard() {
  for (int outer = 0; outer < SIZE; outer++) {
    for (int inner = 0; inner < SIZE; inner++) {
      board[outer][inner] = 0;
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
  printf("Current player: %c\n", translate(current_player));

  for (int outer = 0; outer < SIZE * 2 - 1; outer++) {
    printf("  ");
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

void print_status() {
  if (status == 1) {
    printf("\n\n Winner is Player 1 (X)!\n\n");
  } else if (status == 2) {
    printf("\n\n Winner is Player 2 (X)!\n\n");
  } else if (status == 3) {
    printf("\n\n No winner this time!\n\n");
  }
}

void check_horizontal(int x, int y) {
  if (x + WIN_SIZE <= SIZE) {
    int current = board[x][y];
    int current1 = board[x + 1][y];
    int current2 = board[x + 2][y];
    if (current == 1 && current1 == 1 && current2 == 1) {
      status = 1;
    } else if (current == 2 && current1 == 2 && current2 == 2) {
      status = 2;
    }
  }
}


void check_diagonal(int x, int y) {
  if (x + WIN_SIZE <= SIZE && y + WIN_SIZE <= SIZE) {
    int current = board[x][y];
    int current1 = board[x + 1][y + 1];
    int current2 = board[x + 2][y + 2];
    if (current == 1 && current1 == 1 && current2 == 1) {
      status = 1;
    } else if (current == 2 && current1 == 2 && current2 == 2) {
      status = 2;
    }
  }
}


void check_vertical(int x, int y) {
  if (y + WIN_SIZE <= SIZE) {
    int current = board[x][y];
    int current1 = board[x][y + 1];
    int current2 = board[x][y + 2];
    if (current == 1 && current1 == 1 && current2 == 1) {
      status = 1;
    } else if (current == 2 && current1 == 2 && current2 == 2) {
      status = 2;
    }
  }
}

void check_full() {
  if (used_tiles >= SIZE * SIZE) {
    status = 3;
  }
}

void check() {
  for (int outer = 0; outer < SIZE; outer++) {
    for (int inner = 0; inner < SIZE; inner++) {
      check_horizontal(inner, outer);
      check_diagonal(inner, outer);
      check_vertical(inner, outer);
    }
  }
  check_full();
}

void add() {
  int x = 0;
  int y = 0;
  int flag = 0;

  while (flag == 0) {
    printf("What coordinates? (x y) = ");
    scanf(" %d %d", &x, &y);
    printf("\n");
    
    if (x <= 0 || y <= 0 || x > SIZE || y > SIZE) {
      printf("Wrong input, please try again.\n\n");
    } else {
      flag = 1;
    }
  }

  board[x - 1][y - 1] = current_player;
  used_tiles++;
}

void flip_flop_players() {
  if (current_player == 1) {
    current_player = 2;
  } else {
    current_player = 1;
  }
}

void loop() {
  while (run) {
    add();
    flip_flop_players();
    check();
    print_board();
    print_status();
  }
}

int main (int argc, char *argv[])
{
  printf("\n");
  initBoard();
  print_board();

  loop();

  return 0;
}
