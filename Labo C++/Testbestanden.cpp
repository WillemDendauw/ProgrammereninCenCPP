#include<fstream>
#include<iostream>
using namespace std;

int main(){
	ifstream inv;
	ofstream uitv("tekst.txt");
	inv.open("tekst.txt", ios::app);
	if(inv){
		cout<<"openen gelukt";
	}
	else {
		cout<<"openen mislukt";
	}
	cout<<"Geef 5 regels tekst:"<<endl;
	for(int i=0;i<5;i++){
		string lijn;
		getline(inv, lijn);
	}
	return 0;
}
