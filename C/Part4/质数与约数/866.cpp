#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 质数: 大于1,且能且仅能被1与其本身整除
// 定理 if (d % N == 0) => (d / N % N == 0)
// 例: 3、4与2、6都是12的约数
// 则所有约数都是成对出现的，因此枚举较小的那个。因此d <= sqrt(N)
// sqrt较慢。d <= sqrt(N) == d^2 <= N == d <= N / d
bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i <= num / i; i++){
        if(num % i == 0) return false;
    }
    return true;
}
int main(){
    int N;
    cin >> N;
    while(N--){
        int temp;
        cin >> temp;
        if(isPrime(temp)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}