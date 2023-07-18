//#include <iostream>
//using namespace std;
//# define MAX 100
//void input (int a[], int n)
//{
//for (int i=0; i<n; i++)
//{
//cout<<"nhap a["<<i<<"] = ";
//cin>>a[i];
// }
//}
//void output (int a[], int n)
//{
//for (int i=0; i<n; i++)
//cout<<a[i]<<endl;
//}
//int search (int a[], int n, int x)
//{
//	int i = 0;      
//while ( (i<n) && (a[i] != x) )
//	i++;
//if (i==n)
//	return -1; // tìm không thấy x trong danh sách, return -1
//return i; // tìm thấy x trong danh sách, return i là vị trí tìm thấy x
//}
//
//int Delete(int a[], int &n, int i)
//{
//	if (i>=0 && i < n)
//	{
//	for (int j=i; j<n-1; j++)
//		a[j] = a[j+1];
//	n--;
//	return 1;
//}
//return 0;
//}
//void search1 (int a[], int &n, int x)
//{
//	int i = 0;      
//while ( (i<n) && (a[i] != x) )
//	i++;
//if (i==n)
//	cout << " Khong tim thay phan tu";
//else 
//{cout << "Da tim thay va xoa phan tu" << Delete(a,n,i)<<endl;
//}
//}
//void Insert_last( int a[], int &n, int val)
//{
//	int pos =n;
//	 for(int i = n; i > pos; i--){
//        a[i] = a[i-1];
//    }
//		  a[pos] = val;
//		   ++n;
//}
//void delete_last( int a[], int &n)
//{
//		--n;
//}
//int main()
//{
//int a[MAX];
//	int chon, k,n;
//	do {
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Nhap phan tu vao danh sach\n"
//			<< "2. Xuat cac phan tu trong danh sach.\n"
//			<< "3. Tim 1 phan tu trong danh sach.\n"
//			<< "4. Them 1 phan tu vao cuoi danh sach.\n"
//			<< "5. Xoa 1 phan tu cuoi danh sach.\n"
//			<< "6. Xoa 1 phan tu tai vi tri i.\n"
//			<< "7. Tim 1 phan tu trong danh sach va xoa phan tu do.\n"
//			<< "8. Thoat.\nBan chon: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			cout << "Nhap so phan tu co trong danh sach.\n";
//			cin >>n;
//			input(a,n);
//			break;
//		case 2:	
//				cout <<" Xuat cac phan tu trong danh sach"<<endl;
//				output(a,n);
//				break;
//		case 3:
//				cout <<"Nhap phan tu can tim"<<endl;
//				cin >> k;
//				search(a,n,k);
//				break;
//		case 4:
//				cout << "Nhap phan tu them vao cuoi danh sach: "<<endl;
//				cin >> k;
//				Insert_last(a,n,k);
//				cout <<"Them vao cuoi danh sach thanh cong! Vui long chon 2 de xem.\n";
//				break;
//		case 5:
//				cout <<"Xoa phan tu cuoi danh sach"<<endl;
//				delete_last(a,n);
//				cout << "Xoa thanh cong! Vui long chon 2 de xem!\n";
//				break;
//		case 6:
//				cout << "Nhap vi tri can xoa: "<<endl;
//				cin >> k;
//				Delete(a,n,k);
//				cout <<"Xoa thanh cong! Vui long chon 2 de xem.\n";
//			break;
//		case 7:
//				cout <<"Nhap phan tu muon tim va xoa"<<endl;
//				cin >>k;
//				search1(a,n,k);
//				cout << "Xoa thanh cong! Vui long chon 2 de xem!\n";
//			break;
//			default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 7);
//	return 0;
//}
