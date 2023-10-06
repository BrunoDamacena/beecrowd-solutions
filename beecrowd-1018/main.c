#include <stdio.h>

main(){
	int N,N100,N50,N20,N10,N5,N2,N1;
	scanf("%i",&N);
	
	N100=N/100;
	N50=(N%100)/50;
	N20=(((N%100)%50)/20);
	N10=((((N%100)%50)%20)/10);
	N5=(((((N%100)%50)%20)%10)/5);
	N2=((((((N%100)%50)%20)%10)%5)/2);
	N1=(((((((N%100)%50)%20)%10)%5)%2)/1);
	
	printf("%i\n",N);
	printf("%i nota(s) de R$ 100,00\n",N100);
	printf("%i nota(s) de R$ 50,00\n",N50);
	printf("%i nota(s) de R$ 20,00\n",N20);
	printf("%i nota(s) de R$ 10,00\n",N10);
	printf("%i nota(s) de R$ 5,00\n",N5);
	printf("%i nota(s) de R$ 2,00\n",N2);
	printf("%i nota(s) de R$ 1,00\n",N1);
	
		
	return(0);
}