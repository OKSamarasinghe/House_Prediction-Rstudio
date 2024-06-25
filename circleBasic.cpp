#include <iostream>
using namespace std;

class queuex
{
private:
    int *queArr;
    int size;
    int front;
    int rear;
    int nitems;

public:
    queuex(int n);
    ~queuex();
    void insertQue(int j); // insert into back of the queue
    int removeQue();       // remove from front
    int peekFront();       // peek front of the queue
    bool isFull();
    bool isEmpty();
    void print();
};

queuex::queuex(int n)
{
    size = n;
    queArr = new int[n];
    front = 0;
    rear = -1;
    nitems = 0;
}

queuex::~queuex()
{
    delete[] queArr; // Free the allocated memory in the destructor
}

bool queuex::isEmpty()
{
    return (rear == -1);
}

bool queuex::isFull()
{
    return (rear == (size - 1));
}

void queuex::insertQue(int j)
{
    if (isFull())
        cout << "Queue is full" << endl;
    else
    {
        if (rear == (size - 1))
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queArr[rear] = j;
        nitems++;
    }
}

int queuex::removeQue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1; // Or throw an exception to indicate underflow
    }
    else
    {
        int temp = queArr[front];
        nitems--;
        if (front == (size - 1))
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return temp;
    }
}

int queuex::peekFront()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1; // Or throw an exception to indicate underflow
    }
    else
    {
        return queArr[front];
    }
}

void queuex::print()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
        {
            cout << queArr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    queuex myQueue(5);

    myQueue.insertQue(5);
    myQueue.insertQue(4);
    myQueue.insertQue(7);
    myQueue.print();

    cout << "Front element: " << myQueue.peekFront() << endl;

    cout << "Removed element: " << myQueue.removeQue() << endl;
    myQueue.print();
    return 0;
}
