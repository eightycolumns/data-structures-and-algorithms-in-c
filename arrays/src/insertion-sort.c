#include <stddef.h>

void insertion_sort(int *a, size_t n) {
  for (size_t i = 1; i < n; i += 1) {
    int key = a[i];

    size_t j = i;

    while (j > 0 && a[j - 1] > key) {
      a[j] = a[j - 1];
      j -= 1;
    }

    a[j] = key;
  }
}
