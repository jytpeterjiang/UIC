#include <stdio.h>
#include <math.h>
#include <vcruntime_string.h>

void donut(int A, int B) {
    //float phi = 0, theta = 0, A1 = A, B1 = B, R1 = 1, R2 = 2, K2 = 5, K1 = A1 * 45 / (B1 + 2);
    int d[1760]; //c[1760];
    float i, j, z[1760];
    char b[1760];
    printf("\x1b[2J");
    for (;;) {
        memset(d, 32, 1760);
        memset(z, 0, 7040);
        //memset(c, 0, 7040);
        for (j = 0; 6.28 > j; j += 0.07)
            for (i = 0; 6.28 > i; i += 0.02) {
                float sin_i = sin(i), cos_j = cos(j), sin_A = sin(A), sin_j = sin(j), cos_A = cos(A), cos_j2 = cos_j + 2, mess = 1 / (sin_i * cos_j2 * sin_A + sin_j * cos_A + 5), cos_i = cos(i), cos_B = cos(B), sin_B = sin(B), t = sin_i * cos_j2 * cos_A - sin_j * sin_A;
                int x = 40 + 30 * mess * (cos_i * cos_j2 * cos_B - t * sin_B), y = 12 + 15 * mess * (cos_i * cos_j2 * sin_B + t * cos_B), o = x + 80 * y, N = 8 * ((sin_j * sin_A - sin_i * cos_j * cos_A) * cos_B - sin_i * cos_j2 * sin_A - sin_j * cos_A - cos_i * cos_j * sin_B);
                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o]) {
                    z[o] = mess;
                    d[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                    //c[o] = N > 0 ? 7 : 0;
                }
            }
        printf("\x1b[H");
        for (int k = 0; 1761 > k; k++)
            putchar(k % 80 ? d[k] : 10);
        A += 0.00004;
        B += 0.00002;
    }
}

int main() {
    donut(0, 0); // Adjust parameters A and B for different donut sizes
    return 0;
}