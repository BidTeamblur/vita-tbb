/*
    Copyright (c) 2005-2024 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef __TBB_detail__template_helpers_H
#define __TBB_detail__template_helpers_H

#include "_utils.h"

#include <cstddef>
#include <utility>

namespace tbb {
namespace detail {
inline namespace d0 {

// VITA-TBB: Removed >=cpp14 check here
using std::index_sequence;
using std::make_index_sequence;

//! Attach an index to a type to use it with an index sequence
template<typename T, std::size_t>
using indexed_t = T;

} // inline namespace d0
} // namespace detail
} // namespace tbb

#endif // __TBB_detail__template_helpers_H