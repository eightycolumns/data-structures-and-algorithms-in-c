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

START_TEST(insertion_sort_3_to_3) {
  int expected[] = {3};

  int actual[] = {3};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(insertion_sort_12345_to_12345) {
  int expected[] = {1, 2, 3, 4, 5};

  int actual[] = {1, 2, 3, 4, 5};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(insertion_sort_54321_to_12345) {
  int expected[] = {1, 2, 3, 4, 5};

  int actual[] = {5, 4, 3, 2, 1};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(insertion_sort_543432321_to_122333445) {
  int expected[] = {1, 2, 2, 3, 3, 3, 4, 4, 5};

  int actual[] = {5, 4, 3, 4, 3, 2, 3, 2, 1};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(insertion_sort_0927456381_to_0123456789) {
  int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int actual[] = {0, 9, 2, 7, 4, 5, 6, 3, 8, 1};
  size_t n = sizeof actual / sizeof actual[0];

  insertion_sort(actual, n);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(merge_sort_3_to_3) {
  int expected[] = {3};

  int actual[] = {3};
  size_t n = sizeof actual / sizeof actual[0];

  merge_sort(actual, 0, n - 1);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(merge_sort_12345_to_12345) {
  int expected[] = {1, 2, 3, 4, 5};

  int actual[] = {1, 2, 3, 4, 5};
  size_t n = sizeof actual / sizeof actual[0];

  merge_sort(actual, 0, n - 1);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(merge_sort_54321_to_12345) {
  int expected[] = {1, 2, 3, 4, 5};

  int actual[] = {5, 4, 3, 2, 1};
  size_t n = sizeof actual / sizeof actual[0];

  merge_sort(actual, 0, n - 1);

  compare_arrays(expected, actual, n);
} END_TEST

START_TEST(merge_sort_543432321_to_122333445) {
  int expected[] = {1, 2, 2, 3, 3, 3, 4, 4, 5};

  int actual[] = {5, 4, 3, 4, 3, 2, 3, 2, 1};
  size_t n = sizeof actual / sizeof actual[0];

  merge_sort(actual, 0, n - 1);

  compare_arrays(expected, actual, n);
} END_TEST

Suite *sorting(void) {
  TCase *core = tcase_create("Core");

  tcase_add_test(core, insertion_sort_3_to_3);
  tcase_add_test(core, insertion_sort_12345_to_12345);
  tcase_add_test(core, insertion_sort_54321_to_12345);
  tcase_add_test(core, insertion_sort_543432321_to_122333445);
  tcase_add_test(core, insertion_sort_0927456381_to_0123456789);

  tcase_add_test(core, merge_sort_3_to_3);
  tcase_add_test(core, merge_sort_12345_to_12345);
  tcase_add_test(core, merge_sort_54321_to_12345);
  tcase_add_test(core, merge_sort_543432321_to_122333445);

  Suite *sorting = suite_create("Sorting");
  suite_add_tcase(sorting, core);

  return sorting;
}
