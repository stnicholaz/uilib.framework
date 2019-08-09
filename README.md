# uilib.framework

########################################
#
# uilib库使用说明
# 2019.06.25 by zhaodingsheng
#
########################################

简介：iOS开发中使用xml来布局UI
Uilib是到力于解决iOS开发过程中界面布局的问题，即使使用原生或autolayout或masonry库，仍然无法提高布局效率、灵活性、可读性、可维护性等，由此，uilib应运而生，当然，作者秉承简单易用的特点，uilib无法做做像Android界面布局那般强大，但uilib使用xml格式来配置UI, 使用原生UI控件，可扩展自定义控件，修改UI后不像修改代码后那样需要再次编译代码，从而提升了开发效率、可直接在OC和Swift中使用等等。相信足以为您节省界面开发的大部份时间，提高可维护性。
但是目前还无法开源，因为代码还有很多需要优化，等我有空把代码重构之后再开源出来，在这之前，有问题可以直接联系我stnicholas@qq.com

功能：
1.界面布局：目前支持水平线性布局(horlayout)、垂直线性布局(verlayout)、相对布局(rellayout)、流式布局(flowlayout)
2.样式配置:支持在xml文件中直接配置控件通用属性，如字体、背景图、背景色、圆角、边框等，以及控件特有的如UIImageView的src、UIButton的image、TextField的placeholder/inputType等等

布局原则：
在一个layout内的控件，若不设置size/width/height，则未设置的控件平分每下的空间
如：
<horlayout width="375">
	<view id="view1" width="50"/>
	<view id="view2" width="100"/>
	<view id="view3"/>
	<view id="view4"/>
</horlayout>
上述水平布局中，id为view1、view2的两个控件设置了自己的宽分别为50和100，那么view3、view4未设置宽度就平分layout剩下的宽度:(375-50-100)/2=225/2=112.5

再如：
<verlayout>
	<view id="titlebar" height ="44"/>
	<image id="banner" height="120"/>
	<tableview id="tb_list"/>
	<view id="bottombar" height ="64"/>
</verlayout>
上述是垂直布局，根verlayout未设置高宽，则默认会和父控件一样的大小，
1.id为titlebar的控件大小为 宽=父控件，高=44，位置在layout的顶部
2.id为banner的控件大小为 宽=父控件，高=44，位置自动布局于titlebar的下方
3.id为bottombar的高是64，位于verlayout的最底部，屏幕最下方，为什么它在底部呢，因为id为tb_list的tabelview未设置高度，会把两边的控件“撑开”
4.id为tb_list的tabelview就会自动填充verlayout中间的区域

下面我们来看看rellayout
<rellayout>	
	<GifImage id="bkgrd_gif" src="下雨.gif"/>
	<verlayout id="layout_main">
		<view id="header" height ="44"/>
		<tableview id="body"/>
		<view id="footer" height ="64"/>
	</verlayout>
</rellayout>
最外层的rellayout是相对布局,它意味着其内的子控件都相对于它的左上角布局，后添加控件如与前面的控件会位置上的重叠，则后面的控件会压在前一个控件之上


完整布局格式：
上述xml都还只是部分ui块，现在我们来看看一个完整的ui文件,“登录”界面的UI:
<view title="登录" bkgrd-color="#FFFFFF">
    <verlayout text-align="center">

        <img src="ic_logo_about" size="54x76"/>

	<label text="纽牛" height="42" text-align="center" text-color="#333333" text-size="16"/>
                
        <label height="24" text-color="@font_navBarTitle" text-align="left,center" text="账号" text-size="14" margin-top="30"/>

        <textfield id="tf_account" text-color="@font_navBarTitle" hint-color="#D7DADF" keyboard-type="ascii" text-size="16" placeholder="邮箱地址/手机号" border-style="none" bkgrd-color="0xFFFFFF00" margin-top="10" />

        <view height="0.5" bkgrd-color="@sep_lineColor" />
                
        <label height="24" text-color="@font_navBarTitle" text-align="left,center" text="登录密码" text-size="14" margin-top="40"/>

        <textfield id="tf_password" text-color="@font_navBarTitle" hint-color="@font_hint" text-size="16" placeholder="8-20位数字或字母" secure-text-entry="1" border-style="none" bkgrd-color="0xFFFFFF00" margin-top="10"/>

        <view height="0.5" bkgrd-color="@sep_lineColor" />
                
        <button id="btn_login" text="登录" text-color="#FFFFFF" text-size="17" height="50" margin-top="50" text-align="center" bkgrd-color="@bg_button" bkgrd-pressed-alpha="0.7" border-radius="6" />
          
    </verlayout>
</view>


