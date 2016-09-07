#include <stddef.h>

static void merge(int *a, size_t lo, size_t mid, size_t hi);

void merge_sort(int *a, size_t lo, size_t hi) {
  if (lo < hi) {
    size_t mid = (hi + lo) / 2;

    merge_sort(a, lo, mid);
    merge_sort(a, mid + 1, hi);

    merge(a, lo, mid, hi);
  }
}

static void merge(int *a, size_t lo, size_t mid, size_t hi) {
  size_t n_left = mid + 1 - lo;
  size_t n_right = hi + 1 - (mid + 1);

  int left[n_left + 1];
  int right[n_right + 1];

  size_t i;
  size_t j;

  for (i = 0; i < n_left; i += 1) left[i] = a[lo + i];
  for (j = 0; j < n_right; j += 1) right[j] = a[(mid + 1) + j];

  left[i] = right[j - 1];
  right[j] = left[i - 1];

  i = 0;
  j = 0;

  for (size_t k = lo; k <= hi; k += 1) {
    a[k] = (left[i] < right[j]) ? left[i++] : right[j++];
  }
}
