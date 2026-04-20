#ifndef __TBB_detail__assert_H
#define __TBB_detail__assert_H

#include <cassert>

// Turns _TBB_ASSERT into an alias for assert()
// This means no debug msg function however
#define __TBB_ASSERT(expr, msg) assert(expr)

#endif // __TBB_detail__assert_H