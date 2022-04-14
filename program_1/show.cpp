#include "show.h"
//initialize the private data member.
show::show(){

	head = NULL;
	
    head_gen = NULL;	
	

}

//decontructor
show::~show(){





}
//initialize the data member of the struct info.
info::info(){

	name = NULL;

	genre = NULL;

	description = NULL;

	last_ep = NULL;

	number_watch = 0;

}
//decontructor of the struct info.
info::~info(){
/*
	delete [] name;

	delete [] genre;

	delete [] description;

	delete [] last_ep;
*/

}
//called the add show function and pass in head.
int show::add_show(info to_add){


	return add_show(head_gen,to_add);


}
//add the show in order and genre.
int show::add_show(genre_list *& head_gen,info to_add){
//create a new genre if the list is empty
	if(!head_gen){

		head_gen = new genre_list;

		head_gen -> genre_1= new char[strlen(to_add.genre) + 1];

		strcpy(head_gen -> genre_1,to_add.genre);

		head_gen -> next = NULL;
		
		return sorting_list(head_gen -> head,to_add);
			
	}
	//find the right genre and pass it to the sorting function
	if(strcmp(head_gen -> genre_1,to_add.genre) == 0)
	
		sorting_list(head_gen -> head,to_add);
	
	return add_show(head_gen -> next,to_add);

}


//deep copy your data into the node.

int show::copy(node *& head,info to_add){

	
	head -> data.name = new char[strlen(to_add.name) +1];

	strcpy(head -> data.name, to_add.name);

	
	head -> data.genre = new char[strlen(to_add.genre) +1];

	strcpy(head -> data.genre, to_add.genre);


	head -> data.description = new char[strlen(to_add.description) +1];

	strcpy(head -> data.description, to_add.description);


	head -> data.last_ep = new char[strlen(to_add.last_ep) +1];

	strcpy(head -> data.last_ep, to_add.last_ep);


	head -> data.number_watch = to_add.number_watch;

	return 1;

}

n the stack ADT, there will be the push function that will take in the information from the enqueue, and push it into the array with a top index which will be increment every time an item is add in. 
//create the LLL for the show.
int show::sorting_list(node *& head,info to_add){
//if there is no show then make a new list.
	if(!head){

		head = new node;

		copy(head,to_add);

		head -> next = NULL;
		
		return 1;

	}
//if there is show then put it in the right order.
	node * current = head;

	node * previous = current;

	while(current){
		//if the add show have less view than the current.
		if(to_add.number_watch <= current -> data.number_watch){

			node * temp = new node;

			copy(temp,to_add);

			temp -> next = current;

			previous -> next = temp;
		}
		//if the add show have more views than the current.
		else if(to_add.number_watch >= current -> data.number_watch){
			
			node * temp = new node; 

			copy(temp,to_add);

			temp -> next = current;
			
			head = temp;

			return 1;
		}		
		//move the previous and current up.
		previous = current;

		current = current -> next;


	}
	//add the show at the end of the list.
	previous -> next = new node; 

	copy(previous -> next, to_add);

	previous -> next -> next = NULL;

		
	return 0;


}
/*
int show::watch(char * key_show, char * key_genre){


	return watch(head_gen,key_show,key_genre);


}

int show::watch(genre_list *& head_gen,char * key_show,char * key_genre){

	if(!head_gen)

		return 1;

	else if(strcmp(head_gen -> genre_1,key_genre) == 0){

		return update(head_gen -> head,key_show);

	}

	return watch(head_gen -> next,key_show,key_genre);

}

*/

//display the show in the genre.
int show::display_genre_show(char * key_genre){

	if(!head_gen)

		return 0;

	
	genre_list * current = head_gen;
	//find the right genre to display the show.
	while(current){

		if(strcmp(current -> genre_1,key_genre) == 0)

			return display_genre_show(current -> head);

		current = current -> next;

	}

	return 0;

}
//called the function that will display everything.
int show::display_all(){

	return display_all(head_gen);

}
//display everything.
int show::display_all(genre_list * head_gen){

	if(!head_gen)

		return 1;

	cout<<"GENRE: "<<head_gen -> genre_1<<"\n";

	display_genre_show(head_gen -> head);
	
	return display_all(head_gen -> next);


}


//display the show information in the show node

int show::display_genre_show(node * head){

	if(!head)

		return 1;

	cout<<"The show name is: "<<head -> data.name<<"\n";

	cout<<"The show genre is: "<<head -> data.genre<<"\n";

	cout<<"The show description: "<<head -> data.description<<"\n";

	cout<<"The last episode you watch is: "<<head -> data.last_ep<<"\n";

	cout<<"The number of time the show is watch is: "<<head -> data.number_watch<<"\n";


	return display_genre_show(head -> next);

}

