#include "Character.hpp"

using namespace ariel;

bool Character::isAlive() {
    return false;
}
double Character::distance(Character other) {
    return 0;
}
void Character::hit(int damage) {

}
string Character::getName() {
    return this->name;
}
Point Character::getLocation() {
    return this->loc;
}
string Character::print() {
    return "";
}