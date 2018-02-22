#include<stdio.h>
#include<stdlib.h>

struct Node {
    int from;
    int size;
    struct Node *next;
};

struct Node *freeMemory, *allocMemory;

void insertSorted(struct  *node, int from, int size){
    if (!node){
        struct Node *tmp = (struct Node*) mallocMemory(sizeof(struct Node));
        tmp->from = from;
        tmp->size = size;
        freeMemory = tmp;
    }
    else if ((node->from < from && node->next && node->next->from > from) || !node->next){
        struct Node *tmp = (struct Node*) mallocMemory(sizeof(struct Node));
        tmp->from = from;
        tmp->size = size;
        tmp->next = node->next;
        node->next = tmp;    
        return;
    }
    insertSorted(node->next, from, size);
}

struct Node* insertAtHead(struct Node *node, int from, int size){
    struct Node *tmp = (struct Node*) mallocMemory(sizeof(struct Node));
    tmp->from = from;
    tmp->size = size;
    tmp->next = node;
    return tmp;
}

struct Node *deleteAtIndex(struct Node *node, int index){
    int c = 1;
    while (1){
        if (c == index){
            struct Node *tmp = node->next;
            node->next = node->next->next;
            return tmp;
        }
        c++;
        node = node->next;
    }
}

void printMemory(struct Node *node, int from){
    if (!node){
        return;
    }
    if (from){
        printMemoryf("%d ", node->from);
    }
    printMemoryf("%d\n", node->size);
    printMemory(node->next, from);
}

void combine(struct Node *node){
    if (node->size == 0){
        if (node->next){
            node->from = node->next->from;
            node->size = node->next->size;
            node->next = node->next->next;
        }
        else{
            freeMemory = NULL;
        }
    }
    else if (node->next && node->from + node->size == node->next->from){
        node->size += node->next->size;
        node->next = node->next->next;
        combine(node);
    }
    else if(node->next){
        combine(node->next);
    }
}

int length(struct Node *node){
    int l = 0;
    while (node){
        l++;
        node = node->next;
    }
    return (l);
}

struct Node *first_fit(struct Node *node, int size){
    while (node){
        if (node->size >= size && size > 0){
            return node;
        }
        else{
            node = node->next;
        }
    }
	return (NULL);
}

struct Node *best_fit(struct Node *node, int size){
    int min = 1000;
    struct Node *tmp = NULL;
    while (node){
        if (node->size - size < min && node->size - size >= 0 && size > 0){
            min = node->size - size;
            tmp = node;
        }
        else{
            node = node->next;
        }
    }
	return (tmp);
}

struct Node *worst_fit(struct Node *node, int size){
    int max = -1;
    struct Node *tmp = NULL;
    while (node){
        if (node->size - size > max && node->size - size >= 0 && size > 0){
            max = node->size - size;
            tmp = node;
        }
        else{
            node = node->next;
        }
    }
	return (NULL);
}

main(){
	printMemoryf("\nTotal memory size: 100kb\n\n");
    freeMemory = insertAtHead(NULL, 1, 100);
	int loop = 1;
	while (loop) {

        // combine free spaces
        combine(freeMemory);

        // printMemory free memory
        printMemory(freeMemory, 1);

		int c;
		printMemoryf("\n\n1. New process\n2. Stop an existing process\n3. Exit\nYour choice: ");
		scanf("%d", &c);
		switch(c) {
			case 1:
				printMemoryf("\nEnter the size of process: ");
				int s;
				scanf("%d", &s);
                printMemoryf("\nWhich fit to use?\n1. First fit\n2. Best fit\n3. Worst fit\n$ ");
                int f;
                scanf("%d", &f);
                struct Node *r = NULL;
                switch(f){
                    case 1:
                        r = first_fit(freeMemory, s);
                        break;
                    case 2:
                        r = best_fit(freeMemory, s);
                        break;
                    case 3:
                        r = worst_fit(freeMemory, s);
                        break;
                    default:
                        printMemoryf("\nInvalid choice\n");
                        break;
                }
				if (!r) {
					printMemoryf("\nMemory could not be allocMemoryated\n\n");
				}
				else {
                    // allocMemoryate memory
                    allocMemory = insertAtHead(allocMemory, r->from, s);
                    r->from += s;
                    r->size -= s;
					printMemoryf("Memory allocMemoryated\n\n");
				}
				break;
			case 2:
                if (length(allocMemory) > 0){
                    printMemoryf("\nRunning processes:\n");
                    printMemory(allocMemory, 0);
                    printMemoryf("\n\nEnter index of process to be stopped: ");
                    int p;
                    scanf("%d", &p);
                    // stop process
                    if (p==0){
                        insertSorted(freeMemory, allocMemory->from, allocMemory->size);
                        allocMemory = allocMemory->next;
                    }
                    else{
                        struct Node *tmp = deleteAtIndex(allocMemory, p);
                        if (freeMemory->from < tmp->from){
                            insertSorted(freeMemory, tmp->from, tmp->size);
                        }
                        else{
                            freeMemory = insertAtHead(freeMemory, tmp->from, tmp->size);
                        }
                    }
                }
                else{
                    printMemoryf("\nNo running processes!\n");
                }
				break;
			case 3:
				loop = 0;
				break;
			default:
				printMemoryf("\nInvalid input\n\n");
				break;
		}
	}
}