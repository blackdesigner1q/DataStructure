/*������*/
typedef struct BTNode {
	int data;
	BTNode* lchild;
	BTNode* rchild;
}BTNode;
/*������������ǵݹ鷽ʽ
����һ������ջ�����ڵ���ջ��Ȼ��ͽ����ڵ��ջ���������������ͽ��Һ�������ջ��Ȼ��������ջ������ջ�ĺ���ȳ���ԭ��
���������������Һ���
*/
void preorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* Stack[maxSize];//����ջ�Ĵ�С
		BTNode* p;
		int top = -1;
		Stack[++top] = bt;//�����ڵ�ѹ��ջ��
		while (top != -1)
		{
			p = Stack[top--];//�����ڵ㵯��
			Visit(p);//���ʸ��ڵ�
			if (p->rchild != nullptr)//�Ƚ��Һ���ѹ��ջ��
			{
				Stack[++top] = p->rchild;
			}
			if (p->lchild != nullptr)//�ٽ�����ѹ��ջ�� ��ѭ�����ȳ���ԭ��
			{
				Stack[++top] = p->lchild;
			}
		}
	}
}
/*
��������ķǵݹ鷽��
���ȸ��ڵ���ջ��������ڵ�����Ӵ�����������ջ��������������Ӳ��������ø��ڵ��ջ�����������Һ��Ӵ������ø������Һ�����ջ��
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
			while (p != nullptr)//��������ѹ��ջ��
			{
				Stack[++p] = p;
				p = p->lchild;
			}
			if (pop != -1)//������ѹ����Ϻ� ��ʼ�ж����Ƿ������������������ѹ��ջ�У������ھͽ����ڵ��ջ
			{
				p = Stack[pop--];
				Visit(p);
				p = p->rchild;
			}
		}
	}
}
