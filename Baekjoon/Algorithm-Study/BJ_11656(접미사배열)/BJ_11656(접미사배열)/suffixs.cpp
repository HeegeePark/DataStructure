#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	string S;
	vector<string> Suffixs;		// vector ������ ���̻� �迭
	string suffix;		// ���̻�

	cin >> S;

	// Suffix��� ���̻� �迭�� ��� ���̻� ����
	for (int i = 0; i < S.length(); i++) {
		for (int j = i; j < S.length(); j++) {
			suffix.push_back(S[j]);
		}
		Suffixs.push_back(suffix);
		suffix.clear();
	}

	// ���̻���� ���ĺ���(������)���� ����
	sort(Suffixs.begin(), Suffixs.end());

	// ���������� ���ĵ� ���̻� ���
	for (int i = 0; i < Suffixs.size(); i++) {
		cout << Suffixs[i] << endl;
	}

	system("pause");
	return 0;
}