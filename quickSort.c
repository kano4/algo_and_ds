#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void QuickSort(int bottom, int top, int *data) {
  int lower, upper, div, temp;
  if (bottom >= top) {
    return;
  }
  div = data[bottom];
  for (lower = bottom, upper = top; lower < upper;) {
    while (lower <= upper && data[lower] <= div) {
      lower++;
    }
    while (lower <= upper && data[upper] > div) {
      upper--;
    }
    if (lower < upper) {
      temp = data[lower];
      data[lower] = data[upper];
      data[upper] = temp;
    }
  }
  temp = data[bottom];
  data[bottom] = data[upper];
  data[upper] = temp;

  QuickSort(bottom, upper -1, data);
  QuickSort(upper + 1, top, data);
}

int main(void) {
  int i;

  srand((unsigned int)time(NULL));

  printf("ソート準備:\n");
  for (i = 0; i < N; i++) {
    sort[i] = rand();
    printf("%d ", sort[i]);
  }

  printf("\nソート開始:\n");
  QuickSort(0, N - 1, sort);

  printf("\nソート終了:\n");

  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }

  return EXIT_SUCCESS;
}



