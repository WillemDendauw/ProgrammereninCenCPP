#include <stdio.h>

int main() {
	int rij[] = {8,4,7,5,9,2,5,7,6,2,3,4,8,7,6,8,3,9,4,7,5};
	int lengte = sizeof(rij)/sizeof(int);
	int getal = 0;
	int plaats = plaats_van(rij,lengte,getal);
	return plaats;
}

int plaats_van(const int rij[], int lengte, int getal) {
	int i=0;
	while(rij[i]!=getal){
		i++;
		if(rij[i] == getal){
			printf("het getal %d bevindt zich op plaats %d ",getal,i);
			return(i);
		}
	}
	return(0);
}
