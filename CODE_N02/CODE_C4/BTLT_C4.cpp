#include<iostream>
#include <conio.h>
using namespace std;

struct Node {
	int data;
	Node* right;
	Node* left;
};
Node* root;
struct Queue {
	Node* data;
	Queue* next;
};
Queue* front, * rear;
struct Stack {
	Node* data;
	Stack* next;
};
Stack* top;
void empty_tree() {
	root = NULL;
	top = NULL;
	rear = NULL;
	front = NULL;
}
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void insertNode(Node*& root, int x)
{
	Node* temp = newNode(x);
	Node* p = root;
	Node* prev = NULL;
	while (p != NULL)
	{
		prev = p;
		if (p->data == x)
			return;
		else if (x < p->data)
			p = p->left;
		else
			p = p->right;
	}
	if (prev == NULL)
	{
		prev = temp;
		root = prev;
	}
	else
		if (x < prev->data)
			prev->left = temp;
		else
			prev->right = temp;
}
Node* search(Node* p, int x)
{
	while (p != NULL)
	{
		if (p->data == x)
			return p;
		else
			if (p->data > x)
				p = p->left;
			else
				p = p->right;
	}
	return NULL;
}
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->data = q->data;
		p = q;
		q = q->right;
	}
	else
	{
		searchStandFor(p, q->left);
	}
}
int Delete(Node*& T, int x)
{
	if (T == NULL)
		return 0;
	if (T->data == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete(p);
		return 1;
	}
	if (T->data < x)
		return Delete(T->right, x);
	if (T->data > x)
		return Delete(T->left, x);
}
int isEmpty()
{
	return (top == NULL);
}
void push(Node* x)
{
	Stack* p = new Stack;
	p->data = x;
	p->next = top;
	top = p;
}
int pop(Node* x)
{
	if (top != NULL)
	{
		Stack* p = top;
		x = p->data;
		top = p->next;
		delete(p);
		return 1;
	}
	return 0;
}
void push1(Node* x)
{
	Queue* p;
	p = new Queue;
	p->data = x;
	p->next = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}
int pop1(Node* x)
{
	if (front != NULL)
	{
		Queue* p = front;
		x = p->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty1()
{
	if (front == NULL)
		return 1;
	return 0;
}
void duyetLRN(Node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->data << " ";
	}
}
void preorderTraversal(Node* root)
{
	Node* p;
	if (root != NULL)
	{
		push(root);
	}
	while (!isEmpty())
	{
		p = top->data;
		pop(p);
		cout << p->data << " ";
		if (p->right != NULL)
			push(p->right);
		if (p->left != NULL)
			push(p->left);
	}
}
void inorderTraversal(Node* root)
{
	Node* p = root;
	while (p != NULL||!isEmpty())
	{
		if (p != NULL)
		{
			push(p);
			p = p->left;
		}
		else
		{
			p = top->data;
			pop(p);
			cout << p->data << " ";
			p = p->right;
		}
	}
}
void postorderTraversal(Node* root)
{
	Node* p = root;
	Node* pre = NULL;
	pre = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
}
int main()
{
	int n, x, chon;
	bool check = false;
	do {
		system("cls");
		cout << "MENU\n"
			<< "1. Khoi tao cay nhi phan.\n"
			<< "2. Them mot phan tu vao cay.\n"
			<< "3. Tim mot phan tu trong cay.\n"
			<< "4. Xoa mot nut trong cay.\n"
			<< "5. Duyet NLR.\n"
			<< "6. Duyet LNR.\n"
			<< "7. Duyet LRN.\n"
			<< "8. Thoat.\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			empty_tree();
			cout << "Khoi tao thanh cong";
			check = true;
			break;
		case 2:
			if (check)
			{
				cout << "Nhap gia tri can them: ";
				cin >> x;
				insertNode(root, x);
				cout << endl;
			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		case 3:
			if (check)
			{
				cout << "Nhap gia tri can tim kiem: ";
				cin >> x;
				if (search(root, x) != NULL)
					cout << "Gia tri " << x << "  co trong cay\n";
				else
					cout << "Khong tim thay gia tri " << x << endl;
			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		case 4:
			if (check)
			{
				cout << "Nhap gia tri can xoa: ";
				cin >> x;
				if (Delete(root, x) == 1)
					cout << "Xoa thanh cong!\n";
				else
					cout << "Xoa khong thanh cong!\n";
			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		case 5:
			if (check)
			{
				preorderTraversal(root);
				cout << endl;
			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		case 6:
			if (check)
			{
				inorderTraversal(root);
				cout << endl;

			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		case 7:
			if (check)
			{
				duyetLRN(root);
				cout << endl;

			}
			else
				cout << "Ban chua khoi tao\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 7);
	return 0;
}