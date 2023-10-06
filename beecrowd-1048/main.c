#include<stdio.h>
int main(){
    float salario,novosalario,reajuste;
    int percentual;
    scanf("%f",&salario);
    if (salario<=400){
        novosalario=1.15*salario;
        reajuste=novosalario-salario;
        percentual=15;
    }
    else if (salario<=800){
        novosalario=1.12*salario;
        reajuste=novosalario-salario;
        percentual=12;
    }
    else if (salario<=1200){
        novosalario=1.1*salario;
        reajuste=novosalario-salario;
        percentual=10;
    }
    else if (salario<=2000){
        novosalario=1.07*salario;
        reajuste=novosalario-salario;
        percentual=7;
    }
    else{
        novosalario=1.04*salario;
        reajuste=novosalario-salario;
        percentual=4;
    }
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %\n",novosalario,reajuste,percentual);

    return 0;
}