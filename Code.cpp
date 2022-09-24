#include<iostream>
#include<string>
#include<queue>
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
    Car();
    Car(string Car_Br,int Sp, int Year_Mod){
        Car_Brand=Car_Br;speed=Sp;Year_model=Year_Mod;
    }
    void set_Brand(string Brand){Car_Brand=Brand;}
    void set_Type(string Type){Car_type=Type;}
    void set_Plate(string Plate){Car_Plate=Plate;}
    void set_Model(int model){Year_model=model;}
    void set_speed(int sp){speed=sp;}
    int get_speed(){return speed;}
    int get_model(){return Year_model;}
    string get_Brand(){return Car_Brand;}
    string get_type(){return Car_type;}
    string get_Plate(){return Car_Plate;}
};

class Road
{
private:
    char Road_Type;
    int Speed_Limit;
    int countA=0; int countB=0; int countC=0;
public:
    Road();
    Road(char Road_ty,int speed){
        set_Type(Road_ty);Speed_Limit=speed;
    }
    void set_Type(char type){
        if(type != 'A' && type != 'B' && type != 'C')
            cout<<"Please enter A or B or C\n";
        else Road_Type=type;
    }
    char get_Type(){return Road_Type;}
    void set_Limit(int lim){Speed_Limit=lim;}
    int get_Limit(){return Speed_Limit;}
    int get_countA(){return countA;}
    int get_countB(){return countB;}
    int get_countC(){return countC;}
    bool radar(int car_speed, char Road_Type){
       if(car_speed>Speed_Limit) return true;
       else return false;
    }
    void allow(string car_type){
        if(Road_Type='A'){
            if(car_type == "private" || car_type == "motorcycle"){countA++;countB++;}}
        else if(Road_Type='C'){
            if(car_type == "truck"){countC++;countB++;}}
        else countB++;
    }
    int age(int Year_Model){return 2022-Year_Model;}
};

void check(Car car,Road R,bool x){
    if(x){
        cout<<"This car will be fined on Road of type: "<<R.get_Type()<<"\n";
        cout<<"Brand: "<<car.get_Brand()<<"\n";
        cout<<"Type: "<<car.get_type()<<"\n";
        cout<<"Plate: "<<car.get_Plate()<<"\n";
        cout<<"Speed: "<<car.get_speed()<<"\n";
        cout<<"Year model: "<<car.get_model()<<"\n";
    }
}

int main(){
    Road R('A',120);
    Road R2('B',90);
    Road R3('C',200);
    int i=1;
    Car car1("Mercedes",70,2019);
    car1.set_Type("private");
    car1.set_Plate("ABC123");
    Car car2("Opel",120,2005);
    car2.set_Type("taxi");
    car2.set_Plate("DCF334");
    Car car3("Sacania",90,2017);
    car3.set_Type("truck");
    car3.set_Plate("BNA987");
    Car car4("Honda",60,2009);
    car4.set_Type("motorcycle");
    car4.set_Plate("HGV610");
    Car car5("Hyundai",140,2020);
    car5.set_Type("private");
    car5.set_Plate("MCX234");
    Car car6("BMW",80,2021);
    car6.set_Type("motorcycle");
    car6.set_Plate("MAD591");
    Car car7("Ford",46,2010);
    car7.set_Type("truck");
    car7.set_Plate("CXZ009");
    Car car8("Toyota",220,2003);
    car8.set_Type("taxi");
    car8.set_Plate("SAR222");
    Car car9("Toyota",160,2006);
    car9.set_Type("bus");
    car9.set_Plate("HOI567");

    queue<Car> vehicles;
    vehicles.push(car1);
    vehicles.push(car2);
    vehicles.push(car3);
    vehicles.push(car4);
    vehicles.push(car5);
    vehicles.push(car6);
    vehicles.push(car7);
    vehicles.push(car8);
    vehicles.push(car9);

    while(!vehicles.empty()){
        R.allow(vehicles.front().get_type());
        R2.allow(vehicles.front().get_type());
        R3.allow(vehicles.front().get_type());
        check(vehicles.front(),R,R.radar(vehicles.front().get_speed(),R.get_Type()));
        check(vehicles.front(),R2,R2.radar(vehicles.front().get_speed(),R2.get_Type()));
        check(vehicles.front(),R3,R3.radar(vehicles.front().get_speed(),R3.get_Type()));
    }

    vehicles.push(car1);
    vehicles.push(car2);
    vehicles.push(car3);
    vehicles.push(car4);
    vehicles.push(car5);
    vehicles.push(car6);
    vehicles.push(car7);
    vehicles.push(car8);
    vehicles.push(car9);

    while(!vehicles.empty()){
        cout<<"Age of car number "<<i<<" is: "<<R.age(vehicles.front().get_model())<<"\n";
        vehicles.pop();
        i++;}

    return 0;
}