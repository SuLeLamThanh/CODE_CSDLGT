#include<iostream>
using namespace std;
 
/*
Doi so thap phan sang co so 2 8 16
*/
 
/* khai bao Node */
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
 
/* khai bao cau truc cua Stack */
struct stack
{
    NODE *pTop; // con tro quan ly dau stack
};
typedef struct stack STACK;
 
/* ham khoi tao Stack */
void KhoiTaoStack(STACK &s)
{
    s.pTop = NULL;
}
 
/* ham khoi tao 1 cai node */
NODE *KhoiTaoNode(int x)
{
  //tao moi 1 NODE
    NODE *p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !";
        return NULL;
    }
  // dua du lieu cua bien x vao trong cai data của node p
    p->data = x; 
    p->pNext = NULL;
    return p;
}
 
/* ham kiem tra stack rong*/
bool IsEmpty(STACK s)
{
    // neu stack rong
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}
 
/* them phan tu vao dau Stack (top)*/
bool Push(STACK &s, NODE *p)
{
    // node p dang rong
    if (p == NULL)
    {
        return false;
    }
 
    // neu danh sach rong
    if (IsEmpty(s) == false)
    {
    // node p cung chinh la node pTop <=>chinh la node dau stack
        s.pTop = p;
    }
    else
    {
    // B1: cho con tro cua node p tro den node pTop
        p->pNext = s.pTop; 
    // B2: cap nhat lai node dau chnh la node p
        s.pTop = p;
    }
  // them thanh cong
    return true;
}
 
/* Lay phan tu dau danh sach va huy no di */
bool Pop(STACK &s, int &x) // x chinh la gia tri can lay ra
{
    // neu danh sach rong
    if (IsEmpty(s) == false)
    {
    // lay that bai <=> danh sach dang rong
        return false; 
    }
  // gan node dau danh sach vao node p <=> node p chinh la node ma ti nua ta se xoa no
    NODE *p = s.pTop; 
   // cap nhat lai node dau
    s.pTop = s.pTop->pNext;
  // lay gia tri cua node dau ra gan vao bien x
    x = p->data; 
  // lay phan tu thanh cong
    return true; 
}
 
/* Xem thong tin cua node dau danh sach */
bool Top(STACK s, int &x) 
// x chinh la gia tri can xem
{
    // neu danh sach rong
 
    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}
 
/* Ham doi co so 10 sang cac co so 2, 8, 16 */
void Chuyen_Co_So(STACK &s, int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;
    // them x vao node p
        NODE *p = KhoiTaoNode(x); 
    // them node p vao stack
        Push(s, p);
    //tiep tuc chia den het
        hethapphan /= cosocandoi;
    }
}
 
/* xuat danh sach stack */
void XuatStack(STACK &s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
    //neu x < 10 thi xuat binh thuong
        if (x < 10)
        {
            cout << x;
        }
    //neu x >= 10 thi xuat chu cai tuong ung
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}
 
int main()
{
    STACK s;
    KhoiTaoStack(s);
     
    int hethapphan,cosocandoi;
    cout << "\nNhap gia tri thap phan can chuyen: ";
    cin >> hethapphan;
  do{
    cout << "\nNhap co so can chuyen (2, 8, 16):  ";
      cin >> cosocandoi;
  }while(cosocandoi != 2 && cosocandoi != 8 && cosocandoi != 16);
 
    Chuyen_Co_So(s, cosocandoi, hethapphan);
    cout << "\nKet qua:\n";
    XuatStack(s);
    cout << endl;
	return 0;
}