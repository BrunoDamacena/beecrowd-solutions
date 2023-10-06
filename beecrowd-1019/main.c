#include<stdio.h>

main(){
	int N,h,m,s;
	scanf("%i",&N);
	h=(N/60)/60;
	m=(N/60)%60;
	s=N%60;
	printf("%i:%i:%i\n",h,m,s);
	return(0);	
}