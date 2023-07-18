//#include<iostream>
//#include<fstream>
//#include<string>
//#define MAX 20
//using namespace std;
//int a[MAX][MAX];
//int n = 0;
//int b[MAX][MAX];
//int E1[MAX];
//int E2[MAX];
//int wE[MAX];
//int nE = 0;
//int T1[MAX];
//int T2[MAX];
//int wT[MAX];
//int nT = 0;
//void khoiTao()
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			a[i][j] = 0;
//}
//void input()
//{
//	ifstream File;
//	string tenFile;
//	cin.ignore();
//	cout << "Nhap ten file (luu y nhap ca '.txt') : ";
//	getline(cin, tenFile);
//	File.open(tenFile, ios::in);
//	if (File.is_open())
//	{
//		File >> n;
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				File >> a[i][j];
//
//		cout << "Luu thanh cong. Chon xuat de xem\n";
//		File.close();
//	}
//	else
//		cout << "Khong the mo file.\n";
//}
//void output()
//{
//	cout << "Do thi dang luu tru:\n";
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << a[i][j] << "\t";
//		cout << endl;
//	}
//}
//int TonTai(int d, int D[], int nD)
//{
//	for (int i = 0; i < nD; i++)
//		if(D[i] == d)
//			return 1;
//	return 0;
//}
//void taoE()
//{
//	for(int i = 0; i < n; i++)
//		for(int j = 0; j < n; j++)
//			if(a[i][j] != 0)
//			{
//				E1[nE] = i; 
//				E2[nE] = j;
//				wE[nE] = a[i][j];
//				a[i][j] = 0;
//				a[j][i] = 0;
//				nE++;
//			}
//}
//void SapXepE()
//{
//	for(int i = 0; i < nE-1; i++)
//		for(int j = i+1; j < nE; j++)
//			if(wE[i] > wE[j])
//			{
//				swap(wE[i],wE[j]);
//				swap(E1[i],E1[j]);
//				swap(E2[i],E2[j]);
//			}
//}
//void kruskal()
//{
//	for(int i=0;i<nE;i++)
//	{
//		if(TonTai(E1[i], T1, nT) == 1  && TonTai(E2[i], T1, nT) == 1)
//			continue;
//		if(TonTai(E1[i], T2, nT) == 1  && TonTai(E2[i], T2, nT) == 1)
//			continue;
//		T1[nT] = E1[i];
//		T2[nT] = E2[i]; 
//		wT[nT] = wE[i]; 
//		nT++;
//		if(nT == n - 1)
//			break;
//	}
//}
//void output1()
//{
//	int tong = 0;
//
//	for (int i = 0; i < nT; i++)
//	{
//		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
//		tong += wT[i];
//	}
//	cout << "\nTong = " << tong << endl;
//}
//void XoaViTriE(int i)
//{
//	for (int j = i; j < nE; j++)
//	{
//		E1[j] = E1[j + 1];
//		E2[j] = E2[j + 1];
//		wE[j] = wE[j + 1];
//	}
//	nE--;
//}
//void XoaCanhE(int u, int v)
//{
//	bool flag = false;
//	int i = 0;
//
//	while (i < nE && !flag)
//	{
//		if (E1[i] == u && E2[i] == v)
//		{
//			XoaViTriE(i);
//			flag = true;
//		}
//		i++;
//	}
//}
//void prim(int s)
//{
//	int u = s, min, i, d1, d2;
//	bool flag = false;
//
//    while (nT < n - 1)
//    {
//        for (int v = 0; v < n; v++)
//			if (a[u][v] != 0 && TonTai(v, T2, nT) == 0)
//			{
//				E1[nE] = u;
//				E2[nE] = v;
//				wE[nE] = a[u][v];
//				nE++;
//			}
//
//		i = 0;
//		flag = false;
//		while (i < nE && !flag)
//		{
//			if (TonTai(E2[i], T2, nT) == 0)
//			{
//				min = wE[i];
//				d1 = E1[i];
//				d2 = E2[i];
//				flag = true;
//    	    }
//			i++;
//		}
//
//		for (i = 0; i < nE; i++)
//      		if (TonTai(E2[i], T2, nT) == 0 && min > wE[i])
//			{
//				min = wE[i];
//				d1 = E1[i];
//				d2 = E2[i];
//			}
//
//		T1[nT] = d1;
//		T2[nT] = d2; 
//        wT[nT] = a[d1][d2]; 
//        a[d1][d2] = 0;
//		a[d2][d1] = 0;
//        nT++;
//		XoaCanhE(d1, d2);
//		u = d2;
//     }
//}
//void saochep()
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			b[i][j] = a[i][j];
//}
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void resetE()
//{
//	for (int i = 0; i < nE; i++)
//	{
//		E1[i] = 0;
//		E2[i] = 0;
//		wE[i] = 0;
//	}
//}
//void resetT()
//{
//	for (int i = 0; i < nT; i++)
//	{
//		T1[i] = 0;
//		T2[i] = 0;
//		wT[i] = 0;
//	}
//}
//
//int main()
//{
//	int s;
//	int chon;
//	bool in = false;
//
//	do {
//		system("cls");
//		cout << "-----Menu-----\n"
//			<< "1. Nhap ma tran ke\n"
//			<< "2. Xuat ma tran ke\n"
//			<< "3. Tim cay khung toi thieu bang Prim.\n"
//			<< "4. Tim cay khung toi thieu bang Kruskal.\n"
//			<< "5. Thoat\n"
//			<< "Ban chon: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			if (in)
//			{
//				khoiTao();
//				n = 0;
//
//				input();
//			}
//			else
//			{
//				input();
//				in = true;
//			}
//			break;
//		case 2:
//			if (in)
//			{
//				output();
//			}
//			else
//				cout << "Khong co du lieu\n";
//			break;
//		case 3:
//			if (in)
//			{
//				cout << "Vui long nhap dinh bat dau: ";
//				do {
//					cin >> s;
//					if (s < 1 || s > n)
//						cout << "Nhap sai. Nhap lai: ";
//				} while (s < 1 || s > n);
//
//				s--;
//				prim(s);
//				cout << "Ket qua cay khung toi thieu:\n";
//				output1();
//				resetE();
//				resetT();
//				cout << "De thuc hien cac thao tac tiep theo. Vui long chon 1 de nhap lai du lieu.\n";
//			}
//			else
//				cout << "Khog co du lieu\n";
//			break;
//		case 4:
//			if (in)
//			{
//				nE = 0;
//				nT = 0;
//				saochep();
//				taoE();
//				SapXepE();
//				kruskal();
//				cout << "Ket qua cay khung toi thieu:\n";
//				output1();
//				resetE();
//				resetT();
//				cout << "De thuc hien cac thao tac tiep theo. Vui long chon 1 de nhap lai du lieu.\n";
//			}
//			else
//				cout << "Khog co du lieu\n";
//			break;
//		default:
//			cout << "---Ket thuc chuong trinh---\n";
//		}
//		system("pause");
//	} while (chon >= 1 && chon <= 4);
//
//	return 0;
//}
