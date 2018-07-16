#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string>





typedef struct vrijeme {

	int sat;
	int min;
	char *naziv;

}_vrijeme;

void alarm1(_vrijeme);
void menu();
_vrijeme unos();
void sound(_vrijeme);
void upaliti_za(tm*, _vrijeme);
tm * getlocal();



void alarm1(_vrijeme a) {

	
	tm *local;

	local = getlocal();

	printf("Upravo je  %d sati i  %d minuta \n", local->tm_hour, local->tm_min);

	upaliti_za(local, a);
	
	do {


		local = getlocal();


	} while (local->tm_hour - a.sat != 0 || local->tm_min - a.min != 0);


	sound(a);

	return;

}

tm * getlocal() {

	time_t now = time(0);
	tm *ltm = localtime(&now);
	

	return ltm;

}

void menu() {


	printf("***************MENU***************\n");
	printf("* U - Unos novog alarma          *\n");
	printf("* K - Kraj rada                  *\n");
	printf("**********************************\n");


}

_vrijeme unos() {

	_vrijeme a;

	a.naziv = (char*)malloc(20 * sizeof(char));

	printf("Unesite zeljeni sat alarma : ");
	scanf("%d", &a.sat);

	printf("\nUnesite zeljene minute alarma : ");
	scanf("%d", &a.min);

	printf("\nUnesite naziv alarma : ");
	scanf("%s", a.naziv);

	return a;

}

void sound(_vrijeme a) {
	

	printf("Alarm : %s \n", a.naziv);

	printf("\a \n");
		
		return;
}

void upaliti_za(tm* b, _vrijeme c) {


	if (b->tm_hour >= c.sat  && b->tm_min > c.min) {

		printf("Alarm ce se upaliti za  %d sati i %d minuta \n", 24 - (b->tm_hour - c.sat)-1, 60 - (b->tm_min - c.min));

	}

	else if (b->tm_hour <= c.sat  && b->tm_min < c.min) {

		printf("Alarm ce se upaliti za %d sati i %d minuta \n", c.sat - b->tm_hour, c.min - b->tm_min);

	}

	else if (b->tm_hour > c.sat  && b->tm_min <= c.min) {

			printf("Alarm ce se upaliti za  %d sati i %d minuta \n", 24 - (b->tm_hour - c.sat),c.min-b->tm_min);

		}

	else if (b->tm_hour < c.sat  && b->tm_min >= c.min) {

		printf("Alarm ce se upaliti za %d sati i %d minuta \n", c.sat - b->tm_hour-1, 60 - (b->tm_min- c.min));

	}

	return;

}


int main(void) {

	char *choice;
	choice = (char*)malloc(1 * sizeof(char));
	tm *local1;

	do {

		local1 = getlocal();
		menu();
		printf("Upravo je %d sati %d minuta \n", local1->tm_hour, local1->tm_min);
		printf("Unesite svoj odabir :");
		scanf("%s", choice);

		switch (toupper(*choice)) {

		case 'U':

			_vrijeme alarm;

			alarm=unos();
			alarm1(alarm);

			break;

		case 'K':

			printf("Dobro jutro \n");
			break;
		default:

			printf("Pogresan unos pokusajte ponovno \n");
			break;

		}
	} while (toupper(*choice) != 'K');


	return 0;




}



	








