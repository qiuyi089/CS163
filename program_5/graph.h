/*
Dung Nguyen 
program_5
*/

//including all the library
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;
//create a struct for the vertex
struct vertex{

	char * course;
	struct node * head;
	
};

//create a struct for the linear link list
struct node{

	vertex * adjacent;

	node * next;
};


class graph{

	public:

		graph();//constructor
		~graph();//deconstructor
		
		int insert_vertex(char * course_name);//insert an vertext
		int insert_edge(char * current_vertex, char * to_attach);//insert the edge
		int display_all(char * key_value);//display the path of the available class you can take
		void depth_first(char * key);//show all the combination of the class you can take
	private:
		int remove_list(node *& head);//remove eveything in the linear link list
		void show_path(int index,bool visited []);//check if we already visit the vertex or not
		int find_index(char * key);//find the index base on the course the user input in
		int size;//set the size of the vertext to 5
		vertex * adjacency_list;//array of vertex
		node * tail;//the tail of linear link list
};
