#include <stdlib.h>

#include <check.h>

#include "test/sorting.h"

int main(void) {
  SRunner *srunner = srunner_create(sorting());

  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
