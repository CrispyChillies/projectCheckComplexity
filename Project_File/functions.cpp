#include "functions.hpp"
#include "DataGenerator.hpp"

void countingSort(int a[], int n)
{
    int *u = new int[n];
    int *b = new int[n];

    for (int i = 0; i < n; i++)
        u[i] = 0;

    for (int i = 0; i < n; i++)
        u[a[i]]++;

    for (int i = 1; i < 100; i++)
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

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (a[k] > key && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}

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
    insertionSort(a, n);
}

void insertionSort_count(int a[], int n, long long &countCompare)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (++countCompare && a[k] > key && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}

void flashSort_count(int a[], int n, long long &countCompare)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];

    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (++countCompare && a[i] < minVal)
            minVal = a[i];
        if (++countCompare && a[i] > a[max])
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
        while (++countCompare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }

        flash = a[j];

        if (++countCompare && k < 0)
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
    insertionSort(a, n);
}

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

void bubble_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1] && ++comparisons)
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
    time = double(end - start) / CLOCKS_PER_SEC;
}

void selection_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min && ++comparisons)
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
    time = double(end - start) / CLOCKS_PER_SEC;
}

void insertion_sort_comparisons(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (a[j] > key && j >= 0 && ++comparisons && ++comparisons)
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
    time = double(end - start) / CLOCKS_PER_SEC;
}

//Hieu - radix sort
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

int getDigit(int num, int digit) {
    while (digit > 1) {
        num /= 10;
        digit--;
    }
    return num % 10;
}

