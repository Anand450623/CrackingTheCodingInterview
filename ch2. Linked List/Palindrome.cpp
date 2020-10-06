/*
 * Problem   : Implement Algorithm to check whether a list is palindrome or not.
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

	head = createNewNode(6);
	head->next = createNewNode(2);
	head->next->next = createNewNode(0);
	head->next->next->next = createNewNode(2);
	head->next->next->next->next = createNewNode(5);

	return head;

}

int main()
{

	node* head = nullptr;

	head = initialize(head);
	displayListData(head);

	stack<int> s;
	node* sp = head;
	node* fp = head;

	while( fp!= nullptr && fp->next != nullptr)
	{
		s.push(sp->data);
		sp = sp->next;
		fp = fp->next->next;
	}

	// check for odd length of linked list
	if(fp!=nullptr)
		sp = sp->next;

	while(sp!=nullptr)
	{
		if(s.top()!=sp->data)
			break;
		s.pop();
		sp =sp->next;
	}

	if(sp == nullptr && s.empty())
		cout<<"Linked list is palindrome"<<endl;
	else
		cout<<"Linked list is not palindrome"<<endl;

	return 0;

}
