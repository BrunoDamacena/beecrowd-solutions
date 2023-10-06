#include<stdio.h>
int main(){
    float salario,IR1,IR2,IR3;
    scanf("%f",&salario);
    if (salario<=2000)
        printf("Isento\n");
    else if (salario<=3000){
        salario=salario-2000;
        IR1=salario*0.08;
        printf("R$ %.2f\n",IR1);    
    }
    else if (salario<=4500){
        salario=salario-2000;
        IR1=1000*0.08;
        salario=salario-1000;
        IR2=salario*0.18;
        printf("R$ %.2f\n",IR1+IR2);
    }
    else{
        salario=salario-2000;
        IR1=1000*0.08;
        salario=salario-1000;
        IR2=1500*0.18;
        salario=salario-1500;
        IR3=salario*0.28;
        printf("R$ %.2f\n",IR1+IR2+IR3);
    }
    
    return 0;
}