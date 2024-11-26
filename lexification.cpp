#include <iostream>
#include <vector>

enum TokenType
{
    Number,
    Identifier,
    Equals,
    OpenParen,
    CloseParen,
    BinaryOperator,
    Set,
};


struct Token
{
    std::string value;
    TokenType type;
};


std::vector<std::string> splitString(const std::string &sourceCode){
    std::vector<std::string> words;
    std::string word;
    for (int i = 0; i < sourceCode.length(); i++){
        if (sourceCode[i] != ' '){
            word = word + sourceCode[i];
        }
        
        if (sourceCode[i] == ' ' || i == sourceCode.length() - 1) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    return words;
}

std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    for (int i = 0; i < src.size(); i++){
        std::cout << src[i] << " ";
    }
    return tokens;
}




int main(){
    std::cout << "wassgood cuh" << " ";
    return 0;
}
