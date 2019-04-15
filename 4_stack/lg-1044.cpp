/*************************************************************************
	> File Name: lg-1044.cpp
	> Author: sly
	> Mail: shulingyun@hrbeu.edu.cn
	> Created Time: 2019年04月14日 星期日 15时52分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    int f[30];
    f[0] = 1, f[1] = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            f[i] += f[j] * f[i - j -1];
            
        }
    }
    printf("f[%d] = %d\n", n, f[n]);
    return 0;
}
