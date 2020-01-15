//
//  CBDThirdAppService.h
//  CBDThirdAppService
//
//  Created by Jabir-Zhang on 2019/12/25.
//  Copyright © 2019 CBDThirdAppService. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for CBDThirdAppService.
FOUNDATION_EXPORT double CBDThirdAppServiceVersionNumber;

//! Project version string for CBDThirdAppService.
FOUNDATION_EXPORT const unsigned char CBDThirdAppServiceVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CBDThirdAppService/PublicHeader.h>

#import <CBDThirdAppService/CBDShareEnumDefine.h>
#import <CBDThirdAppService/NSMutableDictionary+CBDShare.h>

NS_ASSUME_NONNULL_BEGIN

/**
 第三方分享状态回调
 
 @param state 返回状态
 @param platformType 平台类型
 @param options 详细信息（可扩展）
 @param error 错误信息
 */
typedef void (^CBDShareStateChangedHandler) (CBDThirdAppServiceResponseState state,
                                             CBDSharePlatformType platformType,
                                             NSDictionary * _Nullable options,
                                             NSError * _Nullable error);

/**
 第三方支付回调
 
 @param state 支付结果状态码
 @param errStr 错误描述
 */
typedef void (^CBDThirdAppPayHandler) (CBDThirdAppServiceResponseState state,NSString *errStr);

/**
 第三方登录回调
 
 @param state 登录结果状态码
 @param code 登录成功后唯一性的标志
 */
typedef void (^CBDThirdAppLoginHandler) (CBDThirdAppServiceResponseState state,NSString *code);

@interface CBDThirdAppService : NSObject
/**
 注册服务单例
 
 @return 自身第三方服务单例
 */
+ (instancetype)registerService;


/**
 第三方回调服务处理
 
 @param url 回调url
 @return 成功返回YES，失败返回NO
 */
+ (BOOL)handleOpenURL:(NSURL *)url;//处理回调服务

+ (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;//处理回调服务

#pragma mark - 第三方分享
/**
 弹出分享菜单
 
 @param platforms  要分享的平台，如果传入nil，则显示已集成的平台列表
 @param shareParams 分享内容参数
 @param stateChangedHandler 分享状态变更事件
 */
+ (void)showShareActionSheetWithPlatforms:(NSArray *)platforms
                              shareParams:(NSMutableDictionary *)shareParams
                           onStateChanged:(CBDShareStateChangedHandler)stateChangedHandler;


/**
 分享
 
 @param platformType 要分享的平台，如果传入nil，则显示已集成的平台列表
 @param shareParams 分享内容参数
 @param stateChangedHandler 分享状态变更事件
 */
+ (void)shareWithPlatformType:(CBDSharePlatformType)platformType
                  shareParams:(NSMutableDictionary *)shareParams
               onStateChanged:(CBDShareStateChangedHandler)stateChangedHandler;


/**
 获取全部分享平台集合

 @return 全部分享平台集合
 */
//+ (NSArray *)allPlatforms;


/**
 获取额外添加短信和紧急联系人的全部分享平台集合，

 @return 全部分享平台集合，增加短信和紧急联系人
 */
+ (NSArray *)allPlatformsExtraMessageAndContact;

#pragma mark - 第三方支付
/**
 微信支付
 */
+ (void)weChatPayWithPartnerId:(NSString *)partnerId
                      prepayId:(NSString *)prepayId
                       package:(NSString *)package
                      nonceStr:(NSString *)nonceStr
                     timeStamp:(NSString *)timeStamp
                          sign:(NSString *)sign
              payResultHandler:(CBDThirdAppPayHandler)payResultHandler;

/**
 支付宝支付服务
 */
+ (void)aliPayWithOrderStr:(NSString *)orderStr
                fromScheme:(NSString *)schemeStr
          payResultHandler:(CBDThirdAppPayHandler)payResultHandler;

#pragma mark - 第三方登录
/**
 微信登录
 
 @param scope scope
 @param state state
 @param loginResultHandler 登录成功回调
 */
+ (void)weChatLoginWithScope:(NSString *)scope
                       state:(NSString *)state
          loginResultHandler:(CBDThirdAppLoginHandler)loginResultHandler;

/**
 QQ登录
 
 @param loginResultHandler 登录成功回调
 */
+ (void)qqLoginWithLoginResultHandler:(CBDThirdAppLoginHandler)loginResultHandler;

/**
 支付宝登录
 
 @param infoStr     授权请求信息字串
 @param schemeStr       调用授权的app注册在info.plist中的scheme
 @param loginResultHandler 登录结果回调
 */
+ (void)aliPayLoginWithInfo:(NSString *)infoStr
                 fromScheme:(NSString *)schemeStr
         loginResultHandler:(CBDThirdAppLoginHandler)loginResultHandler;

#pragma mark - 微信基础服务
/**
 注册微信服务
 
 @param appid 微信后台appid
 @return 成功返回YES，失败返回NO
 */
+ (BOOL)registerAppForWeChat:(NSString *)appid;

/*! @brief 检查微信是否已被用户安装
 *
 * @return 微信已安装返回YES，未安装返回NO。
 */
+(BOOL) isWXAppInstalled;

/*! @brief 判断当前微信的版本是否支持OpenApi
 *
 * @return 支持返回YES，不支持返回NO。
 */
+(BOOL) isWXAppSupportApi;

/**
 打开微信小程序

 @param userName 拉起的小程序的username
 @param path 拉起小程序页面的可带参路径，不填默认拉起小程序首页
 @param resultHandler 打开结果回调
 */
+(void)openWeChatMiniProgram:(NSString *)userName path:(NSString *)path resultHandler:(nullable void(^)(CBDThirdAppServiceResponseState state,NSString *extMsg))resultHandler;


/**
 打开微信内部浏览器

 @param sUrl 网页url
 */
+(void)openWeChatWebview:(NSString *)sUrl;

/// 打开微信支付分
/// @param query query
+(void)openWeChatBusinessView:(NSString *)query;
#pragma mark - QQ基础服务

/**
 注册QQ服务
 
 @param appid QQ后台appid
 */
+ (void)registerAppForQQ:(NSString *)appid;

/**
 检测是否已安装QQ
 
 @return 如果QQ已安装则返回YES，否则返回NO
 */
+ (BOOL)isQQInstalled;


/**
 检测是否支持分享
 
 @return 如果当前已安装QQ且QQ版本支持API调用 或者 当前已安装TIM且TIM版本支持API调用则返回YES，否则返回NO
 */
+ (BOOL)isSupportShareToQQ;
@end

NS_ASSUME_NONNULL_END
