#include <stdio.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main() {
	int T;
	char curPs;
	stack<char> psStack;	// ��ȣ�� ���� ���� ����
	char buf[50];
	string vps = "YES";

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		//gets_s(buf);
		cin >> buf;
		
		vps = "YES"; // ����
		for (int j = 0; buf[j] != '\0'; j++) {
			curPs = buf[j];
			if (curPs == ')') {
				if (!(psStack.empty())) {
					psStack.pop();
				}
				else {		// pop���� ��ȣ�� ���� �� (VPS X)
					vps = "NO";
					break;
				}
			}
			else {
				psStack.push(curPs);
			}
		}

		if (!(psStack.empty())) {
			vps = "NO";
			while (!(psStack.empty())) {
				psStack.pop();
			}
		}
		
		cout << vps << "\n";

	}

	return 0;
}