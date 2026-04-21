struct Listnode*p=head;
for(int i=0;i<2;i++)
{
	p=p->next;
}
struct Listnode* todeletenode=p->next;
p->next=p->next->next;

free(todeletenode);

