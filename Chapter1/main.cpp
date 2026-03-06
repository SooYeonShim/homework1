#include <iostream>
#include <string>

using namespace std;

int status[5] = { 0 }; // 캐릭터 스탯 배열
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main()
{

    int ch = 1; // 유저 선택
    int level = 1;
    

    int HPPotion = 5;
    int MPPotion = 5;
    int* p_HPPotion = &HPPotion;
    int* p_MPPotion = &MPPotion;


    cout << "HP와 MP를 입력해주세요." << endl;

    cin >> status[0];
    cin >> status[1];

    while (status[0] <= 50 || status[1] <= 50)
    {
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
        cin >> status[0];
        cin >> status[1];
    }

    cout << "공격력, 방어력과 민첩성을 입력해주세요." << endl;
    cin >> status[2];
    cin >> status[3];
    cin >> status[4];

    while (status[2] <= 0 || status[3] <= 0 || status[4] <= 0)
    {
        cout << "공격력, 방어력과 민첩성의 값이 너무 작습니다. 다시 입력해주세요." << endl;
        cin >> status[2];
        cin >> status[3];
        cin >> status[4];
    }


    while(ch != 0)
    {
        
        cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5. 민첩성 UP / 6. 현재 능력치 / 7.Level Up / 0.나가기" << endl;

        cin >> ch;

        switch (ch) 
        {
            case 1: 
                setPotion(ch, p_HPPotion, p_MPPotion);                
                break;
            case 2:
                setPotion(ch, p_HPPotion, p_MPPotion);      
                break;
            case 3:
                status[2] *= 2;
                break;
            case 4:
                status[3] *= 2;
                break;
            case 5:
                status[4] *= 2;
                break;
            case 6:
                cout << "현재 레벨 / HP / MP / 공격력 / 방어력 / 민첩성: " << ends;
                cout << level << " / ";
                for (int i = 0; i < sizeof(status)/sizeof(int); i++) 
                {
                    cout << status[i] << ends;
                    if (i != sizeof(status) / sizeof(int) - 1)
                     cout << " / " << ends; 
                }
                cout << endl;
                cout << "남은 포션 개수 - HP 포션: " << HPPotion << "개, MP 포션: " << MPPotion << "개" << endl;
                break;
            case 7:
                setPotion(ch, p_HPPotion, p_MPPotion);
                status[2] += 2;
                status[3] += 2;
                status[4] += 2;
                cout << "현재 레벨 : " << ++level << endl;
                break;
            case 0:
                break;
            default:
                cout << "다시 입력해주세요." << ends;
        }

    }
    return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    switch(count)
    {
    case 1 : 
        if (*p_HPPotion >= 1)
        {
            *p_HPPotion -= 1;
            status[0] += 20;
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;

        }
        else
        {
            cout << "포션이 부족합니다." << endl;
        }
        cout << "현재 HP : " << status[0] << endl;
        cout << "남은 포션 수 : " << *p_HPPotion << endl;
        break;
    case 2:
        if (*p_MPPotion >= 1)
        {
            *p_MPPotion -= 1;          
            status[1] += 20;
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;

        }
        else
        {
            cout << "포션이 부족합니다." << endl;
        }
        cout << "현재 MP : " << status[1] << endl;
        cout << "남은 포션 수 : " << *p_MPPotion << endl;
        break;
    case 6:
        *p_HPPotion += 1;
        *p_MPPotion += 1;
        cout << "남은 HP 포션 수 : " << *p_HPPotion << endl;
        cout << "남은 MP 포션 수 : " << *p_MPPotion << endl;
        break;
    }

}
