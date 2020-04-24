#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	unsigned long long int fac = 1;
	int i, n;
	srand(time(NULL));
	n = rand()%19 +2;
	for(i=2; i<=n; i++){
		fac*=i;
	}
	printf("%d! = %lld\n",n,fac);
	return 0;
}


/* versie 1 is correctd tem 12
int main(){
	long int fac=1;
	int n=30;
	int i;
	for(i=2;i<=n;i++){
		fac *= i;
		printf("%d! = %lld \n",i,fac);
	}
	return 0;
}
*/

/*versie 2 is gewoon met een unsigned long long int fac ipv long int fac
en is correct tem 20*/

/*versie 3 is met een double maar die rond af*/
