template <class T>

class dnode
{
private:
    T* data;
    // forward pointer
    dnode<T>* next;
    // backward pointer
    dnode<T>* prev;
 
public:
    dnode() {
	next = 0;
	prev = 0;
    }

    dnode(T* newData) {
	data = newData;
	next = 0;
	prev = 0;
    }

    

dnode<T>* getNext() {
	return next;
}

dnode<T>* getPrev() {
	return prev;
}

void setNext(dnode<T>* newNext) {
	next = newNext;
}

void setPrev(dnode<T>* newPrev) {
	prev = newPrev; 
}

void setData(T* newData) {
	data = newData; 
}

T* getData() {
	return data; 
}

dnode<T>& operator=(dnode<T> source) {
	source.swap(*this);
	return *this;
}

};
