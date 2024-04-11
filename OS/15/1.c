#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char filename[20];
    int filesize;
    int startblock;
    int endblock;
};
typedef struct file File;

struct node {
    int blockno;
    struct node *next;
};
typedef struct node Block;

Block *freelist = NULL, *allocate = NULL, *lasta = NULL;
File files[20];
int no = 1, d, count = 0;

Block *getblock() {
    Block *temp = (Block *)malloc(sizeof(Block));
    temp->blockno = no++;
    temp->next = NULL;
    return temp;
}

Block *create(int num_blocks) {
    Block *temp, *last = NULL, *list = NULL;
    for (int i = 0; i < num_blocks; i++) {
        temp = getblock();
        if (list == NULL) {
            list = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    return list;
}

Block *create_alloc_list(int file_size) {
    Block *temp, *ptr = freelist;
    Block *prev = NULL;
    int count_blocks = 0;
    files[count].startblock = ptr->blockno;

    while (ptr != NULL && count_blocks < file_size) {
        temp = (Block *)malloc(sizeof(Block));
        temp->blockno = ptr->blockno;
        temp->next = NULL;
        files[count].endblock = temp->blockno;

        if (allocate == NULL) {
            allocate = temp;
            lasta = temp;
        } else {
            lasta->next = temp;
            lasta = temp;
        }

        if (prev == NULL) {
            freelist = ptr->next;
            free(ptr);
            ptr = freelist;
        } else {
            prev->next = ptr->next;
            free(ptr);
            ptr = prev->next;
        }

        prev = ptr;
        count_blocks++;
    }

    return allocate;
}

void accept_file() {
    printf("\nEnter the file name: ");
    scanf("%s", files[count].filename);
    printf("Enter file size in blocks: ");
    scanf("%d", &files[count].filesize);
}

void display_files() {
    printf("\nFile name\t\tFile size\t\tStart block\t\tEnd block\n");
    for (int i = 0; i <= count; i++) {
        printf("%s\t\t\t%d\t\t\t%d\t\t\t%d\n", files[i].filename, files[i].filesize, files[i].startblock, files[i].endblock);
    }
}

void display_list(Block *list) {
    while (list != NULL) {
        printf("%d -> ", list->blockno);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;

    printf("\nEnter the size of disk in blocks: ");
    scanf("%d", &d);
    freelist = create(d);

    while (1) {
        printf("\n1: Allocate space for a new file.");
        printf("\n2: Show used and free space on disk.");
        printf("\n3: Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                accept_file();
                if (count >= 20) {
                    printf("Cannot create more files. File limit reached.\n");
                    break;
                }
                if (count + files[count].filesize > d) {
                    printf("Insufficient space on disk to allocate the file.\n");
                    break;
                }
                create_alloc_list(files[count].filesize);
                display_files();
                count++;
                break;

            case 2:
                printf("\nFree list: ");
                display_list(freelist);
                printf("Allocated list: ");
                display_list(allocate);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
