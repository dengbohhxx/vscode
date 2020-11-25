/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}

		RandomListNode* pNode = pHead;
		// 对于每个结点 复制一个一模一样的结点
		while (pNode)
		{
			RandomListNode* temp = new RandomListNode(pNode->label);
			//temp->label = pNode->label;
			temp->next = pNode->next;
			//temp->random = NULL;

			pNode->next = temp;
			pNode = temp->next;			// 源链表的下一个结点
		}

		pNode = pHead;
		// 指定新分配的每个结点的random(实际上就是源结点的random的next)
		while (pNode)
		{
			RandomListNode* temp = pNode->next;
			// 如果源结点的random不指向NULL 为新链表的结点分配random属性
			if (pNode->random)//????
			{
				temp->random = pNode->random->next;
			}
			pNode = temp->next;
		}

		// 分解两个链表
		pNode = pHead;
		RandomListNode* temp;
		RandomListNode *newHead = pHead->next;
		while (pNode->next)
		{
			temp = pNode->next;
			pNode->next = temp->next;
			pNode = temp;
		}

		return newHead;


	}
};