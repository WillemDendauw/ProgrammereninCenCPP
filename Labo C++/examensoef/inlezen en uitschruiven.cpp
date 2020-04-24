#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream inv("tekst.txt");
	if(inv.is_open()){
		cout << "openen gelukt\n";
	}
	ofstream uitv("output.txt", ios::out);
	int getal;
	inv >> getal;
	char ch;
	ch = inv.get();
	string lijn;
	getline(inv,lijn);
	uitv << getal << " " << ch << " " << lijn << endl;
	cout << getal << " " << ch << " " << lijn << endl;
	return 0;
}
