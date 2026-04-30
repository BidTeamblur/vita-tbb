#ifndef __TBB_profiling_H
#define __TBB_profiling_H

#include <cstdint>
#include <string>

namespace tbb {
namespace detail {
inline namespace d0 {
    // include list of index names
    #define TBB_STRING_RESOURCE(index_name,str) index_name,
    enum string_resource_index : std::uintptr_t {
        #include "detail/_string_resource.h"
        NUM_STRINGS
    };
    #undef TBB_STRING_RESOURCE
    
    enum itt_relation
    {
    __itt_relation_is_unknown = 0,
    __itt_relation_is_dependent_on,         /**< "A is dependent on B" means that A cannot start until B completes */
    __itt_relation_is_sibling_of,           /**< "A is sibling of B" means that A and B were created as a group */
    __itt_relation_is_parent_of,            /**< "A is parent of B" means that A created B */
    __itt_relation_is_continuation_of,      /**< "A is continuation of B" means that A assumes the dependencies of B */
    __itt_relation_is_child_of,             /**< "A is child of B" means that A was created by B (inverse of is_parent_of) */
    __itt_relation_is_continued_by,         /**< "A is continued by B" means that B assumes the dependencies of A (inverse of is_continuation_of) */
    __itt_relation_is_predecessor_to        /**< "A is predecessor to B" means that B cannot start until A completes (inverse of is_dependent_on) */
    };

//! Unicode support
#if (_WIN32||_WIN64)
    //! Unicode character type. Always wchar_t on Windows.
    using tchar = wchar_t;
#else /* !WIN */
    using tchar = char;
#endif /* !WIN */

} // namespace d0
} // namespace detail
} // namespace tbb

// Need these to work regardless of tools support
namespace tbb {
namespace detail {
namespace d1 {
    enum notify_type {prepare=0, cancel, acquired, releasing, destroy};
    enum itt_domain_enum { ITT_DOMAIN_FLOW=0, ITT_DOMAIN_MAIN=1, ITT_DOMAIN_ALGO=2, ITT_NUM_DOMAINS };
} // namespace d1

//  VITA_TBB: exchanged _export.h usage to inline functions.
//  On Vita there is no profiling runtime, so all are no-ops.
namespace r1 {  
inline void call_itt_notify(int, void*) {}
inline void create_itt_sync(void*, const tchar*, const tchar*) {}
inline void itt_make_task_group(d1::itt_domain_enum, void*, unsigned long long,
                                void*, unsigned long long, string_resource_index) {}
inline void itt_task_begin(d1::itt_domain_enum, void*, unsigned long long,
                           void*, unsigned long long, string_resource_index) {}
inline void itt_task_end(d1::itt_domain_enum) {}
inline void itt_set_sync_name(void*, const tchar*) {}
inline void itt_metadata_str_add(d1::itt_domain_enum, void*, unsigned long long,
                                 string_resource_index, const char*) {}
inline void itt_metadata_ptr_add(d1::itt_domain_enum, void*, unsigned long long,
                                 string_resource_index, void*) {}
inline void itt_relation_add(d1::itt_domain_enum, void*, unsigned long long,
                             itt_relation, void*, unsigned long long) {}
inline void itt_region_begin(d1::itt_domain_enum, void*, unsigned long long,
                             void*, unsigned long long, string_resource_index) {}
inline void itt_region_end(d1::itt_domain_enum, void*, unsigned long long) {}
} // namespace r1

namespace d1 {
    inline void create_itt_sync(void*, const char*, const char*) {}
    inline void call_itt_notify(notify_type, void*) {}
    inline void call_itt_task_notify(notify_type, void*) {}
    inline void itt_set_sync_name(void*, const char*) {}
    inline void itt_make_task_group(itt_domain_enum, void*, unsigned long long,
                                    void*, unsigned long long, string_resource_index) {}
    inline void itt_metadata_str_add(itt_domain_enum, void*, unsigned long long,
                                     string_resource_index, const char*) {}
    inline void register_node_addr(itt_domain_enum, void*, unsigned long long,
                                   string_resource_index, void*) {}
    inline void itt_relation_add(itt_domain_enum, void*, unsigned long long,
                                 itt_relation, void*, unsigned long long) {}
    inline void itt_task_begin(itt_domain_enum, void*, unsigned long long,
                               void*, unsigned long long, string_resource_index) {}
    inline void itt_task_end(itt_domain_enum) {}
    inline void itt_region_begin(itt_domain_enum, void*, unsigned long long,
                                 void*, unsigned long long, string_resource_index) {}
    inline void itt_region_end(itt_domain_enum, void*, unsigned long long) {}

    // VITA_TBB: the full class is only instantiated when
    // TBB_USE_PROFILING_TOOLS is defined (never on Vita).
    struct event {
        event(const std::string&) {}
        void emit() {}
        static void emit(const std::string&) {}
    };
} // namespace d1

} // detail

namespace profiling {
    using detail::d1::event;
}

} // tbb

#endif /* __TBB_profiling_H */