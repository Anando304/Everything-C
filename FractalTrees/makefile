CFLAGS=-Wall -O2 -ansi

fib: main_fib.o fib.o bmp.o timing.o
		$(CXX) -o fib $?
	
runall:
		./fib 7 10 10 10 100 100 fib7.bmp
		./fib 9 10 10 10 300 300 fib9.bmp
		./fib 25 10 10 10 10000 10000 fib25.bmp
		./fib 26 10 10 10 15000 15000 fib26.bmp
		./fib 28 10 10 5 29000 12000 fib30.bmp
		./fib 34 10 10 2 30000 30000 fib34.bmp
		
clean:
		@rm -rf fib *.o *bmp