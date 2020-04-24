#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
	out <<endl<< "[";
	for(int i=0; i<v.size()); i++){
		out << v[i] << " - ";
	}
	out << v[v.size()-1] " ]"<<endl;
	return out;
}

template <typename T>
class mijn_vector: public vector<T>{
	using vector<T>::vector; //constructoren gebruiken
	
	public:
		void verdubbel(bool herhaal_elk_element=false);
};

template<typename T>
void mijn_vector<T>::verdubbel(bool herhaal_elk_element){
	if(herhaal_elk_element){
		int lengte = this->size();
		this->resize(2*lengte);
		for(int i=this->size()-1;i>0; i-=2){
			(*this)[i]=(*this)[i/2];
		}
	}
	else {
		for(int i=0;i<this->size(); i++) {
			(*this)[i] = 2 * (*this)[i];
		}
	}
}
