//middle
// delete the 4th node
// first find the 3rd node
struct DoublyListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}

// now p points to the 3rd node, we remove the node after it
struct DoublyListNode* toDelete = p->next;

// remove toDelete from the list
p->next = toDelete->next;
toDelete->next->prev = p;

// setting toDelete's previous and next pointers to null is a good habit (optional)
toDelete->next = NULL;
toDelete->prev = NULL;

// now the list becomes 1 -> 2 -> 3 -> 5



//head
// delete the head node
struct DoublyListNode* toDelete = head;
head = head->next;
head->prev = NULL;

// clear the pointers of the deleted node
toDelete->next = NULL;

// now the linked list becomes 2 -> 3 -> 4 -> 5



//tail
// delete the tail node
struct DoublyListNode* p = head;
// find the tail node
while (p->next != NULL) {
    p = p->next;
}

// now p points to the tail node
// remove the tail node from the list
p->prev->next = NULL;

// it's a good habit to disconnect all pointers of the deleted node (optional)
p->prev = NULL;

// now the list becomes 1 -> 2 -> 3 -> 4












