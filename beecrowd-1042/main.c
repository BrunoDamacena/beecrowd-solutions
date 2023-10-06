#include<stdio.h> 
int main(){
	int a,b,c,al,bl,cl,tmp;
	scanf("%i %i %i",&a,&b,&c);
	al=a;
	bl=b;
	cl=c;
	if (al>bl && bl>cl){
		tmp=al;
		al=cl;
		cl=tmp;
	}
	else if (al>cl && cl>bl){
		tmp=bl;
		bl=al;
		al=tmp;
		tmp=bl;
		bl=cl;
		cl=tmp;
	}
	else if (al>cl && bl>al){
		tmp=bl;
		bl=cl;
		cl=tmp;
		tmp=al;
		al=bl;
		bl=tmp;
	}
	else if (al>bl && cl>al){
		tmp=al;
		al=bl;
		bl=tmp;
	}
	else if (bl>cl && cl>al){
		tmp=bl;
		bl=cl;
		cl=tmp;
	}
	
	printf("%i\n%i\n%i\n\n%i\n%i\n%i\n",al,bl,cl,a,b,c);
		
return 0;
}