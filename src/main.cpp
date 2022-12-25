#include <iostream>
#include "cart.h"

int main() {

    Cart* ShopCart = new Cart ();
    ShopCart->add("toy1",2);
    ShopCart->add("toy1",9);
    // ShopCart->add("toy2",3);
    // ShopCart->remove("toy1",15);
    ShopCart->remove("toy2",15);
}
