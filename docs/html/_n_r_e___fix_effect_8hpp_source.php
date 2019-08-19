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
        <title>NRE-Micro: /mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/LED/Effect/NRE_FixEffect.hpp Source File</title>
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
<li class="navelem"><a class="el" href="dir_68267d1309a1af8e8297ef4c3efbcdba.php">src</a></li><li class="navelem"><a class="el" href="dir_6b864641f3cab9a7d09fa51df47d12f6.php">LED</a></li><li class="navelem"><a class="el" href="dir_14280b194263e09dcc6a357b683f8443.php">Effect</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="headertitle">
<div class="title">NRE_FixEffect.hpp</div>  </div>
</div><!--header-->
<div class="contents">
<a href="_n_r_e___fix_effect_8hpp.php">Go to the documentation of this file.</a><div class="fragment"><div class="line"><a name="l00001"></a><span class="lineno">    1</span>&#160;</div><div class="line"><a name="l00010"></a><span class="lineno">   10</span>&#160;<span class="preprocessor">     #pragma once</span></div><div class="line"><a name="l00011"></a><span class="lineno">   11</span>&#160;</div><div class="line"><a name="l00012"></a><span class="lineno">   12</span>&#160;<span class="preprocessor">     #include &quot;../Controller/NRE_LedController.hpp&quot;</span></div><div class="line"><a name="l00013"></a><span class="lineno">   13</span>&#160;</div><div class="line"><a name="l00018"></a><span class="lineno">   18</span>&#160;    <span class="keyword">namespace </span><a class="code" href="namespace_n_r_e.php">NRE</a> {</div><div class="line"><a name="l00019"></a><span class="lineno">   19</span>&#160;</div><div class="line"><a name="l00024"></a><span class="lineno">   24</span>&#160;        <span class="keyword">namespace </span><a class="code" href="namespace_micro.php">Micro</a> {</div><div class="line"><a name="l00025"></a><span class="lineno">   25</span>&#160;</div><div class="line"><a name="l00030"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_fix_effect.php">   30</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php">FixEffect</a> : <span class="keyword">public</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_effect.php">Effect</a> {</div><div class="line"><a name="l00031"></a><span class="lineno">   31</span>&#160;                <span class="keyword">private</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00032"></a><span class="lineno">   32</span>&#160;                    <a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData&lt;Color&gt;</a>&amp; color; </div><div class="line"><a name="l00034"></a><span class="lineno">   34</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00035"></a><span class="lineno">   35</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00039"></a><span class="lineno">   39</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#a5fdc41f5b8f1e4ffa942b9e99ff16739">FixEffect</a>() = <span class="keyword">delete</span>;</div><div class="line"><a name="l00044"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aed48cc3b728a40c36ef60aa5491bf49b">   44</a></span>&#160;                        <a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aed48cc3b728a40c36ef60aa5491bf49b">FixEffect</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData&lt;Color&gt;</a>&amp; c) : color(c) {</div><div class="line"><a name="l00045"></a><span class="lineno">   45</span>&#160;                        }</div><div class="line"><a name="l00046"></a><span class="lineno">   46</span>&#160;</div><div class="line"><a name="l00047"></a><span class="lineno">   47</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00051"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#acd3cec3a646da0655464290af02947a5">   51</a></span>&#160;<span class="comment"></span>                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#acd3cec3a646da0655464290af02947a5">start</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00052"></a><span class="lineno">   52</span>&#160;                            controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(color);</div><div class="line"><a name="l00053"></a><span class="lineno">   53</span>&#160;                        }</div><div class="line"><a name="l00057"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#a1accc8bbcfbc1ac2fef3e10bb2ed7f2e">   57</a></span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#a1accc8bbcfbc1ac2fef3e10bb2ed7f2e">run</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00058"></a><span class="lineno">   58</span>&#160;                        }</div><div class="line"><a name="l00062"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aca4d9553c6b265f7b6f4add0ff1dd3ca">   62</a></span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aca4d9553c6b265f7b6f4add0ff1dd3ca">stop</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00063"></a><span class="lineno">   63</span>&#160;                            controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(BLACK);</div><div class="line"><a name="l00064"></a><span class="lineno">   64</span>&#160;                        }</div><div class="line"><a name="l00065"></a><span class="lineno">   65</span>&#160;            };</div><div class="line"><a name="l00066"></a><span class="lineno">   66</span>&#160;</div><div class="line"><a name="l00067"></a><span class="lineno">   67</span>&#160;        }</div><div class="line"><a name="l00068"></a><span class="lineno">   68</span>&#160;    }</div><div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php">NRE::Micro::FixEffect</a></div><div class="ttdoc">Represent a fix light effect, setting all leds to the same color with no movement. </div><div class="ttdef"><b>Definition:</b> NRE_FixEffect.hpp:30</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php_aca4d9553c6b265f7b6f4add0ff1dd3ca"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aca4d9553c6b265f7b6f4add0ff1dd3ca">NRE::Micro::FixEffect::stop</a></div><div class="ttdeci">void stop(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_FixEffect.hpp:62</div></div>
<div class="ttc" id="namespace_micro_php"><div class="ttname"><a href="namespace_micro.php">Micro</a></div><div class="ttdoc">Micro&amp;#39;s API. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_led_controller_php_a89faff70fae2c66177362d25e6f1ce80"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">NRE::Micro::LedController::setColor</a></div><div class="ttdeci">void setColor(Color const &amp;color)</div><div class="ttdef"><b>Definition:</b> NRE_LedControllerInl.hpp:79</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php_aed48cc3b728a40c36ef60aa5491bf49b"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php#aed48cc3b728a40c36ef60aa5491bf49b">NRE::Micro::FixEffect::FixEffect</a></div><div class="ttdeci">FixEffect(ObservedData&lt; Color &gt; &amp;c)</div><div class="ttdef"><b>Definition:</b> NRE_FixEffect.hpp:44</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php_a5fdc41f5b8f1e4ffa942b9e99ff16739"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php#a5fdc41f5b8f1e4ffa942b9e99ff16739">NRE::Micro::FixEffect::FixEffect</a></div><div class="ttdeci">FixEffect()=delete</div></div>
<div class="ttc" id="namespace_n_r_e_php"><div class="ttname"><a href="namespace_n_r_e.php">NRE</a></div><div class="ttdoc">The NearlyRealEngine&amp;#39;s global namespace. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.cpp:12</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_led_controller_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_led_controller.php">NRE::Micro::LedController</a></div><div class="ttdoc">Manage access to a led component. </div><div class="ttdef"><b>Definition:</b> NRE_LedController.hpp:125</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php_acd3cec3a646da0655464290af02947a5"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php#acd3cec3a646da0655464290af02947a5">NRE::Micro::FixEffect::start</a></div><div class="ttdeci">void start(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_FixEffect.hpp:51</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_effect_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_effect.php">NRE::Micro::Effect</a></div><div class="ttdoc">Represent a light effect. </div><div class="ttdef"><b>Definition:</b> NRE_Effect.hpp:30</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_fix_effect_php_a1accc8bbcfbc1ac2fef3e10bb2ed7f2e"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_fix_effect.php#a1accc8bbcfbc1ac2fef3e10bb2ed7f2e">NRE::Micro::FixEffect::run</a></div><div class="ttdeci">void run(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_FixEffect.hpp:57</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_observed_data_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_observed_data.php">NRE::Micro::ObservedData</a></div><div class="ttdoc">Represent an observed data by the internal ROM if used, allowing an automatic update between RAM and ...</div><div class="ttdef"><b>Definition:</b> NRE_RomManager.hpp:64</div></div>
</div><!-- fragment --></div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>
