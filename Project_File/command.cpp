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
        GenerateData(a, n, 0);
    }
    else if (input_order == "-sorted")
    {
        GenerateData(a, n, 1);
    }
    else if (input_order == "-nsorted")
    {
        GenerateData(a, n, 3);
    }
    else if (input_order == "-rev")
    {
        GenerateData(a, n, 2);
    }
    else
    {
        outf.close();
        cout << "Wrong Arguments.\n";
        exit(1);
    }

    output_to_file(outf, a, n);
    outf.close();

    long long num_of_comparisons_1 = 0, num_of_comparisons_2 = 0;
    double time_1, time_2 = 0;

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
        heap_sort_count(a, n, num_of_comparisons_1);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_1 = get_time_heap_sort(a, n);
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
        exit(1);

    ifstream inpf("input.txt");
    input_from_file(inpf, a, n);

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
        heap_sort_count(a, n, num_of_comparisons_2);

        ifstream inpf("input.txt");
        input_from_file(inpf, a, n);
        inpf.close();

        time_2 = get_time_heap_sort(a, n);
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
        cout << endl;
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

// Command line 2| Syntax : [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
long Time_Output_Parameter(char *argv[], int a[], int n)
{
    std::string Algorithm = argv[2];
    double TimeOP = 0;
    if (Algorithm == "selection-sort")
    {
        selection_sort_time(a, n, TimeOP);
    }
    else if (Algorithm == "insertion-sort")
    {
        insertion_sort_time(a, n, TimeOP);
    }
    else if (Algorithm == "bubble-sort")
    {
        bubble_sort_time(a, n, TimeOP);
    }
    else if (Algorithm == "heap-sort")
    {
        TimeOP = get_time_heap_sort(a, n);
    }
    else if (Algorithm == "merge-sort")
    {
        TimeOP = get_time_merge_sort(a, n);
    }
    else if (Algorithm == "quick-sort")
    {
        TimeOP = get_time_quick_sort(a, n);
    }
    else if (Algorithm == "radix-sort")
    {
        TimeOP = get_time_radix_sort(a, n);
    }
    else if (Algorithm == "shaker-sort")
    {
        get_time_shakerSort(a, n, TimeOP);
    }
    else if (Algorithm == "shell-sort")
    {
        TimeOP = get_time_shell_sort(a, n);
    }
    else if (Algorithm == "counting-sort")
    {
        get_time_countingSort(a, n, TimeOP);
    }
    else if (Algorithm == "flash-sort")
    {
        get_time_flashSort(a, n, TimeOP);
    }
    return TimeOP;
}

long Compare_Output_Parameter(char *argv[], int a[], int n)
{
    std::string Algorithm = argv[2];
    long long count_compare = 0;

    if (Algorithm == "selection-sort")
    {
        selection_sort_comparisons(a, n, count_compare);
    }
    else if (Algorithm == "insertion-sort")
    {
        insertion_sort_comparisons(a, n, count_compare);
    }
    else if (Algorithm == "bubble-sort")
    {
        bubble_sort_comparisons(a, n, count_compare);
    }
    else if (Algorithm == "heap-sort")
    {
        heap_sort_count(a, n, count_compare);
    }
    else if (Algorithm == "merge-sort")
    {
        // merge_sort_count(a,n, count_compare);
    }
    else if (Algorithm == "quick-sort")
    {
        // Quick_sort_with_count_compare(a, n, count_compare);
    }
    else if (Algorithm == "radix-sort")
    {
        count_compare = get_time_radix_sort(a, n);
    }
    else if (Algorithm == "shaker-sort")
    {
        shakerSort_count(a, n, count_compare);
    }
    else if (Algorithm == "shell-sort")
    {
        shell_sort_count(a, n, count_compare);
    }
    else if (Algorithm == "counting-sort")
    {
        countingSort_count(a, n, count_compare);
    }
    else if (Algorithm == "flash-sort")
    {
        flashSort_count(a, n, count_compare);
    }
    return count_compare;
}

void command_2(int argc, char *argv[])
{
    std::string Algorithm = argv[2];
    std::string InputSize = argv[3];
    std::string DataOrder = argv[4];
    std::string OutputParammeter = argv[5];
    int SizeOfInput = std::stoi(InputSize);
    if (SizeOfInput == 0)
    {
        std::cerr << "There is no data in the file ";
        return;
    }
    int NumForGenerateData;
    if (DataOrder == "-rand")
    {
        NumForGenerateData = 0;
    }
    else if (DataOrder == "-sorted")
    {
        NumForGenerateData = 1;
    }
    else if (DataOrder == "-rev")
    {
        NumForGenerateData = 2;
    }
    else if (DataOrder == "-nsorted")
    {
        NumForGenerateData = 3;
    }
    else
    {
        std::cerr << "Invalid input order! Please using these syntax:" << std::endl;
        std::cout << "-Random order : -rand" << std::endl;
        std::cout << "-Sorted order : -sorted" << std::endl;
        std::cout << "-Reversed order : -rev" << std::endl;
        std::cout << "-Nearly sorted order : -nsorted" << std::endl;
        return;
    }
    int *DataArray = new int[SizeOfInput];
    GenerateData(DataArray, SizeOfInput, NumForGenerateData);
    // output_to_file("Command_2_input.txt",DataArray, SizeOfInput);
    std::cout << "Algorithm: " << Algorithm << std::endl;
    std::cout << "Input size: " << SizeOfInput << std::endl;
    std::cout << "Input order: " << DataOrder << std::endl;
    std::cout << "---------------------------" << std::endl;
    if (OutputParammeter == "-time")
    {
        double TimeOP = Time_Output_Parameter(argv, DataArray, SizeOfInput);
        std::cout << "Running time: " << TimeOP;
    }
    else if (OutputParammeter == "-comp")
    {
        long count_compare = Compare_Output_Parameter(argv, DataArray, SizeOfInput);
        std::cout << "Comparisions: " << count_compare;
    }
    else if (OutputParammeter == "-both")
    {
        double TimeOP = Time_Output_Parameter(argv, DataArray, SizeOfInput);
        std::cout << "Running time: " << TimeOP << std::endl;
        long count_compare = Compare_Output_Parameter(argv, DataArray, SizeOfInput);
        std::cout << "Comparisions: " << count_compare << std::endl;
    }
    else
    {
        std::cerr << "Invalid output parameter(s)! Please using these syntax:" << std::endl;
        std::cout << "-Running time : -time" << std::endl;
        std::cout << "-Comparisions : -comp" << std::endl;
        std::cout << "-Both of them : -both" << std::endl;
    }
    std::cout << std::endl;
    // output_to_file("Command_2_output.txt",DataArray, SizeOfInput);
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
        heap_sort_count(a, count, countCompare);
        copyFromFile(input_file, a, count);
        get_time_heap_sort(a, count);
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
