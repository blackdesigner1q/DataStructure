/*��������������*/
typedef struct TBTNode
{
	char data;
	int ltag;
	int rtag;
	TBTNode* lchild;
	TBTNode* rchild;
}TBTNode;
/*����ݹ����������*/
void InThread(TBTNode *p,TBTNode *&pre)
{
	if (p != nullptr)
	{
		InThread(p -> lchild,pre);//�ݹ飬������������
		if (p -> lchild == nullptr)//������ǰ�ڵ��ǰ������
		{			
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != nullptr && pre -> rchild == nullptr)//����ǰ���ڵ�ĺ������
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;//preָ��ǰ��p Ҳ����˵p�����pre p->rchild�����p
		p = p->rchild;//pָ��һ���µĽڵ㣬��ʱpre��p�ֱ�ָ��Ľڵ����һ��ǰ����̶� Ϊ��һ��������������׼��
		InThread(p ,pre);//�ݹ飬������������
	}
}