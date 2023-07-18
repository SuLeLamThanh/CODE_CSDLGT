//#include <iostream>
//using namespace std;
//const int M = 20;
//struct Node
//{
//	int data;
//	Node *next;
//};
//Node *first[M];
//Node *sp;
//Node *front, *rear;
//void InitStack()
//{
//	sp = NULL;
//}
//int isEmptyS()
//{
//	if(sp == NULL)
//		return 1;
//	return 0;
//}
//void PushS(int x)
//{
//	Node *p = new Node;
//	p->data = x;
//	p->next = sp;
//	sp = p;
//}
//int PopS(int &x)
//{
//	if(sp != NULL)
//	{
//		Node *p = sp;
//		x = p->data;
//		sp = p->next;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void InitQueue()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmptyQ()
//{
//	if(front == NULL)
//		return 1;
//	return 0;
//}
//void PushQ(int x)
//{
//	Node * p = new Node;
//	p->data = x;
//	p->next = NULL;
//	if(rear == NULL)
//		front = p;
//	else
//		rear->next = p;
//	rear = p;
//}
//int PopQ(int &x)
//{
//	if(front != NULL)
//	{
//		Node *p = front;
//		front = p->next;
//		x = p->data;
//		if(front ==NULL)
//		{
//			rear = NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//int n;
//void init()
//{
//	for(int i = 0; i < n; i++)
//	{
//		first[i] = NULL;
//	}
//}
//void insert(Node*&f, int x)// them dau ds lien ket
//{
//	Node*p = new Node;
//	p->data = x;
//	p->next = f;
//	f = p;
//}
//void nhapall()
//{
//	int d,k,x;// dinh dang xet,sluog dinh ke, cac dinh ke se nhap
//	cout << "Nhap so dinh cua do thi n: ";
//	cin >> n;
//	init();
//	for(int i = 0; i < n; i++)
//	{
//		cout << "Nhap vao dinh thu " << i + 1 << ": ";
//		cin >> d;
//		insert(first[i],d);
//		cout << "Nhap vao so dinh ke cua " << i + 1 <<": ";
//		cin >> k;
//		for(int j = 0; j < k; j++)
//		{
//			cin >> x;
//			insert(first[i],x);
//		}
//
//
//	}
//}
//void outputds(Node *f)
//{
//	
//	if(f != NULL)
//	{
//		Node *p = f;
//		while(p !=  NULL)
//		{
//			cout << p->data << " ";
//			p = p->next;
//		}
//	}
//}
//void xuatall()
//{
//	if(n > 0)
//	{
//		for(int i = 0; i < n; i++)
//		{
//			cout << "Danh sach dinh thu " << i + 1 << ": ";
//			outputds(first[i]);
//			cout << endl;
//		}
//	}
//	else
//		cout << "Rong";
//}
//int c[100], bfs[100];
//int nbfs = 0;
//void Initc()
//{
//	for(int i = 0; i < n; i++) // n la so dinh cua do thi
//		c[i] = 1;
//}
//void BFS(int v) // v la dinh bat dau
//{
//	int p;
//	Node *w;
//	PushQ(v);
//	c[v] = 0;
//	while(front != NULL)
//	{
//		PopQ(p);
//		bfs[nbfs] = p;
//		w = first[p];
//		nbfs++;
//		while(w != NULL)
//		{
//			if(c[w->data])
//			{
//				PushQ(w->data);
//				c[w->data] = 0;
//			}
//			w = w->next;
//		}
//	}
//}
//void outputbfs()
//{
//	for (int i = 0; i < nbfs; i++)
//		cout << bfs[i] << "\t";
//}
//// Cau 5.4: Duyet do thi theo DFS
//int dfs[100];
//int ndfs = 0;
//void DFS(int s)
//{
//	PushS(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	c[s] = 0;
//	int u = s;
//	Node *v = NULL;
//	while(isEmptyS() == 0)
//	{
//		if(v == NULL)
//			PopS(u);
//		v = first[u];
//		while(v != NULL)
//		{
//			if(c[v->data] == 1)
//			{
//				PushS(u);
//				PushS(v->data);
//				dfs[ndfs] = v->data;
//				ndfs++;
//				c[v->data] = 0;
//				u = v->data;
//				break;
//			}
//			v = v->next;
//		}
//	}
//}
//void outputdfs()
//{
//	for(int i = 0; i < ndfs; i++)
//		cout << dfs[i] << "  ";
//}
//// Cau 4.5: Dung BFS tim x tren do thi
//void Search_by_BFS(int x, int v) // v la dinh bat dau
//{
//	int p;
//	Node *w;
//	PushQ(v);
//	c[v] = 0;
//	while(front != NULL)
//	{
//		PopQ(p);
//		if(x == p)
//		{
//			cout << "Tim thay x = " << x << endl;
//			return;
//		}
//		w = first[p];
//		while(w != NULL)
//		{
//			if(c[w->data] == 1)
//			{
//				PushQ(w->data);
//				c[w->data] = 0;
//			}
//			w = w->next;
//		}
//	}
//	cout << "Khong tim thay " << x << endl;
//}
//
//int main()
//{
//	int chon, x;
//	do{
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Nhap danh sach ke cua do thi\n"
//			<< "2. Xuat danh sach ke cua do thi\n"
//			<< "3. Duyet BFS\n"
//			<< "4. Duyet DFS\n"
//			<< "5. Kiem tra x co ton tai khong\n"
//			<< "6. Thoat\nBan chon: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			nhapall();
//			break;
//		case 2:
//			xuatall();
//			break;
//		case 3:
//			InitQueue();
//			Initc();
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			nbfs = 0;
//			BFS(x);
//			cout << "Thu tu dinh sau khi duyet BFS: ";
//			outputbfs();
//			break;
//		case 4:
//			InitQueue();
//			Initc();
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			ndfs = 0;
//			DFS(x);
//			cout << "Thu tu dinh sau khi duyet DFS: ";
//			outputdfs();
//			break;
//		case 5:
//			InitQueue();
//			Initc();
//			nbfs = 0;
//			cout << "Vui long nhap gia tri x can tim: ";
//			cin >> x;
//			Search_by_BFS(x, 0);
//			break;
//		default:
//			cout << "Ban chon thoat\n";
//		}
//		system("pause");
//	} while(chon >= 1 && chon <= 5);
//	return 0;
//}
