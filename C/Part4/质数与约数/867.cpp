#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 分解质因数，6 = (2^1) * (3^1)
// 8 = (2^3)
void div(int num){
    for(int i = 2; i <= num / i; i++){
        if(num % i == 0){
            int sum = 0;
            while(num % i == 0) num /= i, sum++;
            cout << i << " " << sum << endl;
        }
    }
    if(num > 1) cout << num  << " " << 1 << endl;
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        int temp;
        cin >> temp;
        div(temp);    
    }
}