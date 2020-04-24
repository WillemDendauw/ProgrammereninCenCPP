#include<iostream>
#include<vector>
using namespace std;


template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
	out << endl << "[ ";
	for(int i=0; i<v.size() - 1; i++){
		out << v[i] << " - ";
	}
	out << v[v.size() - 1] << " ]" << endl;
	return out;
}

template<typename T>
class mijn_vector: public vector<T>{
	using vector<T>::vector;
	
	public:
		void verdubbel(bool herhaal_elk_element=false);
};

template<typename T>
void mijn_vector<T>::verdubbel(bool herhaal_elk_element){
	if(herhaal_elk_element){
		int lengte = this->size();
		this->resize(2*lengte);
		for(int i=this->size()-1;i >0;i-=2){
			(*this)[i] = (*this)[i/2];
			(*this)[i-1] = (*this)[i/2];
		}
	}
	else{
		for(int i=0; i<this->size(); i++){
			(*this)[i] = 2 * (*this)[i];
		}
	}
}


int main(){
	mijn_vector<int> v{10,20,30};
	cout << v;
	
	v.verdubbel();
	cout<<endl<<"na verdubbelen zonder aprameter: " << v;
	v.verdubbel(true);
	cout<<endl<<"na verdubbelen met parameter true: " << v;
	
	mijn_vector<int> w(v);
	cout<<endl<<"een kopie van v: "<<w;
	
	mijn_vector<double> u(7);
	cout<<endl<<"een vector met 7 default-elt: "<<u;
	for(int i=0; i<u.size();i++){
		u[i] = i*1.1;
	}
	cout<<endl<<"na opvullen met getallen: "<< u;
	u.verdubbel();
	cout<<endl<<"na verdubbelen zonder aparmeter: "<<u;
	
	return 0;
}
