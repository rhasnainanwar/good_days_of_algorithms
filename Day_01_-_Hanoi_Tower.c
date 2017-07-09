#include <stdio.h>

void hanoi(int, char *, char *, char *);

int main(int argc, char const *argv[]){
	hanoi( atoi(argv[1]) , "left", "right", "middle" );
	return 0;
}

void hanoi(int height, char * from, char * to, char * through) {
	if(height) {
		hanoi(height - 1, from, through, to);
		printf("%-7s => %s\n", from, to);
		hanoi(height - 1, through, to, from);
	}
}