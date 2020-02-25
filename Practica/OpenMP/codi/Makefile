# Because OpenMP doesnt work with Macos compiler Clang
# I had to install the gnu compiler by using Homebrew package manager

ifeq (, $(shell which g++-9))
COMPILER := g++
else
COMPILER := g++-9
endif

all:
	@echo "Using this compiler: $(COMPILER)"
	$(COMPILER) main_1.cpp -o main_1 -fopenmp
	$(COMPILER) main_2.cpp -o main_2 -Ofast -fopenmp
	$(COMPILER) main_3.cpp -o main_3 -Ofast -fopenmp
	$(COMPILER) main_4.cpp -o main_4 -Ofast -fopenmp
	$(COMPILER) main_5.cpp -o main_5 -Ofast -fopenmp
	$(COMPILER) main_6.cpp -o main_6 -Ofast -fopenmp
	$(COMPILER) main_7.cpp -o main_7 -Ofast -fopenmp
clean:
	rm main_1 main_2 main_3 main_4 main_5 main_6 main_7
