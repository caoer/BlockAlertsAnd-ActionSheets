//
//  BlockAlertView.h
//
//

#import <UIKit/UIKit.h>

enum {
    kAlertViewAnimationSlideFromTop = 1, // Default, slide from top
    kAlertViewAnimationFadeIn,	// Fade in
	kAlertViewAnimationPopIn,	//UIAlertview-like pop in
};
typedef NSUInteger kAlertViewAnimationType;

@interface BlockAlertView : NSObject {
@protected
    UIView *_view;
    NSMutableArray *_blocks;
    CGFloat _height;
    NSUInteger animationType;
	
    id _selfRetain;
}

+ (BlockAlertView *)alertWithTitle:(NSString *)title message:(NSString *)message;

- (id)initWithTitle:(NSString *)title message:(NSString *)message;

- (void)setDestructiveButtonWithTitle:(NSString *)title block:(void (^)())block;
- (void)setCancelButtonWithTitle:(NSString *)title block:(void (^)())block;
- (void)addButtonWithTitle:(NSString *)title block:(void (^)())block;

- (void)show;
- (void)showWithAnimation:(kAlertViewAnimationType)_animationType;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

@property (nonatomic, assign) UIImage *backgroundImage;
@property (nonatomic, readonly) UIView *view;
@property (nonatomic, readwrite) BOOL vignetteBackground;

#pragma mark - Convenient Methods
+ (void)showAlertWithMessage:(NSString *)message
                 cancelTitle:(NSString *)cancelTitle;

+ (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message
               cancelTitle:(NSString *)cancelTitle;

+ (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message
               cancelTitle:(NSString *)cancelTitle
               cancelBlock:(void (^)(void))cancelBlock;

+ (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message
               cancelTitle:(NSString *)cancelTitle
               cancelBlock:(void (^)(void))cancelBlock
              confirmTitle:(NSString *)confirmTitle
              confirmBlock:(void (^)(void))confirmBlock
             animationType:(kAlertViewAnimationType)animationType;
@end
