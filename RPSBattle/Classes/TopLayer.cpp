//
//  TopLayer.cpp
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#include "TopLayer.h"
#include "GameLayer.h"
CCScene* TopLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TopLayer *layer = TopLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TopLayer::init()
{
  
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCMenuItemLabel *item =CCMenuItemLabel::create(CCLabelTTF::create("START!", "Thonburi", 100), this,menu_selector(TopLayer::startGame));
    
    item->setPosition( ccp(WIN_SIZE.width/2, WIN_SIZE.height/2) );
    
    CCMenu* pMenu = CCMenu::create(item, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    
    return true;
}

void TopLayer::startGame(CCObject* pSender)
{
    
    CCScene *gameScene = GameLayer::scene();
    CCDirector::sharedDirector()->replaceScene(gameScene);
    
    
}