#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream in_1("stationnetje.txt");
	ifstream in_2("paddestoel.txt");
	ofstream uit("mix.txt");
	
	if(!in_1.is_open() || !in_2.is_open()){
		cout<<"minstens één bestand werd niet gevonden - jammer.... "<<endl;
	}
	else {
		int teller = 0;
		string zin_1, zin_2;
		getline(in_1,zin_1);
		getline(in_2,zin_2);
		while(!in_1.fail() && !in_2.fail()){
			if(teller%2==0){
				uit << zin_1 << endl;
			}
			else {
				uit << zin_2 << endl;
			}
			teller++;
			getline(in_1,zin_1);
			getline(in_2,zin_2);
		}
	}
	
	return 0;
}
