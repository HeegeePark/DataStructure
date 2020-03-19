#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000];		// ���� A
	int D[1000];		// ���� �� ������� �κ� ������ ����
	int D_asc[1000];		// ���� �� �����ϴ� �κ� ������ ����
	int D_des[1000];		// ���� �� �����ϴ� �κ� ������ ����

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		D_asc[i] = 1;
		D_des[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && D_asc[i] < D_asc[j] + 1) {
				D_asc[i] = D_asc[j] + 1;
			}
			
		}
		D[i] = D_asc[i] + D_des[i] - 1;
	}
	for (int i = N; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {
			if (A[i] > A[j] && D_des[i] < D_des[j] + 1) {
				D_des[i] = D_des[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		D[i] = D_asc[i] + D_des[i] - 1;
	}

	cout << *max_element(D, D + N) << endl;

	system("pause");
	return 0;
}