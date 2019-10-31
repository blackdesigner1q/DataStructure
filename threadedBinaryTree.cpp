/*定义线索二叉树*/
typedef struct TBTNode
{
	char data;
	int ltag;
	int rtag;
	TBTNode* lchild;
	TBTNode* rchild;
}TBTNode;