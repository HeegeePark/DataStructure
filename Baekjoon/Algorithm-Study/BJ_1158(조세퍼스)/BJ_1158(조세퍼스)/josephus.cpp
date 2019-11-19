#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K = 0;
	int temp = 0;
	
	cin >> N;
	cin >> K;

	queue<int> q;
	// queue�� ���� ����
	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}

	cout << "<";
	for (int i = 0; !q.empty(); i++) {		//queue�� �� ������ �ݺ�
		// K��° ����� ��ȣ�� queue�� ����Ʈ�϶�
		if (i % K == K - 1) {
			temp = q.front();
			cout << temp;
			q.pop();
			if (!q.empty()) {
				cout << ", ";
			}
		}
		else {		// �ƴѰ�� : pop�ؼ� �ٽ� ť�� �ڿ� ����
			temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	cout << ">";

	return 0;

}