默认支持的标签<tagname 及其对应的View类型列表：
标签名：			|  View类型
verlayout 		=> UILibLayerView/UIButton
horlayout 		=> UILibLayerView/UIButton
radiogroup 		=> UILibLayerView/UIButton
rellayout 		=> UILibLayerView/UIButton
flowlayout 		=> UILibLayerView/UIButton
abslayout 		=> UILibLayerView/UIButton
view 			=> UIView
label 			=> UILibLabel/UILabel
img/image 		=> UIImageView
button 			=> UIButton
radio/radiobox 		=> UILibRadio
check/checkbox 		=> UILibCheck
text/textfield 		=> UITextField
edit/edittext 		=> UITextField
textview 		=> UITextView
slider 			=> UISlider
switch 			=> UISwitch
segmented/segmentedcontrol => UISegmentedControl
progressview 		=> UIProgressView
stepper 		=> UIStepper
indicator 		=> UIActivityIndicatorView
toolbar 		=> UIToolbar
tabbar 			=> UITabBar
webview 		=> WKWebView
tableview 		=> UITableView
scrollview 		=> UILibScrollFragment/UIScrollView
navigationbar 		=> UINavigationBar
datepicker 		=> UIDatePicker
CollectionView 		=> UICollectionView
visualeffectview 	=> UIVisualEffectView
tableviewcell 		=> UITableViewCell

说明：上会的标签名是不区分大小写的，或者可以直接使用分区大小写的类全名，如<UITableView <UIImageView ...
如果有自定义的View，也将其作为标签名使用，如<CustomView height="50" bkgrd-color="#FFFFFF"/>

接下来，我们来看一下有哪些通用属性：
id="lb_title" 用于在代码中查找此控件
text="标题"
prefix="$" 文本前缀
suffix="%" 文本后缀
width="20" width="fit" （fit表示UILabel/UIButton自动计算文本所占宽度）
height="100" height="fit" （fit表示UILabel/UIButton自动计算文本所占高度）
size="100x20" （可使用百分号 size="100%x50%" 表示与父layout一样的宽和父layout一半的高）
weight="1" （比重，用于与其它平级控件按比例分得父layout的宽或高）
padding="左,上,右,下" （子控件或文本内空白,也可单独设置如下：）
padding-left="15"
padding-top="15"
padding-right="15"
padding-bottom="15"
margin="左,上,右,下" (与其它控件或父控件的偏移,也可单独设置如下：)
margin-left="15"
margin-top="15"
margin-right="15"
margin-bottom="15"
text-align="水平|垂直" （文本对齐 left/right/top/bottom/center）
align-parent="水平|垂直" （只在rellayout内标签有效哟）
visible="1" （是否可见 0否 1是）
hidden="0" （是否隐藏 0否 1是）

//背景
bkgrd-color="#FFFFFF" （背景色，可使用RGB配置如 bkgrd-color="125,3,90"）
bkgrd-image="ic_logo" (背景图,与image-assets中的名字一致，不加图片格式后缀)
bkgrd-image-stretch="左,上,右,下" (背影图9宫格拉伸)

//边框
border-olor="#FF0000" （边框颜色，可使用RGB配置如 bkgrd-color="125,3,90"）
border-width="1" （边框厚度）
border-radius="5" （圆角，如设置了背影色也设置了圆角，背影将会变成圆角样式）

//字体
Font-size="16" (字号)
font-color="#262928" （用RGB：font_color="128,0,55"）

以上大部份控件都支持配置的属性, 除了通用属性之外，还会有些控件所特有的属性:

UILabel:
text-color="#FFFFFF"
Line-number/lines="3" （行数）
line-break-mode="" （换行模式：word-wrap/char-wrap/clip/head/tail/middle）
shadow-color="#000000" （阴影颜色）
shadow-offset="2,3" （阴影偏移）

UIButton:
text-color="#888888"
text-checked-color/text-selected-color="#555555" (选中时字体颜色)
image="ic_logo" （按钮上的图片）
image-size="22x22" （按钮上的图片尺寸）
image-selected/image-checked="ic_logo_hl" （选中时按钮上的图片）
image-edge-insets="左,上,右,下" （图片偏移）
title-edge-insets="左,上,右,下" （文本偏移）
content-edge-insets="左,上,右,下" （内容偏移）

