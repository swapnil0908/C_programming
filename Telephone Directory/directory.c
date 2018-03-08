#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>

char ch, file_name[25],*path, name3[50], name2[50], name1[50], *fname, *lname, *f1name, *l1name, *Phone_number, *f2name, *l2name;
int j, k, n, rand1, phonebook_size, flag4, start=0, end=0, flag9 = 0, i=0, count=0, flag4=0, flag5=0;

typedef struct PhoneBook
{
    int num;
    char FirstName[50];
    char LastName[50];
    char PhoneNumber[50];
}phone;

phone phonebook[10000];
phone temp1[10000], temp2[10000], temp3[10000], temp4[10000], temp5[10000], temp6[10000], temp7[10000], temp8[10000], temp9[10000], temp10[10000], pivot[10000];

void sortDirectory(phone phonebook[], int l, int r);
void merge(phone phonebook[], int l, int m, int r);
void quickSort(phone phonebook[], int l, int r);
int partition (phone phonebook[], int l, int r);
void insertEntry(char *name, char *Phone_number);
void lower(phone temp3[], int median, char *lname, char *fname);
void upper(phone temp3[], int median1, char *lname, char *fname, int a);
void deleteEntry(char *name);


//DELETE FUNCTION
void deleteEntry(char *name){

    int j, count = 0 ,flag8=0;
    f2name = strtok(name, " ");
    l2name = strtok(NULL, ", ");
    if(l2name == NULL){
        printf("PLEASE ENTER THE FULL NAME OF THE CONTACT!\n\n");
        return;
                }
    n = phonebook_size;

    for(i=0;i<n;i++){
      if(strcmp(temp3[i].LastName , l2name) == 0 && strcmp(temp3[i].FirstName , f2name) == 0){
                count++;
                j=i;
    }
}

    if(count > 1){
        if(strcmp(temp3[j].LastName , l2name) == 0){
            if(strcmp(temp3[j].FirstName , f2name) == 0){
                for(i=j;i<n;i++){
                temp3[i] = temp3[i+1];

                }
            }

        }

        phonebook_size=n-1;
}

    else if (count == 1){
        for (i=0;i<n;i++){
            if(strcmp(temp3[i].LastName , l2name) == 0){
                if(strcmp(temp3[i].FirstName , f2name) == 0){
                    for(j=i;j<n;j++){
                    temp3[j] = temp3[j+1];

                }
            }

        }
}
        phonebook_size=n-1;
}

    else if(count == 0){

    printf("\nUNABLE TO FIND RECORD\n");
    flag8 = 1;
}


}

//LOWER BOUND SEARCH FUNTION
void lower(phone temp3[], int median, char *lname, char *fname)
{
    int l = 0, r = median, flag2 = 0, flag4=0;
    median = (l + r)/2;
    while(l <= r && flag2 ==0){
        if(strcmp(temp3[median].LastName, lname) < 0){
                l = median + 1;
        }
        else if(strcmp(temp3[median].LastName, lname)>0) {
                r = median - 1;
        }
        else if(strcmp(temp3[median].LastName, lname)==0){
                flag2 = 1;
                break;
        }
        median = (l+r)/2;
    }

        if(flag2==0){
        return;
    }

    else{
        int c;
        for(i=l;i<=r;i++){
            if(strcmp(temp3[i].FirstName, fname) == 0)
                {
                printf("%d ", temp3[i].num);
                printf("%s ", temp3[i].FirstName);
                printf("%s ", temp3[i].LastName);
                printf("%s \n", temp3[i].PhoneNumber);
                flag4=1;
                }
            }
        }
return;
}

//UPPER BOUND SEARCH FUNCTION
void upper(phone temp3[], int median1, char *lname, char *fname, int a)
{
    int l = median1+1, r = a, flag3 = 0, flag5=0;

    median1 = (l + r)/2;
        while(l <= r && flag3 ==0){

        if(strcmp(temp3[median1].LastName, lname) < 0){
                l = median1 + 1;
        }

        else if(strcmp(temp3[median1].LastName, lname)>0) {
                r = median1 - 1;
        }

        else if(strcmp(temp3[median1].LastName, lname)==0){
                flag3 = 1;
                break;
        }
        median1 = (l+r)/2;
    }

    if(flag3==0){
        return;
    }

    else{
        for(i=l;i<=r;i++){
            if(strcmp(temp3[i].FirstName, fname) == 0)
            {
                printf("%d ", temp3[i].num);
                printf("%s ", temp3[i].FirstName);
                printf("%s ", temp3[i].LastName);
                printf("%s \n", temp3[i].PhoneNumber);
                flag5=1;
            }
        }
 //   if(flag5==0 && flag4 ==0){
//        printf("NAME NOT FOUND!!\n\n");
//    }

        }

}

