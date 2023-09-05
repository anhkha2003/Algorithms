#include <ext/rope>
// SGI extension
using namespace __gnu_cxx;

rope<int> v;
v.insert(k, x); // push x at place k-th: O(log)
v[x] // return value at x-th