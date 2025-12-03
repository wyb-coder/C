#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 数学计算的是中缀表达式，是中序遍历的二叉树但不带括号
// 对这颗二叉树后序遍历得到后缀表达式就无需括号也能得到运算顺序
// 所有的叶节点都是数字、其他节点都是运算符
stack<int> num;
stack<char> op;
void calculate(){
    // 注意弹出顺序
    int res;
    int num2 = num.top(); num.pop();
    int num1 = num.top(); num.pop();
    char oper = op.top(); op.pop();
    if(oper == '+') res = num1 + num2;
    else if(oper == '-') res = num1 - num2;
    else if(oper == '*') res = num1 * num2;
    else res = num1 / num2;
    num.push(res);
}

int main(){
    // 哈希表，快速查询优先级，可直接按左侧符号访问
    unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        auto temp = str[i];
        if(isdigit(temp)){
            int j = i, allNum = 0;
            while(j < str.size() && isdigit(str[j]))
                allNum = allNum * 10 + (str[j++] - '0');
            i = j - 1;
            num.push(allNum);
        } 
        else if (temp == '(') op.push(temp);
        else if (temp == ')'){
            while(op.top() != '(') calculate();
            op.pop();
        } 
        else {
            // 优先级里没有括号，因此特判，栈中不会存在右括号
            while(op.size() && op.top() != '(' && (pr[op.top()] >= pr[temp])) calculate();
            op.push(temp);
        }
    }
    while(op.size()) calculate();
    cout << num.top();
}