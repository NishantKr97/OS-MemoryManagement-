#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocated[m] = {0};
    int sortedblockSize[m] ;

    //New Block size which has to be sorted
    for(int i = 0; i < m; i++)
    {
        sortedblockSize[i] = blockSize[i];
    }

    //Sorting of sortedblockSize[]
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m - i - 1;j++)
        {
            if(sortedblockSize[j] > sortedblockSize[j+1])
            {
                int temp = sortedblockSize[j];
                sortedblockSize[j] = sortedblockSize[j+1];
                sortedblockSize[j+1] = temp;
            }
        }
    }
    //Now we have the sorted array

    int l = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(sortedblockSize[j] > processSize[i] && allocated[j] == 0)
            {
                allocated[j] = processSize[i];
                l = j + 1;
                break;
            }
        }
    }



    printf("Best Fit Allocation : \n");
    for(int i = 0; i < m; i++)
    {
        printf("Memory Block [%d] of size %d - %d\n", i, sortedblockSize[i], allocated[i]);
    }

}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocated[m] = {0};
    int sortedblockSize[m] ;

    //New Block size which has to be sorted
    for(int i = 0; i < m; i++)
    {
        sortedblockSize[i] = blockSize[i];
    }

    //Sorting of sortedblockSize[]
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m - i - 1;j++)
        {
            if(sortedblockSize[j] < sortedblockSize[j+1])
            {
                int temp = sortedblockSize[j];
                sortedblockSize[j] = sortedblockSize[j+1];
                sortedblockSize[j+1] = temp;
            }
        }
    }
    //Now we have the sorted array

    int l = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(sortedblockSize[j] > processSize[i] && allocated[j] == 0)
            {
                allocated[j] = processSize[i];
                l = j + 1;
                break;
            }
        }
    }

    printf("Worst Fit Allocation : \n");
    for(int i = 0; i < m; i++)
    {
        printf("Memory Block [%d] of size %d - %d\n", i, sortedblockSize[i], allocated[i]);
    }

}


void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocated[m] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(blockSize[j] > processSize[i] && allocated[j] == 0)
            {
                allocated[j] = processSize[i];
                break;
            }
        }
    }

    printf("First Fit Allocation : \n");
    for(int i = 0; i < m; i++)
    {
        printf("Memory Block [%d] of size %d - %d\n", i, blockSize[i], allocated[i]);
    }
}

int main()
{
    //Contiguous Memory Allocation

    int blockSize[6] = {50,100,200,150,250,300};
    int processSize[5] = {225, 140, 75, 290, 180};

    int m = 6;
    int n = 5;

    printf("Enter:\n1 for firstFit\n2 for bestFit\n3 for worstFit\n>> ");
    int k;
    scanf("%d",&k);

    switch(k)
    {
        case 1 :firstFit(blockSize, m, processSize, n); 
                break;

        case 2 : bestFit(blockSize, m, processSize, n);
                break;

        case 3 : worstFit(blockSize, m, processSize, n);
                break;

        default : printf("Invalid Input\n");
                break;
    }        


    
    
    
}
