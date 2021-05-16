#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;


struct CMOS {
	string Mname, drain, gate, source, type;
};

// Assuming 2 input gates


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

vector<char> divideExpression(vector<string> eq)
{   
    for (int i=0; i<eq.size(); i++)
    {
        // INV GATE
        if (eq[i] ==  "`")
        {
            
        }

    }
    
}



void generateNetlist(vector<char> exp, vector<CMOS> types, string label)
{
    //vector<MOSFET> M;
    CMOS temp;
	CMOS temp2;
	

	vector<CMOS> output;

    int count = 0;

	
    
	for (int j=0; j<exp.size(); j++)
	{
		if (types[count].type == "PMOS")
			switch (exp[j])
			{
				// x = b`a`|c&
				case '`':
				temp.gate = exp[j-1];
				temp.source = "vdd";
				temp.drain = label;

				output.push_back(temp);
				break;

				case '&':
				//temp.gate 
				temp.source = "vdd";
				temp.drain = "1";
				temp.type = "PMOS";
				output.push_back(temp);
				
				//temp2.gate
				temp2.source = "1";
				temp2.drain = label;
				temp2.type = "PMOS";
				output.push_back(temp2);

				break;

				case '|':
				//temp.gate = 
				temp.source = "vdd";
				temp.drain = label;
				temp.type = "PMOS";
				output.push_back(temp);

				// temp2.gate = 
				temp2.source = "vdd";
				temp2.drain = label;
				temp2.type = "PMOS";
				output.push_back(temp2);




				default: count++;
		}
        
    }
}

int main() {

    // MOSFET M1("M", "D", "G", "S");
    // M1.printout();



    return 0;
}



