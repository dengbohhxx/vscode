#include <iostream>
using namespace std;
struct listnode
{
    int val;
    struct listnode *next;
    listnode(int x) : val(x), next(NULL) {}
};
class List
{
public:
    List()
    {
        int x;
        head = new listnode(0);
        listnode *p = head;
        while (cin >> x)
        {
            listnode *q = new listnode(x);
            p->next = q;
            p = p->next;
        }
        head = head->next;
    }
    void print()
    {
        listnode *p = head;
        while (p != NULL)
        {
            cout << p->val << endl;
            p = p->next;
        }
    }
    void add_to_tail(int value)
    {
        listnode *pnew = new listnode(value);
        if (head == NULL)
        {
            head = pnew;
        }
        else
        {
            listnode *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = pnew;
        }
    }

private:
    listnode *head;
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
/*
void add_to_tail(listnode* head,int value)
    {
        listnode *pnew = new listnode(value);
        if (head == NULL)
        {
            head = pnew;
        }
        else
        {
            listnode *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = pnew;
        }
    }
    */
/*
void add_to_tail(listnode **head, int value)
{
    listnode *pnew = new listnode(value);
    if (*head == NULL)
    {
        *head = pnew;
    }
    else
    {
        listnode *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = pnew;
    }
}*/
//修改指针，使用指针的指针和指针的引用
void add_to_tail(listnode*&head,int value)
    {
        listnode *pnew = new listnode(value);
        if (head == NULL)
        {
            head = pnew;
        }
        else
        {
            listnode *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = pnew;
        }
    }
int main()
{
    /*
    List list;
    list.print();
    cout << "*****************" << endl;
    list.add_to_tail(1000000);
    list.print();
    cout << "+++++++++++++++++++++++++" << endl;
    */
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
    //add_to_tail(&head, 999);
    add_to_tail(head,999);
    print(head);
    return 0;
}