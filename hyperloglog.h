#ifndef HYPERLOGLOG_H
#define HYPERLOGLOG_H

#include <bits/stdc++.h>
#include <bitset>

class hyperloglog
{
private:
    int leadingBits;
    std::vector<int> registers;
    double constant;

public:
    hyperloglog(int bits);
    ~hyperloglog();

    void AddElem(int val);

    double ComputeCardinality();
    double GetCardinality();

    int PositionOfLeftmostOne(uint64_t value);

    uint64_t  FirstBBits(uint64_t &binary);
};

uint64_t CalculateHash(int &val);

#endif