//
//  GameLayer.h
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#ifndef __RPSBattle__GameLayer__
#define __RPSBattle__GameLayer__

#include <iostream>
#include "cocos2d.h"
#include "RPSObject.h"

#define WIN_SIZE CCDirector::sharedDirector()->getWinSize()

using namespace cocos2d;


class GameLayer : public cocos2d::CCLayer
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    void pushButton(CCNode* pSender);
    void rpsFalling(float elapsed);
    void moveFinished(CCNode* sender);
    
    void win();
    void even();
    void lose();
    
    RPSObject *enemy;
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);

private:
    int score;
    const float duration = 2.0f;
    CCLabelTTF* resultLabel;
};

#endif /* defined(__RPSBattle__GameLayer__) */
