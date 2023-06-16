#pragma once

// 2. Definition
class Cat {
private:// Atributes
    float _weight;
    float _height;
public: // Properties
    float weight() { return _weight; }
    float height() { return _height; }

    void setWeight(float value) { _weight = value; }
    void setHeight(float value) { _height = value; }
public:
    void run();
    void sleep();
    void eat();
};