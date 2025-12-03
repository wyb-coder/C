#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 求1 ~ N中质数的个数，基本原理，将i的所有倍数全部删除
// primes存质数，is存是否是质数，cnt维护primes上限
int primes[INF], cnt;
bool is[INF];

// 朴素质数筛:将i的所有倍数全部删除
void getPrimes1(int N){
    for(int i = 2; i <= N; i++){
        if(!is[i]){
            primes[cnt++] = i;
            for(int j = i * 2; j <= N; j += i) is[j] = true;
        }
    }
}

// 线性筛法
void getPrimes2(int N){
    for(int i = 2; i <= N; i++){
        if(!is[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= N / i; j++){
            is[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int N;
    cin >> N;
    getPrimes2(N);
    cout << cnt;
}