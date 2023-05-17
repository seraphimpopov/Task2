#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkSyntax(string str)
{
	stack <char> bracket;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(' || c == '[' || c == '{' || c == '<') {
			bracket.push(c);
		}
		else if (c == ')' || c == ']' || c == '}' || c == '>') {
			if (bracket.empty()) {
				return false;   // Found a closing bracket without a corresponding opening bracket
			}

			char top = bracket.top(); // Erase the top element, compare it with the closing slashes, and remove it from the stack

			if ((c == ')' && top != '(') ||
				(c == ']' && top != '[') ||
				(c == '}' && top != '{') ||
				(c == '>' && top != '<')) {
				return false;  // Bracket type mismatch
			}

			bracket.pop();
		}
	}

	return bracket.empty();  // All brackets must be closed
}

int main()
{
	// Tests
	string inputString = "---(++++)----";
	bool check = checkSyntax(inputString);
	// Result: 0
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "";
	check = checkSyntax(inputString);
	// Result: 0
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "before ( middle []) after ";
	check = checkSyntax(inputString);
	// Result: 0
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = ") (";
	check = checkSyntax(inputString);
	// Result: 1
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "} {";
	check = checkSyntax(inputString);
	// Result: 1
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "<(   >)";
	check = checkSyntax(inputString);
	// Result: 1
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "(  [  <>  ()  ]  <>  )";
	check = checkSyntax(inputString);
	// Result: 0
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	inputString = "   (      [)";
	check = checkSyntax(inputString);
	// Result: 1
	if (check) cout << 0 << endl;
	else cout << 1 << endl;

	return 0;
}