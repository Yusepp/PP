#include <iostream>
#include <omp.h>
#include <chrono>

#include "pract_omp.h"

using namespace std;

// EXERCISES: 1, 2, 3 DEFINITIONS START
bool checkResults(uchar4 *rgba, uchar3_na *brg, int size);
void convertBRG2RGBA(uchar3_na *brg, uchar4 *rgba, int width, int height);
void convertBRG2RGBA2(uchar3_na *brg, uchar4 *rgba, int width, int height);
// EXERCISES: 1, 2, 3 DEFINITIONS END

// EXERCISES: 1, 2, 3
bool checkResults(uchar4* rgba, uchar3_na* brg, int size) {

    bool correct = true;

    for (int i=0; i < size; ++i) {
        correct &= rgba[i].x == brg[i].y;
        correct &= rgba[i].y == brg[i].z;
        correct &= rgba[i].z == brg[i].x;
        correct &= rgba[i].w == 255;
    }

    return correct;
}

// EXERCISES: 1, 2
void convertBRG2RGBA(uchar3_na* brg, uchar4* rgba, int width, int height) {
    for (int x=0; x<width; ++x) {
    	for (int y=0; y<height; ++y) {	
	    rgba[width * y + x].x = brg[width * y + x].y;
	    rgba[width * y + x].y = brg[width * y + x].z;
	    rgba[width * y + x].z = brg[width * y + x].x;
	    rgba[width * y + x].w = 255;
	}
    }
}

// EXERCISE 3
void convertBRG2RGBA2(uchar3_na* brg, uchar4* rgba, int width, int height) {
    for (int y=0; y<height; ++y) {
    	for (int x=0; x<width; ++x) {	
            rgba[width * y + x].x = brg[width * y + x].y;
            rgba[width * y + x].y = brg[width * y + x].z;
            rgba[width * y + x].z = brg[width * y + x].x;
            rgba[width * y + x].w = 255;
	    }
    }
}

// EXERCISES: 4, 5, 6, 7 DEFINITIONS START
bool checkResults(uchar4 *rgba, uchar3 *brg, int size);
void convertBRG2RGBA2(uchar3 *brg, uchar4 *rgba, int width, int height);
void convertBRG2RGBA3(uchar3 *brg, uchar4 *rgba, int width, int height);
// EXERCISES: 4, 5, 6, 7 DEFINITIONS END

// EXERCISES: 4, 5, 6, 7
bool checkResults(uchar4 *rgba, uchar3 *brg, int size)
{
    bool correct = true;

    for (int i = 0; i < size; ++i)
    {
        correct &= rgba[i].x == brg[i].y;
        correct &= rgba[i].y == brg[i].z;
        correct &= rgba[i].z == brg[i].x;
        correct &= rgba[i].w == 255;
    }

    return correct;
}

// EXERCISES: 4, 6, 7
void convertBRG2RGBA2(uchar3 *brg, uchar4 *rgba, int width, int height)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            rgba[width * y + x].x = brg[width * y + x].y;
            rgba[width * y + x].y = brg[width * y + x].z;
            rgba[width * y + x].z = brg[width * y + x].x;
            rgba[width * y + x].w = 255;
        }
    }
}

// EXERCISE: 5
void convertBRG2RGBA3(uchar3 *brg, uchar4 *rgba, int width, int height)
{
#pragma omp parallel for
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            rgba[width * y + x].x = brg[width * y + x].y;
            rgba[width * y + x].y = brg[width * y + x].z;
            rgba[width * y + x].z = brg[width * y + x].x;
            rgba[width * y + x].w = 255;
        }
    }
}

void exercise_omp(int e) {
    bool na = e == 1 || e == 3; // NOT ALIGNED

    uchar3_na *h_brg_na;
    uchar3 *h_brg;
    uchar4 *h_rgba;

    int bar_widht = HEIGHT/3;

    // Alloc and generate BRG bars.
    if (na) {
        h_brg_na = (uchar3_na*)malloc(sizeof(uchar3_na)*WIDTH*HEIGHT);
        for (int i=0; i < WIDTH * HEIGHT; ++i) {
            if (i < bar_widht) {
                h_brg_na[i] = { 255, 0, 0 };
            } else if (i < bar_widht*2) {
                h_brg_na[i] = { 0, 255, 0 };
            } else {
                    h_brg_na[i] = { 0, 0, 255 };
            }
        }
    } else {
        h_brg = (uchar3*)malloc(sizeof(uchar3)*WIDTH*HEIGHT);
        for (int i=0; i < WIDTH * HEIGHT; ++i) {
            if (i < bar_widht) {
                h_brg[i] = { 255, 0, 0 };
            } else if (i < bar_widht*2) {
                h_brg[i] = { 0, 255, 0 };
            } else {
                    h_brg[i] = { 0, 0, 255 };
            }
        }
    }

    // Alloc RGBA pointers
    h_rgba = (uchar4*)malloc(sizeof(uchar4)*WIDTH*HEIGHT);

    auto t1 = chrono::high_resolution_clock::now();

    switch(e) {
        case EXERCISE_1:
        case EXERCISE_2:
        for (int i=0; i<EXPERIMENT_ITERATIONS; ++i) {    
            convertBRG2RGBA(h_brg_na, h_rgba, WIDTH, HEIGHT);
        }
        break;
        case EXERCISE_3:
        for (int i=0; i<EXPERIMENT_ITERATIONS_2; ++i) { 
            convertBRG2RGBA2(h_brg_na, h_rgba, WIDTH, HEIGHT);
        }
        break;
        case EXERCISE_4:
        for (int i=0; i<EXPERIMENT_ITERATIONS_2; ++i) { 
            convertBRG2RGBA2(h_brg, h_rgba, WIDTH, HEIGHT);
        }
        break;
        case EXERCISE_5:
        for (int i=0; i<EXPERIMENT_ITERATIONS_2; ++i) { 
            convertBRG2RGBA3(h_brg, h_rgba, WIDTH, HEIGHT);
        }
        break;
        case EXERCISE_6:
        #pragma omp parallel
        {
            #pragma omp for
            for (int i = 0; i < EXPERIMENT_ITERATIONS_2; ++i)
            {
                convertBRG2RGBA2(h_brg, h_rgba, WIDTH, HEIGHT);
            }
        }
        break;
        case EXERCISE_7:
        #pragma omp parallel
        {
            #pragma omp critical
            {
            cout << "Thread ID: " << omp_get_thread_num() << endl;
            }
            #pragma omp for
            for (int i = 0; i < EXPERIMENT_ITERATIONS_2; ++i)
            {
                convertBRG2RGBA2(h_brg, h_rgba, WIDTH, HEIGHT);
            }
        }
        break;
    }

    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();

    switch(e) {
        case EXERCISE_1:
        case EXERCISE_2:
        cout << "convertBRG2RGBA time for ";
        break;
        case EXERCISE_3:
        case EXERCISE_4:
        case EXERCISE_6:
        case EXERCISE_7:
        cout << "convertBRG2RGBA2 time for ";
        break;
        case EXERCISE_5:
        cout << "convertBRG2RGBA3 time for ";
        break;
    }

    cout << EXPERIMENT_ITERATIONS \
    << " iterations = "<< duration << "us" << endl;

    bool ok;
    if (na) {
        ok = checkResults(h_rgba, h_brg_na, WIDTH*HEIGHT);
    } else {
        ok = checkResults(h_rgba, h_brg, WIDTH*HEIGHT);
    }

    if (ok) {
        cout << "Executed!! Results OK." << endl;
    } else {
        cout << "Executed!! Results NOT OK." << endl;
    }
}