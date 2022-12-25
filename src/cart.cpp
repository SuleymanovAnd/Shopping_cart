#include "cart.h"

Cart::Cart (){
    std::cout << "Enter number of goods: ";
    int nGoods;
    std::cin >> nGoods;
    for (; nGoods > 0; --nGoods){
        std::string vCode;
        int amount;
        std::cout << "Enter vendor code, amount: ";
        std::cin >> vCode >> amount;
        database.emplace(vCode,amount);
    }
};
Cart::Cart(int number_of_goods){

    for (int nGoods = number_of_goods; nGoods > 0; --nGoods){
        std::string vCode;
        int amount;
        std::cout << "Enter vendor code, amount: ";
        std::cin >> vCode >> amount;
        database.emplace(vCode,amount);
    }

}
Cart::Cart(const Cart& oth) {
    database = oth.database;
}

void Cart::add(const std::string vendor_code, int amount) {

}

void Cart::remove(std::string vendor_code, int amount) {

}

Cart::~Cart() = default;