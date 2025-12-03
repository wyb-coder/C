#include<bits/stdc++.h>
using namespace std;

const int INF = 100010, P = 131;
// 字符串哈希,原理是假设字符串是P进制数字,假设没有冲突
// 提前存储P的次方,h[]存储最左侧->目标为序的字串的哈希
// 根据进制数运算，left、right字串，将left左侧的字串抬高(×P的次方倍)再减
typedef unsigned long long ULL;
ULL h[INF] = {0}, p[INF];

ULL getHash(int left, int right){
    return h[right] - h[left - 1] * p[right - left + 1];
}

int main(){
    int N, M;
    cin >> N >> M;
    string str;
    cin >> str;
    str = "0" + str; p[0] = 1;   
    for(int i = 1; i <= N; i++){
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    while(M--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(getHash(l1, r1) == getHash(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}