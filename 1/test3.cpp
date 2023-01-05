// istream:: unget example
#include <iostream>
#include <string>

int main(){
    std::cout << "Please, enter a number or a word: ";
    char c = std::cin.get();
    std::cout << c << std::endl;
    if((c >= '0') && (c <= '9')){
        int n;
        std::cin.unget();
        std::cin >> n;
        std::cout << "You entered a number: " << n << std::endl;
    }
    else{
        std::string str;
        std::cin.unget();
        getline(std::cin, str);
        std::cout << "You entered a word: " << str << std::endl;
    }
}