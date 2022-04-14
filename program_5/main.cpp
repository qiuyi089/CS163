//Dung Nguyen
//program_5

#include "graph.h"


int main(){

	graph table;//create an object for the graph class
	char res;//take in the user responde
	char course_name[100];//temp to hold on to the course name
	do{
		//ask the user what they would like to do 
		//and the program will end when the user enter in q
		cout<<"What would you like to do? \n";
		cout<<"(A)Enter in a course (B)insert edge (C)Display (D)display all possivle path\n";
		cin>>res;
		cin.ignore(100,'\n');
		//if they choose A then ask them for the course name
		//then call the insert vertex function
		if(tolower(res) == 'a'){

			cout<<"What is the course name: ";
			cin.get(course_name,100,'\n');
			cin.ignore(100,'\n');

			table.insert_vertex(course_name);
		}
		//if they choose B then ask them for what course they want to
		//connect togother
		//then call the insert edge function
		if(tolower(res) == 'b'){
			char temp1[30];
			char temp2[30];

			cout<<"Insert a edge from: ";
			cin.get(temp1,30,'\n');
			cin.ignore(30,'\n');

			cout<<"To: ";
			cin.get(temp2,30,'\n');
			cin.ignore(100,'\n');

			table.insert_edge(temp1,temp2);
		}
		//if they choose C then ask them the course they have take
		//then call the display all function to show them all the class they can take
		if(tolower(res) == 'c'){
			
			char course[30];
			cout<<"What is the course plan you want to see: ";
			cin.get(course,30,'\n');
			cin.ignore(100,'\n');
			
			table.display_all(course);

		}
		
		//if(tolower(res) == 'd')

			//table.show_ver();
			
		/*
			char temp3[30];
			cout<<"what is the course you want to start out: ";
			cin.get(temp3,30,'\n');
			cin.ignore(100,'\n');

			table.depth_first(temp3);

		}*/



		
	}while(tolower(res) != 'q');


}
