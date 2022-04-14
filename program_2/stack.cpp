#include "stack.h"

//initalize the data 
stack::stack(){

	head = NULL;

	top_index = 0;

	MAX = 5;


}

//delete everything
stack::~stack(){
	
	while(pop()){
	
		

	}


}

//initalize everything in the struct product
product::product(){

	product_name = NULL;

	part_number = NULL;

	price = 0;

	quanity = 0;

}
product::~product(){

	//delete [] product_name;

	//delete [] part_number;

	//product_name = NULL;

	//part_number = NULL;
	
}
//deep copy the data into the index that they are suppose to be in
int stack::copy(node *& head, product to_add){

	head -> item[top_index].product_name = new char[strlen(to_add.product_name) + 1];

	strcpy(head -> item[top_index].product_name, to_add.product_name);

	head -> item[top_index].part_number = new char[strlen(to_add.part_number) + 1];

	strcpy(head -> item[top_index].part_number, to_add.part_number);

	head -> item[top_index].price = to_add.price;
		
	head -> item[top_index].quanity = to_add.quanity;

	return 1;

}

//push the data the into the stack.
int stack::push(product to_add){
//if the list is empty then make a new node.
	if(!head){

		head = new node;
		
		head -> item = new product[MAX];

		copy(head,to_add);

		head -> next = NULL;
		
		top_index += 1;

	}
	//if the stack is full then make a new node
	else if(top_index == MAX){
	
		top_index = 0;	

		node * temp = head;

		head = new node;

		head -> item = new product[MAX];
		
		copy(head,to_add);

		head -> next = temp;
		
		top_index += 1;

	}
//else incrrement the index by 1 and copy the data 
	copy(head,to_add);

	top_index += 1;

	return 1;


}
//peek function
int stack::peek(){

	if(!head)

		return 0;

	return 1;
}
//show the client the top index
int stack::peek_2(){

	if(!head)
		return 0;

	cout<<"The items is "<<head -> item[top_index - 1].product_name<<"\n";
	
	cout<<"PRICE: "<<head -> item[top_index -1].price<<"\n";	

}

//delete the stack
int stack::pop(){

	if(!head)
		return 0;
//delte the node when get to the last index.
	if(top_index == 1){

		node * temp = head -> next;

		for(int i = 0; i < MAX; ++i){

			delete [] head -> item[i].product_name;

			delete [] head -> item[i].part_number;

		}

		delete [] head -> item;

		delete head;

		head = temp;

		top_index = MAX;

		return 0;

	}
//pop one index everytimes.
	top_index -= 1;

	return head -> item[top_index].price;

}








