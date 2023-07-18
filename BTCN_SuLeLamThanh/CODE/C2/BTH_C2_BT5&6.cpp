//#include <iostream>
//#define MAX 100
//using namespace std;
//void init(int a[], int &sp)
//{
//	sp = -1;
//}
//int isEmpty(int a[], int sp)
//{
//	if (sp==-1)
//		return 1;
//	return 0;
//}
//
//int isFull(int a[], int sp)
//{
//	if (sp== MAX -1)
//		return 1;
//	return 0;
//}
//
//int Push(int a[], int &sp, int x)
//{
//	if (sp< MAX -1)
//	{
//		a[++sp] = x;
//		return 1; 
//	}
//	return 0;
//}
//
//int Pop(int a[], int &sp)
//{
//	if (sp!=-1) // khi stack khác rỗng
//	{
//		int x;
//		 x = a[sp--];
//		return 1;
//	}
//	return 0;
//} 
//void chuyenCoSo(int a[], int &sp,int k)
//{
//	while (k != 0)
//	{
//		int x = k % 2;
//		Push(a,sp,x);
//		k /= 2;
//	}
//}
//void xuatCS(int a[], int &sp)
//{
//	cout << "Ket qua la: ";
//	if (!isEmpty(a,sp))
//		for ( int i=0;i<=sp;i++)
//			cout << a[i] ;
//		cout << endl;
//}
//void xuat(int a[], int sp)
//{
//	if (!isEmpty(a,sp)) 
//		for ( int i=0;i<=sp;i++)
//			cout << a[i]<<"\t" ;
//		cout << endl;
//}
//int main()
//{
//int a[MAX];
//int sp; // đỉnh stack
//bool in = false;
//	int chon, k,n;
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
//			init(a,sp);
//			cout << "Khoi tao thanh cong!\n";
//			in = true;
//			break;
//		case 2:
//			if (in)
//				if (isEmpty(a,sp))
//					cout << "Stack rong.\n";
//				else
//					cout << "Stack khong rong.\n";
//			else
//				cout << "chua khoi tao stack.\n";
//			break;
//		case 3:
//			if(in)
//				xuat(a,sp);
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 4:
//			if(in)
//			{
//				cout << "Nhap gia tri can them vao danh sach: ";
//				cin >> k;
//				Push(a,sp,k);
//				cout <<"Them vao danh sach thanh cong! Vui long chon 3 de xem.\n";
//			}
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 5:
//			if (in)
//			{
//				Pop(a,sp);
//				cout << "Xoa thanh cong! Vui long chon 3 de xem!\n";
//			}
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 6:
//			init(a,sp);
//			cout << "Nhap so can chuyen doi: ";
//			cin >> n;
//			chuyenCoSo(a,sp,n);
//			xuatCS(a,sp);
//			break;
//		default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 6);
//	return 0;
//}