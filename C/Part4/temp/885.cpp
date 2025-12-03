#include<bits/stdc++.h>
using namespace std;
const int INF = 2010, MX = 0x3f3f3f3f;

int C[INF][INF], N, mod = 1e9 + 7;
// 1.当A, B数值都不是很大时，利用递推，递推次数较少
// C(B, A) = C(B, A - 1) + C(B - 1, A - 1)
void calCNum1(){
    for(int i = 0; i < INF; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

// A, B很大时，预处理递推
void calCNum2(){
    for(int i = 0; i < INF; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int main(){
    cin >> N;
    calCNum1();
    while(N--){
        int A, B;
        cin >> A >> B;
        cout << C[A][B] << endl;
    }
}