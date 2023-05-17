#include "Team.hpp"

using namespace std;

namespace ariel {
    class SmartTeam : public Team {
        public:
            SmartTeam(vector<Character> team, Character& leader) : Team(team, leader) {};
        private:
    
    };
}