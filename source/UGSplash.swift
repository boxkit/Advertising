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
	public static let UGSplashfinishNotification = NSNotification.Name("UGSplashfinishNotification")
	
	public static let share = UGSplash()
	public enum SplashStatus:Int{
		case error = 100
		case skip = 101
		case finish = 102
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
			finish(state: .none)
			return
		}
		guard let slot = UGAD.share.data?.kaiping else{
			finish(state: .none)
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

	}
	
	func splash_chuanshanjia(_ slot:UGADModel.UGADItem){
		
		
		if let date = UserDefaults.standard.string(forKey: "splash.showTime"),
		   -(date.date().timeIntervalSinceNow)<slot.time.double() {
			finish(state: .skip)
			return
			
		}

		let frame = UIScreen.main.bounds
		let splashAdView = BUSplashAdView(slotID: slot.adid, frame: frame)
	
		splashAdView.tolerateTimeout = 100
		splashAdView.delegate = self
		
		splashAdView.rootViewController = supervc
		
		app.KWindow?.addSubview(splashAdView)
		adview = splashAdView
		splashAdView.loadAdData()
		
	}
#if canImport(SJMAdSDK)
	func splash_sanjiaomao(_ slot:UGADModel.UGADItem){
	
		if let date = UserDefaults.standard.string(forKey: "splash.showTime"),
		   -(date.date().timeIntervalSinceNow)<slot.time.double() {
			finish(state: .skip)
			return
			
		}
		
		let splashAd = SJMSplashAd.init(placementId:slot.adid)
		splashAd.fetchDelay = 5;
		splashAd.delegate = self;
		splashAd.bottomViewSize = .init(width: app.KWidth, height: 50)
		splashAd.loadAd()

	}
#else
    func splash_sanjiaomao(_ slot:UGADModel.UGADItem){
    }
#endif
	func finish(state:SplashStatus){
		if let block = statusChange{
			block(state)
		}
		NotificationCenter.default.post(name:Self.UGSplashfinishNotification , object: nil)
	}
}

extension UGSplash:BUSplashAdDelegate{
	// 广告加载成功回调
	public func splashAdDidLoad(_ splashAd: BUSplashAdView) {
		supervc?.view.addSubview(splashAd)
		UserDefaults.standard.setValue(Date().toString(), forKey: "splash.showTime")

		
	}
	
	public func splashAdCountdown(toZero splashAd: BUSplashAdView) {
		splashAd.removeFromSuperview()


	}
	public func splashAdDidClickSkip(_ splashAd: BUSplashAdView) {
		splashAd.removeFromSuperview()
	
	
	}
	public func splashAd(_ splashAd: BUSplashAdView, didFailWithError error: Error?) {
		log("穿山甲开屏广告错误\(error)")
		finish(state: .error)

	}
		
	public func splashAdWillClose(_ splashAd: BUSplashAdView) {
		finish(state: .finish)

	}
	
}
#if canImport(SJMAdSDK)
extension UGSplash:SJMSplashAdDelegate{
	//  开屏广告素材加载成功
	public func sjm_splashAdDidLoad(_ splashAd: SJMSplashAd) {
		splashAd.showAd(in: app.KWindow!, withBottomView: nil)
		UserDefaults.standard.setValue(Date().toString(), forKey: "splash.showTime")

	}
	public func sjm_splashAdCountdownEnd(_ splashAd: SJMSplashAd) {
		finish(state: .finish)

	}
	public func sjm_splashAdClosed(_ splashAd: SJMSplashAd) {
		finish(state: .finish)

	}
	
	// 开屏广告错误
	public func sjm_splashAdError(_ splashAd: SJMSplashAd, withError error: Error) {
		UIView.debug(error.uh_localizedDescription )
		finish(state: .error)

	}
}
#endif
