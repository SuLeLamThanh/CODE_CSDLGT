#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100

void input(int a[],int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"nhap a["<<i<<"] = ";
		cin>>a[i];
	 }
}
void output (int a[], int n)
{
	for (int i=0; i<n; i++)
		cout<<a[i]<<endl;
}
void them(int a[],int &n)
{
	int x,vt;
	do {
		cout << "Nhap vi tri can them: ";
		cin >> vt;
		if(vt < 0 && vt > n)
			cout << "Vi tri nay khong ton tai. Nhap lai" << endl;
	} while(vt < 0 && vt > n);
	cout << "Nhap gia tri can them: ";
	cin >> x;
	if(vt>=0 && vt<=n)
	{
		for(int i=n; i>vt; i--)
			a[i] = a[i-1]; 
		a[vt]=x; 
		n++;	
	}
	else
		cout << "Vi tri khong hop le" << endl;
}
int search(int a[],int n,int x)/*Do phuc tap: O(n)*/
{
	int i = 0;	while(i < n && a[i] != x)	{		i++;	}	if(i < n)	{		return i;		}	return -1;	
}
int BinarySearch(int a[], int n, int x) /*Do phuc tap: O(log n)*/{	int left = 0, right = n - 1, mid;	while(left <= right)	{		mid = (left+right)/2;		if(a[mid] == x) 			return mid;		if(x > a[mid]) 			left = mid+1;		else 			right = mid-1;	}	return -1;	
}
void xoa(int a[], int &n, int i)
{
	if (i>=0 && i < n)
	{
	for (int j=i; j<n-1; j++)
		a[j] = a[j+1];
	n--;
	}
}
int main()
{
	int a[MAX];
	int n,choose;
	bool in = false;
	do {
		system("cls");
		cout << "DANH SACH\n1. Nhap cac phan tu\n2. Them mot phan tu\n3. Xuat cac phan tu\n4. Tim kiem mot phan tu (phuong phap tuan tu)\n5. Tim kiem mot phan tu (phuong phap nhi phan)\n6. Tim kiem phan tu va xoa\n7. Thoat\nBan chon: ";
		cin >> choose;
		switch (choose)
		{
			case 1:
				do {
					cout << "Nhap so phan tu trong danh sach: ";
					cin >> n;
					if (n < 0 || n > 100)
						cout << "So phan tu trong danh sach khong thoa!. Nhap lai";
				} while (n < 0 || n > 100);
				input(a,n);
				in = true;
				break;
			case 2:
				if (in)
				{
					them(a,n);
					cout << "Them thanh cong. Chon 3 de xem" << endl;
				}
				else
					cout << "Chua nhap phan tu" << endl;
				break;
			case 3:
				if (in)
				{
					cout << "Cac phan tu co la: " << endl;
					output(a,n);
				}
				else
					cout << "Chua nhap phan tu" << endl;
				break;
			case 4:
				if (in)
				{
					int x;
					cout << "Phan tu can tim: ";
					cin >> x;
					int k = search(a,n,x);
					if (k < 0)
						cout << x << " khong co trong danh sach" << endl;
					else
						cout << x << " duoc tim thay o vi tri thu " << k+1 << endl;
				}
				else
					cout << "Chua nhap phan tu" << endl;
				break;
			case 5:
				if (in)
				{
					int x;
					cout << "Phan tu can tim: ";
					cin >> x;
					int k = BinarySearch(a,n,x);
					if (k < 0)
						cout << x << " khong co trong danh sach" << endl;
					else
						cout << x << " duoc tim thay o vi tri thu " << k+1 << endl;
				}
				else
					cout << "Chua nhap phan tu" << endl;
				break;
			case 6:
				if (in)
				{
					int x;
					cout << "Nhap phan tu can tim kiem va xoa: ";
					cin >> x;
					int  k = search(a,n,x);
					if (k < 0)
						cout << x << " khong co trong danh sach" << endl;
					else
					{
						cout << x << " duoc tim thay o vi tri thu " << k+1 << " va xoa thanh cong. Nhap 3 de xem ket qua!" << endl;
						xoa(a,n,k);
					}
				}
				else
					cout << "Chua nhap phan tu" << endl;
				break;
			default:
				cout << "Ban chon thoat" << endl;
				break;
		}
		_getch();
	} while(choose >= 1 && choose <= 6);
}