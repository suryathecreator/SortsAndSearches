#include <iostream>
using namespace std;

const int n = 10;

void Initialize(int a[]);
void SelectionSort(int a[]);
int FindMax(int a[],int start);
void Swap(int a[],int p1,int p2);
void Display(int a[]);

int main()
{
	int a[n];
    cout << "Unsorted array: " << endl;
	Initialize(a);
    Display(a);
	SelectionSort(a);
    cout << "Sorted array: " << endl;
	Display(a);
	return 0;
}
void Swap(int a[],int p1,int p2)
{
	int temp=a[p1];
	a[p1]=a[p2];
	a[p2]=temp;
}

void Initialize(int a[]) // program in class had faulty Initialize function so I hard-coded the values
{
	int i;
	a[0] = 3;
    a[1] = 1;
    a[2] = 9;
    a[3] = 2;
    a[4] = 8;
    a[5] = 6;
    a[6] = 11;
    a[7] = 21;
    a[8] = 18;
    a[9] = 14;

}

void SelectionSort(int a[])
{
	int i, index;
	
	for(i=0;i<n;i++)
	{
		index=FindMax(a,i);
		Swap(a,i,index);
	}
}

void Display(int a[])
{
	int i;
	
	for(i=0;i<n;i++)
	   cout<<"a["<<i<<"]="<<a[i]<<endl;
}

int FindMax(int a[],int start)
{
	int i, max;
	max=start;
	
	for(i=start+1;i<n;i++)
	{
		if(a[i]>a[max])
		   max=i;
	}
	
	return max;
}
