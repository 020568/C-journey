//head
// insert a new node 0 at the head of the doubly linked list
struct DoublyListNode* newHead = (struct DoublyListNode*)malloc(sizeof(struct DoublyListNode));
newHead->val = 0;
newHead->prev = NULL;
newHead->next = head;
head->prev = newHead;
head = newHead;
// now the list becomes 0 -> 1 -> 2 -> 3 -> 4 -> 5


//tail
struct DoublyListNode* tail = head;
// first, go to the last node of the linked list
while (tail->next != NULL) {
    tail = tail->next;
}

// insert a new node with value 6 at the end of the doubly linked list
struct DoublyListNode* newNode = (struct DoublyListNode*)malloc(sizeof(struct DoublyListNode));
newNode->val = 6;
newNode->next = NULL;
tail->next = newNode;
newNode->prev = tail;
// update the tail node reference
tail = newNode;
// now the linked list becomes 1 -> 2 -> 3 -> 4 -> 5 -> 6


//middle

// if we want to insert at index 3 (4th node)
// we need to operate the node at index 2
struct DoublyListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}

// assemble the new node
struct DoublyListNode* newNode = (struct DoublyListNode*)malloc(sizeof(struct DoublyListNode));
newNode->val = 66;
newNode->next = p->next;
newNode->prev = p;

// insert the new node
p->next->prev = newNode;
p->next = newNode;

// now the linked list becomes 1 -> 2 -> 3 -> 66 -> 4 -> 5


	






