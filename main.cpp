#include <iostream>
#include "hyperloglog.h"

int main() {
    hyperloglog hll(10);

    for (int i = 1; i <= 10000; i++) {
        hll.AddElem(i);
    }

    std::cout << "Estimated cardinality: " << hll.GetCardinality() << std::endl;

    return 0;
}
