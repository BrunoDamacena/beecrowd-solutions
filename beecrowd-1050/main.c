#include<stdio.h>
int main(){
    int codigo;
    scanf("%d",&codigo);
    if (codigo==61)
        printf("Brasilia\n");
    else if (codigo==71)
        printf("Salvador\n");
    else if (codigo==11)
        printf("Sao Paulo\n");
    else if (codigo==21)
        printf("Rio de Janeiro\n");
    else if (codigo==32)
        printf("Juiz de Fora\n");
    else if (codigo==19)
        printf("Campinas\n");
    else if (codigo==27)
        printf("Vitoria\n");
    else if (codigo==31)
        printf("Belo Horizonte\n");    
    else
        printf("DDD nao cadastrado\n");
    
    return 0;
}