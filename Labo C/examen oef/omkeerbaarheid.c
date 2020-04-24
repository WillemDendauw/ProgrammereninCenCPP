#include <stdio.h>
#include <stdbool.h>

bool isOmkeerbaar(const int *t, int n){
	const int * p = &t[n-1];
	int i = 0;
	while(i<(n/2) && p[-i] == t[i]){
		i++;
	}
	return i==n/2;
}

int main(){
	const int t[] = {1,2,3,4,5,6,5,4,3,2,1};
	int grootte = sizeof(t)/sizeof(int);
	int i = isOmkeerbaar(t, grootte);
	if(i == 1) {
		printf("Het is omkeerbaar\n");
		printf("de index is %d",i);
	}
	else {
		printf("Is niet omkeerbaar\n");
		printf("de index is %d",i);
	}
	return 0;
}
