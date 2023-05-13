#include <iostream>
using namespace std;

// Hàm phân hoạch mảng

/*
    phân hoạch mảng sao cho
    nửa trái gồm các phần tử < chốt
    nửa phải gồm các phần tử >= chốt
*/
int phanHoach(int a[],int L , int R , int Chot)
{
    int trai = L;
    int phai = R;
    // Lặp cho đến khi trai >= phai
    while (trai < phai)
    {
        // Tìm phần tử đầu tiên từ trái lớn hơn Chot
        while(a[trai] < Chot) trai += 1;
        // Tìm phần tử đầu tiên từ phải nhỏ hơn hoặc bằng Chot
        while(a[phai] > Chot) phai -= 1;
        // Nếu trai <= phai, hoán đổi hai phần tử và tăng trai, giảm phai
        if(trai <= phai) {
            swap(a[trai],a[phai]);
            trai++; // đoạn ni thầy thiếu thì nhớ hỏi lại thầy :v
            phai--;
            /*
                trai++ và phai-- được sử dụng để di chuyển chỉ số trai và phai sau khi hoán đổi hai phần tử a[trai] và a[phai]
            */
        }
    }
    // Trả về chỉ số của phần tử cuối cùng nhỏ hơn hoặc bằng Chot
    return trai;
}

// Hàm đệ quy thực hiện Quick Sort trên mảng
void quickSort(int a[],int L,int R)
{
    // Điều kiện dừng: nếu L >= R, return
    if(L < R)
    {
        // Chọn phần tử giữa làm chốt
        int chot = a[(L + R) / 2];
        // Phân hoạch mảng và lấy chỉ số của phần tử cuối cùng nhỏ hơn hoặc bằng chốt
        int k = phanHoach(a,L,R,chot);
        // Đệ quy sắp xếp hai mảng con trước và sau chốt
        quickSort(a,L,k-1);
        quickSort(a,k,R);
    }
}

int main() {
    int a[] = {9, 3, 4, 2, 1, 8};
    int n = 6;
    // Thực hiện Quick Sort trên mảng a
    quickSort(a, 0, n - 1);
    
    // In mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}

