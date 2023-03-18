#include <iostream>
#include <set>
using namespace std;
struct node{
	int x ;
	node *next;
};
struct List{
	node *head;
	node *end;
	
};
void khoitao(List &l) {
	l.end=l.head=NULL;
	
}
node *taonode(int x){
	node *p= new node;
	p->x=x;
	p->next=NULL;
	return p;
}
void chendau(List &l,node *q ){
	if(l.head==NULL)
		l.head=l.end=q;
	else {
		q->next=l.head;
		l.head=q;
		
		
	}
	
	
}
void chencuoi(List &l, node *q){ // chen cuoi
	if(l.head==NULL){
		l.head=l.end= q;
	}
	else {
		l.end->next=q;
		l.end=q;
	}
}
int sluong(List l,int x){ // so luong nut < x 
	int dem =0;
	for( node *q = l.head;q!=NULL;q=q->next){
		if(q->x < x )
			dem++;
	}
	return dem;
	
}
//  int demnut_deQuy(node * p, int x)
//     {
//         if(p==NULL) return 0;
//         if (p->x<x)
//         {
//             return i+demnut_deQuy(p->next,x);
//         }
// 		return demnut_deQuy(p->next,x)
        
//     }
void sapxep(List l ){ // sap xep node 
	for(node *q = l.head ; q!=NULL;q=q->next)
		for(node *k = q->next;k!=NULL;k=k->next)
			{
				if(q->x  > k->x)
					{
					int  a= q->x;
						q->x=k->x;
						k->x=a;
				}
			}
	
	
	
}
int lonnhat(List l){          // gia tri lon nhat 
	int max= l.head->x;
	for(node *q= l.head;q!=NULL;q=q->next){
		if(q->x > max)
			max = q->x;
	}
	return max;
	
	
}
void xoacuoi(List &l)
{	// xoa cuoi danh sach 
	node *p;
	for(node *k = l.head; k != NULL; k = k ->next)
	{
		if(k == l.end)
		{
			l.end = p;
			l.end ->next = NULL;
			delete k;
			return;
		}
		p = k;
	}
}
List taof3(List l1,List l2 ){ // hop 2 ds
	set<int> a;
	for(node *q = l1.head;q!=NULL;q=q->next){
		a.insert(q->x);
	}
	
	for(node *q = l2.head; q!=NULL;q=q->next)
		a.insert(q->x);
	List z; 
	khoitao(z);
	for(auto x : a){
		node * q = taonode(x);
		chencuoi(z,q);
		
		
		
	}
	return z;
}
List taof4(List l1,List l2){ // giao 2 ds
	List h;
	khoitao(h);
	for(node *q = l1.head;q!=NULL;q=q->next)
		for(node *k =l2.head;k!=NULL;k=k->next)
			{
				if(q->x == k->x)
					{	int b = q->x;  
						node *q = taonode(b);
						chencuoi(h,q);
					}
			}
	return h;
	
	
}
void timkiem(List l , int x){ 
	int b =0; // tim kiem node khong sap xep 
	for(node *q=l.head;q!=NULL;q=q->next)
		if(q->x==x )
			cout<<"tim thay" <<endl;
			b =1;
	if(b==0)
		cout<<"NULL";
	
	
	
	
}

void chennutx(List &l, int x ){
	node *q = taonode(x); // chen nut x dam bao tang dan 
	if(x < l.head->x)
		chendau(l,q);
	if(x > l.end->x)
		chencuoi(l,q);
	else {
		node *k = l.head;
		for( node *k = l.head;k!=NULL;k=k->next )
			{	node *z = k->next;
				if(z->x > x)
					{
					k->next = q ;
					q->next = z ; 
					break;
						}	
			}
		}
}
void xoadau(List &l){
	node *q = l.head;
	node *k = l.head->next;
	l.head= k;
	delete q ;
	
	
	
}
void xoax(List &l, int x){
	if(l.head->x== x )
		xoadau(l);
	if(l.end->x == x )
		xoacuoi(l);
	else {
		node * k = new node ;
		
		for(node *q = l.head;q!=NULL;q=q->next)
			{
				
				if(q->x==x)
					{
					k->next  = q->next;
					delete k ; 
					
						
						
					}
				k=q;
				
			}
		
		
	}
	
	
}



List saochep(List l){
	int a[100];
	int i =0;
	for(node *q = l.head;q!=NULL;q=q->next){
		a[i]=q->x;
		i++;
		
	}
	for(int j =0;j<i;j++){
	
	 	node *q = taonode(a[j]);
		chencuoi(l,q);
	
	}
	return l;
}
void shownguoc(List l){
 	 
 	 int a[100];
 	 int i =0;
	 for(node *q=l.head;q!=NULL;q=q->next){
 		{
 			a[i] = q->x;
 			i++;
 			
		 }
 		
 		
 		
	 }
	for(int j =i ;0<j;j--)
		cout<< a[j]<<" ";
	
	
	
}
void show(List l){
	for(node *q= l.head;q!=NULL;q=q->next)
		cout << q->x<<" ";
	
}


void chen(node *&p , int x)
{
	if(p==NULL||p->x>x)
	chendau(p,x);
	else chen(p->next,x);
}

void xoanut(node *&p , int x)
{
	if(p==NULL) return;
	if(p->x==x){
		xoadau(p);
		return
	}
	else xoanut(p->next,x);
}
int main(){
	List l,b;
	khoitao(l);
	khoitao(b);
	int n ;
	cin >> n;
	for(int i =0;i<n;i++)
		{	int a;
			cin >> a;
			
			
			node *q= taonode(a);
			chencuoi(l,q);
		}
	for (int i =0  ; i<n;i++)
		{
			int a ;
			cin >> a;
			node * k = taonode(a);
			chencuoi(b,k);
		}
	// hop hai list
	List h = taof3(l,b);
	show(h);
	cout<<"================="<<endl;
	//int b;
	//cin >> b;
	//cout<<sluong(l,b);
	
	// giao hai list
	List k = taof4(l,b);
	show(k);
//	sapxep(l);
	//int x ;
	//cin >> x;
//	chennutx(l,x);
	
	//xoax(l,x);
	
	//show(l);
	
	
}