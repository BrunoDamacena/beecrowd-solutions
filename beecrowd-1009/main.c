#include <stdio.h>

main(){
	char nome;
	double sal, vend, total;

	scanf("%s %lf %lf",&nome,&sal,&vend);
	total=sal+0.15*vend;

	printf("TOTAL = R$ %.2lf\n",total);
}