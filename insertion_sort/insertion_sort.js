/*
    
*/
function insertionSort( array )
{
    for ( let j = 0 ; j < array.length ; ++j)
    {
        key = array[j]
        // Insert array[j] into the sorted sequence array[0..j].

        let i = j - 1 
        while ( i >= 0 && array[i] > key)
        {
            array[i+1] = array[i] 
            i-- 
        }
        array[i+1] = key 
    }
}

function insertionSortGeneric( array, comparator )
{
    for ( let j = 0 ; j < array.length ; ++j)
    {
        key = array[j]
        // Insert array[j] into the sorted sequence array[0..j].

        let i = j - 1 
        while ( i >= 0 && comparator(key, array[i])
        {
            array[i+1] = array[i] 
            i-- 
        }
        array[i+1] = key 
    }
}

function main()
{

}