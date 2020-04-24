#include <stdio.h>

int main() {
	int cijfers[] = {5,6,8,9,4,2,3,1,5,6,7,8,9,5,4,3,1,2,6,8,7,5,6,5,1,3,2,4,11};
	int grootte = sizeof(cijfers)/sizeof(int);
	int zoek;
	do {
		printf("Welk getal wil je zoeken?: ");
		scanf("%d",&zoek);
	}
	while(zoek is reeel)
	printf("%d",index_van(cijfers, grootte, zoek));
	return 0;
}

int index_van(int getallen[], int grootte, int getal) {
	int i = 0;
	while(i<grootte && getallen[i] != getal) {
		i++;
		}
	if(i == grootte) {
		return -1;
	}
	else {
		return i;
	}
}
