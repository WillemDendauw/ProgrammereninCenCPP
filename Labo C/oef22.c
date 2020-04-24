#include <stdio.h>

int main() {
	int rij[] = {2,3,4,0,5,7,2,5,3,0,6,2,9};
	int max;
	int min;
	int lengte = sizeof(rij)/sizeof(int);
	//zoek_extremen(rij,lengte,&min,&max);
	zoek_extremen_rec(rij,lengte,&min,&max);
	printf("het min is %d",min);
	printf(" het max is %d",max);
	return 0;	
}

void zoek_extremen(const int rij[], int lengte, int * min, int * max) {
	*min = rij[0];
	*max = rij[0];
	int i;
	
	for (i=0; i<lengte; i++) {
		if(*min > rij[i]) {
			*min = rij[i];
		}
		else if (*max < rij[i]) {
			*max = rij[i];
		}
	}
}

void zoek_extremen_rec(const int rij[], int lengte, int * min, int * max) {
	if(lengte == 1) {
		*min = rij[0];
		*max = rij[0];
	}
	else {
		zoek_extremen_rec(rij,lengte-1,min,max);
		if(rij[lengte-1] < *min){
			*min = rij[lengte-1];
		}
		else if(rij[lengte-1] > *max){
			*max = rij[lengte-1];
		}
	}
}

