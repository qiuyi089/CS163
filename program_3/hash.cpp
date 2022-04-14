#include "hash.h"

//have the array of NULL head pointer
hash::hash(){

	hash_table_size = 7;
	//a for loop to set the array to NULL
	hash_table = new node*[hash_table_size];
	
	for(int i = 0; i < hash_table_size; ++i){
		
		
		hash_table[i] = NULL;	
		
		
	}



}


hash::~hash(){





}
//initalize the data member 
location::location(){

	name = NULL;

	country = NULL;

	summary = NULL;

	review = NULL;

	sites = NULL;

	rate = 0;


}
//deallocate the data member
location::~location(){

	if(name){
		delete [] name;
		name = NULL;
	}
	if(country){
		delete [] country;
		country = NULL;
	}
	if(summary){
		delete [] summary;
		summary = NULL;
	}
	if(review){
		delete [] review;
		review = NULL;
	}
	if(sites){
		delete [] sites;
		sites = NULL;
	}


}
//read in the from the file 
int hash::read_in(){

	ifstream file_in;
	file_in.open(" ");
	location temp;
	//make a temp for the information
	temp.name = new char[100];
	temp.country = new char[100];
	temp.summary = new char[100];
	temp.review = new char[100];
	temp.sites = new char[100];

	//check if the file is open
	if(file_in){
		//prime the pump
		while(file_in && file_in.peek() != EOF){

			file_in.get(temp.name,100,'|');
			file_in.ignore(1000,'|');

			file_in.get(temp.country,100,'|');
			file_in.ignore(1000,'|');

			file_in.get(temp.summary,100,'|');
			file_in.ignore(1000,'|');

			file_in.get(temp.review,100,'|');
			file_in.ignore(1000,'|');

			file_in.get(temp.sites,100,'|');
			file_in.ignore(100,'|');
		
			insert(temp);//insert from the text file into the hash table

		}

	}

	file_in.close();//close the text file

	return 1;


}


//allocate new memory and deep copy the data.
int location::copy(const location to_add){
		
	name = new char[strlen(to_add.name) + 1];
	strcpy(name,to_add.name);

	country = new char[strlen(to_add.country) + 1];
	strcpy(country,to_add.country);

	summary = new char[strlen(to_add.summary) + 1];
	strcpy(summary,to_add.summary);

	review = new char[strlen(to_add.review) + 1];
	strcpy(review,to_add.review);

	sites = new char[strlen(to_add.sites) + 1];
	strcpy(sites,to_add.sites);

	rate = to_add.rate;
}

//insert into the hash table
int hash::insert(location to_add){

	int index = hash_index(to_add.country);//find the index base on the country that the place is in

	//if the index is empty then make a new chain
	if(!hash_table[index]){

		hash_table[index] = new node; 

		hash_table[index] -> place.copy(to_add);

		hash_table[index] -> next = NULL;

		return 1;

	}
	//if the index is not empty then add in front of the chain
	node * temp = new node;

	temp -> place.copy(to_add);

	temp -> next = hash_table[index];

	hash_table[index] = temp;

	return 1;
}
//look at a particle place 
int hash::review(char * country, char * place){
	//find the index of the place
	int index = hash_index(country);
	
	if(!hash_table[index])
		return 0;
	//retrieve the information
	node * temp = retrieve(hash_table[index],country,place);
	
	temp -> place.display();
	
	return 1;	

}
//retrieve the node from the chain
node * hash::retrieve(node * head,char * country, char * place){
	//if the node is empty 
	if(!head)
		return NULL;	
	
	
	if(strcmp(head -> place.name,place) == 0 && strcmp(head -> place.country,place) == 0)

		return head;

	//move onto the next node
	retrieve(head -> next,country,place);	

}



//display all the place in a country
int hash::display_country(char * key){

	int index = hash_index(key);

	if(!hash_table[index])
		return 0;

	return display_country(hash_table[index]);	
}
//display the content of the node
int hash::display_country(node * head){

	if(!head)
		return 0;

	head -> place.display();

	return display_country(head -> next);

}

//displaying the data
int location::display(){

	cout<<name<<endl;

	cout<<country<<endl;
	
	cout<<summary<<endl;

	cout<<review<<endl;

	cout<<sites<<endl;

}
//find the index of the place
int hash::hash_index(char * key){

	
	int k = strlen(key);
	int hash_value = k;
	for(int i = 0; i < k; ++i)

		hash_value = key[i] + hash_value;

	return hash_value % hash_table_size;


}
















