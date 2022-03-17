#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int MAX = 10;

void initialize(int a[][MAX]);

void clear(int a[][MAX]);

void config(int a[][MAX], int row, int col);//manual insert

int getRandom(int low, int hi);//random # between low and hi

void config(int a[][MAX]);//insert a bunch of #s

void random(int a[][MAX], int n);

void random30(int a[][MAX]);

void copy(int first[][MAX], int second[][MAX]);

void margin(int a[][MAX]);

void print(int a[][MAX]);

int count(int a[][MAX], int row, int col);

void step(int a[][MAX]);

void SaveArray(const char fileName[], int a[][MAX]);

void LoadArray(const char fileName[], int a[][MAX]);

#endif // ARRAY_H
