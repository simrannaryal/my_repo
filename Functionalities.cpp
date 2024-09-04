#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<EvCar>("200A", "TATA", 3440.0, EPowerType::ELECTRIC, batterytype::LION));
    data.push_back(std::make_shared<EvCar>("201A", "NMA", 344670.0, EPowerType::HYBRID, batterytype::NICAD));
    data.push_back(std::make_shared<EvCar>("202A", "YUTA", 77440.0, EPowerType::ELECTRIC, batterytype::OTHER));

    data.push_back(std::make_shared<ICECar>("300A", "BMW", 4550.0, EngineType::DIESEL));
    data.push_back(std::make_shared<ICECar>("301A", "BOM", 56550.0, EngineType::PETROL));
    data.push_back(std::make_shared<ICECar>("302A", "BYU", 7850.0, EngineType::DIESEL));
}

void VehiclePrices(Container &data)
{
    std::cout << "displaying prices:" << std::endl;
    for (Combined ptr : data)
    {
        std::visit(
            [](auto &&val)
            {
                std::cout << val->price() << std::endl;
            },
            ptr);
    }
}

float DisplayAveragePricePrivate(Container &data)
{
    std::cout<<"Average of prices are:"<<std::endl;
    int count = 0;
    float total = 0.0f;
    for (Combined ptr : data)
    {
        std::visit(
            [&](auto &&val)
            {
                total += val->price();
                count++;
            },
            ptr);
    }

    return total / count;
}

std::vector<batterytype> CheckingBatteryType(Container &data)
{
    std::cout<<"Checking Battery type:"<<std::endl;
    std::vector<batterytype> ans;
    for (Combined ptr : data)
    {
        if (std::holds_alternative<EvCarPtr>(ptr))
        {
            EvCarPtr i = std::get<0>(ptr);
            ans.push_back(i->batteryType());
        }
    }
    return ans;
}

std::string FindAndReturnBrandName(Container &data, std::string ids)
{
    std::cout<<"Returning the Brand Name with Matching Id"<<std::endl;
    std::string res;
    for (Combined ptr : data)
    {
        std::visit(
            [&](auto &&val)
            {
                if(val->id() == ids)
               res = val->brandName();
            },
            ptr);
    }
return res;
}

bool CheckPricesAbove60K(Container &data)
{
    bool flag{false};
    std::cout << "Checking if all prices are same or not:" << std::endl;
    for (Combined ptr : data)
    {
        std::visit(
            [&](auto &&val)
            {
                if(val->price()<6000)
                {
                  flag = true;
                }

            },
            ptr);
    }
return false;
}




