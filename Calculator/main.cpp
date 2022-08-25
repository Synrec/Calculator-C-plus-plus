#include<iostream>;
#include<string>;
using namespace std;

bool isNumber(string number) {
	bool hasDecimal = false;
	for (int i = 0; i < number.length(); i++) {
		char num = number[i];
		if (!isdigit(num)) {
			if (hasDecimal) {
				return false;
			}
			else if (num == '.' && i < number.length() - 1) {
				hasDecimal = true;
			}
			else if (i < number.length()) {
				return false;
			}
		}
	}
	return true;
}

bool isValidOperator(string oper) {
	if (oper == "+")return true;
	if (oper == "-")return true;
	if (oper == "*")return true;
	if (oper == "/")return true;
	if (oper == "^")return true;
	return false;
}

int main() {
	string number, oper, input;
	bool exit = false, verified = false;
	double v1 = 0.0, v2 = 0.0;
	while (!exit) {
		string operation;
		if (oper == "+")operation = "Addition";
		if (oper == "-")operation = "Subtraction";
		if (oper == "*")operation = "Multiplication";
		if (oper == "/")operation = "Division";
		if (oper == "^")operation = "Power";
		cout << "v1 = " << v1 << "\n";
		cout << "v2 = " << v2 << "\n";
		cout << "Operation is " << operation << "\n";
		if (!verified) {
			cout << "Input '0x0' to exit\n";
			cout << "Please enter a number or operator:\n";
			cin >> input;
			if (input == "0x0") {
				exit = true;
				cout << "Terminating Calculator.\nThanks for using!\n";
			}
			else if (input == "clear" || input == "c") {
				v1 = 0;
				v2 = 0;
				oper = "";
				cout << "Cleared calculator values.\n\n";
			}
			else {
				if (isNumber(input)) {
					if (!v1) {
						v1 = stod(input);
					}
					else if (!v2) {
						v2 = stod(input);
					}
				}
				else if (isValidOperator(input) && oper.length() <= 0) {
					oper = input;
				}
			}
			if (oper.length() > 0) {
				if (v1 && v2) {
					verified = true;
				}
			}
		}
		else {
			if (oper.length() > 0) {
				if (v1 && v2) {
					int calculation = 0;
					if (oper == "+")calculation = 1;
					if (oper == "-")calculation = 2;
					if (oper == "*")calculation = 3;
					if (oper == "/")calculation = 4;
					if (oper == "^")calculation = 4;
					switch (calculation) {
					case 1:
						cout << "Result: " << v1 + v2 << "\n\n";
						v1 = 0.0;
						v2 = 0.0;
						oper = "";
						break;
					case 2:
						cout << "Result: " << v1 - v2 << "\n\n";
						v1 = 0.0;
						v2 = 0.0;
						oper = "";
						break;
					case 3:
						cout << "Result: " << v1 * v2 << "\n\n";
						v1 = 0.0;
						v2 = 0.0;
						oper = "";
						break;
					case 4:
						cout << "Result: " << v1 / v2 << "\n\n";
						v1 = 0.0;
						v2 = 0.0;
						oper = "";
						break;
					case 5:
						cout << "Result: " << pow(v1, v2) << "\n\n";
						v1 = 0.0;
						v2 = 0.0;
						oper = "";
						break;
					}
				}
				verified = false;
			}
		}
	}
	return 0;
}