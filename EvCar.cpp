#include "EvCar.h"
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    std::string type;
    if(rhs._engine_type == EPowerType::ELECTRIC){
        type = "ELECTRIC";
    }
    if(rhs._engine_type == EPowerType::HYBRID){
        type = "HYBRID";
    }

    std::string type2;
    if(rhs._battery_type == batterytype::LION){
        type2 = "LION";
    }
    if(rhs._battery_type == batterytype::NICAD){
        type2 = "NICAD";
    }
    if(rhs._battery_type == batterytype::OTHER){
        type2 = "OTHER";
    }
    os << "id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: " << type
       << " _battery_type: " << type2;
    return os;
}

EvCar::EvCar(std::string id, std::string brand_name, float price, EPowerType engine_type, batterytype battery_type)
:_id{id}, _brand_name{brand_name}, _price{price},_engine_type{engine_type},_battery_type{battery_type}
{
}