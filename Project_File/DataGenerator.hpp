#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

template <class T>

void HoanVi(T &a, T &b);
void GenerateData(int a[], int n, int dataType);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);

void input_from_file(ifstream &in, int a[], int n);
void final_output(char *argv[], long long num_of_comparisons[], double time[]);