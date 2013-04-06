//
//  ResultLayer.cpp
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#include "ResultLayer.h"
#include "GameLayer.h"

CCScene* ResultLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ResultLayer *layer = ResultLayer::create();
    
    layer->setTag(TAG_RESULT_LAYER);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool ResultLayer::init()
{
    if( !CCLayer::init() )
        return false;
    
    this->bestScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("BestScore");
    
    bestScoreLabel = CCLabelTTF::create(CCString::createWithFormat("BEST SCORE: %d",bestScore,this->score)->getCString(), "Thonburi", 46);
    bestScoreLabel->setColor( ccc3(255, 0, 0) );
    bestScoreLabel->setPosition( ccp(WIN_SIZE.width / 2, WIN_SIZE.height / 2 + 150) );
    this->addChild(bestScoreLabel);
    
    scoreLabel = CCLabelTTF::create("", "Thonburi", 96);
    scoreLabel->setColor( ccc3(255, 0, 0) );
    scoreLabel->setPosition( ccp(WIN_SIZE.width / 2, WIN_SIZE.height / 2 + 50) );
    this->addChild(scoreLabel);
    
    // add instruction below the game over text
    CCLabelTTF *infoLabel = CCLabelTTF::create("touch to continue", "Thonburi", 56);
    infoLabel->setColor( ccc3(255, 255, 255) );
    infoLabel->setPosition( ccp(WIN_SIZE.width / 2, WIN_SIZE.height / 2 - 40) );
    this->addChild(infoLabel);
    
    this->setTouchEnabled(true);
    
    return true;
}

void ResultLayer::setScore(int totalScore){
    
    this->score = totalScore;
    scoreLabel->setString(CCString::createWithFormat("SCORE: %d",this->score)->getCString());
    
    if (bestScore<=score) {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("BestScore", score);
        bestScoreLabel->setString(CCString::createWithFormat("BEST SCORE: %d",score,this->score)->getCString());
    }
}

void ResultLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCScene *gameScene = GameLayer::scene();
    CCDirector::sharedDirector()->replaceScene(gameScene);
}