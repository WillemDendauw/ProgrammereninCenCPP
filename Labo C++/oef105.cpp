#include<iostream>
using namespace std;

int main() {
	double getallen[5] = {5.5,7.7,2.2,9.9,9.8};
	string woorden[3] = {"geloof","hoop","de liefde"};
	cout << "Grootste getal is: "<<grootste(getallen,5) << endl;
	cout << "Het grootste woord is: " << grootste(woorden,3) << "." << endl;
	return 0;
}

int grootte(elt){
	return elt.length();
}
