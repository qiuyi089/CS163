/*Dung Nguyen
program 4
*/

//include all the library for the program.
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

//location struct that will hold the information on a place.
struct location{

	char * name; 
	char * country;
	char * summary;
	char * review;
	char * sites;
	int rate;
	//the struct initializer and decontructor
	location();
	~location();
	int copy(location to_add);//deep copy the data into the node
};

//node struct for the binary tree.
struct node{
	
	location data;//the location struct will be the data.
	node * left;
	node * right;

};


class BST{
	
	public:
		
		BST();//initialize the data member.
		~BST();//decontructor for the class.
		int insert(location to_add);//wrapper function.
		int display();//wrapper function.
		int height();//wrapper function.
		int remove_5();//wrapper function.
		int remove(char * key);//wrapper function.
		node * retrieve(char * match);//wrapper function.
	private:
		
		node * root;//create the root for the tree.
		int insert(location to_add,node *& root);//insert the information into the tree.
		int display(node * root);//display everything alphabetical
		int height(node * root);//return back the height of the tree to the caller.	
		int remove_5(node *& root);//remove all the place with 5 rating or lower.
		int remove(char * key,node *& root);//remove a specific node base on the name the user give.
		node * left_most(node *& root);//find the inorder succussor.
		int remove_all(node *& root);//remove everything when the contructor call it.
		node * retrieve(node * root,char * match);//retrieve a copy of a node back to the caller.

};
