//#include <iostream>
//#include <cmath>
//using namespace std;
//#define MAX 100
//int front,rear;
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
//
//int Push(int a[], int &front, int &rear, int x)
//{
//	if (rear - front == MAX - 1) 
//		return 0;
//	else
//	{
//		if (front == -1) // hang đợi rỗng
//			front = 0;
//		if (rear == MAX - 1) // hang đợi bị tràn
//		{
//			for(int i = front; i<=rear; i++) 
//			// thực hiện dời tịnh tiến các phần tử trong hàng
//				a[i-front]=a[i];
//			rear = MAX -1-front;
//			//rear nhận giá trị mới, sau khi tinh tiến
//			front = 0; // front nhận giá trị mới, sau khi tịnh tiến
//		}
//		a[++rear] = x;
//		return 1;
//	}
//}
//int Pop(int a[], int &front, int &rear)
//{
//	if (front == -1) // hàng đợi rỗng
//		return 0;
//	else
//	{
//		int x;
//		x = a[front++];
//		if (front > rear) 
//		// trường hợp hang đợi có 1 phần tử, sau khi xóa hang rỗng
//		{
//			front = - 1; 
//			rear = -1; 
//		}
//		return 1;
//	}
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;	
//}
//void xuat(int a[], int front,int rear)
//{
//	if(!isEmpty())
//	{
//		for (int i=rear; i>=front; i--)
//		cout<<a[i]<<"\t"<<endl;
//}
//}
//int main()
//{
//int a[MAX];
//int front, rear;
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
//			init(a,front,rear);
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
//				xuat(a,front,rear);
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 4:
//			if(in)
//			{
//				cout << "Nhap gia tri can them vao danh sach: ";
//				cin >> k;
//				Push(a,front,rear,k);
//				cout <<"Them vao danh sach thanh cong! Vui long chon 3 de xem.\n";
//			}
//			else
//				cout << "Ban chua khoi tao stack.\n";
//			break;
//		case 5:
//			if (in)
//			{
//				Pop(a,front,rear);
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
