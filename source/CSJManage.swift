//
//  File.swift
//  Alamofire
//
//  Created by admin on 2022/3/2.
//

import Foundation
import BUAdSDK
import UIKit




/**
 应用id：5265531
 激励：947727765
 开屏：887679040
 信息流：948054181
 */
public extension UIViewController{
	
	var splashEndDtae: String?{
		get{
			return UserDefaults.standard.string(forKey: "splashEndDtae")
		}
		set{
			UserDefaults.standard.set(newValue, forKey: "splashEndDtae")
		}
		
	}

	// 全屏广告
	static var fullscreenAd:BUNativeExpressFullscreenVideoAd? = nil
	func ad_fullscreen(){
		Self.fullscreenAd = BUNativeExpressFullscreenVideoAd.init(slotID: "948062787")
		Self.fullscreenAd?.delegate = self
		Self.fullscreenAd?.loadData()
//		fullscreenAd.show(fromRootViewController: self)
	}
	
	// 信息流
	func ad_feed(slotid:String = "948054181"){
		let slot = BUAdSlot()
		slot.id = slotid
		slot.adType = .feed
		let imgSize =  BUSize.init(by: .feed228_150)
		slot.imgSize = imgSize;
		slot.position = .feed
		let navexmanage = BUNativeExpressAdManager.init(slot: slot, adSize: .init(width: 300, height: 300))
		
//		navexmanage.delegate = self
		navexmanage.loadAdData(withCount: 1)
	}
	
}
extension Error{
	var ug_localizedDescription: String {
		let loca = self.localizedDescription
		if loca.count>20{
			return word0002.loc
		}else{
			return loca
		}
	}
}

// 启动广告的委托
extension UIViewController:BUSplashAdDelegate{
	
	// 广告加载成功回调
	public func splashAdDidLoad(_ splashAd: BUSplashAdView) {
		splashAd.alpha = 1
	}
	public func splashAd(_ splashAd: BUSplashAdView, didFailWithError error: Error?) {
		UIView.error(error?.ug_localizedDescription ?? word0002.loc)
		splashAd.removeFromSuperview()
	}
	public func splashAdCountdown(toZero splashAd: BUSplashAdView) {
		splashAd.removeFromSuperview()
	}
	public func splashAdDidClickSkip(_ splashAd: BUSplashAdView) {
		splashAd.removeFromSuperview()
	}
}

// 全屏视频的委托
extension UIViewController:BUNativeExpressFullscreenVideoAdDelegate{
	public func nativeExpressFullscreenVideoAd(_ fullscreenVideoAd: BUNativeExpressFullscreenVideoAd, didFailWithError error: Error?) {
		UIView.error(error?.localizedDescription ?? "didFailWithError")
	}
	public func nativeExpressFullscreenVideoAdViewRenderFail(_ rewardedVideoAd: BUNativeExpressFullscreenVideoAd, error: Error?) {
		UIView.error(error?.localizedDescription ?? "AdViewRenderFail")
	}
	public func nativeExpressFullscreenVideoAdDidLoad(_ fullscreenVideoAd: BUNativeExpressFullscreenVideoAd) {
		guard let rootvc = UIApplication.shared.windows.first?.rootViewController else{
			return
		}
		fullscreenVideoAd.show(fromRootViewController: rootvc)
		
	}
}




