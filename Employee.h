#include <string>

using namespace std;

class Employee {
public:
	Employee();
	Employee(string first, string last);
	Employee(string first, string last, string email);

	string getFirst();
	string getLast();
	string getEmail();
	void showPrefs();
	void showInfo();
	bool setFirst();
	bool setLast();
	bool setEmail();
	bool modifyPrefs();

private:
	string first;
	string last;
	string email;
	bool prefs[96];
};