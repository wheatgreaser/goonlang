#include <iostream>
#include <vector>
#include <cctype>

enum TokenType
{
    Number,
    Identifier,
    Equals,
    OpenParen,
    CloseParen,
    BinaryOperator,
    Set
};

struct Token
{
    std::string value;
    TokenType type;
};

std::vector<std::string> splitString(const std::string &sourceCode)
{
    std::vector<std::string> words;
    std::string word;
    for (int i = 0; i < sourceCode.length(); i++)
    {
        if (sourceCode[i] != ' ')
        {
            word += sourceCode[i];
        }

        if (sourceCode[i] == ' ' || i == sourceCode.length() - 1)
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
    }
    return words;
}

std::vector<Token> tokenize(std::string &sourceCode)
{
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    for (const std::string &word : src)
    {
        if (std::isdigit(word[0]))
        {
            tokens.push_back({word, TokenType::Number});
        }
        else if (word == "=")
        {
            tokens.push_back({word, TokenType::Equals});
        }
        else if (word == "(")
        {
            tokens.push_back({word, TokenType::OpenParen});
        }
        else if (word == ")")
        {
            tokens.push_back({word, TokenType::CloseParen});
        }
        else if (word == "+" || word == "-" || word == "*" || word == "/")
        {
            tokens.push_back({word, TokenType::BinaryOperator});
        }
        else
        {
            tokens.push_back({word, TokenType::Identifier});
        }
    }

    return tokens;
}

void print_stuff(std::vector<Token> &tokens)
{
    for (const Token &token : tokens)
    {
        std::cout << "Token(Value: " << token.value << ", Type: " << token.type << ")\n";
    }
}

int main()
{
    std::string s;
    std::cout << "Enter your source code: ";
    std::getline(std::cin, s);
    std::vector<Token> tokens = tokenize(s);
    print_stuff(tokens);
    return 0;
}
