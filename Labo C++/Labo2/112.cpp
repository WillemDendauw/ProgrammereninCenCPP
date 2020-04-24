template<typename T>
ostream& operator<<(ostream& out, const set<T>& s){
	out<<"{ ";
	typename set<T>::const_iterator it = s.begin();
	for(int i=0; i<s.size()-1; i++){
		out<<*it<<" , ";
		it++;
	}
	out<<*it<<" }";
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, stack<T> st){
	while(!st.empty()){
		out<<" "<<st.top()<<endl;
		st.pop();
	}
	return out;
}

template<typename S, typename D>
ostream& operator<<(ostream& out, const map<S,D>& m){
	typename map<S,D>::const_iterator it = m.begin();
	while(it!m.end()){
		out<<"  "<<it->first<<" --> "<<it->second<<endl;
		it++;
	}
	return out;
}
