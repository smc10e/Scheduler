#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"

using namespace std;

void displayMenu();
void displayEmployees(vector<Employee>& Employees);
bool addEmployee(vector<Employee>& Employees, ofstream& outFile);
bool removeEmployee(vector<Employee>& Employees, ofstream& outFile);
bool import();
bool addFactor();
bool clearPrefs();
bool newRecord();



int main(){

	int choice;
	bool validChoice = true;
	bool exit = false;
	vector <Employee> Employees;
	ifstream inFile;
	ofstream outFile;

	inFile.open("recent.txt");
	outFile.open("output.txt");

	if(!inFile){
		cout << "Error: Unable to retrieve the most recent file.\n";
	}
	else{
		string info;
		string first = "", last= "", email="";
		cout << "Employee record loaded succesfully.\n";

		while(!inFile.eof()){
			getline(inFile, info);
			outFile << info << "\n";

			int i = 0;
			while(i < info.length()){
				if(info[i] != ';'){
					first = first + info[i];
					i++;
				}
				else{
					i++;
					break;
				}
			}
			while(i < info.length()){
				if(info[i] != ';'){
					last = last + info[i];
					i++;
				}
				else{
					i++;
					break;
				}
			}
			while(i < info.length()){
				email = email + info[i];
				i++;
			}

			//cout << "\n" << first << ";" << last << ";" << email << "\n";
			Employee emp1(first, last, email);
			Employees.push_back(emp1);

			first = "";
			last = "";
			email = "";
		}
	}

	inFile.close();
	outFile.close();
	outFile.open("recent.txt",std::ios::app);
	

	while(exit == false){
		displayMenu();
	
		cout << "-> ";
		cin >> choice;
 
		do{
			validChoice = true;
			switch(choice){
				case 1:		if(addEmployee(Employees, outFile) == true){
								Employees.back().showInfo();
							}
							break;
				case 2:		removeEmployee(Employees, outFile);
							break;
				case 3:		import();
							break;
				case 4:		addFactor();
							break;
				case 5:		clearPrefs();
							break;
				case 6:		newRecord();
							break;
				case 8:		exit = true;
							break;
				case 7:		displayEmployees(Employees);
							break;
				default:	{cout << choice << " is not an option please select again\n";
							cin >> choice;
							validChoice = false;
							}
							break; 
			}
		}while(validChoice == false);
	}

	return(0);
}


bool addEmployee(vector<Employee>& Employees, ofstream& outFile){
	string first, last, email;
	char answer;

	cout << "Please enter the employee's first name: ";
	cin >> first;
	cout << "\nPlease enter the employee's last name: ";
	cin >> last;
	cout << "\nDoes the employee have an email address (Y/N)?: ";
	cin >> answer;

	while(answer !='Y' && answer != 'y' && answer != 'N' && answer != 'n'){
		cout << "Incorrect response please try again.\n";
		cout << "Does the employee have an email address (Y/N)?-> ";
		cin >> answer;
	}

	if(answer == 'Y' || answer == 'y'){
		cout << "Please enter the employee's email\n-> ";
		cin >> email;
		Employee emp(first, last, email);
		Employees.push_back(emp);
		outFile << first << ";" << last << ";" << email << "\n";
	}
	else{
		Employee emp(first, last);
		Employees.push_back(emp);
		outFile << first << ";" << last << ";" << "none\n";
	}

	return(true);
}

bool removeEmployee(vector<Employee>& Employees, ofstream& outFile){

	string f, l, e;
	char answer;

	cout << "Enter the first name of the employee you would like to remove?\n-> ";
	cin >> f;

	cout << "Enter the last name of the employee you would like to remove?\n-> ";
	cin >> l;

	cout << "Does the employee have an email address (Y/N)?\n-> ";
	cin >> answer;

	while(answer !='Y' && answer != 'y' && answer != 'N' && answer != 'n'){
		cout << "Incorrect response please try again.\n";
		cout << "Does the employee have an email address (Y/N)?-> ";
		cin >> answer;
	}

	if(answer == 'Y' || answer == 'y'){
		cout << "Please enter the employee's email\n-> ";
		cin >> e;
		for(int i =0; i < Employees.size(); i++){
			if(Employees[i].getFirst() == f){
				if(Employees[i].getLast() == l){
					if(Employees[i].getEmail() == e){
						Employees.erase(Employees.begin()+i);
						break;
					}
				}
			}
		}
	}
	else{
		for(int i =0; i < Employees.size(); i++){
			if(Employees[i].getFirst() == f){
				if(Employees[i].getLast() == l){
					if(Employees[i].getEmail() == "none"){
						Employees.erase(Employees.begin()+i);
						break;
					}
				}
			}
		}		
	}

	outFile.close();
	outFile.open("recent.txt");

	for(int i = 0; i < Employees.size(); i++){
		if(i != Employees.size()-1)
			outFile << Employees[i].getFirst() << ";" << Employees[i].getLast() << ";" << Employees[i].getEmail() << "\n";
		else
			outFile << Employees[i].getFirst() << ";" << Employees[i].getLast() << ";" << Employees[i].getEmail();
	}

	return(true);
}

bool import(){

	return(true);
}

bool addFactor(){

	return(true);
}

bool clearPrefs(){

	return(true);
}

bool newRecord(){

	return(true);
}

void displayEmployees(vector<Employee>& Employees){

	cout << "First Name\tLast Name\tEmail\n"; 

	for(int i = 0; i< Employees.size(); i++){
		Employees[i].showInfo();
	}
}

void displayMenu(){

	printf("\n\tMain Menu\n");
	printf("1. Add Employee\n");
	printf("2. Remove Employee\n");
	printf("3. Import Employee Preferences\n");
	printf("4. Add Scheduling Factor\n");
	printf("5. Clear Preferences\n");
	printf("6. Create New Employee Record\n");
	printf("7. Display All Employees\n");
	printf("8. Exit\n");
}