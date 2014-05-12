! test1.f08
function test_function(test_input) bind(c, name="test_function") result(test_output)
  use, intrinsic :: iso_c_binding
  implicit none
  integer(kind=c_int), intent(in) :: test_input
  integer(kind=c_int) :: test_output

  test_output = test_input + 10


end function test_function