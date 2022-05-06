//
//  view.swift
//  Alamofire
//
//  Created by admin on 2022/3/26.
//

import Foundation



public protocol UGADBandleCellDelegate:NSObjectProtocol{
	func bandleCellDidUpdate(cell:UGADBandleCell)
}
public class UGADBandleCell:UICollectionViewCell{
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
			
			self.delegate?.bandleCellDidUpdate(cell: self)
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

public class UGADBandleView:UGBandle{
	
	
	public class UGADCell:UICollectionViewCell{
		
		public override init(frame: CGRect) {
			super.init(frame: frame)
		}
		
		required init?(coder: NSCoder) {
			fatalError("init(coder:) has not been implemented")
		}
		
	}
	
	private var isdisshow = false;
	private var adcutDown = 30
	weak public var supervc:UIViewController? = nil
	
	override init(frame: CGRect) {
		super.init(frame: frame)
	}
	
	public override func makeLayout() {
		collectView.snp.makeConstraints { make in
			make.left.right.top.equalToSuperview()
			make.height.equalToSuperview()
		}
		pageControl.isHidden = true
	}
	
	
	required init?(coder: NSCoder) {
		fatalError("init(coder:) has not been implemented")
	}
	public override func makeConfig() {
		collectView.register(UGADCell.self, forCellWithReuseIdentifier: "UGADCell")
		
	}
	public override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
		return dataSouce.count
	}
	public override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
		let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "UGADCell", for: indexPath) as! UGADCell
		if let view = cell.contentView.viewWithTag(101){
			view.removeFromSuperview()
		}
		if let view = dataSouce.value(at: indexPath.row) as? BUNativeExpressAdView{
			cell.contentView.addSubview(view)
			view.render()
			view.tag = 101
			view.rootViewController = supervc
			view.snp.makeConstraints { make in
				make.top.left.right.bottom.equalToSuperview()
			}
		}else if let feedad = dataSouce.value(at: indexPath.row) as? SJMNativeExpressFeedAd{
			let view = feedad.feedView
			view.tag = 101
			cell.contentView.addSubview(view)
			view.snp.makeConstraints { make in
				make.top.left.right.bottom.equalToSuperview()
			}
			
			feedad.rootViewController = supervc
			feedad.render()
			
		}
		return cell
	}
	
}



