/*************************************************************************
	> File Name: lg-1440.cpp
	> Author: sly
	> Mail: shulingyun@hrbeu.edu.cn
	> Created Time: 2019年04月14日 星期日 16时24分40秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000000

int q[MAX_N + 5] = {0}, head = 0, tail = 0;
int ind[MAX_N + 5] = {0};

int main() {
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d\n", q[head]);
        while (tail - head && i - ind[head] >= m) head++;//过期出队
        while (tail - head && q[tail - 1] > a) tail--;//队尾元素大于当前插入元素
        q[tail] = a;
        ind[tail] = i;
        tail++;
    }
    return 0;
}

