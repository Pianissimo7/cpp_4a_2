#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel {
    class Team {
        public:
            Team(Character* leader);
            ~Team();
            void add(Character* other);
            void attack(Team* other);
            int stillAlive();
            void print();
        private:
            vector<Character> team;
    };
}