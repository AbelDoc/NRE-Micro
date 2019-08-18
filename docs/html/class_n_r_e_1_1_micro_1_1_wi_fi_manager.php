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
        <title>NRE-Micro: NRE::Micro::WiFiManager Class Reference</title>
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
<li class="navelem"><a class="el" href="namespace_n_r_e.php">NRE</a></li><li class="navelem"><b>Micro</b></li><li class="navelem"><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php">WiFiManager</a></li>  </ul>
</div>
</div><!-- top -->
<div class="header">
  <div class="summary">
<a href="#pub-methods">Public Member Functions</a> &#124;
<a href="class_n_r_e_1_1_micro_1_1_wi_fi_manager-members.php">List of all members</a>  </div>
  <div class="headertitle">
<div class="title">NRE::Micro::WiFiManager Class Reference</div>  </div>
</div><!--header-->
<div class="contents">

<p>Manage the wifi module with client/server and connection.  
 <a href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php#details">More...</a></p>

<p><code>#include &lt;<a class="el" href="_n_r_e___wi_fi_manager_8hpp_source.php">NRE_WiFiManager.hpp</a>&gt;</code></p>
<div class="dynheader">
Inheritance diagram for NRE::Micro::WiFiManager:</div>
<div class="dyncontent">
 <div class="center">
  <img src="class_n_r_e_1_1_micro_1_1_wi_fi_manager.png" usemap="#NRE::Micro::WiFiManager_map" alt=""/>
  <map id="NRE::Micro::WiFiManager_map" name="NRE::Micro::WiFiManager_map">
<area href="class_n_r_e_1_1_micro_1_1_module.php" alt="NRE::Micro::Module&lt; WiFiManager &gt;" shape="rect" coords="0,56,224,80"/>
<area href="class_n_r_e_1_1_micro_1_1_abstract_module.php" title="Represent an abstract module used to active a certain part of the framework. " alt="NRE::Micro::AbstractModule" shape="rect" coords="0,0,224,24"/>
</map>
 </div></div>
<table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a name="pub-methods"></a>
Public Member Functions</h2></td></tr>
<tr class="memitem:aadc9cdd35e4905e0a95144439ad579bd"><td class="memItemLeft" align="right" valign="top">&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php#aadc9cdd35e4905e0a95144439ad579bd">WiFiManager</a> ()=default</td></tr>
<tr class="separator:aadc9cdd35e4905e0a95144439ad579bd"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a9a0f001e36e296ed8036456560e741cd"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php#a9a0f001e36e296ed8036456560e741cd">setAPOnSetup</a> (String const &amp;name, String const &amp;pwd)</td></tr>
<tr class="separator:a9a0f001e36e296ed8036456560e741cd"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a3ccf7a64ec6ee3718b2eddf18c687c15"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php#a3ccf7a64ec6ee3718b2eddf18c687c15">addKnownNetwork</a> (String const &amp;name, String const &amp;pwd)</td></tr>
<tr class="separator:a3ccf7a64ec6ee3718b2eddf18c687c15"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:a4673d981d3a99bf6c6fe0926fb5bb8a6"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php#a4673d981d3a99bf6c6fe0926fb5bb8a6">setup</a> () override</td></tr>
<tr class="separator:a4673d981d3a99bf6c6fe0926fb5bb8a6"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="inherit_header pub_methods_class_n_r_e_1_1_micro_1_1_module"><td colspan="2" onclick="javascript:toggleInherit('pub_methods_class_n_r_e_1_1_micro_1_1_module')"><img src="closed.png" alt="-"/>&#160;Public Member Functions inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module&lt; WiFiManager &gt;</a></td></tr>
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
<tr class="inherit_header pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td colspan="2" onclick="javascript:toggleInherit('pub_static_methods_class_n_r_e_1_1_micro_1_1_module')"><img src="closed.png" alt="-"/>&#160;Static Public Member Functions inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_module.php">NRE::Micro::Module&lt; WiFiManager &gt;</a></td></tr>
<tr class="memitem:a6d9a8c837f180ffd064224d06d9f42e4 inherit pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memItemLeft" align="right" valign="top">static ModuleId&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php#a6d9a8c837f180ffd064224d06d9f42e4">getId</a> ()</td></tr>
<tr class="separator:a6d9a8c837f180ffd064224d06d9f42e4 inherit pub_static_methods_class_n_r_e_1_1_micro_1_1_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="inherit_header pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td colspan="2" onclick="javascript:toggleInherit('pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module')"><img src="closed.png" alt="-"/>&#160;Static Public Attributes inherited from <a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php">NRE::Micro::AbstractModule</a></td></tr>
<tr class="memitem:a95d15910d0d4e77aa08063fe383ff8dc inherit pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memItemLeft" align="right" valign="top">static ModuleId&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php#a95d15910d0d4e77aa08063fe383ff8dc">counter</a> = 0</td></tr>
<tr class="separator:a95d15910d0d4e77aa08063fe383ff8dc inherit pub_static_attribs_class_n_r_e_1_1_micro_1_1_abstract_module"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table>
<a name="details" id="details"></a><h2 class="groupheader">Detailed Description</h2>
<div class="textblock"><p>Manage the wifi module with client/server and connection. </p>
</div><h2 class="groupheader">Constructor &amp; Destructor Documentation</h2>
<a class="anchor" id="aadc9cdd35e4905e0a95144439ad579bd"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">NRE::Micro::WiFiManager::WiFiManager </td>
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
<p>Construct the wifi module </p>

