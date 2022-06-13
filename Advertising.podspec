Pod::Spec.new do |spec|
	
	spec.name         = "Advertising"
	spec.version      = "1.0.0"
	spec.summary      = "用户信息"
	
	spec.description  = "ios用户信息"
	
	spec.homepage     = "http://github/ubungit.git"
	spec.license      = "MIT"
	
	spec.author             = { "静静地白色外套" => "296019487@qq.com" }
	
	spec.platform     = :ios, "11.0"

	spec.vendored_frameworks = 'SJM/**/*.framework'
	spec.vendored_libraries = 'SJM/**/*.a'
	spec.frameworks = 'UIKit', 'MapKit', 'WebKit', 'MediaPlayer', 'CoreLocation', 'AdSupport', 'CoreMedia', 'AVFoundation', 'CoreTelephony', 'StoreKit', 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion', 'Accelerate','AudioToolbox','JavaScriptCore','Security','CoreImage','AudioToolbox','ImageIO','QuartzCore','CoreGraphics','CoreText'
	
	spec.weak_framework = 'AppTrackingTransparency'
	
	
	spec.libraries = 'c++', 'resolv', 'z', 'sqlite3', 'bz2', 'xml2', 'iconv', 'c++abi'

	spec.source       = { :git => "http://github/ubungit.git", :tag => "#{spec.version}" }
	
	spec.source_files  =  [
  "Advertising.swift",
  "source/**/*.{h,m,swift}",
  "SJM/SJMGDT/*.{h,m,swift}"
  ]
	spec.static_framework = true
	
	spec.pod_target_xcconfig = {
		'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
	}
	
	spec.dependency 'Ads-CN'
	spec.dependency 'HandyJSON'
  
  spec.dependency 'UGNetwork'
  spec.dependency 'UGBase'
  spec.dependency 'UGConfig'
  spec.dependency 'UGAlert'
  spec.dependency 'UGServerLog'
  
	
	
	
	spec.prefix_header_contents = <<-EOS
	
	
	EOS
	
end
