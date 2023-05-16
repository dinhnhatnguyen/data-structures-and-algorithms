#include <iostream>
using namespace std;

/*
DANH SÁCH LIÊN KẾT
*/

struct nut
{
    int so;
    nut *tiep;

    nut()
    {
        tiep = NULL;
    }
};

nut *newnode(int n)
{
    nut *p = new nut();
    p->so= n;
    p->tiep=NULL;
    return p;
}


// void themvaodau(nut *L, int n)
// {
//     nut *p = newnode(n);
//     p->tiep= L;
//     L = p;
// }

void themvaodau(nut *&L, int n)
{
    nut *p = newnode(n);
    p->tiep = L;
    L = p;
}




void themvaosau(nut *L, int n)
{
    nut *q = newnode(n);
    nut *p;
    for (p = L; p->tiep != NULL; p = p->tiep)
        ;
    p->tiep = q;
    q->tiep = NULL;
}

int kiemtra(nut *L)
{
    for(nut *p = L ; p!=NULL ; p =p->tiep)
    {
        if(p->so>p->tiep->so) return 0;
    }
    return 1;
}


// nut *Giao_2_ds(nut* l1, nut*l2)  Cách 1
// {
//     nut *l3 = NULL;

//     for(nut *p = l1 ; p!=NULL ; p= p->tiep)
//         for(nut *q= l2; q!=NULL; q = q->tiep )
//         {
//             if(p->so==q->so) themvaosau(l3,p->so);
//         }
//     return l3;
// }

nut *Giao_2_ds(nut *l1, nut *l2) // cách 2
{
    nut *l3 = NULL;
    nut *p = l1;
    nut *q = l2;

    while (p != NULL && q != NULL)
    {
        if (p->so < q->so)
        {
            p = p->tiep;
        }
        else if (p->so > q->so)
        {
            q = q->tiep;
        }
        else // p->so == q->so
        {
            themvaosau(l3, p->so);
            p = p->tiep;
            q = q->tiep;
        }
    }

    return l3;
}


nut *copy(nut *l , nut* G)
{
     for(nut *p = l ; p!=NULL ; p= p->tiep)
    {
        themvaosau(G,p->so);
    }

    return G;
}


nut *Hop_2_ds(nut * l1 , nut *l2)
{

    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    nut *l3 = NULL;
    for(nut *p = l1 ; p!=NULL ; p= p->tiep)
    {
        themvaosau(l3,p->so);
    }

    for(nut *p = l2 ; p!=NULL ; p= p->tiep)
    {
        for(nut *q= l3; q!=NULL; q = q->tiep )
        {
            if(p->so!=q->so) themvaosau(l3,p->so);
        }
    }

    return l3;
}


/*
    Sắp xếp lựa chọn

    Ý tưởng
        1. Duyệt qua từng vị trí của mảng từ vị trí đầu đến vị trí cuối.
        2. Tại mỗi vị trí, tìm phần tử nhỏ nhất (hoặc lớn nhất) trong đoạn chưa được sắp xếp từ vị trí hiện tại đến cuối mảng.
        3. Hoán đổi phần tử nhỏ nhất (hoặc lớn nhất) với phần tử ở vị trí hiện tại.
        4. Tiếp tục tìm kiếm và hoán đổi cho đến khi hoàn thành duyệt qua tất cả các vị trí.

    Ví dụ: a[12, 2, 8, 5, 1, 6, 4, 15]
        Bước 1: Tại vị trí đầu tiên (index 0), tìm phần tử nhỏ nhất trong đoạn chưa được sắp xếp (từ index 0 đến index 7). Phần tử nhỏ nhất là 1.

        Bước 2: Hoán đổi phần tử nhỏ nhất (1) với phần tử ở vị trí hiện tại (12). Mảng sau bước này: [1, 2, 8, 5, 12, 6, 4, 15].

        Bước 3: Tại vị trí thứ hai (index 1), tìm phần tử nhỏ nhất trong đoạn chưa được sắp xếp (từ index 1 đến index 7). Phần tử nhỏ nhất là 2.

        Bước 4: Hoán đổi phần tử nhỏ nhất (2) với phần tử ở vị trí hiện tại (2). Mảng sau bước này: [1, 2, 8, 5, 12, 6, 4, 15].

        Bước 5: Tiếp tục các bước tương tự cho các vị trí còn lại.

        Bước 6: Kết quả cuối cùng là mảng đã được sắp xếp: [1, 2, 4, 5, 6, 8, 12, 15].

*/

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
    nut *list1 = NULL;
    nut *list2 = NULL;

    // Add elements to list1
    themvaodau(list1, 5);
    themvaodau(list1, 3);
    themvaodau(list1, 1);

    // Add elements to list2
    themvaodau(list2, 6);
    themvaodau(list2, 4);
    themvaodau(list2, 2);

    cout << "List 1: ";
    for (nut *p = list1; p != NULL; p = p->tiep)
        cout << p->so << " ";
    cout << endl;

    cout << "List 2: ";
    for (nut *p = list2; p != NULL; p = p->tiep)
        cout << p->so << " ";
    cout << endl;

    nut *intersection = Giao_2_ds(list1, list2);
    cout << "Intersection: ";
    for (nut *p = intersection; p != NULL; p = p->tiep)
        cout << p->so << " ";
    cout << endl;

    nut *unionList = Hop_2_ds(list1, list2);
    cout << "Union: ";
    for (nut *p = unionList; p != NULL; p = p->tiep)
        cout << p->so << " ";
    cout << endl;

    return 0;
}


/*
CÂY NHỊ PHÂN
*/

// struct Nut
// {
//     int infor;
//     Nut *Left;
//     Nut *Right;
// };


// Nut *init(int data)
// {
//     Nut* New_node = new Nut();
//    New_node->infor =data;
//    New_node->Left = nullptr;
//    New_node->Right = NULL;
//    return New_node;
// }

// Nut* insert(Nut *r , int n)
// {
//     if(r==NULL)
//     {
//         r = init(n);
//     }
//     else
//     {
//         if(n<=r->infor)
//         {
//             r->Left = insert(r->Left,n);
//         }
//         else
//         {
//             r->Right = insert(r->Right,n);
//         }
//     }

//     return r;
// }

// int Min(Nut *r)
// {
//     int m = r->infor;
//     int L = Min(r->Left);
//     int R =Min(r->Right);
//     return min(r->infor,min(L,R));
// }

// int Cap(Nut *T)
// {
//     if(T==NULL||T->Left==NULL&&T->Right==NULL) return 0;
//     else
//     {
//         int left = Cap(T->Left);
//         int right = Cap(T->Right);
//         return max(left,right)+1;
//     }
    
// }
