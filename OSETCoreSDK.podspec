Pod::Spec.new do |s|
  s.name         = "OSETCoreSDK"
  s.version      = "7.0.2.5"
  s.summary      = "奇点广告对接"
  s.description  = <<-DESC
                      OSETCoreSDK 是一个专业的广告SDK，提供高效的广告展示和收益优化功能。
                    DESC
  s.homepage     = "https://github.com/OSETSDK/OSETCoreSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { 'shenshi' => 'yaohaofei@shenshiads.com' }
  
  # 设置最低支持版本
  s.ios.deployment_target = '12.0'
  
  # 源文件配置
  s.source       = {
    :git => 'https://github.com/OSETSDK/OSETCoreSDK.git',
    :tag => s.version.to_s
  }
  
  # 主框架文件
  s.source_files = 'OSETCoreSDK/**/*.{h,m}'

  # 系统框架依赖
  s.frameworks = "Foundation", "UIKit", "AdSupport", "CoreTelephony", "StoreKit", "SystemConfiguration"

  # Swift版本设置
  s.swift_version = '5.0'
  
  s.dependency 'OSETCoreAd'
  s.dependency 'AdSetQDAAdapter'
  s.dependency 'AdSetQDBAdapter'
  s.dependency 'AdSetQDCAdapter'

end
