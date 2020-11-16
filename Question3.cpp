#include<iostream>
#define COUNT 10
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
	node* deleteNode(node* r, int v);
	void print2D(node* root);
	void print2DUtil(node* root, int space);
};
void Tree::print2DUtil(node* root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->RightNode, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";


	print2DUtil(root->LeftNode, space);
}


void Tree::print2D(node* root)
{

	print2DUtil(root, 0);
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

node* Tree::deleteNode(node* r, int v)
{

	if (r == NULL) {
		return NULL;
	}

	else if (v < r->data) {
		r->LeftNode = deleteNode(r->LeftNode, v);
	}

	else if (v > r->data) {
		r->RightNode = deleteNode(r->RightNode, v);
	}
	else {

		if (r->LeftNode == NULL) {
			node* temp = r->RightNode;
			delete r;
			return temp;
		}
		else if (r->RightNode == NULL) {
			node* temp = r->LeftNode;
			delete r;
			return temp;
		}
		else {
			node* current = r->RightNode;

			while (current->LeftNode != NULL) {
				current = current->LeftNode;
			}


			node* temp = current;
			r->data = temp->data;
			r->RightNode = deleteNode(r->RightNode, temp->data);

		}
	}
	return r;
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
		obj.insert_node(data);
	}

} while (data != -222);
obj.print2D(obj.root);
int b;
cout << "Enter the Node Data you want to Delete" << endl;
cin >> b;
obj.deleteNode(obj.root,b);
obj.print2D(obj.root);

}