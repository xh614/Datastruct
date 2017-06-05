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
//1���ݹ鷽ʽʵ�ֶ���������������ͺ���ı�����ӡ

//�ݹ��������
//void preordertraverse(TreeNode* root, vector<int>& p1)//p1Ϊ���ã������ʱ����Զ��ı�
//{
//	if (!root)
//		return;
//	p1.push_back( root->val);
//	preordertraverse(root->left, p1);
//	preordertraverse(root->right, p1);
//}
//
////�ݹ��������
//void inordertraverse(TreeNode* root, vector<int>& p1)
//{
//	if (!root)
//		return;
//	inordertraverse(root->left, p1);
//	p1.push_back(root->val);
//	inordertraverse(root->right, p1);
//}
//
////�ݹ�������
//void posordertraverse(TreeNode* root, vector<int>& p1)
//{
//	if (!root)
//		return;
//	posordertraverse(root->left, p1);
//	posordertraverse(root->right, p1);
//	p1.push_back(root->val);
//}
//	vector<vector<int>> convert(TreeNode* root) {
//		vector<vector<int>>  res(3, vector<int>());           //��ŵ������Ľ��,���������
//		preordertraverse( root,res[0]);//�ݹ��������
//		inordertraverse(root, res[1]);//�ݹ��������
//		posordertraverse(root, res[2]);//�ݹ��������
//		return res;
//	}
	//2���ǵݹ����������������ͺ���ı�����ӡ
	//�ǵݹ��������
vector<int> preorder(TreeNode* root)//p1Ϊ���ã������ʱ����Զ��ı䣬��Ŵ�ӡ��ֵ
	{
	vector<int> pre;
	  if (!root)
		return pre;

		stack<TreeNode*> stack1;//ջ�д������������Ҫ�����Ľṹ
		TreeNode* head = root;
	    stack1.push(head);//�����ڵ�Ԫ��ѹ��ջ,�����������ǿ������ӵ���
		TreeNode* cur = NULL;
		
		while (!stack1.empty())
			{
				cur = stack1.top();//ջ��Ԫ�ؼ�Ϊcur,�´�ѭ��ʱ��ջ��Ԫ��Ϊ֮ǰ���������������������
				stack1.pop();
				pre.push_back(cur->val);//����ӡ
				if (cur->right !=NULL)//��������ѹ��
				{
					stack1.push(cur->right);
				}
				if (cur->left != NULL)//��������ѹ��
				{
					stack1.push(cur->left);
				}
			}
		return pre;
		}
