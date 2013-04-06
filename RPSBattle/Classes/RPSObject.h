//
//  RPSObject.h
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#ifndef __RPSBattle__RPSObject__
#define __RPSBattle__RPSObject__

#include "cocos2d.h"

using namespace cocos2d;

enum EResult { E_Win, E_Even, E_Lose};
enum ERps{ E_Rock = 101, E_Scissors = 102, E_Paper = 103 };

class RPSObject : public CCNode
{
public:
    virtual bool init();
    CREATE_FUNC(RPSObject);
    EResult judge(ERps selectedValue);
    
private:
    ERps type;
    
};

#endif /* defined(__RPSBattle__RPSObject__) */