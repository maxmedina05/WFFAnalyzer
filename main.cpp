#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

bool isBalanced(string str);
bool isVariable(string str);
bool isConector(string str);
bool isWellFormedFormula(string str);

int main(){
	bool flag = false;
	string formula = "((A) && (~(B))) -> ((~(~(A))) <> (B))";

	if (isBalanced(formula)){
		if (isWellFormedFormula(formula)){
			cout << "Formula bien formulada" << endl;
		}
	}
	else
		cout << "Formula mal formulada" << endl;

	return 0;
}

bool isBalanced(string str){
	stack<char> stack;
	for (int i = 0; i < str.length(); i++){
		char ch = str[i];

		if (ch == '(' || ch == '[' || ch == '{')
			stack.push(ch);

		else if (ch == ')' || ch == ']' || ch == '}'){
			if (stack.top() == '(' && ch == ')')
				stack.pop();

			else if (stack.top() == '[' && ch == ']')
				stack.pop();

			else if (stack.top() == '{' && ch == '}')
				stack.pop();
			else
				return false;
		}
	}
	return (stack.size() == 0);
}

bool isVariable(string str)
{
	if (str.length() > 1 || str.length() == 0)
		return false;

	char ch = str[0];
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isConector(string str)
{
	if (str == "&&")
		return true;
	if (str == "||")
		return true;
	if (str == "->")
		return true;
	if (str == "<>")
		return true;

	return false;
}

bool isWellFormedFormula(string str)
{
	stringstream ss(str);
	bool flag = false;
	string word;
	while (ss >> word)
	{
		word.erase(remove(word.begin(), word.end(), '('), word.end());
		word.erase(remove(word.begin(), word.end(), ')'), word.end());
		word.erase(remove(word.begin(), word.end(), '~'), word.end());

		if (isVariable(word))
			flag = true;
		if (isConector(word))
			flag = false;
	}

	return flag;
}