#include <stdio.h>
#include <stdlib.h>

FILE *Fopen(char *fname, char *fmode);

int main(void) {
	FILE *fp;
	
	fp = Fopen("data.txt","r");
	fclose(fp);
	return 0;
}

FILE *Fopen(char *fname, char *fmode) {
	FILE *fp;
	
	fp = fopen(fname,fmode);
	if(fp == NULL) {
		printf("Cannot open file %s\n",fname);
		exit(1);		//프로그램 종료(종료코드 = 1) 
	}
	return fp;
}
