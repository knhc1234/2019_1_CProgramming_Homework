#include <stdio.h>

int main(void) {
	FILE *fpin, *fpout;
	char ofile[]="output.txt";
	int ch;
	
	fpin = fopen("input.txt","r");
	fpout = fopen(ofile,"w");
	
	while((ch=fgetc(fpin))!=EOF)
	fputc(ch,fpout);
	fclose(fpin);
	fclose(fpout);
}
