#include <iostream>
#include <exception>
#include <utility>

class StoreException : public std::exception
        {
    char* message;
public:
    StoreException(){
        message = "some store error";
    }
    StoreException(char* in_message): message(std::move(in_message)){};

    const char* what ()const noexcept override
    {
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