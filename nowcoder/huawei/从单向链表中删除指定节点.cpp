#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct listnode
{
    int val;
    listnode *next;
    listnode(int x) : val(x), next(NULL) {}
};
void print(listnode *head)
{
    listnode *p = head;
    cout << p->val;
    p = p->next;
    while (p != NULL)
    {
        cout << " " << p->val;
        p = p->next;
    }
}
int main()
{
    int num;
    while (cin >> num)
    {
        int n = 0;
        cin >> n;
        listnode *head = new listnode(n);
        num = num - 1;
        while (num--)
        {
            int first = 0;
            int second = 0;
            cin >> first >> second;
            listnode *p = head;
            while (p != NULL)
            {
                if (p->val == second)
                {
                    listnode *temp = new listnode(first);
                    temp->next = p->next;
                    p->next = temp;
                    break;
                }
                p = p->next;
            }
        }
        int deleted = 0;
        cin >> deleted;
        listnode *p = head;
        listnode *pre = head;
        while (p != NULL)
        {
            if (p->val == deleted)
            {
                if (p == head)
                    head = p->next;
                else
                {
                    pre->next = p->next;
                }
                break;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        p = head;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    return 0;
}