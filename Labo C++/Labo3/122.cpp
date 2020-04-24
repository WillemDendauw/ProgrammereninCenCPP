#include "containers.h"

template<typename T>
class Container{
	private:
		set<T> elementen;
		string naam;
	
	public:
		Container(){};
		Container(const T[], int, const string&);
		Container<T>& operator+=(T);
		Container<T> operator*(const Container<T>& )const;
		template<typename U>
		friend ostream& operator<<(ostream&, const Container<U>&);
};

template<typename T>
Container<T>::Container(const T data[], int n, const string& _naam): naam(_naam){
	for(int i=0;i<n;i++){
		elementen.insert(data[i]);
	}
}

template<typename T>
Container<T> Container<T>:: operator*(const Container& c)const{
	Container<T> vv;
	vv.naam = "doorsnede" + naam + " en " + c.naam;
	for(T el : elementen){
		if(c.elementen.count(el)>0){
			vv.elementen.insert(el);
		}
	}
	return vv;
}

template<typename T>
Container<T>& Container<T>::operator+=(T c){
	elementen.insert(c);
	return *this;
}

template<typename T>
ostream& operator<<(ostream& out, const Container<T>& c){
	out<<"*** set "<<c.naam<<" ***\n"<<c.elementen<<endl;
	return out;
}

int main(){
	char v[]={'a','b','c','d', 'e', 'e'};
	Container<char> verz1(v,6,"groot");
	Container<char> verz2(v,2,"klein");
	verz2 += 'e';
	verz2 += 'z';
	Container<char> doorsnede = verz1*verz2;
	//Maak de doorsnede
	cout<<verz1;
	cout<<verz2;
	cout<<doorsnede;
	return 0;
}
