// test1.c           
#include <stdio.h>

int test_function(int *); // Equivalent to int test_function_(int*);

int main() {
  int i = 10;
  int return_value;

  return_value = test_function(&i); // NOT equivalent to test_function_(&i) unless we omit bind(c, "test_function")
  printf("Return value was: %d\n", return_value);

  return 0;
}