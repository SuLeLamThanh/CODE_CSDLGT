//c2_ bai 16
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
struct list
{
	Node *head;
};
void init(list &l)
{
	l.head = NULL;
}
void Insert_last(int x, list &l)
{
    Node *p;
    p = new Node;
	p->info = x;
	p->link = NULL;
	if (l.head == NULL) 
		l.head = p;
	else
	{
		Node *q = l.head;
		while (q-> link!= NULL)
			 q = q->link;
			q->link = p;
	}
}
void giao(list l1, list l2)
{
	int dem = 0;
	Node *p = l1.head;
	Node *q = l2.head;
	while(p != NULL)
	{
		while(q != NULL)
		{
			if(p ->info == q ->info)
			{
				dem++;
				if(dem == 1)
					cout << "Cac phan tu giao nhau: ";
				cout << p ->info << "\t";
			}
			q = q ->link;
		}
		p = p ->link;
	}
	if(dem == 0)
		cout << "Khong co phan tu giao\n";
	cout << endl;
}
void bu(list l1, list l2)
{
	int dem = 0;
	Node *p = l1.head;
	Node *q = l2.head;
	while(p != NULL)
	{
		while(q != NULL)
		{
			if(p ->info != q ->info)
			{
				dem++;
				if(dem == 1)
					cout << "Cac phan tu bu nhau: ";
				cout << p ->info << "\t";
			}
			q = q ->link;
		}
		p = p ->link;
	}
	if(dem == 0)
		cout << "Khong co phan tu bu\n";
	cout << endl;
}
int main()
{
	int n, m, x;
	list l1, l2;
	init(l1);
	init(l2);
	//nhap ds1
	do{
		cout << "Nhap so luong phan tu cho ds thu nhat: ";
		cin >> n;
		if(n <= 0)
			cout << "Vui long nhap so nguyen duong khac 0\n";
	}while(n <= 0);
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		Insert_last(x,l1);
	}
	//nhapds2
	do{
		cout << "Nhap so luong phan tu cho ds thu nhat: ";
		cin >> m;
		if(m <= 0)
			cout << "Vui long nhap so nguyen duong khac 0\n";
	}while(m <= 0);
	for(int i = 0; i < m; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		Insert_last(x,l2);
	}
	giao(l1,l2);
	bu(l1,l2);
	bu(l2,l1);
	return 0;
}