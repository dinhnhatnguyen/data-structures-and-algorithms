#include <iostream>
using namespace std;

void merge (int a[], int l , int m , int h ) // m: là chỉ số mid
{
    int i,j,k = l;
    int n1 = m - l +1;// size của mảng bên trái
    int n2 = h - m;// size của mảng bên phải
    int *L = new int[n1];//left
    int *R = new int[n2];//right
    // tách mảng
    for (i = 0 ;i < n1 ; i++)
    {
        L[i] = a[l+i]; // sao chép phần tử vào mảng trái
    }
    for( j = 0 ; j < n2 ; j++)
    {
        R[j] = a[m+j+1]; //sao chép phần tử vào mảng phải
    } 
    i=j=0;
    // gộp mảng
    while(i<n1&& j<n2)
    {
        a[k++] = (L[i] <= R[j])? L[i++] : R[j++]; // so sánh các phần tử trong mảng 
        // nếu L[i]  <= R[i] thì sao chép vào mảng a
        // nếu không đúng thì chuyển qua phần tử khác và tiếp tục so sánh
    }
    while (i<n1)
    {
        a[k++] = L[i++];
    }
    while (j<n2)
    {
        a[k++] = R[j++];
    }
    
    
}
void merge_sort(int a[], int l, int h) // l: là chỉ số nhỏ nhất trong mảng || h: là chỉ số lớn nhất trong mảng
{
    // 1. tìm phần tử middle 
    // 2. đệ quy nửa trước của mảng
    // 3. đệ quy nửa sau của mảng
    // 4. trộn hai nửa lại thảng mảng kết quả
    if(l < h)
    {
        int m = l+(h-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        merge(a,l,m,h);
    }
     
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int lenght = sizeof(a)/sizeof(int);
    for(int i =0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,lenght-1);
    for(int i = 0; i<n ;i++)
    {
        cout<<a[i]<<" ";
    }
}