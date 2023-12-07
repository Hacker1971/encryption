#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[50];
    char gender;
    int age;
};

void encryption()
{
    char str[100];
    FILE *fpe = fopen("encryption.txt", "w");

    printf("Enter a string for encryption: ");
    fflush(stdin); // Clear input buffer
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] += 5;
        fputc(str[i], fpe);
    }

    fclose(fpe);
    printf("\n\t\t\t\tEncryption suscessful");
}

void decryption()
{
    FILE *fpd = fopen("encryption.txt", "r");
    char ch;
    printf("Decryption:");

    while ((ch = fgetc(fpd)) != EOF)
    {
        ch -= 5;
        printf("%c", ch);
    }

    fclose(fpd);
}

void saveStudentData()
{
    struct student s[3];
    FILE *fps = fopen("student.dat", "w");

    for (int i = 0; i < 3; i++)
    {
        printf("Enter details for student: %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter name: ");
        fflush(stdin); // Clear input buffer
        fgets(s[i].name, sizeof(s[i].name), stdin);

        printf("Enter gender (M/F): ");
        scanf(" %c", &s[i].gender);

        printf("Enter age: ");
        scanf("%d", &s[i].age);

        fwrite(&s[i], sizeof(struct student), 1, fps);
    }

    fclose(fps);
}

void displayStudentData()
{
    struct student s[3];
    FILE *fpd = fopen("student.dat", "r");

    for (int i = 0; i < 3; i++)
    {
        fread(&s[i], sizeof(struct student), 1, fpd);

        printf("\nDetails of student %d\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Gender: %c\n", s[i].gender);
        printf("Age: %d\n", s[i].age);
    }

    fclose(fpd);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n*****MENU*****\n");
        printf("1. Encrypt String\n");
        printf("2. Decrypt String\n");
        printf("3. Save Student Data\n");
        printf("4. Display Student Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            encryption();
            break;

        case 2:
            decryption();
            break;

        case 3:
            saveStudentData();
            break;

        case 4:
            displayStudentData();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
