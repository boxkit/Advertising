//
//  ADAPI.swift
//  ad_csj
//
//  Created by admin on 2022/3/25.
//

import Foundation


extension Session{
	
	func api_adList() -> DataRequest{
		let url = "\(wordapi1.loc)/api/v1/App/GetAdvert"
		let param = ["os":"2"]
		return AF.request(url, method: .get, parameters: param)
	}
}
