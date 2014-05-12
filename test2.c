// test2.c
#include "ruby.h"
#include "stdio.h"

VALUE TestModule = Qnil;


VALUE method_test_function(VALUE self) {
  printf("Hello, Ruby. (From C)\n");
  return 0;
}

void Init_testmodule() {
  TestModule = rb_define_module("TestModule");
  rb_define_method(TestModule, "test_function", method_test_function, 0);
}