/*
Dung Nguyen 

student ID: 976412641

program 1

*/


//include library for the code
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

//the information to store the show information.
struct info{

	char * name;

	char * genre;

	char * description;

	char * last_ep;

	int number_watch;
	
	info();

	~info();
};
//node for the second LLL 
struct node{

	info data;

	node * next;


};
//node for the genre list
struct genre_list{

	node * head;
	
	char * genre_1;

	genre_list * next;


};

class show{

	public:

		show();//initialize all the data member. 
		~show();//decontructot

		int add_show(info to_add);//This function will pass the informtion to the function that add show into the list
		
		int add_show(genre_list *& head_gen,info to_add);//this will put the show into the list.

		int sorting_list(node *& head,info to_add);//this will put the show in order
		
		int copy(node *& head,info to_add);//deep copy the data.
		
		//int watch(char * key_show, char * key_genre);
		
		//int watch(genre_list *& head_gen, char * key_show, char * key_genre);

		int update(node *& head, char *key_show);//update the list when the user watch a show.
		
		int display_genre_show(char * key_genre);//display all the show in a genre.

		int display_all();//call the display all function.

		int display_all(genre_list * head_gen);//display everthing in show.

		int display_genre_show(node * head);//display all the show in the genre.

		int watch_show();//watching show .

	private:

		node * head;//head of the show list.
		
		genre_list * head_gen;//head of the genre list.

};









