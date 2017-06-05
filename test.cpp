#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<string>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 
//1、递归方式实现二叉树的先序、中序和后序的遍历打印

//递归先序遍历
//void preordertraverse(TreeNode* root, vector<int>& p1)//p1为引用，输出的时候会自动改变
//{
//	if (!root)
//		return;
//	p1.push_back( root->val);
//	preordertraverse(root->left, p1);
//	preordertraverse(root->right, p1);
//}
//
////递归中序遍历
//void inordertraverse(TreeNode* root, vector<int>& p1)
//{
//	if (!root)
//		return;
//	inordertraverse(root->left, p1);
//	p1.push_back(root->val);
//	inordertraverse(root->right, p1);
//}
//
////递归后序遍历
//void posordertraverse(TreeNode* root, vector<int>& p1)
//{
//	if (!root)
//		return;
//	posordertraverse(root->left, p1);
//	posordertraverse(root->right, p1);
//	p1.push_back(root->val);
//}
//	vector<vector<int>> convert(TreeNode* root) {
//		vector<vector<int>>  res(3, vector<int>());           //存放弹出来的结点,三种情况下
//		preordertraverse( root,res[0]);//递归先序遍历
//		inordertraverse(root, res[1]);//递归中序遍历
//		posordertraverse(root, res[2]);//递归先序遍历
//		return res;
//	}
	//2、非递归二叉树的先序、中序和后序的遍历打印
	//非递归先序遍历
vector<int> preorder(TreeNode* root)//p1为引用，输出的时候会自动改变，存放打印的值
	{
	vector<int> pre;
	  if (!root)
		return pre;

		stack<TreeNode*> stack1;//栈中存放子树，所以要是树的结构
		TreeNode* head = root;
	    stack1.push(head);//将根节点元素压入栈,则整棵树都是可以链接的了
		TreeNode* cur = NULL;
		
		while (!stack1.empty())
			{
				cur = stack1.top();//栈顶元素记为cur,下次循环时，栈顶元素为之前插入的左子树或者右子树
				stack1.pop();
				pre.push_back(cur->val);//将打印
				if (cur->right !=NULL)//将左子树压入
				{
					stack1.push(cur->right);
				}
				if (cur->left != NULL)//将右子树压入
				{
					stack1.push(cur->left);
				}
			}
		return pre;
		}
