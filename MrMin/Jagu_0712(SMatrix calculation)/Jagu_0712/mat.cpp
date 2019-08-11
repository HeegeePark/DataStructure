#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int n;
extern int** matA;
extern int** matB;
extern int** matC;

// 1. load
void load(FILE* fpA, FILE* fpB) {
	
	// fp�� ����� file���� nxn ũ���� ��� ����
	int i, j, cnt = 0;
	char buf_a[3000], buf_b[3000];
	bool is_start = true;
	

	while (fgets(buf_a, 3000, fpA) != NULL && fgets(buf_b, 3000, fpB) != NULL ) {
		if (is_start) {
			// ��� ũ�� ���ϱ�
			sscanf(buf_a, "%d", &n);

			// ��� ���� �Ҵ�
			matA = (int**)malloc(sizeof(int*) * n);
			for (i = 0; i < n; i++) {
				matA[i] = (int*)malloc(sizeof(int) * n);
			}
			matB = (int**)malloc(sizeof(int*) * n);
			for (i = 0; i < n; i++) {
				matB[i] = (int*)malloc(sizeof(int) * n);
			}
		
			// ��� �ʱ�ȭ
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					matA[i][j] = { 0 };
					matB[i][j] = { 0 };
				}
			}
			is_start = false;
		}
		else {
			// buf�� ������ ��Ŀ� �ֱ�
			char* ptr = strtok(buf_a, " ");
			j = 0;
			while (ptr != NULL && cnt < n) {
				matA[cnt][j++] = atoi(ptr);
				ptr = strtok(NULL, " ");
			}
			ptr = strtok(buf_b, " ");
			j = 0;
			while (ptr != NULL && cnt < n) {
				matB[cnt][j++] = atoi(ptr);
				ptr = strtok(NULL, " ");
			}

			cnt++;
		}		
	}	
	fclose(fpA);
	fclose(fpB);

	// test
	//printf("A matrix\n");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%d", matA[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//printf("B matrix\n");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%d", matB[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	
}

// 2. transpose
int** transpose(int n, int** mat) {
	matC = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		matC[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matC[i][j] = mat[j][i];
		}
	}

	// test
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", matC[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	return matC;
}

// 3. add
int** add(int n, int** matA, int** matB) {
	matC = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		matC[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}

	// test
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", matC[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	return matC;
}

// 4. multiply
int** multiply(int n, int** matA, int** matB) {
	int sum = 0;
	matC = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		matC[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += matA[i][k] * matB[k][j];
			}
			matC[i][j] = sum;
		}		
	}

	// test
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", matC[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	return matC;
}