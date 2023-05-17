#include "Ninja.hpp"

using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja {
        public:
            TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {};
        private:
    
    };
}