#include<bits/stdc++.h>
#include<list>
using namespace std;

#define INF 0x3f3f3f3f;


vector<string> str = {"12", "13", "14", "15", "15"};

// C++ 类
class test{
    public:
    int t1, t2;
    test(int a, int b): t1(a), t2(b){}
    // 重载运算符
    bool operator == (const test &temp) const{
        return t1 == temp.t1 && t2 == temp.t2;
    }
};

// Find_if 谓词
bool findIfTest(const string str){
    return str == "13";
}

int main(){
    // Max、Min
    cout << max(1, max(2, 3)) << endl;
    cout << min(1, min(2, 3)) << endl;  
    // For_Each
    for(string i : str) cout << i << " " << endl;
    // Find:返回迭代器
    cout << find(str.begin(), str.end(), "13") - str.begin() << endl;
    // Find_if:返回迭代器
    cout << find_if(str.begin(), str.end(), [](string str){return str == "13";}) - str.begin() << endl;
    cout << find_if(str.begin(), str.end(), findIfTest) - str.begin() << endl;
    // Find_adjacent:第一个重复的元素
    cout << adjacent_find(str.begin(), str.end()) - str.begin() << endl;
    // Binary_search:二分查找、仅限于有序序列
    cout << binary_search(str.begin(), str.end(), "13") << endl;
    // Count:计数、对应元素出现的个数
    cout << count(str.begin(), str.end(), "15") << endl;
    // Count_if:计数、满足条件的个数
    cout << count_if(str.begin(), str.end(), [](string str){return str >= "15";}) << endl;

    // Sort
    sort(str.begin(), str.end());
    sort(str.begin(), str.end(), [](string str1, string str2){return str1 > str2;});
    // Merge:合并
    vector<string> str1 = {"1", "2", "3", "4", "5"}; vector<string> str2 = {"6", "7", "8", "9", "10"};
    vector<string> str3(10);
    merge(str1.begin(), str1.end(), str2.begin(), str2.end(), str3.begin());
    for(string i : str3) cout << i << " " << endl;
    // Reverse:反转
    reverse(str.begin(), str.end());
    // Swap
    swap(str[0], str[1]);
    // Replace
    replace(str.begin(), str.end(), "15", "16");
    // replace_if
    replace_if(str.begin(), str.end(), [](string str){return str == "16";}, "17");

    // Set_intersection:交集、必须有序且同升、降
    set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), str3.begin());
    set_union(str1.begin(), str1.end(), str2.begin(), str2.end(), str3.begin());

    // __gcd:最大公约数
    cout << __gcd(10, 15) << endl;


    // C++ STL
    // Vector:动态(可变)数组
    vector<int> temp(10, 3);
    cout << temp.size() << temp.empty() << temp.front() << temp.back() << endl;
    temp.push_back(4); temp.pop_back();
    temp.clear(); temp.resize(10);
    temp.insert(temp.begin() + 1, 5);
    temp.erase(temp.begin() + 1);
    reverse(temp.begin(), temp.end());

    // Pair:二元组(数组)
    pair<string, int> p = make_pair("1", 1);
    cout << p.first << p.second << endl;
    vector<pair<string, int>> vec;
    sort(vec.begin(), vec.end(), [](pair<string, int> p1, pair<string, int> p2){return p1.second > p2.second;});

    // String:字符串 区分String中find方法与C++find函数
    string s = "12345";
    cout << s.substr(1, 3) << s.find("3") << s.find("3", 2) << endl;
    if(s.find("132") == s.npos); // 寻找不到

    // Queue:队列
    queue<int> q;
    q.push(1); q.pop(); q.front(); q.back(); q.empty(); q.size();
    // 大根堆 
    priority_queue<int> pq;
    // 小根堆 在一亿个数字中找出最大的10000个
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq.push(1); pq.pop(); pq.top(); pq.empty(); pq.size();

    // Stack:栈
    stack<int> st;
    st.push(1); st.pop(); st.top(); st.empty(); st.size();

    // Set:集合、不允许元素重复
    set<int> se;
    se.insert(1); se.erase(1); se.find(1); se.count(1); se.empty(); se.size();
    se.lower_bound(1); se.upper_bound(1); // 返回第一个大于等于、大于的迭代器

    // Map:映射、不允许键重复
    map<int, int> mp;
    mp[1] = 1; mp.erase(1); mp.find(1); mp.count(1); mp.empty(); mp.size();
    mp.lower_bound(1); mp.upper_bound(1); // 返回第一个大于等于、大于的迭代器
    for(auto i : mp) cout << i.first << i.second << endl;

    // List双向链表
    list<int> myList = {1, 2, 3, 4, 5};
    myList.push_back(6);
    myList.pop_back();
    myList.remove(5);
    auto it = next(myList.begin());
    advance(it, 10);
    // 向迭代器所指示前面插入
    myList.insert(it, 10);
}
