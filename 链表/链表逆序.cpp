#include <iostream>
using namespace std;
struct listnode
{
    int val;
    struct listnode *next;
    listnode(int x) : val(x), next(NULL) {}
};
void print(listnode *head)
{
    listnode *p = head;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}
void reverseprint(listnode * phead)
{
    if(phead!=NULL)
    {
        if(phead->next!=NULL)
            reverseprint(phead->next);
         cout<<phead->val<<endl;   
    }
}
int main()
{
    listnode *head = new listnode(0);
    listnode *p = head;
    int x;
    while (cin >> x)
    {
        listnode *q = new listnode(x);
        p->next = q;
        p = p->next;
    }
    head = head->next;
    print(head);
    cout << "**************************" << endl;
    reverseprint(head);
     cout << "**************************" << endl;

    return 0;
}