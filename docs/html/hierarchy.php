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
        <title>NRE-Micro: Class Hierarchy</title>
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
      <li class="current"><a href="hierarchy.php"><span>Class&#160;Hierarchy</span></a></li>
      <li><a href="functions.php"><span>Class&#160;Members</span></a></li>
    </ul>
  </div>
</div><!-- top -->
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

<div class="header">
  <div class="headertitle">
<div class="title">Class Hierarchy</div>  </div>
</div><!--header-->
<div class="contents">
<div class="textblock">This inheritance list is sorted roughly, but not completely, alphabetically:</div><div class="directory">
<div class="levels">[detail level <span onclick="javascript:toggleLevel(1);">1</span><span onclick="javascript:toggleLevel(2);">2</span><span onclick="javascript:toggleLevel(3);">3</span>]</div><table class="directory">
<tr id="row_0_" class="even"><td class="entry"><span style="width:0px;display:inline-block;">&#160;</span><span id="arr_0_" class="arrow" onclick="toggleFolder('0_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_data.php" target="_self">NRE::Micro::AbstractData</a></td><td class="desc">Represent an abstract data </td></tr>
<tr id="row_0_0_"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_observed_data.php" target="_self">NRE::Micro::ObservedData&lt; T &gt;</a></td><td class="desc">Represent an observed data by the internal ROM if used, allowing an automatic update between RAM and ROM </td></tr>
<tr id="row_0_1_" class="even"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_observed_data.php" target="_self">NRE::Micro::ObservedData&lt; NRE::Micro::Color &gt;</a></td><td class="desc"></td></tr>
<tr id="row_1_"><td class="entry"><span style="width:0px;display:inline-block;">&#160;</span><span id="arr_1_" class="arrow" onclick="toggleFolder('1_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_abstract_module.php" target="_self">NRE::Micro::AbstractModule</a></td><td class="desc">Represent an abstract module used to active a certain part of the framework </td></tr>
<tr id="row_1_0_" class="even"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span id="arr_1_0_" class="arrow" onclick="toggleFolder('1_0_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php" target="_self">NRE::Micro::Module&lt; LedManager &gt;</a></td><td class="desc"></td></tr>
<tr id="row_1_0_0_"><td class="entry"><span style="width:48px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_led_manager.php" target="_self">NRE::Micro::LedManager</a></td><td class="desc">Manage all leds controller </td></tr>
<tr id="row_1_1_" class="even"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span id="arr_1_1_" class="arrow" onclick="toggleFolder('1_1_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php" target="_self">NRE::Micro::Module&lt; WebManager &gt;</a></td><td class="desc"></td></tr>
<tr id="row_1_1_0_"><td class="entry"><span style="width:48px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_web_manager.php" target="_self">NRE::Micro::WebManager</a></td><td class="desc">Manage a web serveur and http updater </td></tr>
<tr id="row_1_2_" class="even"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span id="arr_1_2_" class="arrow" onclick="toggleFolder('1_2_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php" target="_self">NRE::Micro::Module&lt; WiFiManager &gt;</a></td><td class="desc"></td></tr>
<tr id="row_1_2_0_"><td class="entry"><span style="width:48px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_wi_fi_manager.php" target="_self">NRE::Micro::WiFiManager</a></td><td class="desc">Manage the wifi module with client/server and connection </td></tr>
<tr id="row_1_3_" class="even"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_module.php" target="_self">NRE::Micro::Module&lt; SubModule &gt;</a></td><td class="desc">Represent a module interface to create framework sub module </td></tr>
<tr id="row_2_"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_color.php" target="_self">NRE::Micro::Color</a></td><td class="desc">Represent a led <a class="el" href="class_n_r_e_1_1_micro_1_1_color.php" title="Represent a led Color. ">Color</a> </td></tr>
<tr id="row_3_" class="even"><td class="entry"><span style="width:0px;display:inline-block;">&#160;</span><span id="arr_3_" class="arrow" onclick="toggleFolder('3_')">&#9660;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_effect.php" target="_self">NRE::Micro::Effect</a></td><td class="desc">Represent a light effect </td></tr>
<tr id="row_3_0_"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_fix_effect.php" target="_self">NRE::Micro::FixEffect</a></td><td class="desc">Represent a fix light effect, setting all leds to the same color with no movement </td></tr>
<tr id="row_3_1_" class="even"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_rotate_effect.php" target="_self">NRE::Micro::RotateEffect</a></td><td class="desc">Represent a rotate light effect, setting leds on one by one, only one led remain on at the same time </td></tr>
<tr id="row_3_2_"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_rotate_fix_effect.php" target="_self">NRE::Micro::RotateFixEffect</a></td><td class="desc">Represent a rotate light effect, setting leds on one by one, leds remains on while the effect is running </td></tr>
<tr id="row_3_3_" class="even"><td class="entry"><span style="width:32px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_wave_effect.php" target="_self">NRE::Micro::WaveEffect</a></td><td class="desc">Represent a wave light effect, setting all leds to the same color, starting from black to the given color and then back to black </td></tr>
<tr id="row_4_"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_led.php" target="_self">NRE::Micro::Led</a></td><td class="desc">Represent a single <a class="el" href="class_n_r_e_1_1_micro_1_1_led.php" title="Represent a single Led. ">Led</a> </td></tr>
<tr id="row_5_" class="even"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_led_controller.php" target="_self">NRE::Micro::LedController</a></td><td class="desc">Manage access to a led component </td></tr>
<tr id="row_6_"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="class_n_r_e_1_1_micro_1_1_micro_manager.php" target="_self">NRE::Micro::MicroManager</a></td><td class="desc">Manage all modules in the framework, allowing the user simple utilisation of ESP8266 library and functionnality </td></tr>
<tr id="row_7_" class="even"><td class="entry"><span style="width:16px;display:inline-block;">&#160;</span><span class="icona"><span class="icon">C</span></span><a class="el" href="struct_n_r_e_1_1_micro_1_1_network.php" target="_self">NRE::Micro::Network</a></td><td class="desc">Represent a wifi network </td></tr>
</table>
</div><!-- directory -->
</div><!-- contents -->
<!-- HTML footer for doxygen 1.8.8-->
<!-- start footer part -->
</div>
</div>
</div>
</div>
</body>
</html>
