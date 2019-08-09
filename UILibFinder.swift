//
//  UILibUtil.swift
//  letSing
//
//  Created by Mac on 2019/6/24.
//  Copyright © 2019 rcshow. All rights reserved.
//

import Foundation

public class UILibFinder {
    
    weak var _ui: UILibManager!
    
    init(ui: UILibManager?) {
        self._ui = ui;
    }
    func find<T:UIView>(strID : String?) -> T? {
        if(strID != nil && strID!.length > 0 && _ui != nil){
            let obj:UILibObject = _ui.object(withStringId: strID);
            return (obj.view as! T)
        }
        return nil;
    }
    
//    func view(strID : String) -> UIView {
//
//    }
//    func label(strID : String) -> UILabel {
//
//    }
}
