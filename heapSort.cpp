#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
  
// Đẩy một phần tử xuống vun đống tại nút i
void pushdown(int arr[], int n, int i) {
    int largest = i;  // Khởi tạo largest là nút đang xét
    int left = 2 * i + 1;  // Lấy chỉ số của nút con trái
    int right = 2 * i + 2;  // Lấy chỉ số của nút con phải
  
    // Nếu nút con trái lớn hơn nút đang xét
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    // Nếu nút con phải lớn hơn nút đang xét
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    // Nếu largest không phải là nút đang xét
    if (largest != i) {
        swap(arr[i], arr[largest]);
  
        // Đệ quy đẩy phần tử xuống vun đống
        pushdown(arr, n, largest);
    }
}
  
// Hàm heapSort để sắp xếp mảng
void heapSort(int arr[], int n) {
    // Xây dựng vun đống (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        pushdown(arr, n, i);
  
    // Trích xuất từng phần tử từ vun đống
    for (int i = n - 1; i >= 0; i--) {
        // Di chuyển phần tử đầu tiên đến cuối cùng
        swap(arr[0], arr[i]);
  
        // gọi hàm pushdown trên vun đống đã được giảm kích thước
        pushdown(arr, i, 0);
    }
}
  
// Hàm main
int main() {
    int arr[] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
}



/*
đoạn này là code của thầy :v
*/


// void pushDown(int a[], int first, int n)
// {
//     int r = first;
//     while (r<=(n-1)/2)
//     {
//         if(r==(n-1)/2&&a[r]<a[2*r+1])
//         {
//             swap(a[r],a[2*r+1]);
//             break;
//         }

//         if(a[2*r+1]<a[2*r+2]&&a[2*r+2]>a[r])
//         {
//             swap(a[r],a[2*r+2]);
//             r=2*r+2;
//         }

//         if(a[2*r+1]>a[2*r+2]&&a[2*r+1]>a[r])
//         {
//             swap(a[2*r+1],a[r]);
//             r=2*r+1;
//         }

//         else break;
//     }
    
// }


// void heapSort(int a[], int n)
// {
//     for(int i=(n-1)/2;i>=0;i--)
//     {
//         pushDown(a,i,n);
//     }

//     for(int i= n-1 ; i>0 ; i--)
//     {
//         swap(a[0],a[i]);
//         pushDown(a,0,i-1);
//     }
// }


