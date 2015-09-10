//
//  CCSprite_touch.cpp
//  BaseWar
//
//  Created by game-netease on 15/9/10.
//
//

#include "CCSprite_touch.h"

//需要重写create方法，不能使用父类的，不然添加触摸事件会崩溃
CCSprite_touch* CCSprite_touch::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame) {

    CCSprite_touch *pobSprite = new CCSprite_touch();
    if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void CCSprite_touch::onEnter()
{
    //添加一个触摸委托给dispatcher的列表,委托对象this,
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true); //true表示阻断其他层接受触摸事件
    CCSprite::onEnter();
}

void CCSprite_touch::onExit() {
    //移除委托
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

bool CCSprite_touch::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    cocos2d::CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());
    cocos2d::CCRect sRC = cocos2d::CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,
                        getPositionY() - getContentSize().height * getAnchorPoint().y,
                        getContentSize().width, getContentSize().height);
    
    
    sRC.origin = cocos2d::CCPointZero;
    bool isTouched = sRC.containsPoint(sLocalPos);
    if(isTouched)
    {
        cocos2d::CCLog("点中了!! x:%d y:%d", (int)sLocalPos.x, (int)sLocalPos.y);
        return true;
    }
    else
    {
        return false;
    }
}

void CCSprite_touch::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    CCLOG("移动");
}

void CCSprite_touch::ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* event)
{
    CCLOG("点击结束");
}