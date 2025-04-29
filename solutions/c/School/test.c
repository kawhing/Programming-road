#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 声明 findFactors 函数
void findFactors(int num, int factors[], int *count);

// 检查是否是有理根并去重
void findRationalRoots(int coeff[], int degree) {
    int pFactors[100], qFactors[100];
    int pCount = 0, qCount = 0;
    double foundRoots[100];  // 记录已经找到的根
    int foundCount = 0;

    // 找常数项和最高次项的因子
    findFactors(coeff[degree], qFactors, &qCount);  // q 是最高次项的因子
    findFactors(coeff[0], pFactors, &pCount);      // p 是常数项的因子

    // 检查 p/q 是否是根
    for (int i = 0; i < pCount; i++) {
        for (int j = 0; j < qCount; j++) {
            double root = (double)pFactors[i] / qFactors[j];
            double value = 0.0;
            for (int k = 0; k <= degree; k++) {
                value += coeff[k] * pow(root, k);
            }
            if (fabs(value) < 1e-6) {  // 如果 value 接近 0，则认为 root 是一个根
                int isNewRoot = 1;
                for (int k = 0; k < foundCount; k++) {
                    if (fabs(foundRoots[k] - root) < 1e-6) {
                        isNewRoot = 0;
                        break;
                    }
                }
                if (isNewRoot) {
                    foundRoots[foundCount++] = root;
                    printf("有理根为: %.2f\n", root);
                }
            }
        }
    }
}

// 找因子的函数实现
void findFactors(int num, int factors[], int *count) {
    *count = 0;
    for (int i = 1; i <= abs(num); i++) {
        if (num % i == 0) {
            factors[(*count)++] = i;
            factors[(*count)++] = -i;
        }
    }
}

int main() {
    int degree;
    printf("输入多项式的最高次数: ");
    scanf("%d", &degree);

    int coeff[degree + 1];
    printf("输入多项式的系数 (从常数项到最高次项):\n");
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &coeff[i]);
    }

    findRationalRoots(coeff, degree);

    return 0;
}