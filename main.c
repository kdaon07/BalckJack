#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

int main()
{
    int i = 0;                          //새로 뽑은 카드 수
    int mi;                             //메인메뉴 입력 정수
	int money = 10000;					//기본 지급 돈
	int pay;						    //참가 비용
	int temp = 0;                       //총 점수
	char back[10];                      //설명 나가기 char
    char num1[50], num2[50];            //카드 숫자와 문자(A, J, Q, K)
    char plus[6];                       //Hit, Split, Stand 입력받는 문자열
    char suit1[10], suit2[10];          //카드의 모양
    int card3[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};            //뽑을 카드 최대 9장
    char suit3[9][10];                                      //뽑을 카드의 모양
    char num3[9][50];                                       //뽑을 카드의 숫자와 문자
    char x[9];
    char y[9];
    char yn[1];

    SetConsoleTitle("Black-Jack");              //콘솔창 이름 변경
    while(1)                                    //시작화면 코딩
    {
start:
    i=0;
    temp=0;
    int card3[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};            //뽑을 카드 최대 9장
    suit3[9][10];                                      //뽑을 카드의 모양
    num3[9][50];                                       //뽑을 카드의 숫자와 문자
    x[9];
    y[9];
    yn[1];
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
            printf("블랙잭 규칙\n");
            printf("1. 처음에 배팅을 할 돈을 정합니다\n");                //블랙잭 규칙설명 적어야함
            printf("2. 랜덤한 카드 2장을 받습니다\n");
            printf("3. 21에 가까워질때까지 hit명령어로 카드를 뽑습니다\n");
            printf("4. 21점을 얻으면 성공 21점을 넘으면 탈락입니다\n");
            printf("5. 성공하였다면 배팅을 했던 금액에 2배를 받습니다\n");
            printf("\n");
            printf("점수표\n");
            printf("A = 1점 or 11점\n");
            printf("2~10 = 그 숫자와 동일한 점수\n");
            printf("J, Q, K = 10점\n\n");
            printf("\n");
            printf("게임 명령어\n");
            printf("hit = 랜덤한 카드 한장을 뽑습니다.\n");
            printf("stand = 카드를 그만 뽑습니다.\n");
            printf("\n만약 stand를 하면 배팅의 절반을 돌려받고\n 게임에서 패배한다면 0.1배를 돌려받습니다.\n\n");
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
    if(money<1000){
            printf("돈이 적어 지원금으로 5000머니를 드립니다");         //돈이 없으면 5000머니를 주는 코드
            money += 5000;
            Sleep(2000);
            system("cls");
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
            break;

        case (2) :
            sprintf(suit1, "Heart");
            break;

        case (3) :
            sprintf(suit1, "Diamond");
            break;

        case (4) :
            sprintf(suit1, "Club");
            break;
	}

	if(card1==1) sprintf(num1, "A");
        else if(card1==11) sprintf(num1, "J");
        else if(card1==12) sprintf(num1, "Q");
        else if(card1==13) sprintf(num1, "K");
        else sprintf(num1, "%d", card1);

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
            break;

        case (2) :
            sprintf(suit2, "Heart");
            break;

        case (3) :
            sprintf(suit2, "Diamond");
            if(card2==1) sprintf(num2, "A");
            break;

        case (4) :
            sprintf(suit2, "Club");
            break;
        }

        if(card2==1) sprintf(num2, "A");
            else if(card2==11) sprintf(num2, "J");
            else if(card2==12) sprintf(num2, "Q");
            else if(card2==13) sprintf(num2, "K");
            else sprintf(num2, "%d", card2);


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

    if(card1 == card2)
    {
        printf("Split이 가능합니다 하시겠습니까?(y/n) : ");         //같은 숫자의 카드가 나왔을 때 딱 한번 가능한 Split(미완성)
        scanf("%s", &yn);
        if(strcmp(yn,"y")==0){
                system("cls");
                goto cs;
            }
            else if(strcmp(yn,"n")==0) goto cardtest;
    }
cardtest:
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
    temp = card1+card2;                                         //첫번째 카드와 두번째 카드의 합을 temp에 저장함
    while(1)
    {
nomal1:
        printf("보유 머니 : %d\n", money);
        printf("총 점수 : %d\n\n", temp);
        printf("첫 번째 카드 : %s %s\n", suit1, num1);
        printf("두 번째 카드 : %s %s\n", suit2, num2);
        switch(i) {                                                     //2번째 카드 이후 카드들
        case(1):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            break;
        case(2):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            break;
        case(3):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            printf("다섯 번째 카드 : %s %s\n", suit3[3], num3[3]);
            break;
        case(4):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            printf("다섯 번째 카드 : %s %s\n", suit3[3], num3[3]);
            printf("여섯 번째 카드 : %s %s\n", suit3[4], num3[4]);
            break;
        case(5):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            printf("다섯 번째 카드 : %s %s\n", suit3[3], num3[3]);
            printf("여섯 번째 카드 : %s %s\n", suit3[4], num3[4]);
            printf("일곱 번째 카드 : %s %s\n", suit3[5], num3[5]);
            break;
        case(6):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            printf("다섯 번째 카드 : %s %s\n", suit3[3], num3[3]);
            printf("여섯 번째 카드 : %s %s\n", suit3[4], num3[4]);
            printf("일곱 번째 카드 : %s %s\n", suit3[5], num3[5]);
            printf("여덟 번째 카드 : %s %s\n", suit3[6], num3[6]);
            break;
        case(7):
            printf("세 번째 카드 : %s %s\n", suit3[1], num3[1]);
            printf("네 번째 카드 : %s %s\n", suit3[2], num3[2]);
            printf("다섯 번째 카드 : %s %s\n", suit3[3], num3[3]);
            printf("여섯 번째 카드 : %s %s\n", suit3[4], num3[4]);
            printf("일곱 번째 카드 : %s %s\n", suit3[5], num3[5]);
            printf("여덟 번째 카드 : %s %s\n", suit3[6], num3[6]);
            printf("아홉 번째 카드 : %s %s\n", suit3[7], num3[7]);
            break;
        }
        if(temp==21){                                       //21을 정확하게 맞춘다면 배팅 2배
            printf("성공하셨습니다.");
            money += pay*2;
            printf("보유머니 : %d\n", money);
            printf("다시하시겠습니까?(y/n): ");
            scanf("%s", &yn);
            if(strcmp(yn,"y")==0){
                system("cls");
                goto start;

            }
            else if(strcmp(yn,"n")==0) return 1;
            else{
                printf("알수없는 명령어입니다");
                return 1;
            }
        }
        if(temp>=22){                                           //21을 넘긴다면 패배
            system("cls");
            printf("패배하셨습니다.\n점수:%d\n", temp);
            money += pay*0.1;
            printf("다시하시겠습니까?(y/n): ");
            scanf("%s", &yn);
            if(strcmp(yn,"y")==0){
                system("cls");
                goto start;

            }
            else if(strcmp(yn,"n")==0) return 1;
            else{
                printf("알수없는 명령어입니다");
                return 1;
            }
        }
        Sleep(1000);
        printf("1. 한장 더 뽑으실려면 hit\n2. 멈추실려면 stand\n");              //hit, stand를 물어보는 질문
        printf("입력해주세요 : ");
        scanf("%s", plus);
        if(strcmp(plus,"hit")==0){                                              //만약 hit를 입력했으면 새로운 카드를 뽑음
            printf("hit!!\n");
            i++;
            random1 = rand()%4+1;
            card3[i] = rand()%13+1;
            switch(random1){
            case (1) :
                sprintf(suit3[i], "Spade");
                if(card3[i]==1) sprintf(num3[i], "A");
                else if(card3[i]==11) sprintf(num3[i], "J");
                else if(card3[i]==12) sprintf(num3[i], "Q");
                else if(card3[i]==13) sprintf(num3[i], "K");
                else sprintf(num3[i], "%d", card3[i]);
                break;

            case (2) :
                sprintf(suit3[i], "Heart");
                if(card3[i]==1) sprintf(num3[i], "A");
                else if(card3[i]==11) sprintf(num3[i], "J");
                else if(card3[i]==12) sprintf(num3[i], "Q");
                else if(card3[i]==13) sprintf(num3[i], "K");
                else sprintf(num3[i], "%d", card3[i]);
                break;

            case (3) :
                sprintf(suit3[i], "Diamond");
                if(card3[i]==1) sprintf(num3[i], "A");
                else if(card3[i]==11) sprintf(num3[i], "J");
                else if(card3[i]==12) sprintf(num3[i], "Q");
                else if(card3[i]==13) sprintf(num3[i], "K");
                else sprintf(num3[i], "%d", card3[i]);
                break;

            case (4) :
                sprintf(suit3[i], "Club");
                if(card3[i]==1) sprintf(num3[i], "A");
                else if(card3[i]==11) sprintf(num3[i], "J");
                else if(card3[i]==12) sprintf(num3[i], "Q");
                else if(card3[i]==13) sprintf(num3[i], "K");
                else sprintf(num3[i], "%d", card3[i]);
                break;
            }
            switch(card3[i]){                  //카드 2의 알파벳 계산
            case(1) :
                if(card3[i]+temp>21) card3[i] = 1;
                else card3[i] = 11;
            case(11) :
                card3[i] = 10;
            case(12) :
                card3[i] = 10;
            case(13) :
                card3[i] = 10;
            }
            temp += card3[i];
            Sleep(1000);
            system("cls");
            continue;
        }
        if(strcmp(plus,"stand")==0){                                //만약 stand를 입력했으면 카드를 그만뽑음
            printf("멈추셨습니다.\n");
            money += pay*0.5;
            Sleep(1000);
            break;
        }
        else{
            printf("실패했습니다.");                                //이상한 답들을 다시 시작함
            Sleep(1000);
            system("cls");
            continue;
        }

    }
    system("cls");
    printf("보유 머니 : %d\n", money);
    if(strcmp(plus,"stand")==0){                                    //stand를 입력한다면 21점까지 남은 점수와 재도전 여부를 물어봄
        printf("21점까지 %d남았습니다.\n", 21-temp);
        printf("다시하시겠습니까?(y/n): ");
            scanf("%s", &yn);
            if(strcmp(yn,"y")==0){
                system("cls");
                goto start;

            }
    }
cs:
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


}
