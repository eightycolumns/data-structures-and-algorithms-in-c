#include <stddef.h>

void insertion_sort(int *a, size_t n) {
  for (size_t i = 1; i < n; i += 1) {
    for (size_t j = i; j > 0 && a[j - 1] > a[j]; j -= 1) {
      int temp = a[j - 1];
      a[j - 1] = a[j];
      a[j] = temp;
    }
  }
}
