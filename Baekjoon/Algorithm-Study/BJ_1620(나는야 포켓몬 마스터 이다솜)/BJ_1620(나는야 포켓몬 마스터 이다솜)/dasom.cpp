#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	string pokemon;
	char quiz[20];
	cin >> N >> M;
	map<string, int> PokemonsByName;
	map<int, string> PokemonsByNumber;

	// key�� ���ϸ��̸� �� ��ȣ�� ���� ����(��) ���
	for (int i = 0; i < N; i++) {
		cin >> pokemon;
		PokemonsByName.insert(pair<string, int>(pokemon, i + 1));
		PokemonsByNumber.insert(pair<int, string>(i + 1, pokemon));
	}

	// ���� ��ȸ
	for (int i = 0; i < M; i++) {
		cin >> quiz;
		// �Է� = ���ϸ� �̸� : ���° ���ϸ����� ���
		if (atoi(quiz) == 0) {
			cout << PokemonsByName.find(quiz)->second << "\n";
		}
		// �Է� =  ���� : �Է¹�°�� ���ϸ��̸� ���
		else {
			cout << PokemonsByNumber.find(atoi(quiz))->second << "\n";
		}
	}

	return 0;
}