#include <stdio.h>
#define SIZE 5

void copy(int *A,int *B,int size) {
	
	int i;
	
	for(i=0;i<size;i++)
	*(B+i)=*(A+i);
};

int main(void) {
	int A[SIZE]={1,2,3,4,5};
	int B[SIZE];

	int j;
	
	copy(&A,&B,SIZE);
	
	for(j=0;j<SIZE;j++)
	printf("%d\n",B[j]);
	
	return 0;
}
