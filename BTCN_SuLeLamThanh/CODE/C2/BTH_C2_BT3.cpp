//#include <iostream>
//using namespace std;
//#define MAX 100
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void Init()
//	{
//		
//		first = NULL;
//	}
//void Process_list()
//	{
//			Node *p;
//	p = first;
//	while (p!=NULL)
//	{
//		
//		cout<<p -> info<<endl;
//		p=p->link;
//	}
//}
//Node * Search (int x)
//{
//	Node *p= first;
//	while ( (p!=NULL) && (p->info != x) )
//		p=p->link;
//	return p;
//}
//void Insert_last(int x)
//{
//      Node *p;
//      p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (first == NULL) //không có phần tử cuối cùng
//		first = p;
//	else
//	{
//	Node *q = first;
//	while (q-> link!= NULL)
//		 q = q->link;
//		q->link = p;
//	}
//}
//void Insert_first(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = first;	
//	first = p;
//}
//
//int Delete_last()
//{
//	if (first != NULL)
//	{
//		Node *p, * q;
//		p = first; q = NULL;
//		if (p!=NULL)
//			while (p->link !=NULL)
//			{
//				q=p; p=p->link;
//			}
//		if (p!=first) // p là đầu thì không tồn tại q;
//			q->link = NULL;
//		else   first =  NULL;
//		delete p;
//		 return 1;
//	}return 0;
//}
//int SearchAndDelete(int x)
//{
//	if(first != NULL)
//	{
//		Node *p,*q;
//		p= first;
//		q= first;
//		while (p->info != x && p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if(p != first && p->link != NULL)
//		{
//			if(p->link != NULL)
//				q->link = p->link;
//			else
//				q->link = NULL;
//		delete p;
//		return 1;
//	}
//	else if (p == first)
//	{
//		first = p->link;
//		delete p;
//		return 1;
//	}
//	else if (p->link == NULL && p->info == x)
//	{
//		q->link = NULL;
//		delete p;
//		return 1;
//	}
//	else return 0;
//	}
//	return 0;
//}
//
//Node *deleteAt(Node *l, int i)
//{
//	Node *p = l;
//	for (int k = 0; i < i-1; k++){
//		p = p->link;
//	}
//	Node *temp = p->link;
//	p->link = p->link->link;
//	delete(temp);
//	return l;
//}
//void Delete_first()
//{
//	if (first != NULL) // danh sách khác rỗng
//	{
//		Node *p = first;
//		first = first->link;
//		delete p;
//	}
//	
//}
//int main()
//{
//bool in = false;
//	int chon, k;
//	do {
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Khoi tao danh sach rong\n"
//			<< "2. Xuat cac phan tu trong danh sach.\n"
//			<< "3. Tim 1 phan tu trong danh sach.\n"
//			<< "4. Them 1 phan tu vao dau danh sach.\n"
//			<< "5. Xoa 1 phan tu dau danh sach.\n"
//			<< "6. Them 1 phan tu vao cuoi danh sach.\n"
//			<< "7. Xoa 1 phan tu cuoi danh sach.\n"
//			<< "8. Tim 1 phan tu trong danh sach va xoa phan tu do.\n"
//			<< "9. Thoat.\nBan chon: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			Init();
//			cout << "Khoi tao thanh cong!\n";
//			in = true;
//			break;
//		case 2:
//			if(in)	
//			{
//				cout <<" Cac phan tu trong danh sach"<<endl;
//				Process_list();}
//			else cout << " Chua khoi tao danh sach";
//				break;
//		case 3:
//			if(in)
//				{
//				cin >> k;
//				Search(k);
//				}
//			break;
//		case 4:
//			if(in)
//			{
//				cout << "Nhap gia tri can them vao danh sach: "<<endl;
//				cin >> k;
//				Insert_first(k);
//				cout <<"Them vao dau danh sach thanh cong! Vui long chon 2 de xem.\n";
//			}
//			else
//				cout << "Ban chua khoi tao danh sach.\n";
//			break;
//		case 5:
//			if (in)
//			{
//				Delete_first();
//				cout << "Xoa thanh cong! Vui long chon 2 de xem!\n";
//			}
//			else
//				cout << "Ban chua khoi tao danh sach.\n";
//			break;
//		case 6:
//			if(in)
//			{
//				cout << "Nhap gia tri can them vao danh sach: "<<endl;
//				cin >> k;
//				Insert_last(k);
//				cout <<"Them vao cuoi danh sach thanh cong! Vui long chon 2 de xem.\n";
//			}
//			else
//				cout << "Ban chua khoi tao danh sach.\n";
//			break;
//		case 7:
//			if (in)
//			{
//				Delete_last();
//				cout << "Xoa thanh cong! Vui long chon 2 de xem!\n";
//			}
//			else
//				cout << "Ban chua khoi tao danh sach.\n";
//			break;
//		case 8:
//			if (in)
//			{
//				cout <<"Nhap phan tu muon tim va xoa"<<endl;
//				cin >>k;
//				cout << SearchAndDelete(k);
//				cout << "Xoa thanh cong! Vui long chon 2 de xem!\n";
//			}
//			else
//				cout << "Ban chua khoi tao danh sach.\n";
//			break;
//
//		default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 8);
//	return 0;
//}
