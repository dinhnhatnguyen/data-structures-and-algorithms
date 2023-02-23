#include <iostream>
using namespace std;

void max (int n, int a[])
{
    int max = a[0];
    for(int i=0 ; i<n ; i++)
    {
        if(max<a[i]) max = a[i];
    }
}

void dao(int n , int a[])
{
    for(int i = 0 ; i<n/2 ; i++)
    {
        swap(a[i],a[n-i-1]);
    }
}

int doi_xung(int n, int a[])
{
    for(int i = 0 ; i<n/2 ; i++)
    {
        if(a[i]!=a[n-i-1])
             return 0;
    }

    return 1;
}

int nd(int n, int a[])
{
    int count = 0;
    for(int i = 0 ; i<n-1 ; i++)
        for(int j=i+1 ;j<n; j++ )
        {
            if(i<j&&a[i]>a[j])
            {
                count++;
            }
        }
    
    return count;
}

int dem_so(int n , int a[], int x)
{
    int c = 0;
    for(int i = 0 ; i<n-1 ; i++)
        for(int j = i+1 ; j<n ; j++)
        {
            if(a[i]+a[j]==x) c++;
        }

    return c;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    cout<<doi_xung(n, a);
    // int x; cin>>x;
    // cout<<dem_so(n,a,x);
    // dao(n , a);
    // for(int i=0 ; i<n ; i++)
    // {
    //     cout<<a[i];
    // }
    

}