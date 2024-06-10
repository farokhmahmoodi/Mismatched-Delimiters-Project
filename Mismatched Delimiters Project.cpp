/*Write a program that reads in a stream of text and tests for mismatched delimiters.

First, you will create a stack class that stores, in each node, a character (char), a line number (int) and a 
character count (int). This can either be based on a dynamic stack or a static stack from the book, modified 
according to these requirements. I suggest using a stack of structs that have the char, line number and 
character count as members, but you can do this separately if you wish. Second, your program should start 
reading in lines of text from the user. This reading in of lines of text (using getline) should only end when 
it receives the line “DONE”. While the text is being read, you will use this stack to test for matching “blocks”. 
That is, the text coming in will have the delimiters to bracket information into blocks, the braces {}, 
parentheses (), and brackets [ ].

A string is properly delimited if each right delimiter is matched with a preceding left delimiter of the 
same type in such a way that either the resulting blocks of information are disjoint, or one of them is 
completely nested in the other. Write a program that uses your stack to check whether the entered 
text containing the blocks is properly delimited.

Implementation:

All while accepting input, keep track of how many lines you have received already. To do the test, as you 
receive a line of text, start processing each line. To process each line, you have a few cases to deal with: 

Ignore all non-delimiters.
If you receive a left delimiter,{([, push it onto the stack along with the line number and character in 
that line that the delimiter was found.If you receive a right delimiter, ]}), pop the top of the stack and 
compare the characters. If the left matches with a right delimiter, then that is fine and continue processing. 
If they DO NOT MATCH, that is a problem, so output an error message showing the mismatch like the following:

Mismatched delimiter ( found at line 3, char 27 does not match } found at line 7, char 9
If your stack is ever empty when you need to pop, output an error message like the following:
Right delimiter } had no left delimiter found at line 27, char 23
If you reach the end of input and the stack is not empty, output the contest of the stack similarly as follows:
Left delimiter [ at line 10, char 25 had no right delimiter.
Left delimiter [ at line 7, char 3 had no right delimiter.
Left delimiter { at line 3, char 20 had no right delimiter.*/

#include<iostream>
#include <string>
using namespace std;

class DelimiterStack {
private:
	struct DelimiterNode {
		char character;
		int lineNumber;
		int charCount;
		DelimiterNode* next;
		//Constructor
		DelimiterNode(char ch, int lineNum, int chCount, DelimiterNode* next1 = NULL)
		{
			character = ch;
			lineNumber = lineNum;
			charCount = chCount;
			next = next1;
		}
	};
	// Define stack top
	DelimiterNode* top;
public:
	//Constructor
	DelimiterStack() { top = nullptr; }
	//Destructor
	~DelimiterStack();
	//Stack Operations
	void push(char, int, int);
	// reference variables because three variables cannot be returned through return statement
	void popDelimiter(char&, int&, int&); 
	bool isEmpty() const;
	//Stack Exception
	class Underflow {};
};

void DelimiterStack::push(char ch, int lineNum, int chCount)
{
	try
	{
		top = new DelimiterNode(ch, lineNum, chCount, top);
	}
	catch (bad_alloc& ba)
	{
		cout << "Memory allocation error: " << ba.what() << endl;
		exit(1);
	}
}

void DelimiterStack::popDelimiter(char& ch, int& lineNum, int& chCount)
{
	DelimiterNode* temp;

	if (isEmpty()) { throw DelimiterStack::Underflow(); }
	else
	{
		ch = top->character;
		lineNum = top->lineNumber;
		chCount = top->charCount;
		temp = top;
		top = top->next;
		delete temp;
	}
}

bool DelimiterStack::isEmpty() const
{
	return top == nullptr;
}

DelimiterStack::~DelimiterStack()
{
	DelimiterNode* garbage = top;
	while (garbage != nullptr)
	{
		top = top->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = top;
	}
}

int main()
{
	// variable declarations and initializations

	DelimiterStack mydelistack;

	string currentLine = "";
	//do 
	//{
		// parse the input line ignore non delimiters

		// if an opening delimiter, push

		// if a closing delimiter, pop 

		// check if any error needs to be thrown

		// rest of your logic

	//} while (currentLine is not equal to "DONE");

	// rest of the logic

	return 0;
}

