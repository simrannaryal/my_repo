#include <future>
#include <cstring>

class Main : std::future_error
{
private:
char* _msg;
    
public:
    explicit Main(const char* msg, std::future_errc ec)
    :std::future_error(ec){
    _msg = new char[strlen(msg) + 1];
    strcpy(_msg, msg);
    }
    Main() = delete; // Default constructor
    Main(const Main&) = delete; // Copy constructor
    Main& operator=(const Main&) = delete; // Copy assignment operator
    Main(Main&&) = delete; // Move constructor
    Main& operator=(Main&&) = delete; // Move assignment operator
    ~Main() { delete _msg; } // Destructor
    std::string what() { return _msg; }
};