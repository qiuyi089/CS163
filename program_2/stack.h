/*
Dung Nguyen

ID: 976412641

program_2
*/

//include the library
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//struct for the items that the customer will order.
struct product{

	char * product_name;
	char * part_number;
	int quanity;
	int  price;
	
	product();

	~product();

};
//the stack of the cart
struct node{
	
	product * item;

	node * next;

};


class stack{

	public:

		stack();//initalize all the member
		~stack();//deconstruction everyhting 
		
		int copy(node *& head, product to_add);//deep copy the data into stack
		int push(product to_add);//push the data into the stack
		int pop();//delete the top index of stack
		int peek();//take a look at the top index
		int peek_2();//return the top index back
	private:
		node * head;//the head of the list 
		int top_index;//the index of the stack
	    int MAX;//maximum number of stack 

};










