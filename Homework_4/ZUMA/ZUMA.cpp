#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* previous;
	Node* next;
};

class linkedList
{
private:
	Node* head;
	Node* tail;

public:
	linkedList()
	{
		head = tail = nullptr;
	}

	Node* getHead() const
	{
		return head;
	}

	Node* getTail() const
	{
		return tail;
	}

	void push_back(int data)
	{
		Node* nodeToAdd = new Node;
		nodeToAdd->data = data;
		nodeToAdd->previous = tail;
		nodeToAdd->next = nullptr;
		if (head == nullptr)
		{
			head = nodeToAdd;
			tail = nodeToAdd;
		}
		else
		{
			tail->next = nodeToAdd;
			tail = tail->next;
		}
	}

	void insert(Node* current, int data)
	{
		Node* nodeToAdd = new Node;
		nodeToAdd->data = data;
		nodeToAdd->next = current->next;
		if (nodeToAdd->next != nullptr)
		{
			nodeToAdd->next->previous = nodeToAdd;
		}
		current->next = nodeToAdd;
		nodeToAdd->previous = current;
		if (current == tail)
		{
			tail = nodeToAdd;
		}
	}

	int remove(Node* left, Node* right)
	{
		int counter = 1;
		while (left->previous != nullptr && left->previous->data == left->data)
		{
			left = left->previous;
			counter++;
		}
		while (right->next != nullptr && right->next->data == left->data)
		{
			right = right->next;
			counter++;
		}

		if (counter >= 3)
		{
			if (left->previous == nullptr)
			{
				if (right->next == nullptr)
				{
					head = nullptr;
					tail = nullptr;
				}
				else
				{
					head = right->next;
					head->previous = nullptr;
				}
			}
			else if (right->next == nullptr)
			{
				tail = left->previous;
				tail->next = nullptr;
			}
			else
			{
				Node* newLeft = left->previous;
				Node* newRight = right->next;
				newLeft->next = newRight;
				newRight->previous = newLeft;
				if (newLeft->data == newRight->data)
				{
					counter += remove(newLeft, newLeft);
				}
			}
			return counter;
		}
		return 0;
	}
};

Node* balls[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	linkedList* lst = new linkedList();
	int N, Q;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int color;
		cin >> color;
		lst->push_back(color);
		balls[i] = lst->getTail();
	}
	cin >> Q;
	int ballCount = N;
	for (int i = 0; i < Q; i++)
	{
		int ballPosition, ballColor;
		cin >> ballPosition >> ballColor;
		if (lst->getHead() == nullptr)
		{
			cout << "Game Over\n";
			continue;
		}

		lst->insert(balls[ballPosition], ballColor);
		balls[ballCount++] = balls[ballPosition]->next;
		cout << lst->remove(balls[ballPosition]->next, balls[ballPosition]->next) << endl;
	}

	if (lst->getHead() == nullptr)
	{
		cout << -1 << endl;
	}
	else
	{
		Node* curr = lst->getHead();
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
}
