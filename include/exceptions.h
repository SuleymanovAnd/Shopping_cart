#include <iostream>
#include <exception>
#include <utility>

class StoreException{
    std::string message;
public:
    StoreException(){
        message = "some store error";
    }
    StoreException(std::string in_message): message(std::move(in_message)){};

    std::string what ()const noexcept{
        return message;
    }
};

bool overflow ( ){

    if (! std::cin){
        std::cout <<"Input Error. Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return true;
    } else {return false;}
}