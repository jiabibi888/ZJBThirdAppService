#
# Be sure to run `pod lib lint ZJBThirdAppService.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZJBThirdAppService'
  s.version          = '0.1.0'
  s.summary          = 'ZJBThirdAppService provide share and pay service.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
iOS_CBDThirdService提供第三方服务，包括分享（微信、qq、短信等）、支付（支付宝、qq）.
                       DESC

  s.homepage         = 'https://github.com/jiabibi888/ZJBThirdAppService'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'jiabibi888' => 'zjb11934@ly.com' }
  s.source           = { :git => 'https://github.com/jiabibi888/ZJBThirdAppService.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'ZJBThirdAppService/Classes/SGdownloadManager/*'
  s.vendored_frameworks = 'ZJBThirdAppService/Framework/CBDThirdAppService.framework', 'ZJBThirdAppService/Framework/Alipay/*', 'ZJBThirdAppService/Framework/TencentOpenAPI/*', 'ZJBThirdAppService/Framework/WechatOpenSDK/*'
  s.resource = 'ZJBThirdAppService/Framework/CBDThirdAppService.bundle'
    # s.resource_bundles = {
  #   'ZJBThirdAppService' => ['ZJBThirdAppService/Assets/*.png']
  # }


  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit', 'WebKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
