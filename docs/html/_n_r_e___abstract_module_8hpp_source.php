<!-- HTML header for doxygen 1.8.8-->
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <!-- For Mobile Devices -->
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta http-equiv="Content-Type" content="text/xhtml;charset=UTF-8"/>
        <meta name="generator" content="Doxygen 1.8.11"/>
        <script type="text/javascript" src="../../js/jquery-2.1.1.min.js"></script>
        <title>NRE-Micro: /mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/Core/Module/NRE_AbstractModule.hpp Source File</title>
        <!--<link href="tabs.css" rel="stylesheet" type="text/css"/>-->
        <script type="text/javascript" src="dynsections.js"></script>
        <link href="search/search.css" rel="stylesheet" type="text/css"/>
<script type="text/javascript" src="search/searchdata.js"></script>
<script type="text/javascript" src="search/search.js"></script>
<script type="text/javascript">
  $(document).ready(function() { init_search(); });
</script>
        <link href="doxygen.css" rel="stylesheet" type="text/css" />
        <link href="style.css" rel="stylesheet" type="text/css"/>
        <link href='https://fonts.googleapis.com/css?family=Roboto+Slab' rel='stylesheet' type='text/css'>
        <?php
            include '../../php/navigation.php';
            if (!isset($_COOKIE["theme"]) || $_COOKIE["theme"] == "dark") {
                echo '<link href="../../css/dark/bootstrap.css" rel="stylesheet">';
            } else {
                echo '<link href="../../css/light/bootstrap.css" rel="stylesheet">';
            }
        ?>
        <script src="../../js/bootstrap.min.js"></script>
        <script type="text/javascript" src="doxy-boot.js"></script>
    </head>
    <body>
        <div class="container-fluid">
            <header class="page-header">
                <a href="../../../index.php">
                    <img src="../../img/Logo.png" class="logo img-responsive"/>
                </a>
            </header>
            <?php addNavigationBarInl(false); ?>
            <div id="top" class="row"><!-- do not remove this div, it is closed by doxygen! -->
                <div class="col-lg-12">
                    <div class="panel panel-default">
                        <div class="panel-body">
<!-- end header part -->
<!-- Generated by Doxygen 1.8.11 -->
<script type="text/javascript">
var searchBox = new SearchBox("searchBox", "search",false,'Search');
</script>
  <div id="navrow1" class="tabs">
    <ul class="tablist">
      <li><a href="index.php"><span>Main&#160;Page</span></a></li>
      <li><a href="namespaces.php"><span>Namespaces</span></a></li>
      <li><a href="annotated.php"><span>Classes</span></a></li>
      <li class="current"><a href="files.php"><span>Files</span></a></li>
      <li>
        <div id="MSearchBox" class="MSearchBoxInactive">
        <span class="left">
          <img id="MSearchSelect" src="search/mag_sel.png"
               onmouseover="return searchBox.OnSearchSelectShow()"
               onmouseout="return searchBox.OnSearchSelectHide()"
               alt=""/>
          <input type="text" id="MSearchField" value="Search" accesskey="S"
               onfocus="searchBox.OnSearchFieldFocus(true)" 
               onblur="searchBox.OnSearchFieldFocus(false)" 
               onkeyup="searchBox.OnSearchFieldChange(event)"/>
          </span><span class="right">
            <a id="MSearchClose" href="javascript:searchBox.CloseResultsWindow()"><img id="MSearchCloseImg" border="0" src="search/close.png" alt=""/></a>
          </span>
        </div>
      </li>
    </ul>
  </div>
  <div id="navrow2" class="tabs2">
    <ul class="tablist">
      <li><a href="files.php"><span>File&#160;List</span></a></li>
    </ul>
  </div>
<!-- window showing the filter options -->
<div id="MSearchSelectWindow"
     onmouseover="return searchBox.OnSearchSelectShow()"
     onmouseout="return searchBox.OnSearchSelectHide()"
     onkeydown="return searchBox.OnSearchSelectKey(event)">
</div>

