#include <iostream>

int main() {
	int N;
	std::cin >> N;

	// (ȸ�ǽ��۽ð�, ȸ������ð�) 2���� �迭�� ��� 
	int** Confs = new int*[N]();
	for (int i = 0; i < N; i++) {
		Confs[i] = new int[N]();
	}

	// (ȸ�ǽ��۽ð�, ȸ������ð�) �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> Confs[i][j];
		}
	}

	// Sorting
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (Confs[i] == Confs[i-1])
		}
	}
}