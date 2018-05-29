#include <iostream>

using namespace std;

template<class T>
class MyArray
{
public:
    MyArray()=default;

    MyArray(int capacity)
    {
        this->mCapacity = capacity;
        this->mSize = 0;
        this->pAddr = new T[this->mCapacity];
    }
    MyArray(const MyArray<T> &arr)
    {
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //ÉêÇë¿Õ¼ä
        this->pAddr = new T[this->mCapacity];
        // Êý¾Ý¿½±´.
        for(int i=0;i<this->mSize;i++){
            this->pAddr[i] = arr.pAddr[i];
        }
    }
    T& operator[](int index)
    {
        return this->pAddr[index];
    }
    MyArray<T> operator=(const MyArray<T>& arr)
    {
        if(this->pAddr != 0){
            delete[] this->pAddr;
        }
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //ÉêÇë¿Õ¼ä
        this->pAddr = new T[this->mCapacity];
        // Êý¾Ý¿½±´.
        for(int i=0;i<this->mSize;i++){
            this->pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }
    void pushBack( const T& data)
    {
        if(this->mSize>= this->mCapacity){
            return;
        }
        // push the data into the space;
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }

    void pushBack(T&& data)
    {
        if(this->mSize>= this->mCapacity){
            return;
        }
        // push the data into the space;
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    ~MyArray()
    {
        if(this->pAddr != 0)
        {
            cout << "Îö¹¹À²"<< endl;
            delete[] this->pAddr;
        }
    }
public:
    int mCapacity;
    int mSize;
    T* pAddr;
};
void test01()
{
     MyArray<int> marray(20);
     int a=10,b=20,c=30;
     marray.pushBack(a);
     marray.pushBack(b);
     marray.pushBack(c);
     marray.pushBack(20);
     for(int i =0;i<marray.mSize;i++){
        cout << marray[i]<< endl;
     }
}
int main()
{
    test01();
    cout << "Hello world!" << endl;
    return 0;
}
