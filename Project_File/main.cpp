#include "sort.hpp"
#include "DataGenerator.hpp"
#include "command.hpp"

using namespace std;

int main(int argc, char *argv[])
{
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
        if (argc == 5)
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
        else
        {
            command_2(argc, argv);
        }
    }

    if (option == "-c")
    {
        if (argc == 5)
        {
            command_4(argc, argv);
        }
        else
        {
            command_5(argc, argv);
        }
    }

    return 0;
}
