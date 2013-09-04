#include "LLStack.h"
#include <iostream>

int main(int argc, char *argv[])
{
	int out;
	LLStack<int> stack;
	std::cout << "Stack empty: " << stack.isEmpty() <<"\n";
	stack.push(3);
	stack.pop(out);
	std::cout << "popped element: " << out << "\n";
	stack.push(6);
	std::cout << "Stack empty: " << stack.isEmpty() <<"\n";
	stack.clear();
	std::cout << "Stack empty: " << stack.isEmpty() <<"\n";
	stack.push(14);
	stack.pop(out);
	std::cout << "popped element: " << out << "\n";
	stack.push(9);
	stack.push(24);
	stack.peek(out);
	std::cout << "top element: " << out << "\n";
	stack.print();

	system("PAUSE");
}
