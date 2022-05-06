//
//  UGExpress.swift
//  UGAD
//
//  Created by admin on 2022/3/25.
//

import Foundation
import BUAdSDK


// 信息流
public class UGExpress:NSObject{
	
	public var updateBlock:((_ express:UGExpress)->())? = nil
	public var views:[NSObject] = []
	public var isunLike = false
	public var manage:Any? = nil


	public func reload(){
		defer{
			if let block = updateBlock{
				block(self)
			}
		}
		if isunLike == true {
			return
		}
	
		guard let slot = UGAD.share.data?.xinxiliu else{
			
			return
		}
		guard let data =  UGAD.share.data else {
		
			return
		}
		if slot.status == 2{
			return
		}
		if data.tag == "ioschuanshanjia"{
			load_chuangshanjia(slot)
		}else if data.tag == "iossanjiaomao"{
			load_sanjiaomao(slot)
		}
		UGServerLog.ug_log(type: .expressload,info: ["slotID":slot.adid,
											 "tag":data.tag,
											 "adID":data.adid,
											])
		

	}
	
	func load_chuangshanjia(_ slot:UGADModel.UGADItem){
		
		let adslot = BUAdSlot()
		adslot.id = slot.adid
	
		adslot.adType = .feed
		adslot.imgSize = BUSize.init(by: .banner600_300)
		adslot.position = .feed
		manage = (manage==nil) ? BUNativeExpressAdManager.init(slot: adslot, adSize: .init(width: app.KWidth-30, height: 150)) : manage
		guard let ma = manage as? BUNativeExpressAdManager else{
			return
		}
		ma.adSize = .init(width: app.KWidth-30, height: 150)
		ma.delegate = self
		ma.loadAdData(withCount: 3)
		manage = ma
		
	}
	
	func load_sanjiaomao(_ slot:UGADModel.UGADItem){

		manage = (manage==nil) ?  SJMNativeExpressFeedAdManager.init(placementId: slot.adid ,size: .init(width: app.KWidth-30, height: 150)) : manage
		guard let ma = manage as? SJMNativeExpressFeedAdManager else{
			return
		}

		ma.delegate = self
		ma.loadAdData(withCount: 3)
		manage = ma
	
	}
	
	
}
extension UGExpress:BUNativeExpressAdViewDelegate{
	// 加载失败
	public func nativeExpressAdFail(toLoad nativeExpressAdManager: BUNativeExpressAdManager, error: Error?) {
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expressloaderror,info: ["tag":"ioschuanshanjia"])
	}
	// 渲染失败，网络原因或者硬件原因导致渲染失败,可以更换手机或者网络环境测试。建议升级到穿山甲平台最新版本
	public func nativeExpressAdViewRenderFail(_ nativeExpressAdView: BUNativeExpressAdView, error: Error?) {
		
		if let index = views.firstIndex(of: nativeExpressAdView){
			views.remove(at:index)
		}
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expressshowerror,info: ["tag":"ioschuanshanjia"])
		
	}
	public func nativeExpressAdSuccess(toLoad nativeExpressAdManager: BUNativeExpressAdManager, views: [BUNativeExpressAdView]) {
		self.views = views
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expressshow,info: ["tag":"ioschuanshanjia"])
	}
	//  //【重要】需要在点击叉以后 在这个回调中移除视图，否则，会出现用户点击叉无效的情况
	public func nativeExpressAdView(_ nativeExpressAdView: BUNativeExpressAdView, dislikeWithReason filterWords: [BUDislikeWords]) {
		self.views.removeAll()
		isunLike = true
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expresshidden,info: ["tag":"ioschuanshanjia"])
	}
	//【重要】若开发者收到此回调，代表穿山甲会主动关闭掉广告，广告移除后需要开发者对界面进行适配
	public func nativeExpressAdViewDidRemoved(_ nativeExpressAdView: BUNativeExpressAdView) {
		self.views.removeAll()
		isunLike = true
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expresssysunlike ,info: ["tag":"ioschuanshanjia"])
	}
}

extension UGExpress:SJMNativeExpressFeedAdManagerDelegate{
	public func sjm_nativeExpressFeedAdManagerSuccess(toLoad adsManager: SJMNativeExpressFeedAdManager, nativeAds feedAdDataArray: [SJMNativeExpressFeedAd]?) {
		feedAdDataArray?.forEach({ item in
			item.delegate = self
		})
		self.views = feedAdDataArray ?? []
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expressshow ,info: ["tag":"iossanjiaomao"])

	}
	public func sjm_nativeExpressFeedAdManager(_ adsManager: SJMNativeExpressFeedAdManager, didFailWithError error: Error?) {
	
		if let block = updateBlock{
			block(self)
		}
		UGServerLog.ug_log(type: .expressloaderror ,info: ["tag":"iossanjiaomao"])
		
	}
}
extension UGExpress:SJMNativeExpressFeedAdDelegate{
	public func sjm_nativeExpressFeedAdDislike(_ feedAd: SJMNativeExpressFeedAd) {
		self.views.removeAll()
		isunLike = true
		if let block = updateBlock{
			block(self)
		}
	}
}
