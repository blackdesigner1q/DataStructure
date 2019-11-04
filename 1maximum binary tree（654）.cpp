/*
Question:Give an integer array with no duplicates.A maximum Tree building on this array is defined as 
follow :
1.The root is the maximum number in the array.
2.The left subtree is the maximum tree constructed from left part subarray divided by the maximum 
number.
3.The right subtree is the maximum tree constructed from right part subarray divided by the maximum
number.
Constructed the maximum tree by the given array and output the root node of this tree.
Example:
*/
#include <vector> 
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return getMaxBTree(nums, 0, nums.size() - 1);
	}
	TreeNode* getMaxBTree(vector<int>& a, int left, int right) {
		if (left > right)return NULL;
		int max = -1, maxIndex;
		for (int i = left; i <= right; i++) {
			if (a[i] > max) {
				max = a[i];
				maxIndex = i;
			}
		}
		TreeNode* root = new TreeNode(max);
		root->left = getMaxBTree(a, left, maxIndex - 1);
		root->right = getMaxBTree(a, maxIndex + 1, right);
		return root;
	}
};