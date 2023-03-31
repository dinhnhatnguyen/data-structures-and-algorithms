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
    for(int i = 1; i<n;i++) // chạy từ 1 đến n (n-1 bước)
    {
        int key = a[i];
        int j = i-1;

        while(key < a[j] && j >=0) // duyệt ngược lại từ vị trí i-1 đến vị trí 0
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// void buble_sort(int a[], int n)
// {
//     for(int i =0  ; i< n-1 ; i++)
//         for(int j = i+1 ; j<n ; j++)
//         {
//             if(a[i]>a[j]) swap(a[i],a[j]);
//         }
// }


void buble_sort(int a[], int n)
{
    for(int i =0  ; i< n-1 ; i++)
        for(int j = n-1 ; j>=i+1 ; j--)
        {
            if(a[j]<a[j-1]) swap(a[j-1],a[j]);
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