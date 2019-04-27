#include "product.h"
Product::Product(int id, double price):id(id),price(price){}
int Product::getId() const
{
    return id;
}
double Product::getPrice() const
{
    return price;
}
void Product::setId(int id)
{
this->id = id;
}
void  Product::setPrice(double price)
{
this->price = price;
}


bool operator>(const Product& p1, const Product& p2)
{
    return p1.getId() > p2.getId();
}
bool operator==(const Product& p1, const Product& p2)
{
    return p1.getId() == p2.getId();
}

bool operator<(const Product& p1, const Product& p2)
{
    return p1.getId() < p2.getId();
}


bool priceCompare(const Product& p1, const Product& p2)
{
    return p1.getPrice()< p2.getPrice();
}
bool IDCompare(const Product& p1, const Product& p2)
{
    return p1.getId()< p2.getId();
}


std::ostream & operator<<(std::ostream & out, const Product &p){
    out<<"Product # "<< p.getId() << " has a price of $" << p.getPrice();
    return out;
}

