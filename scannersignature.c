#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <string.h>
#include <windows.h>

int GetSignature(FILE **, char [], unsigned char [], size_t *);
int FileFormat(FILE **, char [], unsigned char [], size_t *);
int FileScanning(FILE **, unsigned char [], size_t *, char []);

int main()
{
    FILE* AB;
    FILE* FFS;
    int prove;
    int result;
    char *result2;
    size_t shift;
    unsigned char sign[8];
    char way1[MAX_PATH], way2[MAX_PATH];

    result2 = setlocale(LC_ALL, "Rus");
    if (result2 == NULL)
    {
        printf("\n��������� ������ ��� ��������� �����.\n");
        return 1;
    }
    result = printf("����������, ������� ���� � ������������ ����: \n");
    if (result < 0)
    {
        printf("\n��������� ������ ��� ������ ���������.\n");
        return 2;
    }
    result = scanf("%[^\n]s", &way1);
    if (result < 1)
    {
        printf("\n��������� ������ ��� ���������� ���� � ������������ ����.\n");
        return 3;
    }
    prove = GetSignature(&AB, way1, sign, &shift);
    if (prove != 0)
    {
            if (prove == 1)
            {
                printf("\n��������� ������ ��� �������� ��������� (�� ������������ ����)\n");
                return 4;
            }
            else if (prove == 2)
            {
                printf("\n��������� ������ ��� �������� ���� � ������������ ����.\n");
                return 5;
            }
            else if (prove == 3)
            {
                printf("\n��������� ������ ��� �������� ������� ��� �������� ��������� �� ������������ ����.\n");
                return 6;
            }
            else if (prove == 4)
            {
                printf("\n��������� ������ ��� �������� ���������� ��� �������� ��������.\n");
                return 7;
            }
            else if (prove == 5)
            {
                printf("\n��������� ������ ��� �������� ������������ ����.\n");
                return 8;
            }
            else if (prove == 6)
            {
                printf("\n��������� ������ ��� ���������� ���������� �� ������������ ����.\n");
                return 9;
            }
    }

    result = fflush(stdin);
    if (result != 0)
    {
        printf("\n��������� ������ ��� �������� �������� ������.\n");
        return 10;
    }
    result = printf("����������, ������� ���� � �����, ������� ���������� ���������: \n");
    if (result < 0)
    {
        printf("\n��������� ������ ��� ������ ���������.\n");
        return 11;
    }
    result = scanf("%[^\n]s", &way2);
    if (result < 1)
    {
        printf("\n��������� ������ ��� ���������� ���� � �����.\n");
        return 12;
    }
    prove = FileFormat(&FFS, way2, sign, &shift);
    if (prove != 0)
    {
            if (prove == 1)
            {
                printf("\n��������� ������ ��� �������� ��������� �� ����������� ���� � ������� FileFormat.\n");
                return 13;
            }
            else if (prove == 2)
            {
                printf("\n��������� ������ ��� �������� ���� � ������������ ����� � ������� FileFormat.\n");
                return 14;
            }
            else if (prove == 3)
            {
                printf("\n��������� ������ ��� �������� ������� ��� �������� ��������� �� ������������ ���� � ������� FileFormat.\n");
                return 15;
            }
            else if (prove == 4)
            {
                printf("\n��������� ������ ��� �������� ���������� ��� �������� �������� � ������� FileFormat.\n");
                return 16;
            }
            else if (prove == 5)
            {
                printf("\n��������� ������ ��� �������� ������������ �����.\n");
                return 17;
            }
            else if (prove == 6)
            {
                printf("\n��������� ������ ��� ���������� ���� ������ ������ �� ������������ �����.\n");
                return 18;
            }
            else if (prove == 7)
            {
                printf("\n��������� ������ ��� ������ ��������� (������� FileFormat).\n");
                return 19;
            }
            else if (prove == 8)
            {
                printf("\n��������� ������ ��� �������� ������������ ����� (������� FileFormat).\n");
                return 20;
            }
            else if (prove == 9)
            {
                printf("\n��������� ������ ��� �������� ������������ ����� � ������� FileScanning.\n");
                return 21;
            }
            else if (prove == 10)
            {
                printf("\n��������� ������ ��� �������� ������� ��� �������� ��������� �� ������������ ���� � ������� FileScanning.\n");
                return 22;
            }
            else if (prove == 11)
            {
                printf("\n��������� ������ ��� �������� ���������� ��� �������� �������� � ������� FileScanning.\n");
                return 23;
            }
            else if (prove == 12)
            {
                printf("\n��������� ������ ��� �������� ���� � ������������ ����� � ������� FileScanning.\n");
                return 24;
            }
            else if (prove == 13)
            {
                printf("\n��������� ������ ��� ��������� ��������� ��������� � ����������� ����� �� "
                       "��������� ����.\n");
                return 25;
            }
            else if (prove == 14)
            {
                printf("\n��������� ������ ��� ������ �������� ���������� ����� �� ������������ �����.\n");
                return 26;
            }
            else if (prove == 15)
            {
                printf("\n��������� ������ ��� ������ ���������(������� FileScanning).\n");
                return 27;
            }
            else if (prove == 16)
            {
                printf("\n��������� ������ ��� ��������� ��������� ��������� � ����������� ����� �� "
                       "��������� ��������.\n");
                return 28;
            }
            else if (prove == 17)
            {
                printf("\n��������� ������ ��� ���������� ��������� �� ������������ �����.\n");
                return 29;
            }
            else if (prove == 18)
            {
                printf("\n��������� ������ ��� ������ ��������� (������� FileScanning).\n");
                return 30;
            }
            else if (prove == 19)
            {
                printf("\n��������� ������ ��� ������ ��������� (������� FileScanning).\n");
                return 31;
            }
            else if (prove == 20)
            {
                printf("\n��������� ������ ��� �������� ������������ ����� (������� FileFormat).\n");
                return 32;
            }
    }
    return 0;
}

