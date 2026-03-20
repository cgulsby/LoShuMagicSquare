#include <stdio.h>

#define SIZE 3
#define MAGIC_SUM 15

void printSquare(int square[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", square[i][j]);
    }
    printf("\n");
  }
}

int isMagicSquare(int square[SIZE][SIZE]) {
  // Check that each number 1-9 appears exactly once
  int found[SIZE * SIZE + 1] = {0};
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      int val = square[i][j];
      if (val < 1 || val > SIZE * SIZE || found[val]) {
        return 0;
      }
      found[val] = 1;
    }
  }

  // Check row sums
  for (int i = 0; i < SIZE; i++) {
    int sum = 0;
    for (int j = 0; j < SIZE; j++) {
      sum += square[i][j];
    }
    if (sum != MAGIC_SUM) {
      return 0;
    }
  }

  // Check column sums
  for (int j = 0; j < SIZE; j++) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
      sum += square[i][j];
    }
    if (sum != MAGIC_SUM) {
      return 0;
    }
  }

  // Check diagonal sums
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < SIZE; i++) {
    sum1 += square[i][i];
    sum2 += square[i][SIZE - 1 - i];
  }
  if (sum1 != MAGIC_SUM || sum2 != MAGIC_SUM) {
    return 0;
  }

  return 1;
}

int main(void) {
  int square1[SIZE][SIZE] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};

  int square2[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int square3[SIZE][SIZE] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 7}};

  printf("Square 1:\n");
  printSquare(square1);
  if (isMagicSquare(square1)) {
    printf("This is a Lo Shu Magic Square.\n\n");
  } else {
    printf("This is NOT a Lo Shu Magic Square.\n\n");
  }

  printf("Square 2:\n");
  printSquare(square2);
  if (isMagicSquare(square2)) {
    printf("This is a Lo Shu Magic Square.\n\n");
  } else {
    printf("This is NOT a Lo Shu Magic Square.\n\n");
  }

  printf("Square 3:\n");
  printSquare(square3);
  if (isMagicSquare(square3)) {
    printf("This is a Lo Shu Magic Square.\n\n");
  } else {
    printf("This is NOT a Lo Shu Magic Square.\n\n");
  }

  return 0;
}
