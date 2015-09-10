//
//  CCSprite_touch.h
//  BaseWar
//
//  Created by game-netease on 15/9/10.
//
//

#ifndef __BaseWar__CCSprite_touch__
#define __BaseWar__CCSprite_touch__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class Unit;


class CCSprite_touch : public CCSprite , public CCTargetedTouchDelegate {

public:
    
    int _touchCount; //测试用，可以删除
    
    Unit *_unit; //对应的作战单元

    
    static CCSprite_touch* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
    //添加触屏委托，重新此方法
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
};


#endif /* defined(__BaseWar__CCSprite_touch__) */
