
#include <iostream>
using namespace std;

// định nghĩa cấu trúc Node
struct Node {
   int data;
   Node* left;
   Node* right;

};

// hàm tạo Node mới
Node* createNode(int data) {
   Node* newNode = new Node();
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

// hàm tính chiều cao của cây nhị phân
int getHeight(Node* root) {
   if (root == NULL) {
      return 0;
   } else {
      int leftHeight = getHeight(root->left);
      int rightHeight = getHeight(root->right);
      if (leftHeight > rightHeight) {
         return (leftHeight + 1);
      } else {
         return (rightHeight + 1);
      }
   }
}

// hàm chèn Node mới vào cây nhị phân tìm kiếm
Node* insertNode(Node* root, int data) {
   if (root == NULL) {
      root = createNode(data);
   } else if (data <= root->data) {
      root->right = insertNode(root->right, data);
   } else {
      root->left = insertNode(root->left, data);
   }
   return root;
   /*
   nếu giá trị của node mới nhỏ hơn giá trị của node hiện tại, 
   ta chuyển sang cây con bên trái, ngược lại chuyển sang cây con bên phải
   */
}

// hàm xoá tất cả các nút của cây nhị phân
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

//hàm tìm giá trị nút lớn nhất trong cây nhị phân tìm kiếm
int findMax(Node* root) {
    if (root == NULL) {
        return -1; // hoặc bất kỳ giá trị thích hợp khác
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
    /*
    chỉ cần duyệt hết các nút bên phải nút cuối cùng là nút có giá trị lớn nhất
    */
}

//hàm tìm giá trị nút lớn nhất trong cây nhị phân không phải là cây nhị phân tìm kiếm
int findMax_b(Node* root) {
    int maxVal = root->data;
    if (root->left != NULL) {
        int leftMax = findMax(root->left);
        maxVal = max(maxVal, leftMax);
    }
    if (root->right != NULL) {
        int rightMax = findMax(root->right);
        maxVal = max(maxVal, rightMax);
    }
    return maxVal;
}

//Đếm số nút của cây
int countNode(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + countNode(root->left) +countNode(root->right);
}
 
//tìm nút cha
Node *findeParentNode(Node* root , Node *p)
{
    if(root==NULL || p==NULL) return NULL;
    if(root->left==p||root->right==p) return root;
    Node *tmp = findeParentNode(root->left,p);
    if(tmp!=NULL) return tmp;
    return findeParentNode(root->right,p);
}

// tìm mức của nút được trỏ bởi p thuộc cây T
int level(Node *root,Node *p)
{
    if (root == NULL || p == NULL) {
        return -1;
    }
    if (root == p) {
        return 0;
    }
    Node* parent = findeParentNode(root, p);
    if (parent == NULL) {
        return -1;
    }
    return level(root, parent) + 1;
   
}

// tìm địa chỉ của nút có giá trị = x
Node *find_Address(Node* root,int x)
{
   if(root == NULL) return NULL;
   if(root->data == x) return root;

   Node *left = find_Address(root->left,x);
   if(left != NULL) return left;
   Node *right = find_Address(root->right,x);
   if(right !=NULL) return right;
   return NULL;
}

//in giảm dần
void print_descending_value(Node *root)
{

   /*
   dùng duyệt giữa trái-gốc-phải
   */
   if(root==NULL)
   {
      return;
   }
   print_descending_value(root->right);
   cout << root->data << " ";
   print_descending_value(root->left);
}

//tạo và sao chép dữ liệu vào cây mới
Node *create_New_Tree(Node *root)
{
   if(root == NULL) return NULL;
   Node *L = createNode(root->data);
   L->left = create_New_Tree(root->left);
   L->right = create_New_Tree(root->right);
   return L;
}

//kiểm tra cây nhị phân tìm kiếm

bool isBST(Node *root)
{
   if(root == NULL) return true;
   if(root->left == NULL && right ==NULL) return true;
   if(root->left != NULL && root->right != NULL) return isBST(root->left)<=isBST(root->right);
   return false;
}

// tìm cấp của cây nhị phân
int get_height(Node *root)
{
   if(root==NULL) return 0;
   int left = getHeight(root->left);
   int right = get_height(root->right);
   return max(left,right) + 1;
}

// hàm in giá trị  của cây nhị phân theo thứ tự trước (preorder)
void printNode(Node* root) {
   if (root != NULL) {
      cout << root->data << " ";
      printNode(root->left);
      printNode(root->right);
   }
}



int main() {
   Node* root = NULL;
   root = insertNode(root, 50);
   insertNode(root, 30);
   insertNode(root, 20);
   insertNode(root, 40);
   insertNode(root, 70);
   insertNode(root, 60);
   insertNode(root, 80);


   cout<<endl;

   cout << "Duyệt cây nhị phân theo thứ tự trước: ";
   printNode(root);

   // cout << "\nChiều cao của cây nhị phân là: " << getHeight(root)<<endl;
   // cout<<"Max val = "<<findMax(root)<<endl;
   // cout<<"số nút: "<<countNode(root)<<endl;
   if(isBST(root)) cout<<"true"<<endl;
   else cout<<"false"<<endl;
}


