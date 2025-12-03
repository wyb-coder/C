#include<bits/stdc++.h>
using namespace std;
const int INF = 10010, MX  = 0x3f3f3f3f;

int cmp(string str1, string str2){
    return str1 > str2;
}

int main(){
    string str1 = "11112222", str2 = "22223333";
    unordered_map<char, int> cnt;
    set<char> res;
    for(int i = 0; i < str1.size(); i++) cnt[str1[i]] = 1;
    for(int i = 0; i < str2.size(); i++){
        if(cnt[str2[i]]) res.insert(str2[i]); 
    }
    for(auto s : cnt) cout << s.first << endl;
}
