#include <iostream>
#include <map>

class Cart {
    std::map <std::string, int> database;
public:

    Cart();
    Cart(int number_of_goods);
    Cart(const Cart& oth);
    void add (std::string vendor_code,int amount);
    void remove (std::string vendor_code,int amount);
    ~Cart();
};