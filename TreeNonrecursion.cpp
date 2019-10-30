#define maxSize 100
void Visit(BTNode *bt)
{

}
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
		BTNode* Stack[1];//设置栈的大小
		BTNode* p;
		int top = -1;
		Stack[++top] = bt;//将根节点压入栈中
		while (top != -1)
		{
			p = Stack[top--];//将根节点弹出
			//Visit(p);//访问根节点
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
		BTNode* Stack[1];
		int pop = -1;
		p = bt;

		while (pop = -1 || p != nullptr)
		{
			while (p != nullptr)//将左子树压入栈中
			{
				Stack[++pop] = p;
				p = p->lchild;
			}
			if (pop != -1)//左子树压入完毕后 开始判断其是否存在右子树，存在则压入栈中，不存在就将根节点出栈
			{
				p = Stack[pop--];
				//Visit(p);
				p = p->rchild;
			}
		}
	}
}
/*后序遍历的非递归方法
先序遍历与逆后序遍历比较类似，唯一不同的地方是先序遍历关于根的左右字树互换即可得到逆后序遍历。
*/
void postorderNonrecursion(BTNode *bt)
{
	if (bt != nullptr)
	{
		/*定义两个栈*/
		BTNode* Stack1[maxSize];
		int top1 = -1;
		BTNode* Stack2[maxSize];
		int top2 = -1;
		BTNode* p = nullptr; 
		Stack1[++top1] = bt;
		while (top1 != -1)
		{
			p = Stack1[top1--];
			Stack2[++top2] = p;//输出改为Stack2
			/*以下代码与先序遍历的左右孩子进栈次序正好相反*/
			if (p -> lchild != nullptr)
			{
				Stack1[++top1] = p->lchild;//左孩子先入后出 完成左右孩子逆序操作
			}
			if (p -> rchild != nullptr)
			{
				Stack2[++top2] = p->rchild;
			}
			while (top2 != -1)
			{
				p = Stack2[top2--];
				Visit(p);
			}
		}
	}


}