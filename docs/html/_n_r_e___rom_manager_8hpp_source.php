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
        <title>NRE-Micro: /mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/ROM/Manager/NRE_RomManager.hpp Source File</title>
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
<li class="navelem"><a class="el" href="dir_68267d1309a1af8e8297ef4c3efbcdba.php">src</a></li><li class="navelem"><a class="el" href="dir_b8c575fbce9e88769cd973c21567fab3.php">ROM</a></li><li class="navelem"><a class="el" href="dir_6fd6a1e3d1cabd12d4d22f426f330e02.php">Manager</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="headertitle">
<div class="title">NRE_RomManager.hpp</div>  </div>
</div><!--header-->
<div class="contents">
<a href="_n_r_e___rom_manager_8hpp.php">Go to the documentation of this file.</a><div class="fragment"><div class="line"><a name="l00001"></a><span class="lineno">    1</span>&#160;</div><div class="line"><a name="l00010"></a><span class="lineno">   10</span>&#160;<span class="preprocessor">     #pragma once</span></div><div class="line"><a name="l00011"></a><span class="lineno">   11</span>&#160;</div><div class="line"><a name="l00012"></a><span class="lineno">   12</span>&#160;<span class="preprocessor">     #include &quot;../../Core/Module/NRE_Module.hpp&quot;</span></div><div class="line"><a name="l00013"></a><span class="lineno">   13</span>&#160;</div><div class="line"><a name="l00014"></a><span class="lineno">   14</span>&#160;<span class="preprocessor">     #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00015"></a><span class="lineno">   15</span>&#160;<span class="preprocessor">        #include &lt;EEPROM.h&gt;</span></div><div class="line"><a name="l00016"></a><span class="lineno">   16</span>&#160;<span class="preprocessor">     #endif</span></div><div class="line"><a name="l00017"></a><span class="lineno">   17</span>&#160;</div><div class="line"><a name="l00018"></a><span class="lineno">   18</span>&#160;<span class="preprocessor">     #include &lt;vector&gt;</span></div><div class="line"><a name="l00019"></a><span class="lineno">   19</span>&#160;</div><div class="line"><a name="l00024"></a><span class="lineno">   24</span>&#160;    <span class="keyword">namespace </span><a class="code" href="namespace_n_r_e.php">NRE</a> {</div><div class="line"><a name="l00025"></a><span class="lineno">   25</span>&#160;</div><div class="line"><a name="l00030"></a><span class="lineno">   30</span>&#160;        <span class="keyword">namespace </span><a class="code" href="namespace_micro.php">Micro</a> {</div><div class="line"><a name="l00031"></a><span class="lineno">   31</span>&#160;</div><div class="line"><a name="l00036"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_abstract_data.php">   36</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_data.php">AbstractData</a> {</div><div class="line"><a name="l00037"></a><span class="lineno">   37</span>&#160;                <span class="keyword">public</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00038"></a><span class="lineno">   38</span>&#160;<span class="preprocessor">                    #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00039"></a><span class="lineno">   39</span>&#160;                        <span class="keywordtype">int</span> ptr;  </div><div class="line"><a name="l00040"></a><span class="lineno">   40</span>&#160;<span class="preprocessor">                    #endif</span></div><div class="line"><a name="l00041"></a><span class="lineno">   41</span>&#160;</div><div class="line"><a name="l00042"></a><span class="lineno">   42</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00043"></a><span class="lineno">   43</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00047"></a><span class="lineno">   47</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_data.php#ace46a0e36fc28878ffa0e26c7bd27a10">AbstractData</a>() = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00048"></a><span class="lineno">   48</span>&#160;</div><div class="line"><a name="l00049"></a><span class="lineno">   49</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00050"></a><span class="lineno">   50</span>&#160;<span class="preprocessor">                        #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00051"></a><span class="lineno">   51</span>&#160;</div><div class="line"><a name="l00055"></a><span class="lineno">   55</span>&#160;                            <span class="keyword">virtual</span> <span class="keywordtype">void</span> read(<span class="keywordtype">void</span>* ptr) = 0;</div><div class="line"><a name="l00056"></a><span class="lineno">   56</span>&#160;<span class="preprocessor">                        #endif</span></div><div class="line"><a name="l00057"></a><span class="lineno">   57</span>&#160;            };</div><div class="line"><a name="l00058"></a><span class="lineno">   58</span>&#160;</div><div class="line"><a name="l00063"></a><span class="lineno">   63</span>&#160;            <span class="keyword">template</span> &lt;<span class="keyword">class</span> T&gt;</div><div class="line"><a name="l00064"></a><span class="lineno"><a class="line" href="class_n_r_e_1_1_micro_1_1_observed_data.php">   64</a></span>&#160;            <span class="keyword">class </span><a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData</a> : <span class="keyword">public</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_abstract_data.php">AbstractData</a> {</div><div class="line"><a name="l00065"></a><span class="lineno">   65</span>&#160;                <span class="keyword">private</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00066"></a><span class="lineno">   66</span>&#160;                    T data;                         </div><div class="line"><a name="l00067"></a><span class="lineno">   67</span>&#160;                    std::function&lt;void(T&amp;)&gt; handle; </div><div class="line"><a name="l00069"></a><span class="lineno">   69</span>&#160;                <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00070"></a><span class="lineno">   70</span>&#160;                    <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00074"></a><span class="lineno">   74</span>&#160;<span class="comment"></span>                        <a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData</a>();</div><div class="line"><a name="l00079"></a><span class="lineno">   79</span>&#160;                        <span class="keyword">template</span> &lt;<span class="keyword">class </span>... Args&gt;</div><div class="line"><a name="l00080"></a><span class="lineno">   80</span>&#160;                        <a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData</a>(Args &amp;&amp; ... args);</div><div class="line"><a name="l00081"></a><span class="lineno">   81</span>&#160;</div><div class="line"><a name="l00082"></a><span class="lineno">   82</span>&#160;                    <span class="comment">//## Copy Constructor ##//</span></div><div class="line"><a name="l00087"></a><span class="lineno">   87</span>&#160;<span class="comment"></span>                        ObservedData(ObservedData <span class="keyword">const</span>&amp; d) = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00088"></a><span class="lineno">   88</span>&#160;</div><div class="line"><a name="l00089"></a><span class="lineno">   89</span>&#160;                    <span class="comment">//## Move Constructor ##//</span></div><div class="line"><a name="l00094"></a><span class="lineno">   94</span>&#160;<span class="comment"></span>                        ObservedData(ObservedData &amp;&amp; d) = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00095"></a><span class="lineno">   95</span>&#160;</div><div class="line"><a name="l00096"></a><span class="lineno">   96</span>&#160;                    <span class="comment">//## Deconstructor ##//</span></div><div class="line"><a name="l00100"></a><span class="lineno">  100</span>&#160;<span class="comment"></span>                        ~ObservedData() = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00101"></a><span class="lineno">  101</span>&#160;</div><div class="line"><a name="l00102"></a><span class="lineno">  102</span>&#160;                    <span class="comment">//## Getter ##//</span></div><div class="line"><a name="l00106"></a><span class="lineno">  106</span>&#160;<span class="comment"></span>                        uint32_t getSize() <span class="keyword">const</span>;</div><div class="line"><a name="l00110"></a><span class="lineno">  110</span>&#160;                        T&amp; <span class="keyword">get</span>();</div><div class="line"><a name="l00114"></a><span class="lineno">  114</span>&#160;                        T <span class="keyword">const</span>&amp; <span class="keyword">get</span>() <span class="keyword">const</span>;</div><div class="line"><a name="l00115"></a><span class="lineno">  115</span>&#160;</div><div class="line"><a name="l00116"></a><span class="lineno">  116</span>&#160;                    <span class="comment">//## Setter ##//</span></div><div class="line"><a name="l00121"></a><span class="lineno">  121</span>&#160;<span class="comment"></span>                        <span class="keywordtype">void</span> setHandle(std::function&lt;<span class="keywordtype">void</span>(T&amp;)&gt; h);</div><div class="line"><a name="l00122"></a><span class="lineno">  122</span>&#160;</div><div class="line"><a name="l00123"></a><span class="lineno">  123</span>&#160;                    <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00127"></a><span class="lineno">  127</span>&#160;<span class="comment"></span>                        <span class="keywordtype">void</span> update();</div><div class="line"><a name="l00128"></a><span class="lineno">  128</span>&#160;<span class="preprocessor">                        #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00129"></a><span class="lineno">  129</span>&#160;</div><div class="line"><a name="l00133"></a><span class="lineno">  133</span>&#160;                            <span class="keywordtype">void</span> read(<span class="keywordtype">void</span>* ptr) <span class="keyword">override</span>;</div><div class="line"><a name="l00134"></a><span class="lineno">  134</span>&#160;<span class="preprocessor">                        #endif</span></div><div class="line"><a name="l00135"></a><span class="lineno">  135</span>&#160;</div><div class="line"><a name="l00136"></a><span class="lineno">  136</span>&#160;                    <span class="comment">//## Assignment Operator ##//</span></div><div class="line"><a name="l00142"></a><span class="lineno">  142</span>&#160;<span class="comment"></span>                        ObservedData&amp; operator=(ObservedData <span class="keyword">const</span>&amp; d) = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00148"></a><span class="lineno">  148</span>&#160;                        ObservedData&amp; operator=(ObservedData &amp;&amp; d) = <span class="keywordflow">default</span>;</div><div class="line"><a name="l00154"></a><span class="lineno">  154</span>&#160;                        ObservedData&amp; operator=(T <span class="keyword">const</span>&amp; d);</div><div class="line"><a name="l00160"></a><span class="lineno">  160</span>&#160;                        ObservedData&amp; operator=(T &amp;&amp; d);</div><div class="line"><a name="l00161"></a><span class="lineno">  161</span>&#160;            };</div><div class="line"><a name="l00162"></a><span class="lineno">  162</span>&#160;</div><div class="line"><a name="l00163"></a><span class="lineno">  163</span>&#160;<span class="preprocessor">            #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00164"></a><span class="lineno">  164</span>&#160;</div><div class="line"><a name="l00169"></a><span class="lineno">  169</span>&#160;                <span class="keyword">class </span>RomManager : <span class="keyword">public</span> <a class="code" href="class_n_r_e_1_1_micro_1_1_module.php">Module</a>&lt;RomManager&gt; {</div><div class="line"><a name="l00170"></a><span class="lineno">  170</span>&#160;                    <span class="keyword">private</span> :   <span class="comment">// Fields</span></div><div class="line"><a name="l00171"></a><span class="lineno">  171</span>&#160;                        std::vector&lt;AbstractData*&gt; objects;  </div><div class="line"><a name="l00172"></a><span class="lineno">  172</span>&#160;                        <span class="keywordtype">int</span> currentPtr;</div><div class="line"><a name="l00173"></a><span class="lineno">  173</span>&#160;</div><div class="line"><a name="l00174"></a><span class="lineno">  174</span>&#160;                    <span class="keyword">public</span> :    <span class="comment">// Methods</span></div><div class="line"><a name="l00175"></a><span class="lineno">  175</span>&#160;                        <span class="comment">//## Constructor ##//</span></div><div class="line"><a name="l00179"></a><span class="lineno">  179</span>&#160;<span class="comment"></span>                            RomManager();</div><div class="line"><a name="l00180"></a><span class="lineno">  180</span>&#160;</div><div class="line"><a name="l00181"></a><span class="lineno">  181</span>&#160;                        <span class="comment">//## Methods ##//</span></div><div class="line"><a name="l00186"></a><span class="lineno">  186</span>&#160;<span class="comment"></span>                            <span class="keyword">template</span> &lt;<span class="keyword">class</span> T&gt;</div><div class="line"><a name="l00187"></a><span class="lineno">  187</span>&#160;                            <span class="keywordtype">void</span> addData(<a class="code" href="class_n_r_e_1_1_micro_1_1_observed_data.php">ObservedData&lt;T&gt;</a>&amp; data);</div><div class="line"><a name="l00191"></a><span class="lineno">  191</span>&#160;                            <span class="keywordtype">void</span> clearROM();</div><div class="line"><a name="l00195"></a><span class="lineno">  195</span>&#160;                            <span class="keywordtype">void</span> loadROM();</div><div class="line"><a name="l00199"></a><span class="lineno">  199</span>&#160;                            <span class="keywordtype">void</span> resetROM();</div><div class="line"><a name="l00204"></a><span class="lineno">  204</span>&#160;                            <span class="keyword">template</span> &lt;<span class="keyword">class</span> T&gt;</div><div class="line"><a name="l00205"></a><span class="lineno">  205</span>&#160;                            <span class="keywordtype">void</span> write(T* data, <span class="keywordtype">int</span> addr);</div><div class="line"><a name="l00209"></a><span class="lineno">  209</span>&#160;                            <span class="keywordtype">void</span> setup() <span class="keyword">override</span>;</div><div class="line"><a name="l00210"></a><span class="lineno">  210</span>&#160;</div><div class="line"><a name="l00211"></a><span class="lineno">  211</span>&#160;                    <span class="keyword">public</span> :    <span class="comment">// Static</span></div><div class="line"><a name="l00212"></a><span class="lineno">  212</span>&#160;                        <span class="keyword">static</span> constexpr <span class="keywordtype">int</span> MAX_ADDR = 4096;</div><div class="line"><a name="l00213"></a><span class="lineno">  213</span>&#160;                        <span class="keyword">static</span> constexpr <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> FILL_SYMBOL  = 0x00;</div><div class="line"><a name="l00214"></a><span class="lineno">  214</span>&#160;                        <span class="keyword">static</span> constexpr <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> START_SYMBOL = 0x4E; <span class="comment">// N</span></div><div class="line"><a name="l00215"></a><span class="lineno">  215</span>&#160;                        <span class="keyword">static</span> constexpr <span class="keywordtype">unsigned</span> <span class="keywordtype">char</span> RESET_SYMBOl = 0x52; <span class="comment">// R</span></div><div class="line"><a name="l00216"></a><span class="lineno">  216</span>&#160;                };</div><div class="line"><a name="l00217"></a><span class="lineno">  217</span>&#160;</div><div class="line"><a name="l00218"></a><span class="lineno">  218</span>&#160;                <span class="keyword">static</span> RomManager _RomManager;</div><div class="line"><a name="l00219"></a><span class="lineno">  219</span>&#160;</div><div class="line"><a name="l00220"></a><span class="lineno">  220</span>&#160;<span class="preprocessor">            #endif</span></div><div class="line"><a name="l00221"></a><span class="lineno">  221</span>&#160;        }</div><div class="line"><a name="l00222"></a><span class="lineno">  222</span>&#160;    }</div><div class="line"><a name="l00223"></a><span class="lineno">  223</span>&#160;</div><div class="line"><a name="l00224"></a><span class="lineno">  224</span>&#160;<span class="preprocessor">    #ifdef NRE_USE_ROM</span></div><div class="line"><a name="l00225"></a><span class="lineno">  225</span>&#160;<span class="preprocessor">        #include &quot;<a class="code" href="_n_r_e___rom_manager_inl_8hpp.php">NRE_RomManagerInl.hpp</a>&quot;</span></div><div class="line"><a name="l00226"></a><span class="lineno">  226</span>&#160;<span class="preprocessor">    #endif</span></div><div class="line"><a name="l00227"></a><span class="lineno">  227</span>&#160;</div><div class="line"><a name="l00228"></a><span class="lineno">  228</span>&#160;<span class="preprocessor">    #include &quot;<a class="code" href="_n_r_e___observed_data_inl_8hpp.php">NRE_ObservedDataInl.hpp</a>&quot;</span></div><div class="ttc" id="_n_r_e___observed_data_inl_8hpp_php"><div class="ttname"><a href="_n_r_e___observed_data_inl_8hpp.php">NRE_ObservedDataInl.hpp</a></div><div class="ttdoc">Implementation of Micro&amp;#39;s API&amp;#39;s Core Object : ObservedData. </div></div>
<div class="ttc" id="namespace_micro_php"><div class="ttname"><a href="namespace_micro.php">Micro</a></div><div class="ttdoc">Micro&amp;#39;s API. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_data_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_data.php">NRE::Micro::AbstractData</a></div><div class="ttdoc">Represent an abstract data. </div><div class="ttdef"><b>Definition:</b> NRE_RomManager.hpp:36</div></div>
<div class="ttc" id="namespace_n_r_e_php"><div class="ttname"><a href="namespace_n_r_e.php">NRE</a></div><div class="ttdoc">The NearlyRealEngine&amp;#39;s global namespace. </div><div class="ttdef"><b>Definition:</b> NRE_AbstractModule.cpp:12</div></div>
<div class="ttc" id="_n_r_e___rom_manager_inl_8hpp_php"><div class="ttname"><a href="_n_r_e___rom_manager_inl_8hpp.php">NRE_RomManagerInl.hpp</a></div><div class="ttdoc">Implementation of Micro&amp;#39;s API&amp;#39;s Object : RomManager. </div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_abstract_data_php_ace46a0e36fc28878ffa0e26c7bd27a10"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_abstract_data.php#ace46a0e36fc28878ffa0e26c7bd27a10">NRE::Micro::AbstractData::AbstractData</a></div><div class="ttdeci">AbstractData()=default</div></div>
<div class="ttc" id="class_n_r_e_1_1_micro_1_1_module_php"><div class="ttname"><a href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module</a></div><div class="ttdoc">Represent a module interface to create framework sub module. </div><div class="ttdef"><b>Definition:</b> NRE_Module.hpp:31</div></div>
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