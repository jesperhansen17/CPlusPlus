#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int S = 1000;

// Struct C
struct C {
	int value;
	explicit C(int x) :value(x){};
	C() = default;
	C(const C&) = default;
	C& operator=(C rhs) { value = rhs.value; return *this; }
	C& operator++() { ++value; return *this; }
	bool operator<(const C & rhs) const { return this->value < rhs.value; }
	bool operator>(const C & rhs) const { return this->value > rhs.value; }

	friend ostream& operator<<(ostream & cout, const C& rhs) {
		cout << rhs.value;
		return cout;
	}
private:
	char A[S];
};

// Unary Predicate for deciding if i is even or not
bool is_even(int i)
{
	return (i % 2) == 0;
}

// Binary Predicate for deciding if i is bigger than j
bool is_bigger(int i, int j)
{
	return i > j;
}

// Print function for printing out a vector
template <class T>
void printVector(const vector<T> &vec)
{
	for (vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ' ';
	}

	cout << endl;
	cout << endl;
}

// Push_Back objects to a vector
template <class T>
void pushVector(vector<T> &vec)
{
	T c1;

	for (int i = 0; i < 50; i++) {
		c1.value = rand() % 100;
		vec.push_back(c1);
	}
}

// Task 2A
// C++ implementation of Bubble Sort, but instead of comparing values next to eachother
// it increments i and compares i value with j value. j value always starts from the beginning and increments
// up until it reaches i before incrementing i again.
// If value of is i < j then the i and j will switch place so that the lowest value will be first in the iterator
template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{
	for (auto i = begin; i != end; ++i)
	{
		for (auto j = begin; j < i; ++j)
		{ 
			if (*i < *j)
			{
				swap(*i, *j);
			}
		}
	}
}

// Task 3B
// ForwardSort that that has three arguments.
// Iterator for begin and end. Also a lambda function that tells with sort the 
// function is gonna use. And that function is represented by comp()
template <class ForwardIterator, class Compare>
void ForwardSort(ForwardIterator begin, ForwardIterator end, Compare comp)
{
	for (auto i = begin; i != end; ++i) {
		for (auto j = begin; j < i; ++j) {
			if (comp(*i, *j)) {
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

	cout << "Task 1: Erase and remove from vector!!!!" << endl;

	cout << "50 numbers in order: ";
	printVector(intVector);

	random_shuffle(intVector.begin(), intVector.end());

	cout << "50 numbers is in random order: ";
	printVector(intVector);

	// Remove_if can't remove from container itself.
	// Instead the removal is done by replacing the elements for which is_even is true by the next
	// element for which it does not, and shortened the range by returning an iterator that ends where
	// it should be considered the new one past the end element.
	// That new iterator is the start for which number that will be removed from the container
	intVector.erase(std::remove_if(intVector.begin(), intVector.end(), is_even), intVector.end());

	// Using Lambdas
	//intVector.erase( remove_if(intVector.begin(), intVector.end(), [] (int i) { return (i % 2) = 0; }));

	cout << "Removed all the numbers that can be divided by 2: ";
	printVector(intVector);

	ForwardSort<vector<int>::iterator>(intVector.begin(), intVector.end());

	cout << "Task 2: Sort numbers with bubblesort!!!!!!!!!" << endl;

	cout << "Made the numbers in order with bubblesort: ";
	printVector(intVector);
}

// Use ForwardSort to sort a vector of C objects
void task2B()
{
	vector< C > test2;

	pushVector(test2);

	cout << "Task 2B: Sort numbers with ForwardSort!!!!!!!!" << endl;
	
	// Print the numbers
	cout << "50 numbers in random order: ";
	printVector(test2);

	// Sort using ForwardSort
	ForwardSort<vector<C>::iterator>(test2.begin(), test2.end());

	// Print the numbers
	cout << "50 numbers in sorted order: ";
	printVector(test2);

}

void task3A()
{
	vector< C > test2;

	// Push_back C-objects to an vector
	pushVector(test2);

	cout << "Task 3A: Sort backwards using reverseIterators!!!!!!" << endl;

	// Print the numbers
	cout << "50 numbers in random order: ";
	printVector(test2);

	// Create two reverse iterators 
	reverse_iterator<vector<C>::iterator> reverse_end(test2.begin());
	reverse_iterator<vector<C>::iterator> reverse_begin(test2.end());

	// Use the reverse iterators for sorting backwards using forwardSort
	ForwardSort<reverse_iterator<vector<C>::iterator>>(reverse_begin, reverse_end);

	// Print the numbers
	cout << "50 numbers in sorted order: ";
	printVector(test2);
}

void task3B()
{
	vector< C > test2;

	// Push_back C-objects to an vector
	pushVector(test2);

	cout << "Task 3B: Sort backwards using a lambda expression!!!!!!!!!" << endl;

	// Print the numbers
	cout << "50 numbers in random order: ";
	printVector(test2);

	// Reverse sort the vector with the help of a lambda function in the call of ForwardSort
	ForwardSort(test2.begin(), test2.end(), [](C lhs, C rhs) { return lhs > rhs; });

	// Print the numbers
	cout << "50 numbers in sorted order: ";
	printVector(test2);
}

// Create a vector with a predefined number of C objects, then shuffle them and then
// sort the numbers using std::sort and use a lambda exressesion as a parameter.
void task4()
{
	vector< C > test2;

	// Push_back C-objects to an vector
	pushVector(test2);

	cout << "Task 4: Sort forward using STL sort using lambda expression!!!!!!!!" << endl;

	// Print the numbers
	cout << "50 numbers in random order: ";
	printVector(test2);

	sort(test2.begin(), test2.end(), [](C lhs, C rhs) { return lhs < rhs;  });

	// Print the numbers
	cout << "50 numbers in sorted order: ";
	printVector(test2);
}

void task5()
{
	vector<string> mystring;
	//vector<String> myString;
}

int main()
{
	task1and2A();			// Done
	task2B();				// Done
	task3A();				// Done
	task3B();				// Done
	task4();				// Done
	//task5();				// Not started
	return 0;
}

