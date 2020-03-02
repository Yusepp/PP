#define WIDTH 3840
#define HEIGHT 2160

#define EXPERIMENT_ITERATIONS 100
#define EXPERIMENT_ITERATIONS_2 1000

#define EXERCISE_1 1
#define EXERCISE_2 2
#define EXERCISE_3 3
#define EXERCISE_4 4
#define EXERCISE_5 5
#define EXERCISE_6 6
#define EXERCISE_7 7

typedef unsigned char uchar;

// NOT ALIGNED UCHAR3
struct _uchar3_na {
    uchar x;
    uchar y;
    uchar z;
};
using uchar3_na = _uchar3_na;

// ALIGNED UCHAR3
struct _uchar3
{
    uchar x;
    uchar y;
    uchar z;
} __attribute__((aligned(4)));

using uchar3 = _uchar3;

struct _uchar4 {
    uchar x;
    uchar y;
    uchar z;
    uchar w;
};
using uchar4 = _uchar4;

void exercise_omp(int e);