#include "queue.h"



int main(){
	
	queue line;//make an oject for the queue class
	
	product items;//make an oject for the stack class
		
	customer temp_cus;//make a temp for the customer information
	
	char res;//user respond
	
	char res1;//user respond

	char temp_key[40];//key for searching
	
	temp_cus.name = new char[40];//temp for the name 	
	
	items.product_name = new char[40];//temp for the product name

	items.part_number = new char[20];//temp for the part number

	do{
		//ask the user what they like to do
		cout<<"What would you like to do?(To quit the program just type q or Q) \n";

		cout<<"(A)Register customer (B)Display_cus (C)buy item (D)Check out\n";
  
		cin >> res;

		cin.ignore(1000,'\n');
		//if the user answer a then ask them for their name 		
		if(tolower(res) == 'a'){

			cout<<"customer name: ";

			cin.get(temp_cus.name,40);

			cin.ignore(1000,'\n');

			
			cout<<"customer ID: ";

			cin >> temp_cus.ID;

			cin.ignore(1000,'\n');

			
			cout<<"group number: ";
			
			cin >> temp_cus.number_group;

			cin.ignore(1000,'\n');
			
			//pass the information in to the enqueue function
			line.enqueue(temp_cus);

		}
		//if they choose b then display every customer in the line and show how many customer
		else if(tolower(res) == 'b'){

			int cap = line.display();
			
			cout<<"There is currently "<<cap<<" customer in the store. \n";

		}
		//if they choose c then ask them for the product information 
		else if(tolower(res) == 'c'){

			cout<<"Product name: ";
			cin.get(items.product_name,40,'\n');
			cin.ignore(1000,'\n');

			cout<<"Part numner: ";
			cin.get(items.part_number,20,'\n');
			cin.ignore(1000,'\n');

			cout<<"Quanity: ";
			cin >> items.quanity;
			cin.ignore(100,'\n');

			cout<<"Price: ";
			cin >> items.price;
			cin.ignore(100,'\n');
			
			cout<<"Who buying it: ";
			cin.get(temp_key,40,'\n');
			cin.ignore(100,'\n');
			//pass the product information in to the add_cart function
			line.add_cart(items,temp_key);
		}
		//if they choose d then start ask them for the customer.
		else if(tolower(res) == 'd'){

			int num;
			//show them the item and ask them to confirm their buying
			do{
				
				int num2 = line.check_out();	
				
				cout<<"(Y/N) ?";
				
				cin >> res;
				
				cin.ignore(100,'\n');
				//if they answer y then add the number
				if(tolower(res) == 'y')
					
					num = num2 + num;
				//if they choose n then don't add 
				if(tolower(res) == 'n')

					cout<<"The item is remove. \n";

				cout<<"Do you still want to check out(Y/N)? ";

				cin >> res1;

				cin.ignore(100,'\n');

			}while(tolower(res1) != 'n');//ask them if they finish check out
			
			cout<<"It will be a total of "<<num<<" dollars. \n";
		}
		
	}while(tolower(res) != 'q');//the program will quit if enter in q





	return 1;
}



