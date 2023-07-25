#include "DataGenerator.hpp"

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}


void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = (rand() * rand()) % n;
	}
}


void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}


void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}


void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0: 
		GenerateRandomData(a, n);
		break;
	case 1:
		GenerateNearlySortedData(a, n);
		break;
	case 2: 
		GenerateSortedData(a, n);
		break;
	case 3:
		GenerateReverseData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void output_to_file(ofstream& out, int a[], int n)
{
	out << n << '\n';
	for (int i = 0; i < n; i++)
	{
		out << a[i] << " ";
	}
}

void input_from_file(ifstream& in, int a[], int n)
{
	char line[10];
	in.getline(line, 10);
	for (int i = 0; i < n; i++)
	{
		in >> a[i];
	}
}

void copyFromFile(string inputFile, int* a, int n)
{
	ifstream inf(inputFile);

	if (!inf)
	{
		cout << "Can't open des file to copy.\n";
		return;
	}

	int temp;
	inf >> temp;

	for (int i = 0; i < n; i++)
	{
		inf >> a[i];
	}

	inf.close();
}