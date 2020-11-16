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
	int findMax(node* root);
	int findMin(node* root);
	
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


int Tree::findMax(node* temp)
{
	node* current = temp;


	while (current->RightNode != NULL)
	{
		current = current->RightNode;
	}
	return(current->data);
}
int Tree:: findMin(node* temp)
{
	node* current = temp;

	
	while (current->LeftNode != NULL)
	{
		current = current->LeftNode;
	}
	return(current->data);
}
int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()	---> Press 1" << endl
			
			<< "FindMax()	---> Press 2" << endl
			<< "FindMin()	---> Press 3" << endl
			
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
			
			cout<<"Max Value is: "<<obj.findMax(obj.root);
			cout << endl;
			break;
		}
		case 3:
		{
			
			cout<<"Min value is: "<<obj.findMin(obj.root);
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
