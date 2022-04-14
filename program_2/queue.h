/*
Dung Nguyen

program 2
*/

//include the stack class
#include "stack.h"

//the struct to store the customer 
struct customer{

	char * name;

	int ID;

	int number_group;
	
	customer();//initalize all the member
	~customer();//deconstructor all the data.

};

//the node for the CLL
struct q_node{
	
	customer data;

	stack cart;
	
	q_node * next;

};

class queue{

	public: 
		queue();//initalize all the data member
		
		~queue();//decontructor the data
			
		int	copy_info(q_node *& rear, customer to_add);//copy the information into the list	
					
		int enqueue(customer to_add);//add into the CLL

		int dequeue();//delete a customer.

		int check_out();//call the pop function

		int add_cart(product item_add,char * key);//add into the stack class

		q_node * find(q_node * rear, char * key);//find the node 

		int display();//wrapper function

		int display(q_node * rear);//display everything

	private:

		q_node * rear;//the head of the CLL.
		
};



