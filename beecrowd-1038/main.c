#include<stdio.h>

int main(){
    int num,quant;
    float preco,precoq;
    scanf("%i %i",&num,&quant);
    if (num==1)
        preco=4;
    else if (num==2)
        preco=4.5;
    else if (num==3)
        preco=5;
    else if (num==4)
        preco=2;
    else if (num==5)
        preco=1.5;
    precoq=preco*quant;
    printf("Total: R$ %.2f\n",precoq);

    return(0);
}
