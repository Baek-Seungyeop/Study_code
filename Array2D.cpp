#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int array[30][30] = { 0 }, arraySize, index, countNum; // 배열 크기 n을 받아 대각선으로 증가하는 n x n배열을 구현하자.

	scanf("%d", &arraySize);

	countNum = 0; // 최솟값으로 설정

	for (int i = 0; i < arraySize; i++) // 좌상단, 증가하면서 채운다
	{
		for (int j = 0; j <= i; j++)
		{
			index = i;
			countNum++;
			array[index - j][j] = countNum;
		}
	}

	countNum = arraySize * arraySize; // 최댓값으로 설정

	for (int i = 0; i < arraySize - 1; i++) // 우하단, 감소하면서 채운다.
	{
		for (int j = 0; j <= i; j++)
		{
			index = i;
			array[arraySize - 1 - (index - j)][arraySize - 1 - j] = countNum;
			countNum--;
		}
	}

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}