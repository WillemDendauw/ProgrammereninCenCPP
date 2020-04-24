#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream uit;
	uit.open("tekst.txt", ios::app);
	int i = 0;
	for(i=0; i<5; i++){
		string s;
		cin >> s;
		uit << s;
	}
	return 0;
}
