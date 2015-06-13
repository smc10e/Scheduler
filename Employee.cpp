#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(string f, string l){
	first = f;
	last = l;
	email = "none";

	for(int i =0; i < 96; i++){
		prefs[i] = true;
	}

}

Employee::Employee(string f, string l, string e){
	first = f;
	last = l;
	email = e;

	for(int i =0; i < 96; i++){
		prefs[i] = true;
	}
}

void Employee::showInfo(){
	if(email != "none")
		cout << first << "\t" << last << "\t" << email << "\n";
	else
		cout << first << "\t" << last << "\n";
}

string Employee::getFirst(){
	return first;
}

string Employee::getLast(){
	return last;
}

string Employee::getEmail(){
	return email;
}