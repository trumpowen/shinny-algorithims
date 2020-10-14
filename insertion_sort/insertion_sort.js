/*
    Basic Version Of Insertion Sort 
*/
function insertionSort(array) {
    for (let j = 0; j < array.length; ++j) {
        key = array[j]
            // Insert array[j] into the sorted sequence array[0..j].

        let i = j - 1
        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i]
            i--
        }
        array[i + 1] = key
    }
}

/*
    Generic Version Of Insertion Sort 
*/
function insertionSortGeneric(array, comparator) {
    for (let j = 0; j < array.length; ++j) {
        key = array[j]
            // Insert array[j] into the sorted sequence array[0..j].

        let i = j - 1
        while (i >= 0 && comparator(key, array[i])) {
            array[i + 1] = array[i]
            i--
        }
        array[i + 1] = key
    }
}

function string_add_helper(string, pos) {
    if (pos < 0) {
        return string;
    }
    if (string[pos] == 'Z') {
        string[pos] = 'A';
        return string_add_helper(string, pos - 1);
    }

    let res = String.fromCharCode(string.charCodeAt(pos) + 1);

    string[pos] = string.slice(0, pos) + res + string.slice(pos)
    return string;
}

function string_adder(string, count) {
    while (count--)
        string = string_add_helper(string, string.length - 1);
    return string;
}


function main() {

    const counts = [10, 100, 1000, 10000, 100000];
    const basicTimes = new Array();
    const genericTimes = new Array();

    for (const count of counts) {
        let target = new Array(count)

        for (let j = 0; j < count; ++j) {
            target[j] = count - j;
        }

        console.log(`Sorting ${count} integers \r`)

        const start = new Date()
        insertionSort(target)
        const end = new Date()

        basicTimes.push((start - end) / 1000)

        for (let i = 1; i < target.size(); ++i) {
            if (target[i - 1] > target[i]) {
                throw Error;
            }
        }

        target = new Array(count)

        let s = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

        for (j = count, k = 0; j; --j, k++) {
            targets[j - 1] = string_adder(s, k);
        }

        console.log(`Sorting ${count} strings \r`)

        const start = new Date()
        insertionSortGeneric(target, (a, b) => { return a < b; })
        const end = new Date()

        genericTimes.push((start - end) / 1000)

        console.log("Analysis of Insertion Sort                 ");
        console.log("\n----------------------------------------------------\n");

        console.log(`${n.padStart(10).padEnd(10)} ${Integers(secs).padStart(10).padEnd(10)} ${Strings(secs).padStart(10).padEnd(10)}`);
        console.log("------------------------------------------------------\n");

        for (let i = 0; i < counts.length; ++i) {
            console.log(`${String(counts[i]).padStart(10).padEnd(10)}, \
            ${String(basic_times[i]).padStart(10).padEnd(10)}, \
            ${String(generic_times[i]).padStart(10).padEnd(10)} \n`);
        }
    }
}

main()