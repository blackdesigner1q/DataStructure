/*定义线索二叉树*/
typedef struct TBTNode
{
	char data;
	int ltag;
	int rtag;
	TBTNode* lchild;
	TBTNode* rchild;
}TBTNode;
/*中序递归遍历线索化*/
void InThread(TBTNode *p,TBTNode *&pre)
{
	if (p != nullptr)
	{
		InThread(p -> lchild,pre);//递归，左子树线索化
		if (p -> lchild == nullptr)//建立当前节点的前驱线索
		{			
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != nullptr && pre -> rchild == nullptr)//建立前驱节点的后继线索
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;//pre指向当前的p 也就是说p变成了pre p->rchild变成了p
		p = p->rchild;//p指向一个新的节点，此时pre和p分别指向的节点成了一个前驱后继对 为下一次线索的链接做准备
		InThread(p ,pre);//递归，右子树线索化
	}
}