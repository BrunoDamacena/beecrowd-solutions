#include <stdio.h>
	int main (){  
	int x,y,z;
	scanf ("%d %d %d",&x,&y,&z);
	if(x>y)
		if (x>z)
		printf("%i eh o maior\n",x);
	
	if(y>x)
		if(y>z)
		printf("%i eh o maior\n",y);
	
	if(z>x)
		if(z>y)
		printf("%i eh o maior\n",z);
	
	return(0);
}