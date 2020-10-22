#include <iostream>
#include <vector>
using namespace std;
struct listnode
{
    int val;
    listnode *next;
    listnode(int x) : val(x), next(NULL) {}
};
class List
{
public:
    List(int num)
    {
        int n = 0;
        head= new listnode(0);
        listnode *p=head;
        for (int i = 0; i < num; i++)
        {
            cin >> n;
            listnode * q=new listnode(n);
            p->next=q;
            p=p->next;
        }
        head=head->next;
    }
    void bottomk(int k)
    {
        if(k!=0)
        {
        listnode *slow = head;
        listnode *fast = head;
        for (int i = 0; i < k - 1; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        cout << slow->val << endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }

private:
    listnode *head;
};
int main()
{
    int num = 0;
    while (cin >> num)
    {
        List list(num);
        int k = 0;
        cin >> k;
        list.bottomk(k);
    }
    return 0;
}