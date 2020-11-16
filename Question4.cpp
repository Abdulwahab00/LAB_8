#include<iostream>
using namespace std;
#define COUNT 10
struct node
{
	int data;
	node* rightNode;
	node* leftNode;
};
class Tree
{
public:
	node* root;
	int c;
	Tree()
	{
		c = 0;
		root = NULL;
	}
	void insert(int val);
	int Height(node* temp);
	void print2D(node* root);
	void print2DUtil(node* root, int space);
	void level(int );
	void levelnode(node*, int i);
};

void Tree::level(int v)
{
	int height;
	height = Height(root);
	
	for (int i = 0; i <= height; i++)
	{
		if (i == (v-1))
		{
			levelnode(root, i);
		}
		
	}
	cout << "Number of Nodes at Height " << v << " is: " << c;
}
void Tree::levelnode(node* temp, int level)
{
	if (temp == NULL)
	{
		return;
	}
	else if (level == 0)
	{
		c++;
	}
	else
	{
		levelnode(temp->leftNode, level - 1 );
		levelnode(temp->rightNode, level - 1);
	}
}
void Tree::insert(int val)
{
	node* NewNode = new node;
	NewNode->data = val;
	NewNode->leftNode = NULL;
	NewNode->rightNode = NULL;
	if (root == NULL)
	{
		root = NewNode;
	}
	else {
		node* temp;
		temp = root;

		while (temp != NULL)
		{
			if (temp->data == val)
			{
				cout << "This Value already Exits" << endl;
				break;
			}
			else if (temp->data > val && temp->leftNode == NULL)
			{
				temp->leftNode = NewNode;
				break;
			}
			else if (temp->data > val)
			{
				temp = temp->leftNode;

			}
			else if (temp->data < val && temp->rightNode == NULL)
			{
				temp->rightNode = NewNode;
				break;
			}
			else
			{
				temp = temp->rightNode;
			}
		}
	}
}

int Tree::Height(node* temp)
{
	if (temp == NULL)
	{
		return 0;
	}
	else
	{
		int leftheight = Height(temp->leftNode);
		int rightheight = Height(temp->rightNode);
		if (leftheight > rightheight)
		{
			return (leftheight + 1);
		}
		else
			return (rightheight + 1);
	}
}
void Tree::print2DUtil(node* root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->rightNode, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";


	print2DUtil(root->leftNode, space);
}


void Tree::print2D(node* root)
{

	print2DUtil(root, 0);
}
int main()
{
	int data;
	Tree obj;
	cout << "***Enter Data in  BST***" << endl;
	do
	{
		cout << "Enter the Element you want to insert / Press-222 to stop insertion: ";
		cin >> data;
		if (data != -222)
		{
			obj.insert(data);
		}

	} while (data != -222);
	obj.print2D(obj.root);
	
	int v;
	cout << "Enter the Height on which you want to check number of nodes" << endl;
	cin >> v;
	obj.level(v);
}