#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;


int main(){
    int N;
    unordered_map<int, int> res;
    cin >> N;
    while(N--){
        char op;
        int num;
        cin >> op >> num;
        if(op == 'I') res[num] = 1;
        else {
            if(res.find(num) != res.end()) cout << "Yes";
            else cout << "No";
        }

    }
}