//	//�ǵݹ��������
//	vector<int> inorder(TreeNode* root)
//	{
//		vector<int> ino;
//		if (!root)
//			return ino;
//		stack<TreeNode*> stack1;//ջ�д������������Ҫ�����Ľṹ
//		
//		TreeNode* head = root;
//		//�����ڵ�Ԫ��ѹ��ջ,�����������ǿ������ӵ���
//		TreeNode* cur = head;
//		
//		while (!stack1.empty()||cur)
//		{
//			while (cur != NULL)
//			{
//				stack1.push(cur);
//				cur = cur->left;
//			}
//			if (!stack1.empty()) //��curΪ��
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
//	//�ǵݹ�������
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
//			cur = stack1.top();//����ǰջ����㵯��
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
//		vector<vector<int>>  res;           //��ŵ������Ľ��,���������
//		res.push_back(preorder(root));//�ݹ��������
//		res.push_back(inorder(root));//�ݹ��������
//		res.push_back(posorder(root));//�ݹ��������
//		return res;
//	}
////3�����ղ����ʹ�ö����Ƚ��ȳ�
//vector<vector<int> > printTree(TreeNode* root) {
//	vector<vector<int> > res;
//	int last=root->val;      //���ڴ�ӡ�ĵ�ǰ�е����ҽ��
//	int nlast;     //��һ�е����ҽ�㣬���¼���Ľ��
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
////4���������л��ǵݹ鷽��
//string toString(TreeNode* root) {
//	string str = "";               //���л��Ľ��
//	stack<TreeNode*> stack1;
//	if (!root)
//		return "#!";//��������Ϊ�գ����ӡ#��
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
//	      //to_string(cur->val)�����ַ�������ʽ
//			str += to_string(cur->val) + "!";    //��ջ��Ԫ�ص�������ӡ
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
//				stack1.push(NULL);;//���п����ӡ#��
//		}
//		else str += "#!";
//      }
//     return str;
//}
////5���ݹ��������л�
//string toString(TreeNode* root) {
//
//	if (!root)
//		return "#!";//��������Ϊ�գ����ӡ#��
//	string str = to_string(root->val) + "!";
//	str +=toString(root->left);
//	str += toString(root->right);
//	return str;
//}
////���������������ȱ��������л�
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
////6�������������ĸ����root���뷵��һ��boolֵ������������Ƿ�Ϊƽ�������
////�ݹ麯�����Ǽ��赱ǰ�ĺ�������ʵ���书�ܣ��ں���������ñ���
//int getheight(TreeNode* root)  //�ҵ������������
//{
//	if (root == NULL)
//		return 0;
//	int LH = getheight(root->left);   //�ҵ���ǰ�Ľ��������������
//	int RH = getheight(root->right);  //�ҵ���ǰ�Ľ��������������
//	if (LH > RH)    //�����ֵ   ������������Ƚϴ��+1���ǵ�ǰ���������
//	return LH+1;
//	else return RH + 1;
//}
//bool isbalancedtree(TreeNode* root) {//�ж��Ƿ���ƽ�������
//	if (root == NULL)
//		return true;
//	if (!isbalancedtree(root->left))      //���豾�����ʵ�ֹ��ܣ��������������ƽ���������ֱ�ӷ��ؿ�
//		return false;
//	int LH = getheight(root->left);
//	if (!isbalancedtree(root->right))//���豾�����ʵ�ֹ��ܣ��������������ƽ���������ֱ�ӷ��ؿ�
//		return false;
//	int RH = getheight(root->right);   //��������ƽ����������������
//	if (LH == RH || LH - RH == 1 || RH - LH == 1)//�����ߵ�������1�����ǣ�������
//		return true;
//	else return false;
//}
//bool check(TreeNode* root) {
//	return isbalancedtree(root);
//}
////7�������������ĸ����root���뷵��һ��boolֵ�������Ƿ�Ϊ��ȫ������
//
//bool chk(TreeNode* root) {
//	if (root == NULL)
//		return true;
//	TreeNode* p;
//	queue<TreeNode*> que;
//	que.push(root);
//	bool nochild = false;      //���������û�к��ӵ�������������ֵĽڵ㶼��ΪҶ�ڵ㣬������Ϊ���ڵ�
//	while (!que.empty())
//	{
//		p = que.front();
//		que.pop();
//		if (nochild)
//		{
//			if (p->left || p->right)   //���ǰһ�����ȱ�ٺ��ӣ���һ���������Ϊ���ڵ�������
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
//	return true;   //�����еĽڵ㶼�����㲻������������������������ȫ������
//}
////8����ֽ��ϵ
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
////9��Ѱ�Ҵ�����
//vector<int> inorder(TreeNode* root)
//{
//	vector<int> ino;
//	if (!root)
//		return ino;
//	stack<TreeNode*> stack1;//ջ�д������������Ҫ�����Ľṹ
//
//	TreeNode* head = root;
//	//�����ڵ�Ԫ��ѹ��ջ,�����������ǿ������ӵ���
//	TreeNode* cur = head;
//
//	while (!stack1.empty() || cur)
//	{
//		while (cur != NULL)
//		{
//			stack1.push(cur);
//			cur = cur->left;
//		}
//		if (!stack1.empty()) //��curΪ��
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
//	p1=inorder(root);   //��������������Ľ������p1��
//
//	for (i = 0; i < p1.size()-1; i++)//�������ұ���
//	{
//		if (p1[i] > p1[i + 1])//����һ�γ��ֽ���
//		{
//			a = p1[i];
//			break;
//		}
//	}
//	for (i = p1.size() - 1; i >=0; i--)//�����������
//	{
//		if (p1[i] < p1[i - 1])//����һ�γ������򣬼����������ǽ������һ�ν���
//		{
//			b = p1[i];
//			break;
//		}
//	}
//	error.push_back(min(a,b));    //��С���ȷ���������
//	error.push_back(max(a,b));
//	return error;
//}
////10��������Զ����
//int result = 0;
//int getheight(TreeNode* root)    //�ҵ����������
//{
//	
//	if (root == NULL)
//		return 0;
//	int l1 = getheight(root->left) + 1;   //����������h��Զ�ĵ㵽h�ڵ�ľ���
//	int r1 = getheight(root->right) + 1;//����������h��Զ�ĵ㵽h�ڵ�ľ���
//	result = max(l1+r1-1,result);    //��������������������Զ���룬��h����������
//	return max(l1,r1);  //����h���Ͼ���h��Զ�ľ���
//}
//int findLongest(TreeNode* root) {
//	
//	getheight(root);
//	return result;//�����ķ���ֵ������Ҫ�Ľ������Ҫ����ȫ�ֱ���
//}

