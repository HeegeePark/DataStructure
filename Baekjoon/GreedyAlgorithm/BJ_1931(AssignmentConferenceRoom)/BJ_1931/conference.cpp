#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > Conference;		// ȸ�� ������ ���Ϳ� ����
vector<pair<int, int> > SortedConference;
int main() {
	int N;
	int ConferenceCount = 0; // ����ϰ��� �ϴ� �Ϸ� �ִ� ȸ�Ǽ�
	int MinEnd = 999;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		Conference.push_back(make_pair(start, end));
	}
	
	// ȸ�� ������ ������������ ���� ( ���߿� ����ð� �������� ������ �� ���۽ð��� �� ������ �ö󰡴°� ����)
	sort(Conference.begin(), Conference.end());
	
	//Test
	sort(Conference.end(),Conference.begin());
	int i;
	for (i = 0; i < N; i++) {
		cout << Conference[i] << endl;

	}


	//// ȸ�� ����ð� ���� �ٽ� ����
	//for (int i = 0; i < N; i++) {
	//	int start, end;
	//	if (Conference[i].second < MinEnd) {
	//		start = Conference[i].first;
	//		end = Conference[i].second;
	//		SortedConference.push_back(make_pair(start, end));
	//	}
	//}



	

	//// �� ȸ�ǰ� ������ �̾ �� �� �ִ� ȸ������ �Ѱ��� �迭�� ����
	//int* CountNextPoss = new int[N];
	//for (int i = 0; i < N; i++) {
	//	CountNextPoss[i] = 0;
	//}
	//int MaxCount = 0;
	//int MaxCountIndex = 0;
	//int NextIndex = 0;

	//
	//for (int i = 0; i < N; i++) {
	//	for (int j = i + 1; j < N; j++) {
	//		if (Conference[i].second < Conference[j].first) {
	//			CountNextPoss[i]++;
	//		}
	//	}
	//	if (CountNextPoss[i] > MaxCount) {
	//		MaxCount = CountNextPoss[i];
	//		MaxCountIndex = i;
	//	}
	//}
	////  �Ѱ���(�迭�� value)�� ���� ũ�� ȸ�ǽð��� ���� �ε����� ȸ������(MaxCountIndex)�� ���ϰ�(ȸ�Ǽ�++), 
	//// ���� ȸ�� �������� ������ �ε��� �� value�� ���� ū �ε��� ����
	//// �� ������ �ε����� ���� �� ������ �ε����� �����ϰų� �Ѿ������ �ݺ�
	//while (NextIndex < N ) {
	//	for (int i = NextIndex; i < N; i++) {
	//		if (CountNextPoss[i] > MaxCount) {
	//			MaxCount = CountNextPoss[i];
	//			MaxCountIndex = i;
	//		}
	//	}
	//	ConferenceCount++;
	//	
	//	// �������� �̾��� ȸ�ǰ� �����Ƿ� ��
	//	if (MaxCount == 0) {
	//		break;
	//	}

	//	for (int i = MaxCountIndex + 1; i < N; i++) {
	//		if (Conference[i].first > Conference[MaxCountIndex].second) {
	//			NextIndex = i;
	//			break;
	//		}
	//	}
	//	MaxCount = 0;
	//}

	// �Ϸ翡 �ִ� ������ ȸ�Ǽ� ���
	cout << ConferenceCount << endl;
	return 0;
}