//	//非递归中序遍历
//	vector<int> inorder(TreeNode* root)
//	{
//		vector<int> ino;
//		if (!root)
//			return ino;
//		stack<TreeNode*> stack1;//栈中存放子树，所以要是树的结构
//		
//		TreeNode* head = root;
//		//将根节点元素压入栈,则整棵树都是可以链接的了
//		TreeNode* cur = head;
//		
//		while (!stack1.empty()||cur)
//		{
//			while (cur != NULL)
//			{
//				stack1.push(cur);
//				cur = cur->left;
//			}
//			if (!stack1.empty()) //当cur为空
//			{
//				TreeNode* node = stack1.top();
//				stack1.pop();
//				ino.push_back(node->val);
//				cur = node->right;
//				while (cur != NULL)
//				{
//					stack1.push(cur);
//					cur = cur->left;
//				}
//			}
//		}
//		return ino;
//	}
//	//非递归后序遍历
//	vector<int> posorder(TreeNode* root)
//	{
//		vector<int> post;
//		if (!root)
//			return post;
//		TreeNode* cur;
//		TreeNode* a;
//		stack<TreeNode*> stack1,stack2;
//		
//		stack1.push(root);
//		while (!stack1.empty())
//		{
//			cur = stack1.top();//将当前栈顶结点弹出
//			stack1.pop();
//			stack2.push(cur);
//			if(cur->left!=NULL)
//			{ 
//				stack1.push(cur->left);
//			}
//			if (cur->right != NULL)
//			{
//				stack1.push(cur->right);
//			}	
//		}
//		while (!stack2.empty())
//		{
//			a = stack2.top();
//			stack2.pop();
//			post.push_back(a->val);
//		}
//		return post;
//	}
//
//vector<vector<int>> convert(TreeNode* root) {
//		vector<vector<int>>  res;           //存放弹出来的结点,三种情况下
//		res.push_back(preorder(root));//递归先序遍历
//		res.push_back(inorder(root));//递归中序遍历
//		res.push_back(posorder(root));//递归先序遍历
//		return res;
//	}
////3、按照层遍历使用队列先进先出
//vector<vector<int> > printTree(TreeNode* root) {
//	vector<vector<int> > res;
//	int last=root->val;      //正在打印的当前行的最右结点
//	int nlast;     //下一行的最右结点，最新加入的结点
//	TreeNode* cur;
//	queue<TreeNode*>  Q;
//	vector<int> T;
//	Q.push(root);
//	while(!Q.empty())
//	{
//		cur=Q.front();
//		Q.pop();
//		T.push_back(cur->val);
//		if (cur->left != NULL)
//		{
//			Q.push(cur->left);
//			nlast = cur->left->val;
//		}
//		if (cur->right != NULL)
//		{
//			Q.push(cur->right);
//			nlast = cur->right->val;
//		}
//		if (cur->val == last)
//		{
//			last = nlast;
//			res.push_back(T);
//			T.clear();
//		}
//	}
//	return res;
//}
////4、先序序列化非递归方法
//string toString(TreeNode* root) {
//	string str = "";               //序列化的结果
//	stack<TreeNode*> stack1;
//	if (!root)
//		return "#!";//若二叉树为空，则打印#！
//	stack1.push(root);
//	TreeNode* cur;
//	
//	while (!stack1.empty())
//	{
//		cur = stack1.top();
//		stack1.pop();
//		
//		if (cur != NULL) 
//		{
//	      //to_string(cur->val)返回字符串的形式
//			str += to_string(cur->val) + "!";    //将栈顶元素弹出并打印
//			if (cur->right != NULL)
//			{
//				stack1.push(cur->right);
//			}
//			else
//				stack1.push(NULL);
//
//			if (cur->left != NULL)
//			{
//				stack1.push(cur->left);
//			}
//			else
//				stack1.push(NULL);;//若有空则打印#！
//		}
//		else str += "#!";
//      }
//     return str;
//}
////5、递归先序序列化
//string toString(TreeNode* root) {
//
//	if (!root)
//		return "#!";//若二叉树为空，则打印#！
//	string str = to_string(root->val) + "!";
//	str +=toString(root->left);
//	str += toString(root->right);
//	return str;
//}
////按层遍历（宽度优先遍历）序列化
string toString(TreeNode* root) {
	string st = "";
	queue<TreeNode*> que;
	que.push(root);
	TreeNode* cur;
	while(que!=NULL)
	{
		cur = que.front();
		que.pop();
		if (cur != NULL)
		{
			st += to_string(cur->val) + "!";
			if (cur->left != NULL)
				que.push(root->left);
			else
				que.push(NULL);
			if (cur->right != NULL)
				que.push(root->right);
			else
				que.push(NULL);
		}
		else
			st += "#!";
	}
	return st;
}
////6、给定二叉树的根结点root，请返回一个bool值，代表这棵树是否为平衡二叉树
////递归函数就是假设当前的函数可以实现其功能，在函数里面调用本身
//int getheight(TreeNode* root)  //找到二叉树的深度
//{
//	if (root == NULL)
//		return 0;
//	int LH = getheight(root->left);   //找到当前的结点的左子树的深度
//	int RH = getheight(root->right);  //找到当前的结点的右子树的深度
//	if (LH > RH)    //求绝对值   左右子树中深度较大的+1就是当前子树的深度
//	return LH+1;
//	else return RH + 1;
//}
//bool isbalancedtree(TreeNode* root) {//判断是否是平衡二叉树
//	if (root == NULL)
//		return true;
//	if (!isbalancedtree(root->left))      //假设本身可以实现功能，如果左子树不是平衡二叉树则直接返回空
//		return false;
//	int LH = getheight(root->left);
//	if (!isbalancedtree(root->right))//假设本身可以实现功能，如果右子树不是平衡二叉树则直接返回空
//		return false;
//	int RH = getheight(root->right);   //若本身是平衡二叉树返回其深度
//	if (LH == RH || LH - RH == 1 || RH - LH == 1)//若二者的深度相差1，则是，否则不是
//		return true;
//	else return false;
//}
//bool check(TreeNode* root) {
//	return isbalancedtree(root);
//}
////7、给定二叉树的根结点root，请返回一个bool值代表它是否为完全二叉树
//
//bool chk(TreeNode* root) {
//	if (root == NULL)
//		return true;
//	TreeNode* p;
//	queue<TreeNode*> que;
//	que.push(root);
//	bool nochild = false;      //标记若出现没有孩子的情况，则后面出现的节点都是为叶节点，不能作为父节点
//	while (!que.empty())
//	{
//		p = que.front();
//		que.pop();
//		if (nochild)
//		{
//			if (p->left || p->right)   //如果前一个结点缺少孩子，下一个结点是作为父节点则不满足
//				return false;
//		}
//		if (p->left && p->right)
//		{
//			que.push(p->left);
//			que.push(p->right);
//		}
//		else if (p->left)
//		{
//			que.push(p->left);
//			nochild = true;
//		}
//		else  if (p->right)
//		{
//			que.push(p->right);
//			nochild = true;
//		}
//		else
//			nochild = true;
//	}
//	return true;   //若所有的节点都不满足不是满二叉树的条件，则是完全二叉树
//}
////8、折纸联系
//void inorder(int n, string b, vector<string> &s)
//{
//	if (n > 0)
//		{
//	inorder(n - 1, "down", s);
//		s.push_back(b);
//    inorder(n - 1, "up", s);
//}
//}
//vector<string> foldPaper(int n) {
//	string b = "down";
//	vector<string> s;
//	inorder(n, b, s);
//	return s;
//}
////9、寻找错误结点
//vector<int> inorder(TreeNode* root)
//{
//	vector<int> ino;
//	if (!root)
//		return ino;
//	stack<TreeNode*> stack1;//栈中存放子树，所以要是树的结构
//
//	TreeNode* head = root;
//	//将根节点元素压入栈,则整棵树都是可以链接的了
//	TreeNode* cur = head;
//
//	while (!stack1.empty() || cur)
//	{
//		while (cur != NULL)
//		{
//			stack1.push(cur);
//			cur = cur->left;
//		}
//		if (!stack1.empty()) //当cur为空
//		{
//			TreeNode* node = stack1.top();
//			stack1.pop();
//			ino.push_back(node->val);
//			cur = node->right;
//			while (cur != NULL)
//			{
//				stack1.push(cur);
//				cur = cur->left;
//			}
//		}
//	}
//	return ino;
//}
//
//vector<int> findError(TreeNode* root) {
//	vector<int> error;
//	int a,b,i;
//	vector<int> p1;
//	p1=inorder(root);   //二叉树中序遍历的结果存在p1中
//
//	for (i = 0; i < p1.size()-1; i++)//从左往右遍历
//	{
//		if (p1[i] > p1[i + 1])//若第一次出现降序
//		{
//			a = p1[i];
//			break;
//		}
//	}
//	for (i = p1.size() - 1; i >=0; i--)//从右往左遍历
//	{
//		if (p1[i] < p1[i - 1])//若第一次出现升序，即从左往右是降序，最后一次降序
//		{
//			b = p1[i];
//			break;
//		}
//	}
//	error.push_back(min(a,b));    //将小的先放入数组中
//	error.push_back(max(a,b));
//	return error;
//}
////10、树上最远距离
//int result = 0;
//int getheight(TreeNode* root)    //找到树的最深长度
//{
//	
//	if (root == NULL)
//		return 0;
//	int l1 = getheight(root->left) + 1;   //左子树上离h最远的点到h节点的距离
//	int r1 = getheight(root->right) + 1;//右子树上离h最远的点到h节点的距离
//	result = max(l1+r1-1,result);    //从左子树到右子树的最远距离，跨h结点的最大距离
//	return max(l1,r1);  //返回h树上距离h最远的距离
//}
//int findLongest(TreeNode* root) {
//	
//	getheight(root);
//	return result;//函数的返回值不是想要的结果，需要的是全局变量
//}

