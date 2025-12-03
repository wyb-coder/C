#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f, mod = 1e9 + 7;

unordered_map<int, int> primes;
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
    long long int res = 1, temp = 1;;
    for(auto prime : primes){
        int p = prime.first, t = prime.second;
        while(t--) temp = (temp * p + 1) % mod;
        res = res * temp % mod;
        temp = 1;
    }
    cout << res;
}