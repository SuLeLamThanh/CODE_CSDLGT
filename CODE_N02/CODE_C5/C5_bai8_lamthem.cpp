#include <iostream>// nguyen huy tu,bt 8
#include <conio.h>
#include <fstream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*front;
Node*rear;
Node*sp;

const int M = 20;
int a[M][M];
int n;// số luopngwr đỉnh vertical của đồ thị
int C[100];// luu 1 là chưa xét, 0 là đã xét
int bfs[100];// mảng lưu những phần tử đã xét
int nbfs=0;// chỉ số của mảng bfs khi lưu
int dfs[100];
int ndfs = 0;

void docdothi()
{
	ifstream indata;
	indata.open("do_thi_1.txt");
	if(indata.is_open())
	{
		for(int i = 0; i < 14; i++)
		{
			for(int j = 0; j < 14; j++)
				indata >> a[i][j];
		}
		indata.close();
	}
	else
		cout << "khong co file nay";
}
void xuatmatran()
{
	
		for(int i = 0; i < 14; i++)
		{
			for(int j = 0; j < 14; j++)
				cout << " " << a[i][j];
			cout << endl;
		}
}
void initQueue()
{
	front = NULL;
		rear = NULL;
}
void initStack()
{
	sp = NULL;
}
void pushQ(int x)
{
	Node*p =new Node;
	p-> data = x;
	p->next =NULL;
	// xet TH queue rỗng
	if(rear == NULL)
		front = p;// là phần từ duy nhất có thể lấy ra từ front
	else
		rear->next =p;// thêm vào rear mà
	rear = p;// cập nhật rear mới

}
int popQ(int &x)
{
	if(front == NULL)
		return 0;
	else
	{
		Node*p = front;
		x = p -> data;
		front = front-> next;
		// kiểm tra nếu đã lấy 1 phần tử cuối thì
		if(front ==NULL)
			rear = NULL;// front và rear chỉ chung	1 chỗ

		delete p;
		return 1;
	}
}
void init()
{
	n=0;
}
void input()
{
	cout << "nhap vao so dinh cua do thi n:";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "nhap vao dong thu" << i+1 << ":";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];

	}
}
void output()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void khoitaodinhchuaxet()
{
	for (int i = 0; i <n; i++)
	{
		C[i] = 1;// 1 laf chua xet,
	}
}
void BFS(int v)// đỉnh đầu tiên
{

	int w,p; // w là từng chỉ số đỉnh để tý duyệt đến n đỉnh
	//p là lấy từ trong queue ra từ đầu front
	pushQ(v);
	C[v] = 0;// tức đỉnh đã xét
	while(front!= NULL)
	{
		popQ(p);// lấy p ra;
		bfs[nbfs] = p; // lấy trong queue vô mảng bfs coi như đã duyệt xog
		nbfs++;
		for(w = 0; w < n; w++)
		{
			if(C[w]&& a[p][w] == 1)//tức là tìm tất cả các đỉnh của
			// đồ thị. xem đỉnh nào hiện tại chưa đc xét, và vừa phải kề với đỉnh trc đó
			{
				pushQ(w);
				C[w] = 0;// chuyển  đỉnh này sang đã xét

			}
		}
	}
}
void xuatbfs()
{
	for (int i = 0; i < nbfs; i++)
	{
		cout << bfs[i] << " ";
	}
}
void pushS(int x)
{
	Node*p = new Node;
	p->data = x;
	p->next = sp;
	sp = p;// cập nhật đỉnh của stack
}
int popS(int&x)
{
	// đối với stack thì thêm hay lấy cũng phải là ở đầu
	if(sp != NULL)
	{
		Node*p = sp;
		x = p->data;
		sp = p->next;
		delete p;
		return 1;

	}
	return 0;
}
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v= -1, u = s;
	while(sp!=NULL)
	{
		if(v == n)
			popS(u);
		for(v = 0; v < n; v++)
			if(a[u][v] != 0&& C[v] ==1)
			{
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u =v;
				break;
			}

	}
}
void xuatdfs()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << dfs[i] << " ";
	}
}
bool searchByBFS(int x, int v)
{
	int w, p;
	pushQ(v);// v laf dinh bat dau
	C[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		if(x == p)
		{
			return true;
		}
		for(w = 0; w < n; w++)
		{
			if(C[w] && a[w][p] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
		}
	}	
	return false;
}

int main()
{
	bool in=false;
	int x,chon,v;
	do{
		system("cls");
		cout << "MENU\n1.docdothi\n2.xuatBFS\n3.xuatDFS\n4.timkiem\n5.thoat\n6.chon:";
		cin >> chon;
		switch(chon)
		{
		case 1:
			
				docdothi();
				in= true;
			break;
		case 2:
			if(in)
			{
				initQueue();
				n= 14;
				khoitaodinhchuaxet();
				cout << "chon dinh bat dau:";
				cin >> v;
				BFS(v);
				xuatbfs();
			}
			else
				cout << "vui long doc do thi trc!!\n";
			break;
		case 3:
			if(in)
			{
				n= 14;
				initStack();
				khoitaodinhchuaxet();
				cout << "chon dinh bat dau:";
				cin >> v;
				DFS(v);
				xuatdfs();
			}
			else
				cout << "vui long doc do thi trc!!\n";
			break;
		case 4:
			if(in)
			{
				n = 14;
				khoitaodinhchuaxet();
				initQueue();
				cout << "nhap vao gia tri tim: ";
				cin >> x;
				cout << "bat dau tu dinh nao: ";
				cin >> v;
				bool on = searchByBFS(x,v);
				if(on == true)
					cout << "ton tai";
				else
					cout << "khong ton tai " << x << "trog do thi\n";
			}
			else
				cout << "vui long doc do thi trc!!\n";
			break;
		default:
			cout << "ban chon thoat";
			break;
		}
		_getch();
	}while(chon >= 1 && chon <= 4);

}