#include <iostream>
using namespace std;

int binarySearch(string[], int, string);

int main()
{
    string target;
    int index;
    string colors[11] = {"black", "blue", "brown", "green", "magenta", "orange", "pink", "red", "violet", "white", "yellow"}; // case-sensitive
    cout << "What color would you like to search for? ";
    cin >> target;
    index = binarySearch(colors, 11, target);
    if (index == -1)
    {
        cout << "Your color was not found. " << endl;
    }
    else
        cout << "Your color " << colors[index] << " is found in position " << index + 1 << "." << endl;
}

int binarySearch(string arr[], int size, string target)
{
  int first = 0;
  int last = size -1;
  int middle, index = -1;


  bool found = false;
  while((!found) && first <= last)
  {
    middle =(first + last)/2;
    if((arr[middle]).compare(target) == 0)
    {
      found = true;
      index = middle;
    }
    else if((arr[middle]).compare(target) > 0)
        last = middle-1;
    else
        first = middle + 1;
  }

  return index;
}
