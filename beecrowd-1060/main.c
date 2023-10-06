#include<stdio.h>
int main(){
    int v1,v2,v3,v4,v5,v6,cont;
    cont=0;
    scanf("%d %d %d %d %d %d",&v1,&v2,&v3,&v4,&v5,&v6);
    while (v1>0){
        cont=cont+1;
        v1=0;
    }
    while (v2>0){
        cont=cont+1;
        v2=0;
    }
    while (v3>0){
        cont=cont+1;
        v3=0;
    }
    while (v4>0){
        cont=cont+1;
        v4=0;
    }
    while (v5>0){
        cont=cont+1;
        v5=0;
    }
    while (v6>0){
        cont=cont+1;
        v6=0;
    }
    
    printf("%d valores positivos\n",cont);
    return 0;
}