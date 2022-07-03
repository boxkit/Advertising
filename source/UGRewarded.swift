//
//  UGRewarded.swift
//  UGAD
//
//  Created by admin on 2022/3/25.
//
// 激励广告
import Foundation
import BUAdSDK

@objc public class UGRewarded:NSObject{
	
    @objc public static let share = UGRewarded()
    @objc public enum RewardedStatus:Int{
		case error = 100
		case skip = 101
		case finesh = 102
		case userskip = 103
	}
	var adview:Any? = nil
	weak var supervc:UIViewController? = nil
	var statusChange:((_ status:RewardedStatus)->())? = nil
	var ignoreTime = false
	var isValidSucceed = false
	/**
	 显示激励广告
	 */
    @objc public func show(_ vc:UIViewController? = nil,
					 ignore:Bool = false,
					 willShow:(()->(Bool))? = nil,
					 block:@escaping (_ status:RewardedStatus)->()){
		isValidSucceed = false
		ignoreTime = ignore
		statusChange = block
		supervc = vc
        guard let data =  UGAD.share.data else {
            log("激励广告-无广告数据")
            if let block = statusChange{
                block(.skip)
            }
            return
        }
		guard  var slot = UGAD.share.data?.jili else{
            log("激励广告-无激励广告")
			if let block = statusChange{
				block(.skip)
			}
			return
		}
		
		
		if slot.status == 2{
            log("激励广告-广告不启用")
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
                log("激励广告-距离上次广告相隔时间小于服务器配置时间")
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
            
        }else{
            log("激励广告-代理返回不显示广告")
            if let block = statusChange{
                block(.skip)
            }
            return
        }

	
	}
	
	
	func rewarded_chuanshanjia(_ slot:UGADModel.UGADItem){
        log("激励广告-加载穿山甲广告")
		let model = BURewardedVideoModel()
		model.userId = app.ug_udid
		let rewardedView = BUNativeExpressRewardedVideoAd.init(slotID: slot.adid, rewardedVideoModel: model)
		rewardedView.delegate = self
		rewardedView.loadData()
		adview = rewardedView
	}
	
	func rewarded_sanjiaomao(_ slot:UGADModel.UGADItem){
        log("激励广告-加载三脚猫广告")
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
        log("激励广告-穿山甲ExpressRewardedVideoAd:\(error.debugDescription)",level: .error)
		if let block = statusChange{
			block(.error)
		}
		UGServerLog.ug_log(type: .rewardedloaderror,info: ["tag":"ioschuanshanjia"])
		
	}
	// 渲染失败，网络原因或者硬件原因导致渲染失败,可以更换手机或者网络环境测试。建议升级到穿山甲平台最新版本
	public func nativeExpressRewardedVideoAdViewRenderFail(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd, error: Error?) {
        log("激励广告-穿山甲ExpressRewardedVideoAdViewRenderFail:\(error.debugDescription)",level: .error)
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
        log("激励广告-穿山甲视频加载成功,开始显示")
		rewardedVideoAd.show(fromRootViewController: vc)
	
		UGServerLog.ug_log(type: .expressshow,info: ["tag":"ioschuanshanjia"])
	}
	// 用户关闭广告时会触发此回调，注意：任何广告的关闭操作必须用户主动触发;
	public func nativeExpressRewardedVideoAdDidClose(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd) {
		
        log("激励广告-穿山甲用户关闭广告")
		if let block = statusChange{
			if isValidSucceed{
				block(.skip)
			}else{
				block(.userskip)
			}
		}
		UGServerLog.ug_log(type: .expresshidden,info: ["tag":"ioschuanshanjia"])
	
	
	}
	
	public func nativeExpressRewardedVideoAdServerRewardDidSucceed(_ rewardedVideoAd: BUNativeExpressRewardedVideoAd, verify: Bool) {
        log("激励广告-穿山甲触发有效激励")
		isValidSucceed = true
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
        log("激励广告-三脚猫 视频数据下载成功回调 rewardVideoAdVideoDidLoad")
		if let adview = adview as? SJMRewardVideoAd{
			adview.show(in: vc)
	
		}
		UGServerLog.ug_log(type: .expressshow,info: ["tag":"iossanjiaomao"])
	
	}
	public func sjm_rewardVideoAdDidClose(_ rewardedVideoAd: SJMRewardVideoAd) {
        log("激励广告-三脚猫 广告关闭")
		if let block = statusChange{
			block(.finesh)
		}
		UGServerLog.ug_log(type: .expresshidden,info: ["tag":"iossanjiaomao"])
		
	}
	public func sjm_rewardVideoAd(_ rewardedVideoAd: SJMRewardVideoAd, didFailWithError error: Error) {
        log("激励广告-三脚猫 rewardVideoAd:\(error)",level: .error)
		if let block = statusChange{
			block(.error)
		}
		UGServerLog.ug_log(type: .expressloaderror,info: ["tag":"iossanjiaomao"])
	}
	public func sjm_rewardVideoAdDidRewardEffective(_ rewardedVideoAd: SJMRewardVideoAd) {
        log("激励广告-三脚猫 触发有效激励")
		if !ignoreTime{
			UserDefaults.standard.setValue(Date().toString(), forKey: "ugad.rewarded.showTime")
		}
	}
	
}
