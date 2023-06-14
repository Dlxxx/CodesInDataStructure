#include <iostream>
#include <queue>
using namespace std;

template <typename kindType>
class priorityQueue_min: public queue<kindType>
{
    public:
        priorityQueue_min(int capacity = 100);
        priorityQueue_min(const kindType data[], int size);
        ~priorityQueue_min();
        bool isEmpty() const;
        void enQueue(const kindType &x);
        kindType deQueue();
        kindType getHead() const;

    private:
        int currentSize;
        kindType *array;
        int maxSize;
    
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};


template <typename kindType>
priorityQueue_min<kindType>::priorityQueue_min(int capacity)
{
    array = new kindType [capacity];
    maxSize = capacity;
    currentSize = 0;
}


template <typename kindType>
priorityQueue_min<kindType>::~priorityQueue_min()
{
    delete []array;
}


template <typename kindType>
bool priorityQueue_min<kindType>::isEmpty() const
{
    return currentSize == 0;
}


template <typename kindType>
kindType priorityQueue_min<kindType>::getHead() const
{
    return array[1];
}


template <typename kindType>
void priorityQueue_min<kindType>::enQueue(const kindType& x)
{
    if(currentSize == maxSize-1) doubleSpace();
    int hole = ++currentSize;
    for (; hole>1 && x<array[hole/2]; hole/=2)
        array[hole] = array[hole/2];
    array[hole] = x;
}


template <typename kindType>
kindType priorityQueue_min<kindType>::deQueue()
{
    kindType minIterm;
    minIterm = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minIterm;
}


template <typename kindType>
void priorityQueue_min<kindType>::percolateDown(int hole)
{
    int child;
    kindType tmp = array[hole];

    for(; hole*2<=currentSize; hole=child){
        child = hole*2;
        if(child != currentSize && array[child+1]<array[child])
            child++;
        if(array[child]<tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}


template <typename kindType>
void priorityQueue_min<kindType>::buildHeap()
{
    for(int i=currentSize/2; i>0; i--){
        percolateDown(i);
    }
}


template <typename kindType>
priorityQueue_min<kindType>::priorityQueue_min(const kindType*items, int size):maxSize(size+10), currentSize(size)
{
    array = new kindType[maxSize];
    for(int i=0; i<size; i++){
        array[i+1] = items[i];
        buildHeap();
    }
}


template <typename kindType>
void priorityQueue_min<kindType>::doubleSpace()
{
    kindType *tmp = array;
    maxSize *=2;
    array = new kindType[maxSize];
    for(int i=0; i<=currentSize; ++i){
        array[i] = tmp[i];
    }
    delete []tmp;
}



template <typename Type>
class priorityQueue_max: public queue<Type>
{
    public:
        priorityQueue_max(int capacity=100);
        priorityQueue_max(const Type data[], int size);
        ~priorityQueue_max();
        bool isEmpty() const;
        void enQueue(const Type &x);
        Type deQueue();
        Type getHead() const;

    private:
        int currentSize;
        Type *array;
        int maxSize;
    
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};


template <typename Type>
priorityQueue_max<Type>::priorityQueue_max(int capacity)
{
    array = new Type [capacity];
    maxSize = capacity;
    currentSize = 0;
}


template <typename Type>
priorityQueue_max<Type>:: ~priorityQueue_max()
{
    delete []array;
}


template <typename Type>
bool priorityQueue_max<Type>::isEmpty() const
{
    return currentSize == 0;
}


template <typename Type>
Type priorityQueue_max<Type>::getHead() const
{
    return array[1];
}


template <typename Type>
void priorityQueue_max<Type>::enQueue(const Type& x)
{
    if(currentSize == maxSize-1) doubleSpace();
    int hole = ++currentSize;
    for (; hole>1 && x>array[hole/2]; hole/=2)
        array[hole] = array[hole/2];
    array[hole] = x;
}


template <typename Type>
Type priorityQueue_max<Type>::deQueue()
{
    Type minIterm;
    minIterm = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minIterm;
}


template <typename Type>
void priorityQueue_max<Type>::percolateDown(int hole)
{
    int child;
    Type tmp = array[hole];

    for(; hole*2<=currentSize; hole=child){
        child = hole*2;
        if(child != currentSize && array[child+1]<array[child])
            child++;
        if(array[child]<tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}


template <typename Type>
void priorityQueue_max<Type>::buildHeap()
{
    for(int i=currentSize/2; i>0; i--){
        percolateDown(i);
    }
}


template <typename Type>
priorityQueue_max<Type>::priorityQueue_max(const Type*items, int size):maxSize(size+10), currentSize(size)
{
    array = new Type[maxSize];
    for(int i=0; i<size; i++){
        array[i+1] = items[i];
        buildHeap();
    }
}


template <typename Type>
void priorityQueue_max<Type>::doubleSpace()
{
    Type *tmp = array;
    maxSize *=2;
    array = new Type[maxSize];
    for(int i=0; i<=currentSize; ++i){
        array[i] = tmp[i];
    }
    delete []tmp;
}


int main()
{
    int n;
    cin>>n;
    int a[100005], b[100005];
    long long max_re=0, min_re=0;
    priorityQueue_max<int> que_a_max, que_b_max;
    priorityQueue_min<int> que_a_min, que_b_min;

    for (int _=0; _<n; _++){
        cin>>a[_];
        que_a_max.enQueue(a[_]);
        que_a_min.enQueue(a[_]);
    }
    for (int _=0; _<n; _++){
        cin>>b[_];
        que_b_min.enQueue(b[_]);
        que_b_max.enQueue(b[_]);
    }
    max_re = que_a_max.getHead()*que_b_max.getHead();
    min_re = que_a_min.getHead()*que_b_min.getHead();
    cout<<max_re<<" "<<min_re;
    
    return 0;
}