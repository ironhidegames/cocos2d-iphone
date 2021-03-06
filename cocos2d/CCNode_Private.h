//
//  CCNode_Private.h
//  cocos2d-ios
//
//  Created by Viktor on 10/28/13.
//
//

#import "CCNode.h"

@interface CCNode ()

/** The real openGL Z vertex.
 Differences between openGL Z vertex and cocos2d Z order:
 - OpenGL Z modifies the Z vertex, and not the Z order in the relation between parent-children
 - OpenGL Z might require to set 2D projection
 - cocos2d Z order works OK if all the nodes uses the same openGL Z vertex. eg: vertexZ = 0
 @warning: Use it at your own risk since it might break the cocos2d parent-children z order
 @since v0.8
 */
@property (nonatomic,readwrite) float vertexZ;

@property (nonatomic,readonly) BOOL isPhysicsNode;

/** Shader Program
 @since v2.0
 */
@property(nonatomic,readwrite,strong) CCGLProgram *shaderProgram;

/** used internally for zOrder sorting, don't change this manually */
@property(nonatomic,readwrite) NSUInteger orderOfArrival;

/** GL server side state
 @since v2.0
 */
@property (nonatomic, readwrite) ccGLServerState glServerState;

/** CCActionManager used by all the actions.
 IMPORTANT: If you set a new CCActionManager, then previously created actions are going to be removed.
 @since v2.0
 */
@property (nonatomic, readwrite, strong) CCActionManager *actionManager;

/** CCScheduler used to schedule all "updates" and timers.
 IMPORTANT: If you set a new CCScheduler, then previously created timers/update are going to be removed.
 @since v2.0
 */
@property (nonatomic, readwrite, strong) CCScheduler *scheduler;

/** Compares two nodes in respect to zOrder and orderOfArrival (used for sorting sprites in display list) */
- (NSComparisonResult) compareZOrderToNode:(CCNode*)node;

@end
