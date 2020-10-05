/*
 * Problem   : Implement algorithm to delete a node in the middle of a singly linked list, given access to only that node.
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

node* initialize(node* head)
{

	head = createNewNode(0);
	head->next = createNewNode(0);
	head->next->next = createNewNode(1);
	head->next->next->next = createNewNode(1);
	head->next->next->next->next = createNewNode(2);

	return head;

}

bool deleteItemsFromList(node *current)
{

	// node should not be first or last
	if(current == nullptr || current->next ==nullptr)
		return false; //failure

	node* next = current->next;
	current->data = next->data;
	current->next = next->next;
	return true;

}

int main()
{

	node* head = nullptr;

	head = initialize(head);
	displayListData(head);

	if(deleteItemsFromList(head->next->next))
	{
		cout<<"Item deleted successfully, please find the new list contents as follows: ";
		displayListData(head);
	}
	else
	{
		cout<<"Some Error occured"<<endl;
	}

	return 0;

}
