#include "hyperloglog.h"

hyperloglog::hyperloglog(int bits)
{
    this->leadingBits = bits;
    int m = 1 << bits;
    registers.resize(m, 0);
    constant = 0.7942;
}


uint64_t hyperloglog::FirstBBits(uint64_t &hash)
{
    uint64_t Firstbits = hash >> (64 - leadingBits);
    return Firstbits;
}

int hyperloglog::PositionOfLeftmostOne(uint64_t x)
{
    int pos = 1;
    while ((x & (1ULL << 63)) == 0 && x != 0)
    {
        x <<= 1;
        pos++;
    }
    if (x == 0)
        return 0;
    return pos;
}

void hyperloglog::AddElem(int val)
{
    uint64_t hash = CalculateHash(val);
    uint64_t index = FirstBBits(hash);
    uint64_t remaining = hash << leadingBits;
    int position = PositionOfLeftmostOne(remaining);
    registers[index] = std::max(registers[index], position);
}

double hyperloglog::ComputeCardinality()
{
    double sum = 0.0;
    for (int j = 0; j < registers.size(); j++)
    {
        sum += std::pow(2.0, -registers[j]);
    }

    double estimate = constant * registers.size() * registers.size() / sum;

    return estimate;
}

double hyperloglog::GetCardinality()
{
    return ComputeCardinality();
}

uint64_t CalculateHash(int &val)
{
    return static_cast<uint64_t>(std::hash<int>{}(val));
}

hyperloglog::~hyperloglog() {
}