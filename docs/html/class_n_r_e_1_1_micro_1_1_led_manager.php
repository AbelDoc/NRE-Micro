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
        <title>NRE-Micro: NRE::Micro::LedManager Class Reference</title>
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
      <li class="current"><a href="annotated.php"><span>Classes</span></a></li>
      <li><a href="files.php"><span>Files</span></a></li>
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
      <li><a href="annotated.php"><span>Class&#160;List</span></a></li>
      <li><a href="classes.php"><span>Class&#160;Index</span></a></li>
      <li><a href="hierarchy.php"><span>Class&#160;Hierarchy</span></a></li>
      <li><a href="functions.php"><span>Class&#160;Members</span></a></li>
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
<li class="navelem"><a class="el" href="namespace_n_r_e.php">NRE</a></li><li class="navelem"><b>Micro</b></li><li class="navelem"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php">LedManager</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="summary">
<a href="#pub-methods">Public Member Functions</a> &#124;
<a href="class_n_r_e_1_1_micro_1_1_led_manager-members.php">List of all members</a>  </div>
  <div class="headertitle">
<div class="title">NRE::Micro::LedManager Class Reference</div>  </div>
</div><!--header-->
<div class="contents">

<p>Manage all leds controller.  
 <a href="class_n_r_e_1_1_micro_1_1_led_manager.php#details">More...</a></p>

<p><code>#include &lt;<a class="el" href="_n_r_e___led_manager_8hpp_source.php">NRE_LedManager.hpp</a>&gt;</code></p>
<div class="dynheader">
Inheritance diagram for NRE::Micro::LedManager:</div>
<div class="dyncontent">
 <div class="center">
  <img src="class_n_r_e_1_1_micro_1_1_led_manager.png" usemap="#NRE::Micro::LedManager_map" alt=""/>
  <map id="NRE::Micro::LedManager_map" name="NRE::Micro::LedManager_map">
<area href="class_n_r_e_1_1_micro_1_1_module.php" alt="NRE::Micro::Module&lt; LedManager &gt;" shape="rect" coords="0,56,220,80"/>
<area href="class_n_r_e_1_1_micro_1_1_abstract_module.php" title="Represent an abstract module used to active a certain part of the framework. " alt="NRE::Micro::AbstractModule" shape="rect" coords="0,0,220,24"/>
</map>
 </div></div>
