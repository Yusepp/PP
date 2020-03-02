# Because OpenMP doesnt work with Macos compiler Clang
# I had to install the gnu compiler by using Homebrew package manager

ifeq (, $(shell which g++-9))
COMPILER := g++
else
COMPILER := g++-9
endif

all:
	@echo "Using this compiler: $(COMPILER)"
	$(COMPILER) main.cpp pract_omp.cpp -o main -fopenmp -Ofast
clean:
	rm main
