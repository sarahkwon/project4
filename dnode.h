template <class T>

class dnode
{
private:
    T data;
    // forward pointer
    dnode<T>* next;
    // backward pointer
    dnode<T>* prev;
 
public:
    dnode(); 
    ~dnode();
    dnode(const dnode &source); 
    dnode& operator= (const dnode &source); 
    dnode<T>* getNext();
    dnode<T>* getPrev();
    void setNext(dnode<T>* newNext);
    void setPrev(dnode<T>* newPrev);
    void setData(T newData);
    T* getData();

};
