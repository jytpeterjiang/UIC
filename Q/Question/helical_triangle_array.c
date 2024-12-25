#include <stdio.h>
#include <stdlib.h>

// 打印二维数组 ar 的内容，n 表示数组的大小
void Print_Ar(int **br, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 如果元素不为 0，则打印该元素；否则打印三个空格
            if (br[i][j] != 0) {
                printf("%3d", br[i][j]);
            } else {
                printf("   "); // 使用空格代替0
            }
        }
        printf("\n"); // 每行结束后换行
    }
    printf("\n"); // 打印完所有行后加一个空行
}

int main() {
    int n;
    // 提示用户输入螺旋三角形的边长 n
    printf("请输入螺旋三角形的边长 n: ");
    scanf("%d", &n);

    // 检查输入的边长是否有效
    if (n <= 0) {
        printf("螺旋三角形的边长必须大于0。\n");
        return 1;
    }

    // 动态分配内存用于存储二维数组 ar
    int **ar = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        ar[i] = (int *)malloc(n * sizeof(int));
        // 初始化所有元素为 0
        for (int j = 0; j < n; j++) {
            ar[i][j] = 0;
        }
    }

    // 定义边界变量
    int Left = 0, Right = n - 1, Up = 0, Down = n - 1;
    int num = 1; // 从 1 开始填充数组

    // 填充螺旋三角形
    while (Left <= Right && Up <= Down) {
        // 从上到下填充最左边的一列
        for (int i = Up; i <= Down; i++) {
            ar[i][Left] = num++;
        }
        // 从左到右填充最下面的一行（除去最左边的一个元素）
        for (int i = Left + 1; i <= Right; i++) {
            ar[Down][i] = num++;
        }
        // 从右下角向左上角填充对角线（如果存在）
        for (int i = Down - 1, j = Right - 1; i > Up && j > Left; i--, j--) {
            ar[i][j] = num++;
        }
        // 更新边界变量，缩小范围
        Left++, Right -= 2, Up += 2, Down--;
    }

    // 打印生成的螺旋三角形
    Print_Ar(ar, n);

    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        free(ar[i]);
    }
    free(ar);

    return 0;
}