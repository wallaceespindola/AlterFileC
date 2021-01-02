#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *name;
	float gpa;
} student;

/**
 * https://www.youtube.com/watch?v=2pBVlpLM1Sc
 */
int main() {

	FILE *originalFile = fopen("alterFile.txt", "r");
	FILE *newFile = fopen("alterFile_tmp.txt", "w");

	//test.txt:
	//1
	//2 aaaa 10.35
	//3 bbbbb 11.35
	//4 ccc 12.35
	//5 dddddd 13.35
	//6 eeee 14.35
	//7

	printf("\n Iniciando... \n");

	int studentCount;
	fscanf(originalFile, "%d", &studentCount);
//    int studentCount = 0;
//    char *stringSaida[1000];
//	while (!feof(originalFile)) {
//		fscanf(originalFile, "%s", stringSaida[studentCount]);
//		studentCount++;
//	}

	printf("\n studentCount: %d \n", studentCount);

	student *passingStudents = malloc(sizeof(student) * studentCount);

	int passingCount = 0;
	for (int i = 0; i < studentCount; i++) {

		int nameLen;
		fscanf(originalFile, "%d", &nameLen);

		printf("\n nameLen: %d \n", nameLen);

		char *name = malloc(sizeof(char) * (nameLen+1) );
		name[nameLen] = '\0';
		float gpa;

		fscanf(originalFile, "%s %f", name, &gpa);

		printf("\n leu: %s %f \n", name, gpa);

		if (gpa >= 12.00) {
			passingStudents[passingCount].name = name;
			passingStudents[passingCount].gpa = gpa;
			passingCount++;
		}
	}

	printf("\n passingCount: %d \n", passingCount);

	fprintf(newFile, "%i\n", passingCount);


	for (int i = 0; i < passingCount; i++) {
		fprintf(newFile, "%d %s %.2f\n", i, passingStudents[i].name, passingStudents[i].gpa);
	}

	fclose(originalFile);
	fclose(newFile);

	//remove("alterFile.txt");
	//rename("alterFile_tmp.txt", "alterFile.txt");

	printf("\n Removeu abaixo de 12.00 com sucesso. Restaram: %d \n", passingCount);

	getch();

	return 0;
}
