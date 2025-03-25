#include <iostream>
using namespace std;
bool isprime(int num)
{
    if (num < 2) 
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) 
            return false;
    }
    return true;
}
template <class t>
class list
{
protected:
    t* arr;
    int maxsize;
    int currentsize;
public:
    list(int size = 10)
    {
        maxsize = size;
        currentsize = 0;
        arr = new t[maxsize];
    }
    list(const list& other)
    {
        maxsize = other.maxsize;
        currentsize = other.currentsize;
        arr = new t[maxsize];
        for (int i = 0; i < currentsize; i++) 
        {
            arr[i] = other.arr[i];
        }
    }
    virtual ~list() 
    {
        delete[] arr;
        cout << "Destructor is called." << endl;
    }
    virtual void addelementatfirstindex(t) = 0;
    virtual void addelementatlastindex(t) = 0;
    virtual t removeelementfromend() = 0;
    virtual void removeelementfromstart() = 0;
};
template <class t>
class customlist : public list<t>
{
public:
    customlist(int size = 10) : list<t>(size) {}
    customlist(const customlist& other) : list<t>(other) {}
    ~customlist() {}
    void addelementatfirstindex(t value) override
    {
        if (this->currentsize >= this->maxsize) return;
        for (int i = this->currentsize; i > 0; --i) 
        {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = value;
        this->currentsize++;
    }
    void addelementatlastindex(t value) override
    {
        if (this->currentsize < this->maxsize)
        {
            this->arr[this->currentsize++] = value;
        }
    }
    t removeelementfromend() override
    {
        if (this->currentsize == 0)
            return t();
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
    t sumofprime()
    {
        t sum = 0;
        for (int i = 0; i < this->currentsize; i++)
        {
            if (isprime(this->arr[i])) 
            {
                sum += this->arr[i];
            }
        }
        return sum;
    }
    t secondmaxeven()
    {
        t max1 = -1;
        t max2 = -1;
        for (int i = 0; i < this->currentsize; i++) 
        {
            if (this->arr[i] % 2 == 0)
            {
                if (this->arr[i] > max1)
                {
                    max2 = max1;
                    max1 = this->arr[i];
                }
                else if (this->arr[i] > max2 && this->arr[i] != max1) 
                {
                    max2 = this->arr[i];
                }
            }
        }
        return max2;
    }

    t secondminodd() 
    {
        t min1 = -1;
        t min2 = -1;
        for (int i = 0; i < this->currentsize; i++) 
        {
            if (this->arr[i] % 2 != 0)
            {
                if (min1 == -1 || this->arr[i] < min1) 
                {
                    min2 = min1;
                    min1 = this->arr[i];
                }
                else if ((min2 == -1 || this->arr[i] < min2) && this->arr[i] != min1) 
                {
                    min2 = this->arr[i];
                }
            }
        }
        return min2;
    }
    void printduplicates()
    {
        cout << "Duplicate elements are: ";
        for (int i = 0; i < this->currentsize; i++) 
        {
            for (int j = i + 1; j < this->currentsize; j++)
            {
                if (this->arr[i] == this->arr[j]) {
                    cout << this->arr[i] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
};
int main() 
{
    int size;
    int value;
    cout << "Enter the size of the list: ";
    cin >> size;
    customlist<int> mylist(size);
    mylist.addelementatfirstindex(1);
    mylist.addelementatlastindex(3);
    mylist.addelementatlastindex(5);
    mylist.addelementatfirstindex(7);
    mylist.addelementatfirstindex(5);
    cout << "Sum of prime numbers: " << mylist.sumofprime() << endl;
    cout << "Second max even: " << mylist.secondmaxeven() << endl;
    cout << "Second min odd: " << mylist.secondminodd() << endl;
    mylist.printduplicates();
    return 0;
}
