#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::string output = "Success";

    std::stack <Bracket> opening_brackets_stack;

    bool check = true;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here

            // Push to stack
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                output  = std::to_string(position+1);
                break;
            }

            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();

            if ((top.type == '[' && next != ']') || (top.type == '(' && next != ')') || (top.type == '{' && next != '}')){
                output = std::to_string(position+1);
                check = false;
                break;
            }
        }
    }

    if (!opening_brackets_stack.empty() && check){
        output = std::to_string(opening_brackets_stack.top().position+1);
    }

    // Printing answer, write your code here

    std::cout << output << '\n';

    return 0;
}
