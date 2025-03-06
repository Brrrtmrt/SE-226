#include <iostream>
#include <memory>


/* MANUAL FOR QUEUE 


     INIT: Queue foo{};

*/

class Node
{
    using NodePtr = std::unique_ptr<Node>;

public:
    int data;
    NodePtr next;

    Node(int val) : data{val}, next{nullptr}
    {
    }
};

class LinkedList
{
    using NodePtr = std::unique_ptr<Node>;

public:
    int size;

    LinkedList(int val) : head{std::make_unique<Node>(val)}, tail{head.get()}, size{1}
    {
    }
    NodePtr head; // owns memory
    Node *tail;   // slave
};

class Queue
{
private:
    LinkedList list;

public:
    Queue(int data) : list{data}
    {
    }
    void enqueue(int val)
    {
        if (list.head == nullptr)
        {   
            list.head=std::make_unique<Node>(val);
            list.size++;
            return;
        }

        list.tail->next = std::make_unique<Node>(val);
        list.tail=list.tail->next.get();
       
        list.size++;
        return;
    }
    bool dequeue() noexcept { //move does not throw
		
		if (list.head == nullptr)
			return false;
        	if (list.size == 1) {
			list.head = std::move(list.head->next);
			if (list.head == nullptr) {
				list.tail = nullptr;
			}
			list.size--;
			return true;
		}

		size_t iter = 0;
		auto curr = list.head.get();
		while (curr && iter < list.size - 1) {
			curr = curr->next.get();
			iter++;
		}
		if (curr && curr->next) {
			if (curr->next.get() == list.tail) { 
				list.tail = curr;
			}
			curr->next = std::move(curr->next->next);
			list.size--;
			return true;
		}
		return false;

	}
    int top() noexcept
    {
        if (list.head == nullptr || list.size == 0)
        {
            return -1;
        }
        return list.tail->data;
    }
    bool isEmpty() noexcept
    {
        return list.size == 0;
    }
    int size()
    {
        return list.size;
    }
    void printqueue()
    {
        if (list.head == nullptr)
        {
            return;
        }
        auto temp = list.head.get();
        while (temp != nullptr)
        {
            std::cout << temp->data;
            temp = temp->next.get();
        }
        return;
    }
};

int main()
{
 /*   using namespace std;
    Queue q{0};
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();

    q.printqueue();
    cout << boolalpha << q.isEmpty();
    cout << q.top();
    cout << q.size();
    */
}
