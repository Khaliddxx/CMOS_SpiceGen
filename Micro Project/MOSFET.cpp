#include "MOSFET.h"
#include <sstream>
#include <iostream>

using namespace std;


// init
MOSFET::MOSFET(string Mname, string drain, string gate, string source)
{
    _Mname = Mname;
    _drain = drain;
    _gate = gate;
    _source = source;
}

//string MOSFET::calculate(string input)
// {

// // loop on characters
    
//     // spaces not allowed => error handling
    
//     // paranthesis not allowed (except with bonus)
    
//     // single output symbol (except in bonus)
    
//     // always vdd NET representing positive terminal of DC
// }

bool check_priority(char& operator1, char& operator2)
{
	bool priority_bool = false;

	if ((operator1 == '`' && operator2 == '&') ||
		(operator1 == '`' && operator2 == '|') ||
		(operator1 == '&' && operator2 == '|'))
		priority_bool = true;

	return priority_bool;
}

vector <string> calculate_priority(string& input_exp)
{
	vector <string> string_vec;
	vector <string> last_vec;
	string current_str, expression;
	char topchar;
	std::stack<char> stack;
	stringstream ss(input_exp);

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ';');
		string_vec.push_back(substr);
	}

	for (int i = 0; i < string_vec.size(); i++)
	{
		current_str = string_vec[i];
		for (int i = 0; i < current_str.length(); i++)
		{
			if (current_str[i] == '`' || current_str[i] == '&' || current_str[i] == '|')
			{
				if (!stack.empty())
					topchar = stack.top();
				while (!stack.empty() && check_priority(topchar, current_str[i]))
				{
					topchar = stack.top();
					stack.pop();
					expression += topchar;
					if (!stack.empty())
						topchar = stack.top();
				}
				stack.push(current_str[i]);
			}

			else if (current_str[i] == '(')
				stack.push(current_str[i]);

			else if (current_str[i] == ')' && !stack.empty())
			{
				topchar = stack.top();
				stack.pop();
				while (!stack.empty() && topchar != '(')
				{
					expression += topchar;
					topchar = stack.top();
					stack.pop();
				}
			}
			else
				expression += current_str[i];
		}

		while (!stack.empty())
		{
			topchar = stack.top();
			stack.pop();
			expression += topchar;
		}
		last_vec.push_back(expression);
		expression = "";
	}
	return last_vec;
}


void MOSFET::printout()
{
    cout << _Mname << _drain << _gate << _source << endl;
}
