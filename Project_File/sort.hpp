#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
#include <cstring>

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

void insertion_sort(int a[], int n);
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

double get_time_quick_sort(int a[], int n);
int Partition_with_count_compare(int a[], int left, int right, long long &count_compare);
void Quick_sort_with_count_compare(int a[], int left, int right, long long &count_compare);

double get_time_merge_sort(int a[], int n);
void Merge_with_count_compare(int a[], int left, int right, int mid, long long &count_compare);
void merge_sort_count(int a[], int left, int right, long long &count_compare);
void Merge_sort_without_count_compare(int a[], int left, int right);

double get_time_heap_sort(int a[], int n);
void Sift_with_count_compare(int a[], int left, int right, long long &count_compare);
void heap_sort_count(int a[], int n, long long &count_compare);
void Heap_sort_without_count_compare(int a[], int n);

// Miscellaneous functions
void createData_3(char *argv[]);

long Compare_Output_Parameter(char *argv[], int a[], int n);
long Time_Output_Parameter(char *argv[], int a[], int n);