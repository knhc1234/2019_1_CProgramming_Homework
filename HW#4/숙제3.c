#include<stdio.h>

int main(void) {
	
	int score[10];
	float mean;
	int i;
	int a;
	int b;
	
	for(i=0;i<10;i++)
		scanf("%d", &score[i]);
		
	mean = 0.0;
	for(i=0;i<10;i++)
		mean = mean + score[i]*0.1;
		
	printf("평균 점수 = %0.1f\n",mean);
	
	a=0;
	for(i=0;i<10;i++) {
		if(score[i]>=a)
		a=score[i];
		else
		a=a;
	}
	
	printf("최고 점수 = %d\n", a);
	
	b=100;
	for(i=0;i<10;i++) {
		if(score[i]<=b)
		b=score[i];
		else
		b=b;
	}
	
	printf("최저 점수 = %d\n", b);
	
}
