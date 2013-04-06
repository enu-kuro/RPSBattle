//
//  TopLayer.h
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#ifndef __RPSBattle__TopLayer__
#define __RPSBattle__TopLayer__

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
//using namespace CocosDenshion;

class TopLayer : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void startGame(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(TopLayer);
};


#endif /* defined(__RPSBattle__TopLayer__) */
