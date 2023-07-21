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
void countingSort_count(int a[], int n, long long &countCompare);
void get_time_countingSort(int a[], int n, double &elaspedTime);

void flashSort(int a[], int n);
void flashSort_count(int a[], int n, long long &countCompare);
void get_time_flashSort(int a[], int n, double &elaspedTime);

void shakerSort(int a[], int n);
void shakerSort_count(int a[], int n, long long &countCompare);
void get_time_shakerSort(int a[], int n, double &elaspedTime);

void bubble_sort_comparisons(int a[], int n, long long &comparisons);
void bubble_sort_time(int a[], int n, double &time);

void selection_sort_comparisons(int a[], int n, long long &comparisons);
void selection_sort_time(int a[], int n, double &time);

void insertion_sort_comparisons(int a[], int n, long long &comparisons);
void insertion_sort_time(int a[], int n, double &time);

void count_sort_comparisons(char *argv[], long long num_of_comparisons[]);
void count_sort_time(char *argv[], double time[]);

void radixsort(int a[], int n);
void radixsort_count(int a[], int n, long long &compCount);
double get_time_radix_sort(int a[], int n);

int shell_sort(int arr[], int n);
void shell_sort_count(int arr[], int n, long long &compCount);
double get_time_shell_sort(int a[], int n);

// Miscellaneous functions
void createData_3(char *argv[]);
void output_to_file(ofstream &out, int a[], int n);

// check mode functions
string checkArgv_3(char *argv[]);

void command_1(int argc, char *argv[]);
void command_3(char *argv[]);