//11、最大二叉搜索子树
//int getmaxval(TreeNode* root)  //获取当前二叉树的最大值
//{
//	if (root == NULL)
//		return 0;
//	if (root != NULL&&root->right == NULL)
//		return root->val;
//	return getmaxval(root->right);
//}
//int getminval(TreeNode* root)//获取当前二叉树的最小值
//{
//	if (root == NULL)
//		return 0;
//	if (root != NULL&&root->left == NULL)
//		return root->val;
//	return getmaxval(root->left);
//}
//bool ismaxtree(TreeNode* root)//若判断是否是最大搜索子树
//{
//	if (root == NULL)
//		return true;
//	int minval, maxval;
//	if (ismaxtree(root->left) && ismaxtree(root->right))   //若左右子树都是最大搜索子树，判断当前节点与左右子树的最大最小节点之间的关系
//	{
//		if (root->left)
//		{
//			maxval = getmaxval(root->left);      //若有左子树，找到二叉子树左子树的最大值与头结点比较
//			if (root->val <= maxval)
//				return false;
//		}
//		if (root->right)
//		{
//			minval = getminval(root->right);//若有右子树，找到二叉子树右子树的最小值与头结点比较
//			if (root->val >= minval)
//				return false;
//		}
//		return true;
//	}
//	else
//		return false;	
//}
//
//int getnum(TreeNode* root)  //获取当前最大搜索二叉树的节点数
//{
//	if (root != NULL&&root->left == NULL&&root->right == NULL)//判断极限情况
//		return 1;
//	if (root == NULL)
//		return 0;
//	return getnum(root->left) + getnum(root->right) + 1;
//
//}
//TreeNode* s;
//int n = -1;
//TreeNode* getMax(TreeNode* root) {
//	int m;
//	if (root == NULL)
//		return root;
//	if (ismaxtree(root))   //如果是最大搜索二叉树，返回其头结点
//	{
//		m = getnum(root);
//		if (n < m)   //题目给定的二叉树就是最大搜索二叉树的情况
//		{
//			n = m;
//			s = root;
//		}
//		else if(n==m)   //题目给的二叉树不是最大二叉树，调用本函数时
//		{
//			if(root->val>s->val)//s为最大搜索二叉树的头结点，root为当前头结点
//			s = root;
//		}
//
//	}
//	else
//	{
//		getMax(root->left);
//		getMax(root->right);
//	}
//	return s;
//}

	void CreateBiTree(TreeNode * &root)  //构造二叉树
	{
		    char a;
			a = getchar();
			if (a ==' ' ) root = NULL;
			else
			{
				root= new TreeNode(a);//边生成边插入
				CreateBiTree(root->left);
				CreateBiTree(root->right);
			}	
	}


	void main() 
	{
		//1、递归输出遍历结果
		TreeNode* root;
		int n=5;   //二叉树的节点数目
		cout << "创建二叉树：" << endl;
		CreateBiTree(root);//生成一颗二叉树
		vector<int> res= preorder(root);
		cout << "中序遍历结果为：" << endl;
		for(int i=0;i<res.size();i++)
		{
			cout << res[i] << endl;
		}
		_getch();
	}