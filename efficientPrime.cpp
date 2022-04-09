#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int IsPrime(unsigned int prime)
{
	unsigned i, limit;

	if (prime == 2) return 1; // 2는 소수

	if (prime <= 1 || prime % 2 == 0) return 0; // 1이하 및 2의 배수는 소수x

	limit = (int)sqrt((double)prime);

	for (i = 3; i <= limit; i += 2)
	{
		if (prime % i == 0) return 0; // 양의 제곱근과 홀수의 나머지 비교
	}
	return 1;
}

int main()
{
	int num, testcase;

	printf("Please, give me testcase : ");
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		printf("Please, give me number : ");
		scanf("%d", &num);
		
		if (IsPrime(num)) printf("Yes, %d is prime\n", num);
		else printf("No, %d isn't prime\n", num);
	}

	return 0;
}

const int LIMIT = 100001;
bool prime[LIMIT] = { 1, 1, 0 };

void prime_init()
{
	int sqrtlimit = (int)sqrt((double)LIMIT);

	for (int i = 2; i <= sqrtlimit; i++) // 최대 크기의 양의 제곱근까지만 돌면 된다.
	{
		if (!prime[i])
		{
			for (int j = i * i; j < LIMIT; j = j + i)
			{
				prime[j] = 1; // 2부터 자기자신을 제외한 배수를 모두 1로 넣고 0인 부분이 소수
			}
		}
	}
}