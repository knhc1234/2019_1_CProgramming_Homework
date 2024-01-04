#include <stdio.h>
#include <time.h>

int main(void) {
	
	int a[5];
	int b,c,i,j,k,N;
	srand(time(NULL));
	
	for(N=0;N<100;N++) {

	for(i=0;i<5;i++)
	a[i]=rand()%11;
	
while(a[0]==a[1]||a[0]==a[2]||a[0]==a[3]||a[0]==a[4]||a[1]==a[2]||a[1]==a[3]||a[1]==a[4]||a[2]==a[3]||a[2]==a[4]||a[3]==a[4])
	for(j=0;j<5;j++) {
		for(k=0;k<5;k++) {
			if(j!=k){
				if(a[j]==a[k])
					a[k]=rand()%11;
				}
			}	
		}
	
	
	
	for(i=0;i<5;i++)
	printf("a[%d]=%d\n",i,a[i]);
printf("\n\n");
}
}