//SEARCH DIRECTORY FUNCTION
void searchDirectory(char *name1)
{
    int median, median1, l = 0, r = phonebook_size-1, flag = 0, x, flag1 = 0, count = 0;
    fname = strtok(name1, " ");
    lname = strtok(NULL, ", ");
        if(lname == NULL){
                printf("PLEASE ENTER THE FULL NAME OF THE CONTACT!\n\n");
                return;
                    }
    median = (l + r)/2;
    while(l <= r && flag ==0){
        if(strcmp(temp3[median].LastName, lname) < 0){
                l = median + 1;
        }
        else if(strcmp(temp3[median].LastName, lname)>0){
                r = median - 1;
        }
        else if(strcmp(temp3[median].LastName, lname)==0){
                flag = 1;
                break;
        }
        median = (l+r)/2;
    }
    if(flag==0){
        printf("\nNAME NOT FOUND!!\n\n");
    }

    else{
        median1 = median;
        lower(temp3, median, lname, fname);
        upper(temp3, median1, lname, fname, r);
	if (flag4 == 0 && flag5 == 0){
	printf("NAME NOT FOUND\n");
	}
    }
}

//INSERT ENTRY FUNCTION
void insertEntry(char *name, char *Phone_number){
    int i, j, k, flag7=0;
    n = phonebook_size;
    for(i=0;i<n;i++){
        if (strcmp(temp3[i].LastName, temp5[0].LastName)==0 && strcmp(temp3[i].FirstName, temp5[0].FirstName)==0 && (strcmp(temp3[i].PhoneNumber, temp5[0].PhoneNumber)==0 || strcmp(temp3[i].PhoneNumber, temp5[0].PhoneNumber)==-10 || strcmp(temp3[i].PhoneNumber, temp5[0].PhoneNumber)==10)){
        printf("\nRECORD ALREADY EXISTS!!\n\n");
        flag7=1;
        }
    }


if (flag7 != 1){
    phonebook_size = n+1;
    temp5[0].num = n+1;
    temp3[n] = temp5[0];


sortDirectory(temp3, 0, phonebook_size-1);

    i=0,start=0, end=0;
    while(i<phonebook_size){
        if(strcmp(temp3[i].LastName, temp3[i+1].LastName)==0 && strcmp(temp3[i].FirstName, temp3[i+1].FirstName)==0){
            start = i;
            while(strcmp(temp3[i].LastName, temp3[i+1].LastName)==0 && strcmp(temp3[i].FirstName, temp3[i+1].FirstName)==0){
                i++;
                    }
                end = i;
                quickSort(temp3, start, end);
                i = phonebook_size + 1;
                    }

                    else{

                        i++;
                        end = i;
                    }

                    i = end;

                }


    for(i=0;i<n+1;i++){
                temp3[i].num = i+1;

            }

        }
    }


int partition_r(phone phonebook[], int l, int r){
    srand(time(NULL));
    int random;
    random = l + rand()%(r-l);
    temp8[0] = phonebook[random];
    phonebook[random] = phonebook[r];
    phonebook[r] = temp8[0];
    return partition(phonebook, l, r);
}

//RANDOMIZE THE PIVOT
int partition (phone phonebook[], int l, int r){
    pivot[0] = phonebook[r];
    i= l - 1;
    for(j=l;j<=r-1;j++)
    {
        if(strcmp(phonebook[j].PhoneNumber, pivot[0].PhoneNumber) <= 0){
            i++;
            temp9[0] = phonebook[i];
            phonebook[i] = phonebook[j];
            phonebook[j] = temp9[0];
        }
    }
    temp10[0] = phonebook[i+1];
    phonebook[i+1] = phonebook[r];
    phonebook[r] = temp10[0];
    return i+1;
}

//QUICK SORT FUNCTION
void quickSort(phone phonebook[], int l, int r){
    int index;
    if( l < r ){
        index = partition_r(phonebook, l, r);
        quickSort(phonebook, l, index-1);
        quickSort(phonebook, index+1, r);
    }
}

//MERGE FUNCTION FOR MERGE SORT
void merge(phone phonebook[], int l, int m, int r)
{
    int L= m-l+1;
    int R= r-m;
    int i;
    for(i=0;i<L;i++)
    {
        temp1[i] = phonebook[l+i];
    }
    for(i=0;i<R;i++)
    {
        temp2[i] = phonebook[m+i+1];
    }

    int j=0,k;
    i=0;
    k=l;
    while(i<L&&j<R)
    {
        if(strcmp(temp1[i].LastName,temp2[j].LastName)<0) phonebook[k++] = temp1[i++];
        else if(strcmp(temp1[i].LastName,temp2[j].LastName)==0 && strcmp(temp1[i].FirstName,temp2[j].FirstName)<0) {
        phonebook[k++] = temp1[i++];
        }
        else phonebook[k++] = temp2[j++];
    }
    while(i<L) phonebook[k++] = temp1[i++];
    while(j<R) phonebook[k++] = temp2[j++];

}

