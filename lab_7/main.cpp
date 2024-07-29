#include <iostream>
#include <stdexcept>
using namespace std;

class List {
    protected:
    int *data;
    int size;

    public:
    List() : data(nullptr), size(0){}

    List(int size) : size(size){
        if(size > 0){
            data = new int[size];
        } else{
            throw invalid_argument("The size of the list must be positive");
        }
    }

    ~List(){
        delete[] data;
    }

    virtual void addAnElement(int value){}

    virtual void deleteAnElement(){}

    void showList(){
        cout << "List: ";
        for(int i; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class Stack : public List {
    public:
    Stack(int size) : List(size){}

    void addAnElement(int value) override{
        if(size < List::size){
            data[size++] = value;
        } else{
            throw overflow_error("Stack is full");
        }
    }

    void deleteAnElement() override{
        if(size > 0){
            --size;
        } else{
            throw underflow_error("Stack is empty");
        }
    }
};

class Queue : public List {
    public:
    Queue(int size) : List(size){}

    void addAnElement(int value) override{
        if(size < List::size){
            for(int i = size - 1; i >= 0; --i){
                data[i + 1] = data[i];
            }
            data[0] = value;
            ++size;
        } else{
            throw overflow_error("Queue is full");
        }
    }

    void deleteAnElement() override{
        if(size > 0){
            --size;
        } else{
            throw underflow_error("Queue is empty");
        }
    }
};

int main(){
    try {
        Stack stack(5);
        stack.addAnElement(1);
        stack.addAnElement(2);
        stack.addAnElement(3);
        stack.showList();

        stack.deleteAnElement();
        stack.showList();

        Queue queue(5);
        queue.addAnElement(1);
        queue.addAnElement(2);
        queue.addAnElement(3);
        queue.showList();

        queue.deleteAnElement();
        queue.showList();
    } catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}