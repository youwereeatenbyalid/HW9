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
    /* Constructor alt
    * assigns the initial 
    */
    Driver(Product array[],int size){

       productvector.assign  (array,array+size);
       clean(IDCompare);
       std::cout<<"Welcome to the Database.\n";
    }
    
    /* Menu
    * Provides the user with a series of options;
    * input products, retrieve products by id, retrieve products by price, 
    * remove all instances of a container with the product ID in question BAR ONE,
    * print a list of all products in order.
    */
    void menu(){
        while(true){
        /*
        * Prints the default list of options. Currently unsure how to make a better menu outside of chaining else ifs.
        */
        std::cout<<"Options:\n"
        << "Insert: Insert new records.\n"
        << "ID: Retrieve subset of records with a matching product ID.\n" 
        << "Price: Retrieve subset of records with a matching price.\n"
        << "Print: Print the current selection of records.\n"
        << "Erase: Remove all records in subset except one of your choosing.\n"
        << "Clean: Reset selection to full recordlist.\n"
        << "Quit: Exit the program.\n";
        
        //acquire user input.
        std::cin >> inputstring;
            //Insert command
            if(inputstring.compare("Insert")==0) Input();
            
            //ID command
            else if(inputstring.compare("ID")==0){
                //creates a temp ID and feeds it into the product to be searched for.
                //after that, it calls the retrieveId method.
                int tempID;
                std::cout << "Input product id.\n";
                std::cin >> tempID;
                searchProduct.setId(tempID);
                retrieve(IDCompare);
            }
        
            //Price command
            else if(inputstring.compare("Price")==0){
                //creates a temp price and feeds it into the product to be searched for.
                //after that, it calls the retrievePrice method.
                double tempprice;
                std::cout << "Input product price.\n";
                std::cin >> tempprice;
                searchProduct.setPrice(tempprice);
                retrieve(priceCompare);
            }
            
            //Print command
            else if(inputstring.compare("Print")==0){
                //calls print method.
                print();
            }
            
            //Clean command
            else if(inputstring.compare("Clean")==0){
                //calls clean method.
                clean(IDCompare);
            }
            
            //Erase command
            else if(inputstring.compare("Erase")==0){
                //calls erase method.    
                erase();
            } 
            
            //Quit
            else if(inputstring.compare("Quit")==0){
                //breaks menu and exits program
                break;
                
            //Error
            }else{
                //printed if command not recognized by above.
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
        bool valid = true;
        std::cout <<"Inserting new records. Type q to quit at any point.\n";
        while(true){
            inputstring = " ";
            num, price = 0;
            valid = true;
            
            std::cout << "Type product number.\n";
            std::cin >> inputstring;
            if(inputstring.compare("q")==0) break;
                try{
                    num = stoi(inputstring);
                }catch(std::invalid_argument){
                    valid = false;
                }
            std::cout << "Type product price.\n";
            std::cin >> inputstring;
            if(inputstring.compare("q")==0) break;
            try{
            price = stod(inputstring);
            }catch(std::invalid_argument){
                valid = false;
            }
            if(valid){
                productvector.push_back(*new Product(num,price));
            }else{
                std::cout << "Error. Please reenter record.\n";
            }

            
        }
        clean(IDCompare);
}
    /* retrieve
    * uses the std algorithms to sort the vector using a parameter of a boolean function built into product 
    * (ID or price compare), 
    * then find the range of Product ID's in the vector equal to the ID of the search Product 
    */
    void retrieve(bool (*comp)(const Product& p1, const Product& p2)){
        //calls clean method
        clean(comp);
        //uses the equal_range algorithm to return an iterator pair at the beginning and end of range of products with matching value.
        /*Equal range
         * Calls two binary search algorithms to aquire the high and low bounds of the vector where the value is less then or equal, 
         * and greater than respectively.
         * It then returns a vector pair of the two.
         */
        selection = std::equal_range(productvector.begin(),productvector.end(),searchProduct, *comp);
        //updates the selection size.
        selectionsize = std::distance(selection.first,selection.second);
        //outputs the number of records found.
        std::cout<< "Found "<<selectionsize<<" Records that matched the product id.\n";
    }
    

    /* erase
    * removes all products from the selection bar one.
    */
    void erase(){
        std::string subsetNumber;
        //checks to ensure that the entire vector isn't in range (don't want to delete the whole database probably)
        if(selection.first != productvector.begin() || selection.second != productvector.end()){
            //prints the values that match the selection so the user can know which values will be deleted.
            print();
            //requests record to keep and also a back out option in case erase was selected accidentally.
            std::cout<< "Input record # to keep. Type q to quit.\n";
            std::cin >> subsetNumber;
            if(subsetNumber.compare("q")!=0){
                //creates a copy of the product that the user wishes to keep
                Product backup = selection.first[stoi(subsetNumber)-1];
                //erases everything within the selection
                productvector.erase(selection.first,selection.second);
                //adds the the kept product back to the vector.
                productvector.push_back(backup);
                //calls the clean method.
                clean(IDCompare);
            }
        }else{
            std::cout <<"Warning, no subsection selected.";
        }

    }
    /*Clean
     * resets the selection to the beginning and end of the product vector,
     * Then sorts by by whatever function was selected.
     */
    void clean(bool (*comp)(const Product& p1, const Product& p2)){
        selection.first = productvector.begin();
        selection.second= productvector.end();
        sort(selection.first,selection.second,comp);
        selectionsize = std::distance(selection.first,selection.second);
    }
    
    /* print
    * prints a list of the products currently selected.
    */
    void print(){
        int i = 0;
        for(std::vector<Product>::iterator printer = selection.first;printer != selection.second;printer++){
            i++;
            std:: cout << "record #" << i << ": " <<*printer <<std::endl;
        }
    }
    

private:
    //string to hold user input
    std::string inputstring;
    //a search product used in the comparison algorithms, the ID/Price to search is assigned to the product
    //then the product is used as the value in the algorithms.
    Product searchProduct = Product(0,0);
    //the vector that holds the database.
    std::vector<Product> productvector;
    //a pair of iterators that point to the beginning and end of the selection.
    //they point to beginning and end of productvector if nothing is selected.
    std::pair<std::vector<Product>::iterator,std::vector<Product>::iterator> selection;
    //an integer to hold the current size of the selection.
    int selectionsize;
};

    int main() {
        Product initial[] = {Product(2,3.99),Product(1,2.99),Product(7,3.99),Product(2,4.99),Product(5,3.99),Product(9,9.99)};
        Driver myDriver(initial,6);
        myDriver.menu();
        return 0;
    }