</div>
</div>
<h2 class="groupheader">Member Function Documentation</h2>
<a class="anchor" id="a3ccf7a64ec6ee3718b2eddf18c687c15"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void NRE::Micro::WiFiManager::addKnownNetwork </td>
          <td>(</td>
          <td class="paramtype">String const &amp;&#160;</td>
          <td class="paramname"><em>name</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">String const &amp;&#160;</td>
          <td class="paramname"><em>pwd</em>&#160;</td>
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
<p>Add a known network, add them in priority order </p><dl class="params"><dt>Parameters</dt><dd>
  <table class="params">
    <tr><td class="paramname">name</td><td>the network name </td></tr>
    <tr><td class="paramname">pwd</td><td>the network password </td></tr>
  </table>
  </dd>
</dl>

</div>
</div>
<a class="anchor" id="a9a0f001e36e296ed8036456560e741cd"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void NRE::Micro::WiFiManager::setAPOnSetup </td>
          <td>(</td>
          <td class="paramtype">String const &amp;&#160;</td>
          <td class="paramname"><em>name</em>, </td>
        </tr>
        <tr>
          <td class="paramkey"></td>
          <td></td>
          <td class="paramtype">String const &amp;&#160;</td>
          <td class="paramname"><em>pwd</em>&#160;</td>
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
<p>Set the hotspot network </p><dl class="params"><dt>Parameters</dt><dd>
  <table class="params">
    <tr><td class="paramname">name</td><td>the hotspot name </td></tr>
    <tr><td class="paramname">pwd</td><td>the hotspot password </td></tr>
  </table>
  </dd>
</dl>

</div>
</div>
<a class="anchor" id="a4673d981d3a99bf6c6fe0926fb5bb8a6"></a>
<div class="memitem">
<div class="memproto">
<table class="mlabels">
  <tr>
  <td class="mlabels-left">
      <table class="memname">
        <tr>
          <td class="memname">void NRE::Micro::WiFiManager::setup </td>
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
<li>/mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/WiFi/Manager/<a class="el" href="_n_r_e___wi_fi_manager_8hpp_source.php">NRE_WiFiManager.hpp</a></li>
<li>/mnt/c/Users/abell/Documents/GitHub/NRE-Micro/src/WiFi/Manager/<a class="el" href="_n_r_e___wi_fi_manager_inl_8hpp_source.php">NRE_WiFiManagerInl.hpp</a></li>
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
