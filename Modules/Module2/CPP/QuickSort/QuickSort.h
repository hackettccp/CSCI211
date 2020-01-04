/**
 * Quicksort Algorithm 
 */
void quicksort(int array[], int start, int end) {
    int lower = start;                                //Index for inserting in the lower partition
    int upper = end;                                  //Index for inserting in the upper partition
    int temp;                                         //Used when swapping values
    int pivot = array[(lower + upper) / 2];           //Uses the middle element as the pivot value

    //Partitioning
    //Moves numbers less than the pivot to the lower partition, numbers greater than to the pivot to the upper partition
    while(lower <= upper) {
        while(array[lower] < pivot) {
            lower++;                                  //Increment the lower insert index as long as values are less than the pivot value
        }
        while(array[upper] > pivot) {
            upper--;                                  //Decrement the upper insert index as long as values are greater than the pivot value
        }
        if(lower <= upper) {
            //Swap the elements at index "lower" and index "upper" (the indexes where the above while loops needed to stop)                                    
            temp = array[lower];
            array[lower] = array[upper];
            array[upper] = temp;
            lower++;                                  //Increment the lower insert index
            upper--;                                  //Decrement the upper insert index 
        }
    }

    //Recursively partition the lower and upper partitions
    if(start < upper) {
        quicksort(array, start, upper);               //Lower partition (Start index through where upper left off)
    }
    if(lower < end) {
        quicksort(array, lower, end);                 //Upper partition (Where lower left off through the ending index)
    }
}