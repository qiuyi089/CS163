#include"show.h"


//main function 
int main(){

	info show_info;//create an object for the struct info.

	show tv_show;//create an object for the show class.

	show_info.name = new char[40];//allocate space for the show name.

	show_info.genre = new char[20];//allocate space for the show genre

	show_info.description = new char[100];//allocate space for the show description

	show_info.last_ep = new char[15];//allocate space for the show last episode

	char res;//create a respond variable

	char temp_genre[20];//create a temp for genre

	char watch_show[40];//create a temp for the show name
	
		
	do{
		
		cout<<"What would you like to do? \n";//ask the user what they want to do

		cout<<"(A)Add show (B)Watch a show (C)Display all show in a genre (D)Display all\n";//show the user their option

		cin>>res;//take in the user respond

		cin.ignore(100,'\n');
		//if it a then ask them the show information and add it into the list
		if(tolower(res) == 'a'){
			
			cout<<"What is the show name: ";
			
			cin.get(show_info.name,40,'\n');
			
			cin.ignore(1000,'\n');	
			
			cout<<"What is the show genre: ";
			
			cin.get(show_info.genre,20,'\n');
			
			cin.ignore(1000,'\n');	
			
				
			cout<<"What is the show description: ";
			
			cin.get(show_info.description,100,'\n');
			
			cin.ignore(1000,'\n');	
			
			
			cout<<"What is the last episode you watched: ";
			
			cin.get(show_info.last_ep,15,'\n');
			
			cin.ignore(1000,'\n');	
		
		
			cout<<"What is the number of times the show is watched: ";
			
			cin>>show_info.number_watch;
			
			cin.ignore(100,'\n');
			
			
			tv_show.add_show(show_info);//called the add show function and add the show into the list			
		
			
		}
		//if it b then ask them what show do they want to watch.
		if(tolower(res) == 'b'){

			cout<<"What show would you like to watch: ";

			cin.get(watch_show,40,'\n');

			cin.ignore(100,'\n');

			
			cout<<"What is the genre of your show: ";

			cin.get(temp_genre,20,'\n');

			cin.ignore(1000,'\n');
			
			
			//tv_show.watch(watch_show,temp_genre);


		}
		//if c then ask them what genre it is and then display all the show in the genre.
		if(tolower(res) == 'c'){

			cout<<"What genre you want to see: ";

			cin.get(temp_genre,20,'\n');

			cin.ignore(100,'\n');
			
			tv_show.display_genre_show(temp_genre);//called the display show function
				
		}
		//if it d then called the display all function
		if(tolower(res) == 'd')

			tv_show.display_all();
		
	}while(tolower(res) != 'q');//if the user press d then the program is discontinue







	return 1;

}
