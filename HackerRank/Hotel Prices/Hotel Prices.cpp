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

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
    
    private:
    int bedrooms_;
    int bathrooms_;
    
    
   public:
    HotelRoom(int bedrooms, int bathrooms) 
    {
        bedrooms_ = (bedrooms); 
        bathrooms_ = (bathrooms) ;
    
    }
    
    int get_price() 
    {
       int room_price = 50*bedrooms_ + 100*bathrooms_ ;
       
       return room_price;
    }

};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms + 2, bathrooms) {}

    int get_price() {
        int hotel_price =  ( HotelRoom::get_price());
        return hotel_price ;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}