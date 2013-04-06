//
//  ResultLayer.h
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#ifndef __RPSBattle__ResultLayer__
#define __RPSBattle__ResultLayer__

#include <iostream>
#include "cocos2d.h"

#define TAG_RESULT_LAYER 10

using namespace cocos2d;

class ResultLayer : public CCLayer
{
public:
    CREATE_FUNC(ResultLayer);
    static cocos2d::CCScene* scene();
    virtual bool init();
    void setScore(int totalScore);
private:
    void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    int score;
    CCLabelTTF *scoreLabel;
    CCLabelTTF *bestScoreLabel;
    int bestScore;
};

#endif /* defined(__RPSBattle__ResultLayer__) */
