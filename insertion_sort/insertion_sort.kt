fun insertionSort ( array : Array<Long>): Unit
{
    for ( j in 0..array.size)
    {
        val key = array[j] 
        
        var i = j - 1 
        while ( i >= 0 && array[i] > key )
        {
            array[i + 1] = array[i] 
            i-- 
        }
        array[i + 1] = key 
    }
}

fun <T> insertionSortGeneric ( array : Array<T>, comparator : (a:T, b:T) -> Boolean ) : Unit
{
    for ( j in 0..array.size)
    {
        val key = array[j] 
        
        var i = j - 1 
        while ( i >= 0 && comparator(key, array[i) )
        {
            array[i + 1] = array[i] 
            i-- 
        }
        array[i + 1] = key 
    }
}

fun main()
{
    // sort the following in worst case    
}
