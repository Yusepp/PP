#include <iostream>
#include <string>

#include "pract_omp.h"

#define SPACE " "
#define EXERCISE "-e"
#define EXERCISE_V "--exercise"

using namespace std;

bool is_num(string str)
{
    try
    {
        int i = stoi(str);
        //if (i == 0) no need to check!
        return true;
    }
    catch (exception const &e)
    {
        return false;
    }
}

int print_usage(char *argv[])
{
    cout << "Usage:" << SPACE << argv[0] << SPACE << "<option>" << SPACE << "<exercise>" << endl;
    cout << "<option>:" << SPACE << EXERCISE << "," << SPACE << EXERCISE_V << endl;
    cout << "<exercise>:" << SPACE << "integer value" << endl;
    return 1;
}

int main(int argc, char *argv[])
{
    bool paramsc, parame, paramne;

    string mode;
    int exercise;

    paramsc = argc == 3;
    if (!paramsc)
    {
        return print_usage(argv);
    }

    parame = string(argv[1]).compare(EXERCISE) != 0 || string(argv[1]).compare(EXERCISE_V) != 0;
    if (!parame)
    {
        return print_usage(argv);
    }
    mode = EXERCISE;

    paramne = is_num(string(argv[2]));
    if (!paramne)
    {
        return print_usage(argv);
    }
    exercise = stoi(string(argv[2]));

    switch (exercise)
    {
    case EXERCISE_1:
    case EXERCISE_2:
        exercise_omp(EXERCISE_1);
        break;
    case EXERCISE_3:
        exercise_omp(EXERCISE_3);
        break;
    case EXERCISE_4:
        exercise_omp(EXERCISE_4);
        break;
    case EXERCISE_5:
        exercise_omp(EXERCISE_5);
        break;
    case EXERCISE_6:
        exercise_omp(EXERCISE_6);
        break;
    case EXERCISE_7:
        exercise_omp(EXERCISE_7);
        break;
    default:
        cout << "Invalid exercise" << endl;
        break;
    }

    return 0;
}