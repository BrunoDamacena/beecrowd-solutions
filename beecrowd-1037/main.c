#include<stdio.h>

int main(){
    float N;

    scanf("%f",&N);

    if (N>=0 && N<=25)
        printf("Intervalo \[0,25]\n");
    if (N>25 && N<=50)
        printf("Intervalo \(25,50]\n");
    if (N>50 && N<=75)
        printf("Intervalo \(50,75]\n");
    if (N>75 && N<=100)
        printf("Intervalo \(75,100]\n");
    if (N<0)
        printf("Fora de intervalo\n");
    if (N>100)
        printf("Fora de intervalo\n");
}
