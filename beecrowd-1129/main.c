#include<stdio.h>

int main(){
    int N,A,B,C,D,E;
    char R;
    while(1){
		scanf("%d",&N);
		if (N==0)
			break;
		else{
			for(;N>0;N--){
				scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
				
				if (A<=127 && B>127 && C>127 && D>127 && E>127)
					R='A';
				else if (B<=127 && A>127 && C>127 && D>127 && E>127)
					R='B';
				else if (C<=127 && B>127 && A>127 && D>127 && E>127)
					R='C';
				else if (D<=127 && B>127 && C>127 && A>127 && E>127)
					R='D';
				else if (E<=127 && B>127 && C>127 && D>127 && A>127)
					R='E';
				else
					R='*';
				printf("%c\n",R);			
			}
		}		
	}
}