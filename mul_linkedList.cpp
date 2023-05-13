#include <iostream>
#include <cstring>

using namespace std;

struct Hocsinh
{
    int MaHs;
    string HoTen;
    string NgaySinh;
    Hocsinh *Next;
};

struct Lop
{
  Lop *Down;
  string TenLop;
  Hocsinh *DSHS;
};


Hocsinh* create_student(int mahs , string hoten , string ngaysinh)
{
    Hocsinh* new_student = new Hocsinh();
    new_student->MaHs = mahs;
    new_student->HoTen = hoten;
    new_student->NgaySinh = ngaysinh;
    new_student->Next = NULL;
    return new_student;
}

Lop* create_class(string tenlop)
{
    Lop* new_class = new Lop();
    new_class->TenLop = tenlop;
    new_class->Down = NULL;
    new_class->DSHS = NULL;
    return new_class;
}

struct DSLH
{
    Lop * F;
    DSLH()
    {
        this->F=NULL;
    }

    void add_class(string tenlop)
    {
        Lop* new_class = create_class(tenlop);
        if(F==NULL)
        {
            F = new_class;
        }
        else
        {
            Lop *p = F;
            while (p->Down!=NULL)
            {
                p = p->Down;
            }
            p->Down = new_class;
        }
    }

    Lop* diaChi_lop(string tenLop)
    {
        for(Lop * p = F ; p!=NULL; p=p->Down)
        {
            if (p->TenLop == tenLop)
            {
                return p;
            }
        }

        return NULL;
    }

    void add_student( string TenLop ,int mahs , string hoten , string ngaysinh)
    {
        Lop *p = diaChi_lop(TenLop);

        if(p==NULL) cout<<"Khong ton tai lop "<<TenLop<<endl;
        else
        {
            Hocsinh* new_student = create_student(mahs,hoten,ngaysinh);
            new_student->Next = p->DSHS;
            p->DSHS = new_student;
        }
    }

    void add_student_end_of_list( string TenLop ,int mahs , string hoten , string ngaysinh)
    {
        Lop *p = diaChi_lop(TenLop);
        Hocsinh *q;

        if(p==NULL) cout<<"Khong ton tai lop "<<TenLop<<endl;
        else
        {
            Hocsinh* new_student = create_student(mahs,hoten,ngaysinh);
            for(q = p->DSHS; q!=NULL ; q=q->Next);
            q = new_student;
            new_student->Next = NULL;
        }
    }

    void inDSHS(string tenlop)
    {
        Lop *p = diaChi_lop(tenlop);
        int i = 1;

        if(p==NULL) cout<<"Khong ton tai lop "<<tenlop<<endl;

        else
        {
            for(Hocsinh *q = p->DSHS; q!=NULL ; q=q->Next  )
            {
                cout<<endl;
                cout<<i<<" "<<q->MaHs<<" "<<q->HoTen<<" "<<q->NgaySinh<<endl;
                i+=1;
            }
        }
    }

    int SiSo(string tenlop)
    {
        Lop *p = diaChi_lop(tenlop);
        int count = 0;
        if(p==NULL) cout<<"Khong ton tai lop "<<tenlop<<endl;


        else
        {
            for(Hocsinh *q = p->DSHS; q!=NULL ; q=q->Next  )
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    // Create an instance of the class managing the list of classes
    DSLH ds;

    // Add classes to the list
    ds.add_class("ClassA");
    ds.add_class("ClassB");

    // Add students to classes
    ds.add_student("ClassA", 1, "John Doe", "2000-01-01");
    ds.add_student("ClassA", 2, "Jane Smith", "2001-02-03");
    ds.add_student("ClassB", 3, "Alice Johnson", "1999-05-12");

    // Print the list of students in a class
    cout << "Students in ClassA:" << endl;
    ds.inDSHS("ClassA");

    // Get the number of students in a class
    int size = ds.SiSo("ClassA");
    cout << "ClassA size: " << size << endl;

    return 0;
}



