#include<stdio.h>
#define N 5

char *lees() {
	char s[N+1];
	fgets(s,N+1,stdin);
	int lengte = strlen(s);
	char *str  = malloc(lengte); //string voorzien met dezelfde lengte als je ingegeven string
	if(s[lengte-1] =='\n'){ //het laatste teken van de array vervangen door een 0 wanneer het een enter is
		s[lengte-1]= '\0';
	}
	while(getchar() != '\n') { //overloopt je string en leegt de buffer
	}
	strcpy(str, s); 
	return str;
}

int main() {
	int i;
	for(i=0; i<5;i++) {
		char * tekst = lees();
		printf("ik las in %s. \n",tekst);
	}
	return 0;
}
