#include <iostream>
using namespace std;
void insert(int a[], int n)
{
    for(int i=0;i<n;i++ )
    {
        cin>>a[i];
    }
}
void insertion_sort(int a[], int n)
{
    for(int i = 1; i<n;i++)
    {
        int key = a[i];
        int j = i-1;

        while(key < a[j] && j >=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void show (int a[], int n)
{
    for(int i=0;i<n;i++ )
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    insert(a,n);
    cout<<"Before: ";
    show(a,n);
    cout<<endl;
    insertion_sort(a,n);
    cout<<"After: ";
    show(a,n);
    cout<<endl;
}