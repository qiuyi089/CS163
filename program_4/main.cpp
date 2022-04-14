/*
Dung Nguyen
program_4
*/

#include "BST.h"


int main(){
	BST tree;//create an object for the tree
	location place;//create an object for the location struct
	//create a temp to hold the information from the user answer.
	place.name = new char[100];
	place.country = new char[100];
	place.summary = new char[100];
	place.review = new char[100];
	place.sites = new char[100];
	
	char res;
	char temp_res[20];

	do{
		//ask the user what they would like to do
		//if they press q then it will end the program
		cout<<"Press Q or q to quit the program. \n";
		cout<<"What would you like to do? \n";
		cout<<"(A)Enter a place (B)display all (C)remove all 5 rate (D)remove a place \n";
		cin>>res;
		cin.ignore(100,'\n');

		cout<<" \n";

		//if they choose A then ask them for the place information and then pass it to the insert function
		if(tolower(res) == 'a'){

			cout<<"What is the place name: ";
			cin.get(place.name,100,'\n');
			cin.ignore(100,'\n');
		
			cout<<"What is the country: ";
			cin.get(place.country,100,'\n');
			cin.ignore(100,'\n');
		

			cout<<"Summary of the thing you do: ";
			cin.get(place.summary,100,'\n');
			cin.ignore(100,'\n');
		
		
			cout<<"Your review of the place: ";
			cin.get(place.review,100,'\n');
			cin.ignore(100,'\n');
		
			cout<<"List 5 sites you visits: ";
			cin.get(place.sites,100,'\n');	
			cin.ignore(100,'\n');
		
			cout<<"What your rating: ";
			cin>>place.rate;
			cin.ignore(100,'\n');

			tree.insert(place);
			
		}
		//if they choose b then display everything for them and show them the height of the tree.
		if(tolower(res) == 'b'){

			int temp = tree.height();

			tree.display();

			cout<<"The height of your tree is: "<<temp<<" \n";

		}
		//if they choose C then delete everything that have a 5 or lower rating
		//show them the height of the tree after the removal
		if(tolower(res) == 'c'){

			tree.remove_5();

			int temp = tree.height();

			cout<<"The height of your tree is: "<<temp<<" \n";


		}
		//if they choose D then ask them for the place name to remove
		//display the tree height after the removal.
		if(tolower(res) == 'd'){

			cout<<"What the place name you want to remove: ";
			
			cin.get(temp_res,20,'\n');

			cin.ignore(100,'\n');

			tree.remove(temp_res);

			int temp = tree.height();

			cout<<"The height of your tree is: "<<temp<<" \n";
			

		}

	}while(tolower(res) != 'q');





}
