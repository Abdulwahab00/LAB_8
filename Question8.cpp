#include<iostream>
#include<stack> 
using namespace std;
struct node
{
	int data;
	node* LeftNode;
	node* RightNode;

};
class Tree
{
public:
	node* root;
	Tree()
	{
		root = NULL;
	}
	void insert_node(int);
	
	void iterativePreorder(node* root);
	
	void postorderIterative(node* root);
	
};
void Tree::insert_node(int val)
{
	node* new_node = new node;
	new_node->data = val;
	new_node->LeftNode = NULL;
	new_node->RightNode = NULL;
	node* temp = root;
	if (root == NULL)
	{
		root = new_node;
	}
	while (temp != NULL)
	{

		if (root->data == new_node->data)
		{
			break;
		}

		else if (new_node->data < temp->data && temp->LeftNode == NULL)
		{
			temp->LeftNode = new_node;
			break;
		}
		else if (new_node->data < temp->data)
		{
			temp = temp->LeftNode;
		}
		else if (new_node->data > temp->data && temp->RightNode == NULL)
		{
			temp->RightNode = new_node;
			break;
		}
		else
		{
			temp = temp->RightNode;
		}

	}

}

void Tree:: iterativePreorder(node* root)
{
	
	if (root == NULL)
		return;

	stack<node*> nodeStack;
	nodeStack.push(root);

	
	while (nodeStack.empty() == false) 
	{
		struct node* node = nodeStack.top();
		cout << node->data << "   ";
		
		nodeStack.pop();

		if (node->RightNode)
			nodeStack.push(node->RightNode);
		if (node->LeftNode)
			nodeStack.push(node->LeftNode);
	}
}


void Tree::postorderIterative(node* root)
{

	if (root == NULL)
		return;

	stack<node*> nodeStack;
	nodeStack.push(root);


	while (nodeStack.empty() == false)
	{
		struct node* node = nodeStack.top();
		

		nodeStack.pop();

		
		
		if (node->LeftNode)
			nodeStack.push(node->LeftNode);
		cout << node->data << "   ";
		if (node->RightNode)
			nodeStack.push(node->RightNode);
	}
}




int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()		---> Press 1" << endl
			
			<< "iterativePreorder()	---> Press 2" << endl
			
			<< "iterativePostOrder()	---> Press 3" << endl
			<< "Exit()			---> Press 0" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			while (val != -222)
			{

				cout << "Enter the Element You want to insert/ Enter -222 To exit: ";
				cin >> val;
				if (val != -222)
				{


					obj.insert_node(val);
				}
			}

			break;
		}
		
		case 2:
		{
			cout << "Pre Order Data printing: " << endl;
			
			obj.iterativePreorder(obj.root);
			cout << endl;
			break;
		}
		
		case 3:
		{
			cout << "Post Order Data printing: " << endl;
			
			
			obj.postorderIterative(obj.root);
			cout << endl;
			break;
		}
		default:
		{
			cout << "Select the Correct Option" << endl;
		}


		}
	} while (opt != 0);
}

