// create a singly linked list
int arr[] = {1, 2, 3, 4, 5};
struct ListNode* head = createLinkedList(arr, 5);

// insert a new node 66 after the 3rd node
// first, find the predecessor node, i.e., the 3rd node
struct ListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}
// now p points to the 3rd node
// set the next pointer of the new node
struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
newNode->val = 66;
newNode->next = p->next;

// insert the new node
p->next = newNode;

// now the linked list becomes 1 -> 2 -> 3 -> 66 -> 4 -> 5