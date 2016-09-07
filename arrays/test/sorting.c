#include "test/sorting.h"

#include <stddef.h>

#include <check.h>

#include "src/arrays.h"

static void compare_arrays(const int *expected, const int *actual, size_t n) {
  for (size_t i = 0; i < n; i += 1) {
    ck_assert_msg(
      expected[i] == actual[i],
      "expected[%zd] == %d, actual[%zd] == %d", i, expected[i], i, actual[i]
    );
  }
}

START_TEST(insertion_sort_54321_to_12345) {
  int expected[] = {1, 2, 3, 4, 5};

  int actual[] = {5, 4, 3, 2, 1};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

Suite *sorting(void) {
  TCase *core = tcase_create("Core");

  tcase_add_test(core, insertion_sort_54321_to_12345);

  Suite *sorting = suite_create("Sorting");
  suite_add_tcase(sorting, core);

  return sorting;
}
