#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     
     int positives = 0;
     float sumOfPositives = 0;
     
     for(int i = 0; i < 6; i++) {
         float num;
         scanf("%f", &num);
         if (num > 0) {
             positives++;
             sumOfPositives += num;
         }
     }
     
     float average = sumOfPositives / positives;
     
     printf("%d valores positivos\n%.1f\n", 
        positives, 
        average
    );
 
    return 0;
}