<!-- iframe showing the search results (closed by default) -->
<div id="MSearchResultsWindow">
<iframe src="javascript:void(0)" frameborder="0" 
        name="MSearchResults" id="MSearchResults">
</iframe>
</div>

<div id="nav-path" class="navpath">
  <ul>
<li class="navelem"><a class="el" href="dir_68267d1309a1af8e8297ef4c3efbcdba.php">src</a></li><li class="navelem"><a class="el" href="dir_a2f0e5642e47e7ed59fe0f0829eafb5f.php">Core</a></li><li class="navelem"><a class="el" href="dir_b00fbd6cf7f8e36694ce8c1205bd4029.php">Module</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="headertitle">
<div class="title">NRE_AbstractModule.hpp</div>  </div>
</div><!--header-->
<div class="contents">
<a href="_n_r_e___abstract_module_8hpp.php">Go to the documentation of this file.</a><div class="fragment"><div class="line"><a name="l00001"></a><span class="lineno">    1</span>&#160;</div><div class="line"><a name="l00010"></a><span class="lineno">   10</span>&#160;<span class="preprocessor">    #pragma once</span></div><div class="line"><a name="l00011"></a><span class="lineno">   11</span>&#160;</div><div class="line"><a name="l00016"></a><span class="lineno">   16</span>&#160;    <span class="keyword">namespace </span><a class="code" href="namespace_n_r_e.php">NRE</a> {</div><div class="line"><a name="l00021"></a><span class="lineno">   21</span>&#160;        <span class="keyword">namespace </span><a class="code" href="namespace_micro.php">Micro</a> {</div><div class="line"><a name="l00022"></a><span class="lineno">   22</span>&#160;</div><div class="line"><a name="l00023"></a><span class="lineno">   23</span>&#160;            <span class="keyword">typedef</span> <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> ModuleId;</div><div class="line"><a name="l00024"></a><span class="lineno">   24</span>&#160;</div><div class="line"><a name="l00029"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">   29</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> {</div><div class="line"><a name="l00030"></a><span class="lineno">   30</span>&#160;                <span class="keyword">public</span> :   <span class="comment">// Methods</span></div><div class="line"><a name="l00031"></a><span class="lineno">   31</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00035"></a><span class="lineno">   35</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#aa3db66bc689eb07168e52157e6cf1702">AbstractModule</a>() = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00036"></a><span class="lineno">   36</span>&#160;</div><div class="line"><a name="l00037"></a><span class="lineno">   37</span>&#160;                    <span class="comment">//## Deconstructor ##//</span></div><div class="line"><a name="l00041"></a><span class="lineno">   41</span>&#160;<span class="comment"></span>                        <span class="keyword">virtual</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a38f613f697ca8d200a1a270e03967d04">~AbstractModule</a>() = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00042"></a><span class="lineno">   42</span>&#160;</div><div class="line"><a name="l00043"></a><span class="lineno">   43</span>&#160;                    <span class="comment">//## Copy Constructor ##//</span></div><div class="line"><a name="l00048"></a><span class="lineno">   48</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#aa3db66bc689eb07168e52157e6cf1702">AbstractModule</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> <span class="keyword">const</span>&amp; m) = <span class="keyword">delete</span>;</div><div class="line"><a name="l00049"></a><span class="lineno">   49</span>&#160;</div><div class="line"><a name="l00050"></a><span class="lineno">   50</span>&#160;                    <span class="comment">//## Move Constructor ##//</span></div><div class="line"><a name="l00055"></a><span class="lineno">   55</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#aa3db66bc689eb07168e52157e6cf1702">AbstractModule</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&amp; m) = <span class="keyword">delete</span>;</div><div class="line"><a name="l00056"></a><span class="lineno">   56</span>&#160;</div><div class="line"><a name="l00057"></a><span class="lineno">   57</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00061"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a8f93564ffc4fa3818c765b6eed3ab083">   61</a></span>&#160;<span class="comment"></span>                        <span class="keyword">virtual</span> <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a8f93564ffc4fa3818c765b6eed3ab083">setup</a>() {</div><div class="line"><a name="l00062"></a><span class="lineno">   62</span>&#160;                        }</div><div class="line"><a name="l00066"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a62533d0ef5768f92707d413d53fb3904">   66</a></span>&#160;                        <span class="keyword">virtual</span> <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a62533d0ef5768f92707d413d53fb3904">loop</a>() {</div><div class="line"><a name="l00067"></a><span class="lineno">   67</span>&#160;                        }</div><div class="line"><a name="l00068"></a><span class="lineno">   68</span>&#160;</div><div class="line"><a name="l00069"></a><span class="lineno">   69</span>&#160;                    <span class="comment">//## Assignment Operator ##//</span></div><div class="line"><a name="l00075"></a><span class="lineno">   75</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a>&amp; <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a2452ab1a95d5dd5c4305605ed4243492">operator=</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> <span class="keyword">const</span>&amp; m) = <span class="keyword">delete</span>;</div><div class="line"><a name="l00081"></a><span class="lineno">   81</span>&#160;                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a>&amp; <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a2452ab1a95d5dd5c4305605ed4243492">operator=</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&amp; m) = <span class="keyword">delete</span>;</div><div class="line"><a name="l00082"></a><span class="lineno">   82</span>&#160;</div><div class="line"><a name="l00083"></a><span class="lineno">   83</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Static</span></div><div class="line"><a name="l00084"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a95d15910d0d4e77aa08063fe383ff8dc">   84</a></span>&#160;                    <span class="keyword">static</span> ModuleId <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a95d15910d0d4e77aa08063fe383ff8dc">counter</a>;    </div><div class="line"><a name="l00085"></a><span class="lineno">   85</span>&#160;            };</div><div class="line"><a name="l00086"></a><span class="lineno">   86</span>&#160;</div><div class="line"><a name="l00087"></a><span class="lineno">   87</span>&#160;        }</div><div class="line"><a name="l00088"></a><span class="lineno">   88</span>&#160;    }</div><div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_a38f613f697ca8d200a1a270e03967d04"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a38f613f697ca8d200a1a270e03967d04">NRE::Micro::AbstractModule::~AbstractModule</a></div><div class="ttdeci">virtual ~AbstractModule()=default</div></div>
<div class="ttc" id="namespace_micro_php"><div class="ttname"><a href="namespace_micro.php">Micro</a></div><div class="ttdoc">Micro&amp;#39;s API. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_a2452ab1a95d5dd5c4305605ed4243492"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a2452ab1a95d5dd5c4305605ed4243492">NRE::Micro::AbstractModule::operator=</a></div><div class="ttdeci">AbstractModule &amp; operator=(AbstractModule const &amp;m)=delete</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php">NRE::Micro::AbstractModule</a></div><div class="ttdoc">Represent an abstract module used to active a certain part of the framework. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.hpp:29</div></div>
<div class="ttc" id="namespace_n_r_e_php"><div class="ttname"><a href="namespace_n_r_e.php">NRE</a></div><div class="ttdoc">The NearlyRealEngine&amp;#39;s global namespace. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.cpp:12</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_a95d15910d0d4e77aa08063fe383ff8dc"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a95d15910d0d4e77aa08063fe383ff8dc">NRE::Micro::AbstractModule::counter</a></div><div class="ttdeci">static ModuleId counter</div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.hpp:84</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_a8f93564ffc4fa3818c765b6eed3ab083"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a8f93564ffc4fa3818c765b6eed3ab083">NRE::Micro::AbstractModule::setup</a></div><div class="ttdeci">virtual void setup()</div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.hpp:61</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_a62533d0ef5768f92707d413d53fb3904"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a62533d0ef5768f92707d413d53fb3904">NRE::Micro::AbstractModule::loop</a></div><div class="ttdeci">virtual void loop()</div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.hpp:66</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_module_php_aa3db66bc689eb07168e52157e6cf1702"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_module.php#aa3db66bc689eb07168e52157e6cf1702">NRE::Micro::AbstractModule::AbstractModule</a></div><div class="ttdeci">AbstractModule()=default</div></div>
</div><!-- fragment --></div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>
