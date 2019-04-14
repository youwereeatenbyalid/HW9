#include <iostream>
#include <list>
#include "product.h"
class Driver{
public:
    /* Constructor
     * no work is done here
     */
    Driver(){}
    
    /* Menu
    /* Provides the user with a series of options;
     * input products, retrieve products by id, retrieve products by price, 
     * remove all instances of a container with the product ID in question BAR ONE,
     * print a list of all products in order.
     */
    void Menu(){}
    
    /* retrieve (ID)
     * return a pointer that points to an (array? Linked List?) of all products with an id
     * that match the parameter
     */
    Product* retrieve(int id){
        
    }
    
    /* retrieve (price)
     * return a pointer that points to an (array? Linked List?) of all products with a price
     * that match the parameter
     */
    Product* retrieve(double product){
        
    }
    /* clean
     * removes all products with matching ID's from the list bar one.
     */
    void clean(int id){}
    
    /* print
     * prints an ordered list of the products by ascending product ID
     */
    void print(){}
    

private:
    std::list<Product> productlist;
}

    int main() {
        std::cout << "Update a thing please!" << std::endl;
        Driver myDriver();
        myDriver.Menu();
        return 0;
    }
