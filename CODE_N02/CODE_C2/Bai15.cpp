#include <iostream>
#include <conio.h>
using namespace std;
const int MAXSIZE = 150;

void nhap(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}
void xuat(int a[],int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
void timGiao(int a[], int b[], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i] == b[j])
				cout << a[i] <<"\t";
}
void timBuA(int a[], int b[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		bool check = true;
		for (int j = 0; j < m; j++)
			if (a[i] == b[j])
				check = false;
		if (check == true)
			cout << a[i] << "  ";
	}
}
void timBuB(int a[], int b[], int n, int m)
{
	for (int i = 0; i < m ;i++)
	{
		bool check = true;
		for (int j = 0; j < n; j++)
			if (b[i] == a[j])
				check = false;
		if (check == true)
			cout << b[i] << "  ";
	}
}
int main()
{
	int a[MAXSIZE], b[MAXSIZE];
	int n,m,chon;
	bool in = false;
	do{
		system("cls");
		cout << "MENU\n"
			<< "1. Nhap tap hop.\n"
			<< "2. Xuat tap hop.\n"
			<< "3. Xuat phan giao hai tap hop.\n"
			<< "4. Xuat phan bu hai tap hop.\n"
			<< "5.Thoat\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Nhap so luong phan tu tap hop A: ";
			cin >> n;
			nhap(a,n);
			cout << "Nhap so luong phan tu tap hop B: ";
			cin >> m;
			nhap(b,m);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Tap hop A: ";
				xuat(a,n);
				cout << endl;
				cout << "Tap hop B: ";
				xuat(b,m);
				cout << endl;
			}
			else
				cout << "Ban chua nhap. Chon 1 de nhap.\n";
			break;
		case 3:
			cout << "A: ";
			xuat(a,n);
			cout << endl;
			cout << "B: ";
			xuat(b,m);
			cout << endl;
			cout << "Giao cua hai tap hop la: ";
			timGiao(a,b,n,m);
			break;
		case 4:
			cout << "Phan bu cua A: ";
			timBuA(a,b,n,m);
			cout << endl;
			cout << "Phan bu cua B: ";
			timBuB(a,b,n,m);
			cout << endl;
			break;
		default:
			cout << "Ban chon thoat!\n";
		}
		_getch();
	}while (chon >= 1 && chon <= 4);
	return 0;
}