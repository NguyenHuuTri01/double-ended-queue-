#include<stdio.h>
#include<stdlib.h>
struct Node{
	int Data;
	Node *Next, *Prev;
};
typedef Node* List;
void insert(int x, List &F, List &L) {
	List p = new(Node);
	p->Data = x;
	p->Next = p->Prev = NULL;
	if(F == NULL) {
		F=L=p;
	} else {
		p->Next = F;
		F->Prev = p;
		F=p;
	}
}
void insertLast(int x, List &F, List &L) {
	List p = new(Node);
	p->Data = x;
	p->Prev = p->Next = NULL;
	if(L == NULL) {
		L = F = p;
	} else {
		p->Prev = L;
		L->Next = p;
		L = p;
	}
}
void listFormF(List F) {
	printf("\n-----Duyet danh sach tu dau-----");
	List p = F;
	while(p != NULL){
		printf("\n\t-Gia tri: %d",p->Data );
		p = p->Next ;
	}
}
void listFormL(List L) {
	printf("\n-----Duyet danh sach tu cuoi-----");
	List p = L;
	while(p != NULL){
		printf("\n\t-Gia tri: %d",p->Data );
		p = p->Prev ;
	}
}
void deleteLast(List &F, List &L){
	List p = L;
	if(F == L){
		F=L=NULL;
	} else {
		L=p->Prev ;
		L->Next = NULL;
	}
	delete(p);
}
void deleteFirst(List &F, List &L){
	List p = L;
	if(F == L){
		F=L=NULL;
	} else {
		F=F->Next ;
		F->Prev = NULL;
	}
	delete(p);
}
void deleteMid(List p, List &F, List &L){
	if(F == L){
		F=L=NULL;
	} else {
		p->Prev->Next = p->Next;
		p->Next->Prev = p->Prev;
	}
	delete(p);
}
void listTang(int &n, List &F, List &L)
// sap xep list tang dan cac gia tri
{
	int x, chan=0, le=0;
	printf("Moi Ban Nhap So N:");
	scanf("%d",&n);
	printf("Gia Tri Thu 1 :");
	scanf("%d",&x);
	chan=x;
	le=x;
	insert(x,F,L);
	for(int i=1 ; i<n ; i++){
		printf("Gia Tri Thu %d :", i+1);
		while(1){
			scanf("%d",&x);
			if(x%2 == 0 && x<chan && x<le){
				insert(x,F,L);
				chan = x;
				break;
			} else if(x%2 == 0 && (x<chan || x<le)){
				printf("\nMoi Nhap Lai : ");
			} else if(x%2!=0 && x>le){
				insertLast(x,F,L);
				le = x;
				break;
			} else {
				printf("\nMoi Nhap Lai: ");
			}
		}
	}
}

int chenK(int k, List &F, List &L)
// chen K de khong anh huong den tinh tang dan cua list
{
	printf("\nNhap k can chen vao list: ");
	scanf("%d",&k);
	List p = new(Node);
	List t = L;
	List s = F;
	List tam;
	p->Data = k;
	p->Next =p->Prev = NULL;
	if(p->Data >= t->Data){
		insertLast(p->Data , F, L);
		return 0;
	}
	if(p->Data <= s->Data ){
		insert(p->Data , F, L);
		return 0;
	}
	while(s != NULL){
		if(s->Data >= k) {
			tam = s->Prev;
			tam->Next = p;
			p->Next = s;
			p->Prev = tam;
			s->Next = p;
			tam->Next = p;
		}
		s = s->Next ;
	}
}

void xoaK(int k, List &F, List &L){
	printf("\nNhap phan tu can xoa : ");
	scanf("%d",&k);
	List p = new(Node);
	p->Data = k;
	p->Prev = p->Next = NULL;
	deleteMid(p,F,L);
}
void listGiamDan(int n, List &F, List &L){
	List tmp1 = F;
	List tmp2 = L;
	List tmp;
	for(int i = 0 ; i<n/2 ; i++){
		tmp = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp;
		tmp1->Next ;
		tmp2->Prev ;
	}
	tmp = F;
	F=L;
	L=tmp;
	listFormF(F);
}
int menu(){
	int x;
	printf("\n----------MENU----------\n");
	printf("1.Nhap Danh Sach\n");
	printf("2.Xuat Danh Sach Lien Ket Tu F\n");
	printf("3.Xuat Danh Sach Lien Ket Tu L\n");
	printf("4.Chen K Vao Danh Sach Lien Ket\n");
	printf("5.Xoa Phan Tu Bang K Ra Khoi Danh Sach Lien Ket\n");
	printf("6.Xoa Phan Tu 0 Cuoi Ra Khoi Danh Sach Lien Ket\n");
	printf("7.Xoa Phan Tu 0 Dau Ra Khoi Danh Sach Lien Ket\n");
	printf("8.Sap Xep Lai Danh Sach Lien Ket Giam Dan\n");
	printf("\tMoi Nhap Chuc Nang: ");
	scanf("%d",&x);
	return x;
}

main(){
	List F,L;
	int n,k,x,h;
	F = L = NULL;
	do{
		x = menu();
		system("cls");
		switch(x) {
			case 1 : listTang(n,F,L); break;
			case 2 : listFormF(F); break;
			case 3 : listFormL(L); break;
			case 4 : chenK(k,F,L); break;
			case 5 : xoaK(h,F,L); break;
			case 6 : deleteLast(F,L); break;
			case 7 : deleteFirst(F,L); break;
			case 8 : listGiamDan(n,F,L);
		}
	} while(true);
}


