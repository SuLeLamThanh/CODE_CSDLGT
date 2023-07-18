#include<iostream>
#include<conio.h>

using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];
int C[MAX];

struct Node
{
	int info;
	Node *link;
};
Node *sp;
void init()
{
	n=0;
}
void input()
{
	cout << "Nhap so dinh do thi n: "; 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu "<< i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void output()
{
	a[MAX][MAX];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void khoitaochuaxet()
{
	for(int i = 0; i < MAX; i++)
		C[i] = 1;
}
// Khoi tao hang doi
typedef struct
{
        int A[MAX];
        int head,tail,count;        
} queue;

// Khoi tao hang doi rong

void init(queue *q)
{
        q->head=0;
        q->tail=MAX-1;
        q->count=0;     
}                  

int isEmpty(queue q)
{
        return(q.count==0);    
}       

int isFull(queue q)
{
        return(q.count>=(MAX-1));    
}

void push(queue *q, int x)
{
        if(isFull(*q)) 
        {
            cout<<"Hang doi day!";
            return;
        }
        else
        {
            if(q->tail==MAX-1)
            {                 
                  q->count++;
                  q->tail=0;
                  q->A[q->tail]=x;
            }
            else
            {
                   q->tail++;
                   q->A[q->tail]=x;
                   q->count++;
            }     
        }
}

int pop(queue *q)
{
        if(isEmpty(*q)) 
        {
            cout<<"Hang doi rong!";
            return -1;
        }
       
            int x=q->A[q->head];
            if(q->head==MAX-1) // dau, cuoi trung nhau
            {
                   q->head=0;
                   q->count--;
            }
            else
            {
                   q->head++;
                   q->count--;    
            }
            return x;    
            
}

void BFS(int u)
{
     queue q;
     init(&q);
     for(int i=1;i<=n;i++)
     {
             C[i]=0;        
     }     
     C[u]=1;
     cout<<endl<<"Duyet theo BFS: "<<u<<" ";
     push(&q,u);
     while(!isEmpty(q))
     {
             int x=pop(&q);
             for(int i=0;i<=n;i++)
             {
                     if((a[x][i])&&(C[i]==0))
                     {
                             push(&q,i);
                             cout<<i<< " "; 
                             C[i]=1;                             
                     }
             }
                                
     }
}
// thuat toan DFS
void DFS(int u){
// xet dinh u
 C[u]=0;
 cout<<u<<" ";
 for(int v=0;v<n;v++)
   if(C[v]==1&&a[u][v]==1)
   {
     DFS(v);
    }
 }
Node *front, *rear;
void Search_by_BFS(int x, int v) {	queue q;	int w, p;	push(&q,v);	C[v] = 0;	while(front != NULL)	{		pop(&q);		if (x == p)		{			cout << x << "ton tai";			return;		}		for(w = 0; w < n; w++)			 if(C[w] && a[p][w] == 1)			 {			   push(&q,w);			   C[w] = 0;			 }	}}
int main()
{
	int a[MAX][MAX];
	int x;
	bool in = false;
	int chon;
	do{
		system("cls");
		cout << "MENU\n1. Nhap ma tran ke\n2. Xuat ma tran ke\n3. Duyet do thi theo chieu rong\n4. Duyet do thi theo chieu sau\n5. Tim kiem theo chieu sau\n6. Thoat\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			input();
			in = true;
			break;
		case 2:
			if(in)
				output();
			else
				cout << "Chua nhap ma tran" << endl;
			break;
		case 3:
			if(in)
			{
				queue q;
				init(&q);
				push(&q,5);
				push(&q,4);
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				BFS(x);
			}
			else
				cout << "Chua nhap ma tran" << endl;
			break;
		case 4:
			if(in)
			{
				khoitaochuaxet();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				DFS(x);
				break;
			}
			else
				cout << "Chua nhap ma tran" << endl;
			break;
		case 5:
			if (in)
			{
				cout << "Nhap dinh can tim: ";
				cin >> x;
				Search_by_BFS(x,0);
			}
			else
				cout << "Chua nhap ma tran" << endl;
			break;
		default:
			cout << "SEE YOU LATER!" << endl;
			break;
		}
		_getch();
	} while(chon >= 1 && chon <= 5);
}