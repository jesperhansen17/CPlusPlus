#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_even(int i)
{
    return (i % 2) == 0;
}

bool is_bigger(int i, int j)
{
    return i > j;
}

void print(const vector<int> &vec)
{
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
    cout << endl;
}

// Task 2A
// C++ implementation of Bubble Sort, but instead of comparing values next to eachother
// it increments i and compares i value with j value. j value always starts from the beginning and increments
// up until it reaches i before incrementing i again.
// If value of is i < j then the i and j will switch place so that the lowest value will be first in the iterator
template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{
    ForwardIterator i, j;

    for (i = begin; i != end; i++)
    {
        for (j = begin; j < i; j++)
        {
            if (*i < *j)
            {
                swap(*i, *j);
            }
        }
    }
}

// Creates an vector that is being filled with 50 numbers from 0 - 49
// Shuffles the number and then removes the number that is even
// Finally sort the vector with bubble sort to make the uneven numbers in order
void task1and2A()
{
    vector<int> intVector;

    for (int i = 0; i < 50; i++)
    {
        intVector.push_back(i);
    }

	cout << "50 numbers in order: ";
    print(intVector);

    random_shuffle(intVector.begin(), intVector.end());

	cout << "50 numbers is in random order: ";
    print(intVector);

    // Remove_if can't remove from container itself.
    // Instead the removal is done by replacing the elements for which is_even is true by the next
    // element for which it does not, and shortened the range by returning an iterator that ends where
    // it should be considered the new one past the end element.
    // That new iterator is the start for which number that will be removed from the container
    intVector.erase( std::remove_if(intVector.begin(), intVector.end(), is_even), intVector.end() );

    // Using Lambdas
    //intVector.erase( remove_if(intVector.begin(), intVector.end(), [] (int i) { return (i % 2) = 0; }));

	cout << "Removed all the numbers that can be divided by 2: ";
    print(intVector);

    ForwardSort(intVector.begin(), intVector.end());

	cout << "Made the numbers in order with bubblesort: ";
    print(intVector);
}

template<int N>
struct C {
    int value;  //det är denna som används
    int a[N];   //bara en placeholder för att det ska ta tid att kopiera ett C objekt.
};

void task2B()
{
	vector< C<10> > test2;

}

// Add a predefined number of ints to an vector, then create two reverse iterators and
// print out the numbers in backward order.
void task3A()
{
    vector<int> intVector;

    for (int i = 0; i < 50; i++)
    {
        intVector.push_back(i);
    }

    print(intVector);

    reverse_iterator<vector<int>::iterator> reverse_end(intVector.begin());
    reverse_iterator<vector<int>::iterator> reverse_begin(intVector.end());

    while (reverse_begin != reverse_end)
    	std::cout << *reverse_begin++ << ' ';
    std::cout << '\n';
}

// Create a vector with a predefined number of ints, then shuffle them and then
// sort the numbers using std::sort and use a lambda exressesion as a parameter.
void task4()
{
    vector<int> intVector;

    for (int i = 0; i < 50; i++)
    {
        intVector.push_back(i);
    }

    print(intVector);

    random_shuffle(intVector.begin(), intVector.end());

    print(intVector);

    sort(intVector.begin(), intVector.end(), [] (int lhs, int rhs) { return lhs > rhs; });
    //sort(intVector.begin(), intVector.end(), is_bigger);
    print(intVector);
}

void Test5()
{
	vector<string> mystring;
	//vector<String> myString;
}

int main()
{
    //task1and2A();
    //task2B();
    //task3A();
    //task4();
    return 0;
}
