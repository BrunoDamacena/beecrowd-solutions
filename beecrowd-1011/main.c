#include<stdio.h>

main(){
	double R,volume;
	
	scanf("%lf",&R);
	volume=(4*3.14159*R*R*R)/3;
	printf("VOLUME = %.3lf\n",volume);

}