#include <iostream>
using namespace std;

typedef char St25[25];
typedef char St8[8];

struct HocSinh
{ int MaHS;
    St25 HoTen;
    St8 NgaySinh;
    HocSinh *Next;
};

struct Lop
{ 
    Lop *Down;
    St8 TenLop;
    HocSinh *DSHS;
};
Lop *F;

/*
    viết thêm hàm:
        tạo nút cho lớp với tạo nút cho học sinh
        thêm lớp , thêm học sinh 
*/

void ThemLop_DauDS(Lop*F,St8 Blop)
{
    // tự viết
}

HocSinh *timKiemHs(HocSinh *F , int Mahs )
{
     // tự viết
}

HocSinh BoSungHS_cuoi(HocSinh *F, int MaHS,St25 TenHS , St8 NgaySinh)
{
     // tự viết
}
HocSinh capNhat(HocSinh *p , St25 tenHS , st8 ngaySinh)
{
     // tự viết
}

void XoaHS(HocSinh *F, int BmaHS)
{
     // tự viết
}

void XoaLop(Lop F,St8 Blop)
{
     // tự viết
}
void BoSung(Lop *F , St8 Blop , int Mahs , St25 tenHS, St8 ngaySinh)
{
    Lop *k == Diachi(F,Blop);
    if(k==NULL)
    {
        ThemLop_DauDS(F,Blop);
        BoSungHS_cuoi(F->DSHS,Mahs,tenHS,ngaySinh);
    }
    else
    {
        HocSinh * p = timKiemHs(k->DSHS,Mahs);
        if(p!=NULL)//tìm kiếm hs
        {
            capNhat(p,tenHS, ngaySinh);
        }
        else
            BoSungHS_cuoi(k->DSHS,Mahs,tenHS,ngaySinh);
    }
}

void Xoa(Lop*&F, St8 Blop, int BmaHS)
{
    Lop k = Diachi(F,Blop);
    XoaHS(k.DSHS,BmaHS);
    if(k.DSHS==NULL)
    XoaLop(F,Blop);

}
Lop * Diachi(Lop * F , St8 Blop)
{
    for(Lop *p = F ; p!=NULL ; p = p->Down)
    {
        if(strcmp(p->TenLop,Blop)==0) return p;
    }

    return NULL;
}

void inDSHS(Lop *F , St8 Blop)
{
   
   Lop *k = Diachi(F,Blop);
   //duyệt danh sách hs tương ứng để in DSHS
   for(HocSinh *p = k->DSHS ; p!= NULL ; p = p->Next)
   {
        cout<<p->MaHS<<" "<<p->HoTen<<" "<<p->NgaySinh<<endl;
   } 
}

int DemSiSo(HocSinh * F)
{
    int cnt = 0;
    for  (;F!=NULL;F->Next)
    {
        cnt++;
    }

    return cnt;
    
}
int siSo(Lop * F , St8 Blop)
{
    Lop *k = Diachi(F,Blop);
    if(Blop==NULL) return 0;
   
   return DemSiSo(k->DSHS);
}

// in sĩ số các lớp
void inSiSoCacLop(Lop *F)
{
    for (Lop *p=F; p!=NULL; p->Down)
    {
        cout<<p->TenLop<<" "<<DemSiSo(p->DSHS)<<endl;
    } 
}


