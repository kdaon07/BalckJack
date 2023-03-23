#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

int main()
{
    int i = 2;                          //새로 뽑은 카드 수
    int mi;                             //메인메뉴 입력 정수
	int money = 10000;					//기본 지급 돈
	int pay;						    //참가 비용
	int temp = 0;                       //총 점수
	char back[10];                      //설명 나가기 char
    char num1[50], num2[50];            //카드 숫자와 문자(A, J, Q, K)
    char plus[6];                       //Hit, Double, Stand 입력받는 문자열
    char suit1[10], suit2[10];          //카드의 모양
    int card3[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};            //뽑을 카드 최대 9장
    char suit3[9][10];                                      //뽑을 카드의 모양
    char num3[9][50];                                       //뽑을 카드의 숫자와 문자

    SetConsoleTitle("Black-Jack");              //콘솔창 이름 변경
    while(1)                                    //시작화면 코딩
    {
        printf("블랙잭\n");
        printf("1. 블랙잭 시작\n");
        printf("2. 블랙잭 규칙\n");
        printf("3. 블랙잭 종료\n");
        printf("블랙잭 : ");
        scanf("%d", &mi);
        switch(mi){
        case(1) :
            system("cls");
            break;                              //게임 시작

        case(2) :
case2:                                                              //goto 여기로 이동
            system("cls");
            printf("1. 처음에 배팅을 할 돈을....\n");                //블랙잭 규칙설명 적어야함
            printf("돌아가실려면 back를 입력해주세요 : ");
            scanf("%s", back);
            if((strcmp(back,"back")==0)){                           //명렁어 back를 쓰면 메인화면으로 돌아감
                system("cls");
                continue;
            }
            else {
                printf("알 수 없는 명령어 입니다");                      //back 말고 다른 명령어를 쓴다면
                Sleep(1000);
                system("cls");
                goto case2;                                          //다시 물어봄

            }
        case(3) :
            system("cls");                                      //프로그램 종료
            return 1;
        default :
            printf("알 수 없는 명령어 입니다.");               //다시 물어봄
            system("cls");
            return 1;
        }
        break;
    }
	while(1)					//무한 반복
	{
		printf("보유 머니 : %d\n", money);
		printf("참가비용(최소 1000) : ");
		scanf("%d", &pay);

		if (money < pay)		 //만약 가지고 있는 머니보다 참가 비용이 더 크다면
		{
			printf("가지고 있는 돈이 적습니다");
            Sleep(1000);
			system("cls");				//콘솔창을 정리함
			continue;				//반복을 다시 시작함
		}
		else if (pay < 1000)
		{
			printf("최소금액보다 참기비용이 적습니다");
			Sleep(1000);;
			system("cls");
			continue;
		}
		else{
            money -= pay;                //머니 계산
            break;				//반복을 중지함
		}

	}

	printf("성공하였습니다");
	Sleep(1000);
	system("cls");

	int random1 = 0;
	int card1 = 0;

	srand(time(NULL));              //랜덤 변수 초기화
	random1 = rand()%4+1;
	card1 = rand()%13+1;           //랜덤으로 1~13까지 뽑음.

	printf("첫 번째 카드 : ");

	switch(random1){                //첫 번째 카드 모양, 숫자 정하기
        case (1) :
            sprintf(suit1, "Spade");
            if(card1==1) sprintf(num1, "A");
            else if(card1==11) sprintf(num1, "J");
            else if(card1==12) sprintf(num1, "Q");
            else if(card1==13) sprintf(num1, "K");
            else sprintf(num1, "%d", card1);
            break;

        case (2) :
            sprintf(suit1, "Heart");
            if(card1==1) sprintf(num1, "A");
            else if(card1==11) sprintf(num1, "J");
            else if(card1==12) sprintf(num1, "Q");
            else if(card1==13) sprintf(num1, "K");
            else sprintf(num1, "%d", card1);
            break;

        case (3) :
            sprintf(suit1, "Diamond");
            if(card1==1) sprintf(num1, "A");
            else if(card1==11) sprintf(num1, "J");
            else if(card1==12) sprintf(num1, "Q");
            else if(card1==13) sprintf(num1, "K");
            else sprintf(num1, "%d", card1);
            break;

        case (4) :
            sprintf(suit1, "Club");
            if(card1==1) sprintf(num1, "A");
            else if(card1==11) sprintf(num1, "J");
            else if(card1==12) sprintf(num1, "Q");
            else if(card1==13) sprintf(num1, "K");
            else sprintf(num1, "%d", card1);
            break;
	}

	int random2 = 0;                //변수 초기화
	int card2 = 0;

	random2 = rand()%4+1;           //랜덤으로 1~4까지 뽑음.
	card2 = rand()%13+1;           //랜덤으로 1~13까지 뽑음.

	printf("두 번째 카드 : ");       //두 번째 카드 모양, 숫자 정하기

	while(1)
    {
        switch(random2){
        case (1) :
            sprintf(suit2, "Spade");
            if(card2==1) sprintf(num2, "A");
            else if(card2==11) sprintf(num2, "J");
            else if(card2==12) sprintf(num2, "Q");
            else if(card2==13) sprintf(num2, "K");
            else sprintf(num2, "%d", card2);
            break;

        case (2) :
            sprintf(suit2, "Heart");
            if(card2==1) sprintf(num2, "A");
            else if(card2==11) sprintf(num2, "J");
            else if(card2==12) sprintf(num2, "Q");
            else if(card2==13) sprintf(num2, "K");
            else sprintf(num2, "%d", card2);
            break;

        case (3) :
            sprintf(suit2, "Diamond");
            if(card2==1) sprintf(num2, "A");
            else if(card2==11) sprintf(num2, "J");
            else if(card2==12) sprintf(num2, "Q");
            else if(card2==13) sprintf(num2, "K");
            else sprintf(num2, "%d", card2);
            break;

        case (4) :
            sprintf(suit2, "Club");
            if(card2==1) sprintf(num2, "A");
            else if(card2==11) sprintf(num2, "J");
            else if(card2==12) sprintf(num2, "Q");
            else if(card2==13) sprintf(num2, "K");
            else sprintf(num2, "%d", card2);
            break;
        }
        if(suit1 == suit2 && num1 == num2)          //만약 카드가 똑같다면 다시 돌리기
        {
            int random2 = 0;
            int card2 = 0;
            random2 = rand()%4+1;           //랜덤으로 1~4까지 뽑음.
            card2 = rand()%13+1;
            continue;
        }
        else break;
    }


    switch(card1){                  //카드 1의 알파벳 계산
    case(1) :
        card1 = 11;
    case(11) :
        card1 = 10;
    case(12) :
        card1 = 10;
    case(13) :
        card1 = 10;
    }

    switch(card2){                  //카드 2의 알파벳 계산
    case(1) :
        if(card1<=11) card2 = 1;
        else card2 = 11;
    case(11) :
        card2 = 10;
    case(12) :
        card2 = 10;
    case(13) :
        card2 = 10;
    }

    system("cls");
    temp = card1+card2;
    while(1)
    {
        printf("보유 머니 : %d\n", money);
        printf("총 점수 : %d\n\n", temp);
        printf("첫 번째 카드 : %s %s\n", suit1, num1);
        printf("두 번째 카드 : %s %s\n\n", suit2, num2);
        switch(i) {
        case(3):
            printf("세 번째 카드 : %s %s\n\n", suit2, num2);
        }
        Sleep(1000);
        printf("1. 한장 더 뽑으실려면 hit\n2. 멈추실려면 stand\n3.같은 숫자를 나누실려면 double를 입력해주세요\n");
        printf("입력해주세요 : ");
        scanf("%s", plus);
        if(strcmp(plus,"hit")==0){
            printf("hit!!\n");
            i++;
            Sleep(1000);
            break;
        }
        if(strcmp(plus,"stand")==0){
            printf("멈추셨습니다.\n");
            Sleep(1000);
            break;
        }
        if(strcmp(plus,"double")==0){
            printf("double\n");
            Sleep(1000);
            break;
        }
        else{
            printf("실패했습니다.");
            Sleep(1000);
            system("cls");
            continue;
        }

    }
    system("cls");
    printf("보유 머니 : %d\n", money);
    if(strcmp(plus,"stand")==0){
            printf("21점까지 %d남았습니다.\n", 21-temp);
        }

}
