// This is not a fully functional queue class
#include <iostream>
#include <stdlib.h>
using namespace std;

class queue
{
	int *intarray, start, end, capacity;

public:
	queue(int);
	queue();
	void enqueue(int);
	void pop();
	~queue();
	int size();
	int front();
	int getCapacity();

};

// Overloading queue's constructor
queue::queue(int size)
{
	intarray = (int*)malloc(sizeof(int)*size);
	capacity = size;
	start = 0;
	end = -1;

}

queue::queue()
{
	intarray = (int*)malloc(sizeof(int)*10);
	start = 0;
	end = -1;
	capacity = 10;

}

queue::~queue()
{
	cout << "Freeing Memory\n";
	free(intarray);


}

void queue::enqueue(int x)
{
	if (end < capacity)
		intarray[++end] = x;
	else
	{
		cout << "Overflow" << endl;
	}

}

void queue::pop()
{
	if(size() != 0)
		start++;
}

int queue::size()
{
	return (capacity - start + end + 1)%capacity;
}

int queue::front()
{
	if(size() != 0)
		return intarray[start];
}

int queue::getCapacity()
{
	return capacity;
}

int main()
{
	queue q1;

	cout << "capacity is " << q1.getCapacity() << "\n\n";

	cout << "Enqueue 5" << endl;
	q1.enqueue(5);
	cout << "Size of Q1 is " << q1.size() << endl;

	cout << "Enqueue 6" << endl;
	q1.enqueue(6);
	cout << "Size of Q1 is " << q1.size() << endl;

	cout << "Enqueue 7" << endl;
	q1.enqueue(7);
	cout << "Size of Q1 is " << q1.size() << "\n\n";


	for (int i = 0; i < 3; i++)
	{
		cout << "Element on top is " << q1.front() << "  Removing it" << endl;
		q1.pop();
		cout << "Size of Q1 after this removal is " << q1.size() << "\n\n";

	}


	return 0;
}