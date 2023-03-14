#include <iostream>

using namespace std;

// Định nghĩa lớp Node
class Node {
public:
    int data;
    Node* next;
};

// Định nghĩa lớp LinkedList
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    // Phương thức thêm nút vào đầu danh sách liên kết
    void addFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Phương thức thêm nút vào cuối danh sách liên kết
    void addLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Phương thức in danh sách liên kết
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int count(int x)
    {
        int count  = 0;
        for(Node * p = head ; p!=NULL ; p->next)
        {
            if(p->data < x )
            {
                count+=1;
            }
        } 

        return count;
    }

    // Phương thức xoá nút đầu tiên trong danh sách liên kết
    void deleteFirst() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Phương thức xoá nút cuối cùng trong danh sách liên kết
    void deleteLast() {
        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        delete current->next;
        current->next = NULL;
    }

    // Phương thức xoá nút ở vị trí n trong danh sách liên kết
    void deleteAt(int n) {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        if (n == 0) {
            head = current->next;
            delete current;
            return;
        }

        for (int i = 0; current != NULL && i < n - 1; i++) {
            current = current->next;
        }

        if (current == NULL || current->next == NULL) {
            return;
        }

        Node* next = current->next->next;
        delete current->next;
        current->next = next;
    }

    // Phương thức tìm phần tử có giá trị lớn nhất trong danh sách liên k
    int getMaxValue() {
        if (head == NULL) {
            return 0;
        }

        int maxVal = head->data;
        Node* current = head->next;
        while (current != NULL) {
            if (current->data > maxVal) {
                maxVal = current->data;
            }
            current = current->next;
        }

        return maxVal;
    }

    Node * (int x)
    {
        for(Node *p = head ; p!=NULL ; p->next)
        {
            if(p->data==x)
            {
                return p;
            }
        }

        return NULL;
    }
    // Phương thức sắp xếp các nút tăng dần trong danh sách liên kết
    void sortList() {
        Node* current = head;
        Node* index = NULL;
        int temp;

        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;

                while (index != NULL) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};

int main()
{
    LinkedList a;
    int n;
    cout<<"n= "; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        a.addLast(val);
    }
    cout<<"Danh sách liên kết: "; a.printList();
}