void sort(int a[], int n, int k) {
    int* b = new int[n];
    int* f = new int[10](0);

    for (int i = 0; i < n; i++)
        f[getDigit(a[i], k)]++;

    for (int i = 1; i < 10; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int j = getDigit(a[i], k);
        b[f[j] - 1] = a[i];
        f[j]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
}

void radix_sort(int a[], int n) {
    int d = get_number_digits(a, n);
    for (int k = 1; k <= d; k++)
        sort(a, n, k);
}

double get_time_radix_sort(int a[], int n)
{
    int start = clock();
    radixsort(a, n);
    int end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

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
    int comparisons = 0;
    if (strcmp(argv[2], "-bubble-sort") == 0)
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
    if (strcmp(argv[2], "-selection-sort") == 0)
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
    if (strcmp(argv[2], "-insertion-sort") == 0)
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
}

void count_sort_time(char *argv[], double time[])
{
    int n = stoi(argv[3]);
    int *a = new int[n];
    if (strcmp(argv[2], "-bubble-sort") == 0)
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
    if (strcmp(argv[2], "-selection-sort") == 0)
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
    if (strcmp(argv[2], "-insertion-sort") == 0)
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
}

void command_3(char *argv[])
{
    long long num_of_comparisons[4];
    double time[4];
    createData_3(argv);
    int size = stoi(argv[3]); // size of the array
    if (strcmp(argv[4], "-comp") == 0)
    {
        count_sort_comparisons(argv, num_of_comparisons);
    }
    if (strcmp(argv[4], "-time") == 0)
    {
        count_sort_time(argv, time);
    }
    if (strcmp(argv[4], "-both") == 0)
    {
        count_sort_comparisons(argv, num_of_comparisons);
        count_sort_time(argv, time);
    }
    final_output(argv, num_of_comparisons, time);
}

void final_output(char *argv[], long long num_of_comparisons[], double time[])
{
    cout << "ALGORITHM MODE" << '\n';
    char *algorithm = argv[2];

    // remove dashes
    char *space = strchr(algorithm, '-');
    space[0] = ' ';
    space = strchr(algorithm, '-');
    space[0] = ' ';

    cout << "Algorithm:" << algorithm << '\n';
    cout << "Input size: " << stoi(argv[3]) << '\n'
         << '\n';

    // Random data
    cout << "Input order: Randomize" << '\n';
    cout << "--------------------------" << '\n';
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Running time: " << time[0] << '\n';
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Comparisons: " << num_of_comparisons[0] << '\n';
    cout << '\n';

    // Nearly sorted data
    cout << "Input order: Nearly Sorted" << '\n';
    cout << "--------------------------" << '\n';
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Running time: " << time[1] << '\n';
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Comparisons: " << num_of_comparisons[1] << '\n';
    cout << '\n';

    // Sorted data
    cout << "Input order: Sorted" << '\n';
    cout << "--------------------------" << '\n';
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Running time: " << time[2] << '\n';
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Comparisons: " << num_of_comparisons[2] << '\n';
    cout << '\n';

    // Reversed data
    cout << "Input order: Reversed" << '\n';
    cout << "--------------------------" << '\n';
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Running time: " << time[3] << '\n';
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        cout << "Comparisons: " << num_of_comparisons[3] << '\n';
    cout << '\n';
}

void command_1(int argc, char *argv[])
{
    if (argc == 6)
        return;

    long long countCompare = 0;

    string algorithm = argv[2];
    string Input_Size = argv[3];
    string outputParams = argv[4];

    int l = Input_Size.length();

    string check;
    int cnt = 0;

    for (int i = l - 1; i >= 0; i--)
    {
        cnt++;
        if (cnt > 3)
        {
            break;
        }
        check += Input_Size[i];
    }

    cout << "ALGORITHM: " << algorithm << endl;
    cout << "Input file: " << Input_Size << endl;

    if (check != "txt")
    {
        return;
    }
    else
    {
        ifstream inf(Input_Size);

        if (!inf)
        {
            cout << "Can't open input file. \n";
            exit(1);
        }

        int count = 0;

        inf >> count;

        int *a = new int[count];

        for (int i = 0; i < count; i++)
        {
            inf >> a[i];
        }

        inf.close();

        // Calculate the run time and the comparisions of the algorithm

        double elaspedTime = 0;
        clock_t start, end;

        if (algorithm == "bubble-sort")
        {
        }
        else if (algorithm == "selection-sort")
        {
            /* code */
        }
        else if (algorithm == "insertion-sort")
        {
            /* code */
        }
        else if (algorithm == "heap-sort")
        {
        }
        else if (algorithm == "merge-sort")
        {
        }
        else if (algorithm == "quick-sort")
        {
        }
        else if (algorithm == "radix-sort")
        {
        }
        else if (algorithm == "shaker-sort")
        {
            start = clock();
            shakerSort(a, count);
            end = clock();

            elaspedTime = double(end - start) / CLOCKS_PER_SEC;

            shakerSort_count(a, count, countCompare);
        }
        else if (algorithm == "counting-sort")
        {
            start = clock();
            countingSort(a, count);
            end = clock();

            elaspedTime = double(end - start) / CLOCKS_PER_SEC;
        }
        else if (algorithm == "shell-sort")
        {
        }
        else if (algorithm == "flash-sort")
        {
            start = clock();
            flashSort(a, count);
            end = clock();
            elaspedTime = double(end - start) / CLOCKS_PER_SEC;

            flashSort_count(a, count, countCompare);
        }

        if (outputParams == "-both")
        {
            cout << "---------------------\n";
            cout << "Running Time: " << elaspedTime << endl;
            cout << "Comparisions: " << countCompare << endl;
        }
        else if (outputParams == "-comp")
        {
            cout << "---------------------\n";
            cout << "Comparisions: " << countCompare << endl;
        }
        else
        {
            cout << "---------------------\n";
            cout << "Running Time: " << elaspedTime << endl;
        }

        // Write the file into another file
        ofstream out("output.txt");

        if (!out)
        {
            cout << "Can't open des file. \n";
            exit(1);
        }

        for (int i = 0; i < count; i++)
        {
            out << a[i] << endl;
        }

        out.close();
    }
}
