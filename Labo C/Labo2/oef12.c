#include <stdio.h>

int main() {
	int getal;
	int som = 0;
	int i = 1;
	printf("Geef mij een positief getal: ");
	scanf("%d",&getal);
	while(getal >=0 && i<5) {
		som += getal;
		i++;
		printf("Geef mij een positief getal: ");
		scanf("%d",&getal);
	}
	if(getal>=0) {
		som += getal;
	}
	printf("De som van je getallen is: %d",som);
	return 0;
}
