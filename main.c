#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

int main()
{
    int i = 0;                          //���� ���� ī�� ��
    int mi;                             //���θ޴� �Է� ����
	int money = 10000;					//�⺻ ���� ��
	int pay;						    //���� ���
	int temp = 0;                       //�� ����
	char back[10];                      //���� ������ char
    char num1[50], num2[50];            //ī�� ���ڿ� ����(A, J, Q, K)
    char plus[6];                       //Hit, Double, Stand �Է¹޴� ���ڿ�
    char suit1[10], suit2[10];          //ī���� ���
    int card3[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};            //���� ī�� �ִ� 9��
    char suit3[9][10];                                      //���� ī���� ���
    char num3[9][50];                                       //���� ī���� ���ڿ� ����
    char x[9];
    char y[9];
    char yn[1];

    SetConsoleTitle("Black-Jack");              //�ܼ�â �̸� ����
    while(1)                                    //����ȭ�� �ڵ�
    {
start:
    i=0;
    temp=0;
    int card3[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};            //���� ī�� �ִ� 9��
    suit3[9][10];                                      //���� ī���� ���
    num3[9][50];                                       //���� ī���� ���ڿ� ����
    x[9];
    y[9];
    yn[1];
        printf("����\n");
        printf("1. ���� ����\n");
        printf("2. ���� ��Ģ\n");
        printf("3. ���� ����\n");
        printf("���� : ");
        scanf("%d", &mi);
        switch(mi){
        case(1) :
            system("cls");
            break;                              //���� ����

        case(2) :
case2:                                                              //goto ����� �̵�
            system("cls");
            printf("1. ó���� ������ �� ����....\n");                //���� ��Ģ���� �������
            printf("���ư��Ƿ��� back�� �Է����ּ��� : ");
            scanf("%s", back);
            if((strcmp(back,"back")==0)){                           //���� back�� ���� ����ȭ������ ���ư�
                system("cls");
                continue;
            }
            else {
                printf("�� �� ���� ��ɾ� �Դϴ�");                      //back ���� �ٸ� ��ɾ ���ٸ�
                Sleep(1000);
                system("cls");
                goto case2;                                          //�ٽ� ���

            }
        case(3) :
            system("cls");                                      //���α׷� ����
            return 1;
        default :
            printf("�� �� ���� ��ɾ� �Դϴ�.");               //�ٽ� ���
            system("cls");
            return 1;
        }
        break;
    }
	while(1)					//���� �ݺ�
	{
		printf("���� �Ӵ� : %d\n", money);
		printf("�������(�ּ� 1000) : ");
		scanf("%d", &pay);

		if (money < pay)		 //���� ������ �ִ� �ӴϺ��� ���� ����� �� ũ�ٸ�
		{
			printf("������ �ִ� ���� �����ϴ�");
            Sleep(1000);
			system("cls");				//�ܼ�â�� ������
			continue;				//�ݺ��� �ٽ� ������
		}
		else if (pay < 1000)
		{
			printf("�ּұݾ׺��� �������� �����ϴ�");
			Sleep(1000);;
			system("cls");
			continue;
		}
		else{
            money -= pay;                //�Ӵ� ���
            break;				//�ݺ��� ������
		}

	}

	printf("�����Ͽ����ϴ�");
	Sleep(1000);
	system("cls");

	int random1 = 0;
	int card1 = 0;

	srand(time(NULL));              //���� ���� �ʱ�ȭ
	random1 = rand()%4+1;
	card1 = rand()%13+1;           //�������� 1~13���� ����.

	printf("ù ��° ī�� : ");

	switch(random1){                //ù ��° ī�� ���, ���� ���ϱ�
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

	int random2 = 0;                //���� �ʱ�ȭ
	int card2 = 0;

	random2 = rand()%4+1;           //�������� 1~4���� ����.
	card2 = rand()%13+1;           //�������� 1~13���� ����.

	printf("�� ��° ī�� : ");       //�� ��° ī�� ���, ���� ���ϱ�

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
        if(suit1 == suit2 && num1 == num2)          //���� ī�尡 �Ȱ��ٸ� �ٽ� ������
        {
            int random2 = 0;
            int card2 = 0;
            random2 = rand()%4+1;           //�������� 1~4���� ����.
            card2 = rand()%13+1;
            continue;
        }
        else break;
    }


    switch(card1){                  //ī�� 1�� ���ĺ� ���
    case(1) :
        card1 = 11;
    case(11) :
        card1 = 10;
    case(12) :
        card1 = 10;
    case(13) :
        card1 = 10;
    }

    switch(card2){                  //ī�� 2�� ���ĺ� ���
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
        printf("���� �Ӵ� : %d\n", money);
        printf("�� ���� : %d\n\n", temp);
        printf("ù ��° ī�� : %s %s\n", suit1, num1);
        printf("�� ��° ī�� : %s %s\n", suit2, num2);
        switch(i) {
        case(1):
            printf("�� ��° ī�� : %s %s\n", suit3[1], num3[1]);
            break;
        case(2):
            printf("�� ��° ī�� : %s %s\n", suit3[1], num3[1]);
            printf("�� ��° ī�� : %s %s\n", suit3[2], num3[2]);
            break;
        case(3):
            printf("�� ��° ī�� : %s %s\n", suit3[1], num3[1]);
            printf("�� ��° ī�� : %s %s\n", suit3[2], num3[2]);
            printf("�ټ� ��° ī�� : %s %s\n", suit3[3], num3[3]);
            break;
        case(4):
            printf("�� ��° ī�� : %s %s\n", suit3[1], num3[1]);
            printf("�� ��° ī�� : %s %s\n", suit3[2], num3[2]);
            printf("�ټ� ��° ī�� : %s %s\n", suit3[3], num3[3]);
            printf("���� ��° ī�� : %s %s\n", suit3[4], num3[4]);
            break;
        }
        if(temp==21){
            printf("�����ϼ̽��ϴ�.");
            money = pay*2;
            printf("�����Ӵ� : %d\n", money);
            printf("�ٽ��Ͻðڽ��ϱ�?(y/n): ");
            scanf("%s", &yn);
            if(strcmp(yn,"y")==0){
                system("cls");
                goto start;

            }
            else if(strcmp(yn,"n")==0) return 1;
            else{
                printf("�˼����� ��ɾ��Դϴ�");
                return 1;
            }
        }
        if(temp>=22){
            system("cls");
            printf("�й��ϼ̽��ϴ�.\n����:%d\n", temp);
            printf("�ٽ��Ͻðڽ��ϱ�?(y/n): ");
            scanf("%s", &yn);
            if(strcmp(yn,"y")==0){
                system("cls");
                goto start;

            }
            else if(strcmp(yn,"n")==0) return 1;
            else{
                printf("�˼����� ��ɾ��Դϴ�");
                return 1;
            }
        }
        Sleep(1000);
        printf("1. ���� �� �����Ƿ��� hit\n2. ���߽Ƿ��� stand\n3.���� ���ڸ� �����Ƿ��� double�� �Է����ּ���\n");
        printf("�Է����ּ��� : ");
        scanf("%s", plus);
        if(strcmp(plus,"hit")==0){
            printf("hit!!\n");
            i++;
            random1 = rand()%4+1;
            card3[i] = rand()%13+1;
            switch(random1){                //ù ��° ī�� ���, ���� ���ϱ�
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
            switch(card3[i]){                  //ī�� 2�� ���ĺ� ���
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
        if(strcmp(plus,"stand")==0){
            printf("���߼̽��ϴ�.\n");
            Sleep(1000);
            break;
        }
        if(strcmp(plus,"double")==0){
            printf("double\n");
            Sleep(1000);
            break;
        }
        else{
            printf("�����߽��ϴ�.");
            Sleep(1000);
            system("cls");
            continue;
        }

    }
    system("cls");
    printf("���� �Ӵ� : %d\n", money);
    if(strcmp(plus,"stand")==0){
            printf("21������ %d���ҽ��ϴ�.\n", 21-temp);
        }

}

