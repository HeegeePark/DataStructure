#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000];		// ����
	int d[1000];		// ���� �� ���� ���̸� �����ϴ� ���̳��� ���� �迭
	vector<int> temp;		// max�� ã�� temp ����
	int len_max = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	d[0] = 1;
	if (A[1] > A[0]) d[1] = 2; else d[1] = 1;
	for (int i = 2; i < N; i++) {
		// 0~ i-1 ���� ���� �� i��° ������ �� ū ����� ���̳��� �� �ִ뿡 1���ϱ�
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				temp.push_back(d[j]);
			}
		}
		if (!temp.empty()) {
			d[i] = *max_element(temp.begin(), temp.end()) + 1;		// *max_element : ���� �� �ִ밪�� ã�Ƴ��� �Լ�
			temp.clear();
		}
		else d[i] = 1;
	}

	cout << *max_element(d,d+N) << endl;
	
	system("pause");
	return 0;
}