//
//  UGAD.swift
//  ad_csj
//
//  Created by admin on 2022/3/25.
//

import Foundation

@objcMembers
public class UGAD:NSObject{
	public static let UGADfinishNotification = NSNotification.Name("UGADfinishNotification")
	
	public static let share = UGAD()
	
    public var data:UGADModel? = nil
    
    @objc public func isHasJili()->Bool{
        return data?.jili != nil
    }
	
	private var finishBlock:(()->())? = nil
	
	public func setUp(_ finish:@escaping (()->())){
		finishBlock = finish
		cacheADDate()
	}
	
	func cacheADDate(){
		AF.api_adList()
			.responseModel([UGADModel].self) {[weak self] result in
				guard let self = self else {return}
				switch result{
				case .success(let value):
					self.data = value.first
					log("获取广告数据成功",level: .info)
				case .failure(let err):
					debugPrint(err)
					log("获取广告数据失败",level: .error)
					break
				}
				self.adDtatDidfinish()
			}
		
	}
	// 获取到广告后显示开屏广告
	//	static
	func adDtatDidfinish(){
		
		
		if  data?.tag == "ioschuanshanjia"{
			BUAdSDKManager.setAppID(data?.adid)
		}
#if canImport(SJMAdSDK)
		if  data?.tag == "iossanjiaomao",
			let adid = data?.adid
		{
			SJMAdSDKManager.registerAppId(adid)
		}
#endif

		self.finishBlock?()

	}
}


public struct UGADModel:HandyJSON{
	
	public struct UGADItem:HandyJSON{
		var id:Int = 0 //广告组id
		var sort:Int = 0 // 排序
		var status:Int = 0 // 状态 1：启用 2：不启用
		var typename:String = "" // 广告名称
		var tag:String = "" // 自定义标签 xinxiliu jili kaiping
		var description:String = "" //描述，目前是放广告Id
		var type_id:String = "" // 广告组id
		public var time:String = "" // time
		var adid:String = "" //广告位id
		
		public init() {
			
		}
	}
	
	var id:Int = 0 // 广告组id
	var sort:Int = 0 // 排序
	var name:String = "" // 广告组名称
	var tag:String = "" // 自定义标签 ioschuanshanjia iossanjiaomao
	var package_name:String = ""  // 包名
	var sha1:String = "" //sha1值
	var crackType:String = "" // 破解处理 破解方式 1：不处理 2：弹出提示（弹出提示框，点击跳转官网） 3：闪退
	var remark:String = "" // 弹出信息
	var site:String = "" // 跳转地址
	var adid:String = ""// 广告平台id
	var list:[UGADItem] = []
	public init() {
	
	}
	
	var kaiping:UGADItem?{
		list.filter { $0.tag == "kaiping"}.first
	}
	public var jili:UGADItem?{
		list.filter { $0.tag == "jili"}.first
	}
	var xinxiliu:UGADItem?{
		list.filter { $0.tag == "xinxiliu"}.first
	}

	
}
