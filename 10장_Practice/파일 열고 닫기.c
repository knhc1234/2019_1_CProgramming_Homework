#include <stdio.h>

int main(void) {
	FILE *fp;
	
	fp = fopen("data.txt","r");
	if (fp==NULL) {
		printf("Cannot open input file\n");
		return 1;
	}
	
	fclose(fp);
	return 0;
}
