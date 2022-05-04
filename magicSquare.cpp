#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	/*int oddMagicSquare[9][9], testcase, oddSize;

	scanf("%d", &testcase);

	for (int k = 0; k < testcase; k++)
	{
		scanf("%d", &oddSize);

		for (int i = 0, j = oddSize / 2, num = 1; num <= oddSize * oddSize; num++) // 홀수 마방진
		{
			oddMagicSquare[i][j] = num; // 마방진에 숫자를 넣는다.

			if (num % oddSize == 0)i++;
			else
			{
				i--; j++;

				if (i < 0) i = oddSize - 1; // 행을 벗어나면 반대편 행으로(윗쪽 -> 아랫쪽)
				if (j == oddSize) j = 0; // 열을 벗어나면 반대편 열로 (오른쪽 -> 왼쪽) 
			}
		}

		for (int i = 0; i < oddSize; i++)
		{
			for (int j = 0; j < oddSize; j++)
			{
				printf("%d\t", oddMagicSquare[i][j]);
			}
			printf("\n\n");
		}
	}*/

	int testcase, evenSize, evenArray[400], index, arraySize;
	bool AsendingRow1, AsendingCol1, AsendingRow2, AsendingCol2, isAsending;

	scanf("%d", &testcase);

	while (testcase--)
	{
		scanf("%d", &evenSize); // 4배수 마방진

		arraySize = evenSize * evenSize;

		for (int i = 0; i < evenSize; i++)
		{
			for (int j = 0; j < evenSize; j++)
			{
				/*AsendingRow1 = (j % 4 == 0) || (j % 4 == 3); // 행과 열의 4로 나눈 나머지가 각각 0 또는 3 아니면 1 또는 2인가
				AsendingCol1 = (i % 4 == 0) || (i % 4 == 3);

				AsendingRow2 = (j % 4 == 1) || (j % 4 == 2);
				AsendingCol2 = (i % 4 == 1) || (i % 4 == 2);

				isAsending = (AsendingRow1 && AsendingCol1) || (AsendingRow2 && AsendingCol2);*/

				isAsending = ( (i % 4 == 0) || (i % 4 == 3) ) ^ ( (j % 4 == 0) || (j % 4 == 3) ); // 0 3, 1 2 똑같으며 위의 논리를 간략화하는 방식이다.

				index = i * evenSize + j;

				if (!isAsending) { // xor연산을 해 원래 의도와 반전돼어 나오기에 ! 연산을 한 번 해준다.
					evenArray[index] = index + 1;
				}

				else{
					evenArray[index] = arraySize - index;
				}
			}
		}

		for (int i = 0; i < arraySize; i++)
		{		
			printf("%-5d", evenArray[i]);
			if ((i % evenSize) == (evenSize - 1)) printf("\n");
		}
	}
	return 0;
}