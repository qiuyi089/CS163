#include "queue.h"
//initalize the data member
queue::queue(){

	rear = NULL;

}

//decontruct every node in the CLL
queue::~queue(){

	while(rear){

		if(rear -> next == rear){

			delete [] rear -> data.name;

			delete rear;

			rear = NULL;
		}
		
		else{	

			q_node * temp = rear -> next;

			rear -> next = temp -> next;

			delete [] temp -> data.name;
			
			delete temp;
		}
	}

}
//initalize the member
customer::customer(){

	name = NULL;
	
	ID = 0;
	
	number_group = 0;			
}

customer::~customer(){

	//delete [] name;

}

//copy the data into the node
int queue::copy_info(q_node *& rear, customer to_add){

	rear -> data.name = new char[strlen(to_add.name) + 1];

	strcpy(rear -> data.name, to_add.name);

	rear -> data.ID = to_add.ID;

	rear -> data.number_group = to_add.number_group;
	
	return 1;

}
//adding a node into the CLL
int queue::enqueue(customer to_add){
//if it empty then make a new node
	if(!rear){

		rear = new q_node;

		copy_info(rear,to_add);

		rear -> next = rear;

		return 1;
		
	}
	//if you add in the first node 
	if(rear -> next == rear){

		q_node * temp = new q_node;

		copy_info(temp,to_add);

		temp -> next = rear;

		rear -> next = temp;

		rear = temp;

		return 1;
	}
//else add at the rear of the list
	q_node * temp = new q_node;

	copy_info(temp,to_add);

	temp -> next = rear -> next;

	rear -> next = temp;

	rear = temp;

	return 1;

}

//add the dat in the cart 
int queue::add_cart(product item_add,char * key){

	q_node * temp = find(rear -> next,key);
	
	temp -> cart.push(item_add);

	return 1;
}
//find the node that the buying customer are in
q_node * queue::find(q_node * rear,char * key){
//empty list then return NULL
	if(!rear)
		return NULL;
	//find a match 
	if(strcmp(rear -> data.name,key) == 0){

		return rear;
	}
	//if no match then return NULL
	if(rear == this -> rear){
		return NULL;
	}

	return find(rear -> next,key);

}

//wrapper to the display function
int queue::display(){

	return display(rear -> next);

}

//display every customer in the line
int queue::display(q_node * rear){
//if it empty then return 
	if(!rear)
		return 0;
//if you reach the end of the list then display the last and return
	if(rear == this -> rear){	
		cout<<"The customer name: "<<rear -> data.name<<" \n";
		cout<<"Their ID: "<<rear -> data.ID<<" \n";
		cout<<"The number in the group: "<<rear -> data.number_group<<"\n";
		return 1;
	}
	cout<<"The customer name: "<<rear -> data.name<<" \n";
	cout<<"Their ID: "<<rear -> data.ID<<" \n";
	cout<<"The number in the group: "<<rear -> data.number_group<<"\n";

	return display(rear -> next) + 1;
}
//delete the CLL
int queue::dequeue(){

	if(!rear)
		return 0;

	if(rear -> next == rear){

		delete rear;

		rear = NULL;

		return 1;
	}

	q_node * temp = rear -> next;

	rear -> next = temp -> next;

	delete temp;

	return 1;

}
//called the pop function from the stack to delete the items
int queue::check_out(){

	if(!rear -> cart.peek())
		return dequeue();

	else if(!rear -> next -> cart.peek())
		return dequeue();

	rear -> next -> cart.peek_2();

	return rear -> next -> cart.pop();

}





