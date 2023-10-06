#include<stdio.h>
#include<ctype.h>
int main(){
	int N,A,B,result;
	char letra;
	for (scanf("%d",&N);N>0;N--){
		scanf("%d%c%d",&A,&letra,&B);
		if (A==B)
			result=A*B;
		else if (islower(letra))
			result=A+B;
		else if (isupper(letra))
			result=B-A;
		printf("%d\n",result);
		
	}	
	return 0;
}	