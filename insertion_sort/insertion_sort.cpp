#include<vector>
#include<chrono>
#include<algorithm>
#include<iostream>
#include<iomanip>

/*
    Basic Version Of Insertion Sort 
*/
void insertion_sort( std::vector<long>& array )
{
    for ( long j = 1 ; j < array.size() ; ++j)
    {
        long key = array[j] ;

        // Insert array[j] into the sorted sequence array[0..j].
        long i = j - 1 ;
        while ( i >= 0 && array[i] > key)
        {
            array[i+1] = array[i] ;
            i-- ;
        }
        array[i + 1 ] = key ;

    }
}


/*
    Generic Version of Insertion Sort 
*/

template<typename T, typename Functor>
void insertion_sort_generic( std::vector<T> & array, Functor comparator)
{
    for ( long j = 1 ; j < array.size() ; ++j)
    {
        T key = array[j] ;

        // Insert array[j] into the sorted sequence array[0..j].
        long i = j - 1 ;
        while ( i >= 0 && comparator(key,array[i]))
        {
            array[i+1] = array[i] ;
            i-- ;
        }
        array[i + 1 ] = key ;
    }
}

int main()
{
    std::vector<long> counts = {10, 100, 1000, 10000, 100000} ;
    std::vector<double> basic_times(5, 0) ;
    std::vector<double> generic_times(5, 0) ;

    for ( auto count : counts)
    {
        std::vector<long>target(count);
        for ( long j = 0 ; j < count ; ++j)
        {
            target[j] = (count - j) ;
        }
        auto start = std::chrono::system_clock::now();
        insertion_sort(target);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        basic_times.push_back(elapsed_seconds.count());

        std::vector<std::string>target2(count) ;
        
        std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

        for ( long j = 0 ; j < count ; ++j)
        {
            target2[count-j-1] = std::string(s) ;
            if(!next_permutation(s.begin(), s.end())){
                s = "abcdefghijklmnopqrstuvxyz" ;
            }
        }

        start = std::chrono::system_clock::now();
        //insertion_sort_generic(target2, [](const std::string& a, const std::string& b ){ return a < b; }  );
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        generic_times.push_back(elapsed_seconds.count()) ;
    }

    std::cout<<"Analysis of Insertion Sort                 " ;
    std::cout<<"\n----------------------------------------------------\n" ;

    std::cout<<std::setw(10)<<"n"<<std::setw(20)<<"Integers(secs)"<<std::setw(20)<<"String(secs)"<<std::endl ;
    std::cout<<"------------------------------------------------------\n" ;
    
    for ( long i = 0 ; i < counts.size() ; ++i)
    { 
        std::cout<<std::setw(10)<<counts[i]<<std::setw(20)<<basic_times[i]<<std::setw(20)<<generic_times[i]<<std::endl ;
    }

    return 0;
}