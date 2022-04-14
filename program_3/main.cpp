
//including the hash class
#include "hash.h"

int main(){

	hash trip;//make the object for the class
	location places;//make the object for the location struct
	char res;//temp to hold the respond
	//allocate memory for the information
	places.name = new char[100];
	places.country = new char[100];
	places.summary = new char[100];
	places.review = new char[100];
	places.sites = new char[100];

	do{
		//ask the user what they want to do
		cout<<"what would you like to do? \n";
		cout<<"(A)add a travel place (B)Update a place (C)Display country (D)Review a place\n";
		cin >> res;
		cin.ignore(1000,'\n');
		//if they choose A then ask them for the place information and pass it into the insert function
		if(tolower(res) == 'a'){
			
			cout<<"What is the name of the place: ";
			cin.get(places.name,100,'\n');
			cin.ignore(100,'\n');
			
			cout<<"What country does it belong to: ";
			cin.get(places.country,100,'\n');
			cin.ignore(100,'\n');
			
			cout<<"Summary about the place: ";
			cin.get(places.summary,100,'\n');
			cin.ignore(100,'\n');
			
			cout<<"Review of the place: ";
			cin.get(places.review,100,'\n');
			cin.ignore(100,'\n');
			
			cout<<"5 sites you visit: ";
			cin.get(places.sites,100,'\n');
			cin.ignore(100,'\n');
			
			trip.insert(places);	
				
		}
		//if the user choose B then ask them the country and place they want to update
		if(tolower(res) == 'b'){
			
			return 0;	
			
			
		}
		//if the respond is C then ask them what country they like to see and pass it into the display_country function
		if(tolower(res) == 'c'){
			char country[100];
			
			cout<<"What country you want to see? \n";
			cin.get(country,100,'\n');
			cin.ignore(100,'\n');
			
			trip.display_country(country);
		}
		//if they choose D then ask them for the country and the place name 
		//pass it into the review function ot display the information
		if(tolower(res) == 'd'){
			
			char temp_place[100];
			char temp_country[100];
			
			cout<<"What is the place you want to see: ";
			cin.get(temp_place,100,'\n');
			cin.ignore(100,'\n');
			
			cout<<"What country the place is in: ";
			cin.get(temp_country,100,'\n');
			cin.ignore(100,'\n');
			
			trip.review(temp_country,temp_place);		
			
			
		}
		
			
	}while(tolower(res) != 'q');//if the user want to quit then press q to get out.




}
