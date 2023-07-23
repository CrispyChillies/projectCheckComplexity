#include "sort.hpp"
#include "DataGenerator.hpp"

/////////////////////////////
///////Selection-sort////////
/////////////////////////////

void selection_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 0; ++comparisons && i < n; i++)
    {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++comparisons && j < n; j++)
        {
            if (++comparisons && a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        HoanVi(a[i], a[minIndex]);
    }
}

void selection_sort_time(int a[], int n, double &time)
{
    clock_t start = clock();
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        HoanVi(a[i], a[minIndex]);
    }
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC * 1000;
}

/////////////////////////////
///////Insertion-sort////////
/////////////////////////////

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertion_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 1; ++comparisons && i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (++comparisons && a[j] > key && ++comparisons && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertion_sort_time(int a[], int n, double &time)
{
    clock_t start = clock();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC * 1000;
}

/////////////////////////////
/////////Bubble-sort/////////
/////////////////////////////

void bubble_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 0; ++comparisons && i < n; i++)
    {
        for (int j = n - 1; ++comparisons && j > i; j--)
        {
            if (++comparisons && a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
            }
        }
    }
}

void bubble_sort_time(int a[], int n, double &time)
{
    clock_t start = clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
            }
        }
    }
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC * 1000;
}

/////////////////////////////
/////////Shaker-sort/////////
/////////////////////////////

void shakerSort_count(int a[], int n, long long &countCompare)
{
    int left = 0;
    int k = 0;
    int right = n - 1;
    int temp = 0;

    do
    {
        for (int j = right; ++countCompare && j > left; j--)
        {
            // Comparison: a[j - 1] > a[j]

            if (++countCompare && a[j - 1] > a[j])
            {
                HoanVi(a[j - 1], a[j]);
                k = j;
            }
        }

        left = k;

        for (int j = left; ++countCompare && j < right; j++)
        {
            // Comparison: a[j] > a[j + 1]

            if (++countCompare && a[j] > a[j + 1])
            {
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
        }

        right = k;
        // Assignment: right = k

    } while (++countCompare && left < right);
}

void shakerSort(int a[], int n)
{
    int left = 0;
    int k = 0;
    int right = n - 1;
    int temp = 0;

    do
    {
        for (int j = right; j > left; j--)
        {
            if (a[j - 1] > a[j])
            {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                k = j;
            }
        }

        left = k;

        for (int j = left; j < right; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                k = j;
            }
        }

        right = k;

    } while (left < right);
}

