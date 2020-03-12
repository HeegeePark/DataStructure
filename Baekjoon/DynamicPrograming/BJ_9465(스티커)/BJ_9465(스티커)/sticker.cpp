#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int T;
	long N;
	int scoreSum = 0;		// �ִ� ����
	long**s;		// ��������
	long**d;		// ��ƼĿ ��뿩������

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

		// Ž�� �� ���� ���θ� ������ 2�����迭(2*N) �����ϰ� 0(��ƼĿ�� ��������)���� �ʱ�ȭ
		d = (long**)malloc(sizeof(long*) * 2);
		for (int i = 0; i < 2; i++) {
			d[i] = (long*)malloc(sizeof(long) * N);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = { 0 };
			}
		}


		// ��ƼĿ �ִ� ���� ���ϱ�(���̳���)
		for (int i = 0; i < 2; i++) {
			// ù��° ��
			if (i == 0) {
				for (int j = 0; j < N; j++) {
					if (j == 0) {		// ó������ ��� �����ϱ�
						d[i][j] = 1;
					}
					if (s[i][j] > s[i][j - 1]) {		// ���� ��ƼĿ������ ���� ��ƼĿ�������� Ŭ ��
						d[i][j] = 1;
						d[i][j - 1] = 0;
					}
				}
			}

			// �ι�° �� (ù��° ���� ����ϸ� Ž��)
			else {
				for (int j = 0; j < N; j++) {
					if (d[i - 1][j] == 1) {		// ���� ������ ��ƼĿ�� ��������� ��
						if (s[i][j] > s[i - 1][j]) {		// ������ ���� ��ƼĿ�� ���� �� => �� ��ƼĿ 0, ���� ��ƼĿ 1
							d[i][j] = 1;
							d[i - 1][j] = 0;
						}
					}
					else {		// �� ��ƼĿ�� �ȶ���ٸ� ���� ��ƼĿ ��� ���� ��ƼĿ���� ���� ��
						if (j == 0) d[i][j] = 1;
						else {
							if (s[i][j] > s[i][j - 1]) {		// ���� ��ƼĿ������ ���� ��ƼĿ�������� Ŭ ��
								d[i][j] = 1;
								d[i][j - 1] = 0;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][j] == 1) {
					scoreSum += s[i][j];
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