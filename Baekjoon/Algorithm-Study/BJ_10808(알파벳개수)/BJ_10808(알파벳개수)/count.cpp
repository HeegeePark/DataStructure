#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char S[100];	// �ܾ ���� ���ڿ�
	int cnt_S[26] = { 0 };		// ���ڿ��� �ش� ���ĺ� ������ ���� ������ �迭
		
	cin >> S;

	// ���ĺ� ���� ����
	for (int i = 0; S[i] != NULL; i++) {
		cnt_S[S[i] - 97]++;		// 'a' = 97
	}

	// ���
	for (int i = 0; i < sizeof(cnt_S)/sizeof(int); i++) {
		cout << cnt_S[i] << " ";
	}

	return 0;
}