#include <iostream>
using namespace std;

template <typename T>
class Node 
{
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) 
        : data(value),
        next(nullptr),
        prev(nullptr) 
    { }
};

template <typename T>
class DoublyLinkedList 
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() 
        : head(nullptr), 
        tail(nullptr)
    { }

    ~DoublyLinkedList() 
    {
        while (head != nullptr) 
        {
            removeFromHead();
        }
    }

    void addToHead(T value) 
    {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToTail(T value) 
    {
        Node<T>* newNode = new Node<T>(value);

        if (tail == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFromHead() 
    {
        if (head == nullptr) 
        {
            cerr << "List is empty. Cannot remove from head." << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        if (head != nullptr) 
        {
            head->prev = nullptr;
        }
        else 
        {
            tail = nullptr;  // If the list becomes empty after removal
        }

        delete temp;
    }

    void removeFromTail()
    {
        if (tail == nullptr)
        {
            std::cerr << "List is empty. Cannot remove from tail." << std::endl;
            return;
        }

        Node<T>* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) 
        {
            tail->next = nullptr;
        }
        else 
        {
            head = nullptr;  // If the list becomes empty after removal
        }

        delete temp;
    }

    void display()
    {
        Node<T>* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insertAt(T value, int position) 
    {
        //Node<T>* newNode = new Node<T>(value);

        if (head == nullptr || position == 0)
        {
            this->addToHead(value);
        }
        else 
        {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            int currentPosition = 0;

            while (currentPosition < position - 1 && current->next != nullptr)
            {
                current = current->next;
                currentPosition++;
            }

            newNode->next = current->next;
            if (current->next != nullptr) 
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;

            if (newNode->next == nullptr) 
            {
                tail = newNode;
            }
        }
    }
};

int main() 
{
    DoublyLinkedList<int> myList;

    myList.addToHead(1);
    myList.addToTail(2);
    myList.addToHead(3);
    myList.display();

    myList.removeFromHead();
    myList.display();

    myList.removeFromTail();
    myList.display();

    myList.insertAt(1, 0);
    myList.insertAt(2, 1);
    myList.insertAt(3, 1);
    myList.display();

    return 0;
}
