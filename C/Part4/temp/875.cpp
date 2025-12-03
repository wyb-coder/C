#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 快速幂。快速求(A^K mod P),预处理 A^(2^0) ... A^(2^logK)
// 其中 D1 = A^(2^0) D2 = A^(2^1) D3 = A^(2^2) 则Dn = D(n-1)^2
// 将A^K 拆解成 A^(2^X1) ... A^(2^Xn)
// 则将K 拆解为 (2^X1) ... ^(2^Xn) 这显然可以用二进制表示
// 则logK直接表示为K的二进制位数
typedef long long int LL;
LL quickPow(LL A, LL B, LL P){
    LL res = 1;
    while(B){
        // A的次方隐藏在了A的变化中
        if(B & 1) res = res * A % P;
        A = A * A % P;
        B = B >> 1;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        LL A, B, P;
        scanf("%lld %lld %lld", &A, &B, &P);
        printf("%lld\n", quickPow(A, B ,P));
    }
}