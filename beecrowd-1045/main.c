#include<stdio.h>
int main(){
    float a,b,c,tmp;    
	scanf("%f %f %f",&a,&b,&c);
	if (a<b && b<c){
		tmp=a;
		a=c;
		c=tmp;
	}
	else if (a<c && c<b){
		tmp=b;
		b=a;
		a=tmp;
		tmp=b;
		b=c;
		c=tmp;
	}
	else if (a<c && b<a){
		tmp=b;
		b=c;
		c=tmp;
		tmp=a;
		a=b;
		b=tmp;
	}
	else if (a<b && c<a){
		tmp=a;
		a=b;
		b=tmp;
	}
	else if (b<c && c<a){
		tmp=b;
		b=c;
		c=tmp;
	}
	else if (a==c && a>b && c>b){
	    tmp=b;
	    b=c;
	    c=tmp;
	}
	else if (b==c && b>a && c>a){
	    tmp=a;
	    a=c;
	    c=tmp;
	}
	else if (a==b && a<c && b<c){
	    tmp=c;
	    c=a;
	    a=tmp;
	}
	else if (a==c && a<b && c<b){
	    tmp=b;
	    b=a;
	    a=tmp;
	}
	
	if (a>=(b+c))
	    printf("NAO FORMA TRIANGULO\n");
    else {
        if (a*a == ((b*b)+(c*c)))
            printf("TRIANGULO RETANGULO\n");
        if (a*a > ((b*b)+(c*c)))
            printf("TRIANGULO OBTUSANGULO\n");
        if (a*a < ((b*b) + (c*c)))
            printf("TRIANGULO ACUTANGULO\n");
        if (a==b && b==c && c==a)
            printf("TRIANGULO EQUILATERO\n");
        if ((a==b && a!=c && b!=c) || (a==c && a!=b && c!=b) || (b==c && b!=a && c!=a))
            printf("TRIANGULO ISOSCELES\n");  
    }      
    return 0;
}