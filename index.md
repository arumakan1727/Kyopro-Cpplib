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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# {{ site.title }}

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions)
<a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

{% if site.github.project_tagline %}{{ site.github.project_tagline }}{% else %}This documentation is automatically generated by <a href="https://github.com/online-judge-tools/verification-helper">online-judge-tools/verification-helper</a>.{% endif %}

## Library Files

<div id="b2507468f95156358fa490fd543ad2f0"></div>

### export

* :warning: <a href="library/export/template.cpp.html">export/template.cpp</a>


<div id="9db7d97a5d6bc6230f80aab8020b7e44"></div>

### include/data-structure

* :heavy_check_mark: <a href="library/include/data-structure/union-find.hpp.html">Union-Find (素集合データ構造) <small>(include/data-structure/union-find.hpp)</small></a>


<div id="d5567e78d3674558c180d2f4feaa863b"></div>

### include/template-parts

* :warning: <a href="library/include/template-parts/all-macro.hpp.html">all()マクロ <small>(include/template-parts/all-macro.hpp)</small></a>
* :warning: <a href="library/include/template-parts/bye.hpp.html">bye() (出力してexit(0)) <small>(include/template-parts/bye.hpp)</small></a>
* :warning: <a href="library/include/template-parts/chminmax.hpp.html">chmin(), chmax() <small>(include/template-parts/chminmax.hpp)</small></a>
* :warning: <a href="library/include/template-parts/constant.hpp.html">よく使う定数 <small>(include/template-parts/constant.hpp)</small></a>
* :warning: <a href="library/include/template-parts/container-io.hpp.html">コンテナの入出力 <small>(include/template-parts/container-io.hpp)</small></a>
* :warning: <a href="library/include/template-parts/div-ceil.hpp.html">divceil() (切り上げ除算) <small>(include/template-parts/div-ceil.hpp)</small></a>
* :heavy_check_mark: <a href="library/include/template-parts/io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(include/template-parts/io-setup.hpp)</small></a>
* :warning: <a href="library/include/template-parts/is-within-range.hpp.html">within() (半開区間内に含まれているかの判定) <small>(include/template-parts/is-within-range.hpp)</small></a>
* :warning: <a href="library/include/template-parts/join-into-ostream.hpp.html">join() (要素を区切り文字で結合して出力) <small>(include/template-parts/join-into-ostream.hpp)</small></a>
* :warning: <a href="library/include/template-parts/makeVec.hpp.html">makeVec() (多次元std::vectorの生成) <small>(include/template-parts/makeVec.hpp)</small></a>
* :warning: <a href="library/include/template-parts/println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(include/template-parts/println.hpp)</small></a>
* :warning: <a href="library/include/template-parts/rep-macro.hpp.html">rep()マクロ <small>(include/template-parts/rep-macro.hpp)</small></a>
* :warning: <a href="library/include/template-parts/template.cpp.html">include/template-parts/template.cpp</a>
* :warning: <a href="library/include/template-parts/tuple-print.hpp.html">tupleの出力 <small>(include/template-parts/tuple-print.hpp)</small></a>
* :warning: <a href="library/include/template-parts/type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>
* :warning: <a href="library/include/template-parts/var-declaration-with-input.hpp.html">複数変数宣言をして同時に入力もするやつ <small>(include/template-parts/var-declaration-with-input.hpp)</small></a>


## Verify Files

* :heavy_check_mark: <a href="verify/test/DSL_1_A.test.cpp.html">test/DSL_1_A.test.cpp</a>

