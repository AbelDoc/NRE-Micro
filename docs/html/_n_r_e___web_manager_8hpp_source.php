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
        <title>NRE-Micro: /mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/Web/Manager/NRE_WebManager.hpp Source File</title>
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
<li class="navelem"><a class="el" href="dir_68267d1309a1af8e8297ef4c3efbcdba.php">src</a></li><li class="navelem"><a class="el" href="dir_2f7b293845ef2dc4967d47cb94f137d6.php">Web</a></li><li class="navelem"><a class="el" href="dir_5fb43b3d5c0b969c19995fcd4c7ae70a.php">Manager</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="headertitle">
<div class="title">NRE_WebManager.hpp</div>  </div>
</div><!--header-->
<div class="contents">
<a href="_n_r_e___web_manager_8hpp.php">Go to the documentation of this file.</a><div class="fragment"><div class="line"><a name="l00001"></a><span class="lineno">    1</span>&#160;</div><div class="line"><a name="l00010"></a><span class="lineno">   10</span>&#160;<span class="preprocessor">     #pragma once</span></div><div class="line"><a name="l00011"></a><span class="lineno">   11</span>&#160;</div><div class="line"><a name="l00012"></a><span class="lineno">   12</span>&#160;<span class="preprocessor">     #include &quot;../../Core/Module/NRE_Module.hpp&quot;</span></div><div class="line"><a name="l00013"></a><span class="lineno">   13</span>&#160;<span class="preprocessor">     #include &lt;ESP8266WebServer.h&gt;</span></div><div class="line"><a name="l00014"></a><span class="lineno">   14</span>&#160;<span class="preprocessor">     #include &lt;ESP8266HTTPUpdateServer.h&gt;</span></div><div class="line"><a name="l00015"></a><span class="lineno">   15</span>&#160;</div><div class="line"><a name="l00016"></a><span class="lineno">   16</span>&#160;<span class="preprocessor">     #include &lt;vector&gt;</span></div><div class="line"><a name="l00017"></a><span class="lineno">   17</span>&#160;<span class="preprocessor">     #include &lt;functional&gt;</span></div><div class="line"><a name="l00018"></a><span class="lineno">   18</span>&#160;</div><div class="line"><a name="l00019"></a><span class="lineno">   19</span>&#160;<span class="preprocessor">     #ifndef NRE_USE_WIFI</span></div><div class="line"><a name="l00020"></a><span class="lineno">   20</span>&#160;<span class="preprocessor">        #error Web Server can&#39;t work without WiFi module, please use it.</span></div><div class="line"><a name="l00021"></a><span class="lineno">   21</span>&#160;<span class="preprocessor">     #endif</span></div><div class="line"><a name="l00022"></a><span class="lineno">   22</span>&#160;</div><div class="line"><a name="l00023"></a><span class="lineno">   23</span>&#160;<span class="preprocessor">     #ifndef NRE_WEB_SERVER_PORT</span></div><div class="line"><a name="l00024"></a><span class="lineno">   24</span>&#160;<span class="preprocessor">        #define NRE_WEB_SERVER_PORT 80</span></div><div class="line"><a name="l00025"></a><span class="lineno">   25</span>&#160;<span class="preprocessor">     #endif</span></div><div class="line"><a name="l00026"></a><span class="lineno">   26</span>&#160;</div><div class="line"><a name="l00031"></a><span class="lineno">   31</span>&#160;    <span class="keyword">namespace </span><a class="code" href="namespace_n_r_e.php">NRE</a> {</div><div class="line"><a name="l00032"></a><span class="lineno">   32</span>&#160;</div><div class="line"><a name="l00037"></a><span class="lineno">   37</span>&#160;        <span class="keyword">namespace </span><a class="code" href="namespace_micro.php">Micro</a> {</div><div class="line"><a name="l00038"></a><span class="lineno">   38</span>&#160;</div><div class="line"><a name="l00039"></a><span class="lineno">   39</span>&#160;            <span class="keyword">typedef</span> std::function&lt;void(ESP8266WebServer&amp; server)&gt; ServerHandle;</div><div class="line"><a name="l00040"></a><span class="lineno">   40</span>&#160;</div><div class="line"><a name="l00045"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_web_manager.php">   45</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php">WebManager</a> : <span class="keyword">public</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_module.php">Module</a>&lt;WebManager&gt; {</div><div class="line"><a name="l00046"></a><span class="lineno">   46</span>&#160;                <span class="keyword">private</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00047"></a><span class="lineno">   47</span>&#160;                    ESP8266HTTPUpdateServer updater;    </div><div class="line"><a name="l00048"></a><span class="lineno">   48</span>&#160;                    ESP8266WebServer server;            </div><div class="line"><a name="l00049"></a><span class="lineno">   49</span>&#160;                    std::vector&lt;ServerHandle&gt; handles;  </div><div class="line"><a name="l00051"></a><span class="lineno">   51</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00052"></a><span class="lineno">   52</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00056"></a><span class="lineno">   56</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php#a9ecc75f34d80a10da66edf8afbc47fc8">WebManager</a>();</div><div class="line"><a name="l00057"></a><span class="lineno">   57</span>&#160;</div><div class="line"><a name="l00058"></a><span class="lineno">   58</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00063"></a><span class="lineno">   63</span>&#160;<span class="comment"></span>                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php#a6ea119278f71be42f465f72f2aceb499">addHandle</a>(ServerHandle handler);</div><div class="line"><a name="l00067"></a><span class="lineno">   67</span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php#a0a051633dc4a2f90579ea83819980641">setup</a>() <span class="keyword">override</span>;</div><div class="line"><a name="l00071"></a><span class="lineno">   71</span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php#a83547254a117ec8c8f35909759909557">loop</a>() <span class="keyword">override</span>;</div><div class="line"><a name="l00072"></a><span class="lineno">   72</span>&#160;            };</div><div class="line"><a name="l00073"></a><span class="lineno">   73</span>&#160;</div><div class="line"><a name="l00074"></a><span class="lineno">   74</span>&#160;            <span class="keyword">static</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_web_manager.php">WebManager</a> _webManager;</div><div class="line"><a name="l00075"></a><span class="lineno">   75</span>&#160;        }</div><div class="line"><a name="l00076"></a><span class="lineno">   76</span>&#160;    }</div><div class="line"><a name="l00077"></a><span class="lineno">   77</span>&#160;</div><div class="line"><a name="l00078"></a><span class="lineno">   78</span>&#160;<span class="preprocessor">    #include &quot;<a class="code" href="_n_r_e___web_manager_inl_8hpp.php">NRE_WebManagerInl.hpp</a>&quot;</span></div><div class="ttc" id="_n_r_e___web_manager_inl_8hpp_php"><div class="ttname"><a href="_n_r_e___web_manager_inl_8hpp.php">NRE_WebManagerInl.hpp</a></div><div class="ttdoc">Implementation of Micro&amp;#39;s API&amp;#39;s Object : WebManager. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_web_manager_php_a83547254a117ec8c8f35909759909557"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_web_manager.php#a83547254a117ec8c8f35909759909557">NRE::Micro::WebManager::loop</a></div><div class="ttdeci">void loop() override</div><div class="ttdef"><b>Definition:</b> NRE_WebManagerInl.hpp:31</div></div>
<div class="ttc" id="namespace_micro_php"><div class="ttname"><a href="namespace_micro.php">Micro</a></div><div class="ttdoc">Micro&amp;#39;s API. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_web_manager_php_a0a051633dc4a2f90579ea83819980641"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_web_manager.php#a0a051633dc4a2f90579ea83819980641">NRE::Micro::WebManager::setup</a></div><div class="ttdeci">void setup() override</div><div class="ttdef"><b>Definition:</b> NRE_WebManagerInl.hpp:20</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_web_manager_php_a6ea119278f71be42f465f72f2aceb499"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_web_manager.php#a6ea119278f71be42f465f72f2aceb499">NRE::Micro::WebManager::addHandle</a></div><div class="ttdeci">void addHandle(ServerHandle handler)</div><div class="ttdef"><b>Definition:</b> NRE_WebManagerInl.hpp:16</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_web_manager_php_a9ecc75f34d80a10da66edf8afbc47fc8"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_web_manager.php#a9ecc75f34d80a10da66edf8afbc47fc8">NRE::Micro::WebManager::WebManager</a></div><div class="ttdeci">WebManager()</div><div class="ttdef"><b>Definition:</b> NRE_WebManagerInl.hpp:13</div></div>
<div class="ttc" id="namespace_n_r_e_php"><div class="ttname"><a href="namespace_n_r_e.php">NRE</a></div><div class="ttdoc">The NearlyRealEngine&amp;#39;s global namespace. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.cpp:12</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_module_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module</a></div><div class="ttdoc">Represent a module interface to create framework sub module. </div><div class="ttdef"><b>Definition:</b> NRE_Module.hpp:31</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_web_manager_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_web_manager.php">NRE::Micro::WebManager</a></div><div class="ttdoc">Manage a web serveur and http updater. </div><div class="ttdef"><b>Definition:</b> NRE_WebManager.hpp:45</div></div>
</div><!-- fragment --></div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>