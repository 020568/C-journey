// insert a new node with value 6 at the end of the linked list
struct ListNode* p = head;
// first, go to the last node of the linked list
while (p->next != NULL) {
    p = p->next;
}
// now p is the last node of the linked list
// insert a new node after p
p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
p->next->val = 6;
p->next->next = NULL;

// now the linked list becomes 1 -> 2 -> 3 -> 4 -> 5 -> 6