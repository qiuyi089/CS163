//Dung Nguyen
//program_5


#include "graph.h"


graph::graph(){
	//set the size of the array to 5
	//and then create a new array of vertex
	//set all head and tail to null	
	size = 5;	
	tail = NULL;			
	adjacency_list = new vertex[size];

	for(int i = 0; i < size; ++i)

		adjacency_list[i].head = NULL;

}



graph::~graph(){
//check if we have an array and if we do then traverse it 
//delete the data in the vertex
//call the remove function
//set everything to NULL
if(adjacency_list){
	for(int i = 0; i < size; ++i){
		delete [] adjacency_list[i].course;
		adjacency_list[i].course = NULL;
		remove_list(adjacency_list[i].head);
		delete tail;
		tail = NULL;
	}
	delete [] adjacency_list;
	adjacency_list = NULL;
}

}
//remove function that will delete the LLL
int graph::remove_list(node *& head){
	//check if there anything in the list
	if(!head)
		return 0;
	//go to the next node
	remove_list(head -> next);
	//delete head and set it to null
	head -> adjacent = NULL;
	delete head;
	head = NULL;
}

//insert the information into the vertex
int graph::insert_vertex(char * course_name){
	//find the spot for the information
	for(int i = 0; i < size; ++i){
		//if the spot is empty then put the information in there
		if(!adjacency_list[i].course){
	
			adjacency_list[i].course = new char[strlen(course_name) + 1];
			strcpy(adjacency_list[i].course, course_name);
			return 1;
		}

	}

	return 0;

}

//insert an node to the LLL
int graph::insert_edge(char * current_vertex, char * to_attach){

	//find the index of the current index and the index you want to connect to
	int temp_index = find_index(to_attach);
	int current_index = find_index(current_vertex);
	//check to see if head is null
	//if it is then create a new node
	if(!adjacency_list[current_index].head){

		adjacency_list[current_index].head = new node;
		adjacency_list[current_index].head -> adjacent = &adjacency_list[temp_index];
		adjacency_list[current_index].head -> next = NULL;
		tail = adjacency_list[current_index].head;
		return 1;
	}
	//adding at the end of LLL
	//make a temp and put the information into it
	//set tail to point to it
	//and set tail to temp
	node * temp = new node;
	temp -> adjacent = &adjacency_list[temp_index];
	temp -> next = NULL;
	tail -> next = temp;
	tail = temp;
	return 1;

}
//display all the node in the LLL
int graph::display_all(char * key_value){
	//find the index of the course you take
	int index = find_index(key_value);
	cout<< adjacency_list[index].course <<" \n";

	if(!adjacency_list[index].head)
		return 0;
	//use current to traverse the list and display the information in the list	
	node * current = adjacency_list[index].head;
	while(current){

		cout<< current -> adjacent -> course << " \n";
		current = current -> next;

	}

	return 1;

}

//displaying depth first traversal
void graph::depth_first(char * key){
	
	bool * visited = new bool[size];
	for(int i = 0; i < size; ++i){
		visited[i] = false;
	}

	int index = find_index(key);
	show_path(index,visited);

}
//check to see if the vertext have been visit or not
//print out the information in the vertx.
void graph::show_path(int index,bool visited[]){

	visited[index] = true;
	cout<<adjacency_list[index].course<<" \n";

	for(int i = 0;i < size; ++i){

		if(!visited[i])
			show_path(i,visited);

	}
}
//find the index base on the key in the vertex
int graph::find_index(char * key){

	for(int i = 0; i < size; ++i){

		if(strcmp(adjacency_list[i].course,key) == 0)

			return i;

	}

}