int GetSignature(FILE ** AB, char w1[], unsigned char sign[], size_t * shift)
{
    if (AB == NULL) return 1;
    if (w1 == NULL) return 2;
    if (sign == NULL) return 3;
    if (shift == NULL) return 4;

    int Res;
    * AB = fopen(w1, "r");
    if (* AB == NULL) return 5;
    Res = fscanf(* AB, "%hhd%hhd%hhd%hhd%hhd%hhd%hhd%hhd%zu",
                 &sign[0], &sign[1], &sign[2], &sign[3], &sign[4], &sign[5], &sign[6], &sign[7], shift);
    if (Res != 9)
    {
        fclose(* AB);
        return 6;
    }
    Res = fclose(*AB);
    if (Res != 0)
    {
        return 7;
    }
    return 0;
}

int FileFormat(FILE ** FFS, char w2[], unsigned char sign[], size_t * shift)
{
    if (FFS == NULL) return 1;
    if (w2 == NULL) return 2;
    if (sign == NULL) return 3;
    if (shift == NULL) return 4;

    int Res;
    unsigned char form[2];
    * FFS = fopen(w2, "rb");
    if (* FFS == NULL) return 5;

    Res = fread(form, sizeof(unsigned char), 2, * FFS);
    if (Res != 2)
    {
        fclose(* FFS);
        return 6;
    }
    if (form[0] != 'M' || form[1] != 'Z')
    {
        Res = printf("\n��� ������, ���� ����.\n");
        if (Res < 0) return 7;
        Res = fclose(* FFS);
        if (Res != 0)
        {
            return 8;
        }
    }
    else {
        Res = FileScanning(FFS, sign, shift, w2);
        if (Res != 0)
        {
            fclose(* FFS);
            return Res + 8;
        }
        Res = fclose(* FFS);
        if (Res != 0)
        {
            return 20;
        }
    }
    return 0;
}

int FileScanning(FILE ** FFS, unsigned char sign[], size_t * shift, char w2[])
{
    if (FFS == NULL) return 1;
    if (sign == NULL) return 2;
    if (shift == NULL) return 3;
    if (w2 == NULL) return 4;

    int Res;
    size_t LastShift;
    unsigned char list[8];

    Res = fseek(* FFS, -1, SEEK_END);
    if (Res != 0)
    {
        fclose(* FFS);
        return 5;
    }
    LastShift = ftell(* FFS);
    if (LastShift == -1L)
    {
        fclose(* FFS);
        return 6;
    }
    if (LastShift - * shift < 7)
    {
        Res = printf("\n���� ����.\n");
        if (Res < 0) return 7;
        return 0;
    }

    Res = fseek(* FFS, * shift, SEEK_SET);
    if (Res != 0)
    {
        fclose(* FFS);
        return 8;
    }
    Res = fread(list, sizeof(unsigned char), 8, * FFS);

    if (Res != 8)
    {
        fclose(* FFS);
        return 9;
    }
    if (memcmp(list, sign, 8) == 0)
    {
        Res = printf("\n��������!������ ���� �������! ��� �����: %s\n", w2);
        if (Res < 0)
        {
            fclose(* FFS);
            return 10;
        }
    }
    else
    {
        Res = printf("\n���� ����.\n");
        if (Res < 0)
        {
            fclose(* FFS);
            return 11;
        }
    }
    return 0;
}
