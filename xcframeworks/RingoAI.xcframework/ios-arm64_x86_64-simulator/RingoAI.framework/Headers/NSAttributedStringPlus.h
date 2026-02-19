//
//  NSAttributedStringPlus.h
//

#import <UIKit/UIKit.h>

@interface NSAttributedString(plus)

+ (instancetype _Nonnull)attributedString;
+ (instancetype _Nonnull)attributedStringWithString:(NSString* _Nonnull)value;
+ (instancetype _Nonnull)attributedStringWithImage:(UIImage* _Nonnull)image;

@end

@interface NSMutableAttributedString(plus)

+ (instancetype _Nonnull)attributedStringWithString:(NSString* _Nonnull)value
									  font:(UIFont* _Nonnull)fvalue
									 color:(UIColor* _Nonnull)cvalue;

- (void)setFont:(UIFont* _Nonnull)value;
- (void)setColor:(UIColor* _Nonnull)value;
- (void)setKerning:(CGFloat)value;
- (void)setBaselineOffset:(CGFloat)value;

- (void)setParagraphStyle:(NSParagraphStyle* _Nonnull)value;

- (void)overlayAttribute:(NSString *_Nonnull)name value:(id _Nonnull)value range:(NSRange)range;

@end

@interface NSString(AttributedPlus)

- (BOOL)contains:(NSString* _Nonnull)str;	// case insensitive

// quasi-RTF
//	[b]bold[/b]
//	[s]strike thru[/s]
//	[u]underline[/u]
//  [img]cancel.png[/img]
//	[link]Apple|http://www.apple.com[/link]
//	[justLeft/justRight/justCenter]...[/justLeft/justRight/justCenter]
//	[color:0xFF0088]orange[/color:0xFF0088]	-- web color
//	[blueColor]blue[/blueColor]				-- this will call [UIColor blueColor] - so custom color categories are just fine
//	[appFont:14]14 point thin[/appFont:14]	-- you need a UIFont category with the prototype + (UIFont*)appFont:(CGFloat)fontSize;

- (BOOL)hasAttributes;

- (NSMutableAttributedString* _Nonnull)attributed;

- (NSMutableAttributedString* _Nonnull)attributedStringWithTermHighlighted:(NSString* _Nonnull)term;

@end
