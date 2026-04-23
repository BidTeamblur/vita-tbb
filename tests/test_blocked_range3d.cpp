#include <cassert>
#include "oneapi/tbb.h"

int main() {
    tbb::blocked_range3d<int> r(
        0, 10,   // pages
        0, 20,   // rows
        0, 30    // cols
    );

    assert(!r.empty());
    assert(r.is_divisible());

    tbb::blocked_range3d<int> r2(r, tbb::split{});

    // One dimension must have been split
    bool page_split = r.pages().end() == r2.pages().begin();
    bool row_split  = r.rows().end()  == r2.rows().begin();
    bool col_split  = r.cols().end()  == r2.cols().begin();

    assert(page_split || row_split || col_split);

    return 0;
}
