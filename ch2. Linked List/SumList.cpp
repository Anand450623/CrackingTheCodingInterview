/*
 * Problem   : Two numbers are given by link list, where each node represents a digit of number. Implement function to add two numbers.
 * Note      : Each number is represented in reverse order.
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

	head = createNewNode(7);
	head->next = createNewNode(1);
	head->next->next = createNewNode(6);

	return head;

}

node* initialize2(node* head)
{

	head = createNewNode(3);
	head->next = createNewNode(8);
	head->next->next = createNewNode(3);

	return head;

}

// Recursive
node* summation(node* head1, node* head2, int carry)
{

	if(head1 == nullptr && head2 == nullptr && carry == 0)
		return NULL;

	int res = carry;
	if(head1 != NULL)
		res += head1->data;

	if(head2 != NULL)
		res += head2->data;

	node* result = createNewNode(res%10);
	if(head1 != nullptr || head2 != nullptr)
	{
		node* more = summation(head1 == nullptr? nullptr: head1->next, head2 == nullptr? nullptr: head2->next, res >= 10?1:0);
		result->next = more;
	}

	return result;

}

// Iterative
node* iterativeSummation(node* head1, node* head2)
{

	node* result = createNewNode(0);
	node* ptr = result;
	int carry = 0;
	while(head1 != nullptr || head2 != nullptr || carry != 0)
	{

		int res = carry;
		if(head1 != nullptr)
		{
			res += head1->data;
			head1 = head1->next;
		}

		if(head2 != nullptr)
		{
			res += head2->data;
			head2 = head2->next;
		}

		result->data = res%10;
		carry = res>=10 ?1:0;

		if(head1 != nullptr || head2 != nullptr || carry != 0)
		{
			result->next = createNewNode(0);
			result = result->next;
		}

	}

	result = nullptr;

	return ptr;

}

int main()
{

	node* head1 = nullptr;
	node* head2 = nullptr;

	head1 = initialize1(head1);
	head2 = initialize2(head2);

	displayListData(head1);
	displayListData(head2);

	node* sum = summation(head1, head2, 0);
	displayListData(sum);

	displayListData(head1);
	displayListData(head2);

	node* sumptr = iterativeSummation(head1, head2);
	displayListData(sumptr);

	return 0;

}
