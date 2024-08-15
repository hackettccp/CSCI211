package MinHeap;

import GenericHeap.Heap;
import GenericHeap.HeapObject;

public class MinHeap extends Heap {

    /**
     * Constructor
     * @param s - heap size
     */
    public MinHeap(int s) {
        super(s);
    }

    /**
     * Adds an object to the heap
     * @param data
     */
    @Override
    public void add(HeapObject data) {
        if(nextAvail > SIZE - 1) {
            return;                                         //Heap is full
        }
        array[nextAvail] = data;                            //Add the new object to the heap
        int p = getParentIndex(nextAvail);                  //Get this object's parent's index
        int i = nextAvail;                                  //Index to start at
        while(p >= 1) {
            if(array[p].getData() > array[i].getData()) {
                //Parent is larger, so swap the objects
                swap(p, i);
            }
            i = p;                                          //Replace current index with the parent index
            p = getParentIndex(p);                          //Replace parent index with its parent's index
        }
        nextAvail++;
    }

    /**
     * Reorganizes the heap after a removal
     */
    @Override
    protected void fixHeap() {
        int i = 1;                                          //Starts at the root
        HeapObject o = array[1];                            //Gets object at the root
        while(hasChildren(i)) {
            //Get the children
            HeapObject left = array[getLeftChildIndex(i)];
            HeapObject right = array[getRightChildIndex(i)];

            if(left != null) {
                //Has at least a left child
                if(right != null) {
                    //Has both a left and right child
                    if(left.getData() < right.getData()) {
                        //Left child is smallest of the two
                        if(o.getData() > left.getData()) {
                            //If left child is smaller, swap them
                            swap(i, getLeftChildIndex(i));
                            i = getLeftChildIndex(i);
                            continue;
                        }
                        else {
                            //Done promoting children
                            break;
                        }
                    }
                    else {
                        //Right child is smallest of the two
                        if(o.getData() > right.getData()) {
                            //If right child is smaller, swap them
                            swap(i, getRightChildIndex(i));
                            i = getRightChildIndex(i);
                            continue;
                        }
                        else {
                            //Done promoting children
                            break;
                        }
                    }
                }
                else {
                    //If left child is smaller, swap them
                    if(o.getData() > left.getData()) {
                        swap(i, getLeftChildIndex(i));
                        i = getLeftChildIndex(i);
                        continue;
                    }
                    else {
                        //Done promoting children
                        break;
                    }
                }

            }
            else {
                //No children (If no left child, then definitely no right child)
                break;
            }
        }
    }

}
