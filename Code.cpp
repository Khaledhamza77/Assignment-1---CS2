#include<iostream>
#include<string>
using namespace std;

class Car
{
private:
    string Car_Brand;
    string Car_type;
    string Car_Plate;
    int speed;
    int Year_model;
public:
    Car(){}
    Car(string Car_Br,int Max_Sp, int Year_Mod){
        Car_Brand=Car_Br;speed=Max_Sp;Year_model=Year_Mod;
    }
    void set_Brand(string Brand){Car_Brand=Brand;}
    void set_Type(string Type){Car_type=Type;}
    void set_Plate(string Plate){Car_Plate=Plate;}
    void set_Model(int model){Year_model=model;}
    void set_speed(int sp){speed=sp;}
    int get_speed(){return speed;}
    string get_Brand(){return Car_Brand;}
    string get_type(){return Car_type;}
    string get_Plate(){return Car_Plate;}
};

class Road{
private:
    char Road_Type;
    int Speed_Limit;
public:
    Road(){}
    Road(char Road_ty,int speed,int year_model){
        Road_Type=Road_ty;Speed_Limit=speed;
    }
    bool radar(int car_speed){
        if(car_speed>=100) return true;
        else return false;
    }
    void allow(string car_type){
        
    }
};

int main(){

    return 0;
}