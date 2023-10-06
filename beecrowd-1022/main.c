#include<stdio.h>
#include<math.h>

int MDC(int num1, int num2){
    if (num2 == 0)
      return num1;
    else
      return MDC(num2, num1%num2);
}


void TDA(){
    int N1,N2,D1,D2,NP,DP,NF,DF,mdc;
    char op,div;
    scanf("%d %c %d %c %d %c %d",&N1,&div,&D1,&op,&N2,&div,&D2);
    if(op=='+'){
        NP = (N1*D2)+(N2*D1);
        DP = D1*D2;
        NF=NP;
        DF=DP;

    }
    else if(op=='-'){
       NP =  (N1*D2 - N2*D1); 
       DP = (D1*D2);
    }
    else if(op=='*'){
        NP = (N1*N2);
        DP = (D1*D2);

    }
    else if(op=='/'){
        NP = (N1*D2);
        DP = (N2*D1);

    }
    mdc=abs(MDC(NP,DP));
    NF=NP/mdc;
    DF=DP/mdc;
    printf("%d/%d = %d/%d\n",NP,DP,NF,DF);
}

int main(){
    int qtd;
    for(scanf("%d",&qtd);qtd>0;qtd--){
        TDA();
    }
    return 0;
}