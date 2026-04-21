#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode
{
	int val;
	struct Listnode* next;
}Listnode;

Listnode* creat_linked_listnode(int* arr,int arr_size)
{
	if(arr==NULL || arr_size==0)
	{
		return NULL;
	}
	
	Listnode* head =(struct Listnode*)malloc(sizeof(Listnode));
	head->val=arr[0];
	head->next=NULL;
	
	Listnode* curr = head;
	
	for(int i=1;i<arr_size;i++)
	{
		curr->next=(Listnode*)malloc(sizeof(Listnode));//identify a listnode
		curr->next->val=arr[i];
		curr->next->next=NULL;
		curr=curr->next;
		
	}
	
	return head;
	
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	Listnode* head=creat_linked_listnode(arr,sizeof(arr)/sizeof(arr[0]));
	
	for(Listnode* p=head;p!=NULL;p=p->next)//important!!!!!!
	{
		printf("%d ",p->val);
	}
	
	
	
	
	
	
}



