#include<stdio.h>
#define INF 10010
const int MX  = 0x3f3f3f3f;

int main(){
    int N, Max = -MX, sum = 0, A[INF], B[INF], AK = 0, BK = 0;
    double avg = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        if(num % 2 == 0) B[BK++] = num;
        else A[AK++] = num;
        sum += num;
        if(Max < num) Max = num;
    }
    for(int i = 0; i < AK; i++) printf("%d ", A[i]);
    for(int i = 0; i < BK; i++) printf("%d ", B[i]);
    printf("\n");
    avg = 1.0 * sum / N;
    printf("%d %d %d %.2f", AK, BK, Max, avg);


}
