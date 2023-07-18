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
//int Search(int a[], int n, int X)
//{
//	int i = 0;
//	while(i < n && a[i] != X)
//		i++;
//	if(i < n)
//		return i;		// x trong danh sách a, và nằm ở vị trí i.
//	return -1;		// không tìm thấy X trong danh sách a.
//}
//
//void InsertionSort(int a[], int n)
//{
//     int x, i, j;
//for(int i = 1; i < n; i++)
//{
//	x = a[i];		// biến x lưu giá trị a[i]
//     j = i - 1;
//	while(0 <= j && x < a[j])
//	{
//		a[j + 1] = a[j];
//		j--;
//	}
//	a[j+1] = x;
//}
//}
//void swap(int &a, int &b)
//{
//     	int  c; 	
//	c=a;	
//	a=b;
//	b=c;
//}
//void SelectionSort(int a[], int n)
//{
//     int  min_pos, i, j;
//for(i=0; i<n-1; i++)
//{
//	min_pos= i;
//	for (j=i+1;j<n;j++)
//		if (a[j]<a[min_pos])
//			min_pos=j; //min_pos là vị trí chứa giá trị hiện tại nhỏ nhất
//	swap(a[min_pos], a[i]);
//}
//}
//void InterchangeSort(int a[], int n)
//{
//for (int i = 0; i < n - 1; i++)
//	for (int j = i + 1;j < n; j++)
//		if (a[i] > a[j])
//			swap(a[i], a[j]); // đổi chỗ a[i] và a[j]
//}
//void BubbleSort(int a[], int n)
//{
//for(int i=0; i<n-1; i++)
//	for(int j=n-1;j>i; j--)
//		if(a[j-1] >a[j]) // xét điều kiện phần tử sau nhỏ hơn phần tử trước
//			swap(a[j],a[j-1]); // hoán vị a[j] với a[j-1]
//		
//}
//void QuickSort(int a[], int left, int right)
//{
//	int x = a[(left+right)/2];
//	int i = left;
//	int j = right;
//	while(i < j) 
//	{
//	        while(a[i] < x) i++;
//	        while(a[j] > x) j--;
//        if(i <= j){
//		swap(a[i], a[j]);
//		i++; j--;
//		}
//	}
//	if(left < j)
//	        QuickSort(a, left, j);
//	if(i < right)
//	        QuickSort(a, i, right);
//}
//void shift(int a[], int i, int n)
//{
//	int j = 2*i+1;
//	if (j >= n)	// nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
//		return;
//	if (j+1 < n)        // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
//		if ( a[j]<a[j+1] )	// nếu vị trí j không tồn tại phần tử a[j] < a[j+1]
//			j++;
//
//	if (a[i] >= a[j] ) 
//		return;
//	else {
//		int x = a[i];
//		a[i] = a[j];
//		a[j] = x;
//		shift(a, j, n);
//	}
//}
//void HeapSort(int a[], int n)
//{
//	int i = n/2;
//	while (i >= 0)	// tạo Heap ban đầu
//	{	
//		shift(a, i, n-1);	i--;	
//	}
//	int right = n-1;	// right là vị trí cuối Heap đang xét
//	while (right > 0)
//	{	
//		swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
//		right --;	// giới hạn lại phần tử cuối đang xét
//		if (right > 0)	// Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
//			shift(a, 0, right);	// tạo Heap lại tại vị trí 0
//	}
//
//}
//int BinarySearch(int a[], int n, int x)
//{
//	int left = 0, right = n - 1, mid;
//	while(left <= right)
//	{
//		mid = (left+right)/2;
//		if(a[mid] == x) return mid;
//		if(x > a[mid]) left = mid+1;
//		else right = mid-1;
//	}
//	return -1;	// không tìm thấy X trong danh sách a.
//}
//
//int main()
//{
//int a[MAX];
//	int chon, k,n;
//	do {
//		system("cls");
//		cout << "MENU\n"
//			<< "1. Nhap phan tu vao danh sach\n"
//			<< "2. Xuat cac phan tu trong danh sach.\n"
//			<< "3. Sap xep danh sach bang InsertionSort.\n"
//			<< "4. Sap xep danh sach bang SelectionSort.\n"
//			<< "5. Sap xep danh sach bang InterchangeSort.\n"
//			<< "6. Sap xep danh sach bang BubbleSort.\n"
//			<< "7. Sap xep danh sach bang QuickSort.\n"
//			<< "8. Sap xep danh sach bang HeapSort.\n"
//			<< "9. Tim kiem phan tu bang tim kiem tuan tu.\n"
//			<< "10. Tim kiem phan tu bang tim kiem nhi phan.\n"
//			<< "11. Thoat.\nBan chon: ";
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
//				cout <<"Sap xep danh sach bang InsertionSort"<<endl;
//				InsertionSort(a,n);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//				break;
//		case 4:
//				cout << "Sap xep danh sach bang SelectionSort"<<endl;
//				SelectionSort(a,n);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//				break;
//		case 5:
//				cout <<"Sap xep danh sach bang InterchangeSort"<<endl;
//				InterchangeSort(a,n);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//				break;
//		case 6:
//				cout << "Sap xep danh sach bang BubbleSort "<<endl;
//				BubbleSort(a,n);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//			break;
//		case 7:
//				cout << "Sap xep danh sach bang QuickSort "<<endl;
//				QuickSort(a,0,n-1);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//			break;
//		case 8:
//				cout << "Sap xep danh sach bang HeapSort "<<endl;
//				HeapSort(a,n);
//				cout <<"Sap xep thanh cong vui long chon 2 de xem" <<endl;
//			break;
//		case 9:
//				cout << "Nhap phan tu can tim"<<endl;
//				cin >>k;
//				cout <<" Phan tu o vi tri "<<Search(a,n,k);
//			break;
//		case 10:
//				cout <<"Nhap phan tu can tim"<<endl;
//				cin >>k;
//				cout <<" Phan tu o vi tri "<<BinarySearch(a,n,k);
//			break;
//			default:
//			cout << "Ban chon thoat.\n";
//		}
//		system("pause");
//	}while (chon >= 1 && chon <= 10);
//	return 0;
//}
