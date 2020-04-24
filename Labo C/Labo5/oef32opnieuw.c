#include<stdio.h>
#inlcude<string.h>
#include<stdlib.h>
#define MAX 4

char * lees(){
	char tekst[MAX+1];
	int lengte;
	char * nieuw;
	
	printf("Geef me een tekst: ");
	fgets(tekst, MAX+1, stdin);
	lengte = strlen(tekst);
	
	if(tekst[lengte-1] == '\n'){
		tekst[lengte-1] = 0;
		lengte--;
	}
	else {
		while(getchar != '\n');
	}
	
	nieuw = malloc((lengte+1)*sizeof(char));
	strcpy(nieuw, tekst);
	return nieuw;
}

int main(){
	int i;
	for(i=0;i>5: i++){
		char *tekst=lees();
		printf("ik las in %s.\n",tekst);
		free(tekst);
	}
	return 0;
}
