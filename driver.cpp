#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "product.h"
#include <iterator>

class Driver{
public:
    /* Constructor
     * no work is done here
     */
    Driver(){
        std::cout<<"Welcome to the Database.\n";
    }
    
    /* Menu
     * Provides the user with a series of options;
     * input products, retrieve products by id, retrieve products by price, 
     * remove all instances of a container with the product ID in question BAR ONE,
     * print a list of all products in order.
     */
    void menu(){
        while(inputstring.compare("Quit")!=0){
        std::cout<<"Options:\n"
        << "Insert: Insert new records.\n"
        << "ID: Retrieve subset of records with a matching product ID.\n" 
        << "Price: Retrieve subset of records with a matching price.\n"
        << "Print: Print the current selection of records.\n"
        << "Erase: Remove all records in subset except one of your choosing.\n"
        << "Clean: Reset selection to full recordlist.\n"
        << "Quit: Exit the program.\n";
        std::cin >> inputstring;
            if(inputstring.compare("Insert")==0) Input();
            else if(inputstring.compare("ID")==0){
                int tempID;
                std::cout << "Input product id.\n";
                std::cin >> tempID;
                retrieve(tempID);
            }else if(inputstring.compare("Price")==0){
                double tempprice;
                std::cout << "Input product price.\n";
                std::cin >> tempprice;
                retrieve(tempprice);
            }else if(inputstring.compare("Print")==0){
                if(!subset.empty()) print(subset);
                else print(productvector);
            }else if(inputstring.compare("Erase")==0){
                    erase();
            }else{
                std::cout<<"Did not understand command.";
            }
        }
    }
    /* Input
     * a looping that allows a series of products to be created and added to the product vector.
     * can be exited out of to return to main menu, sorting the vector in the process.
     */
    void Input(){
        int num;
        double price;
        std::cout <<"Inserting new records. Type q to quit at any point.\n";
        while(inputstring.compare("q")!=0){
            std::cout << "Type product number.\n";
            std::cin >> inputstring;
            num = stoi(inputstring);
            std::cout << "Type product price.\n";
            std::cin >> inputstring;
            price = stod(inputstring);
            productvector.push_back(*new Product(num,price));
            num, price = 0;
            inputstring = " ";
        }
        vectorsize = productvector.size();
        
   }
    /* retrieve (ID)
     * return a pointer that points to an (array? Linked List?) of all products with an id
     * that match the parameter
     */
    void retrieve(int id){
        clean();
        sort(productvector.begin(),productvector.end());
        *top = std::lower_bound(productvector.back(),productvector.front(),id);
        *bottom = std::upper_bound(productvector.back(),productvector.front(),id);
         copy(top, bottom, subset);
        std::cout<< "Found" << subset.size() << "Records that matched the product id.\n";
    }
    
    /* retrieve (price)
     * return a pointer that points to an (array? Linked List?) of all products with a price
     * that match the parameter
     */
    void retrieve(double price){
        clean();
        sort(productvector.begin(),productvector.end(),priceCompare);
        *top = std::lower_bound(productvector.back(),productvector.front(),price);
        *bottom = std::upper_bound(productvector.back(),productvector.front(),price);
         copy(top, bottom, subset);
        std::cout<< "Found" << subset.size() << "Records that matched the price.\n";
    }
    /* erase
     * removes all products with matching ID's from the list bar one.
     */
    void erase(){
        std::string subsetNumber;
        if(!subset.empty()){
            print(subset);
            std::cout<< "Input record # to keep. Type q to quit.\n";
            std::cin >> subsetNumber;
            if(subsetNumber.compare("q")!=0){
            Product backup = subset[stoi(subsetNumber)];
            productvector.erase(top,bottom);
            productvector.push_back(backup);
            clean();
            }
        }else{
            std::cout <<"Warning, no subsection selected.";
        }

    }
    void clean(){
        subset.clear();
        top = productvector.begin();
        bottom = productvector.end();
    }
    
    /* print
     * prints an ordered list of the products by ascending product ID
     */
    void print(std::vector<Product> printvector){
        int i = 0;
        for(std::vector<Product>::iterator printer = printvector.begin();printer != printvector.end();printer++){
            i++;
            std:: cout << "record #" << i << ": " <<*printer;
        }
    }
    

private:
    std::string inputstring;
    std::vector<Product> productvector,subset;
    std::vector<Product>::iterator top, bottom;
    int vectorsize;
};

    int main() {
        std::cout << "Update a thing please!" << std::endl;
        Driver myDriver;
        myDriver.Menu();
        return 0;
    }
