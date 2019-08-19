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
        <title>NRE-Micro: /mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/LED/Effect/NRE_RotateFixEffect.hpp Source File</title>
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
<div class="title">NRE_RotateFixEffect.hpp</div>  </div>
</div><!--header-->
<div class="contents">
<a href="_n_r_e___rotate_fix_effect_8hpp.php">Go to the documentation of this file.</a><div class="fragment"><div class="line"><a name="l00001"></a><span class="lineno">    1</span>&#160;</div><div class="line"><a name="l00010"></a><span class="lineno">   10</span>&#160;<span class="preprocessor">     #pragma once</span></div><div class="line"><a name="l00011"></a><span class="lineno">   11</span>&#160;</div><div class="line"><a name="l00012"></a><span class="lineno">   12</span>&#160;<span class="preprocessor">     #include &quot;../Controller/NRE_LedController.hpp&quot;</span></div><div class="line"><a name="l00013"></a><span class="lineno">   13</span>&#160;</div><div class="line"><a name="l00018"></a><span class="lineno">   18</span>&#160;    <span class="keyword">namespace </span><a class="code" href="namespace_n_r_e.php">NRE</a> {</div><div class="line"><a name="l00019"></a><span class="lineno">   19</span>&#160;</div><div class="line"><a name="l00024"></a><span class="lineno">   24</span>&#160;        <span class="keyword">namespace </span><a class="code" href="namespace_micro.php">Micro</a> {</div><div class="line"><a name="l00025"></a><span class="lineno">   25</span>&#160;</div><div class="line"><a name="l00030"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php">   30</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php">RotateFixEffect</a> : <span class="keyword">public</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_effect.php">Effect</a> {</div><div class="line"><a name="l00031"></a><span class="lineno">   31</span>&#160;                <span class="keyword">private</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00032"></a><span class="lineno">   32</span>&#160;                    <a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData&lt;Color&gt;</a>&amp; color; </div><div class="line"><a name="l00033"></a><span class="lineno">   33</span>&#160;                    <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> speed;        </div><div class="line"><a name="l00034"></a><span class="lineno">   34</span>&#160;                    LedId current;              </div><div class="line"><a name="l00035"></a><span class="lineno">   35</span>&#160;                    <span class="keywordtype">unsigned</span> <span class="keywordtype">long</span> lastTime;     </div><div class="line"><a name="l00036"></a><span class="lineno">   36</span>&#160;                    <span class="keywordtype">bool</span> clockwise;             </div><div class="line"><a name="l00037"></a><span class="lineno">   37</span>&#160;                    <span class="keywordtype">bool</span> negateOrFill;          </div><div class="line"><a name="l00038"></a><span class="lineno">   38</span>&#160;                    <span class="keywordtype">bool</span> cycleComplete;         </div><div class="line"><a name="l00040"></a><span class="lineno">   40</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00041"></a><span class="lineno">   41</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00045"></a><span class="lineno">   45</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a187e56c8591563050743ae9847c524f8">RotateFixEffect</a>() = <span class="keyword">delete</span>;</div><div class="line"><a name="l00053"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#adac483f6f3ea2bb5306ee6a87a7fe7fb">   53</a></span>&#160;                        <a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#adac483f6f3ea2bb5306ee6a87a7fe7fb">RotateFixEffect</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData&lt;Color&gt;</a>&amp; c, <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> s = 5, <span class="keywordtype">bool</span> clockwiseEffect = <span class="keyword">true</span>, <span class="keywordtype">bool</span> negateOrFillEffect = <span class="keyword">false</span>) : color(c), speed(s), current(0), lastTime(0), clockwise(clockwiseEffect), negateOrFill(negateOrFillEffect), cycleComplete(false) {</div><div class="line"><a name="l00054"></a><span class="lineno">   54</span>&#160;                        }</div><div class="line"><a name="l00055"></a><span class="lineno">   55</span>&#160;</div><div class="line"><a name="l00056"></a><span class="lineno">   56</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00060"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a1834123e636878bdcf35c45bd258a407">   60</a></span>&#160;<span class="comment"></span>                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a1834123e636878bdcf35c45bd258a407">start</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00061"></a><span class="lineno">   61</span>&#160;                            controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(BLACK);</div><div class="line"><a name="l00062"></a><span class="lineno">   62</span>&#160;                        }</div><div class="line"><a name="l00066"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a79f9ca1a5b2bee5991558adef2a65341">   66</a></span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a79f9ca1a5b2bee5991558adef2a65341">run</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00067"></a><span class="lineno">   67</span>&#160;                            <span class="keywordtype">unsigned</span> <span class="keywordtype">long</span> time = micros();</div><div class="line"><a name="l00068"></a><span class="lineno">   68</span>&#160;                            <span class="keywordflow">if</span> (time - lastTime &lt;= 100 * speed) {</div><div class="line"><a name="l00069"></a><span class="lineno">   69</span>&#160;                                delay(100 * speed - (time - lastTime));</div><div class="line"><a name="l00070"></a><span class="lineno">   70</span>&#160;                            }</div><div class="line"><a name="l00071"></a><span class="lineno">   71</span>&#160;                            lastTime = time;</div><div class="line"><a name="l00072"></a><span class="lineno">   72</span>&#160;</div><div class="line"><a name="l00073"></a><span class="lineno">   73</span>&#160;                            <span class="keywordtype">int</span> next = static_cast &lt;<span class="keywordtype">int</span>&gt; (current);</div><div class="line"><a name="l00074"></a><span class="lineno">   74</span>&#160;</div><div class="line"><a name="l00075"></a><span class="lineno">   75</span>&#160;                            <span class="keywordflow">if</span> (clockwise) {</div><div class="line"><a name="l00076"></a><span class="lineno">   76</span>&#160;                                --next;</div><div class="line"><a name="l00077"></a><span class="lineno">   77</span>&#160;                                <span class="keywordflow">if</span> (next &lt; 0) {</div><div class="line"><a name="l00078"></a><span class="lineno">   78</span>&#160;                                    next = controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#acf67ef0f630bfc74d85ea0bb75e19c2c">getCount</a>() - 1;</div><div class="line"><a name="l00079"></a><span class="lineno">   79</span>&#160;                                    <span class="keywordflow">if</span> (!negateOrFill) {</div><div class="line"><a name="l00080"></a><span class="lineno">   80</span>&#160;                                        controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(BLACK);</div><div class="line"><a name="l00081"></a><span class="lineno">   81</span>&#160;                                    } <span class="keywordflow">else</span> {</div><div class="line"><a name="l00082"></a><span class="lineno">   82</span>&#160;                                        cycleComplete = !cycleComplete;</div><div class="line"><a name="l00083"></a><span class="lineno">   83</span>&#160;                                    }</div><div class="line"><a name="l00084"></a><span class="lineno">   84</span>&#160;                                }</div><div class="line"><a name="l00085"></a><span class="lineno">   85</span>&#160;                            } <span class="keywordflow">else</span> {</div><div class="line"><a name="l00086"></a><span class="lineno">   86</span>&#160;                                ++next;</div><div class="line"><a name="l00087"></a><span class="lineno">   87</span>&#160;                                <span class="keywordflow">if</span> (next &gt;= controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#acf67ef0f630bfc74d85ea0bb75e19c2c">getCount</a>()) {</div><div class="line"><a name="l00088"></a><span class="lineno">   88</span>&#160;                                    next = 0;</div><div class="line"><a name="l00089"></a><span class="lineno">   89</span>&#160;                                    <span class="keywordflow">if</span> (!negateOrFill) {</div><div class="line"><a name="l00090"></a><span class="lineno">   90</span>&#160;                                        controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(BLACK);</div><div class="line"><a name="l00091"></a><span class="lineno">   91</span>&#160;                                    } <span class="keywordflow">else</span> {</div><div class="line"><a name="l00092"></a><span class="lineno">   92</span>&#160;                                        cycleComplete = !cycleComplete;</div><div class="line"><a name="l00093"></a><span class="lineno">   93</span>&#160;                                    }</div><div class="line"><a name="l00094"></a><span class="lineno">   94</span>&#160;                                }</div><div class="line"><a name="l00095"></a><span class="lineno">   95</span>&#160;                            }</div><div class="line"><a name="l00096"></a><span class="lineno">   96</span>&#160;</div><div class="line"><a name="l00097"></a><span class="lineno">   97</span>&#160;                            current = static_cast &lt;LedId&gt; (next);</div><div class="line"><a name="l00098"></a><span class="lineno">   98</span>&#160;</div><div class="line"><a name="l00099"></a><span class="lineno">   99</span>&#160;                            <span class="keywordflow">if</span> (negateOrFill &amp;&amp; cycleComplete) {</div><div class="line"><a name="l00100"></a><span class="lineno">  100</span>&#160;                                controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(current, BLACK);</div><div class="line"><a name="l00101"></a><span class="lineno">  101</span>&#160;                            } <span class="keywordflow">else</span> {</div><div class="line"><a name="l00102"></a><span class="lineno">  102</span>&#160;                                controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(current, color);</div><div class="line"><a name="l00103"></a><span class="lineno">  103</span>&#160;                            }</div><div class="line"><a name="l00104"></a><span class="lineno">  104</span>&#160;                        }</div><div class="line"><a name="l00108"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a0914e8c393cef1837a39110f98e2383e">  108</a></span>&#160;                        <span class="keywordtype">void</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a0914e8c393cef1837a39110f98e2383e">stop</a>(<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a>&amp; controller)<span class="keyword"> override </span>{</div><div class="line"><a name="l00109"></a><span class="lineno">  109</span>&#160;                            controller.<a class="code" href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">setColor</a>(BLACK);</div><div class="line"><a name="l00110"></a><span class="lineno">  110</span>&#160;                        }</div><div class="line"><a name="l00111"></a><span class="lineno">  111</span>&#160;            };</div><div class="line"><a name="l00112"></a><span class="lineno">  112</span>&#160;</div><div class="line"><a name="l00113"></a><span class="lineno">  113</span>&#160;        }</div><div class="line"><a name="l00114"></a><span class="lineno">  114</span>&#160;    }</div><div class="ttc" id="class_n_r_e_1_1_micro_1_1_led_controller_php_acf67ef0f630bfc74d85ea0bb75e19c2c"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_led_controller.php#acf67ef0f630bfc74d85ea0bb75e19c2c">NRE::Micro::LedController::getCount</a></div><div class="ttdeci">LedId getCount() const </div><div class="ttdef"><b>Definition:</b> NRE_LedControllerInl.hpp:53</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php">NRE::Micro::RotateFixEffect</a></div><div class="ttdoc">Represent a rotate light effect, setting leds on one by one, leds remains on while the effect is runn...</div><div class="ttdef"><b>Definition:</b> NRE_RotateFixEffect.hpp:30</div></div>
<div class="ttc" id="namespace_micro_php"><div class="ttname"><a href="namespace_micro.php">Micro</a></div><div class="ttdoc">Micro&amp;#39;s API. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_led_controller_php_a89faff70fae2c66177362d25e6f1ce80"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_led_controller.php#a89faff70fae2c66177362d25e6f1ce80">NRE::Micro::LedController::setColor</a></div><div class="ttdeci">void setColor(Color const &amp;color)</div><div class="ttdef"><b>Definition:</b> NRE_LedControllerInl.hpp:79</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php_a187e56c8591563050743ae9847c524f8"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a187e56c8591563050743ae9847c524f8">NRE::Micro::RotateFixEffect::RotateFixEffect</a></div><div class="ttdeci">RotateFixEffect()=delete</div></div>
<div class="ttc" id="namespace_n_r_e_php"><div class="ttname"><a href="namespace_n_r_e.php">NRE</a></div><div class="ttdoc">The NearlyRealEngine&amp;#39;s global namespace. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.cpp:12</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php_a79f9ca1a5b2bee5991558adef2a65341"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a79f9ca1a5b2bee5991558adef2a65341">NRE::Micro::RotateFixEffect::run</a></div><div class="ttdeci">void run(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_RotateFixEffect.hpp:66</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php_adac483f6f3ea2bb5306ee6a87a7fe7fb"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#adac483f6f3ea2bb5306ee6a87a7fe7fb">NRE::Micro::RotateFixEffect::RotateFixEffect</a></div><div class="ttdeci">RotateFixEffect(ObservedData&lt; Color &gt; &amp;c, unsigned char s=5, bool clockwiseEffect=true, bool negateOrFillEffect=false)</div><div class="ttdef"><b>Definition:</b> NRE_RotateFixEffect.hpp:53</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_led_controller_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_led_controller.php">NRE::Micro::LedController</a></div><div class="ttdoc">Manage access to a led component. </div><div class="ttdef"><b>Definition:</b> NRE_LedController.hpp:125</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_effect_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_effect.php">NRE::Micro::Effect</a></div><div class="ttdoc">Represent a light effect. </div><div class="ttdef"><b>Definition:</b> NRE_Effect.hpp:30</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php_a0914e8c393cef1837a39110f98e2383e"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a0914e8c393cef1837a39110f98e2383e">NRE::Micro::RotateFixEffect::stop</a></div><div class="ttdeci">void stop(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_RotateFixEffect.hpp:108</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_observed_data_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_observed_data.php">NRE::Micro::ObservedData</a></div><div class="ttdoc">Represent an observed data by the internal ROM if used, allowing an automatic update between RAM and ...</div><div class="ttdef"><b>Definition:</b> NRE_RomManager.hpp:64</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_rotate_fix_effect_php_a1834123e636878bdcf35c45bd258a407"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php#a1834123e636878bdcf35c45bd258a407">NRE::Micro::RotateFixEffect::start</a></div><div class="ttdeci">void start(LedController &amp;controller) override</div><div class="ttdef"><b>Definition:</b> NRE_RotateFixEffect.hpp:60</div></div>
</div><!-- fragment --></div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>
