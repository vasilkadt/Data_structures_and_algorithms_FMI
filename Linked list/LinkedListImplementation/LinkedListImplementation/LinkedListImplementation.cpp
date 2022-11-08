#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}

	Node(int value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};

class List
{
private:
	Node* head;
	Node* tail;

public:

	//default constructor
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	//destructor
	~List()
	{
		Node* cur = head;
		Node* prev = nullptr;
		while (cur != nullptr)
		{
			prev = cur->next;
			delete cur;
			cur = prev;
		}
	}

	//insert element at the end
	void push_back(int element)
	{
		if (head == nullptr)
		{
			head = new Node(element, nullptr);
			tail = head;
		}
		else
		{
			tail->next = new Node(element, nullptr);
			tail = tail->next;
		}
	}

	//insert element at the beginning
	void push_front(int element)
	{
		Node* newHead = new Node(element, head);
		head = newHead;
		if (tail == nullptr) 
		{
			tail = head;
		}
	}

	//print elements
	void print() const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << "\n";
	}

	//insert element at position
	void insert(int element, int position)
	{
		if (position == 0)
		{
			push_front(element);
			return;
		}
		else if (head == nullptr)
		{
			throw out_of_range("Invalid insert index. list is empty");
		}
		else
		{
			Node* current = head;
			Node* previous = nullptr;
			for (int i = 0; i < position; i++)
			{
				if (current->next != nullptr)
				{
					previous = current;
					current = current->next;
				}
				else
				{
					throw out_of_range("Cannot insert in invalid position");
				}
			}
			previous->next = new Node(element, current);
			if (tail == previous)
			{
				tail = previous->next;
			}
		}
	}

	//delete first element
	void pop_front()
	{
		Node* current = head;
		head = head->next;
		delete current;
	}

	//delete last element
	void pop_back()
	{
		Node* current = head;
		Node* previous = nullptr;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = nullptr;
		delete current;
	}

	//remove element at position
	void remove(int position)
	{
		if (position == 0)
		{
			pop_front();
			return;
		}
		else if (head == nullptr)
		{
			throw out_of_range("Invalid remove index, list is empty");
		}
		else
		{
			Node* current = head;
			Node* previous = nullptr;
			for (int i = 0; i < position; i++)
			{
				if (current->next != nullptr)
				{
					previous = current;
					current = current->next;
				}
				else
				{
					throw out_of_range("Cannot insert in invalid position");
				}
			}
			previous->next = current->next;
			if (current == tail)
			{
				tail = previous;
			}
			delete current;
		}
	}

	//search element in list
	bool search(int element)
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			if (current->value == element)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}

	//return first element of the list
	int peek_front() {
		return head->value;
	}

	//return last element of the list
	int peek_back() {
		return tail->value;
	}

	//reverse list
	void reverse()
	{
		Node* current, * previous, * nextNode;
		current = head;
		previous = nullptr;
		nextNode = current->next;

		while (nextNode != nullptr)
		{
			current->next = previous;
			previous = current;
			current = nextNode;
			nextNode = nextNode->next;
		}
		current->next = previous;
		head->next = nullptr;

		swap(head, tail);
	}

	//clear the list
	void clear()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* previous = head;
		Node* currrent = head->next;

		while (currrent != nullptr) {
			delete previous;

			previous = currrent;
			currrent = currrent->next;
		}

		delete previous;
	}
};

int main()
{
	List list;

	list.push_front(1);
	list.push_back(5);
	list.insert(4, 1);
	list.insert(19, 2);
	list.print();
	list.reverse();
	list.print();
	list.remove(1);
	list.print();
	list.pop_back();
	list.print();
}