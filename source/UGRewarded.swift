//
//  UGRewarded.swift
//  UGAD
//
//  Created by admin on 2022/3/25.
//
// 激励广告
import Foundation
import BUAdSDK

public class UGRewarded:NSObject{
	
	public static let share = UGRewarded()
	public enum RewardedStatus:Int{
		case error = 100
		case skip = 101
		case finesh = 102
	}
	var adview:Any? = nil
	weak var supervc:UIViewController? = nil
	var statusChange:((_ status:RewardedStatus)->())? = nil
	var ignoreTime = false
	/**
	 显示激励广告
	 */
	public func show(_ vc:UIViewController? = nil,
					 ignore:Bool = false,
					 willShow:(()->(Bool))? = nil,
					 block:@escaping (_ status:RewardedStatus)->()){
		ignoreTime = ignore
		statusChange = block
		supervc = vc
		guard  var slot = UGAD.share.data?.jili else{
			if let block = statusChange{
				block(.skip)
			}
			return
		}
		
		guard let data =  UGAD.share.data else {
			if let block = statusChange{
				block(.skip)
			}
			return
		}
		if slot.status == 2{
			if let block = statusChange{
				block(.skip)
			}
			return
		}
		if ignore == true{
			slot.time = "0"
		}

		if let date = UserDefaults.standard.string(forKey: "ugad.rewarded.showTime"){
			let abs = (date.date().timeIntervalSinceNow)+slot.time.double()
			
			if abs>0{
				if let block = statusChange{
					block(.skip)
				}
				return
			}
		}
		if let willblock = willShow,
		   willblock() == true{
			if data.tag == "ioschuanshanjia"{
				rewarded_chuanshanjia(slot)
			}else if data.tag == "iossanjiaomao"{
				rewarded_sanjiaomao(slot)
			}
			// 加载激励广告
			UGServerLog.ug_log(type: .rewardedload,info: ["slotID":slot.adid,
												 "tag":data.tag,
												 "adID":data.adid,
												])
		}

	
	}
	
	
	func rewarded_chuanshanjia(_ slot:UGADModel.UGADItem){
		
		let model = BURewardedVideoModel()
		model.userId = app.ug_udid
		let rewardedView = BUNativeExpressRewardedVideoAd.init(slotID: slot.adid, rewardedVideoModel: model)
		rewardedView.delegate = self
		rewardedView.loadData()
		adview = rewardedView
	}
	
	func rewarded_sanjiaomao(_ slot:UGADModel.UGADItem){
	
		let model = SJMRewardVideoModel()
		model.userId = app.ug_udid
		model.reward_name = word0008.loc
		model.reward_amount = 10
		let rewardedView = SJMRewardVideoAd.init(placementId:slot.adid, rewardedVideoModel: model)

		rewardedView.delegate = self
		rewardedView.load()
		adview = rewardedView
	}
	
}

// 信息流的委托
extension UGRewarded:BUNativeExpressRewardedVideoAdDelegate{
	// 返回的错误码(error)表示广告加载失败的原因，所有错误码详情请见链接
	public func nativeExpressRewardedVideoAd(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd, didFailWithError error: Error?) {
		if let block = statusChange{
			block(.error)
		}
		UGServerLog.ug_log(type: .rewardedloaderror,info: ["tag":"ioschuanshanjia"])
		
	}
	// 渲染失败，网络原因或者硬件原因导致渲染失败,可以更换手机或者网络环境测试。建议升级到穿山甲平台最新版本
	public func nativeExpressRewardedVideoAdViewRenderFail(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd, error: Error?) {
		if let block = statusChange{
			block(.error)
		}
		UGServerLog.ug_log(type: .rewardedshowerror,info: ["tag":"ioschuanshanjia"])
	}
	
	
	// 广告素材物料加载成功
	public func nativeExpressRewardedVideoAdDidLoad(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd) {
		
	}
	// 视频下载完成
	public func nativeExpressRewardedVideoAdDidDownLoadVideo(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd) {
		guard let vc:UIViewController = self.supervc  else {
			return
		}
		rewardedVideoAd.show(fromRootViewController: vc)
	
		UGServerLog.ug_log(type: .expressshow,info: ["tag":"ioschuanshanjia"])
	}
	// 用户关闭广告时会触发此回调，注意：任何广告的关闭操作必须用户主动触发;
	public func nativeExpressRewardedVideoAdDidClose(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd) {
		
		if let block = statusChange{
			block(.finesh)
		}
		UGServerLog.ug_log(type: .expresshidden,info: ["tag":"ioschuanshanjia"])
	
	
	}
	
	public func nativeExpressRewardedVideoAdServerRewardDidSucceed(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd, verify: Bool) {
		if !ignoreTime && verify{
			UserDefaults.standard.setValue(Date().toString(), forKey: "ugad.rewarded.showTime")
		}
	}


}


extension UGRewarded:SJMRewardVideoAdDelegate{
	// 视频数据下载成功回调，已经下载过的视频会直接回调
	public func sjm_rewardVideoAdVideoDidLoad(_ rewardedVideoAd: SJMRewardVideoAd) {
	
		guard let vc:UIViewController = supervc  else {
			return
		}
		if let adview = adview as? SJMRewardVideoAd{
			adview.show(in: vc)
	
		}
		UGServerLog.ug_log(type: .expressshow,info: ["tag":"iossanjiaomao"])
	
	}
	public func sjm_rewardVideoAdDidClose(_ rewardedVideoAd: SJMRewardVideoAd) {
		if let block = statusChange{
			block(.finesh)
		}
		UGServerLog.ug_log(type: .expresshidden,info: ["tag":"iossanjiaomao"])
		
	}
	public func sjm_rewardVideoAd(_ rewardedVideoAd: SJMRewardVideoAd, didFailWithError error: Error) {
		if let block = statusChange{
			block(.error)
		}
		UGServerLog.ug_log(type: .expressloaderror,info: ["tag":"iossanjiaomao"])
	}
	public func sjm_rewardVideoAdDidRewardEffective(_ rewardedVideoAd: SJMRewardVideoAd) {
		if !ignoreTime{
			UserDefaults.standard.setValue(Date().toString(), forKey: "ugad.rewarded.showTime")
		}
	}
	
}
