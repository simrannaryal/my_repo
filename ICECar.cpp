#include "ICECar.h"
std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    std::string TYPE;
    if(rhs._engine_type == EngineType::DIESEL){
        TYPE = "DIESEL";
    }
     if(rhs._engine_type == EngineType::PETROL){
        TYPE = "PETROL";
    }
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: " << TYPE;
    return os;
}

ICECar::ICECar(std::string id, std::string brand_name, float price, EngineType engine_type)
: _id{id}, _brand_name{brand_name}, _price{price}, _engine_type{engine_type}
{
}