import java.util.Date

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
    var counts = IntArrayOf(10, 100, 1000, 10000, 100000, 1000000) 
    val basicTimes : DoubleArray(count.size()) 
    val genericTimes : DoubleArray(count.size())

    for ( count in counts){

        target = Array(count){ count - it } 

        val start = Date() 
        insertionSort(target) 
        val end = Date() 

        for (  i  in 1..count)
            if (target[i] > target[i-1])
                throw Exception()

        
    }   

}
