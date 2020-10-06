/*
 * Problem   : Two numbers are given by link list, where each node represents a digit of number. Implement function to add two numbers.
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

node* initialize1(node* head)
{

	head = createNewNode(6);
	head->next = createNewNode(2);
	head->next->next = createNewNode(0);
	head->next->next->next = createNewNode(0);

	return head;

}

node* initialize2(node* head)
{

	head = createNewNode(8);
	head->next = createNewNode(8);
	head->next->next = createNewNode(0);

	return head;

}

node* summation(node* head1, node* head2, int& carry)
{

	if(head1 == nullptr && head2 == nullptr)
		return nullptr;

	node* sum = summation(head1->next, head2->next, carry);
	int val = carry+head1->data+head2->data;
	node* temp = createNewNode(val%10);
	temp->next = sum;
	sum = temp;
	carry = val/10;
	return sum;

}

int getListLength(node* head)
{
	int count = 0;
	while(head != nullptr)
	{
		count++;
		head = head->next;
	}
	return count;
}

node* paddList(node* head, int padd)
{
	for(int i=0; i<padd; i++)
	{
		node* temp = createNewNode(0);
		temp->next = head;
		head = temp;
	}
	return head;
}

int main()
{

	node* head1 = nullptr;
	node* head2 = nullptr;

	head1 = initialize1(head1);
	head2 = initialize2(head2);

	displayListData(head1);
	displayListData(head2);

	int l1 = getListLength(head1);
	int l2 = getListLength(head2);

	if(l1 > l2)
	{
		head2 = paddList(head2, l1-l2);
	}
	else
	{
		head1 = paddList(head1, l2-l1);
	}

	displayListData(head1);
	displayListData(head2);

	int carry = 0;
	node* sum = summation(head1, head2, carry);
	if(carry == 1)
	{
		node* temp = createNewNode(1);
		temp->next = sum;
		sum = temp;
	}
	displayListData(sum);

	return 0;

}
