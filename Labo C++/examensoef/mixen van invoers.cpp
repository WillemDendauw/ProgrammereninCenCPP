#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string zin1, zin2;
	ifstream in1("testtekst1.txt");
	ifstream in2("testtekst2.txt");
	ofstream uit("mix.txt", ios::out);
	if(!in1.is_open() || !in2.is_open()){
		cout << "bestand gefaald"<< endl;
	}
	else {
		int teller = 0;
		getline(in1,zin1);
		getline(in2,zin2);
		while(!in1.fail() && !in2.fail()){
			if(teller%2 == 0){
				uit << zin1 <<endl;
			}
			else {
				uit << zin2 <<endl;
			}
			teller++;
			getline(in1,zin1);
			getline(in2,zin2);
		}
	}
	
	return 0;
}
