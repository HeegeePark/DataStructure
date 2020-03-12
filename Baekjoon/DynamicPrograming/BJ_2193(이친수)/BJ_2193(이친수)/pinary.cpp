#include <iostream>
#include <stdlib.h>
using namespace std;

// ��ģ�� ��Ģ
// 1. 0���� �������� �ʴ´�.
// 2. 1�� �� �� �������� �Ͼ�� �ʴ´�.

int main() {
	int N;
	long piNum = 0;
	
	cin >> N;
	
	// N ���̸� ���� ��ģ�� �迭 �Ҵ� �� �ʱ�ȭ (long���� �ʱ�ȭ�ϴ°� �߿�!)
	long**binum = (long**)malloc(sizeof(long*)*N);
	for (int i = 0; i < N; i++) {
		binum[i] = (long*)malloc(sizeof(long) * 2);
		for (int j = 0; j < 2; j++) {
			binum[i][j] = { 0 };
		}
	}

	// ��ģ�� ���� ���ϱ�
	for (int i = 0; i < N; i++) {
		// N�� ���ڸ� ��
		if (i == 0) {
			binum[i][1] = 1;
		}
		else {
			for (int j = 0; j < 2; j++) {
				if (j == 0) binum[i][j] = binum[i - 1][0] + binum[i - 1][1];
				if (j == 1) binum[i][j] = binum[i - 1][0];
			}
		}
	}

	// ��ģ�� ���
	for (int i = 0; i < 2; i++) {
		piNum += binum[N - 1][i];
	}
	cout << piNum << endl;

	free(binum);
	system("pause");
	return 0;
}