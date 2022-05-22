#include <iostream>
#include <string>
using namespace std;

int partition(string[], int, int);
void sort(string[], int, int);

int main()
{
    string array[7] = {"Russian", "English", "Italian", "Spanish", "Hebrew", "French", "German"};
    cout << "Input: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    sort(array, 0, 6);
    cout << "Output: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

int partition(string array[], int low, int high)
{
    int pivot = high, i = low - 1;
    string tmp;
    for (int j = low; j < high; j++)
    {
        if(array[j].compare(array[pivot]) <= 0)
        {
            i++;
            array[i].swap(array[j]);
        }
    }
    array[i + 1].swap(array[high]);
    return i + 1;
}
void sort(string array[], int low, int high)
{
    if (low < high)
    {
    int pivot = partition(array, low, high);
    sort(array, low, pivot - 1);
    sort(array, pivot + 1, high);
    }
}
