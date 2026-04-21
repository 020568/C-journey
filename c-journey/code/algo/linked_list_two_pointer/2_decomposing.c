struct Listnode
{
	int val;
	struct Listnode* next;
};



struct Listnode* partition(struct Listnode* head,int x)
{
	struct Listnode dummy1;
	dummy1.val=-1;
	dummy1.next=NULL;
	
	struct Listnode dummy2;
	dummy2.val=-1;
	dummy2.next=NULL;
	
	struct Listnode* p1=&dummy1;
	struct Listnode* p2=&dummy2;
	struct Listnode* p=head;
	
	while(p!=NULL)
	{
		if(p->val<x)
		{
			p1->next=p;
			p1=p1->next;
		}
		else
		{
			p2->next=p;
			p2=p2->next;
		}
		
		struct Listnode* temp=p->next;
		p->next=NULL;
		p=temp;
		
	}
	
	
	p1->next=dummy2.next;
	
	return dummy1.next;

	
}