<table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="pub-methods"></a>
Public Member Functions</h2></td></tr>
<tr class="memitem:a98cb708bb00b9eeed825c584428305ab"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php#a98cb708bb00b9eeed825c584428305ab">LedManager</a> ()=default</td></tr>
<tr class="separator:a98cb708bb00b9eeed825c584428305ab"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:aa13e06d999087f6f193f4804419d86a0"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php#aa13e06d999087f6f193f4804419d86a0">~LedManager</a> ()</td></tr>
<tr class="separator:aa13e06d999087f6f193f4804419d86a0"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:aa64ef572a79d594e67843ee27bf74b46"><td class="memItemLeft" align="right" valign="top"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a> &amp;&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php#aa64ef572a79d594e67843ee27bf74b46">getController</a> (unsigned char id)</td></tr>
<tr class="separator:aa64ef572a79d594e67843ee27bf74b46"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:aa778378bc85b3894103d1eabb5a80cd3"><td class="memItemLeft" align="right" valign="top">unsigned char&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php#aa778378bc85b3894103d1eabb5a80cd3">addController</a> (LedId nb, Pin pin, neoPixelType type=NEO_GRB+NEO_KHZ800)</td></tr>
<tr class="separator:aa778378bc85b3894103d1eabb5a80cd3"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a72b0073aef8f0e38e59fd141d719acc2"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php#a72b0073aef8f0e38e59fd141d719acc2">setup</a> () override</td></tr>
<tr class="separator:a72b0073aef8f0e38e59fd141d719acc2"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="inherit_header pub_methods_class_n_r_e_1_1_micro_1_1_module"><td colspan="2" onclick="javascript:toggleInherit('pub_methods_class_n_r_e_1_1_micro_1_1_module')"><img src="closed.png" alt="-"/>&#160;Public Member Functions inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module&lt; LedManager &gt;</a></td></tr>
<tr class="memitem:ab8051683526e308ef6d0c878ccfb9fe2 inherit pub_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php#ab8051683526e308ef6d0c878ccfb9fe2">Module</a> ()</td></tr>
<tr class="separator:ab8051683526e308ef6d0c878ccfb9fe2 inherit pub_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ab4e431b60f84d4b499c9315cf4502f4b inherit pub_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memItemLeft" align="right" valign="top">virtual&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php#ab4e431b60f84d4b499c9315cf4502f4b">~Module</a> ()=default</td></tr>
<tr class="separator:ab4e431b60f84d4b499c9315cf4502f4b inherit pub_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="inherit_header pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td colspan="2" onclick="javascript:toggleInherit('pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module')"><img src="closed.png" alt="-"/>&#160;Public Member Functions inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">NRE::Micro::AbstractModule</a></td></tr>
<tr class="memitem:aa3db66bc689eb07168e52157e6cf1702 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#aa3db66bc689eb07168e52157e6cf1702">AbstractModule</a> ()=default</td></tr>
<tr class="separator:aa3db66bc689eb07168e52157e6cf1702 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a38f613f697ca8d200a1a270e03967d04 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">virtual&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a38f613f697ca8d200a1a270e03967d04">~AbstractModule</a> ()=default</td></tr>
<tr class="separator:a38f613f697ca8d200a1a270e03967d04 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a6aef5a0cbb4fb0b08e8b77f3ff5076b0 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a6aef5a0cbb4fb0b08e8b77f3ff5076b0">AbstractModule</a> (<a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> const &amp;m)=delete</td></tr>
<tr class="separator:a6aef5a0cbb4fb0b08e8b77f3ff5076b0 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ad67ca9dc2add373f389afa03d17e3c0f inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#ad67ca9dc2add373f389afa03d17e3c0f">AbstractModule</a> (<a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&amp;m)=delete</td></tr>
<tr class="separator:ad67ca9dc2add373f389afa03d17e3c0f inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a62533d0ef5768f92707d413d53fb3904 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">virtual void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a62533d0ef5768f92707d413d53fb3904">loop</a> ()</td></tr>
<tr class="separator:a62533d0ef5768f92707d413d53fb3904 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a2452ab1a95d5dd5c4305605ed4243492 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a2452ab1a95d5dd5c4305605ed4243492">operator=</a> (<a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> const &amp;m)=delete</td></tr>
<tr class="separator:a2452ab1a95d5dd5c4305605ed4243492 inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a2f01e20c0f30f2e706af1dfdea3b591b inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a2f01e20c0f30f2e706af1dfdea3b591b">operator=</a> (<a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">AbstractModule</a> &amp;&amp;m)=delete</td></tr>
<tr class="separator:a2f01e20c0f30f2e706af1dfdea3b591b inherit pub_methods_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table><table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="inherited"></a>
Additional Inherited Members</h2></td></tr>
<tr class="inherit_header pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td colspan="2" onclick="javascript:toggleInherit('pub_static_methods_class_n_r_e_1_1_micro_1_1_module')"><img src="closed.png" alt="-"/>&#160;Static Public Member Functions inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module&lt; LedManager &gt;</a></td></tr>
<tr class="memitem:a6d9a8c837f180ffd064224d06d9f42e4 inherit pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memItemLeft" align="right" valign="top">static ModuleId&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php#a6d9a8c837f180ffd064224d06d9f42e4">getId</a> ()</td></tr>
<tr class="separator:a6d9a8c837f180ffd064224d06d9f42e4 inherit pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="inherit_header pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td colspan="2" onclick="javascript:toggleInherit('pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module')"><img src="closed.png" alt="-"/>&#160;Static Public Attributes inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">NRE::Micro::AbstractModule</a></td></tr>
<tr class="memitem:a95d15910d0d4e77aa08063fe383ff8dc inherit pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">static ModuleId&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a95d15910d0d4e77aa08063fe383ff8dc">counter</a> = 0</td></tr>
<tr class="separator:a95d15910d0d4e77aa08063fe383ff8dc inherit pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table>
<a name="details" id="details"></a><h2 class="groupheader">Detailed Description</h2>
<div class="textblock"><p>Manage all leds controller. </p>
</div><h2 class="groupheader">Constructor &amp; Destructor Documentation</h2>
<a class="anchor" id="a98cb708bb00b9eeed825c584428305ab"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">NRE::Micro::LedManager::LedManager </td>
          <td>(</td>
          <td class="paramname"></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">default</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">
<p>Construct the led module </p>

</div>
</div>
<a class="anchor" id="aa13e06d999087f6f193f4804419d86a0"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">NRE::Micro::LedManager::~LedManager </td>
          <td>(</td>
          <td class="paramname"></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">inline</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">
<p><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php" title="Manage all leds controller. ">LedManager</a> Deconstructor </p>

</div>
</div>
<h2 class="groupheader">Member Function Documentation</h2>
<a class="anchor" id="aa778378bc85b3894103d1eabb5a80cd3"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">unsigned char NRE::Micro::LedManager::addController </td>
          <td>(</td>
          <td class="paramtype">LedId&#160;</td>
          <td class="paramname"><em>nb</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">Pin&#160;</td>
          <td class="paramname"><em>pin</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">neoPixelType&#160;</td>
          <td class="paramname"><em>type</em> = <code>NEO_GRB&#160;+&#160;NEO_KHZ800</code>&#160;</td>
        </tr>
        <tr>
          <td></td>
          <td>)</td>
          <td></td><td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">inline</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">
<p>Add a led controller </p><dl class="params"><dt>Parameters</dt><dd>
  <table class="params">
    <tr><td class="paramname">nb</td><td>the number of led </td></tr>
    <tr><td class="paramname">pin</td><td>the leds strip pin </td></tr>
    <tr><td class="paramname">type</td><td>the leds type </td></tr>
  </table>
  </dd>
</dl>
<dl class="section return"><dt>Returns</dt><dd>the controller id </dd></dl>

</div>
</div>
<a class="anchor" id="aa64ef572a79d594e67843ee27bf74b46"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname"><a class="el" href="class_n_r_e_1_1_micro_1_1_led_controller.php">LedController</a> &amp; NRE::Micro::LedManager::getController </td>
          <td>(</td>
          <td class="paramtype">unsigned char&#160;</td>
          <td class="paramname"><em>id</em></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">inline</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">
<p>Query a led controller </p><dl class="params"><dt>Parameters</dt><dd>
  <table class="params">
    <tr><td class="paramname">id</td><td>the controller id </td></tr>
  </table>
  </dd>
</dl>
<dl class="section return"><dt>Returns</dt><dd>the corresponding controller </dd></dl>

</div>
</div>
<a class="anchor" id="a72b0073aef8f0e38e59fd141d719acc2"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void NRE::Micro::LedManager::setup </td>
          <td>(</td>
          <td class="paramname"></td><td>)</td>
          <td></td>
        </tr>
      </table>
  </td>
  <td class="mlabels-right">
<span class="mlabels"><span class="mlabel">inline</span><span class="mlabel">override</span><span class="mlabel">virtual</span></span>  </td>
  </tr>
</table>
</div><div class="memdoc">
<p>Setup the module </p>

<p>Reimplemented from <a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a8f93564ffc4fa3818c765b6eed3ab083">NRE::Micro::AbstractModule</a>.</p>

</div>
</div>
<hr/>The documentation for this class was generated from the following files:<ul>
<li>/mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/LED/Manager/<a class="el" href="_n_r_e___led_manager_8hpp_source.php">NRE_LedManager.hpp</a></li>
<li>/mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/LED/Manager/<a class="el" href="_n_r_e___led_manager_inl_8hpp_source.php">NRE_LedManagerInl.hpp</a></li>
</ul>
</div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>
