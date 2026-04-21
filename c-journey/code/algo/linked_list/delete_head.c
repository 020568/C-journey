Listnode* todelete=head;
head=head->next;
free(todelete);