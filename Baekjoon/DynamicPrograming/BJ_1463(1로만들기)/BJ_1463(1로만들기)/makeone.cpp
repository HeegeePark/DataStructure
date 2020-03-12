#include <iostream>
#include <stdlib.h>
using namespace std;

int cnt[1000001];
int make_1(int _n);

int main() {
	int N;

	cin >> N;
	cout << make_1(N) << '\n';
		
	system("pause");
	return 0;
}

int make_1(int _n) {
	int n = _n;

	/*Top-Down*/
	//if (n == 1) {
	//	return 0;
	//}
	//else if (cnt[n] > 0) {
	//	return cnt[n];
	//}
	//else {
	//	cnt[n] = make_1(n - 1) + 1;
	//	if (n % 3 == 0) {		// 3���� ���������� ���
	//		int temp = make_1(n / 3) + 1;
	//		if (cnt[n] > temp) cnt[n] = temp;
	//	}
	//	if (n % 2 == 0) {		// 2���� ���������� ���
	//		int temp = make_1(n / 2) + 1;
	//		if (cnt[n] > temp) cnt[n] = temp;
	//	}			
	//}
	
	/*Bottom-up*/
	cnt[1] = 0;
	for (int i = 2; i <= n; i++) {
		cnt[i] = cnt[i - 1] + 1;
		if (i % 2 == 0 && cnt[i] > cnt[i / 2] + 1) {		// 2���� ����������, ���̳ʽ� 1 ������ ���� ������, ���� Ƚ���� ������� 
			cnt[i] = cnt[i / 2] + 1;
		}
		if (i % 3 == 0 && cnt[i] > cnt[i / 3] + 1) {		// 3���� ����������, ���̳ʽ� 1 ������ ���� ������, ���� Ƚ���� ������� 
			cnt[i] = cnt[i / 3] + 1;
		}
	}
	
	return cnt[n];
}