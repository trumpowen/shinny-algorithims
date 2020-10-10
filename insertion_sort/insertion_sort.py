import time 
import itertools 

def insertion_sort( array: list):
    for j in range( 1, len(array)):
        key = array[j]
        # Insert array[j] into the sorted sequence array[0..j]. 
        i = j  - 1 
        while i >= 0 and array[i] > key :
            array[i+1] = array[i] 
            i -= 1 
        array[i+1] = key 


def insertion_sort_generic( array : list , comparator):
    for j in range( 1, len(array)):
        key = array[j]
        # Insert array[j] into the sorted sequence array[0..j]. 
        i = j  - 1 
        while i >= 0 and comparator(key, array[i]) :
            array[i+1] = array[i] 
            i -= 1 
        array[i+1] = key 

if __name__ == '__main__':

    counts = [10, 100, 1000, 10_000, 100_000, 1_000_000]
    
    basic_times = []
    generic_times = [] 

    # sorting integers in worst case scenarios 
    for count in counts :
        target = [ count - i for i in range(0, count) ]
        print(f"Sorting ..... {count: 10} numbers ", end="\r")
        start = time.time() 
        insertion_sort(target) 
        end = time.time() 
        diff = end - start 
        basic_times.append(round(diff, 3))

        #ensure that it is really sorted 
        for i in range (1, count):
            assert(target[i-1] <= target[i])
        
    # sorting strings in worst case scenarios 
    data = "".join(reversed("ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
    for count in counts:
        target = []
        p = itertools.permutations(data)
        while count:
            target.append("".join(next(p)))
            count -= 1  

        print(f"Sorting ..... {len(target): 10} strings ", end="\r")
        start = time.time() 
        insertion_sort_generic(target, lambda a,b : a < b)
        end = time.time() 
        diff = end - start 
        generic_times.append(round(diff, 3))

        #ensure that it is really sorted 
        for i in range (1, count):
            assert(target[i-1] <= target[i])

    display  = "%s%-10s %-20s %-20s\n" % (" ","n", "Integers(secs)", "Strings(secs)") + \
                     "------------------------------------------------\n"+ \
                    "\n".join(
                        f" {a[0]:<10} {a[1]:<20} {a[2]:<20}" 
                        for a in zip(counts, basic_times, generic_times))
    
    print(display)

 