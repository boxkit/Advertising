//
//  UGSplash.swift
//  UGAD
//
//  Created by admin on 2022/3/25.
//

import Foundation
import BUAdSDK
import UIKit


public class UGSplash:NSObject{
	public static let UGSplashFineshNotification = NSNotification.Name("UGSplashFineshNotification")
	
	public static let share = UGSplash()
	public enum SplashStatus:Int{
		case error = 100
		case skip = 101
		case finesh = 102
		case none
	}
	
	var adview:Any? = nil
	var supervc:UIViewController? = nil
	var statusChange:((_ status:SplashStatus)->())? = nil
	/**
	 显示开屏广告
	 */
	public func show(_ vc:UIViewController? = nil, block:@escaping (_ status:SplashStatus)->()){
		statusChange = block
		supervc = vc
		guard let data =  UGAD.share.data else {
			log("未获得广告数据",level: .error)
			finesh(state: .none)
			return
		}
		guard let slot = UGAD.share.data?.kaiping else{
			log("未获得开屏广告数据",level: .error)
			finesh(state: .none)
			return
		}
		if slot.status == 2{
			if let block = statusChange{
				block(.skip)
			}
			return
		}
		
	
		if data.tag == "ioschuanshanjia"{
			splash_chuanshanjia(slot)
		}else if data.tag == "iossanjiaomao"{
			splash_sanjiaomao(slot)
		}
		// 加载广告埋点
		UGServerLog.ug_log(type: .splashload,info: ["slotID":slot.adid,
											 "tag":data.tag,
											 "adID":data.adid,
											])
	}
	
	func splash_chuanshanjia(_ slot:UGADModel.UGADItem){
		
		
		if let date = UserDefaults.standard.string(forKey: "splash.showTime"),
		   -(date.date().timeIntervalSinceNow)<slot.time.double() {
			finesh(state: .skip)
			return
			
		}

		let frame = UIScreen.main.bounds
		let splashAdView = BUSplashAdView(slotID: slot.adid, frame: frame)
	
		splashAdView.tolerateTimeout = 100
		splashAdView.delegate = self
		
		splashAdView.rootViewController = supervc
		
		app.KWindow??.addSubview(splashAdView)
		adview = splashAdView
		splashAdView.loadAdData()
		UGServerLog.ug_log(type: .splashload,info: ["slotID":slot.adid,"tag":"ioschuanshanjia"])
	}
	
	func splash_sanjiaomao(_ slot:UGADModel.UGADItem){
	
		if let date = UserDefaults.standard.string(forKey: "splash.showTime"),
		   -(date.date().timeIntervalSinceNow)<slot.time.double() {
			finesh(state: .skip)
			return
			
		}
		
		let splashAd = SJMSplashAd.init(placementId:slot.adid)
		splashAd.fetchDelay = 5;
		splashAd.delegate = self;
		splashAd.bottomViewSize = .init(width: app.KWidth, height: 50)
		splashAd.loadAd()
		UGServerLog.ug_log(type: .splashload,info: ["slotID":slot.adid,"tag":"iossanjiaomao"])
		
		
	}
	
	func finesh(state:SplashStatus){
		if let block = statusChange{
			block(state)
		}
		NotificationCenter.default.post(name:Self.UGSplashFineshNotification , object: nil)
	}
}

extension UGSplash:BUSplashAdDelegate{
	// 广告加载成功回调
	public func splashAdDidLoad(_ splashAd: BUSplashAdView) {
		supervc?.view.addSubview(splashAd)
		UserDefaults.standard.setValue(Date().toString(), forKey: "splash.showTime")
		log("chuanshanjia:splashAdDidLoad")
		UGServerLog.ug_log(type: .splashshow,info: ["slotID":splashAd.slotID,"tag":"ioschuanshanjia"])
		
	}
	
	public func splashAdCountdown(toZero splashAd: BUSplashAdView) {
		log("chuanshanjia:splashAdCountdown")
		splashAd.removeFromSuperview()


	}
	public func splashAdDidClickSkip(_ splashAd: BUSplashAdView) {
		log("chuanshanjia:splashAdDidClickSkip")
		splashAd.removeFromSuperview()
	
	
	}
	public func splashAd(_ splashAd: BUSplashAdView, didFailWithError error: Error?) {
		log("chuanshanjia:didFailWithError",error.debugDescription,level: .error)
		finesh(state: .error)
		
		UGServerLog.ug_log(type: .splashloaderror,info: ["slotID":splashAd.slotID,"tag":"ioschuanshanjia"])
	}
		
	public func splashAdWillClose(_ splashAd: BUSplashAdView) {
		log("chuanshanjia:splashAdWillClose")
		finesh(state: .finesh)
		UGServerLog.ug_log(type: .splashhidden,info: ["slotID":splashAd.slotID,"tag":"ioschuanshanjia"])
	}
	
}

extension UGSplash:SJMSplashAdDelegate{
	//  开屏广告素材加载成功
	public func sjm_splashAdDidLoad(_ splashAd: SJMSplashAd) {
		splashAd.showAd(in: app.KWindow!!, withBottomView: nil)
		UserDefaults.standard.setValue(Date().toString(), forKey: "splash.showTime")
		UGServerLog.ug_log(type: .splashshow,info: ["slotID":splashAd.placementId,
											 "tag":"iossanjiaomao"])
	}
	public func sjm_splashAdCountdownEnd(_ splashAd: SJMSplashAd) {
		finesh(state: .finesh)
		UGServerLog.ug_log(type: .splashhidden,info: ["slotID":splashAd.placementId,
											 "tag":"iossanjiaomao"])
	}
	public func sjm_splashAdClosed(_ splashAd: SJMSplashAd) {
		finesh(state: .finesh)
		UGServerLog.ug_log(type: .splashhidden, info: ["slotID":splashAd.placementId,
											 "tag":"iossanjiaomao"])
	}
	
	// 开屏广告错误
	public func sjm_splashAdError(_ splashAd: SJMSplashAd, withError error: Error) {
		UIView.debug(error.ug_localizedDescription )
		finesh(state: .error)
		UGServerLog.ug_log(type: .splashloaderror,info: ["slotID":splashAd.placementId,
											 "tag":"iossanjiaomao"])
	}
}
