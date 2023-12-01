#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int i;char c;
	for(i=1;i<argc;i++)
	{
		printf("%s",argv[i]);
	}

	return 0;
}
