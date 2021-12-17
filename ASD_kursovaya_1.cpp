#include <string>
#include <iostream>
#include <cmath>
#include "Stack.h"
//#include <stdexcept>
#define pi 3.14159265 
#define e 2.718281
using namespace std;

bool check_for_correct_input(string str) {
	bool check = true;
	for (int pos = 0; pos < str.length(); pos++)
	{
		if (str[pos] == '.' && (str[pos - 1] > 57 && str[pos - 1] < 48) && (str[pos + 1] > 57 && str[pos + 1] < 48)) {
			throw invalid_argument("Incorrect input of number");
			check = false;
		}
		else if (str[pos] == '*' && (str[pos - 1] == '(' || str[pos + 1] == ')')) {
			throw invalid_argument("Incorrect input of application *");
			check = false;
		}
		else if (str[pos] == '+' && (str[pos - 1] == '(' || str[pos + 1] == ')')) {
			throw invalid_argument("Incorrect input of application +");
			check = false;
		}
		else if (str[pos] == '-' && str[pos + 1] == ')') {
			throw invalid_argument("Incorrect input of application -");
			check = false;
		}
		else if (str[pos] == '/' && (str[pos - 1] == '(' || str[pos + 1] == ')')) {
			throw invalid_argument("Incorrect input of application /");
			check = false;
		}
		else if (str[pos] == '^' && str[pos - 1] == '(') {
			throw invalid_argument("Incorrect input of application ^");
			check = false;
		}
		else if (str[pos] <= 57 && str[pos] >= 48) {}

		else if (str[pos] == 'a' && str[pos + 1] != 'b' && str[pos + 2] != 's') {
			throw invalid_argument("Incorrect input of the abs function");
			check = false;
		}
		else if ((str[pos] == 'a' && str[pos + 1] == 'b' && str[pos + 2] == 's') && (str[pos + 3] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the abs function");
			check = false;
		}
		else if (str[pos] == 'a' && str[pos + 1] == 'b' && str[pos + 2] == 's') {
			pos = pos + 3;
		}

		else if (str[pos] == 'c' && ((str[pos + 1] != 'o' && str[pos + 2] != 's') && (str[pos + 1] != 't' && str[pos + 2] != 'g'))) {
			throw invalid_argument("Incorrect input of the cos or ctg function");
			check = false;
		}
		else if ((str[pos] == 'c' && ((str[pos + 1] == 'o' && str[pos + 2] == 's') || (str[pos + 1] == 't' && str[pos + 2] == 'g'))) && (str[pos + 3] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect input of arithmetics the cos or ctg function");
			check = false;
		}
		else if (str[pos] == 'c' && str[pos + 1] == 'o' && str[pos + 2] == 's') {
			pos = pos + 3;
		}
		else if (str[pos] == 'c' && str[pos + 1] == 't' && str[pos + 2] == 'g') {
			pos = pos + 3;
		}

		else if (str[pos] == 's' && ((str[pos + 1] != 'i' && str[pos + 2] != 'n') && (str[pos + 1] != 'q' && str[pos + 2] != 'r' && str[pos + 3] != 't'))) {
			throw invalid_argument("Incorrect input of the sin or sqrt function");
			check = false;
		}
		else if ((str[pos] == 's' && str[pos + 1] == 'i' && str[pos + 2] == 'n') && (str[pos + 3] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the sin function");
			check = false;
		}
		else if ((str[pos] == 's' && str[pos + 1] == 'q' && str[pos + 2] == 'r' && str[pos + 3] == 't') && (str[pos + 4] != '(' || (pos != 0 && (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43))))) {
			throw invalid_argument("Incorrect arithmetics the sqrt function");
			check = false;
		}
		else if (str[pos] == 's' && str[pos + 1] == 'q' && str[pos + 2] == 'r' && str[pos + 3] == 't') {
			pos = pos + 4;
		}
		else if (str[pos] == 's' && str[pos + 1] == 'i' && str[pos + 2] == 'n') {
			pos = pos + 3;
		}


		else if (str[pos] == 'l' && ((str[pos + 1] != 'o' && str[pos + 2] != 'g') && (str[pos + 1] != 'n'))) {
			throw invalid_argument("Incorrect input of the log or ln function");
			check = false;
		}
		else if ((str[pos] == 'l' && str[pos + 1] == 'o' && str[pos + 2] == 'g') && (str[pos + 3] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the log function");
			check = false;
		}
		else if ((str[pos] == 'l' && str[pos + 1] == 'n') && (str[pos + 2] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the ln function");
			check = false;
		}
		else if (str[pos] == 'l' && str[pos + 1] == 'o' && str[pos + 2] == 'g') {
			pos = pos + 3;
		}
		else if (str[pos] == 'l' && str[pos + 1] == 'n') {
			pos = pos + 2;
		}


		else if (str[pos] == 't' && str[pos + 1] != 'g') {
			throw invalid_argument("Incorrect input of the tg function");
			check = false;
		}
		else if ((str[pos] == 't' && str[pos + 1] == 'g') && (str[pos + 2] != '(' || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the tg function");
			check = false;
		}
		else if (str[pos] == 't' && str[pos + 1] == 'g') {
			pos = pos + 2;
		}

		else if (str[pos] == 'p' && str[pos + 1] != 'i') {
			throw invalid_argument("Incorrect input of the pi const");
			check = false;
		}
		else if ((str[pos] == 'p' && str[pos + 1] == 'i') && ((str[pos + 3] != 45 && str[pos + 3] != 47 && str[pos + 3] != 94 && str[pos + 2] != 41 && str[pos + 3] != 42 && str[pos + 3] != 43) || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the pi const");
			check = false;
		}
		else if (str[pos] == 'p' && str[pos + 1] == 'i') {
			pos = pos + 2;
		}
		else if (str[pos] == 'e' && ((str[pos + 2] != 45 && str[pos + 2] != 47 && str[pos + 2] != 94 && str[pos + 1] != 41 && str[pos + 2] != 42 && str[pos + 2] != 43) || (pos != 0 && (str[pos - 2] != 45 && str[pos - 2] != 47 && str[pos - 2] != 94 && str[pos - 1] != 40 && str[pos - 2] != 42 && str[pos - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the e const");
			check = false;
		}
		else if (str[pos] == '=') {}
		else if (str[pos] == ' ') {}
		else if (str[pos] == ' ' && str[pos] != '=' && str[pos] != 'a' && str[pos] != 'b' && str[pos] != 'e' && str[pos] != 'c' && str[pos] != 'o' && str[pos] != 's' && str[pos] != 't' && str[pos] != 'g' && str[pos] != 'i' && str[pos] != 'n' && str[pos] != 'q' && str[pos] != 'r' && str[pos] != 'l' && str[pos] != 'p' && str[pos] != '+' && str[pos] != '-' && str[pos] != '/' && str[pos] != '*' && str[pos] != '^' /*&& str[pos] != ')' && str[pos] != '('*/ && !(str[pos] <= 57 && str[pos] >= 48)) {
			throw invalid_argument("Invalid character. The calculator can use only numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin, cos, tg, ctg, sqrt, log, ln, abs");
			check = false;
		}

	}
	return check;
}

string change_functions(string stroka) {
	//sqrt,sgn,sin,cos,log,ln,tg,ctg
	int val1 = stroka.find("sin");
	if (val1 != -1) {
		stroka.replace(stroka.find("sin"), 3, "s");
	}
	int val2 = stroka.find("cos");
	if (val2 != -1) {
		stroka.replace(stroka.find("cos"), 3, "c");
	}
	int val3 = stroka.find("sqrt");
	if (val3 != -1) {
		stroka.replace(stroka.find("sqrt"), 4, "q");
	}
	int val4 = stroka.find("abs");
	if (val4 != -1) {
		stroka.replace(stroka.find("abs"), 3, "a");
	}
	int val5 = stroka.find("log");
	if (val5 != -1) {
		stroka.replace(stroka.find("log"), 3, "l");
	}
	int val6 = stroka.find("ln");
	if (val6 != -1) {
		stroka.replace(stroka.find("ln"), 2, "n");
	}
	int val7 = stroka.find("tg");
	if (val7 != -1) {
		stroka.replace(stroka.find("tg"), 2, "t");
	}
	int val8 = stroka.find("ctg");
	if (val8 != -1) {
		stroka.replace(stroka.find("ctg"), 3, "y");
	}
	return stroka;
}
int hasPrecedence(string i) // function to determine operator precedence
{
	int iWeight;
	if (i == "*" || i == "/")
		iWeight = 2;
	else if (i == "^")
		iWeight = 3;
	else if (i == "sin" || i == "cos" || i == "tg" || i == "ctg" || i == "sqrt" || i == "log" || i == "ln" || i == "abs")
		iWeight = 4;
	else
		iWeight = 1;
	return iWeight;
}

string postfix(string stroka) {
	Stack<string> temp;
	string postfix_string;  // converted string
	string buf, dop;
	int pos;
	size_t size = -1;
	for (int i = 0; i < stroka.length(); i++)
	{
		buf = stroka[i];
		if (buf == "0" || buf == "1" || buf == "2" || buf == "3" || buf == "4" || buf == "5" || buf == "6" || buf == "7" || buf == "8" || buf == "9" || buf == "." || buf == "e")    // if str[i] is a digit (0-9), add to postfix string
		{
			postfix_string += buf;
			size++;
		}
		else if (buf == " ") {
			if (postfix_string.length() != 0 && (postfix_string[postfix_string.length() - 1] != ' ')) {
				postfix_string += buf;
				size++;
			}
		}
		else if (buf == "p" && stroka[i + 1] == 'i')
		{
			postfix_string += buf;
			postfix_string += stroka[i + 1];
			size = size + 2;
			i = i + 2;
		}//pi
		else if (buf == "a" && stroka[i + 1] == 'b')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//log
		else if (buf == "s" && stroka[i + 1] == 'q')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//sqrt
		else if (buf == "s" && stroka[i + 1] == 'i')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//sin
		else if (buf == "c" && stroka[i + 1] == 'o')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//cos
		else if (buf == "c" && stroka[i + 1] == 't')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//ctg
		else if (buf == "t" && stroka[i + 1] == 'g')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//tg
		else if (buf == "l" && stroka[i + 1] == 'o')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//log
		else if (buf == "l" && stroka[i + 1] == 'n')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = stroka.find("(", i);
			dop.assign(stroka, i, pos - i);
			temp.push(dop);
			dop = "\0";
			stroka[pos] = ' ';
			i = pos;
		}//ln

		else if (buf == "(")   // if str[i] is an opening parenthesis, push to stack
			temp.push(buf);

		else if (buf == "+" || buf == "-" || buf == "*" || buf == "/" || buf == "^")    // if an operator...
		{
			if (temp.empty() || temp.top() == "(") // ... push to stack if stack is empty or top of stack is opening parenthesis
			{
				temp.push(buf);
			}
			else if (hasPrecedence(buf) > hasPrecedence(temp.top())) // ... if the operator has higher precedence, push to stack
			{
				temp.push(buf);
			}

			else // ... if neither of the above cases, add operator already in stack to string, pop it, and push the new operator to stack
			{
				if (buf == "-" && hasPrecedence(temp.top()) == 4) {
					temp.push(buf);
				}
				else {
					while (((temp.size()) != 0) && (hasPrecedence(buf) <= hasPrecedence(temp.top()))) {
						postfix_string += temp.top();
						postfix_string += ' ';
						size = size + 2;
						temp.pop();
					}
					temp.push(buf);
				}
			}
		}
		else if (buf == ")") // ... if str[i] is closing parenthesis, add to string and pop until opening parenthesis is reached
		{

			while (temp.top() != "(")
			{
				if (postfix_string.length() != 0 && (postfix_string[postfix_string.length() - 1] != ' ')) {
					postfix_string += ' ';
					size++;
				}
				postfix_string += temp.top();
				size++;
				temp.pop();
			}
			if (temp.top() == "(")
				temp.pop();
		}
	}
	while (!temp.empty()) // after string has been iterated, add the remainder of the stack to the string
	{
		postfix_string += ' ';
		postfix_string += temp.top();
		size = size + 2;
		temp.pop();
	}
	/*cout << size;*/
	return postfix_string;
}

void calculate(string postfix_string) {
	Stack<double> calc;
	string num;
	double number;
	double var1, var2, var3 = 0;
	for (int i = 0; i < postfix_string.length(); i++) {
		if (postfix_string[i] == '0' || postfix_string[i] == '1' || postfix_string[i] == '2' || postfix_string[i] == '3' || postfix_string[i] == '4' || postfix_string[i] == '5' || postfix_string[i] == '6' || postfix_string[i] == '7' || postfix_string[i] == '8' || postfix_string[i] == '9' || postfix_string[i] == '.')
			num += postfix_string[i];
		else if ((postfix_string[i] == ' ') && (postfix_string[i - 1] == '0' || postfix_string[i - 1] == '1' || postfix_string[i - 1] == '2' || postfix_string[i - 1] == '3' || postfix_string[i - 1] == '4' || postfix_string[i - 1] == '5' || postfix_string[i - 1] == '6' || postfix_string[i - 1] == '7' || postfix_string[i - 1] == '8' || postfix_string[i - 1] == '9')) {
			number = stod(num);
			calc.push(number);
			num = "\0";;
		}
		else if (postfix_string[i] == '+' || postfix_string[i] == '-' || postfix_string[i] == '*' || postfix_string[i] == '/' || postfix_string[i] == '^' || postfix_string[i] == 's' || postfix_string[i] == 'c' || postfix_string[i] == 'q' || postfix_string[i] == 'a' || postfix_string[i] == 't' || postfix_string[i] == 'g' || postfix_string[i] == 'l' || postfix_string[i] == 'n') {
			if (postfix_string[i] == '+') {
				var2 = calc.top();
				calc.pop();
				var1 = calc.top();
				calc.pop();
				var3 = var1 + var2;
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == '-') {
				var2 = calc.top();
				calc.pop();
				if (calc.empty()) {
					var3 = 0 - var2;
				}
				else {
					var1 = calc.top();
					calc.pop();
					var3 = var1 - var2;
				}
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == '*') {
				var2 = calc.top();
				calc.pop();
				var1 = calc.top();
				calc.pop();
				var3 = var1 * var2;
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == '/') {
				var2 = calc.top();
				calc.pop();
				var1 = calc.top();
				calc.pop();
				var3 = var1 / var2;
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == '^')
			{
				var2 = calc.top();
				calc.pop();
				var1 = calc.top();
				calc.pop();
				var3 = pow(var1, var2);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 's') {
				var1 = calc.top();
				calc.pop();
				var3 = sin(var1 * pi / 180);
				calc.push(var3);
				/*var3 = 0;*/
			}
			if (postfix_string[i] == 'c') {
				var1 = calc.top();
				calc.pop();
				var3 = cos(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'a') {
				var1 = calc.top();
				calc.pop();
				var3 = abs(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'q') {
				var1 = calc.top();
				calc.pop();
				var3 = sqrt(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 't') {
				var1 = calc.top();
				calc.pop();
				var3 = sin(var1) / cos(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'g') {
				var1 = calc.top();
				calc.pop();
				var3 = cos(var1) / sin(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'l') {
				var1 = calc.top();
				calc.pop();
				var3 = log10(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'n') {
				var1 = calc.top();
				calc.pop();
				var3 = log(var1);
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'e') {
				var3 = 2.718281;
				calc.push(var3);
				var3 = 0;
			}
			if (postfix_string[i] == 'p') {
				var3 = 3.14159265;
				calc.push(var3);
				var3 = 0;
			}
		}
	}
	cout << "Result = " << calc.top() << endl;

}


int main() {
	string stroka;
	double g;
	cout << "Input: " << endl;
	getline(cin, stroka, '=');
	string postfix_string;
	try {
		if (/*check_bracekts(stroka) &&*/ check_for_correct_input(stroka) /*&& chek_kol_(stroka)*/) {
			postfix_string = postfix(stroka); // convert to postfix
		}
	}
	catch (const invalid_argument error) {
		cout << error.what() << endl << endl;
	}
	change_functions(postfix_string);
	cout << "In postfix notaion: " << endl;
	cout << postfix_string << '\n';
	//cout << stroka << '\n';
	calculate(change_functions(postfix_string));
	
}
