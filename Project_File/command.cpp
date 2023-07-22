#include "functions.hpp"
#include "command.hpp"
#include "DataGenerator.hpp"

void final_output(char *argv[], long long num_of_comparisons[], double time[])
{
    cout << "ALGORITHM MODE" << '\n';
    char *algorithm = argv[2];

    // remove dashes
    char *space = strchr(algorithm, '-');
    space[0] = ' ';

    cout << "Algorithm: " << algorithm << '\n';
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

void command_4(int argc, char *argv[])
{
    if (argc > 5)
    {
        cout << "Too many arguments\n";
        exit(1);
    }

    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string input_file = argv[4];

    ifstream inf(input_file);
    if (!inf)
    {
        cout << "Can't open file " << input_file << endl;
        exit(1);
    }

    int n;
    long long num_of_comparisons_1 = 0, num_of_comparisons_2 = 0;
    double time_1 = 0, time_2 = 0;

    inf >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        inf >> a[i];
    }

    // get number of comparisons and time of algorithm 1
    if (algorithm_1 == "bubble-sort")
    {
        bubble_sort_comparisons(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        bubble_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "selection-sort")
    {
        selection_sort_comparisons(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        selection_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "insertion-sort")
    {
        insertion_sort_comparisons(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        insertion_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "shaker-sort")
    {
        shakerSort_count(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        get_time_shakerSort(a, n, time_1);
    }
    else if (algorithm_1 == "shell-sort")
    {
        shell_sort_count(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        time_1 = get_time_shell_sort(a, n);
    }
    else if (algorithm_1 == "heap-sort")
    {
        // heap_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_heap_sort(a, n);
    }
    else if (algorithm_1 == "merge-sort")
    {
        // merge_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_merge_sort(a, n);
    }
    else if (algorithm_1 == "quick-sort")
    {
        // quick_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_quick_sort(a, n);
    }
    else if (algorithm_1 == "flash-sort")
    {
        flashSort_count(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        get_time_flashSort(a, n, time_1);
    }
    else if (algorithm_1 == "counting-sort")
    {
        countingSort_count(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        get_time_countingSort(a, n, time_1);
    }
    else if (algorithm_1 == "radix-sort")
    {
        radixsort_count(a, n, num_of_comparisons_1);
        copyFromFile(input_file, a, n);
        time_1 = get_time_radix_sort(a, n);
    }
    else
    {
        cout << "Invalid algorithm\n";
        exit(1);
    }

    inf.seekg(0, ios::beg);

    for (int i = 0; i < n; i++)
    {
        inf >> a[i];
    }

    // get number of comparisons and time of algorithm 2
    if (algorithm_2 == "bubble-sort")
    {
        bubble_sort_comparisons(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        bubble_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "selection-sort")
    {
        selection_sort_comparisons(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        selection_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "insertion-sort")
    {
        insertion_sort_comparisons(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        insertion_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "shaker-sort")
    {
        shakerSort_count(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        get_time_shakerSort(a, n, time_2);
    }
    else if (algorithm_2 == "shell-sort")
    {
        shell_sort_count(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        time_2 = get_time_shell_sort(a, n);
    }
    else if (algorithm_2 == "heap-sort")
    {
        // heap_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_heap_sort(a, n);
    }
    else if (algorithm_2 == "merge-sort")
    {
        // merge_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_merge_sort(a, n);
    }
    else if (algorithm_2 == "quick-sort")
    {
        // quick_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_quick_sort(a, n);
    }
    else if (algorithm_2 == "flash-sort")
    {
        flashSort_count(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        get_time_flashSort(a, n, time_2);
    }
    else if (algorithm_2 == "counting-sort")
    {
        countingSort_count(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        get_time_countingSort(a, n, time_2);
    }
    else if (algorithm_2 == "radix-sort")
    {
        radixsort_count(a, n, num_of_comparisons_2);
        copyFromFile(input_file, a, n);
        time_2 = get_time_radix_sort(a, n);
    }
    else
    {
        cout << "Invalid algorithm\n";
        exit(1);
    }

    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------" << endl;
    cout << "Running time: " << time_1 << " | " << time_2 << endl;
    cout << "Comparisons: " << num_of_comparisons_1 << " | " << num_of_comparisons_2 << endl;
    cout << endl;

    inf.close();
    delete[] a;
}

void copy_array(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

// Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
void command_5(int argc, char *argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    int n = atoi(argv[4]);
    string input_order = argv[5];

    ofstream outf("input.txt");

    int *a;
    a = new int[n];

    if (input_order == "-rand")
    {
        GenerateRandomData(a, n);
    }
    else if (input_order == "-nsorted")
    {
        GenerateNearlySortedData(a, n);
    }
    else if (input_order == "-sorted")
    {
        GenerateSortedData(a, n);
    }
    else if (input_order == "reverse")
    {
        GenerateReverseData(a, n);
    }

    output_to_file(outf, a, n);
    outf.close();
    
    long long num_of_comparisons_1, num_of_comparisons_2;
    double time_1, time_2;

    if (algorithm_1 == "bubble-sort")
    {
        bubble_sort_comparisons(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        bubble_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "selection-sort")
    {
        selection_sort_comparisons(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        selection_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "insertion-sort")
    {
        insertion_sort_comparisons(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        insertion_sort_time(a, n, time_1);
    }
    else if (algorithm_1 == "shaker-sort")
    {
        shakerSort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_shakerSort(a, n, time_1);
    }
    else if (algorithm_1 == "shell-sort")
    {
        shell_sort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_1 = get_time_shell_sort(a, n);
    }
    else if (algorithm_1 == "heap-sort")
    {
        // heap_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_heap_sort(a, n);
    }
    else if (algorithm_1 == "merge-sort")
    {
        // merge_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_merge_sort(a, n);
    }
    else if (algorithm_1 == "quick-sort")
    {
        // quick_sort_count(a, n, num_of_comparisons_1);
        // time_1 = get_time_quick_sort(a, n);
    }
    else if (algorithm_1 == "flash-sort")
    {
        flashSort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_flashSort(a, n, time_1);
    }
    else if (algorithm_1 == "counting-sort")
    {
        countingSort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_countingSort(a, n, time_1);
    }
    else if (algorithm_1 == "radix-sort")
    {
        radixsort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_1 = get_time_radix_sort(a, n);
    }
    else
    {
        cout << "Invalid algorithm\n";
        exit(1);
    }

    ifstream inpf("input.txt");
	input_from_file(inpf,a,n);

    // get number of comparisons and time of algorithm 2
    if (algorithm_2 == "bubble-sort")
    {
        bubble_sort_comparisons(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        bubble_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "selection-sort")
    {
        selection_sort_comparisons(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        selection_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "insertion-sort")
    {
        insertion_sort_comparisons(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        insertion_sort_time(a, n, time_2);
    }
    else if (algorithm_2 == "shaker-sort")
    {
        shakerSort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_shakerSort(a, n, time_2);
    }
    else if (algorithm_2 == "shell-sort")
    {
        shell_sort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_2 = get_time_shell_sort(a, n);
    }
    else if (algorithm_2 == "heap-sort")
    {
        // heap_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_heap_sort(a, n);
    }
    else if (algorithm_2 == "merge-sort")
    {
        // merge_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_merge_sort(a, n);
    }
    else if (algorithm_2 == "quick-sort")
    {
        // quick_sort_count(a, n, num_of_comparisons_2);
        // time_2 = get_time_quick_sort(a, n);
    }
    else if (algorithm_2 == "flash-sort")
    {
        flashSort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_flashSort(a, n, time_2);
    }
    else if (algorithm_2 == "counting-sort")
    {
        countingSort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        get_time_countingSort(a, n, time_2);
    }
    else if (algorithm_2 == "radix-sort")
    {
        radixsort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_2 = get_time_radix_sort(a, n);
    }
    else
    {
        cout << "Invalid algorithm\n";
        exit(1);
    }

    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " << input_order << endl;
    cout << "-------------------------" << endl;
    cout << "Running time: " << time_1 << " | " << time_2 << endl;
    cout << "Comparisons: " << num_of_comparisons_1 << " | " << num_of_comparisons_2 << endl;
    cout << endl;

    delete[] a;
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

void command_1(int argc, char *argv[])
{
    if (argc == 6)
        return;

    long long countCompare = 0;

    string algorithm = argv[2];
    string input_file = argv[3];
    string outputParams = argv[4];

    ifstream inf(input_file);

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
        bubble_sort_time(a, count, elaspedTime);
        copyFromFile(input_file, a, count);
        bubble_sort_comparisons(a, count, countCompare);
    }
    else if (algorithm == "selection-sort")
    {
        selection_sort_time(a, count, elaspedTime);
        copyFromFile(input_file, a, count);
        selection_sort_comparisons(a, count, countCompare);
    }
    else if (algorithm == "insertion-sort")
    {
        insertion_sort_time(a, count, elaspedTime);
        copyFromFile(input_file, a, count);
        insertion_sort_comparisons(a, count, countCompare);
    }
    else if (algorithm == "heap-sort")
    {
        // heap-sort
    }
    else if (algorithm == "merge-sort")
    {
        // merge-sort
    }
    else if (algorithm == "quick-sort")
    {
        // quick-sort
    }
    else if (algorithm == "radix-sort")
    {
        radixsort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        elaspedTime = get_time_radix_sort(a, count);
    }
    else if (algorithm == "shaker-sort")
    {
        shakerSort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        get_time_shakerSort(a, count, elaspedTime);
    }
    else if (algorithm == "counting-sort")
    {
        countingSort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        get_time_countingSort(a, count, elaspedTime);
    }
    else if (algorithm == "shell-sort")
    {
        shell_sort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        elaspedTime = get_time_shell_sort(a, count);
    }
    else if (algorithm == "flash-sort")
    {
        flashSort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        get_time_flashSort(a, count, elaspedTime);
    }
    else
    {
        cout << "Invalid Argument " << algorithm << ". \n";
        exit(1);
    }

    if (outputParams == "-both")
    {
        cout << "ALGORITHM: " << algorithm << endl;
        cout << "Input file: " << input_file << endl;
        cout << "---------------------\n";
        cout << "Running Time: " << elaspedTime << " ms" << endl;
        cout << "Comparisions: " << countCompare << endl;
    }
    else if (outputParams == "-comp")
    {
        cout << "ALGORITHM: " << algorithm << endl;
        cout << "Input file: " << input_file << endl;
        cout << "---------------------\n";
        cout << "Comparisions: " << countCompare << endl;
    }
    else if (outputParams == "-time")
    {
        cout << "ALGORITHM: " << algorithm << endl;
        cout << "Input file: " << input_file << endl;
        cout << "---------------------\n";
        cout << "Running Time: " << elaspedTime << " ms" << endl;
    }
    else
    {
        cout << "Invalid Argument " << outputParams << ".\n";
        exit(1);
    }

    // Write the file into another file
    ofstream out("output.txt");

    if (!out)
    {
        cout << "Can't open des file. \n";
        exit(1);
    }

    out << count << endl;

    for (int i = 0; i < count; i++)
    {
        out << a[i] << " ";
    }

    out.close();
}

string checkArgv_3(char *argv[])
{
    string Input = argv[3];

    int l = Input.length();

    string check;
    int cnt = 0;

    for (int i = l - 1; i >= 0; i--)
    {
        cnt++;
        if (cnt > 3)
        {
            break;
        }
        check += Input[i];
    }

    return check;
}
