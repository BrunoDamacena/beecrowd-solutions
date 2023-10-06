#include<stdio.h>

main(){
	int idade,anos,meses,dias;
	scanf("%i",&idade);
	anos=idade/365;
	meses=(idade%365)/30;
	dias=(idade%365)%30;

	printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n",anos,meses,dias);

	return(0);
}