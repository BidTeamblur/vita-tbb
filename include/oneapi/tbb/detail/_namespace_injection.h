// Public API version namespace.
// Upstream places exposed types (e.g. blocked_range) into an inline
// namespace v1 to allow future versioning without breaking
// compatibility. This should preserve that structure for Vita.
// Not sure if fully necessary but just in case.
namespace tbb {
inline namespace v1 {}
}