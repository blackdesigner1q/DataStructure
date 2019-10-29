/*定义树*/
typedef struct BTNode {
	int data;
	BTNode* lchild;
	BTNode* rchild;
}BTNode;
/*树的先序遍历非递归方式
构造一个辅助栈，根节点入栈，然后就将根节点出栈，如有左右子树就将右孩子先入栈，然后将左孩子入栈，根据栈的后进先出的原则
先输出左孩子再输出右孩子
*/
void preorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* Stack[maxSize];//设置栈的大小
		BTNode* p;
		int top = -1;
		Stack[++top] = bt;//将根节点压入栈中
		while (top != -1)
		{
			p = Stack[top--];//将根节点弹出
			Visit(p);//访问根节点
			if (p->rchild != nullptr)//先将右孩子压入栈中
			{
				Stack[++top] = p->rchild;
			}
			if (p->lchild != nullptr)//再将左孩子压入栈中 遵循后入先出的原则
			{
				Stack[++top] = p->lchild;
			}
		}
	}
}
/*
中序遍历的非递归方法
首先根节点入栈，如果根节点的左孩子存在则左孩子入栈，如果根结点的左孩子不存在则让根节点出栈，若根结点的右孩子存在则让根结点的右孩子入栈。
*/
void inorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* p;
		BTNode* Stack[maxsize];
		int pop = -1;
		p = bt;

		while (pop = -1 || p != nullptr)
		{
			while (p != nullptr)//将左子树压入栈中
			{
				Stack[++p] = p;
				p = p->lchild;
			}
			if (pop != -1)//左子树压入完毕后 开始判断其是否存在右子树，存在则压入栈中，不存在就将根节点出栈
			{
				p = Stack[pop--];
				Visit(p);
				p = p->rchild;
			}
		}
	}
}
