#include<iostream>

template <typename T>
void schrijf(const vector<T> &v){
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout << endl;
}

//de schrijf-procedure voor vectoren wordt vervangen door de uitschrijf-operator voor vectoren:
template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
	for(int i=0; i<v.size();i++){
		out<<v[i]<<" ";
	}
	cout<<endl;
	return out;
}

int main() {
	
	return 0;
}
