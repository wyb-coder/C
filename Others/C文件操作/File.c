#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
#define INF 10010

// 文件打开、循环读入
int main(){
    char temp, buffer[256];
    FILE *fp1, *fp2;
    // 打开文件，失败返回NULL，而EOF用于判断文件结尾
    if(NULL == (fp1 = fopen("test.txt", "r+"))){
        printf("Error in open file");
        return 0;
    }

    while(EOF != (temp = fgetc(fp1))){
        printf("%c", temp);
    }
    printf("\n--------------\n");
    // 重定位到文件头 rewind(fp1) 等价于 fseek(fp1, 0, 0);;    
    // fseek(fp1, X, Y); Y有三个取值，是内置宏 
    // SEEK_SET文件头；SEEK_CUR当前位置；SEEK_END文件结尾
    fseek(fp1, 0, SEEK_SET);
    // EOF 是文件结束符，一个符号。而fgets读入一行，失败是NULL
    while(NULL != (fgets(buffer, sizeof(buffer), fp1)))
        printf("%s", buffer);
    
    rewind(fp1);
    // 文件向buffer输入。实际是读入文件
    fscanf(fp1, "%s", &buffer); printf("%s", buffer);
}