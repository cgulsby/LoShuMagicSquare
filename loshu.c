#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define MAGIC_SUM 15

void printSquare(int square[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    printf("[");
    for (int j = 0; j < SIZE; j++) {
      if (j == 2) {
        printf("%d", square[i][j]);
      } else {
        printf("%d ", square[i][j]);
      }
    }
    printf("]");
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

void generateSquare(int square[SIZE][SIZE]) {
  int nums[SIZE * SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Fisher-Yates Shuffle
  for (int i = SIZE * SIZE - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  // Puts the shuffled array into the grid
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      square[i][j] = nums[i * SIZE + j];
    }
  }
}

int main(void) {
  srand(time(NULL));

  int square[SIZE][SIZE];
  int count = 0;

  do {
    generateSquare(square);
    count++;
  } while (!isMagicSquare(square));

  printf("Squares tested: %d\n", count);
  printf("Lo Shu Magic Square found:\n");
  printSquare(square);

  return 0;
}
