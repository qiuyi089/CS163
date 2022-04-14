/*
Dung Nguyen
program_4
*/




#include "BST.h"
//initialize all the data member.
BST::BST(){

	root = NULL;	
}
//delete everything
BST::~BST(){

	remove_all(root);	

}
//initialize all the data member
location::location(){
	
	name = NULL;
	country = NULL;
	summary = NULL;
	review = NULL;
	sites = NULL;
	rate = 0;
}

//delete everything 
location::~location(){

	if(name){
		delete [] name;
		name = NULL;
	}
	if(country){
		delete [] country;
		country = NULL;
	}
	if(summary){
		delete [] summary;
		summary = NULL;
	}
	if(review){
		delete [] review;
		review = NULL;
	}
	if(sites){
		delete [] sites;
		sites = NULL;
	}

}



//do a deep copy of the thing that need to add into the node.
int location::copy(location to_add){

	name = new char[strlen(to_add.name) + 1];
	strcpy(name,to_add.name);

	
	country = new char[strlen(to_add.country) + 1];
	strcpy(country,to_add.country);


	summary = new char[strlen(to_add.summary) + 1];
	strcpy(summary,to_add.summary);

	review = new char[strlen(to_add.review) + 1];
	strcpy(review,to_add.review);

	sites = new char[strlen(to_add.sites) + 1];
	strcpy(sites,to_add.sites);

		
	rate = to_add.rate;
	
	return 1;

}

//wrapper function
int BST::insert(location to_add){

	
	return insert(to_add,root);


}

//insert the node into the tree
int BST::insert(location to_add, node *& root){

	//if there is nothing in the tree
	if(!root){

		root = new node; 

		root -> data.copy(to_add);

		root -> left = NULL;

		root -> right = NULL;

		return 1;

	}
	//else move it base on it name
	if(strcmp(to_add.name,root -> data.name) < 0)

		return insert(to_add, root -> left);

	
	return insert(to_add,root -> right);

}

//wrapper function for the height
int BST::height(){

	return height(root);

}

//return height of the tree back to the caller.
int BST::height(node * root){
	//if the tree is empty then do nothing
	if(!root)
		return 0;

	//go left and right to count number of level.
	int left = height(root -> left) + 1;
	int right = height(root -> right) + 1;
	
	//return the bigger number
	if(left < right)
		return right;

	if(left > right)
		return left;
}

//retrieve function
node * BST::retrieve(char * match){
	
	return retrieve(root,match);

}

//return a copy of the node back to the caller
node * BST::retrieve(node * root,char * match){
	//if it empty then return null
	if(!root)
		return NULL;
	//compare the name and return the node 
	if(strcmp(match,root -> data.name) == 0)

		return root;
	//go left if the alphabet is smaller.
	if(strcmp(match,root -> data.name) < 0)

		return retrieve(root -> left,match);

	if(strcmp(match,root -> data.name) > 0)

		return retrieve(root -> right,match);


}
//wrapper function
int BST::remove_5(){

	return remove_5(root);

}
//remove all the 5 or lower rating score from the tree
int BST::remove_5(node *& root){
	if(!root)
		return 0;

	int result = remove_5(root -> left) + remove_5(root -> right);

	if(root -> data.rate <= 5){
		//has two children
		if(root->right && root->left)
		{
			//
			node * temp = left_most(root -> right);
			temp -> left = root -> left;
			temp -> right = root -> right;
			delete root;
			root = temp;

		}
		//case leaf node or only one child
		else
		{
			node * temp;
			if(left)
			{
				temp = root->left;	
			}
			else
			{
				temp = root->right;	
			}
			delete root;
			root = temp;
		}
		result += 1;
	}
	return result;
}
//wrapper function
int BST::remove(char * key){

	return remove(key,root);

}

//remove the node with a specific name
int BST::remove(char * key, node *& root){

	if(!root)
		return 0;

	int result = remove(key, root -> left) + remove(key, root -> right);

	if(strcmp(key, root -> data.name) == 0){

		//has two children
		if(root->right && root->left)
		{
			
			node * temp = left_most(root -> right);
			temp -> left = root -> left;
			temp -> right = root -> right;
			delete root;
			root = temp;
			
		}
		//case leaf node or only one child
		else
		{
			node * temp;
			if(left)
			{
				temp = root->left;	
			}
			else
			{
				temp = root->right;	
			}
			delete root;
			root = temp;
		}
		result += 1;
	}
	return result;
}
//return the left most node in the tree
node * BST::left_most(node *& root){
	//if the tree is empty then return null	
	if(!root)
		return NULL;
	//if there isnt a left child
	if(!root -> left){
		
		node * temp = root;

		root = root -> right;

		temp -> left = NULL;

		temp -> right = NULL;
		
		return temp;

	}
//if there is a left child then go to it.
	return left_most(root -> left);
	
	
}


//remove everything in the binary tree
int BST::remove_all(node *& root){

	if(!root)
		return 0;

	remove_all(root -> left);
	remove_all(root -> right);

	delete root;

	root = NULL;

}


//wrapper function
int BST::display(){

	return display(root);

}
//do a inorder traversal and display the data inside the node.
int BST::display(node * root){

	if(!root)
		return 0;
	display(root -> left);

	cout<<root -> data.name<<"\n";
	cout<<root -> data.country<<"\n";
	cout<<root -> data.summary<<"\n";
	cout<<root -> data.review<<"\n";
	cout<<root -> data.sites<<"\n";
	cout<<root -> data.rate<<"\n";
	cout<<" \n";
	display(root -> right);


}





















