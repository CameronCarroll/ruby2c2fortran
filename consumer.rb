require './sievemodule.so'
include SieveModule


iterations = 1000
result = invoke_sieve(iterations)


puts "Primes under #{iterations}:"
result.each_with_index do |item, ii|;
  if result[ii] == 1 # Then value is a prime; Print it out.
    print ii + 2
    print " "
  else 
    # Value is composite.
  end
end
puts "\n"