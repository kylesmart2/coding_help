#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 20
#define NS 50


int main(void)
{
	struct student
	{
		char f_name[N+1];
		char l_name[N+1];
		int id_num;
		float test1;
		float test2;
		float test3;
	};
	struct student names[NS];
	int i, count = 0, j;
	char temp_first[N+1], temp_last[N+1], grades[N], grade;

	printf("Please enter student's name (First Last) (ZZ to quit): ");
	scanf("%s", &temp_first[0]);
	
	
	while (strncmp(temp_first, "ZZ\0", 3))
	{
		scanf("%s", &temp_last[0]);
		strncpy(names[count].f_name, temp_first, N + 1);
		strncpy(names[count].l_name, temp_last, N + 1);

		printf("Please enter student's ID number: ");
		scanf("%d", &names[count].id_num);


		printf("Please enter student's three test scores: ");
		scanf("%f %f %f", &names[count].test1, &names[count].test2, &names[count].test3);
		grade = (names[count].test1 + names[count].test2 + names[count].test3) / 3;
		switch (grade/10)
		{
			case 9: grades[count] = 'A';
				break;
			case 8: grades[count] = 'B';
				break;
			case 7: grades[count] = 'C';
				break;
			case 6: grades[count] = 'D';
				break;
			default: grades[count] = 'F';

		}
		count++;

		printf("Please enter student's name (First Last) (ZZ to quit): ");
		scanf("%s", &temp_first[0]);
				

	}

	printf("\nSTUDENT\t\t\t\t   FINAL GRADE\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%s, %s\t\t\t\t%c", names[i].l_name, names[i].f_name, grades[i]);
	}
	printf("\n");
	
	
	return 0;
}


