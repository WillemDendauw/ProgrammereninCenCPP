#include<iostream>
using namespace std;

int main() {
	char c = 'x';
	//string s = "" + c;

	
	//mis, je kan geen 2 c-strings optellen;
	//hier doe je dan een gewone string + c-string en dat kan wel
	string s = "";
	s = s + c;
	cout << "karakter "<< c <<" omgezet: "<< s << "." << endl;
	
	char k = 'y';
	string w = "";
	w += k;
	cout << "karakter "<< k <<" omgezet: "<< w << "." << endl;
	
	return 0;
}
