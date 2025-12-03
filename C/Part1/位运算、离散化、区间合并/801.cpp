#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// (1)第K位(0.1.2...)二进制数:
// 右移K位将其放到最右侧再查看最右侧(Num & 1)
// 这也是快速求二进制表示的方法
// for(int i = N; i >= 0; i--) (Num >> i) & 1;

// lowbit 返回Num的最后一位1,树状数组基本操作
// 1010->10   11000->1000 返回二进制数字
// 原理为，Num & -Num(其补码)
int lowbit(int Num){ return Num & (- Num); }
int main(){
    long long int N, A[INF];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++){
        int count = 0;
        while(A[i] != 0) A[i] -= lowbit(A[i]), count++;
        cout << count << " ";
    }
}