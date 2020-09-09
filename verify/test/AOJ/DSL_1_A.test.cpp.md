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


# :heavy_check_mark: test/AOJ/DSL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/DSL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:38:47+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Data-Structure/Disjoint-Set/union-find.hpp.html">Union-Find (素集合データ構造) <small>(Data-Structure/Disjoint-Set/union-find.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Util/IO/io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(Util/IO/io-setup.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#include "../../Data-Structure/Disjoint-Set/union-find.hpp"
#include "../../Util/IO/io-setup.hpp"
using namespace std;

int main() {
    ioSetup();
    constexpr char LF = '\n';

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.same(x, y) << LF;
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/DSL_1_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#line 5 "Data-Structure/Disjoint-Set/union-find.hpp"

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
#line 4 "Util/IO/io-setup.hpp"

/**
 * @brief ioSetup() (iostreamの高速化と実数出力の設定)
 */
void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}
#line 6 "test/AOJ/DSL_1_A.test.cpp"
using namespace std;

int main() {
    ioSetup();
    constexpr char LF = '\n';

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.same(x, y) << LF;
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
