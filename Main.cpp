#include "Functionalities.h"
#include <thread>

int main()
{
    Container data;
    CreateObjects(data);
    std::thread t1(&VehiclePrices, std::ref(data));
    t1.join();

    float ans = DisplayAveragePricePrivate(data);
    std::cout << ans << std::endl;

    std::future<std::string> f1 = std::async(&FindAndReturnBrandName, std::ref(data), "200A");
    std::cout << f1.get() << std::endl;

    std::vector<batterytype> ans2 = CheckingBatteryType(data);
    for (batterytype ptr : ans2)
    {
        std::cout << static_cast<int>(ptr) << std::endl;
    }
    std::future<bool> f2 = std::async(&CheckPricesAbove60K, std::ref(data));
    std::cout << std::boolalpha << f2.get() << std::endl;
}