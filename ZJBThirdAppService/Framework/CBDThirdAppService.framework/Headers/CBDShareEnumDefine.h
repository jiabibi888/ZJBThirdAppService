//
//  CBDShareEnumDefine.h
//  CarBaDa
//
//  Created by zjb on 2018/9/21.
//  Copyright © 2018年 wyj. All rights reserved.
//

#ifndef CBDShareEnumDefine_h
#define CBDShareEnumDefine_h

/**
 *  车巴达分享平台枚举
 */
typedef NS_ENUM(NSInteger, CBDSharePlatformType) {
    CBDSharePlatformAll = 0,
    CBDSharePlatformWechatSession = 1,//微信
    CBDSharePlatformWechatTimeline = 2,//朋友圈
    CBDSharePlatformQQ = 3,//QQ
    CBDSharePlatformQZone = 4,//qq空间
    CBDSharePlatformMessage = 5,//短信
    CBDSharePlatformEmergencyContact = 6//紧急联系人 （请求接口外部实现）
};

/**
 *  车巴达分享类型枚举
 */
typedef NS_ENUM(NSInteger, CBDShareContentType) {
    CBDShareContentWebUrl = 1,
    CBDShareContentImageUrl = 2,
    CBDShareContentImagePath = 3,//(混合不支持)
    CBDShareContentVideoUrl = 4,
    CBDShareContentVideoPath = 5,//(混合不支持)
    CBDShareContentAudioUrl = 6,
    CBDShareContentAudioPath = 7,//(混合不支持)
    CBDShareContentMiniProgram = 8,//小程序
    CBDShareContentImageBase64 = 9,
    CBDShareContentFileUrl = 10,
    CBDShareContentFileBase64 = 11
};

/**
 *  第三方app服务响应状态
 */
typedef NS_ENUM(NSUInteger, CBDThirdAppServiceResponseState){
    CBDThirdAppServiceRespStateBegin     = 0,//开始
    CBDThirdAppServiceRespStateSuccess    = 1,//成功
    CBDThirdAppServiceRespStateFail       = 2,//失败
    CBDThirdAppServiceRespStateCancel     = 3,//取消
    CBDThirdAppServiceRespStateBeginUPLoad = 4,//视频文件开始上传
    CBDThirdAppServiceRespStateWaitResult = 5 //支付结果确认中或者支付结果未知
};

#endif /* CBDShareEnumDefine_h */
