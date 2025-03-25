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
};

template <class T>
class MyList : public List<T>
{
public:
    MyList(int size = 10) : List<T>(size) {}
    MyList(const MyList& other) : List<T>(other) {}
    ~MyList() {}
    int size() const
    {
        return this->currentsize;
    }
    bool insert(int index, T value)
    {
        if (index < 0 || index > this->currentsize || this->currentsize >= this->maximumsize)
            return false;
        for (int i = this->currentsize; i > index; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[index] = value;
        this->currentsize++;
        return true;
    }

    void addelementatfirstindex(T value) override
    {
        insert(0, value);
    }
    void addelementatlastindex(T value) override
    {
        if (this->currentsize < this->maximumsize)
        {
            this->arr[this->currentsize++] = value;
        }
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
    T get(int index) const
    {
        if (index < 0 || index >= this->currentsize)
            throw out_of_range("Index out of range");
        return this->arr[index];
    }
};

template <class T>
void printlist(const MyList<T>& list)
{
    cout << "Elements are: ";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;
}

int main() {
    int size;
    int choice;
    int value;
    int index;
    cout << "Enter the size of the list: ";
    cin >> size;
    MyList<int> myList(size);
    do
    {
        cout << "                    ***********" << endl;
        cout << "                    *   Menu  *:" << endl;
        cout << "                    ***********" << endl;
        cout << "1. Add the element at first index" << endl;
        cout << "2. Add the element at last index" << endl;
        cout << "3. Remove the element from start" << endl;
        cout << "4. Remove the element from End" << endl;
        cout << "5. Insert the element at index" << endl;
        cout << "6. Print the List" << endl;
        cout << "7. Exit the menu :("<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            myList.addelementatfirstindex(value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            myList.addelementatlastindex(value);
            break;
        case 3:
            myList.removeelementfromstart();
            cout << "Element is removed from start" << endl;
            break;
        case 4:
            myList.removeelementfromend();
            cout << "Element is removed from end" << endl;
            break;
        case 5:
            cout << "Enter the index and value: ";
            cin >> index >> value;
            if (myList.insert(index, value))
                cout << "Value is inserted successfully." << endl;
            else
                cout << "Insertion failed." << endl;
            break;
        case 6:
            printlist(myList);
            break;
        case 7:
            cout << "Exiting the menu" << endl;
            break;
        default:
            cout << "Invalid choice please try again." << endl;
        }
    } 
    while (choice != 7);
    return 0;
}
