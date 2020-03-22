#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int D[100001];		// �������� ������ ��Ÿ�� ��, ������ ���� �ּ� ����
int last_t = 0;		// ������ ��

void solution() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		D[i] = i;
		for (int j = 1; i >= pow(j, 2); j++) {
			last_t = pow(j, 2);
			if (D[i] > D[i - last_t] + 1) {		// ���� j ���� �� ������ ������ ���� �ʱ�ȭ
				D[i] = D[i - last_t] + 1;
			}
		}
	}
	cout << D[N] << endl;
}

int main() {
	solution();
	system("pause");
	return 0;
}