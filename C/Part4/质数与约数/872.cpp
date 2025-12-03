#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f, mod = 1e9 + 7;

// 最大公约数 (A, B) == (B, A mod B)
int gcd(int A, int B){
    if(B != 0) return gcd(B, A % B);
    else return A;
}
int main(){
    int N;
    cin >> N;
    while(N--){
        int A, B;
        cin >> A >> B;
        cout << gcd(A, B) << endl;
    }
}