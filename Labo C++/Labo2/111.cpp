#include<iostream>

template <typename T>
void print(const vector<T> &v){
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
	for(int i=0; i<v.size();i++){
		out<<v[i]<<" ";
	}
	cout<<endl;
	return out;
}
