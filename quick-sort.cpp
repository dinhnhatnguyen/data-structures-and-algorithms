#include <iostream>
using namespace std;


//6 8 3 9 5 7
//pivot = 1
//i = -1
//j = 0 -> 4
//j = 0: 6 8 3 9 5 7 i=0
//j = 1:
//j = 2: 6 3 8 9 5 7 i=1
//j = 3:
//j = 4: 6 3 5 9 8 7 i=2
///: 6 2 5 7 8 9 i = 3 
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

bool ascending(int a, int b)
{
    return a > b;
}

int partition(int l, int r, int a[], bool compare(int, int))
{
    int pivot = a[r];
    int i = l-1;
    int j;
    for(int j = l; j<r; j++)
    {
        if(compare(pivot,a[j]))
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[++i],a[r]);

    return i;
}

void quickSort(int l, int r, int a[], bool compare(int, int))
{
    if(l < r)
    {
        int pivot = partition(l,r,a,compare);

        quickSort(l,pivot-1,a,compare);
        quickSort(pivot+1,r,a,compare);
    }
}

int main()
{
    int a[6] = {6,8,3,9,5,7};
    quickSort(0,5,a,ascending);
    for(int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
}