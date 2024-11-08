#include "RPN.hpp"

RPN::RPN()
{
    //std::cout << "RPN constructor" << std::endl;
}

RPN::RPN(RPN const &src)
{
    //std::cout << "RPN copy constructor" << std::endl;
    *this = src;
}

RPN::~RPN()
{
    //std::cout << "RPN destructor" << std::endl;
}

RPN &RPN::operator=(RPN const &src)
{
    //std::cout << "RPN assignation operator" << std::endl;
    if (this != &src)
    {
        *this = src;
    }
    return *this;
}

void printStack(std::stack<int> stack) {
    // Создаем копию стека, чтобы не изменять оригинал
    std::cout << "printStack" << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top(); // Печатаем верхний элемент
        stack.pop(); // Удаляем верхний элемент
    }
    std::cout << std::endl;
}

static int check_input(std::string input)
{
    if (input.size() < 3)
    {
        std::cerr << "Error: input is too small" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && !isdigit(input[i]))
        {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || isdigit(input[i])) && (input[i+1] != ' ' && input[i+1] != '\0'))
        {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
    }
    return 0;
}

void RPN::calculate(std::string input)
{
    if (check_input(input))
        return;
    //std::cout << "RPN calculate" << std::endl;
    std::stack<int> stack;
    std::stringstream ss(input); //Создается объект stringstream с именем ss, который инициализируется входной строкой input. Это позволяет разбивать строку на отдельные токены (числа и операторы).
    std::string token;
    while (ss >> token) //Цикл while продолжает выполняться, пока из ss можно извлекать токены. Каждый токен будет помещен в переменную token.
    {
        //printStack(stack);
        //std::cout << "token: " << token << std::endl;
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: not enough operands" << std::endl;
                return;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(b + a);
            else if (token == "-")
                stack.push(b - a);
            else if (token == "*")
                stack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    return;
                }
                stack.push(b / a);
            }
                
        }
        else
        {
            int i = std::atoi(token.c_str());
            stack.push(i);
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: too many operands" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}

