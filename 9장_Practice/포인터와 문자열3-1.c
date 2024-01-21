#include <stdio.h>

int main(void) {
	char *p, s[20];
	p=s;
	strcpy(p,"computer");
	
	printf("p=%s\n",p);
	printf("s=%s\n",s);
}
