//
//  SGdownloader.m
//  downloadManager
//
//  Created by saturngod on 11/7/12.
//

#import "SGdownloader.h"

@interface SGdownloader()
@property (nonatomic,assign) float receiveBytes;
@property (nonatomic,assign) float exceptedBytes;
@property (nonatomic,retain) NSMutableURLRequest *request;

//for block
@property (nonatomic,copy) SGDownloadProgressBlock progressDownloadBlock;
@property (nonatomic,copy) SGDowloadFinished progressFinishBlock;
@property (nonatomic,copy) SGDownloadFailBlock progressFailBlock;

@end

@implementation SGdownloader
@synthesize receiveData = _receiveData;
@synthesize request = _request;
@synthesize connection = _connection;
@synthesize downloadedPercentage = _downloadedPercentage;
@synthesize receiveBytes;
@synthesize exceptedBytes;
@synthesize progress = _progress;
@synthesize progressFailBlock = _progressFailBlock;
@synthesize progressDownloadBlock = _progressDownloadBlock;
@synthesize progressFinishBlock = _progressFinishBlock;
@synthesize delegate = _delegate;

-(id)initWithURL:(NSURL *)fileURL timeout:(NSInteger)timeout{
    if(self = [super init])
    {
        self.receiveBytes = 0;
        self.exceptedBytes = 0;
        _receiveData = [[NSMutableData alloc] initWithLength:0];
        _downloadedPercentage = 0.0f;
        self.request = [[NSMutableURLRequest alloc] initWithURL:fileURL cachePolicy:NSURLRequestReloadIgnoringCacheData timeoutInterval:timeout];
        self.connection = [NSURLConnection connectionWithRequest:self.request delegate:self];
    }
    return self;
}


- (id)initWithURL:(NSURL *)fileURL timeout:(NSInteger)timeout startBytes:(int)startbyte {
    if(self = [super init])
    {
        self.receiveBytes = 0;
        self.exceptedBytes = 0;
        _receiveData = [[NSMutableData alloc] initWithLength:0];
        _downloadedPercentage = 0.0f;
        self.request = [[NSMutableURLRequest alloc] initWithURL:fileURL cachePolicy:NSURLRequestReloadIgnoringLocalCacheData timeoutInterval:timeout];
        [self.request setValue:[NSString stringWithFormat:@"bytes=%d-",startbyte] forKey:@"Range"];
        self.connection = [NSURLConnection connectionWithRequest:self.request delegate:self];
    }
    return self;
}

#pragma mark - NSURLConnectionDataDelegate

- (void)dealloc {
    [_request release];
    [_receiveData release];//Instrument_leaks 6.30_lzq
    [super dealloc];
}

-(void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [_receiveData appendData:data];
    
    NSInteger len = [data length];
    receiveBytes = receiveBytes + len;
    
    if(exceptedBytes != NSURLResponseUnknownLength) {
        _progress = ((receiveBytes/(float)exceptedBytes) * 100)/100;
        _downloadedPercentage = _progress * 100;
        
        if([_delegate respondsToSelector:@selector(SGDownloadProgress:Percentage:)])
        {
            [_delegate SGDownloadProgress:_progress Percentage:_downloadedPercentage];
        }
        else {
            if(_progressDownloadBlock) {
                _progressDownloadBlock(_progress,_downloadedPercentage);
            }
        }
    }
    
}

-(void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    //return back error
    if([_delegate respondsToSelector:@selector(SGDownloadFail:)])
    {
        [_delegate SGDownloadFail:error];
    }
    else {
        if(_progressFailBlock) {
            _progressFailBlock(error);
        }
    }
}

-(void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    exceptedBytes = [response expectedContentLength];
}

-(void)connectionDidFinishLoading:(NSURLConnection *)connection {
    self.connection = nil;
    
    if([_delegate respondsToSelector:@selector(SGDownloadFinished:)])
    {
        [_delegate SGDownloadFinished:_receiveData];
    }
    else {
        if(_progressFinishBlock) {
            _progressFinishBlock(_receiveData);
        }
    }
}

#pragma mark - properties
-(void)startWithDelegate:(id<SGdownloaderDelegate>)delegate {
    _delegate = delegate;
    if(self.connection) {
        [self.connection start];
        _progressDownloadBlock= nil;
        _progressFinishBlock = nil;
        _progressFailBlock = nil;
    }
}
-(void)startWithDownloading:(SGDownloadProgressBlock)progressBlock onFinished:(SGDowloadFinished)finishedBlock onFail:(SGDownloadFailBlock)failBlock {
    if(self.connection) {
        [self.connection start];
        _delegate = nil; //clear delegate
        _progressDownloadBlock = [progressBlock copy];
        _progressFinishBlock = [finishedBlock copy];
        _progressFailBlock = [failBlock copy];
    }
    
}
-(void)cancel {
    if(self.connection) {
        [self.connection cancel];
    }
}
@end
