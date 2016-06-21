#include <stdio.h>

int main() {

  int matrix[4][4] = {
    {  1,  2,  3,  4 },
    { 12, 13, 14,  5 },
    { 11, 16, 15,  6 },
    { 10,  9,  8,  7 } };

  int edge = sizeof(matrix[0]) / sizeof(int) - 1;
  int i = 0;
  int j = 0;

  printf("%d ", matrix[i][j]);
  for (int c = 0; c < edge; ++c) { printf("%d ", matrix[i][++j]); }

  while (0 < edge) {
    for (int c = 0; c < edge; ++c) { printf("%d ", matrix[++i][j]); }
    for (int c = 0; c < edge; ++c) { printf("%d ", matrix[i][--j]); }
    --edge;
    for (int c = 0; c < edge; ++c) { printf("%d ", matrix[--i][j]); }
    for (int c = 0; c < edge; ++c) { printf("%d ", matrix[i][++j]); }
    --edge;
  }

  return 0;
}
