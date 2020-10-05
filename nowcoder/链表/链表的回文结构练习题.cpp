/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
	bool isPalindrome(ListNode* head) {
		//方法一 栈 
        /*
         stack<int> s;
        ListNode * p1=pHead;
        ListNode * p2=pHead;
        while(p1!=NULL)
        {
            s.push(p1->val);
            p1=p1->next;
        }
        while(p2!=NULL)
        {
            if(s.top()!=p2->val)
            {
                return false;
            }
            s.pop();
            p2=p2->next;
        }
        return true;
        */
        //方法二 快慢指针 栈
        /*
         stack<int> s;
        int n=0;//计数用，从1开始
        ListNode * p=pHead;
        while(p!=NULL)
        {
            n++;
            p=p->next;
        }
        //快慢指针
        ListNode* slow=pHead;
        ListNode* fast=pHead;
        while(fast!=NULL&&fast->next!=NULL)
        {
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        //当链表长度为奇数时
        if(n%2!=0)
        {
            slow=slow->next;
        }
        //判断
        while(slow!=NULL)
        {
            if(s.top()!=slow->val)
            {
                return false;
            }
            else
            {
                s.pop();
                slow=slow->next;
            }
        }
        return true;
        */
        //方法三 快慢指针 链表逆序
        // write code here
		if (head == NULL)
			return true;
		//快慢两个指针
		ListNode* slow = head;
		ListNode* fast = head;
		//考虑奇偶两种情况
		while (fast != NULL&&fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* pre = slow;//pre标记为slow
		slow = slow->next;//slow指向下一个，为逆序做准备
		pre->next = NULL;
		//逆序，
		while (slow != NULL)
		{
			ListNode* temp = slow->next;
			slow->next = pre;
			pre = slow;
			slow = temp;
		}
		ListNode* left = head;//左右开始向中间遍历 ，看是否为回文结构
		ListNode* right = pre;
		while (right!=NULL)//当节点数为偶数时，right==NULL就是循环停止条件，这时left并不为NULL
		{
			if (left->val == right->val)//相等，下一对节点，不相等，返回  false
			{
				left = left->next;
				right = right->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};