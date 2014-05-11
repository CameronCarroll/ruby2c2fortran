# Rakefile for Ruby/C/Fortran Interoperation Example
# Cameron Carroll, May 2014

require 'rake/clean'
require 'rbconfig'

CLOBBER.include('*.o', '*.so')

CFLAGS = RbConfig::CONFIG["CFLAGS"]
HDRDIR = RbConfig::CONFIG["rubyhdrdir"]
ARCHHDRDIR = RbConfig::CONFIG["rubyarchhdrdir"]

task :default => "sievemodule.so"

file "driver.o" do |t|
  sh "gcc -c -I #{ARCHHDRDIR} -I#{HDRDIR} #{CFLAGS} driver.c"
end

file "provider.o" do |t|
  sh "gcc -c -fPIC provider.f08"
end

file "sievemodule.so" => ["driver.o", "provider.o"] do
  sh "gcc -shared -o sievemodule.so driver.o provider.o -lgfortran -lm -lruby"
end

