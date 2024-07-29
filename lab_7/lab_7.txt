#include <iostream>
#include <stdexcept>
using namespace std;

class List {
protected:
    int* data;
    int size;
public:
    static int count;
    List() : data(nullptr), size(0) {}
    List(int n) : data(new int[n]), size(n) {}
    List(const List& other) : data(new int[other.size]), size(other.size) {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    ~List() {
        delete[] data;
    }
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int getSize() const {
        return size;
    }

	void c(){
		cout << "count of element: " << count << endl;
	}

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
};

int List::count = 0;

class Stack : public List {
public:
    Stack() : List() {}
    Stack(int n) : List(n) {}
    Stack(const Stack& other) : List(other) {}
    void push(int value) {
        int* newData = new int[getSize() + 1];
        for (int i = 0; i < getSize(); i++) {
            newData[i] = (*this)[i];
        }
        newData[getSize()] = value;
        delete[] data;
        data = newData;
        size++;
		count++;
    }
    int pop() {
        if (getSize() == 0) {
            throw out_of_range("Stack is empty");
        }
        int value = (*this)[getSize() - 1];
        int* newData = new int[getSize() - 1];
        for (int i = 0; i < getSize() - 1; i++) {
            newData[i] = (*this)[i];
        }
        delete[] data;
        data = newData;
        size--;
		count--;
        return value;
    }
};

class Queue : public List {
public:
    Queue() : List() {}
    Queue(int n) : List(n) {}
    Queue(const Queue& other) : List(other) {}
    void enqueue(int value) {
        int* newData = new int[getSize() + 1];
        for (int i = 0; i < getSize(); i++) {
            newData[i] = (*this)[i];
        }
        newData[getSize()] = value;
        delete[] data;
        data = newData;
        size++;
		count++;
    }
    int dequeue() {
        if (getSize() == 0) {
            throw out_of_range("Queue is empty");
        }
        int value = (*this)[0];
        int* newData = new int[getSize() - 1];
        for (int i = 1; i < getSize(); i++) {
            newData[i - 1] = (*this)[i];
        }
        delete[] data;
        data = newData;
        size--;
		count--;
        return value;
    }
};

int main(){
	system("clear");
	cout << "Stack:" << endl;
	Stack stack(0);
	stack.push(3);
	stack.push(1);
	stack.push(4);
	stack.push(7);
	stack.push(9);
	stack.print();
	stack.c();

	stack.pop();
	stack.print();
    stack.c();
	stack.pop();
	stack.print();
    stack.c();
	stack.pop();
	stack.print();
    stack.c();
	stack.pop();
	stack.print();
    stack.c();
	stack.pop();
	stack.print();
	stack.c();
	//stack.pop(); //при удалении несуществующего объекта происходит завершение програнны через исклюсения

	cout << endl;

	cout << "Queue:" << endl;
	Queue queue(0);
	queue.enqueue(4);
	queue.enqueue(2);
	queue.enqueue(6);
	queue.enqueue(3);
	queue.enqueue(8);
	queue.print();
	queue.c();

	queue.dequeue();
	queue.print();
	queue.c();
	queue.dequeue();
	queue.print();
	queue.c();
	queue.dequeue();
	queue.print();
	queue.c();
	queue.dequeue();
	queue.print();
	queue.c();
	queue.dequeue();
	queue.print();
	queue.c();
	//queue.dequeue();
}