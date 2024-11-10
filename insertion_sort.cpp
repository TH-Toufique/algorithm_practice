#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1];
            j--;
        }
        arr[j + 1];
    }
}

int main()
{
    const int MAX_SIZE = 100000;
    int number[MAX_SIZE];
    int count = 0;

    ifstream input_file("numbers.txt");
    if (!input_file)
    {
        cerr << "The file is not found";
        return -1;
    }

    while (input_file >> number[count] && count < MAX_SIZE)
    {
        count++;
    }
    input_file.close();

    clock_t start = clock();

    insertion_sort(number, count);

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;

    cout << "Time taken to sorts: " << time_taken << " seconds" << endl;
    return 0;
}