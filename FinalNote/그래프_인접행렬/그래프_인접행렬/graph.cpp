#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int MAX = 10;

// 5 6		(������ ����, ������ ����)
// 1 2		1 ---  2
// 1 3		| \   /
// 1 4		|  \ /
// 2 4		3   4 --- 5
// 4 5		�� ------/
// 3 5

// Q1. ���� X�� Y�� ������ �Ǿ� �ִ°�? (YES/NO)
// Q2. ���� X�� ������ �Ǿ� �ִ� ��� ������ ����϶�.

bool isConnected(int myGraph[MAX][MAX], int x, int y) {
	// x�� y�� ������ �Ǿ� ������ true, �ƴϸ� false
	return myGraph[x][y] == 1 ? true : false;
}

void getAdj(int myGraph[MAX][MAX], int n, int x) {
	// adjacent node
	for (int i = 1; i <= n; i++) {
		if (myGraph[x][i] == 1) cout << i << " ";
	}
	cout << endl;
}

int main() {
	int n, m;		// n: ������ ����, m: ������ ����
	int myGraph[MAX][MAX] = { 0, };

	cin >> n >> m;

	for (int i = 0; i < m; i++) {		// ������ ������ŭ
		int a, b;

		cin >> a >> b;
		myGraph[a][b] = 1;
		myGraph[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << myGraph[i][j] << " ";
		}
		printf("\n");
	}

	// isConnected O(1)
	
	cout << (int)isConnected(myGraph, 1, 2) << endl;
	cout << (int)isConnected(myGraph, 1, 5) << endl;
	cout << (int)isConnected(myGraph, 3, 5) << endl;

	// getAdj O(n)
	
	getAdj(myGraph, n, 2);
	getAdj(myGraph, n, 4);


	system("pause");
	return 0;
}