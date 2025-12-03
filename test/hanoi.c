#include<stdio.h>

// A -> C by B
// from -> to by temp
// 初始输入 A,C,B
// 分为两部分，最大的盘子和剩下n - 1个
// (1)将A的n - 1个由C放到B
// (2)将A剩下的放到C
// (3)将B的n - 1个由A放到C
// 特例:有且仅有一个盘子，直接将A->C
void hanoi(int N, char A, char C, char B){
    if(N == 1){
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    hanoi(N - 1, A, B, C);
    printf("Move disk %d from %c to %c\n", N, A, B);
    hanoi(N - 1, B, C, A);
}

int main(){
    int N;
    scanf("%d", &N);
    hanoi(N, 'A', 'C', 'B');
}