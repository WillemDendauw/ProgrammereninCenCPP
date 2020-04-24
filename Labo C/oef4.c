#include <stdio.h>

int main() {
	int macht = 1;
	while (macht < 10000) {
		printf("%d ", macht);
		macht *= 2;
	}
	return 0;
}

/* de volgorde van de printf en de verandering van de macht moet omgewisseld worden om onder de 10000 te blijven */
