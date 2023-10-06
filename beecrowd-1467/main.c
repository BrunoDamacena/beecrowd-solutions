#include<stdio.h>

int main(){
    int A,B,C;
    char R;
    
    while(scanf("%d %d %d",&A,&B,&C)!=EOF){
		if (A==B && B==C)
			R='*';
		else if (A==B && B!=C)
			R='C';
		else if (A==C && B!=C)
			R='B';
		else if (A!=B && B==C)
			R='A';
		
		printf("%c\n",R);		
		
	}
}