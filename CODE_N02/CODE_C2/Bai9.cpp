#include <iostream>
using namespace std;

struct stack
{
	int top = -1;
	char data[26];
	void push(char a)
	{
		if (top < 25)
			data[++top] = a;
	}
	char pop()
	{
		if (top != -1)
			return data[top--];
		return NULL;
	}
	bool isFull()
	{
		if (top <= 26)
			return true;
		return false;
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}
/*	void display(int a)
	{
		cout << a + 1 << " |";
		for (int i = 0; i < top; i++)
			cout << data[i] << " ";
		cout << endl;
	} //Em thử vẽ ra tháp nhưng không thành, mong thầy thông cảm */
} tower[3];
void type(int& n)
{
	do {
		cout << "n = ";
		cin >> n;
		if (n < 1 || n > 26)
			cout << "Wrong! Type again ";
	} while (n < 1 || n > 26);
}
/*void show()
{
	for (int i = 0; i < 3; i++)
		tower[i].display(i);
} //Em thử vẽ ra tháp nhưng không thành, mong thầy thông cảm */
void move(int n, char begin, int start, int finish, int temp, int &count)
{
	if (n == 0) return;
	move(n - 1, tower[start - 1].data[n - 1], start, temp, finish, count);
	cout << "Move " << tower[start - 1].data[n - 1] << " from tower " << start << " to tower " << finish << endl;
	tower[finish - 1].push(tower[start - 1].pop());
	count++;
	move(n - 1, tower[temp - 1].data[n - 1], temp, finish, start, count);
}

int main()
{
	char a[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, count = 0; 
	cout << "How many disks? ";
	type(n);
	for (int i = n; i > 0; i--)
		tower[0].push(a[i]);
	cout << "Before moving (start from the 1st tower, letter A is bottom): ";
	for (int i = 0; i < n; i++)
		cout << tower[0].data[i] << " ";
	cout << endl;
	move(n, tower[0].data[n], 1, 3, 2, count);
	cout << "After moving " << count << " times to the 3rd tower: ";
	for (int i = 0; i < n; i++)
		cout << tower[2].data[i] << " ";
	cout << endl;
	return 0;
}