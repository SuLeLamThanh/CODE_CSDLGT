//nhom baitap 2,nguyen huy tú
#include <iostream>// bai 4 lam them
#include <conio.h>
using namespace std;
struct node
{
	int data;
	node*link;
};
node*first;
void init();
void themcuoi(int x);
node*tim(int x);
void timxoa(int x);
void xuat();
int themsaunot_o(int x, int y);
void insertion();
int main()
{
	int chon,x,y;
	bool in =false;
	do{
		system("cls");
		cout << "MENU\n1.xuat\n2.timxoa\n3.themcuoi\n4.findtoAdd\n5.khoi tao\n6thoat:\nchon:";
		cin>> chon;
		switch(chon)
		{
		case 1:
			if(in)
			{
				xuat();
			}
			else
				cout << "vui long khoi tao truoc\n";
			break;
		case 2:
			if(in)
			{
				cout << "nhap so can xoa: ";
				cin >> x;
				timxoa(x);
				cout << "xoa thanh cong,muon xem chon xuat!\n ";
			}
			else
				cout << "vui long khoi tao truoc\n";
			break;
		case 3:
			if(in)
			{
				cout << "nhap so can them: ";
				cin >> x;
				themcuoi(x);
				insertion();
				cout << "them thanh cong,muon xem chon xuat!\n ";
			}
			else
				cout << "vui long khoi tao truoc\n";

			break;
		case 4:
			if(in)
			{
			
				cout << "chon node TRUOC NODE CAN THEM: ";
				cin >> y;// tý vô hàm kiểm tra xem y có thật trog ds ko , nếu ko thì ko thể thêm đc// y này chính là NODE o
				cout << "value can them: ";
				cin >> x;
				if(themsaunot_o(x,y))// có y tồn tại thì thêm
				{
					cout << "them thanh cong, vui long xuat";
				}
				else
					cout << "them ko duoc vi ko co"<< y<<" trong danh sach\n";
			}
			else
				cout << "vui long khoi tao truoc\n";
			break;
		case 5:
			init();
			in =true;
			break;

		default:
			cout<< "ban chon thoat\n";
			break;
		}
		_getch();
	}while(chon >= 1 && chon <= 5);
}
void init()
{
	first = NULL;
}
void xuat()
{
	node*p = first;
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}
}
node*tim(int x)
{
	node*p = first;
	
	while(p!=NULL && p->data != x)
	{
		p = p->link;
	
	}
	return p;// khong tìm thấy sẽ == NULL


}
int demsluong()
{
	int dem = 0;
	node*p = first;
	while(p != NULL)
	{
		p= p->link;
		dem++;
	}
	return dem;

}
void timxoa(int x)
{
	
	node*q = tim(x);
	if(q == NULL)
	{
		cout << "khong co phan tu " << x <<endl;
		return;
	}
	node*a =new node;
	for(node*p =first; p != NULL; p = p->link )
	{
		

		if(p ->data == q ->data)
		{
			//node*g = p->link;// node g chính là node nằm sau node p
			a->link = p->link;// cập nhật mối liên hệ giữa node năm sau p(cũng là node q)
			//với node trước p
			delete p; // xóa node nằm sau node p
			return;// bắt buộc có để dừng khi tìm đc và xóa r
		}
		a = p;// a là thằng được gán trc thằng cần xóa, trc khi qua vog lắp típ theo

	}
}
void themcuoi(int x)
{
	node*p = new node;
	p->link = NULL;
	p->data = x;
	if(first == NULL)
		first = p;
	else
	{
		node*q =first;
		while(q->link !=NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
int themsaunot_o(int x, int y)// them x vao sau y
{
	node*o = tim(y);// node truoc vitri  them

	
	if(o == NULL)// nếu thằng y ko được tìm thấy thì y ko tồn tại trog ds ,lấy gì thêm sau nó hả?nên return 0(ko thêm đc)
		return 0;
	else
	{
			node*p = new node;
			p->data = x;
			if(o->link == NULL)// dang o node cuoi
			{
				// themcuoi or
				p->link = NULL;// gán vô cuối
				// sau đó nối nó với thằng trước nó là thằng o
				o->link = p;

			}
			else// không phải ở node cuối thì nó thêm đầu or giữa 
			{
				//nối node được thêm với node sau
				p->link = o->link;//  thằng o->link chính là thằng nằm sau o ở danh sách ban đầu trước khi thêm
				// nối node với thằng node trước nữa là ok
				o->link = p;
			}
			return 1;
	}
}
void insertion()
{
	int x;
	node*q = new node;
	node*p;
	for(p = first->link; p != NULL; p = p->link)
	{
		x = p->data;
		q->link = p;
		while(q!=first && x < q->data)
		{
			(q->link)->data = q->data;
			q->link = q;
		}
		(q->link)->data = x;

	}
}



