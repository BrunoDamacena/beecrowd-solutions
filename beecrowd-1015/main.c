#include<stdio.h>
#include<math.h>
main(){
	float x1,x2,y1,y2,distancia;
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	distancia=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	printf("%.4f\n",distancia);

}