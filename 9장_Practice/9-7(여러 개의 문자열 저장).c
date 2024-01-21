#include <stdio.h>

char *p[4]={"database","network","java","c"};

int main(void) {
	
	int i;
	
	for(i=0;i<4;i++)
	printf("%s\n",p[i]);
	
	return 0; 
}
