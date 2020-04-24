#include<iostream>
#include<fstream>
using namespace std; 

void schrijf(const int * arr, int aantal, bool achterstevoren = false, char tussenteken = ' ');

int main(){
	const int t[] = {1,2,3,4,5,11,13};
	schrijf(t,7);
	schrijf(t,7,true);
	schrijf(t,7,false,'-');
	schrijf(t,7,true,'-');
	return 0;
}

void schrijf(const int * arr, int aantal, bool achterstevoren, char tussenteken) {
	if(achterstevoren){
		cout << arr[aantal-1];
		for(int i=aantal-2; i>=0; i--){
			cout << tussenteken << arr[i];
		}
	}
	else {
		cout << arr[0];
		for(int i=1; i<aantal; i++){
			cout << tussenteken << arr[i];
		}
	}
	cout << endl;
}
