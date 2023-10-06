#include<stdio.h>
#include<math.h>

int main(){
	float N;
	int N100,N50,N20,N10,N5,N2,M1,M50,M25,M10,M05,M01;

	scanf("%f",&N);
	N100=N/100;
	N -= N100*100;
	N50=N/50;
	N -= N50*50;
	N20=N/20;
	N -= N20*20;
	N10=N/10;
	N -= N10*10;
	N5=N/5;
	N -= N5*5;
	N2=(N/2);
	N -= N2*2;
	M1=(N/1);
	N -= M1*1;
	M50=(N/0.50);
	N -= M50*0.5;
	M25=(N/0.25);
	N -= M25*0.25;
	M10=(N/0.10);
	N -= M10*0.10;
	M05=(N/0.05);
	N -= M05*0.05;
	M01=round(N/0.01);
	N -= M01*0.01;
	printf("NOTAS:\n");
	printf("%i nota(s) de R$ 100.00\n",N100);
	printf("%i nota(s) de R$ 50.00\n",N50);
	printf("%i nota(s) de R$ 20.00\n",N20);
	printf("%i nota(s) de R$ 10.00\n",N10);
	printf("%i nota(s) de R$ 5.00\n",N5);
	printf("%i nota(s) de R$ 2.00\n",N2);
	printf("MOEDAS:\n");
	printf("%i moeda(s) de R$ 1.00\n",M1);
	printf("%i moeda(s) de R$ 0.50\n",M50);
	printf("%i moeda(s) de R$ 0.25\n",M25);
	printf("%i moeda(s) de R$ 0.10\n",M10);
	printf("%i moeda(s) de R$ 0.05\n",M05);
	printf("%i moeda(s) de R$ 0.01\n",M01);

	return 0;
}