#include <iostream>
using namespace std;


template <typename type>
class myArray {
    type* arr;
    int size;
    int noOfEl;
public:
    myArray(int size) : size(size),noOfEl(0)
    {
        arr = new type[size];
    }
    void insert(type el,int index)
    {
        if (noOfEl != size)
        {
            arr[index] = el;
            noOfEl++;
        }
        else
            cout << "array is already full\n";
    }
    void del(int index) {
        if (noOfEl == 1)
        {
            noOfEl--;
            return;
        }
        if (index < noOfEl)
            arr[index] = arr[noOfEl--];
        else
            cout << "There is already nothing in this index\n";
    }
    type get(int index)
    {
        if (index < noOfEl)
            return arr[index];
        else
            cout << "dont have this index\n";
    }
    void update(type el, int index)
    {
        if (index < noOfEl)
        arr[index] = el;
        else
            cout << "dont have this index\n";
    }
    int currentSize()
    {
        return noOfEl;
    }
    void display()
    {
        for (int i = 0; i < noOfEl; i++)
        {
            cout << arr[i] << " " << endl;
        }
    }

    int findIndex(type el)
    {
        for (int i = 0; i < noOfEl; i++)
        {
            if (arr[i] == el)
                return i;
        }
    }

    // Task 2

    void reverse()
    {
        for (int i = 0,j = noOfEl - 1; i < noOfEl / 2; i++,j--)
        {
            type temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Task3

    bool IfPalindrome()
    {
        for (int i = 0, j = noOfEl - 1; i < noOfEl / 2; i++, j--)
        {
            if (arr[i] != arr[j])
                return 0;
        }
        return 1;
    }

};

int main() {

    myArray<int> arr(4);
    arr.insert(0, 0);
    int ind = arr.get(0);
    cout << endl << ind << endl;
    arr.update(1, 0);
    arr.display();
    cout << arr.currentSize() << endl;
    cout << arr.findIndex(1) << endl;
    arr.del(0);
    arr.display();

    cout << endl;
    arr.insert(1,0);
    arr.insert(2, 1);
    arr.insert(3, 2);
    cout << "array before reverse\n";
    arr.display();
    arr.reverse();
    cout << "array after reverse\n";
    arr.display();

    arr.update(1, 0);
    arr.update(0, 1);
    arr.update(1, 2);
    cout << "Array\n";
    arr.display();
    cout << "Checking if its palindrome\n";
    bool check = arr.IfPalindrome();
    if (check == 1)
        cout << "Its a Palindrome\n";
    else
        cout << "Its not a Palindrome\n";
    return 0;
}
