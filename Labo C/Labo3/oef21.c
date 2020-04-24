#include <stdio.h>

int main() {
	char letters [] = {'p','o','r','g','o','e','d','o','i','d','o','k','i',':','a','-','t','('};
    const char *p = letters;
    
    schrijf_aantal(letters+3,4);
	printf("\n");
	schrijf(p+10,p+12);
	return 0;
}
 
void schrijf(const char* begin,const char* eind) {
	while (begin<eind) {
		printf("%c",*begin);
		begin++;
	}	
}

void schrijf_aantal(const char a[], int n) {
	int i;
	for(i=0 ; i<n; i++) {
		printf("%c",a[i]);
	}
}
