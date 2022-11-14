#include <iostream>

// namespace std;

void main(void){
    std::string answer;


    std::cout << "あなたの名前は？" << std::endl;
    std::cin >> answer;
    std::cout << "こんにちは、" << answer;
}