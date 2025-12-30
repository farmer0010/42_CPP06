#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.name = "Chulsoo";
    myData.age = 42;
    myData.height = 180;

    std::cout << "Original Data Addr: " << &myData << std::endl;
    std::cout << "Data Contents: " << myData.name << ", " << myData.age << std::endl;

    std::cout << "------------------------------------" << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    std::cout << "------------------------------------" << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Addr: " << ptr << std::endl;

    std::cout << "------------------------------------" << std::endl;

    if (ptr == &myData)
    {
        std::cout << "SUCCESS! The pointers are equal." << std::endl;
        std::cout << "Restored Data: " << ptr->name << ", " << ptr->age << std::endl;
    }
    else
    {
        std::cout << "FAILURE! Pointers are different." << std::endl;
    }

    return 0;
}
