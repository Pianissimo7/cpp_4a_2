#include "Ninja.hpp"

using namespace std;

namespace ariel {
    class YoungNinja : public Ninja {
        public:
            YoungNinja(string name, Point location) : Ninja(name, location, 10, 14) {};
        private:
    };
}