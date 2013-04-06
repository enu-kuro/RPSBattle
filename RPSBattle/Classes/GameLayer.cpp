//
//  GameLayer.cpp
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#include "GameLayer.h"
#include "ResultLayer.h"

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameLayer::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCLabelTTF* rockLabel = CCLabelTTF::create("Rock", "Thonburi", 56);
    CCMenuItemLabel *rock =CCMenuItemLabel::create(rockLabel, this,menu_selector(GameLayer::pushButton));
    rock->setPosition( ccp(WIN_SIZE.width / 2, 50) );
    rock->setTag(E_Rock);
    
    
    CCLabelTTF* paperLabel = CCLabelTTF::create("Paper", "Thonburi", 56);
    CCMenuItemLabel *paper =CCMenuItemLabel::create(paperLabel,this,menu_selector(GameLayer::pushButton));
    paper->setPosition( ccp(WIN_SIZE.width / 4,  50) );
    paper->setTag(E_Paper);
    
    
    CCLabelTTF* scissorsLabel = CCLabelTTF::create("Scissors", "Thonburi", 56);
    CCMenuItemLabel *scissors =CCMenuItemLabel::create(scissorsLabel,this,menu_selector(GameLayer::pushButton));
    scissors->setPosition( ccp(WIN_SIZE.width / 4*3, 50) );
    scissors->setTag(E_Scissors);
    
    
    CCMenu* pMenu = CCMenu::create(rock,paper,scissors, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 100);
    
    
    resultLabel = CCLabelTTF::create("", "Thonburi", 160);
    resultLabel->setPosition( ccp(WIN_SIZE.width/2, WIN_SIZE.height/2) );
    resultLabel->setColor( ccc3(255, 0, 0) );
    resultLabel->setScale(0);
    this->addChild(resultLabel,20);
    
    
    this->schedule( schedule_selector(GameLayer::rpsFalling), duration );
    
    
    return true;
}

void GameLayer::pushButton(CCNode* pSender)
{
    if(enemy==NULL or enemy->isVisible()==false){return;}
    
    ERps selectedValue = ERps(pSender->getTag());
    
    EResult result = enemy->judge(selectedValue);
    
    const char *resultChar;
    if (result==E_Win){
        CCLOG("Win");
        score++;
        enemy->setVisible(false);
        resultChar = "WIN!";
    }else
    if (result==E_Even){
        CCLOG("Even");
        enemy->setVisible(false);
        resultChar = "EVEN!";
    }else
    if (result==E_Lose){
        CCLOG("Lose");
        this->lose();
    }
    
    resultLabel->setString(resultChar);
    CCScaleTo *scaleTo = CCScaleTo::create(0.2f, 1.0f);
    CCDelayTime *delay = CCDelayTime::create(0.2f);
    CCScaleTo *disappear = CCScaleTo::create(0.2f, 0);
    CCSequence *seq = CCSequence::create(scaleTo,delay,disappear,NULL);
    resultLabel->runAction(seq);

}



void GameLayer::rpsFalling(float elapsed)
{
    enemy = RPSObject::create();
    enemy->setPosition(ccp(WIN_SIZE.width/2, WIN_SIZE.height+50));
    this->addChild(enemy,10);
    
	CCFiniteTimeAction* actionMove = CCMoveTo::create( duration, ccp(WIN_SIZE.width/2,-50 ));
	CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create(this, callfuncN_selector(GameLayer::moveFinished));
    enemy->runAction( CCSequence::create(actionMove, actionMoveDone, NULL) );
    
}



void GameLayer::moveFinished(CCNode *sender)
{
    if(sender->isVisible()==true){ this->lose(); }
    sender->removeFromParentAndCleanup(true);
}

void GameLayer::lose()
{
    CCScene *resultScene = ResultLayer::scene();
    ResultLayer *resultLayer = (ResultLayer*)resultScene->getChildByTag(TAG_RESULT_LAYER);
    resultLayer->setScore(this->score);
    CCDirector::sharedDirector()->pushScene(resultScene);
}







