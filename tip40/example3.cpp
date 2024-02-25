#include <iostream>

class Base {  
public:  
    int value;  
      
    Base() : value(0) {}  
      
    void printValue() const {  
        std::cout << "Base value: " << value << std::endl;  
    }  
};  
  
class Derived1 : virtual public Base {  
    // Derived1 adds its own members and functions  
};  
  
class Derived2 : virtual public Base {  
    // Derived2 adds its own members and functions  
};  
  
class MostDerived : public Derived1, public Derived2 {  
    // MostDerived inherits from both Derived1 and Derived2, which virtually inherit from Base  
};  
  
int main() {  
    MostDerived md;  
      
    // Accessing Base's members through MostDerived  
    md.value = 42;  // Sets the value in the shared Base subobject  
    md.printValue();  // Calls Base::printValue() on the shared Base subobject  
      
    return 0;  
}