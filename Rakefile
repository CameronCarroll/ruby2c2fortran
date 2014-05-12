# Rakefile

require 'rake/clean'
require 'rbconfig'

CLOBBER.include('*.o', '*.so')

CFLAGS = RbConfig::CONFIG["CFLAGS"]
HDRDIR = RbConfig::CONFIG["rubyhdrdir"]
ARCHHDRDIR = RbConfig::CONFIG["rubyarchhdrdir"]

task :test1 => ["test1_f.o", "test1_c.o"]
	
	file "test1_f.o" => "test1.f08" do |t|
		compile(t.prerequisites.first, t.name)
	end

	file "test1_c.o" => "test1.c" do |t|
		compile(t.prerequisites.first, t.name)
	end

task :test2 => "test2.o"

	file "test2.o" => "test2.c" do |t|
		compile_c_for_ruby(t.prerequisites.first, t.name)
	end

task :test3 => "sievemodule.so"
task :default => :test3

	file "sievemodule.so" => ["driver.o", "provider.o"] do |t|
	  sh "gcc -shared -o sievemodule.so driver.o provider.o -lgfortran -lm -lruby"
	end

	file "driver.o" => "driver.c" do |t|
	  compile_c_for_ruby(t.prerequisites.first, t.name)
	end

	file "provider.o" => "provider.f08" do |t|
	  compile(t.prerequisites.first, t.name)
	end

def compile(src, target)
	sh "gcc -c -fPIC -o #{target} #{src}"
end

def compile_c_for_ruby(src, target)
	sh "gcc -c -I #{ARCHHDRDIR} -I#{HDRDIR} #{CFLAGS} -o #{target} #{src}"
end