void get_time_shakerSort(int a[], int n, double &elapsedTime)
{
    clock_t start, end;

    start = clock();

    shakerSort(a, n);

    end = clock();

    elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

//////////////////////////////
/////////Shell-sort///////////
//////////////////////////////

int shell_sort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

double get_time_shell_sort(int a[], int n)
{
    clock_t start, end;

    start = clock();
    shell_sort(a, n);
    end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC * 1000;
}

void shell_sort_count(int arr[], int n, long long &compCount)
{
    for (int gap = n / 2; ++compCount && gap > 0; gap /= 2)
    {
        for (int i = gap; ++compCount && i < n; i += 1)
        {
            int temp = arr[i];
            int j;

            for (j = i; ++compCount && j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

//////////////////////////////
//////////Heap-sort///////////
//////////////////////////////

void sift_with_count_compare(int a[], int left, int right,long long& count_compare) {
    int i = left;
    int j = i * 2;
    int x = a[i];
    while (++count_compare && j <= right) {
        if (++count_compare && j < right) {
            if (++count_compare && a[j] > a[j + 1]) {
                j++;
            }
        }
        if (++count_compare && x <= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j; j = i * 2;
    }
    a[i] = x;
}
void Heap_sort_with_count_compare(int a[], int n,long long& count_compare) {
    int left = n / 2;
    int right = n - 1;
    while (++count_compare && left > 0) {
        sift_with_count_compare(a, left, right, count_compare);
        left--;
    }
    while (++count_compare && right > 1) {
        std::swap(a[right], a[1]);
        right--;
        sift_with_count_compare(a, 1, right, count_compare);
    }
}

void sift_without_count_compare(int a[], int left, int right) {
    int i = left;
    int j = i * 2;
    int x = a[i];
    while (j <= right) {
        if (j < right) {
            if (a[j] > a[j + 1]) {
                j++;
            }
        }
        if (x <= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j; j = i * 2;
    }
    a[i] = x;
}
void Heap_sort_without_count_compare(int a[], int n) {
    int left = n / 2;
    int right = n - 1;
    while (left > 0) {
        sift_without_count_compare(a, left, right);
        left--;
    }
    while (right > 1) {
        std::swap(a[right], a[1]);
        right--;
        sift_without_count_compare(a, 1, right);
    }
}
double Heap_sort_running_time(int a[], int n) {
    clock_t Start = clock();
    Heap_sort_without_count_compare(a, n);
    clock_t End = clock();
    double RunningTime = static_cast<double>(End - Start) * 1000 / CLOCKS_PER_SEC;
    return RunningTime;
}

////////////////////////////////
//////////Merge-sort///////////
////////////////////////////////
void merge_with_count_compare(int a[], int left, int right, int mid,long long& count_compare) {
    int t1 = mid - left + 1;
    int t2 = right - mid;
    int* ML = new int[t1]; // mid to left
    int* MR = new int[t2]; // mid to right
    for (int i = 0; ++count_compare && i < t1; i++) {
        ML[i] = a[i + left];
    }
    for (int j = 0; ++count_compare && j < t2; j++) {
        MR[j] = a[j + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (++count_compare && i < t1 && ++count_compare && j < t2) {
        if (++count_compare && ML[i] > MR[j]) {
            a[k] = MR[j];
            j++;
        }
        else {
            a[k] = ML[i];
            i++;
        }
        k++;
    }
    while (++count_compare && i < t1) {
        a[k] = ML[i];
        k++; i++;
    }
    while (++count_compare && j < t2) {
        a[k] = MR[j];
        k++; j++;
    }
    delete[] MR;
    delete[] ML;
}
void Merge_sort_with_count_compare(int a[], int left, int right, long long& count_compare) {
    if (++count_compare && left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort_with_count_compare(a, left, mid, count_compare);
        Merge_sort_with_count_compare(a, mid + 1, right, count_compare);
        merge_with_count_compare(a, left, right, mid, count_compare);
    }
}

void merge_without_count_compare(int a[], int left, int right, int mid) {
    int t1 = mid - left + 1;
    int t2 = right - mid;
    int* ML = new int[t1]; // mid to left
    int* MR = new int[t2]; // mid to right
    for (int i = 0; i < t1; i++) {
        ML[i] = a[i + left];
    }
    for (int j = 0; j < t2; j++) {
        MR[j] = a[j + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < t1 && j < t2) {
        if (ML[i] > MR[j]) {
            a[k] = MR[j];
            j++;
        }
        else {
            a[k] = ML[i];
            i++;
        }
        k++;
    }
    while (i < t1) {
        a[k] = ML[i];
        k++; i++;
    }
    while (j < t2) {
        a[k] = MR[j];
        k++; j++;
    }
    delete[] MR;
    delete[] ML;
}
void Merge_sort_without_count_compare(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort_without_count_compare(a, left, mid);
        Merge_sort_without_count_compare(a, mid + 1, right);
        merge_without_count_compare(a, left, right, mid);
    }
}
double Merge_sort_running_time(int a[], int n) {
    clock_t Start = clock();
    Merge_sort_without_count_compare(a, 0, n - 1);
    clock_t End = clock();
    double RunningTime = static_cast<double>(End - Start) * 1000 / CLOCKS_PER_SEC;
    return RunningTime;
}
///////////////////////////////
//////////Quick-sort///////////
///////////////////////////////
int Partition_without_count_compare(int a[], int low, int high) {
    int p = a[(high + low) / 2];
    int i = low - 1;
    for (int j = low;j < high; j++) {
        if (a[j] <= p) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}
void Quick_sort_without_count_compare(int a[], int left, int right) {
    int s = 0;
    if (left < right) {
        s = Partition_without_count_compare(a, left, right);
        Quick_sort_without_count_compare(a, left, s - 1);
        Quick_sort_without_count_compare(a, s + 1, right);
    }
}

int Partition_with_count_compare(int a[], int low, int high,long long& count_compare) {
    int p = a[(high + low) / 2];
    int i = low-1;
    for (int j = low; ++count_compare && j < high; j++) {
        if (a[j] <= p) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}
void Quick_sort_with_count_compare(int a[], int left, int right,long long& count_compare) {
    int s = 0;
    if (left < right && ++count_compare) {
        s = Partition_with_count_compare(a, left, right, count_compare);
        Quick_sort_with_count_compare(a, left, s - 1, count_compare);
        Quick_sort_with_count_compare(a, s + 1, right, count_compare);
    }
}
double Quick_sort_running_time(int a[], int n) {
    clock_t StartOfQuicksort = clock();
    Quick_sort_without_count_compare(a, 0, n - 1);
    clock_t EndofQuicksort = clock();
    double RunningTime = static_cast<double>(EndofQuicksort - StartOfQuicksort) * 1000 / CLOCKS_PER_SEC;
    return RunningTime;
}

//////////////////////////////
////////Counting-sort/////////
//////////////////////////////

void countingSort(int a[], int n)
{
    int *u = new int[n];
    int *b = new int[n];

    for (int i = 0; i < n; i++)
    {
        u[i] = 0;
    }

    for (int i = 0; i < n; i++)
        u[a[i]]++;

    for (int i = 1; i < n; i++)
        u[i] = u[i - 1] + u[i];

    for (int i = n - 1; i >= 0; i--)
    {
        b[u[a[i]] - 1] = a[i];
        u[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] u;
}

void get_time_countingSort(int a[], int n, double &elaspedTime)
{
    clock_t start, end;

    start = clock();
    countingSort(a, n);
    end = clock();

    elaspedTime = double(end - start) / CLOCKS_PER_SEC * 1000;
}

void countingSort_count(int a[], int n, long long &countCompare)
{
    int *u = new int[n];
    int *b = new int[n];

    memset(u, 0, n * sizeof(int));

    for (int i = 0; ++countCompare && i < n; i++)
        u[a[i]]++;

    for (int i = 1; ++countCompare && i < n; i++)
        u[i] = u[i - 1] + u[i];

    for (int i = n - 1; ++countCompare && i >= 0; i--)
    {
        b[u[a[i]] - 1] = a[i];
        u[a[i]]--;
    }

    for (int i = 0; ++countCompare && i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] u;
}

//////////////////////////////
//////////Flash-sort//////////
//////////////////////////////

void flashSort(int a[], int n)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    HoanVi(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    insertion_sort(a, n);
}

void flashSort_count(int a[], int n, long long &countCompare)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];

    for (int i = 0; ++countCompare && i < m; i++)
        l[i] = 0;
    for (int i = 1; ++countCompare && i < n; i++)
    {
        if (++countCompare && a[i] < minVal)
            minVal = a[i];
        if (++countCompare && a[i] > a[max])
            max = i;
    }

    if (++countCompare && a[max] == minVal)
        return;

    double c1 = (double)(m - 1) / (a[max] - minVal);

    for (int i = 0; ++countCompare && i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    for (int i = 1; ++countCompare && i < m; i++)
        l[i] += l[i - 1];

    HoanVi(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++countCompare && nmove < n - 1)
    {
        while (++countCompare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }

        flash = a[j];

        if (++countCompare && k < 0)
            break;
        while (++countCompare && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }

    delete[] l;
    insertion_sort_comparisons(a, n, countCompare);
}

void get_time_flashSort(int a[], int n, double &elaspedTime)
{
    clock_t start, end;

    start = clock();
    flashSort(a, n);
    end = clock();

    elaspedTime = double(end - start) / CLOCKS_PER_SEC * 1000;
}

//////////////////////////////
//////////Radix-sort//////////
//////////////////////////////

int get_number_digits(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int count = 0;

    while (max > 0)
    {
        count++;
        max /= 10;
    }

    return count;
}

int getDigit(int num, int digit)
{
    while (digit > 1)
    {
        num /= 10;
        digit--;
    }

    return num % 10;
}

void sort(int a[], int n, int k)
{
    int *b = new int[n];
    int f[10] = {0};

    for (int i = 0; i < n; i++)
        f[getDigit(a[i], k)]++;

    for (int i = 1; i < 10; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int j = getDigit(a[i], k);
        b[f[j] - 1] = a[i];
        f[j]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
}

void radixsort(int a[], int n)
{
    int d = get_number_digits(a, n);

    for (int k = 1; k <= d; k++)
        sort(a, n, k);
}

double get_time_radix_sort(int a[], int n)
{
    clock_t start, end;

    start = clock();
    radixsort(a, n);
    end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC * 1000;
}

int get_number_digits_count(int a[], int n, long long &compCount)
{
    int max = a[0];

    for (int i = 1; ++compCount && i < n; i++)
        if (++compCount && a[i] > max)
            max = a[i];

    int count = 0;

    while (++compCount && max > 0)
    {
        count++;
        max /= 10;
    }

    return count;
}

int getDigit_count(int num, int digit, long long &compCount)
{
    while (++compCount && digit > 1)
    {
        num /= 10;
        digit--;
    }

    return num % 10;
}

void sort_count(int a[], int n, int k, long long &compCount)
{
    int *b = new int[n];
    int f[10] = {0};

    for (int i = 0; ++compCount && i < n; i++)
    {
        f[getDigit_count(a[i], k, compCount)]++;
    }

    for (int i = 1; ++compCount && i < 10; i++)
    {
        f[i] += f[i - 1];
    }

    for (int i = n - 1; ++compCount && i >= 0; i--)
    {
        int j = getDigit_count(a[i], k, compCount);
        b[f[j] - 1] = a[i];
        f[j]--;
    }

    for (int i = 0; ++compCount && i < n; i++)
    {
        a[i] = b[i];
    }

    delete[] b;
}

void radixsort_count(int a[], int n, long long &compCount)
{
    int d = get_number_digits_count(a, n, compCount);

    for (int k = 1; ++compCount && k <= d; k++)
        sort(a, n, k);
}



// Creating data and check commands
void createData_3(char *argv[])
{
    int n = stoi(argv[3]);
    int *a = new int[n];

    GenerateRandomData(a, n);
    ofstream out1("input1.txt");
    output_to_file(out1, a, n);
    out1.close();

    GenerateNearlySortedData(a, n);
    ofstream out2("input2.txt");
    output_to_file(out2, a, n);
    out2.close();

    GenerateSortedData(a, n);
    ofstream out3("input3.txt");
    output_to_file(out3, a, n);
    out3.close();

    GenerateReverseData(a, n);
    ofstream out4("input4.txt");
    output_to_file(out4, a, n);
    out4.close();
}

void count_sort_comparisons(char *argv[], long long num_of_comparisons[])
{
    int n = stoi(argv[3]);
    int *a = new int[n];

    if (strcmp(argv[2], "bubble-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        bubble_sort_comparisons(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        bubble_sort_comparisons(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        bubble_sort_comparisons(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        bubble_sort_comparisons(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "selection-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        selection_sort_comparisons(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        selection_sort_comparisons(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        selection_sort_comparisons(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        selection_sort_comparisons(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "insertion-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        insertion_sort_comparisons(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        insertion_sort_comparisons(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        insertion_sort_comparisons(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        insertion_sort_comparisons(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "radix-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        num_of_comparisons[0] = 0;
        radixsort_count(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        num_of_comparisons[1] = 0; 
        radixsort_count(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        num_of_comparisons[2] = 0; 
        radixsort_count(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        num_of_comparisons[3] = 0; 
        radixsort_count(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "shaker-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        num_of_comparisons[0] = 0; 
        shakerSort_count(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        num_of_comparisons[1] = 0; 
        shakerSort_count(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        num_of_comparisons[2] = 0; 
        shakerSort_count(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        num_of_comparisons[3] = 0; 
        shakerSort_count(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "counting-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        num_of_comparisons[0] = 0; 
        countingSort_count(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        num_of_comparisons[1] = 0; 
        countingSort_count(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        num_of_comparisons[2] = 0; 
        countingSort_count(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        num_of_comparisons[3] = 0; 
        countingSort_count(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "shell-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        num_of_comparisons[0] = 0; 
        shell_sort_count(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        num_of_comparisons[1] = 0; 
        shell_sort_count(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        num_of_comparisons[2] = 0; 
        shell_sort_count(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        num_of_comparisons[3] = 0; 
        shell_sort_count(a, n, num_of_comparisons[3]);
    }
    if (strcmp(argv[2], "flash-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        num_of_comparisons[0] = 0; 
        flashSort_count(a, n, num_of_comparisons[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        num_of_comparisons[1] = 0; 
        flashSort_count(a, n, num_of_comparisons[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        num_of_comparisons[2] = 0; 
        flashSort_count(a, n, num_of_comparisons[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        num_of_comparisons[3] = 0; 
        flashSort_count(a, n, num_of_comparisons[3]);
    }
    
}

void count_sort_time(char *argv[], double time[])
{
    int n = stoi(argv[3]);
    int *a = new int[n];
    if (strcmp(argv[2], "bubble-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        bubble_sort_time(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        bubble_sort_time(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        bubble_sort_time(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        bubble_sort_time(a, n, time[3]);
    }
    if (strcmp(argv[2], "selection-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        selection_sort_time(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        selection_sort_time(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        selection_sort_time(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        selection_sort_time(a, n, time[3]);
    }
    if (strcmp(argv[2], "insertion-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        insertion_sort_time(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        insertion_sort_time(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        insertion_sort_time(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        insertion_sort_time(a, n, time[3]);
    }
    if (strcmp(argv[2], "radix-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        time[0] = get_time_radix_sort(a, n);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        time[1] = get_time_radix_sort(a, n);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        time[2] = get_time_radix_sort(a, n);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        time[3] = get_time_radix_sort(a, n);
    }
    if (strcmp(argv[2], "shaker-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        get_time_shakerSort(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        get_time_shakerSort(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        get_time_shakerSort(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        get_time_shakerSort(a, n, time[3]);
    }
    if (strcmp(argv[2], "counting-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        get_time_countingSort(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        get_time_countingSort(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        get_time_countingSort(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        get_time_countingSort(a, n, time[3]);
    }
    if (strcmp(argv[2], "shell-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        time[0] = get_time_shell_sort(a, n);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        time[1] = get_time_shell_sort(a, n);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        time[2] = get_time_shell_sort(a, n);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        time[3] = get_time_shell_sort(a, n);
    }
    if (strcmp(argv[2], "flash-sort") == 0)
    {
        ifstream in_random("input1.txt");
        input_from_file(in_random, a, n);
        in_random.close();
        get_time_flashSort(a, n, time[0]);

        ifstream in_nearlysorted("input2.txt");
        input_from_file(in_nearlysorted, a, n);
        in_nearlysorted.close();
        get_time_flashSort(a, n, time[1]);

        ifstream in_sorted("input3.txt");
        input_from_file(in_sorted, a, n);
        in_sorted.close();
        get_time_flashSort(a, n, time[2]);

        ifstream in_reversed("input4.txt");
        input_from_file(in_reversed, a, n);
        in_reversed.close();
        get_time_flashSort(a, n, time[3]);
    }
}

