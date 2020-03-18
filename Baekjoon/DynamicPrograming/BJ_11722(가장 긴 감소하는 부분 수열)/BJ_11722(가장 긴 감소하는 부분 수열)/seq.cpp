#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000];		// ����
	int d[1000];		// ���� �� ���� ���̸� �����ϴ� ���̳��� �迭

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	d[0] = 1;
	
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d, d + N) << endl;

	system("pause");
	return 0;
}