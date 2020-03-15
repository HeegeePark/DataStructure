#include <iostream>
#include <stdlib.h>
using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int N;
	long stairs[300];		// ����� ����
	long d[300];		// ����� �ִ����� �� ���̳��� �迭

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stairs[i];
	}

	d[0]= stairs[0];
	d[1] = d[0] + stairs[1];
	d[2] = max(d[0] + stairs[2], stairs[1] + stairs[2]);
	for (int i = 3; i < N; i++) {
		d[i] = max(
			d[i - 2] + stairs[i],		// ù��°�� ������ ���
			d[i - 3] + stairs[i - 1] + stairs[i]		// �ι�°�� ������ ���
		);
	}
	
	cout << d[N-1] << endl;		// ������ ����� �� ��ƾ� �ϹǷ� �ִ����� �� = d[N-1]
	
	system("pause");
	return 0;
}
