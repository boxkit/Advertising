//
//  ADAPI.swift
//  ad_csj
//
//  Created by admin on 2022/3/25.
//

import Foundation

import UGExtension

extension Session{
	
	func api_adList() -> DataRequest{
		let url = "\(wordapi1.loc)/api/v1/App/GetAdvert"
		var param = ["os":"2"]
        param["version"] = wordVerstion.loc
        param["packagename"] = app.shared.uh_bundleIdentifier
		return AF.request(url, method: .get, parameters: param)
	}
}
