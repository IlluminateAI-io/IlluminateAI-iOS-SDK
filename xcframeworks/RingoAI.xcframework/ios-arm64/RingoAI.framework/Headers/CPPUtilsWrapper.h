//
//  CPPUtilsWrapper.h
//  MySkin
//
//  Created by Sagar Bhosale on 17/02/24.
//
#import <Foundation/Foundation.h>
#import <AVFoundation/AVDepthData.h>

typedef struct {
	double yaw_angleXY;
	double pitch_angleYZ;
	double roll_angleZX;
} YPRAnglesStruct;

extern BOOL hasTrueDepthData;

@interface CPPUtilsAPIWrapper : NSObject
@property (readwrite) double capture_width;
@property (readwrite) double capture_height;
@property (readwrite) double capture_fov;

// Wrapper method for readMediapipeLandmark
- (float)getPixelPupilDistanceWithMediaPipeLMDataDict:(nonnull NSDictionary *)dataDict;
- (float)getPixelIrisDistanceWithMediaPipeLMDataDict:(nonnull NSDictionary *)dataDict;

- (nonnull NSDictionary<NSString *, id> *) getROIPyrWithrefLM:(nonnull NSArray<NSDictionary<NSString *, id> *> *)refLMs
													  curData:(nonnull NSDictionary<NSString *, id> *)curData
												   depthDatas:(nonnull NSArray<AVDepthData *> *)depthDatas;

- (nonnull NSDictionary<NSString *, id> *) getROIPyrWithrefLMFilePaths:(nonnull NSArray<NSString *> *)refLMFilePaths
											   curDataFilePath:(nonnull NSString *)curDataFilePath
											depthDataFilePaths:(nonnull NSArray<NSString *> *)depthDataFilePaths;

- (nonnull NSDictionary<NSString *, NSNumber *> *)getFacePRY:(nonnull NSDictionary<NSString *, id> *)curData;

- (float)getPupilDepth:(nonnull NSDictionary *)imageData
		  andDepthData:(nullable AVDepthData *)depthData;
//- (float)getFaceDepthWithTD:(nonnull NSDictionary *)landmarks
//			   andDepthData:(nullable AVDepthData *)depthData;

- (void)startPDCalibration;
- (BOOL)hasPDCalibrationStarted;
- (BOOL)isPDCalibDone;
- (void)setPDCalibDone:(BOOL)status;

- (void) setHorizFovDegrees: (double) fov ;
- (void) setVertFovDegrees: (double) fov ;
- (void) setFrameCaptureWidth: (double) value ;
- (void) setFrameCaptureHeight: (double) value ;

+ (double)getPupilDistance;
@end
