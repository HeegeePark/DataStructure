#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int T;
	int n;
	int add[10];
	
	// 1, 2, 3 ������ ����� �� ���ϱ�
	add[0] = 1;
	add[1] = 2;
	add[2] = 4;
	for (int i = 3; i < 11; i++) {
		add[i] = add[i - 1] + add[i - 2] + add[i - 3];
	}
	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << add[n - 1] << endl;
	}
	
	system("pause");
	return 0;
}