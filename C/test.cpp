#include<bits/stdc++.h>
using namespace std;

const int INF = 10010;
const int MX = 0x3f3f3f3f;

typedef struct Student{
    int num;
    int computer;
}Stu;
Stu s[5] = {{101, 75}, {103, 80}, {104, 85}, {106, 90}, {102, 88}};

int cmp(const void *A, const void *B){
    return (*(Student*)A).computer - (*(Student*)B).computer;
}

int main(){
    qsort(s, 5, sizeof(Student), cmp);
    for(int i = 0; i < 5; i++){
        cout << s[i].num << " " << s[i].computer << endl;
    }
}
