#include<stdio.h>
int main(){
	int A,B;
	while (scanf("%u %u",&A,&B) != EOF)
		printf("%u\n",A^B);
return 0;
}