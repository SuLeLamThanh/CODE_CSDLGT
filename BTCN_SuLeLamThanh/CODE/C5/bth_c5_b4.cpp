//#include <iostream>
//using namespace std;
//int C[100];
//int C2[100];
//int bfs[100];
//int nbfs=0;
//#define max 20
//int
//	a[max][max];
//int n;
//int C1[100];
//int dfs[100];
//int ndfs=0;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node * front, *rear; 
//struct Stack
//{
//	int info;
//	Stack *link;
//};
//Stack * sp; 
//void init1()
//{
//	 front= NULL;
//	 rear= NULL;
//}
//void init()
//{
//	n = 0;
//}
//void init2()
//{
//	sp = NULL;
//}
//void input()
//{
//	cout << "Nhap so dinh cua do thi n: ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap vao dong thu " << i + 1 << ": ";
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//	}
//}
//void output()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << a[i][j] << "\t";
//		cout << endl;
//	}
//}
//void Push(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = NULL;	
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop(int &x)
//{
//	if (front!= NULL)
//	{
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
//void ktchuaxet()
//{
//	for (int i = 0; i < n; i++)
//		C[i] = 1;
//}
//void BFS(int v)
//{
//	int w, p;
//	ktchuaxet();
//	Push(v);
//	C[v] = 0;
//	while (front != NULL)
//	{
//		Pop(p);
//		bfs[nbfs] = p;
//		nbfs++;
//		for (w = 0; w < n; w++)
//			if(C[w] && a[p][w] == 1)
//			{
//				Push(w);
//				C[w] = 0;
//			}
//	}
//}
//void outputbfs()
//{
//	for (int i = 0; i < nbfs; i++)
//		cout << bfs[i] << "\t";
//}
//void Push1(int x)
//{
//	Stack *p;
//	p = new Stack;
//	p->info = x;
//	p->link = sp;	
//	sp = p;
//}
//int Pop1(int &x)
//{
//	if (sp != NULL)
//	{
//		Stack *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int isEmpty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//	
//}
//void ktchuaxet1()
//{
//	for (int i = 0; i < n; i++)
//		C1[i] = 1;
//}
//void DFS(int s)
//{
//	ktchuaxet1();
//    Push1(s); 
//    dfs[ndfs] = s;
//    ndfs++;
//    C1[s] = 0;
//    int v = -1, u = s;
//    while(!isEmpty())
//    {
//		if(v == n)
//			Pop1(u);
//		for(v = 0; v < n; v++)
//			if(a[u][v] != 0 && C1[v] == 1)
//			{
//				Push1(u);
//				Push1(v);
//				dfs[ndfs] = v;
//				ndfs++;
//				C1[v] = 0;
//				u = v;
//				break;
//			}
//	} // end while
//} // end DFS
//void outputdfs()
//{
//	for(int i = 0; i < ndfs; i++)
//		cout << dfs[i] << "  ";
//}
//void Search_by_BFS(int x, int v) // v là đỉnh bắt đầu
//{
//	int w, p;
//	Push(v);
//	C2[v] = 0;
//	while(front != NULL)
//	{
//		Pop(p);
//		if (x == p)
//		{
//			cout << x << " ton tai\n";
//			return;
//		}
//		for(w = 0; w < n; w++)
//			if(C2[w] && a[p][w] == 1)
//			{
//				Push(w);
//				C2[w] = 0;
//			}
//	}
//}
//
//
//int main()
//{
//	int chon, x, v, s;
//	do{
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Nhap ma tran ke cua do thi\n"
//			<< "2. Xuat ma tran ke\n"
//			<< "3. Duyet BFS\n"
//			<< "4. Duyet DFS\n"
//			<< "5. Kiem tra x co ton tai khong\n"
//			<< "6. Thoat\nBan chon: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			input();
//			break;
//		case 2:
//			cout << "Ma tran ke:\n";
//			output();
//			break;
//		case 3:
//			cout << "Nhap dinh bat dau: ";
//			cin >> x;
//			v = x - 1;
//			BFS(v);
//			outputbfs();
//			break;
//		case 4:
//			cout << "Nhap dinh bat dau: ";
//			cin >> x;
//			s = x - 1;
//			DFS(s);
//			outputdfs();
//			break;
//		case 5:
//			int gt, d;
//			cout << "Nhap gia tri can tim: ";
//			cin >> gt;
//			cout << "Nhap dinh bat dau: ";
//			cin >> d;
//			Search_by_BFS(gt,d);
//			break;
//		default:
//			cout << "Ban chon thoat\n";
//		}
//		system("pause");
//	}while(chon >= 1 && chon <= 5);
//	return 0;
//}