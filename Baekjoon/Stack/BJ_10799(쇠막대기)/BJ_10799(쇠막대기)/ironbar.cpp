#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> s;
	char parentheses[100000];		//��ȣ ��� char �迭
	int parCnt = 0;		// ��ȣ ����
	int i = 0;
	int barCnt = 0;
	bool is_bar = false;
	cin >> parentheses;

	// ������ ���� detect �� ��ȣ stack�� push
	for (i = 0; parentheses[i] != NULL; i++) {
		if (parentheses[i] == ')') {
			if (!s.empty()) {		// ���� ��ȣ�� ���� ��, ������ ���� �ȵ�
				if (parentheses[i - 1] == '(') {	// ���� ��ȣ�� ���� ��ȣ�� ��(������)
					// ������ ��ȣ pop
					s.pop();

					// ���ÿ� ���� ��ȣ �� ��ƴ �۴�� ���� ++
					barCnt += s.size();

				}
				else {			// �۴�Ⱑ ���� ��
					s.pop();
					barCnt += 1;
				}
			}

		}
		else {		// ���� ��ȣ�� �ݴ� ��ȣ X
			s.push(parentheses[i]);
		}
	}

	cout << barCnt << "\n";

	return 0;
}