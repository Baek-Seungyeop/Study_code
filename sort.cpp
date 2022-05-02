#include <stdio.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#pragma warning(disable:4996)

void bubble_sort(int list[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) { // 0 ~ (i-1)까지 반복
        for (j = 0; j < i; j++) { // 한 회전에 제일 큰 값이 마지막 위치로 감으로 j < i
            if (list[j] < list[j + 1]) { // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int list[], int n) {
    int i, j, least, temp;
   
    for (i = 0; i < n - 1; i++) { // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
        least = i;

        for (j = i + 1; j < n; j++) { // 최솟값을 탐색한다.
            if (list[j] < list[least])
                least = j;
        }

        if (i != least) { // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
            SWAP(list[i], list[least], temp);
        }
    }
}

void insertion_sort(int list[], int n) {
    int i, j, key;
   
    for (i = 1; i < n; i++) { // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
        }

        list[j + 1] = key;
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;

    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
        // j 값은 first 이상이어야 하고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
        for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
            list[j + gap] = list[j]; // 레코드를 gap만큼 오른쪽으로 이동
        }

        list[j + gap] = key;
    }
}

// 셸 정렬
void shell_sort(int list[], int n) {
    int i, gap;

    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) {
            gap++; // gap을 홀수로 만든다.
        }

            // 부분 리스트의 개수는 gap과 같다.
            for (i = 0; i < gap; i++) {
                // 부분 리스트에 대한 삽입 정렬 수행
                inc_insertion_sort(list, i, n - 1, gap);
            }
    }
}

// 1. 피벗을 기준으로 2개의 부분 리스트로 나눈다.
// 2. 피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
/* 2개의 비균등 배열 list[left...pivot-1]와 list[pivot+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

    /* low와 high가 교차할 때까지 반복(low<high) */
    do {
        /* list[low]가 피벗보다 작으면 계속 low를 증가 */
        do {
            low++; // low는 left+1 에서 시작
        } while (low <= right && list[low] < pivot);

        /* list[high]가 피벗보다 크면 계속 high를 감소 */
        do {
            high--; //high는 right 에서 시작
        } while (high >= left && list[high] > pivot);

        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if (low < high) {
            SWAP(list[low], list[high], temp);
        }
    } while (low < high);

    // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    SWAP(list[left], list[high], temp);

    // 피벗의 위치인 high를 반환
    return high;
}
// 퀵 정렬
void quick_sort(int list[], int left, int right) {

    /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
    if (left < right) {
        // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
        int q = partition(list, left, right); // q: 피벗의 위치

        // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_sort(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
        quick_sort(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    }
}
#define MAX_SIZE 8
int sorted[MAX_SIZE]; // 추가적인 공간이 필요

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* 분할 정렬된 list의 합병 */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    // 남아 있는 값들을 일괄 복사
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
        merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}