struct Listnode* mergeTwoLists(struct Listnode* l1,struct Listnode* l2)
{
	struct Listnode dummy;
	dummy.val=-1;
	dummy.next=NULL;
	struct Listnode* p=&dummy;//!!!!
	struct Listnode* p1=l1;
	struct Listnode* p2=l2;
	
	while(p1 !=NULL && p2!=NULL)
	{
		if(p1->val>p2->val)
		{
			p->next=p2;
			p2=p2->next;
		}
		else
		{
			p->next=p1;
			p1=p1->next;
		}
		p=p->next;
	}
	
	if(p1!=NULL)
	{
		p->next=p1;
	}
	
	if(p2!=NULL)
	{
		p->next=p2;
	}
	
	return dummy.next;
	
	
}