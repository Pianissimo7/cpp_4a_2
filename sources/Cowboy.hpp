#include "Character.hpp"


namespace ariel {
    class Cowboy : public Character {
        public:
            Cowboy(string name, Point location) : Character(name, location, 110) {};
            void shoot(Character* target);
            bool hasboolets();
            void reload();
        private:
            int bullets;
    };
}