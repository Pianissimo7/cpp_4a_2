#include "Ninja.hpp"

using namespace std;

namespace ariel {
    class OldNinja : public Ninja {
        public:
            OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {};
        private:
    
    };
}