#include<iostream>
class Product{
public:
    /* Constructor function
     * Creates a product instance from an int and a double. 
     * The int is assigned to the id, and the double is assigned to the product.
     */
    Product(int id, double price);
    /* getId
     * retrieves the product id and returns it as an integer.
     */
    int getId() const;
    /* setId
     * takes an integer as a parameter and sets the id variable to that value.
     */
    void setId(int id);
    /* getPrice
     * retrieves the product price and returns it as an double.
     */
    double getPrice() const;
    /* setPrice
     * takes an double as a parameter and sets the price variable to that value.
     */
    void setPrice(double price);
    /* extractor
     * a friend function that returns a label with the id and the price separated by a comma
     */
    friend std::ostream & operator<<(std::ostream & out, const Product &p);
private:
    int id;
    double price;
};
/* ==
 * nonmember function that compares two products
 * returns a boolean result based on whether their id's are the same
 */
bool operator==(const Product & p1, const Product &p2);

/* <
 * nonmember function that compares two products
 * returns a boolean result based on whether the first id is less then the second id
 */
bool operator<(const Product & p1, const Product &p2);

/*
 * Two different boolean functions used to determine criteria in the sort algorithms
 */
bool priceCompare(const Product & p1, const Product &p2);
bool IDCompare(const Product& p1, const Product& p2);
/* >
 * nonmember function that compares two products
 * returns a boolean result based on whether the first id is greater then the second id
 */
bool operator>(const Product & p1, const Product &p2);
