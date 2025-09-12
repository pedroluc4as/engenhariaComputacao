#include <iostream>
#include <string>

using namespace std;

class Hotel 
{
private:
    string hotelGuest;
    int room;

public:
    //construtor
    Hotel(string hotelGuest, int room) : hotelGuest(std::move(hotelGuest)), room(std::move(room)){}

    //metodos
    //reservar quarto = bookRoom
    void bookRoom() {};
};

class HotelGuest {
private:
    string name, adress, CPF;
    int dateOfBirth;
    
public:
    HotelGuest(string name, string adress, string CPF, int dateOfBirth) : name(std::move(name)), adress(std::move(adress)), CPF(std::move(CPF)), dateOfBirth(std::move(dateOfBirth)){}

};