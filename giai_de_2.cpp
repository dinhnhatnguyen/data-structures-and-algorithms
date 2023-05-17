#include <iostream>
using namespace std;



/*
        GIẢI ĐỀ 2022
*/


/*
    CÂU 1
*/


void dem(int a[], int n)
{
    int b[n];
    for(int i =0 ; i<n ; i++)
    {
        int dem = 0 ;
        for(int j = i+1; j<n; j++)
        {
            if(a[i]>a[j]) dem++;
        } 
        b[i] = dem;
    }

    for(int i = 0 ; i<n ; i++)
    {
        cout<<b[i]<<" ";
    }
}

/*
        CÂU 2
*/

typedef char St25[25]; typedef char St8[8];

struct NutM
{
    int maM;
    NutM *Tiep;
};

struct NutGV
{
    St8 maGV;
    St25 HoTenGV;
    NutGV *Down;
    NutM *DSM;
};

NutGV *FistT;

NutGV *Addr(NutGV *FistT , St8 BMaGV)
{
    for(NutGV *p = FistT ; p!= NULL ; p = p->Down) // duyệt danh sách giáo viên 
    {
        if(p->maGV==BMaGV) return p; // tìm được thì trả về địa chỉ
    }

    return NULL; // kết thúc vòng lặp không tìm được nên return NULL
}

void ListOfTeacher(NutGV *FirstT , int BMaM)
{
    for(NutGV *p = FistT ; p!= NULL ; p = p->Down)
    {
        bool flag = false;
        for(NutM * q = p->DSM ; q!= NULL ; q =q->Tiep) //duyệt danh sách môn của mỗi giáo viên đêt tìm kiếm
        {
            if(q->maM == BMaM) flag = true;
        }

        if(flag) cout<<p->HoTenGV<<" "<<p->maGV<<endl;
    }
}


/*
        CÂU 3
*/

struct Nut
{
    int infor;
    Nut *Left , *Right;
};

Nut *T;

Nut* khoiTao(int n)
{
    Nut *T = new Nut();
    T->infor = n;
    T->Left = NULL;
    T->Right= NULL;
    return T;
}

int SoNutLa(Nut *T)
{
    if(T==NULL) return 0;
    if(T->Left==NULL&&T->Right==NULL) return 1;

    int L = SoNutLa(T->Left);
    int R = SoNutLa(T->Right);

    return L+R;
}




void chuyen_du_lieu(Nut *T , int a[], int &index) // chuyển dữ liệu trong cây nhị phân vào lưu trong mảng
{
    if(T==NULL) return;
    chuyen_du_lieu(T->Left,a);
    a[index]= T->infor;
    index++;
    chuyen_du_lieu(T->Right);

}

void * Them_nut(Nut *T, int n) // thêm 1 nút vào cây nhị phân tìm kiếm
{
    if(T==NULL)
    {
       T = khoiTao(n);
    }
    
    if(T->infor>n) T->Left = Them_nut(T->Left,n);
    else if(T->infor<n) T->Right = Them_nut(T->Right,n);
}


/* HÀM CHUYỂN ĐỔI
    
    Ý tưởng:
        B1: chuyển dữ liệu của cây muốn chuyển đổi lưu vào 1 mảng
        B2: duyệt mảng và thêm lại dữ liệu vào cây nhị phân tìm kiếm
*/
Nut *ChuyenDoi(Nut *T)
{
    if(T==NULL)  return NULL;
    int n = SoNutLa(T);// lấy số phần tử của mảng
    int a[n];
    int index = 0;

    Nut *newT = NULL; 

    chuyen_du_lieu(T,a,index);// chuyển dữ liệu của cây muốn chuyển vào lưu vào mảng

    for(int i = 0; i<n ; i++)
    {
        Them_nut(newT,a[i]); // duyệt mảng và đưa từng phần tử của mảng vào cây nhị phân tìm kiếm
    }

    return newT;
}


/* 
    CÂU 4
*/


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


/*
    MINH HOẠ THUẬT TOÁN  thôi lười lắm ngang nớ được rồi háy :3
*/



