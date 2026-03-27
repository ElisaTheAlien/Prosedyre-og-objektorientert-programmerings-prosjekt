#include <iostream>

class Constillation {
    protected:
        std::string name;
        std::string distance;
    
    public:
        const std::string& getName() const {
            return name;
        }
};