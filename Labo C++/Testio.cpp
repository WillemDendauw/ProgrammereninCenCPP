#include<iostream>
#include<string>
using namespace std;

void oef1(); //inlezen getal
void oef2(); //inlezen woord
void oef3(); //inlezen zin
void oef4(); //inlezen char

int main(){
	oef4();
	
	return 0;
}

void oef1(){
	cout<< "geef 2 getallen in:\n";
	int g1, g2;
	cin >> g1 >> g2;
	cout << "getal1 dec = " << g1 << endl << "getal2 hex = " << hex << g2;
}

void oef2(){
	//string inlezen
	cout << "typ een woord:"<<endl;
	string s;
	cin >> s; //leest 1woord, oftewel alle characters tot de volgende whitespace
	cout<< s;
}

void oef3(){
	cout << "typ een zin:"<<endl;
	string s;
	getline(cin, s);
	cout << s;
}

void oef4(){
	cout<< "geef een teken:"<<endl;
	char a;
	a = cin.get(); //of a = getchar();
	cout << a;
}
