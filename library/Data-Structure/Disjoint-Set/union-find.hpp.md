---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Union-Find (素集合データ構造) <small>(Data-Structure/Disjoint-Set/union-find.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#510221fd93ed01153e9d07e085298835">Data-Structure/Disjoint-Set</a>
* <a href="{{ site.github.repository_url }}/blob/master/Data-Structure/Disjoint-Set/union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/AOJ/DSL_1_A.test.cpp.html">test/AOJ/DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(size_t n)
        : p(n, -1) {}

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }

    int root(int x) const {
        if (p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    bool same(int x, int y) const { return root(x) == root(y); }

    int size(int x) const { return -p[root(x)]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Data-Structure/Disjoint-Set/union-find.hpp"
#include <cstdint>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(size_t n)
        : p(n, -1) {}

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }

    int root(int x) const {
        if (p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    bool same(int x, int y) const { return root(x) == root(y); }

    int size(int x) const { return -p[root(x)]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
