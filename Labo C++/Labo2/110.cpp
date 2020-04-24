#include<iostream>
#include<functional>
#include<iomanip>
using namespace std;

void schrijf(const string & tekst, const int* v, int aantal){
	cout<<tekst;
	for(int i=0;i<aantal;i++){
		cout<<setw(4)<<v[i]<<" ";
	}
	cout<<endl;
}

void vul_array(const int* a, const int* b, int* c, int grootte, function<int(int,int)> func){
	int i;
	for(i=0;i<grootte;i++){
		c[i] = func(a[i],b[i]);
	}
}

int main(){
	const int GROOTTE = 10;
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[] = {0,10,20,30,40,50,60,70,80,90};
	int c[GROOTTE];
	
	vul_array(a,b,c,GROOTTE,[](int x, int y){return x+y;});
	schrijf("Som:		",c,GROOTTE);
	
	vul_array(a,b,c,GROOTTE,[](int x,int y){return x*y;});
	schrijf("Product:	",c,GROOTTE);
	
	vul_array(a,b,c,GROOTTE,[](int x,int y){return x-y;});
	schrijf("Verschil:	",c,GROOTTE);
	
	return 0;
}
