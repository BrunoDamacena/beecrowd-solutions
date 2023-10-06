#include<stdio.h>
int main(){
    int hi,hf,tempo;
    tempo=0;
    scanf("%d %d",&hi,&hf);
    if (hi==hf)
        printf("O JOGO DUROU 24 HORA(S)\n");
    else {
        while (hi!=hf){
            hi=hi+1;
            if (hi==24)
                hi=0;
            tempo=tempo+1;
        }
    printf("O JOGO DUROU %d HORA(S)\n",tempo);
    }
    return 0;
}