#include<stdio.h>

void schrijf(const char rij[], int aantal);
void schuif_links(char rij[], int lengte);

int main(){
	char rij[] = {'s','a','p','a','p','p','e','l'};
	int lengte = sizeof(rij)/sizeof(char);
	int i;
	
	schrijf(rij,lengte);
	
	for(i=0;i<3;i++){
		schuif_links ( rij , lengte );
		schrijf ( rij , lengte );
	}
	
	return 0;
}

void schrijf(const char rij[], int aantal){
	int i;
	for(i=0; i<aantal; i++){
		printf("%c",rij[i]);
	}
	printf("\n");
}

void schuif_links(char rij[], int lengte){
	char reserve = rij[0];
	int i;
	for(i=1;i<lengte;i++) {
		rij[i-1] = rij[i];
	}
	rij[lengte-1] = reserve;
}
