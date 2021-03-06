//
//  HLSKenBurnsSlideshow.h
//  CoconutKit
//
//  Created by Samuel Défago on 17.10.11.
//  Copyright (c) 2011 Hortis. All rights reserved.
//

/**
 * A view implementing the Ken Burns effect: A slideshow with random zooming and panning effects, as well as cross dissolve
 * transitions between images.
 *
 * You can instantiate a Ken Burns slide show either using a nib or programmatically. It then suffices to set its
 * images property to the array of images which must be displayed. Other properties provide for further
 * customization.
 *
 * Designated initializer: initWithFrame:
 */
@interface HLSKenBurnsSlideshow : UIView {
@private
    NSArray *m_imageViews;                      // Two image views needed (front / back buffer) to create smooth cross-dissolve transitions
    NSArray *m_images;
    NSMutableArray *m_animations;               // Two animations in parallel (at most)
    BOOL m_running;
    NSInteger m_currentImageIndex;
    NSInteger m_currentImageViewIndex;
    NSTimeInterval m_imageDuration;
    NSTimeInterval m_transitionDuration;
    BOOL m_random;
}

/**
 * The array of images to be displayed. Images will be displayed in a endless loop, either sequentially or in a random
 * order (see random property)
 */
@property (nonatomic, retain) NSArray *images;

/**
 * How much time an image stays visible. Default is 10 seconds
 */
@property (nonatomic, assign) NSTimeInterval imageDuration;

/**
 * The duration of the cross dissolve transition between two images. Default is 3 seconds
 */
@property (nonatomic, assign) NSTimeInterval transitionDuration;

/**
 * If set to YES, images will be played in a random order. If set to NO, they are played sequentially
 * Default is NO
 */
@property (nonatomic, assign) BOOL random;

/**
 * Start / stop the slideshow
 */
- (void)play;
- (void)stop;

@end
