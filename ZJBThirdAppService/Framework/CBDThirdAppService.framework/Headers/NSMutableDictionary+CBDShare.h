//
//  NSMutableDictionary+CBDShare.h
//  CarBaDa
//
//  Created by zjb on 2018/9/21.
//  Copyright © 2018年 wyj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CBDShareEnumDefine.h"
#import <UIKit/UIKit.h>

@interface NSMutableDictionary (CBDShare)
/**
 *  设置分享参数
 *
 *  @param text         文本
 *  @param title        标题
 *  @param url          分享链接
 *  @param thumbImage   缩略图，可以为UIImage、NSString（图片路径）、NSURL（图片路径）、NSData（二进制文件）
 *  @param image        图片，可以为UIImage、NSString（图片路径）、NSURL（图片路径）、NSData（二进制文件）
 *  @param file         文件，可以为NSString（图片路径）、NSURL（文件路径）、NSData（二进制文件）
 *  @param fileName         文件名
 *  @param fileExtension        文件后缀名
 *  @param type         分享类型，CBDShareContentType
 *  @param platformSubType 平台子类型，CBDSharePlatformType
 *
 */
- (void)CBDShareSetupParamsByText:(NSString *)text
                            title:(NSString *)title
                              url:(NSString *)url
                       thumbImage:(id)thumbImage
                            image:(id)image
                             file:(id)file
                         fileName:(NSString *)fileName
                    fileExtension:(NSString *)fileExtension
                             type:(CBDShareContentType)type
               forPlatformSubType:(CBDSharePlatformType)platformSubType;


/**
 短信分享内容

 @param text 短信内容
 @param phoneNumber 电话号码数组
 @param type 分享类型
 @param platformSubType 平台类型
 */
- (void)CBDShareSetupMessageParamsByText:(NSString *)text
                                  phoneNumber:(NSArray *)phoneNumber
                                   type:(CBDShareContentType)type
                     forPlatformSubType:(CBDSharePlatformType)platformSubType;

/**
微信小程序分享增加
 
 @param title 标题
 @param description 详细说明
 @param webpageUrl 网址（6.5.6以下版本微信会自动转化为分享链接 必填）
 @param path 跳转到页面路径
 @param thumbImage 缩略图 , 旧版微信客户端（6.5.8及以下版本）小程序类型消息卡片使用小图卡片样式 要求图片数据小于32k
 @param hdThumbImage 高清缩略图，建议长宽比是 5:4 ,6.5.9及以上版本微信客户端小程序类型分享使用 要求图片数据小于128k
 @param userName 小程序的userName （必填）
 @param withShareTicket 是否使用带 shareTicket 的转发
 @param miniProgramType 分享小程序的版本（0-正式，1-开发，2-体验）
 @param platformSubType 分享自平台 微信小程序暂只支持 SSDKPlatformSubTypeWechatSession（微信好友分享)
 */
- (void)CBDShareSetupWeChatMiniProgramShareParamsByTitle:(NSString *)title
                                             description:(NSString *)description
                                              webpageUrl:(NSString *)webpageUrl
                                                    path:(NSString *)path
                                              thumbImage:(id)thumbImage
                                            hdThumbImage:(id)hdThumbImage
                                                userName:(NSString *)userName
                                         withShareTicket:(BOOL)withShareTicket
                                         miniProgramType:(NSUInteger)miniProgramType
                                      forPlatformSubType:(CBDSharePlatformType)platformSubType;



@end
