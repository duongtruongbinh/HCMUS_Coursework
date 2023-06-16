#pragma once
#include <iostream>
#include <memory>
using namespace std;

class RandomIntegerGenerator {
private:
    inline static shared_ptr<RandomIntegerGenerator> _instance = NULL;
    RandomIntegerGenerator();
    
public:
    static shared_ptr<RandomIntegerGenerator> instance() {
        if (_instance == NULL) {
            RandomIntegerGenerator* temp = new RandomIntegerGenerator();
            _instance = shared_ptr<RandomIntegerGenerator>(temp);
        }

        return _instance;
    }
public:
    ~RandomIntegerGenerator();
public:
    int next();
    int next(int);
    int next(int, int);
};