/*
 * Problem   : write code to remove duplicates from an unsorted linked list.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;

node* createNewNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void  displayListData(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* removeDuplicatesUsingHashTable(node *head)
{

	set<int> s;
	node* previous = head;
	node* newList = previous;
	if(head->next !=  NULL)
	{
		head = head->next;
	}

	s.insert(previous->data);

	while(head!=nullptr)
	{

		if(s.find(head->data) == s.end())
		{
			s.insert(head->data);
			previous->next = head;
			previous = previous->next;
		}

		head = head->next;

	}

	return newList;

}

node* removeDuplicatesUsingLoops(node* head)
{

	for(node* current=head; current!=nullptr; current=current->next)
	{
		for(node* runner= current; runner->next!=nullptr; runner=runner->next)
		{
			if(runner->next->data == current->data)
				runner->next = runner->next->next;
		}
	}

	return head;

}

node* initialize(node* head)
{

	head = createNewNode(0);
	head->next = createNewNode(0);
	head->next->next = createNewNode(1);
	head->next->next->next = createNewNode(1);
	head->next->next->next->next = createNewNode(2);

	return head;

}

int main()
{

	node* head = nullptr;

	head = initialize(head);
	displayListData(head);

	head = removeDuplicatesUsingHashTable(head);
	displayListData(head);

	head = initialize(head);
	displayListData(head);

	head = removeDuplicatesUsingLoops(head);
	displayListData(head);

	return 0;

}
