/*
 * Problem   : Implement algorithm to partition a linked list around a value x, such that all nodes less than x comes before all nodes greater or equal to x.
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

	head = createNewNode(3);
	head->next = createNewNode(5);
	head->next->next = createNewNode(8);
	head->next->next->next = createNewNode(5);
	head->next->next->next->next = createNewNode(10);
	head->next->next->next->next->next = createNewNode(2);
	head->next->next->next->next->next->next = createNewNode(1);

	return head;

}

node* stablePartition(node *head, int key)
{

	node* beforeStart = nullptr;
	node* beforeEnd = nullptr;
	node* afterStart = nullptr;
	node* afterEnd = nullptr;

	while(head != nullptr)
	{

		if(head->data < key)
		{
			if(beforeStart==nullptr)
			{
				beforeStart = head;
				beforeEnd = head;
			}
			else
			{
				beforeEnd->next = head;
				beforeEnd = beforeEnd->next;
			}
		}
		else
		{
			if(afterStart == nullptr)
			{
				afterStart = head;
				afterEnd = head;
			}
			else
			{
				afterEnd->next = head;
				afterEnd = afterEnd->next;
			}
		}

		head = head->next;

	}

	if(beforeStart == nullptr)
		return afterStart;

	beforeEnd->next = afterStart;
	afterEnd->next = nullptr;

	return beforeStart;

}

node* unstablePartition(node* root, int key)
{

	node* head = root;
	node* tail = root;

	while(root != nullptr)
	{
		node* next = root->next;
		if(root->data < key)
		{
			root->next = head;
			head = root;
		}
		else
		{
			tail->next = root;
			tail = root;
		}
		root = next;
	}

	tail->next = nullptr;

	return head;

}


int main()
{

	node* head = nullptr;

	head = initialize(head);
	displayListData(head);

	head = stablePartition(head, 5);
	displayListData(head);

	head = initialize(head);
	displayListData(head);

	head = unstablePartition(head, 5);
	displayListData(head);

	return 0;

}
