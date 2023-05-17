#include <string>
#include "Point.hpp"

#pragma once

using namespace std;

namespace ariel {
    class Character {
        public:
            Character(string name, Point location, int hit_points) : name(name), loc(location), health_points(hit_points) {};
            bool isAlive();
            double distance(Character other);
            void hit(int damage);
            string getName();
            Point getLocation();
            string print();
        private:
            Point loc;
            int health_points;
            string name;


    };
}