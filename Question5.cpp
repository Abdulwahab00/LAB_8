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
	void PreOrder(node* r); //(NLR)
	void inOrder(node* r); //(LNR)
	void PostOrder(node* r); //(LRN)
	
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


void Tree::PreOrder(node* r) //(NLR)
{
	if (r == NULL)
	{
		return;
	}
	cout << r->data << "  ";
	PreOrder(r->LeftNode);
	PreOrder(r->RightNode);

}

void Tree::inOrder(node* r)// (LNR)
{
	if (r == NULL)
	{
		return;
	}
	inOrder(r->LeftNode);
	cout << r->data << "  ";
	inOrder(r->RightNode);

}
void Tree::PostOrder(node* r)// (LRN)
{
	if (r == NULL)
	{
		return;
	}
	PostOrder(r->LeftNode);

	PostOrder(r->RightNode);

	cout << r->data << "  ";

}

int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()	---> Press 1" << endl
			
			<< "PreOrder()	---> Press 2" << endl
			<< "inOrder()	---> Press 3" << endl
			<< "PostOrder()	---> Press 4" << endl
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
			cout << "Pre Order Data printing: " << endl;
			obj.PreOrder(obj.root);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "IN Order Data printing: " << endl;
			obj.inOrder(obj.root);
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Post Order Data printing: " << endl;
			obj.PostOrder(obj.root);
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
