#include <iostream>
#include <stdlib.h>
using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int N;
	long d[10000][4];		// �ִ� ������ ���� ������ ���̳��� �迭([i][0]: i-1,i�ȸ���, [][1]: i-1 X,i O, [][2]: i-1 O,i X, [][3]: i-1 O,i O)
	long wine[10000];		// wine[i] : i��° ������ ���� ��
	int wine_max = 0;		// �ִ�� ���� �� �ִ� �������� ��

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wine[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			d[i][0] = 0;
			d[i][1] = wine[i];
			d[i][2] = 0;
			d[i][3] = 0;
		}
		else {
			d[i][0] = max(d[i - 1][0], d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + wine[i];
			d[i][2] = max(d[i - 1][1], d[i - 1][3]);
			d[i][3] = d[i - 1][1] + wine[i];		// d[i-1][3]�� i-2,i-1�� �������� �������Ƿ� ���X
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			if (d[i][j] > wine_max) {
				wine_max = d[i][j];
			}
		}
	}

	cout << wine_max << endl;

	system("pause");
	return 0;
}