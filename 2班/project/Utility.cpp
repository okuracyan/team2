#include <sstream>
#include <DxLib.h>
#include "Utility.h"
#include "Time.h"
#include "Library/Time.h"

namespace
{
    static const float REPEAT_TIME = 0.1f;      //  �L�[���s�[�g�Ԋu(sec)

    static bool triggerKeyBufferArray[0xff];    //  �g���K�[�L�[�o�b�t�@
    static float repeatKeyBufferArray[0xff];    //  ���s�[�g�L�[�o�b�t�@
}


/**********************/
/***    KeyUtility  ***/
/**********************/

//  �L�[�֘A�����̏�����
void KeyUtility::Init()
{
    for (int i = 0; i < 0xff; i++)
    {
        triggerKeyBufferArray[i] = false;
        repeatKeyBufferArray[i] = 0.0f;
    }
}

//  �L�[���͂̃g���K�[�擾
bool KeyUtility::CheckTrigger(int keyCode)
{
    bool triggerFlag = false;

    //  �Y���L�[��������Ă���
    if (CheckHitKey(keyCode) != 0)
    {
        //  �O�t���[���ŉ�����Ă��Ȃ��������g���K�[
        if (!triggerKeyBufferArray[keyCode])
        {
            triggerFlag = true;
        }
        //�L�[�o�b�t�@�ɓo�^
        triggerKeyBufferArray[keyCode] = true;
    }
    else
    {
        //�L�[�o�b�t�@�ɓo�^
        triggerKeyBufferArray[keyCode] = false;
    }

    return triggerFlag;
}

//  �L�[���͂̃��s�[�g�擾
bool KeyUtility::CheckRepeat(int keyCode)
{
    bool repeatFlag = false;

    //  �Y���L�[��������Ă���
    if (CheckHitKey(keyCode) != 0)
    {
        //  ���s�[�g�Ԋu���ԉ�����Ă�����A���s�[�g���͂Ƃ���
        repeatKeyBufferArray[keyCode] += Time::DeltaTime();
        if (repeatKeyBufferArray[keyCode] >= REPEAT_TIME)
        {
            repeatFlag = true;
            repeatKeyBufferArray[keyCode] = 0.0f;
        }
    }
    else
    {
        //�L�[�o�b�t�@�ɓo�^
        repeatKeyBufferArray[keyCode] = 0.0f;
    }

    return repeatFlag;
}


/*******************/
/***    CSV�֘A  ***/
/*******************/

//  ��؂蕶�����w�肵�ĕ�����𕪊�����
std::vector<std::string> CSV::split(const std::string& text, char delim)
{
    std::vector<std::string> elements;
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        if (!item.empty())
        {
            elements.push_back(item);
        }
    }
    return elements;
}