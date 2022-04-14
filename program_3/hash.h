/*Dung Nguyen 

2/22/2018

*/

//include the library 
#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>
using namespace std;


//make the struct for the location 
struct location{

	char * name;

	char * country;

	char * summary;

	char * review;

	char * sites;

	int rate;

	location();//initalize the data
	~location();//deallocate all the data
	int copy(const location to_add);//deep copy the data into the struct
	int display();//display the data member.
};

//make the node for the hash table
struct node{
	
	location place;

	node * next;

};

class hash{

	public:

		hash();//initalize the data
		~hash();//deallocate the data
		
		int insert(location to_add);//insert the node into the hash table

		node * retrieve(node * head, char * country, char * place);//retrieve the data from the hash table

		int review(char * country, char * place);//show the data inside a node

		int display_country(char * key_name);//display everything in a hash index
		
		int display_country(node * head);//display everything in a hash index

		int read_in();//read in from the text file


	private:

		node ** hash_table;//make a hash table
	
		int hash_index(char * key);//find the index base on the country of the place
		
		int hash_table_size;//the max size of the hash table

};
