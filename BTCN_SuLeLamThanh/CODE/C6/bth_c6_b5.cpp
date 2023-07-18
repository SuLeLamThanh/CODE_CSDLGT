//#include<iostream>
//#include<fstream>
//#include<string>
//#define MAX 20
//using namespace std;
//int a[MAX][MAX];
//int n = 0;
//int E1[MAX];
//int E2[MAX];
//int wE[MAX];
//int nE = 0;
//int T1[MAX];
//int T2[MAX];
//int wT[MAX];
//int nT = 0;
//void khoiTaoMaTranRong()
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			a[i][j] = 0;
//}
//void input()
//{
//	cout << "*Lien ket : nhap Trong So w\n*Khong lien ket : 0\n";
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap trong so cho dong thu " << i + 1 << ": ";
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//	}
//
//	cout << "Luu do thi thanh cong. Chon xuat de kiem tra\n";
//}
//void inputByFile()
//{
//	ifstream dataFile;
//	string nameFile;
//	cin.ignore();
//	cout << "Nhap ten file (luu y nhap ca '.txt' : ";
//	getline(cin, nameFile);
//	dataFile.open(nameFile, ios::in);
//	if (dataFile.is_open())
//	{
//		dataFile >> n;
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				dataFile >> a[i][j];
//
//		cout << "*Luu do thi thanh cong. Chon xuat de kiem tra\n";
//		dataFile.close();
//	}
//	else
//		cout << "*Khong the mo file. Vui long kiem tra\n";
//}
//void outputMaTranKe()
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
//int tim_MinE()
//{
//	int min;
//	int temp = -1;
//	bool find = false;
//	
//	min = wE[0];
//	for (int j = 1; j < nE; j++)
//	{
//		if (!find && wE[j] != 0)
//		{
//			if (wE[j] < min)
//			{
//				min = wE[j];
//				temp = j;
//				find = true;
//			}
//		}
//
//		if (find && wE[j] != 0 && wE[j] < min)
//		{
//			min = wE[j];
//			temp = j;
//		}
//	}
//
//	return temp;
//}
//void kruskal()
//{
//	int i = 0;
//	bool flag = false;
//	int x = 0;
//
//	while (i < nE && !flag)
//	{
//		x = tim_MinE();
//		if (x != -1)
//		{
//			if(TonTai(E1[x], T1, nT) == 0  || TonTai(E2[x], T1, nT) == 0)
//			{
//				if (TonTai(E1[x], T2, nT) == 0 || TonTai(E2[x], T2, nT) == 0)
//				{
//					T1[nT] = E1[x];
//					T2[nT] = E2[x]; 
//					wT[nT] = wE[x];
//					nT++;
//
//					if(nT == n - 1)
//						flag = true;
//				}
//			}
//			wE[x] = 0;
//		}
//		i++;
//	}
//}
//void output()
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
//int main()
//{
//	int chon;
//	bool in = false;
//
//	do {
//		system("cls");
//		cout << "-----Menu-----\n"
//			<< "1. Nhap ma tran ke (bang file)\n"
//			<< "2. Xuat ma tran ke\n"
//			<< "3. Tim cay khung toi thieu\n"
//			<< "4. Thoat\n"
//			<< "Ban chon: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			if (in)
//			{
//				khoiTaoMaTranRong();
//				n = 0;
//
//				inputByFile();
//			}
//			else
//			{
//				inputByFile();
//				in = true;
//			}
//			break;
//		case 2:
//			if (in)
//			{
//				outputMaTranKe();
//			}
//			else
//				cout << "Khong co du lieu\n";
//			break;
//		case 3:
//			if (in)
//			{
//				taoE();
//				//SapXepE();
//				kruskal();
//				cout << "Ket qua cay khung toi thieu:\n";
//				output();
//			}
//			else
//				cout << "Khog co du lieu\n";
//			break;
//		default:
//			cout << "---Ket thuc chuong trinh---\n";
//		}
//		system("pause");
//	} while (chon >= 1 && chon <= 3);
//	return 0;
//}
