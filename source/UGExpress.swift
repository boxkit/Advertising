//
//  UGExpress.swift
//  UGAD
//
//  Created by admin on 2022/3/25.
//

import Foundation
import BUAdSDK
import UGExtension


// 信息流
public class UGExpress:NSObject{
    @objc static public var adexpressW:CGFloat{
        app.KWidth
    }
	@objc static public let adexpressH:CGFloat = 240
	public var updateBlock:((_ express:UGExpress)->())? = nil
	@objc public var views:[NSObject] = []
	public var isunLike = false
	public var manage:Any? = nil


	public func reload(){
		defer{
			if let block = updateBlock{
				block(self)
			}
		}
		if isunLike == true {
			log("信息流广告被用户关闭了", level: .debug)
			return
		}
		guard let data =  UGAD.share.data else {
			log("信息流无广告数据", level: .debug)
			return
		}
		guard let slot = data.xinxiliu else{
			log("无信息流广告", level: .debug)
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

	}
	
	func load_chuangshanjia(_ slot:UGADModel.UGADItem){
		log("获取穿山甲信息流广告", level: .debug)
		let adslot = BUAdSlot()
		adslot.id = slot.adid
	
        adslot.adType = .feed
        adslot.imgSize = BUSize(by: .drawFullScreen)
		adslot.position = .top
		manage = (manage==nil) ? BUNativeExpressAdManager.init(slot: adslot ,adSize: .init(width: UGExpress.adexpressW, height: UGExpress.adexpressH)) : manage
		guard let ma = manage as? BUNativeExpressAdManager else{
			return
		}
		ma.delegate = self
		ma.loadAdData(withCount: 3)
		manage = ma
		
	}
#if canImport(SJMAdSDK)
	func load_sanjiaomao(_ slot:UGADModel.UGADItem){
		log("获取三角猫信息流广告", level: .debug)
		manage = (manage==nil) ?  SJMNativeExpressFeedAdManager.init(placementId: slot.adid ,size: .init(width: UGExpress.adexpressW, height: UGExpress.adexpressH)) : manage
		guard let ma = manage as? SJMNativeExpressFeedAdManager else{
			return
		}

		ma.delegate = self
		ma.loadAdData(withCount: 3)
		manage = ma
	
	}
#else
    func load_sanjiaomao(_ slot:UGADModel.UGADItem){
    }
#endif
	
	
}
extension UGExpress:BUNativeExpressAdViewDelegate{
	// 加载失败
	public func nativeExpressAdFail(toLoad nativeExpressAdManager: BUNativeExpressAdManager, error: Error?) {
		if let block = updateBlock{
			block(self)
		}
		log("穿山甲信息流广告加载失败 error:\(error.debugDescription)", level: .error)

	}
	// 渲染失败，网络原因或者硬件原因导致渲染失败,可以更换手机或者网络环境测试。建议升级到穿山甲平台最新版本
	public func nativeExpressAdViewRenderFail(_ nativeExpressAdView: BUNativeExpressAdView, error: Error?) {
		
		if let index = views.firstIndex(of: nativeExpressAdView){
			views.remove(at:index)
		}
		if let block = updateBlock{
			block(self)
		}
		log("穿山甲信息流广告渲染加载失败 error:\(error)", level: .error)
	
		
	}
	public func nativeExpressAdSuccess(toLoad nativeExpressAdManager: BUNativeExpressAdManager, views: [BUNativeExpressAdView]) {
		self.views = views
		if let block = updateBlock{
			block(self)
		}

	}
	//  //【重要】需要在点击叉以后 在这个回调中移除视图，否则，会出现用户点击叉无效的情况
	public func nativeExpressAdView(_ nativeExpressAdView: BUNativeExpressAdView, dislikeWithReason filterWords: [BUDislikeWords]) {
		self.views.removeAll()
		isunLike = true
		if let block = updateBlock{
			block(self)
		}
	
	}
	//【重要】若开发者收到此回调，代表穿山甲会主动关闭掉广告，广告移除后需要开发者对界面进行适配
	public func nativeExpressAdViewDidRemoved(_ nativeExpressAdView: BUNativeExpressAdView) {
		self.views.removeAll()
		isunLike = true
		if let block = updateBlock{
			block(self)
		}
	
	}
}

#if canImport(SJMAdSDK)
extension UGExpress:SJMNativeExpressFeedAdManagerDelegate{
	public func sjm_nativeExpressFeedAdManagerSuccess(toLoad adsManager: SJMNativeExpressFeedAdManager, nativeAds feedAdDataArray: [SJMNativeExpressFeedAd]?) {
		feedAdDataArray?.forEach({ item in
			item.delegate = self
		})
		self.views = feedAdDataArray ?? []
		if let block = updateBlock{
			block(self)
		}


	}
	public func sjm_nativeExpressFeedAdManager(_ adsManager: SJMNativeExpressFeedAdManager, didFailWithError error: Error?) {
	
		if let block = updateBlock{
			block(self)
		}
		
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
#endif
