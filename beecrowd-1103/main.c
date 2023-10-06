#include<stdio.h>
#include<math.h>

int main(){
	int h1,m1,h2,m2,mm1,mm2,qm;
	while(1){
		scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
		if (h1==0 && m1==0 && h2==0 && m2==0)
			break;
		else{
			mm1=(h1*60)+m1;
			mm2=(h2*60)+m2;
			qm=mm2-mm1;
			if(qm<0)
				qm=qm+1440;
			printf("%d\n",qm);
		}
	}

	return 0;
}