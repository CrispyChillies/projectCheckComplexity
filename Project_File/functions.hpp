#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>

using namespace std;

void insertionSort(int a[], int n);
void insertionSort_count(int a[], int n, long long &countCompare);

void countingSort(int a[], int n);

void flashSort(int a[], int n);
void flashSort_count(int a[], int n, long long &countCompare);

void shakerSort(int a[], int n);
void shakerSort_count(int a[], int n, long long &countCompare);

// Miscellaneous functions
void createData_3(char *argv[]);
void output_to_file(ofstream &out, int a[], int n);

// Algorithms' functions
void bubble_sort_comparisons(int a[], int n, long long &comparisons);
void bubble_sort_time(int a[], int n, double &time);
void selection_sort_comparisons(int a[], int n, long long &comparisons);
void selection_sort_time(int a[], int n, double &time);
void insertion_sort_comparisons(int a[], int n, long long &comparisons);
void insertion_sort_time(int a[], int n, double &time);

void count_sort_comparisons(char *argv[], long long num_of_comparisons[]);
void count_sort_time(char *argv[], double time[]);

void command_1(int argc, char *argv[]);
void command_3(char *argv[]);
