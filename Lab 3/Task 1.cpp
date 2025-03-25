#include <iostream>
using namespace std;
template <class T>
class List
{
protected:
    T* arr;
    int maximumsize;
    int currentsize;
public:
    List(int size = 10)
    {
        maximumsize = size;
        currentsize = 0;
        arr = new T[maximumsize];
    }
    List(const List& other)
    {
        maximumsize = other.maximumsize;
        currentsize = other.currentsize;
        arr = new T[maximumsize];
        for (int i = 0; i < currentsize; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    virtual ~List()
    {
        delete[] arr;
        cout << "Destructor is called." << endl;
    }
    virtual void addelementatfirstindex(T) = 0;
    virtual void addelementatlastindex(T) = 0;
    virtual T removeelementfromend() = 0;
    virtual void removeelementfromstart() = 0;
    int getsize() const
    {
        return currentsize;
    }
    T getelement(int index) const
    {
        return arr[index];
    }
};

template <class T>
class ArrayList : public List<T>
{
public:
    ArrayList(int size = 10) : List<T>(size) {}
    void addelementatfirstindex(T value) override
    {
        if (this->currentsize >= this->maximumsize)
            return;
        for (int i = this->currentsize; i > 0; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = value;
        this->currentsize++;
    }
    void addelementatlastindex(T value) override
    {
        if (this->currentsize >= this->maximumsize)
            return;
        this->arr[this->currentsize++] = value;
    }
    T removeelementfromend() override
    {
        if (this->currentsize == 0)
            return T();
        return this->arr[--this->currentsize];
    }
    void removeelementfromstart() override
    {
        if (this->currentsize == 0)
            return;
        for (int i = 0; i < this->currentsize - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->currentsize--;
    }
};

template <class T>
void printList(const ArrayList<T>& list)
{
    cout << "Elements are: ";
    for (int i = 0; i < list.getsize(); i++)
    {
        cout << list.getelement(i) << " ";
    }
    cout << endl;
}

int main() {
    ArrayList<int> myList(120);
    myList.addelementatlastindex(100);
    myList.addelementatlastindex(110);
    myList.addelementatfirstindex(120);
    printList(myList);
    myList.removeelementfromstart();
    printList(myList);
    myList.removeelementfromend();
    printList(myList);
    return 0;
}
