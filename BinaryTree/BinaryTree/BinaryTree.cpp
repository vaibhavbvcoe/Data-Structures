// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib> 
#include<iostream>
using namespace std;
struct node
{
	node(int val)
	{
		left_leaf=NULL;
		right_leaf=NULL;
		m_data=val;
	}
	int m_data;
	node *left_leaf,*right_leaf;


}*root;

void insert(node** currNode,int val)
{
	if(*(currNode) == NULL)
	{
		(*currNode) = new node(val);
		return;
	}
	else
	{
		if( (*currNode)->m_data < val )
		{
			insert( &((*currNode)->left_leaf),val );
		}else
		{
			insert( &((*currNode)->right_leaf),val );
		}

	}
}
void printInorder(struct node* nod)
{
	if (nod == NULL)
		return;   
	printInorder(nod->left_leaf); 
	cout << nod->m_data << "-->";    
	printInorder(nod->right_leaf);
}
void printPostorder(struct node* nod)
{
	if (nod == NULL)
		return;   
	printInorder(nod->left_leaf);    
	printInorder(nod->right_leaf);
	cout << nod->m_data << "-->";
}
void printPreorder(struct node* nod)
{
	if (nod == NULL)
		return;  
	cout << nod->m_data << "-->";
	printInorder(nod->left_leaf);    
	printInorder(nod->right_leaf);

}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={31,23,1234,2,89,102,321,1,9,100,432,45};
	root = new node(65);
	for (int i=0;i<11;i++)
	{
		insert(&root,arr[i]);
	}
	cout<<"preorder traversal"<<endl;
	printPreorder(root);
	cout<<std::endl<<std::endl;
	cout<<"Inorder traversal"<<endl;
	printInorder(root);
	cout<<endl<<endl;
	cout<<"PostOrder traversal"<<endl;
	printPostorder(root);
	cout<<endl<<endl;
	system("pause");
	return 0;
}

