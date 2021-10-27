/**
 * @file "Hotel Prices.cpp"
 * @author Vipul Kumar Singh 
 * @brief  (https://www.hackerrank.com/challenges/hotel-prices/problem)
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> // header files 
#include <vector>

using namespace std;

class HotelRoom {
    
    private: 
    /* 
     access specifier : private 
     it means that the variables declared in this access specifier private cannot be accessed 
     by the other class data members and functions

    */ 
    int bedrooms_; // for the no. of bedrooms in class hotelroom
    int bathrooms_; // for the no. of bathrooms in class hotelroom
    
    
   public:
    HotelRoom(int bedrooms, int bathrooms)  // parameterized constructor for the assign some values to the variables 
    {
        bedrooms_ = (bedrooms); 
        bathrooms_ = (bathrooms) ;
    
    }
    
    int get_price() // the function is used to calculate the price of the hotel 
    {
       int room_price = 50*bedrooms_ + 100*bathrooms_ ;
       
       return room_price;
    }

};


/*
Creating new class called Hotel Apartment which inheriting from the base class HotelRoom  
*/
class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms + 2, bathrooms) {}

    int get_price() 
    {
        int hotel_price =  ( HotelRoom::get_price()); // using the base class function called get_price() and storing them in hotel_price variable  
        return hotel_price ;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) 
    {
        string room_type;
        int bedrooms;
        int bathrooms;
        
        cin >> room_type >> bedrooms >> bathrooms;

        if (room_type == "standard") 
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms)); 
            /*
             dynamic memory allocation using new to create new object of HotelRoom class and
             also call the parameterized constructor and 
             the data is stored in vector rooms 
            */
        } 
        
        else 
        {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
             /*
             dynamic memory allocation using new to create new object of HotelApartment class and
             also call the parameterized constructor and 
             the data is stored in vector rooms 
            */
        }
    }

    int total_profit = 0;

    for (auto room : rooms) 
    {
        total_profit += room->get_price();
    }
    
    cout << total_profit << endl;

    //deletion of objects that created by new operator for optimum performance 

    for (auto room : rooms) 
    {
        delete room;
    }

    rooms.clear(); // eraseing the data from vector and size became 0 

    return 0;
}