//MERGE SORT FUNCTION
void sortDirectory(phone phonebook[], int l, int r){
    if (l < r)
    {
        int m = (l+r)/2;
        sortDirectory(phonebook, l, m);
        sortDirectory(phonebook, m+1, r);
        merge(phonebook, l, m, r);
    }

}

//READ INPUT FILE AND CREATE A DIRECTORY
void create (char *path)
{
   FILE *fp;
   char *num, *first, *last, *pnum;
   fp = fopen(path,"r");
   if( fp == NULL)
   {
      perror("ERROR WHILE OPENING THE FILE...!!!\n");
      exit(EXIT_FAILURE);
   }
    char line[100];
    while (fgets(line, 100, (FILE*)fp))
    {
        num = strtok(line, " ");
        first = strtok(NULL, ", ");
        last = strtok(NULL, ", ");
        pnum = strtok(NULL, ", ");

        phonebook[i].num = atoi(num);
        strcpy(phonebook[i].FirstName, first);
        strcpy(phonebook[i].LastName, last);
        strcpy(phonebook[i].PhoneNumber, pnum);

        i++;
    }

    fclose(fp);

    phonebook_size = i;

    int temp_1, count1=1;

    sortDirectory(phonebook, 0, phonebook_size-1);

    i=0, start=0, end=0, flag9 = 0;
    while(i<phonebook_size)
    {
        if(strcmp(phonebook[i].LastName, phonebook[i+1].LastName)==0 && strcmp(phonebook[i].FirstName, phonebook[i+1].FirstName)==0){
            start = i;
            while(strcmp(phonebook[i].LastName, phonebook[i+1].LastName)==0 && strcmp(phonebook[i].FirstName, phonebook[i+1].FirstName)==0){
                i++;
                    }
                end = i;
                quickSort(phonebook, start, end);
                i = phonebook_size + 1;
                    }
            else{

                i++;
                end = i;
                    }
                i = end;
                }

    for(i=0;i<phonebook_size;i++)
                {
                phonebook[i].num = i+1;
                temp3[i]=phonebook[i];
                }

}



int main(int argc, char * argv[]) {
    int s=1;
    path = argv[1];
    create(path);
    while (s!=0) {
        int choice = 0;
        printf("\n\nPlease provide options: \n");
        printf("Insert\t\t(Press 1)\nSearch\t\t(Press 2)\nDelete\t\t(Press 3)\nShow Directory\t(Press 4)\nExit\t\t(Press 5)\n");
        printf("\n");
        scanf("%d",&choice);

        switch(choice){
           case 1:
                {
                    char name2[50];
                    printf("\nPLEASE ENTER THE FULL NAME AND NUMBER OF THE CONTACT YOU WANT TO INSERT:\n");
                    scanf(" %[^\n]s", name2);
                    f1name = strtok(name2, " ");
                    l1name = strtok(NULL, ", ");
                    Phone_number = strtok(NULL, ", ");
                    if(l1name == NULL || Phone_number == NULL){
                        printf("\nPLEASE ENTER THE FULL NAME AND NUMBER OF THE CONTACT!\n");
                        break;
                    }
                    strcpy(temp5[0].LastName, l1name);
                    strcpy(temp5[0].FirstName, f1name);
                    strcpy(temp5[0].PhoneNumber, Phone_number);
                    insertEntry(name2, Phone_number);
                    break;

                }
             case 2:
                {
                    char name1[50];
                    printf("\nPLEASE ENTER THE FULL NAME YOU WANT TO SEARCH:\n");
                    scanf(" %[^\n]s", name1);
                    searchDirectory(name1);
                    break;
                }
            case 3:
                {
                    char name3[50];
                    printf("\nPLEASE ENTER THE NAME YOU WANT TO DELETE:\n");
                    scanf(" %[^\n]s", name3);
                    deleteEntry(name3);
                    printf("\nTOTAL NUMBER OF RECORDS:%d\n\n",phonebook_size);
                    break;

                }
            case 4:
                {
                printf("\n");
                for(i=0;i<phonebook_size;i++)
                {
                temp3[i].num = i+1;
                printf("%d ", temp3[i].num);
                printf("%s ", temp3[i].FirstName);
                printf("%s ", temp3[i].LastName);
                printf("%s\n", temp3[i].PhoneNumber);

                }
            }
            break;

            case 5:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("INVALID CHOICE!\n");
                break;
            }

        }

    }
return 0;
}
