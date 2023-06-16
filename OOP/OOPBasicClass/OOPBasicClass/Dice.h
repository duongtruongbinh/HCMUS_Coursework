#pragma once


class Dice {
private:
    int _faces;
public:
    int faces() { return _faces; }

    Dice();
    Dice(int);

    int roll();
};