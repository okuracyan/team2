#pragma once

#include <vector>

/// <summary>
/// �L�[���͂̃N���X
/// </summary>
/// <author>HORIKOSHI Masahiro</author>
namespace KeyUtility
{
    void Init();
    bool CheckTrigger(int keyCode);     //  �L�[���͂̃g���K�[�擾
    bool CheckRepeat(int keyCode);      //  �L�[���͂̃��s�[�g�擾
}

/// <summary>
/// csv�̃N���X
/// </summary>
/// <author>HORIKOSHI Masahiro</author>
namespace CSV
{
    std::vector<std::string> split(const std::string& text, char delim);    //  ��؂蕶�����w�肵�ĕ�����𕪊�����
}
