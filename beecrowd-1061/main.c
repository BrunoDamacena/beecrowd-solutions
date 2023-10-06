#include<stdio.h>

int main(){
    int d1,h1,m1,s1,d2,h2,m2,s2,qd=0,qh=0,qm=0,qs=0;
    char dia[4],pontos1[3],pontos2[3];
    
    scanf("%s%d",dia,&d1);
    scanf("%d%s%d%s%d",&h1,pontos1,&m1,pontos2,&s1);
    scanf("%s %d",dia,&d2);
    scanf("%d%s%d%s%d",&h2,pontos1,&m2,pontos2,&s2);
    while(s1!=s2){
        s1=s1+1;
        if(s1==60){
            s1=0;
            qm=qm-1;
        }
        qs=qs+1;
    }
    while(m1!=m2){
        m1=m1+1;
        if(m1==60){
            m1=0;
            qh=qh-1;
        }
        qm=qm+1;
    }
    while(h1!=h2){
        h1=h1+1;
        if(h1==24){
            h1=0;
            qd=qd-1;
        }
        qh=qh+1;
    }
    while(d1!=d2){
        d1=d1+1;
        qd=qd+1;
    }
    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n",qd,qh,qm,qs);
    return 0;
}