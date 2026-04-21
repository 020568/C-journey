// insert a new node with value 0 at the head of the single linked list
struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
newNode->val = 0;
newNode->next = head;
head = newNode;

// now the linked list becomes 0 -> 1 -> 2 -> 3 -> 4 -> 5

//Local variables disappear once they are used up, while the head remains. 
//First, let the newly created newnode point to the original head, 
//and then let the head take the value of newnode. This way, the update is completed.