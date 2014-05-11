subroutine sieve_of_eratosthenes(max_value, number_list) bind(c, name="sieve_of_eratosthenes")
  use, intrinsic :: iso_c_binding
  implicit none

  integer(kind=c_int), intent(in) :: max_value
  integer(kind=c_int), dimension(max_value), intent(out) :: number_list(max_value)
  integer(kind=c_int) :: outer_high_bound, inner_high_bound, i

  number_list = 1
  number_list(1) = 0

  outer_high_bound = int (sqrt (real (max_value)))
  inner_high_bound = max_value

  do i = 2, outer_high_bound
    if (number_list(i) == 1) number_list(i*i : max_value : i) = 0
  end do

end subroutine sieve_of_eratosthenes