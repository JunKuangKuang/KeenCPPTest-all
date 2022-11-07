
#include "../../utils/chain/chain.h"

int main() {
    chain<int> chain;
    for (int i = 0; i < 10; ++i) {
        chain.insert(i,i);
    }
    chain.output(cout);

    return 0;
}
