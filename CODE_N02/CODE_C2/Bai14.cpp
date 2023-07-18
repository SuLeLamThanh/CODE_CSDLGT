
#include <iostream>
using namespace std;

struct Node {
	int sm;
	int hs;
	Node* next;
};

struct List {
	Node* head, * tail;
};

void Init(List& l) {
	l.head = l.tail = NULL;
}

Node* creatNode(int h, int s) {
	Node* p = new Node;
	if (p == NULL) exit(1);
	p->sm = s;
	p->hs = h;
	p->next = NULL;
	return p;
}

void addTail(List& l, Node* p) {
	if (l.head == NULL) 
		l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = p; // cap nhap l.tail
	}
}

void nhap(List& l) {
	int x, n;
	cout << "\nNhap bac cua da thuc: "; cin >> n;
	for (int i = n; i >= 0; i--) {
		cout << "\nNhap he so cua x^" << i << ": "; cin >> x;
		Node* p = creatNode(x, i);
		addTail(l, p);
	}
}

void cong(List& l, List l1, List l2) {
	Node* p = new Node, * q = new Node;
	if (l1.head->sm > l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs += p->hs;
		p = p->next;
		q = q->next;
	}
}
void hieu(List& l, List l1, List l2) {
	Node* p = new Node, * q = new Node;
	if (l1.head->sm > l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs -= p->hs;
		p = p->next;
		q = q->next;
	}
}
void tich(List& l, List l1, List l2) {
	Node* p = new Node, * q = new Node;
	if (l1.head->sm > l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs *= p->hs;
		p = p->next;
		q = q->next;
	}
}
void thuong(List& l, List l1, List l2) {
	Node* p = new Node, * q = new Node;
	if (l1.head->sm > l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) 
		q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs /= p->hs;
		p = p->next;
		q = q->next;
	}
}

void xuat(List l) {
	Node* p = l.head;
	while (p != l.tail) {
		if (p->hs) 
			cout << p->hs << "x^" << p->sm;
		p = p->next;
		if (p->hs) {
			if (p->hs > 0 && p->next !=	NULL) 
				cout << " + ";
			else 
				cout << " ";
		}
	}
}

int main() {
	List l, l1, l2;
	Init(l); Init(l1); Init(l2);
	cout << "\nNhap P(x): "; 
	nhap(l1);
	cout << "\nNhap Q(x): "; 
	nhap(l2);
	cout << "\nP(x) = "; 
	xuat(l1);
	cout << "\nQ(x) = "; 
	xuat(l2);
	thuong(l, l1, l2);
	cout << "\nR(x) = "; 
	xuat(l);
	return 0;
}
