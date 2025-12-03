#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 约数个数、约数之和
// 分解质因数:N = (P1 ^ X1) * ... * (Pn ^ Xn)
// 用分解质因数后的公式相乘
// 乘积的约数个数 = (X1 + 1) * ... * (Xn + 1)
// 约数之和 = (P1 ^ 0 + ... + P1 ^ X1) * ... * (Pn ^ 0 + ... + Pn ^ Xn)
unordered_map<int, int> primes;
const int mod = 1e9 + 7;
int main(){
    int N;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        for(int i = 2; i <= num / i; i++){
            while(num % i == 0){
                num /= i;
                primes[i]++;
            }
        }
        if(num > 1) primes[num]++;
    }
    long long int res = 1;
    for(auto prime : primes) res = res * (prime.second + 1) % mod;
    cout << res;
}