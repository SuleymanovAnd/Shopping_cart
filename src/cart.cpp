#include "cart.h"
#include <exception>
#include "exceptions.h"

Cart::Cart (){
    std::cout << "Enter number of goods: ";
    int nGoods;
    std::cin >> nGoods;
        while (overflow()){std::cin >> nGoods;}

    for (; nGoods > 0; --nGoods){
        std::string vCode;
        int amount;
        std::cout << "Enter vendor code, amount: ";
        std::cin >> vCode >> amount;
        while (overflow()){std::cin >> amount;}
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

        try {
            if (database.at(vendor_code)) { // если найден товар в базе данных
                if (database[vendor_code] >= amount){ // если товара на базе больше запрошенного
                    if(cart.find(vendor_code) == cart.end()){ // если корзина пуста, то добавляем сразу
                    cart.emplace(vendor_code,amount);
                    } else if (cart[vendor_code] + amount > database[vendor_code]){ // иначе проверяем корзину
                        throw StoreException("It is not possible to increase the number of items in the cart.\n Not enough stock in the store.");
                    }else { // если все хорошо добавляем к имеющимся
                        cart[vendor_code] += amount;
                    }
                }else { // если товара на складе не достаточно
                    throw StoreException("Not enough stock in the store");
                }
            }
        }

    catch(const std::out_of_range & x){
        std::cerr <<"\""<< vendor_code << "\" no matching item in store";
    }
    catch(const StoreException & x){
        std::cerr<< x.what();
    }
}


void Cart::remove(std::string vendor_code, int amount) {
    try {
        if (cart.at(vendor_code)){
            if(cart[vendor_code] - amount < 0){
                throw StoreException ("There are fewer items in the cart, than you want to remove");
            }
            else {
                cart[vendor_code] = amount;
            }
        }
    }
    catch (const std::out_of_range& x){
        std::cerr << "\""<< vendor_code << "\" no matching item in cart";
    }
    catch(const StoreException & x){
        std::cerr<< x.what();
    }
}

Cart::~Cart() = default;