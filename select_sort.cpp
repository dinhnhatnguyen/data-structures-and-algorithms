#include <iostream>
using namespace std;

void select_sort(int n , int a[])
{
    for(int i=0 ; i<n ; i++)
    {
        int min_local = i;
        for(int j = i+1; j<n-2 ; j++)
        {
            if(a[min_local]>a[j])
            {
                min_local = j; // lấy vị trí phần tử nhỏ nhất
            }
        }
        swap(a[i],a[min_local]);
    }
}

int main()
{
    int n;
    cout<<"Size: "; cin>>n;
    int a[n];

    for(int i = 0; i<n ; i++)
    {
        cin>>a[i];
    }

    select_sort(n,a);

    cout<<"result: ";
    for(int i = 0; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
}