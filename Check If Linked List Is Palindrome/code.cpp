/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/

bool isPalindrome(Node *head)
{
    if(head == NULL)
        return true;

    Node *p1 = head;
    Node *p2 = head;

    while(p2->next && p2->next->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1;
    p1 = p1->next;
    p2->next = nullptr;

    while(p1){
        Node *curr = p1->next;
        p1->next = p2;
        p2 = p1;
        p1 = curr;
    }

    p1 = head;
    while(p1){
        if(p1->data != p2->data)
            return false;
        else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return true;
}
