#include <stdio.h>

int get_sum(int array[], int size);

int main()
{
    int i;
    int sum = 0;
    int arrSum;
    int arr[3][6] = {
        {7, 7, 4, 0, 6, 10},
        {4, 7, 5, 1, 9, 2 },
        {4, 9, 0, 6, 5, 0},
    };

    for (i = 0; i < 3; i++) {
        arrSum = get_sum(arr[i], 6);
        sum += arrSum;
        printf("%d번째 줄: %d\n", i + 1, arrSum);
    }
    printf("전체 합계: %d\n", sum);

    return 0;
}

int get_sum(int array[], int size)
{
    int i;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}