//#include <iostream>
//using namespace std;
//#define MAX 100
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node * sp; //lưu trữ địa chỉ phần tử đầu tiên của Stack
//void init()
//{
//	sp = NULL;
//}
//void Push(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = sp;	
//	sp = p;
//}
//int Pop()
//{
//	if (sp!= NULL)
//	{
//		int x;
//		Node *p = sp;
//		x = p -> info;
//		sp= p ->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//bool isEmpty()
//{
//	if (sp == NULL)
//		return true;
//	return false;
//}
//void xuat()
//{
//	if (!isEmpty())
//	{ 
//		Node *p = sp;
//		while (p != NULL)
//		{
//			cout << p->info << "\t";
//			p = p->link;
//		}
//	}
//}
//void chuyenCoSo(int k)
//{
//	while (k != 0)
//	{
//		int x = k % 2;
//		Push(x);
//		k /= 2;
//	}
//}
//void xuatCS()
//{
//	cout << "Ket qua la: ";
//	if (!isEmpty())
//	{ 
//		Node *p = sp;
//		while (p != NULL)
//		{
//			cout << p->info;
//			p = p->link;
//		}
//	}
//		cout << endl;
//}
//int main()
//{
//bool in = false;
//	int chon, k, a;
//	do {
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Khoi tao stack rong\n"
//			<< "2. Kiem tra stack.\n"
//			<< "3. Xuat.\n"
//			<< "4. Push.\n"
//			<< "5. Pop.\n"
//			<< "6. Chuyen he 10 sang he 2.\n"
//			<< "7. Thoat.\nBan chon: ";
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
//					cout << "Stack rong.\n";
//				else
//					cout << "Stack khong rong.\n";
//			else
//				cout << "chua khoi tao stack.\n";
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
//		case 6:
//			init();
//			cout << "Nhap so can chuyen doi: ";
//			cin >> a;
//			chuyenCoSo(a);
//			xuatCS();
//			break;
//		default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 6);
//	return 0;
//}
