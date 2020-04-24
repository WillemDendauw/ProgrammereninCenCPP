#include <stdio.h>

int main() {
	int macht = 1;
	int i;
	for(i=0; i<20; i++) {
		printf("%d ",macht);
		macht *= 2;
		if (macht > 10000) {
			break;
		}
	}
	return 0;
}

/* je mag geen for lus gebruiken als je niet precies weet hoeveel keer je de lus doorloopt en
hier neem je een willekeurig getal 20, en je gebruikt break wanneer het moet stoppen. */
