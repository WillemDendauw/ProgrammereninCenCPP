#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	for(int i= 0; i<65; i++) {
		cout << "dec: " << dec << i <<setw(10)<< " oct: " << oct << i <<setw(10)<< " hex: " << hex << i << endl;
	}
	return 0;
}
