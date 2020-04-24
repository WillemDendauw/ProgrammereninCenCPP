#include<iostream>

struct punt {
	int x,y;
};

template <class T>
void wissel(T &a, T &b){
	T hulp = a;
	a = b;
	b = hulp;
}

int main(){
	double d1 = 3.6;
	double d2 = 5.4;
	printf("%d %d \n",d1,d2);
	wissel(d1,d2);
	printf("%d %d \n",d1,d2);
	punt p1 = {1,2};
	punt p2 = {3,4};
	printf("%d %d &	%d %d \n",p1.x,p1.y,p2.x,p2.y);
	wissel(p1,p2);
	printf("%d %d &	%d %d \n",p1.x,p1.y,p2.x,p2.y);
}
