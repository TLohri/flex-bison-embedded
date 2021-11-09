// Mem_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "../flex-bison-poc/memory_management.h"

#include <stdio.h>

#define PAGES 16

#define PAGE_SIZE 512


int errors;

void tryAllocation(int n, int size)
{
    int i;

    unsigned char* char_arrays[PAGES];

    for (i = 0; i < n; i++)
    {
        char_arrays[i] = my_alloc(size);
        if (char_arrays[i] == NULL)
        {
            printf("Allocation %i invalid, NULL\n", i);
            errors++;
        }
        else
        {
            printf("Page %i OK\n", i);
        }
    }

    void* should_be_null = my_alloc(1);

    if (should_be_null != NULL)
    {
        errors++;
        printf("Too much memory allocated\n");
    }
    else
    {
        printf("Memory full, allocation impossible\n");
    }

    printf("Freeing %i Arrays\n", n);

    for (i = 0; i < n; i++)
    {
        my_free(char_arrays[i]);
        printf("Page %i free\n", i);
    }
}



int main()
{
    int errors = 0;

    int error_found = 0;

    printf("Starting Tests\n");
    printf("Allocate all Pages\n");

    unsigned char* char_arrays[PAGES];
    int i,j;

    errors = 0;

    printf("Try allocation\n");

    tryAllocation(PAGES, sizeof(long long) * PAGE_SIZE);
    
    //Check larger Pages

    printf("Check Larger Allocation Sizes \n\n");

    tryAllocation(PAGES/2, sizeof(long long) * PAGE_SIZE * 2);

        //Check small sizes

    printf("Check Smaller Allocation Sizes \n\n");

    tryAllocation(PAGES, 1);

    
    printf("Checking page sizes\n\n");

    for (i = 0; i < PAGES; i++)
    {
        char_arrays[i] = my_alloc(sizeof(char) * PAGE_SIZE * 8);
        if (char_arrays[i] == NULL)
        {
            printf("Allocation %i invalid, NULL\n", i);
            errors++;
        }
        else
        {
            printf("Page %i OK, setting up test data \n", i);
            for (j = 0; j < PAGE_SIZE * 8; j++)
            {
                char_arrays[i][j] = i * 0x11;
            }
        }
    }

    for (i = 0; i < PAGES; i++)
    {
        printf("Checking Page %i\n", i);
        error_found = 0;
        for (j = 0; j < PAGE_SIZE * 8; j++)
        {
            if (char_arrays[i][j] != i * 0x11)
            {
                error_found = 1;
            }
        }
        if (error_found == 1)
        {
            printf("Error detected\n");
            errors++;
        }
        else
        {
            printf("Page %i OK\n", i);
        }
    }
    

    for (i = PAGES - 1; i >= 0; i--)
    {
        for (j = 0; j < PAGE_SIZE * 8; j++)
        {
            char_arrays[i][j] = i * 0x11;
        }
    }

    for (i = PAGES - 1; i >= 0; i--)
    {
        printf("Checking Page %i\n", i);
        error_found = 0;
        for (j = 0; j < PAGE_SIZE * 8; j++)
        {
            if (char_arrays[i][j] != i * 0x11)
            {
                error_found = 1;
            }
        }
        if (error_found == 1)
        {
            printf("Error detected\n");
            errors++;
        }
        else
        {
            printf("Page %i OK\n", i);
        }
    }





    printf("Freeing %i Arrays\n", PAGES);

    for (i = 0; i < PAGES; i++)
    {
        my_free(char_arrays[i]);
        printf("Page %i free\n", i);
    }

    printf("Testing realloc function\n");

    /*
        Page size in bytes = sizeof(char) * PAGE_SIZE * 8
    */

    
    for (i = 0; i < PAGES; i++)
    {
        char_arrays[i] = my_alloc(sizeof(char) * PAGE_SIZE * 8);
        if (char_arrays[i] == NULL)
        {
            printf("Allocation %i invalid, NULL\n", i);
            errors++;
        }
        else
        {
            printf("Page %i OK, setting up test data \n", i);
            for (j = 0; j < PAGE_SIZE * 8; j++)
            {
                char_arrays[i][j] = i * 0x11;
            }
        }
    }

    //free 2 consecutive arrays, realloc other array for 2x size

    my_free(char_arrays[0]);
    my_free(char_arrays[1]);

    char_arrays[3] = my_realloc(char_arrays[3], sizeof(char) * PAGE_SIZE * 8 * 2);

    if (char_arrays[3] == NULL)
    {
        errors++;
        printf("Error detected, reallocation impossible\n");
    }
    else
    {
        printf("Reallocation test succeeded\n");
    }
    for (i = 2; i < PAGES; i++)
    {
        my_free(char_arrays[i]);
    }

    printf("Memory Test complete, %i errors detected", errors);




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
