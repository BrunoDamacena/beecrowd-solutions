#include<stdio.h>
int main(){
    int hi,mi,hf,mf,tempoh,tempom;
    tempoh=0;
    tempom=0;
    scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
    if (hi==hf && mi==mf)
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    else {
        while (mi!=mf){
            mi=mi+1;
            if (mi==60){
                mi=0;
                tempoh=tempoh-1;
            }
            tempom=tempom+1;
        }
        while (hi!=hf){
            hi=hi+1;
            if (hi==24)
                hi=0;
            tempoh=tempoh+1;
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",tempoh,tempom);
    }


    return 0;
}