//11����������������
//int getmaxval(TreeNode* root)  //��ȡ��ǰ�����������ֵ
//{
//	if (root == NULL)
//		return 0;
//	if (root != NULL&&root->right == NULL)
//		return root->val;
//	return getmaxval(root->right);
//}
//int getminval(TreeNode* root)//��ȡ��ǰ����������Сֵ
//{
//	if (root == NULL)
//		return 0;
//	if (root != NULL&&root->left == NULL)
//		return root->val;
//	return getmaxval(root->left);
//}
//bool ismaxtree(TreeNode* root)//���ж��Ƿ��������������
//{
//	if (root == NULL)
//		return true;
//	int minval, maxval;
//	if (ismaxtree(root->left) && ismaxtree(root->right))   //����������������������������жϵ�ǰ�ڵ������������������С�ڵ�֮��Ĺ�ϵ
//	{
//		if (root->left)
//		{
//			maxval = getmaxval(root->left);      //�������������ҵ��������������������ֵ��ͷ���Ƚ�
//			if (root->val <= maxval)
//				return false;
//		}
//		if (root->right)
//		{
//			minval = getminval(root->right);//�������������ҵ�������������������Сֵ��ͷ���Ƚ�
//			if (root->val >= minval)
//				return false;
//		}
//		return true;
//	}
//	else
//		return false;	
//}
//
//int getnum(TreeNode* root)  //��ȡ��ǰ��������������Ľڵ���
//{
//	if (root != NULL&&root->left == NULL&&root->right == NULL)//�жϼ������
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
//	if (ismaxtree(root))   //��������������������������ͷ���
//	{
//		m = getnum(root);
//		if (n < m)   //��Ŀ�����Ķ���������������������������
//		{
//			n = m;
//			s = root;
//		}
//		else if(n==m)   //��Ŀ���Ķ����������������������ñ�����ʱ
//		{
//			if(root->val>s->val)//sΪ���������������ͷ��㣬rootΪ��ǰͷ���
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

	void CreateBiTree(TreeNode * &root)  //���������
	{
		    char a;
			a = getchar();
			if (a ==' ' ) root = NULL;
			else
			{
				root= new TreeNode(a);//�����ɱ߲���
				CreateBiTree(root->left);
				CreateBiTree(root->right);
			}	
	}


	void main() 
	{
		//1���ݹ�����������
		TreeNode* root;
		int n=5;   //�������Ľڵ���Ŀ
		cout << "������������" << endl;
		CreateBiTree(root);//����һ�Ŷ�����
		vector<int> res= preorder(root);
		cout << "����������Ϊ��" << endl;
		for(int i=0;i<res.size();i++)
		{
			cout << res[i] << endl;
		}
		_getch();
	}