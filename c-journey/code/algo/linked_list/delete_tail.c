struct Listnode* p=head;
while(p->next->next!=NULL)
{
	p=p->next;
}

p->next=NULL;