RadioBox:
checked="1" (是否选中 1/0）

CheckBox:
checked="1" (是否选中 1/0）

UITextView:
readonly="0" (是否只读 1/0）
editable="1" (是否可编辑 1/0）

UITextField:
place-holder/hint="请输入6-20位的密码" （未输入时的提示文字）
place-holder-color/hint-color="#888888" (未输入时提示文字的颜色）
place-holder-align="left" （对齐方式 left,right,center）
readonly="0" (是否只读 1/0）
editable="1" (是否可编辑 1/0）
tint-color="#005500"（光标颜色）
secure-text-entry/password="1"（是否密码模式）
keyboard-type/input-type="default"（键盘模式:ascii/number/url/numberpad/phonepad/ namephonepad/email/decimal/twitter/websearch/asciinumber)
border-style="line" (边框样式：line/bezel/round)

UIImageView:
src="" （图片名称，与image.assets中的名称一致，不带后缀）
stretch="10,10,10,10" (九宫格拉伸：左，上，右，下)
content-mode/mode="" （图片填充模式：ScaleToFill/ScaleAspectFit/ScaleAspectFill/redraw/center/top/bottom/left/right/topleft/topright/bottomleft/bottomright)
clips-to-bounds/clips-bounds="1" (是否clip:0/1)
animation-images="image1,image2,image3,..." (动画图片组)
animation-duration="300" （动画时间间隔）

UITabBar:
text-unselected-color="#555555" （未选中时的字体颜色）
tint-color/text-selected-color="#005555" （选中时的字体颜色）
bar-tint-color/bkgrd-color="#FFFFFF" （背影颜色）
translucent/transparent="0" （是否有透明度：0/1）
item-width="100" (item的宽度)
item-spacing="0" （item间的空隙）
item-image-size="22x22" （item内图标的尺寸）
items="文字#默认图标#选中图标,..."
items-text="文字1,文字2,文字3,..."
items-image="默认图标#选中图标,..."
image-always-original="1"（始终保持原始图片，否则系统会将其换色）
selected-index="0" (选择序号)

WKWebView:
url="http://www.github.com/" (要跳转到的网址)

UISlider:
range="0,100" （取值范围）
value="50" （当前值）

UISwitch:
on="1" 	（1开0关）
on-tint-color="#008800" (on的背景颜色)
tint-color/off-tint-color="#BCBCBC" （off的背景颜色）
thumb-color/thumb-tint-color="#FFFFFF" （圆形滑块的颜色）
transform="0.6" (缩放比例, UISwitch无法指定size)

UIProgressView:
style-bar="0" (progressView.progressViewStyle != UIProgressViewStyleBar)
tint-color="#BCBCBC" 
tint-image="tint_progress"
track-color="滑道背景颜色"
track-image="" （滑道背景图片）
progress="50" (当前进度)

UIStepper:
continuous="1" (代表被改变的值是在用户交互期间立即更改，还是用户交互结束时再更改？)
auto-repeat="1" （是否按住不放来连续更改数值）
wraps="0" (超过范围后是回到最小/最大值还是保持不变)
step-value="1" (每次增加值)
range="1，100" （取值范围）
value="35" (当前值)
tint-color="#00000a0" （样式颜色）
decrement-image="ic_jian" (-号图标)
increment-image="ic_jia"  (+号图标)

UIActivityIndicatorView:
style="white" (主题样式：white/gray/large)
color="#BCBCBC" （圈圈的颜色）
center="1" (是否居中)
auto-start="1" (是否自动开始转圈)
hides-when-stopped="0" (当停止动画时是否隐藏起来)

UISegmentedControl:
titles="title1,title2,..." （item列表）
tint-color="#0000aa" (色调,选中项的背景色，未选中的是backgroundColor)
text-selected-color="#353535" (选中时字体颜色)
divider-image="bg_seq" (设置标签之间分割线的图案)
divider-color="#0000aa" (设置标签之间分割线的颜色)
selected-index="0" (选中序号)

UIVisualEffectView:
blur-effect-style/effect-style="light" (样式：light/extralight/dark)
alpha="0.7" (透明度)

UIDatePicker:
locale="" (设置日期选择控件的地区)
current-date/current-calendar="1" （是否默认为当天）
default-time-zone="1" (是否设置DatePicker的默认时区)
min-date/minimum-date="2000-01-01" （最小日期）
max-date/maximum-date="2099-12-31" （最大日期）
date="2019-08-09" (设置当前显示的日期)

UITableView:
separator-style/line-style="line" （分隔线样式：none/line/etched）
separator-color/line-color="#FBFBFB" （分隔线颜色）
separator-inset/line-inset="15,0,15,0" （类似margin,左,上,右,下）

UITableViewCell:
icon/image="ic_logo" (左侧图标)
image-size/icon-size="20x20" （图标尺寸）
text="xxx" (文本)
text-size="16" （文字字号）
text-color="#353535" （文字颜色）
detail="" (右侧二级文本，详情)
detail-text-size="#BCBCBC" （详情字体颜色）
show-arrow="1" （是否显示箭头）
accessory-type="arrow" (右侧图标类型：none/arrow(indicator)/disclosure(detailarrow)/checkmark/detail)
arrow-image="ic_arrow_r" （自定义箭头图标）
tint-color="#0000aa" （主色调）

UICollectionView:
item-size="100x100" (item尺寸)
estimated-item-size
spacing="15,10" （水平，垂直间距）
minimum-line-spacing="15"  （水平间距）
minimum-interitem-spacing="10" （垂直间距）
section-inset="10" （内空白,类似padding）
scroll-direction="horizontal" (滚动方向：horizontal简写hor)

UIScrollView:
scroll-enabled="1" （是否可以滚动）
shows-scroll-indicator/scrollbar="0" (是否显示滚动条)
shows-horizontal-scroll-indicator/scrollbar-x (是否显示水平滚动条)
shows-vertical-scroll-indicator"/scrollbar-y (是否显示垂直滚动条)
paging-enabled="0" （是否分页）
always-bounce-vertical="1" （滚到垂直尽头时是否启用弹簧效果）
always-bounce-horizontal="1" （滚到水平尽头时是否启用弹簧效果）
delays-content-touches="1"
can-cancel-content-touches="1"
切记:千万不要在tableView上试delaysContentTouches属性，那会让你试到怀疑人生的。这个属性在tableView上根本没有效果










