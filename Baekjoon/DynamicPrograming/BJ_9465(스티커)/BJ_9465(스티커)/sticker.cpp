#include <iostream>
#include <stdlib.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int T;
	long N;
	int scoreSum = 0;		// �ִ� ����
	long**s;		// ��������
	long**d;		// ��ƼĿ �ִ���������

	cin >> T;

	// �׽�Ʈ���̽� �ݺ���
	for (int i = 0; i < T; i++) {
		cin >> N;
		// ��ƼĿ���� 2�����迭(2*N)�� ����
		s = (long**)malloc(sizeof(long*) * 2);
		for (int i = 0; i < 2; i++) {
			s[i] = (long*)malloc(sizeof(long) * N);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> s[i][j];
			}
		}

		// ��ƼĿ�� �ִ������� ������ 2�����迭(2*N) ����
		// d[i][j] : i��° ������ j����(0= �ȶ�, 1= ����, 2= �Ʒ���)�� ���� �ִ�����
		d = (long**)malloc(sizeof(long*) * N);
		for (int i = 0; i < N; i++) {
			d[i] = (long*)malloc(sizeof(long) * 3);
		}
		


		// ��ƼĿ �ִ� ���� ���ϱ�(���̳���)
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				d[0][0] = 0;
				d[0][1] = s[0][0];
				d[0][2] = s[1][0];
			}
			else {
				d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
				d[i][1] = max(d[i - 1][0], d[i - 1][2]) +s[0][i];
				d[i][2] = max(d[i - 1][0], d[i - 1][1]) + s[1][i];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				if (d[i][j] >=scoreSum) {
					scoreSum = d[i][j];
				}
			}
		}
		cout << scoreSum << endl;

		// �޸� ����, �ִ����� ����
		delete[] s;
		delete[] d;
		scoreSum = 0;
	}

	system("pause");
	return 0;
}