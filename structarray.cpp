#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct person
{
    char name[15];
    int number;
    char address[15];
}p[100];

int main()
{
    int n;

    person tmp;

    printf("주소 정렬할 인원을 입력해주세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s", p[i].name, &p[i].number, p[i].address);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(p[i].address, p[j].address) > 0)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    printf("주소 정렬 결과입니다.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %s\n", p[i].name, p[i].number, p[i].address);
    }
}