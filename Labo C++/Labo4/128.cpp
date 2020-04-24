#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Doos;

template<typename T>
class Schijf{
	public:
		Schijf();
		Schijf(const Schrijf<T>&);
		Schijf<T>& operator=(const Schijf<T>&);
		virtual ~Schijf<T>(); //destructor altijd virtual maken!!
		//extra
		Schijf(Schijf<T>&&); //move constructor
		Schijf<T>& operator=(Schijf<T>&&); //move operator
		
	private:
		Doos<T> *a;
};

template<typename T>
class Doos{
	public:
		Doos();
		Doos(const Doos<T>& doos);
		Doos<T>& operator=(const Doos<T>&);
		virtual ~Doos();
		//extra
		Doos(Doos<T>&&); //move construcotr
		Doos<T>& operator=(Doos<T>&&); //move operator
	
	private:
		vector<T> b;
		Schijf<T>** d;
		Doos<T>* c;
};

/*****************************Schijf***************************/
template<typename T>
Schijf<T>::Schijf():a(0){
}

template<typename T>
Schijf<T>::Schijf(const Schijf<T>& schijf){
	if(schijf.a != 0){
		a = new Doos<T>(*(schijf.a));
	}
	else{
		a=0;
	}
}

template<typename T>
Schijf<T>::~Schijf(){
	delete a;
}

template<typename T>
Schijf<T>& Schijf<T>::operator=(const Schijf<T>& schijf){
	if(this!=&schijf){
		delete a;
		a=0;
		if(schijf.a!=0){
			a=new Doos<T>(*(schijf.a));
		}
	}
	return *this;
}

template<typename T>
Schijf<T>::Schijf(Schijf<T>&& schijf): a(schijf.a) {
	schijf.a == nullptr;
}

template<typename T>
Schijf<T>& Schijf<T>::operator=(Schijf<T>&& schijf){
	if(this != &schijf){
		delete a;
		a = schijf.a;
		schijf.a = nullptr;
	}
	return *this;
}

/***************************Doos****************************/
template<typename T>
Doos<T>::Doos():b(4),c(0){
	d = new Schijf<T>*[3];
	for(int i=0; i<3; i++){
		d[i] = 0;
	}
}

template<typename T>
Doos<T>::Doos(const Doos<T>& doos) b(doos.b){
	if(doos.c !=0){
		c = new Doos<T>(*(doos.c));
	}
	else{
		c =0;
	}
	d = new Schijf<T>*[3];
	for(int i=0; i<3; i++){
		if(doos[i] != 0){
			d[i] = new Schijf<T>(*(doos.d[i));
		}
		else{
			d[i] = 0;
		}
	}
}

template<typename T>
Doos<T>& Doos<T>::operator=(const Doos<T>& doos){
	if(this!=&doos){
		b = doos.b;
		delete c;
		if(doos.c!=0){
			c = new Doos<T>(*(doos.c));
		}
		for(int i=0; i<3; i++){
			delete d[i];
			if(doos.d[i] != 0){
				d[i] = new Schijf<T>(*(doos.d[i]));
			}
			else{
				d[i] = 0;
			}
		}
	}
	return *this;
}

template<typename T>
Doos<T> :: ~Doos(){
	delete c;
	for(int i=0;i<3;i++){
		delete(d[i]);
	}
	delete []d;
}

template<typename T>
Doos<T>::Doos(Doos<T>&& doos): b(move(doos.b)), c(doos.c), d(doos.d) {
	doos.c = nullptr;
	doos.d = nullptr;
}

template<typename T>
Doos<T>& Doos<T> :: operator=(Doos<T>&& doos){
	if(this!=&doos){
		b = move(doos.b);
		c = doos.c;
		doos.c = nullptr;
		for(int i=0; i<3; i++){
			delete(d[i]);
		}
		delete[] d;
		d = doos.d;
		doos.d = nullptr;
	}
	return *this;
}



















