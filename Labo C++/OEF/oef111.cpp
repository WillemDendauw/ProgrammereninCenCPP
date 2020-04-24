#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
	for(int i=0; i<v.size();i++){
		out<<v[i]<<" ";
	}
	cout<<endl;
	return out;
}

struct Persoon{
	string naam;
	int leeftijd;
};

template <typename T>
void schrijf(const vector<T> &v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout <<endl;
}

int main(){
	
	
	return 0;
}
