#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int A[1000];		// ���� A
	int D[1000];		// ���� A�� ���� ū ���� �κ� ������ �� ���̳��� �迭
	vector<int> temp;
	
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	D[0] = A[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				temp.push_back(D[j]);
			}
		}
		if (!temp.empty()) {
			D[i] = *max_element(temp.begin(), temp.end()) + A[i];
			temp.clear();
		}
		else {
			D[i] = A[i];
		}
	}

	cout << *max_element(D, D + N) << endl;
	
	system("pause");
	return 0;
}