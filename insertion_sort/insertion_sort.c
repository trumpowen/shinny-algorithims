#include<stdlib.h>
#include<time.h>
#include <assert.h>
#include<string.h>
#include<stdio.h>

#define COUNT_LEN 5

/*
    Basic Version Of Insertion Sort 
    
    The function sorts a set of integers in increasing order 
    array
*/
void insertion_sort( long* array, long len )
{
    for ( long j = 1 ; j < len  ; ++j)
    {    
        long key = array[j] ;

        // Insert array[j] into the sorted sequence array[0..j].
        long i = j - 1 ; 
        while ( i >= 0 && array[i] > key )
        {
            array[i + 1] = array[i] ;
            --i  ;
        }
        array[i + 1] = key ; 
    }
}

/*
    Generic Version of Insertion Sort 
    
    The function sorts a set of data using the comparator function provided 
    by the user. 

*/
void insertion_sort_generic( void ** array, long len , int (*comparator)(void* , void*))
{
    for ( long j = 1 ; j < len  ; ++j)
    {    
        void* key = array[j] ;

        // Insert array[j] into the sorted sequence array[0..j].
        long i = j - 1 ; 
        while ( i >= 0 && comparator(key, array[i]) )
        {
            array[i + 1] = array[i] ;
            --i  ;
        }
        array[i + 1] = key ; 
    }    
}


// helper functions 

int comparator ( void* a, void* b)
{
    return strcmp(a, b) < 0  ;
}

char* string_add_helper(char* string, long pos)
{
    if (pos < 0)
    {
        return string ;
    }
    if ( string[pos] == 'Z')
    {
        string[pos] = 'A';
        return string_add_helper(string , pos-1) ;
    }
    string[pos] = string[pos] + 1 ;
    return string ;
}

char* string_adder(char* string, long count)
{
    while (count--)
        string = string_add_helper(string, strlen(string)-1) ;

    return string ;
}

int main(void)
{
    long counts[COUNT_LEN] = {10, 100, 1000, 10000, 100000} ;
    double basic_times[COUNT_LEN] ;
    double generic_times[COUNT_LEN] = {} ;

    for (long i = 0 ; i < COUNT_LEN ; ++i)
    {
        printf("Sorting .... %10ld numbers\f", counts[i]) ;
        long * targets = calloc(counts[i], sizeof(long)) ;
        assert(targets != NULL) ;
        // producing completely reversed integers 
        for ( long j = counts[i], k = 0 ; j ; --j, k++)
        {
            targets[k] = j ; 
        }
        
        time_t start_time = time(NULL) ;
        insertion_sort(targets, counts[i]) ;
        time_t end_time = time(NULL) ;

        basic_times[i] = end_time - start_time ;

    }
    for (long i = 0 ; i < COUNT_LEN ; ++i)
    {
        char ** targets = calloc(counts[i], sizeof(char*)) ;
        assert(targets != NULL) ;

        // producing completely reversed strings
        char* s = strcpy(malloc(32), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        for ( long j = counts[i], k = 0 ; j ; --j, k++)
        {
            strcpy(s, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") ;
            targets[j-1] = strcpy(malloc(32), string_adder(s, k) );
        }
        
        time_t start_time = time(NULL) ;
        insertion_sort_generic((void**)targets, counts[i], comparator) ;
        time_t end_time = time(NULL) ;

        generic_times[i] = difftime(end_time, start_time) ;

        // free memory
        for (long j = counts[0] ; j ; --j)
            free(targets[j-1]);
        free(targets);
        free(s) ;

    }
    
    printf("Analysis of Insertion Sort                 ") ;
    printf("\n----------------------------------------------------\n") ;

    printf("%-10s %-20s %-20s\n", " n" , "Integers(secs)", "Strings(secs)") ;
    printf("------------------------------------------------------\n") ;
    
    for ( long i = 0 ; i < COUNT_LEN ; ++i)
    {
        printf(" %-10ld %-20.2f %-20.2f \n", 
                    counts[i], basic_times[i], generic_times[i]) ;
    }

    return 0;
}
