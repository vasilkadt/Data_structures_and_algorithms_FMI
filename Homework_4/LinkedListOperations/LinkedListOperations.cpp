#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
	while (node) {
		fout << node->data;

		node = node->next;

		if (node) {
			fout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
	if (position == 0)
	{
		SinglyLinkedListNode* newHead = new SinglyLinkedListNode(data);
		newHead->next = llist;
		llist = newHead;
		return llist;
	}
	else if (llist == nullptr)
	{
		throw out_of_range("Invalid insert index. list is empty");
	}
	else
	{
		SinglyLinkedListNode* current = llist;
		SinglyLinkedListNode* previous = nullptr;
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
		previous->next = new SinglyLinkedListNode(data);
		previous->next->next = current;
	}
	return llist;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position)
{
	if (position == 0)
	{
		SinglyLinkedListNode* current = llist;
		llist = llist->next;
		delete current;
		return llist;
	}
	else if (llist == nullptr)
	{
		throw out_of_range("Invalid insert index. list is empty");
	}
	else
	{
		SinglyLinkedListNode* current = llist;
		SinglyLinkedListNode* previous = nullptr;
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
		delete current;
	}
	return llist;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
	int firstLenght = 0;
	int secondLenght = 0;

	SinglyLinkedListNode* temp1 = head1;
	SinglyLinkedListNode* temp2 = head2;
	while (head1 != nullptr)
	{
		firstLenght++;
		head1 = head1->next;
	}

	while (head2 != nullptr)
	{
		secondLenght++;
		head2 = head2->next;
	}

	int meetPoint = 0;
	int startPoint = abs(firstLenght - secondLenght);
	if (firstLenght > secondLenght)
	{
		for (int i = 0; i < startPoint; i++)
		{
			temp1 = temp1->next;
		}
	}
	else
	{
		for (int i = 0; i < startPoint; i++)
		{
			temp2 = temp2->next;
		}
	}

	while (temp1 != nullptr)
	{
		if (temp1 == temp2)
		{
			meetPoint = temp1->data;
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return meetPoint;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int tests;
	cin >> tests;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
		int index;
		cin >> index;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		SinglyLinkedList* llist1 = new SinglyLinkedList();

		int llist1_count;
		cin >> llist1_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist1_count; i++) {
			int llist1_item;
			cin >> llist1_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist1->insert_node(llist1_item);
		}

		SinglyLinkedList* llist2 = new SinglyLinkedList();

		int llist2_count;
		cin >> llist2_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist2_count; i++) {
			int llist2_item;
			cin >> llist2_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist2->insert_node(llist2_item);
		}

		SinglyLinkedListNode* ptr1 = llist1->head;
		SinglyLinkedListNode* ptr2 = llist2->head;

		for (int i = 0; i < llist1_count; i++) {
			if (i < index) {
				ptr1 = ptr1->next;
			}
		}

		for (int i = 0; i < llist2_count; i++) {
			if (i != llist2_count - 1) {
				ptr2 = ptr2->next;
			}
		}

		ptr2->next = ptr1;

		int result = findMergeNode(llist1->head, llist2->head);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}