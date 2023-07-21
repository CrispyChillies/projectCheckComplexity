#include "functions.hpp"
#include "DataGenerator.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ofstream out("input.txt");
    int n = 1000000;
    out << n << endl;

    if (!out)
    {
        cout << "Can't open file to generate data\n";
        exit(1);
    }

    int *a;

    a = new int[n];

    GenerateReverseData(a, n);

    for (int i = 0; i < n; i++)
    {
        out << a[i] << endl;
    }

    out.close();

    if (argc < 4)
    {
        cout << "Usage: " << argv[0] << " -a [Algorithm] [Given input] [Output parameter(s)]\n";
        cout << "Usage: " << argv[0] << " -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n";
        cout << "Usage: " << argv[0] << " -a [Algorithm] [Input size] [Output parameter(s)]\n";
        cout << "Usage: " << argv[0] << " -c [Algorithm 1] [Algorithm 2] [Given input]\n";
        cout << "Usage: " << argv[0] << " -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
        return 1; // Exit the program indicating an error
    }

    string option = argv[1];

    if (option == "-a")
    {
        if (checkArgv_3(argv) == "txt")
        {
            command_1(argc, argv);
        }
        else
        {
            command_3(argv);
        }
    }

    delete[] a;

    return 0;
}