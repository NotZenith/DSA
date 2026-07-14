#include<stdio.h>
#define SIZE 10

int hashTable[SIZE];


void initialize();
int hash(int key);

int linearProbe(int index);
void insert(int key);

void display();

int quadraticProbe(int index, int i);
void quadraticInsert(int key);

void initialize(){
    int i;
    for(i = 0; i < SIZE; i++){
        hashTable[i] = -1;
    }
}

int hash(int key){
    return key%SIZE;
}

int linearProbe(int index){
    return(index+1) % SIZE;
}

void insert(int key){
    int index;
    index = hash(key);
    while(hashTable[index] != -1){
        index = linearProbe(index);
    }
    hashTable[index] = key;
}
    
int quadraticProbe(int index, int i){
    return(index + i*i)% SIZE;
}

void quadraticInsert(int key){
    int index, i = 1;
    index = hash(key);

    while(hashTable[index] != -1){
        index = hash(key);
        i++;
    }
    hashTable[index] = key;
}



void display(){
    int i;
    printf("\nIn hash table\n");
    for(i = 0; i<SIZE; i++){
        if(hashTable[i] == -1){
            printf("\nIn slot %d = empty", i);
        }
        else{
            printf("\nIn slot %d : %d", i, hashTable[i]);
        }
    }
}





int main(){
    int choice;
    printf("\n1: Linear Probing.\n2: Quadratic Probing.\n3: Terminate the program. \n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            int n, key, i;
            initialize();

            printf("Enter no. of Elements: ");
            scanf("%d",&n);

            printf("\nEnter Elements:");

            for(i = 0;i <n; i++){
                scanf("%d",&key);
                insert(key);
            }

            display();
            break;

        case 2:
            int n2, key2, i2;

            initialize();

            printf("Enter no, of Elements: ");
            scanf("%d",&n2);

            for(i2 = 0; i2 < n2; i2++){
                printf("\nEnter elements: ");
                scanf("%d", &key2);
                quadraticInsert(key2);
            }

            display();
            printf("\nProgram terminated.\n");
            break;

        case 3:
            break;
        
        default:
            printf("Invalid input, please try again.");
    }
}