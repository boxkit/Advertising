//
//  UGADCollectionView.swift
//  Charts
//
//  Created by admin on 2022/5/1.
//

import Foundation
import UIKit

public class UGADCollectionView:UIView{
	
	private var cutDown = 30
	public weak var delegate:UGADBandleCellDelegate?{
		didSet{
			if let vc = delegate as? UIViewController{
				itemview.supervc = vc
			}
		}
	}
	
	public lazy var express: UGExpress = {
		let ex = UGExpress()
		ex.updateBlock = ({ [weak self] statue in
			guard let self = self else {return}
		
			self.itemview.dataSouce = self.express.views
			self.itemview.reloadData()
			
		})
		return ex
	}()
	lazy var itemview: UGADBandleView = {
		let view = UGADBandleView()
		return view
	}()
	public override init(frame: CGRect) {
		super.init(frame: frame)
		NotificationCenter.default.addObserver(self, selector: #selector(globalDoit), name: UIApplication.timerNotification, object: nil)
		addSubview(itemview)
		DispatchQueue.main.asyncAfter(deadline: .now() + 0.35) {
			self.express.reload()
		}
		
		itemview.snp.makeConstraints { make in
			make.left.right.bottom.top.equalToSuperview()
		}
	}
	
	@objc open func globalDoit(){
		cutDown -= 1
		if cutDown<=0{
			cutDown = 30
			express.reload()
		}
		
	}
	
	required init?(coder: NSCoder) {
		fatalError("init(coder:) has not been implemented")
	}
	
}
