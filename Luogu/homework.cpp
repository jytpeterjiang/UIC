#include <stdio.h>

void printTriangle(int n) {
    int arr[n][n];
    int num = 1;
    int i, j, start = 0, end = n - 1;

    // 逆时针填充数组
    while (num <= (n * (n + 1) / 2)) {
        // 从左上到右上
        for (j = start; j <= end && num <= (n * (n + 1) / 2); j++) {
            arr[start][j] = num++;
        }
        // 从右上到右下
        for (i = start + 1; i <= end && num <= (n * (n + 1) / 2); i++) {
            arr[i][end] = num++;
        }
        // 从右下到左下
        for (j = end - 1; j >= start && num <= (n * (n + 1) / 2); j--) {
            arr[end][j] = num++;
        }
        // 从左下到左上
        for (i = end - 1; i > start && num <= (n * (n + 1) / 2); i--) {
            arr[i][start] = num++;
        }
        start++;
        end--;
    }

    // 打印数组
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("请输入数字: ");
    scanf("%d", &n);
    printTriangle(n);
    return 0;
}
