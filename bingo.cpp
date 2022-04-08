#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

const int SIZE = 5;
int iBingo[SIZE][SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };

void printBoard()
{
	printf("┌───┬───┬───┬───┬───┐\n"); // 빙고의 제일 윗 줄

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (iBingo[i][j] == 0) printf("│ ■"); // 빙고일 시 네모 출력
			else printf("│%3d", iBingo[i][j]); // 아니면 그대로 출력
		}
		printf("│\n");

		if (i != 4) printf("├───┼───┼───┼───┼───┤\n"); // 맨 마지막 줄이 아니면 출력
	}
	printf("└───┴───┴───┴───┴───┘\n"); // 맨 마지막 줄에 출력
}

void initBoard()
{
	int init[25] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 }, count = 0;
	int random_x, random_y;

	srand(time(NULL));

	random_x = rand() % 25 + 1; 
	random_y = rand() % 25 + 1;

	for (int i = 0; i < 100; i++)
	{
		random_x = rand() % 25; 
		random_y = rand() % 25;
		int tmp = init[random_x];
		init[random_x] = init[random_y];
		init[random_y] = tmp;
	}

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			iBingo[i][j] = init[i * SIZE + j];
}

void endScene()
{
	printf("축하합니다 빙고 3줄 맞췄습니다.\n");
}

int check_x()
{
	int x, bingo = 0;

	for (int i = 0; i < SIZE; i++)
	{
		x = 0;

		for (int j = 0; j < SIZE; j++)
		{
			if (iBingo[i][j] == 0) x++;
		}
		if (x == 5) bingo++;
	}
	return bingo;
}

int check_y()
{
	int y, bingo = 0;

	for (int i = 0; i < SIZE; i++)
	{
		y = 0;

		for (int j = 0; j < SIZE; j++)
		{
			if (iBingo[j][i] == 0) y++;
		}
		if (y == 5) bingo++;
	}
	return bingo;
}

int check_cross()
{
	int z1 = 0, z2 = 0, bingo = 0;

	for (int i = 0, j = 0; i < SIZE; i++, j++)
	{
		if (iBingo[i][j] == 0) z1++;
		if (iBingo[SIZE - 1 - i][i] == 0) z2++;
	}
	if (z1 == 5) bingo++;
	if (z2 == 5) bingo++;

	return bingo;
}

int checkBoard()
{
	int total = 0;

	total += check_x();
	total += check_y();
	total += check_cross();

	return total;
}

void deletNum(int num)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (num == iBingo[i][j])
			{
				iBingo[i][j] = 0; 
				return;
			}
}

int main(void)
{
	int num, count;

	initBoard();
	printBoard();

	while (true)
	{
		printf("정수를 입력하세요(1~25) : ");
		scanf("%d", &num);

		deletNum(num);
		printBoard();
		count = checkBoard();

		if (count >= 3) break;
		else printf("%d줄 완성입니다.\n", count);
	}
	endScene();

	return 0;
}