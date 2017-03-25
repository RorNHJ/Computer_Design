#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int checkOperation(char* a,char* b,char* oper);
void Print(int a, int b, char* oper);
int searchNumber(char* a,int count);
int main(void){

    char a[100]; 
    char b[100]; 
    char oper[10];
    int i;
    int result = 0;
    int total_result =0;

    while(1){

       fgets(a,sizeof(a),stdin);
       a[strlen(a)-1]=0;
       if(!strcmp(a,"q")|| !strcmp(a,"Q")){
          printf("종료합니다.여태까지 구한 결과는 다음과 같습니다.\n");
          printf("%d\n",total_result);
         
          exit(0);
       }
       fgets(oper, sizeof(oper), stdin);
       oper[strlen(oper)-1]=0;
       fgets(b,sizeof(b),stdin);
       b[strlen(b)-1]=0;
       result = checkOperation(a,b,oper);
       printf("= %d\n",result);
       total_result = total_result + result;
    }
}
int  checkOperation(char* a, char* b,char* oper){

    int m_a,m_b;
    if(!strcmp(oper,"+")){
       m_a= searchNumber(a,4);
       m_b= searchNumber(b,4);
       Print(m_a,m_b,oper);
       return m_a+m_b;
    }else if(!strcmp(oper,"-")){
       m_a= searchNumber(a,4);
       m_b= searchNumber(b,4);
       Print(m_a,m_b,oper);
       return m_a-m_b;
    }else if(!strcmp(oper,"*")){
       m_a= searchNumber(a,3);
       m_b= searchNumber(b,3);
       Print(m_a,m_b,oper);
       return m_a*m_b;
    }else if(!strcmp(oper,"/")){
       m_a= searchNumber(a,3);
       m_b= searchNumber(b,3);
       Print(m_a,m_b,oper);
       return m_a/m_b;
    }
    else if(!strcmp(oper,"%")){
       m_a= searchNumber(a,5);
       m_b= searchNumber(b,5);
       Print(m_a,m_b,oper);
       return m_a%m_b;
    }
    
    
}
int searchNumber(char* a, int count){
    int i=0,j,k=0;
    int sum =0;
    int max;
    char temp;
    int num[128];
    while(*a){
      
        if(isdigit(*a)){
            temp = *a;
            if(i==0 && atoi(&temp)==0){
                a++;
                continue;
            }
            num[i++] = atoi(&temp); 
            a++;
        }
        else a++;

        if(i>=count) break;
    }
    max = (int)pow(10,count);
    for(j=1; j<max; j=j*10){
            i = i-1;
            if(i<0) break;
            sum = num[i]*j +sum;
    }
   return sum;       
}

void Print(int a, int b, char* oper){

       printf("%d ",a);
       printf("%s ",oper);
       printf("%d ",b);
}
