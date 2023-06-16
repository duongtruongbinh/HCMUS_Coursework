#include "Dice.h"
#include "RandomIntegerGenerator.h"

Dice::Dice() {
    _faces = 6;
}

Dice::Dice(int faces) {
    this->_faces = faces;
}

int Dice::roll() {
    int value = 0;
    auto rng = RandomIntegerGenerator::instance();
    value = rng->next(_faces) + 1;

    return value;
}