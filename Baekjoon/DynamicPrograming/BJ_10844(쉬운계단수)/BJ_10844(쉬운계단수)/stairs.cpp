#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
	int N;
	long long ezStairs = 0;		// ��ܼ�
	long long mod = 1000000000;		// ������ ���� ��

	cin >> N;

	// N��ŭ�� ���̸� ���� �ڸ����� �޸� �Ҵ� �� 0���� �ʱ�ȭ
	long long**stairs = (long long**)malloc(sizeof(long long*)*N);
	for (int i = 0; i < N; i++) {
		stairs[i] = (long long*)malloc(sizeof(long long) * 10);
		for (int j = 0; j < 10; j++) {
			stairs[i][j] = { 0 };
		}
	}

	// ��ܼ� ���ϱ�
	for (int i = 0; i < N; i++) {
		if (i == 0) {		// N�� ���ڸ� �� �϶� => ������ 1(1 ~ 9)
			for (int j = 1; j < 10; j++) {
				stairs[i][j] = 1;
			}
		}
		
		else {		// N�� ���ڸ� �� �̻��� ��
			for (int j = 0; j < 10; j++) {		// j�� �������� Top-Down���� �ڸ����� ��ܼ� ���ϱ�
				if (j == 0) stairs[i][j] = stairs[i - 1][1] % mod;
				else if (j == 9) stairs[i][j] = stairs[i - 1][8] % mod;
				else stairs[i][j] = stairs[i - 1][j - 1] + stairs[i - 1][j + 1] % mod;
			}
		}
	}
		
	// N ������ �����ܼ��� ���ϰ�, 1,000,000,000���� ���� �������� �ʱ�ȭ �� ���
	for (int i = 0; i < 10; i++) {
		ezStairs += stairs[N - 1][i];

	}
	ezStairs %= mod;

	cout << ezStairs << endl;	

	free(stairs);
	system("pause");
	return 0;
}