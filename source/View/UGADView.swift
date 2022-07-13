//
//  view.swift
//  Alamofire
//
//  Created by admin on 2022/3/26.
//

import Foundation



@objc public protocol UGADBandleCellDelegate:NSObjectProtocol{
	func isEnableReload()->Bool
	func bandleCellDidUpdate(express:UGExpress)
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
			self.itemview.dataSouce = self.express.views
			self.itemview.reloadData()
            self.delegate?.bandleCellDidUpdate(express: ex)
			
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
		contentView.addSubview(itemview)
		DispatchQueue.main.asyncAfter(deadline: .now() + 0.35) {
			self.express.reload()
		}
		itemview.snp.makeConstraints { make in
			make.edges.equalToSuperview()
		}
		
	}
	public func reloadData(){
		
		itemview.snp.remakeConstraints() { make in
			make.edges.equalToSuperview()
		}
	
		itemview.reloadData()

	}
	
	@objc open func globalDoit(){
		cutDown -= 1
		if cutDown<=0{
			cutDown = 30
			
			if delegate?.isEnableReload() == false{
				return
			}
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
		
		public override func layoutSubviews() {
			super.layoutSubviews()
			if let view = contentView.viewWithTag(101){
				view.snp.remakeConstraints { make in
					make.top.left.right.bottom.equalToSuperview()
				}
			}
			
		}
		
	}
	
	private var isdisshow = false;
	private var adcutDown = 30
	public var supervc:UIViewController? = nil
	
	override init(frame: CGRect) {
		super.init(frame: frame)
	}
	
	public override func makeLayout() {
		collectView.snp.makeConstraints { make in
			make.edges.equalToSuperview()
		}
		pageControl.isHidden = true
	}
	
	
	required init?(coder: NSCoder) {
		fatalError("init(coder:) has not been implemented")
	}
	public override func reloadData() {
		super.reloadData()
		
		self.collectView.reloadData()
		
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
		
			view.render()
			view.tag = 101
			view.rootViewController = supervc
			cell.contentView.addSubview(view)
			
		}
        #if canImport(SJMAdSDK)
//        else if let feedad = dataSouce.value(at: indexPath.row) as? SJMNativeExpressFeedAd{
			let view = feedad.feedView
			view.tag = 101
			feedad.rootViewController = supervc
			feedad.render()
			cell.contentView.addSubview(view)

//		}
        #endif
       
		return cell
	}
	
	public override func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
		
		return .init(width: bounds.size.width, height: 120)
	}
	
}



