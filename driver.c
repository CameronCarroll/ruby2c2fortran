#include <stdio.h>
#include "ruby.h"

int sieve_of_eratosthenes(int *, int *);
VALUE SieveModule = Qnil;

VALUE method_invoke_sieve(VALUE self, VALUE iterations) {
  int output [iterations], ii;
  VALUE result;
  int c_iterations = NUM2INT(iterations);
  if (c_iterations) {
    sieve_of_eratosthenes(&c_iterations, output);
  }

  result = rb_ary_new();
  for(ii=0; ii<c_iterations; ii++) {
    int prime = ii + 1;
    rb_ary_push(result, INT2FIX(output[prime]));
  }
  return result;
}

void Init_sievemodule() {
  SieveModule = rb_define_module("SieveModule");
  rb_define_method(SieveModule, "invoke_sieve", method_invoke_sieve, 1);
}