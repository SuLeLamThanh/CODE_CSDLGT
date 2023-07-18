//#include <iostream>
//using namespace std;
//#define MAX 100
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node * front, *rear; // front vị trí xóa, rear vị trí thêm
//void init()
//{
//	 front= NULL;
//	 rear= NULL;
//}
//
//void Push(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = NULL;	
//	if (rear == NULL)
//		front =p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop()
//{
//	if (front!= NULL)
//	{
//		int x;
//		Node *p = front;
//		x = p -> info;
//		front = front ->link;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;	
//}
//void xuat()
//{
//	if (!isEmpty())
//	{ 
//		Node *p = front;
//		while (p != NULL)
//		{
//			cout << p->info << "\t";
//			p = p->link;
//		}
//	}
//}
//int main()
//{
//bool in = false;
//	int chon, k;
//	do {
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Khoi tao queue rong\n"
//			<< "2. Kiem tra queue.\n"
//			<< "3. Xuat.\n"
//			<< "4. Push.\n"
//			<< "5. Pop.\n"
//			<< "6. Thoat.\nBan chon: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao thanh cong!\n";
//			in = true;
//			break;
//		case 2:
//			if (in)
//				if (isEmpty())
//					cout << "Queue rong.\n";
//				else
//					cout << "Queue khong rong.\n";
//			else
//				cout << "chua khoi tao Queue.\n";
//			break;
//		case 3:
//			if(in)
//				xuat();
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 4:
//			if(in)
//			{
//				cout << "Nhap gia tri can them vao danh sach: ";
//				cin >> k;
//				Push(k);
//				cout <<"Them vao danh sach thanh cong! Vui long chon 3 de xem.\n";
//			}
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 5:
//			if (in)
//			{
//				Pop();
//				cout << "Xoa thanh cong! Vui long chon 3 de xem!\n";
//			}
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 5);
//	return 0;
//}
