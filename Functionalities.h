#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H


#include <iostream>
#include <memory>
#include <vector>
#include <variant>
#include "EvCar.h"
#include "ICECar.h"
#include "futureException.h"

using EvCarPtr = std::shared_ptr<EvCar>;
using ICEPtr = std::shared_ptr<ICECar>;

using Combined = std::variant<EvCarPtr, ICEPtr>;

using Container = std::vector<Combined>;

void CreateObjects(Container &data);

void VehiclePrices(Container &data);

float DisplayAveragePricePrivate(Container &data);

std::string FindAndReturnBrandName(Container &data, std::string ids);

bool CheckPricesAbove60K(Container &data);

std::vector<batterytype> CheckingBatteryType(Container &data);


#endif // FUNCTIONALITIES_H
