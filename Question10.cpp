#include<iostream>
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
	int LeafCount(node* root, int c);
	
};
int Tree::LeafCount(node* root, int count)
{
	if (root == NULL)
		return -1;

	if (root->LeftNode == NULL && root->RightNode == NULL) {
		return 1 + count;
	}
	else {
		int lc = LeafCount(root->LeftNode, count);
		int total = LeafCount(root->RightNode, lc);
		return total;
	}
}
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




int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()	---> Press 1" << endl
			
			<< "LeafCount()	---> Press 2" << endl
			
			
			<< "Exit()		---> Press 0" << endl;
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
			
			cout<<"Number of leaf nodes are: "<<obj.LeafCount(obj.root,0);
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
