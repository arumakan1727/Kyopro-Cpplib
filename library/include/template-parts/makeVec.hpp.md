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


# :warning: 多次元 vector の生成 <small>(include/template-parts/makeVec.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/makeVec.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 11:03:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @brief 多次元 vector の生成
 */
template <class T>
inline std::vector<T> makeVec(const T &initValue, size_t sz) {
    return std::vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto makeVec(const T &initValue, size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(initValue, args...))>(sz, makeVec<T>(initValue, args...));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/makeVec.hpp"
#include <vector>

/**
 * @brief 多次元 vector の生成
 */
template <class T>
inline std::vector<T> makeVec(const T &initValue, size_t sz) {
    return std::vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto makeVec(const T &initValue, size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(initValue, args...))>(sz, makeVec<T>(initValue, args...));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

