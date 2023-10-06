#include<stdio.h>

int main(){
	float N1,N2,N3,N4,media,exame,final;

	scanf("%f %f %f %f",&N1,&N2,&N3,&N4);
	media=((N1*2)+(N2*3)+(N3*4)+(N4*1))/(2+3+4+1);

	printf("Media: %.1f\n",media);
	if (media>=7.0)
		printf("Aluno aprovado.\n");
	else if (media <5.0)
		printf("Aluno reprovado.\n");
	else if (media>=5.0 && media<7.0) {
		printf("Aluno em exame.\n");
		scanf("%f",&exame);
		printf("Nota do exame: %.1f\n",exame);
		final=(media+exame)/2;
		if (final>=5.0)
			printf("Aluno aprovado.\n");
		else
			printf("Aluno reprovado.\n");
		printf("Media final: %.1f\n",final);
	}
return (0);
}