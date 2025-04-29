#include <stdio.h>

// 合并两个有序数组的函数
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    // 循环比较两个数组元素的大小
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i]; // 将较小的元素添加到结果数组中
            i++; // 移动第一个数组的索引
        } else {
            result[k] = arr2[j];
            j++; // 移动第二个数组的索引
        }
        k++; // 移动结果数组的索引
    }

    // 将第一个数组剩余的元素添加到结果数组中
    while (i < n1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    // 将第二个数组剩余的元素添加到结果数组中
    while (j < n2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {1, 3, 5, 0, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int result[n1 + n2]; // 创建结果数组

    mergeArrays(arr1, n1, arr2, n2, result); // 调用合并函数

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", result[i]); // 打印合并后的数组
    }

    return 0;
}