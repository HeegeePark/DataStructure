#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > Conference;		// ȸ�� ������ ���Ϳ� ����
int main() {
	int N;
	int ConferenceCount = 0; // ����ϰ��� �ϴ� �Ϸ� �ִ� ȸ�Ǽ�
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		Conference.push_back(make_pair(start, end));
	}
	
	// ȸ�� ������ ������������ ����
	sort(Conference.begin(), Conference.end());

	// �� ȸ�ǰ� ������ �̾ �� �� �ִ� ȸ������ �Ѱ��� �迭�� ����
	int* CountNextPoss = new int[N];
	for (int i = 0; i < N; i++) {
		CountNextPoss[i] = 0;
	}
	int MaxCount = 0;
	int MaxCountIndex = 0;
	int NextIndex = 0;

	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (Conference[i].second < Conference[j].first) {
				CountNextPoss[i]++;
			}
		}
		if (CountNextPoss[i] > MaxCount) {
			MaxCount = CountNextPoss[i];
			MaxCountIndex = i;
		}
	}
	//  �Ѱ���(�迭�� value)�� ���� ũ�� ȸ�ǽð��� ���� �ε����� ȸ������(MaxCountIndex)�� ���ϰ�(ȸ�Ǽ�++), 
	// ���� ȸ�� �������� ������ �ε��� �� value�� ���� ū �ε��� ����
	// �� ������ �ε����� ���� �� ������ �ε����� �����ϰų� �Ѿ������ �ݺ�
	while (NextIndex < N ) {
		for (int i = NextIndex; i < N; i++) {
			if (CountNextPoss[i] > MaxCount) {
				MaxCount = CountNextPoss[i];
				MaxCountIndex = i;
			}
		}
		ConferenceCount++;
		
		// �������� �̾��� ȸ�ǰ� �����Ƿ� ��
		if (MaxCount == 0) {
			break;
		}

		for (int i = MaxCountIndex + 1; i < N; i++) {
			if (Conference[i].first > Conference[MaxCountIndex].second) {
				NextIndex = i;
				break;
			}
		}
		MaxCount = 0;
	}

	// �Ϸ翡 �ִ� ������ ȸ�Ǽ� ���
	cout << ConferenceCount << endl;
	return 0;
}