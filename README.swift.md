# uilib.framework

########################################
#
# uilib库在swift中的使用说明
# 2019.06.25 by zhaodingsheng
#
########################################
方式一、继承基类
//1.首先继承UILibViewController或UILibFragment或UILibScrollFragment
class RecordRoomBottombarView: UILibFragment {

    var resingBtn: UIButton!
    var settingBtn: UIButton!
    var completeBtn: UIButton!

    internal override func nameOfUi() -> String {
	//2.重载nameOfUi返回ui文件
        return "view/RecordRoomBottombarView"
    }
    internal override func viewDidLoad() {
        
        super.viewDidLoad()
        //3.使用UILibFinder
        let uf = UILibFinder(ui: ui!)
        resingBtn = uf.find(strID: "btn_resing")
        completeBtn = uf.find(strID: "btn_finish")
        settingBtn = uf.find(strID: "btn_settings")
    }
}

方式二、直接创建UIView
class RecordRoomView: UIView {
    private var ui:UILibManager?
    private var topBar:RecordRoomTopbarView!

    internal override func viewDidLoad() {
        
        super.viewDidLoad()
	//1.定义
        ui = UILibManager(view: self)
	//2.加载ui文件
        ui?.loadUI("view/RecordRoomView")
	//3.确保布局生效
        ui?.relayoutUI(self.frame)
	//4.使用UILibFinder
        let uf = UILibFinder(ui: ui!)
        //5.获取相应的view
        topBar = uf.find(strID: "topbar")
    }
}


