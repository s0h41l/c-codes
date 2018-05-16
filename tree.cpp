#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<math.h>
using namespace::std;

struct node{
		int data;
		int degree;
		node* left;
		node* right;
		node():data(0),left(NULL),right(NULL){
		}
		node(int a):data(a),left(NULL),right(NULL){
		};
		void print()
		{
			cout<<data<<"->";
		}
};

class CBTree{
    node* root;
	public:
		int count;
		CBTree():root(NULL),count(0){
		};
		CBTree(node* ptr):root(ptr),count(1){
			ptr->left=NULL;
			ptr->right=NULL;
		}
		CBTree(int i){
			root=new node(i);
			count=1;
			}
		~CBTree()
		{
			while(root)
			{
			node* dump=root;
			root=root->right;
			delete dump;
			}
		}
		//Code to Insert data in tree (for integer);
		void In(node*& nptr,int i){
		if(nptr){
                if(nptr->data>i){
                    In(nptr->left,i);
                }
                if(nptr->data<i){
                    In(nptr->right,i);
                }
		}else{
		    nptr=new node(i);
		}
		}
		void InsertTotree(int i){
		if(root){
		node* nptr=root;
		In(nptr,i);
		}else{
		root=new node(i);
		}

		}
		//Integer Insert code end


	//Print code of tree
	void Inorder(node*& root)
		{
			if(root){
				Inorder(root->left);
				cout << root->data << " ";
				Inorder(root->right);
		}

	}
	void Preorder(node*& root)
		{
			if(root){
			cout<< root->data << " ";
			Preorder(root->left);
			Preorder(root->right);
		}
		}
	void Postorder(node*& root){
		if(root){
			Postorder(root->left);
			Postorder(root->right);
			cout << root->data << " ";
		}
	}

	void printInOrder(){
	    Inorder(root);
	}

	void printPostOrder(){
	Preorder(root);
	}

	void printPreOrder(){
	Postorder(root);
	}
	//Print code end

	//Search Code
	bool search(node* ptr){
			node* rp=root;
			while(rp)
			{
				if(rp->data==ptr->data)
					return true;
				else if(rp->data<ptr->data)
				{
					rp=rp->right;
				}
				else
				{
					rp=rp->left;
				}
			}
			return false;
		}

		//Set section of Code

		void setdegreeofnode()
		{
			void setdegofnode(node*& root);

			setdegofnode(root);
		}
		void setdegofnode(node*& root)
		{
			if(root){
				setdegofnode(root->left);
				root->degree=0;
				if(root->left)
					++root->degree;
				if(root->right)
					++root->degree;
				setdegofnode(root->right);
			}

		}

};


int main()
{
    CBTree *tree=new CBTree();


    for(int i=0;i<10;i++){
            tree->InsertTotree(i);

    }
    tree->printPreOrder();
    cout << endl;
    tree->printPostOrder();
    cout<<endl;
    tree->printInOrder();
	return 0;
}
