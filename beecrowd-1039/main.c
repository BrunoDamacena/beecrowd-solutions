#include<stdio.h>
#include<math.h>

int main(){
	int R1,X1,Y1,R2,X2,Y2;
	float area;
	while((scanf("%d %d %d %d %d %d",&R1,&X1,&Y1,&R2,&X2,&Y2))!=EOF){
	area=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	if (R1>=area+R2)
		printf("RICO\n");
	else
		printf("MORTO\n");	
	}

	return 0;
}