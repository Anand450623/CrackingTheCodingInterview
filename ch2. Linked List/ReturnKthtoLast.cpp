/*
 * Problem   : Implement algorithm to find the kth to last element of a singly linked list.
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

node* findKthToLast(node *head, int k)
{

	node* runner = head;
	for(int i=0; i<k; i++)
	{
		if(runner!=nullptr)
			runner = runner->next;
		else
			return nullptr;
	}

	node* current=head;
	while(runner != NULL)
	{
		runner = runner->next;
		current = current->next;
	}

	return current;

}

int main()
{

	node* head = nullptr;

	head = initialize(head);
	displayListData(head);

	for(int k=0; k<10; k++)
	{
		// please note that zero last doesn't make any sense.
		node* kth = findKthToLast(head, k);
		if(kth == nullptr)
			cout<<"Link out of bounds"<<endl;
		else
			cout<<"The "<<k<<"th last element is = "<<kth->data<<endl;

	}

	return 0;

}
