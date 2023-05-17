#include "Character.hpp"

#pragma once

using namespace std;

namespace ariel {
    class Ninja : public Character {
        public:
            Ninja(string name, Point location, int hit_points, int speed) : Character(name, location, hit_points), speed(speed) {};
            void move(Character* other);
            void slash(Character* other);
        private:
            int speed;
    };
}