#include <stdio.h>

int main(void) {

	int gugu[8][9];
	int i;
	int j;

	for(i=0;i<8;i++) {
		for(j=0;j<9;j++) {
		gugu[i][j]=(i+2)*(j+1);
		printf("gugu[%d][%d]=%d*%d\n",i,j,i+2,j+1);
		}
	}			
	printf("------------------\n");
}
