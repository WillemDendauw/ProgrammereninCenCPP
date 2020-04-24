#include<stdio.h>
#define MIN 100
#define MAX 120
#define AANTAL MAX - MIN
#define BEREIK MAX - MIN

int main(){
	int getal;
	int aanwezigheid[BEREIK+1]={0};
	int i;
	srand(time(NULL));
	
	for(i=0; i<AANTAL; i++){
		getal = MIN + rand()%(BEREIK+1);
		aanwezigheid[getal-MIN]=1;
		printf("%d ",getal);
	}
	
	printf("\nKwamen niet voor:\n");
	for(i=0; i<BEREIK+1; i++){
		if(aanwezigheid[i]==0){
			printf("%d ",(i+MIN));
		}
	}
	return 0;
}
