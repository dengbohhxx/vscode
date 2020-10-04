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
//头插法
listnode *reverselist1(listnode *phead)
{
    if (phead == NULL)
        return phead;
    listnode *newhead = phead;
    listnode *p = phead->next;
    while (p != NULL)
    {
        phead->next = p->next;
        p->next = newhead;
        newhead = p;
        p = phead->next;
    }
    return newhead;
}
//尾插法
listnode *reverselist2(listnode *phead)
{
    if (phead==NULL)
        return phead;
    listnode * pre=NULL;
    listnode * p=NULL;
    while(phead!=NULL)
    {
        p=phead->next;
        phead->next=pre;
        pre=phead;
        phead=p;
    }
    return pre;
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
    cout<<"顺序打印列表:"<<endl;
    print(head);
    cout << "**************************" << endl;
     //cout<<"头插法:"<<endl;
    //listnode *newhead=reverselist1(head);
    //print(newhead);
    //cout << "**************************" << endl;
    cout<<"尾插法:"<<endl;
    listnode *newhead1=reverselist2(head);
    print(newhead1);
    cout << "**************************" << endl;

    return 0;
}