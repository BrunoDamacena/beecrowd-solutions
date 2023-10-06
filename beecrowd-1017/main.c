#include<stdio.h>
main(){
	int veloc,tempo;
	float comb,kml,dist;
	kml=12;
	scanf("%i %i",&tempo,&veloc);
	dist=tempo*veloc;
	comb=dist/kml;
	printf("%.3f\n",comb);
}