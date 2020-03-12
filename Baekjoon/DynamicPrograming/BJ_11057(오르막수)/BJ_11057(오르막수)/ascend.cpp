#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int N;
	long long ascendNum = 0;		// ��������
	long long mod = 10007;		// ������ ���� ��
	cin >> N;

	// ���̰� N�� �ڸ����� ���������� ������ �迭 �Ҵ� �� �ʱ�ȭ
	long long**a = (long long**)malloc(sizeof(long long*)*N);
	for (int i = 0; i < N; i++) {
		a[i] = (long long*)malloc(sizeof(long long) * 10);
		for (int j = 0; j < 10; j++) {
			a[i][j] = { 0 };
		}
	}
	
	// �������� ���ϱ�
	for (int i = 0; i < N; i++) {
		if (i == 0) {		// N�� ���ڸ� �� �϶� => ������ 1(1 ~ 9)
			for (int j = 0; j < 10; j++) {
				a[i][j] = 1;
			}
		}

		else {		// N�� ���ڸ� �� �̻��� ��
			for (int j = 0; j < 10; j++) {		// j�� �������� Top-Down���� �ڸ����� �������� ���ϱ�
				for (int k = 0; k <= j; k++) {
					a[i][j] += a[i - 1][k];
				}
				a[i][j] %= mod;
			}
		}
	}

	// N ������ ���������� ���ϰ�, 10,007���� ���� �������� �ʱ�ȭ �� ���
	for (int i = 0; i < 10; i++) {
		ascendNum += a[N - 1][i];

	}
	ascendNum %= mod;

	cout << ascendNum << endl;

	system("pause");
	return 0;
}