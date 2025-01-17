//
//  Copyright (c) 2021 Open Whisper Systems. All rights reserved.
//

#import <CocoaLumberjack/DDFileLogger.h>

NS_ASSUME_NONNULL_BEGIN

@interface DebugLogger : NSObject

+ (instancetype)shared;

- (void)enableFileLogging;

- (void)disableFileLogging;

- (void)enableTTYLogging;

- (void)enableErrorReporting;

@property (nonatomic, readonly) NSURL *errorLogsDir;

- (void)wipeLogs;

- (void)removeObsoleteDebugLogs;

- (NSArray<NSString *> *)allLogFilePaths;

@property (nonatomic, readonly, class) NSString *mainAppDebugLogsDirPath;
@property (nonatomic, readonly, class) NSString *shareExtensionDebugLogsDirPath;
@property (nonatomic, readonly, class) NSString *nseDebugLogsDirPath;
#ifdef TESTABLE_BUILD
@property (nonatomic, readonly, class) NSString *testDebugLogsDirPath;
#endif

@end

#pragma mark -

@interface ErrorLogger : DDFileLogger

+ (void)playAlertSound;

@end

NS_ASSUME_NONNULL_END
