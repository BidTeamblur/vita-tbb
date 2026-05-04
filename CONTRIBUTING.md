# Contributing

Pull requests are welcome. A few things worth knowing before you open one.

## Constraints

- C++14 only. No C++20, no concepts, no requires clauses. The Vita
  toolchain is GCC 10.x and from my tests `-std=c++20` does not actually enable C++20.
- Stay as close to upstream oneTBB structure and naming as possible.
  If something had to be changed, there is usually a comment explaining why, with the prefix VITA_TBB:
- Header-only where possible. The only exception right now would be the thread pool
  implementation which requires Vita-specific OS calls.

## What to work on

The project is a subset, not a full port. 
If you want to help, anything is fair game.

If something is genuinely hard to implement correctly on Vita, leaving it
out is better than implementing it badly.

## Testing

Tests live in `tests/` and are plain `.cpp` files with no framework.
If you add or change something testable, add a test for it.

## License

Contributions are under Apache 2.0, same as the rest of the project.