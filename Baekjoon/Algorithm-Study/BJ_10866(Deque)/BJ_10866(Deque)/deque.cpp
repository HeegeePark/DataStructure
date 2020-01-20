#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

// �� ����
int main() {
	deque<int> d;
	int N;
	int X;
	char order[20];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> order;
		// front�� pop
		if (strcmp(order, "pop_front") == 0) {
			if (!d.empty()) {
				cout << d.front() << endl;
				d.pop_front();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		// back�� pop
		else if (strcmp(order, "pop_back") == 0) {
			if (!d.empty()) {
				cout << d.back() << endl;
				d.pop_back();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		// �� size ���
		else if (strcmp(order, "size") == 0) {
			cout << d.size() << endl;
		}
		// �� empty() ���
		else if (strcmp(order, "empty") == 0) {
			if (d.empty()) {
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		// front ���
		else if (strcmp(order, "front") == 0) {
			if (!d.empty()) {
				cout << d.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		// back ���
		else if (strcmp(order, "back") == 0) {
			if (!d.empty()) {
				cout << d.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		// front�� push
		else if (strcmp(order, "push_front") == 0) {
			cin >> X;
			d.push_front(X);
		}
		// back�� push
		else {
			cin >> X;
			d.push_back(X);
		}

	}

	return 0;
}