#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

string genereer_string(int n); 
void vul_array_met_strings(string tab[], int n, int len);
void schrijf(string tab[], int n);
void bepaal_min_en_max(string tab[], int n, string &min, string &max);

int main() {
	srand(time(NULL)); //seed in main, anders in de for loop vraagt hij het te snel opnieuw op en veranderd die tijd niet
	string s = genereer_string(8);
	string tab[10];
	vul_array_met_strings(tab, 10, 8);
	schrijf(tab, 10);
	string min;
	string max;
	bepaal_min_en_max(tab,10, min, max);
	cout << "min: "<<min << endl;
	cout << "max: "<<max;
	cout << s;
	return 0;
}

string genereer_string(int n) {
	string s;
	int getal;
	for(int i = 0; i<n; i++) {
		getal = rand()%26;
		char letter = 'a'+ getal;
		s+=letter;
	}
	return s;
}

void vul_array_met_strings(string tab[], int n, int len)  {
	for (int i=0; i<n; i++) {
		tab[i] = genereer_string(len);
	}
}

void schrijf(string tab[], int n) {
	for (int i=0; i<n; i++){
		cout << tab[i] << endl;
	}
}

void bepaal_min_en_max(string tab[], int n, string &min, string &max){
	min = tab[0];
	max = tab[0];
	for (int i=0; i<n; i++){
		if (tab[i]<min) {
			min = tab[i];
		}
		if (tab[i]>max) {
			max = tab[i];
		}
	}
}
