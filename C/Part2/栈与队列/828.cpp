#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

int main(){
    stack<int> res;
    int M;
    cin >> M;
    while(M--){
        string str;
        cin >> str;
        int num;
        if(str == "push"){
            cin >> num;
            res.push(num);
        } else if (str == "pop"){
            res.pop();
        } else if (str == "empty"){
            if(res.empty()) cout << "YES" << endl;
            else cout << "NO" << endl; 
        } else {
            cout << res.top() << endl;
        }
    }
}