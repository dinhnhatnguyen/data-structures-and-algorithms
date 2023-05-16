#include <iostream>
using namespace std;
void insert(int a[], int n)
{
    for(int i=0;i<n;i++ )
    {
        cin>>a[i];
    }
}

/* SẮP XẾP CHÈN 
    Ý tưởng:

        Chọn lần lượt từng phần tử trong mảng và chèn nó vào đúng vị trí 
        của nó trong mảng đã sắp xếp trước đó. Thuật toán hoạt động bằng cách so sánh từng phần tử 
        trong mảng với những phần tử đứng trước nó và đổi chỗ nếu phần tử trước đó lớn hơn nó, cho 
        đến khi phần tử đó đã đứng ở đúng vị trí.
    Ví dụ: a [12, 2, 8, 5, 1, 6, 4, 15]

        1. Lần lượt chọn các phần tử từ trái sang phải.
        2. Với phần tử đầu tiên (12), ta sẽ cho nó giữ nguyên vì không có phần tử nào đứng trước nó.
        3. Với phần tử thứ hai (2), ta sẽ so sánh với phần tử đứng trước nó (12) và đổi chỗ vị trí của hai phần tử này. Mảng hiện tại trở thành [2, 12, 8, 5, 1, 6, 4, 15].
        4. Với phần tử thứ ba (8), ta sẽ so sánh với phần tử đứng trước nó (12) và thấy rằng không cần đổi chỗ. Sau đó, ta sẽ so sánh với phần tử đứng trước nó (2) và đổi chỗ với phần tử đó. Mảng hiện tại trở thành [2, 8, 12, 5, 1, 6, 4, 15].
        5. Tiếp tục quá trình cho đến hết mảng, thu được mảng đã được sắp xếp [1, 2, 4, 5, 6, 8, 12, 15].
*/
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