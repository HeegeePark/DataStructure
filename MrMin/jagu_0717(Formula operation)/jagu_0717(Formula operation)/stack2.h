// ���� ǥ��� ����
#include <stdio.h>

class stack2 {
public:
	int top;
	int n;
	float* arr = (float*)malloc(sizeof(float)*n);

	bool is_Full();
	bool is_Empty();
	void push(float od);
	float pop();
};