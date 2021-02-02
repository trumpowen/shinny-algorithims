#include <stdlib.h>

void merge (long * array, size_t start, size_t divider, size_t end )
{
    size_t firstPart = divider - start + 1;
    size_t secondPart = end - divider  ; 

    long * array_1 = malloc(sizeof(long) * firstPart) ;
    long * array_2 = malloc(sizeof(long) * secondPart) ;

    for ( size_t i = 0 ; i < firstPart; ++i)
    {
        array_1[i] = array[start + i] ;
    }   
    for ( size_t i = 0 ; i < secondPart; ++i)
    {
        array_2[i] = array[divider+1+i] ;
    }
    
    size_t i = 0 ;
    size_t j = 0 ; 
    
    for (size_t k = start ; k <= end ; ++k ) 
    {
        if ( i == firstPart)
        {
            array[k] = array_2[j] ;
            j += 1 ;
            continue ;
        }
        if ( j == secondPart )
        {
            array[k] = array_1[i] ;
            i += 1 ;
            continue ;
        }
        if (array_1[i] <= array_2[j] )
        {
            array[k] = array_1[i] ;
            i += 1 ; 
        }
        else 
        {
            array[k] = array_2[j] ;
            j += 1 ;
        }
    }

    free(array_1) ;
    free(array_2) ;
}


void merge_sort(long * array, size_t start, size_t end )
{
    size_t divider = ( start + end ) / 2;
    if (start < end)
    {
        merge_sort(array, start, divider) ;
        merge_sort(array, divider, end) ;
    }
    merge(array, start, divider, end) ;
}

int main(int argc, char** argv)
{
    long array[] = { 4,1} ;
    merge_sort(array, 0, 3) ;
}
