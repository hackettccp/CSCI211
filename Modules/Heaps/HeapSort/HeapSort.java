package HeapSort;

import GenericHeap.Heap;
import GenericHeap.HeapObject;
import MinHeap.MinHeap;

public class HeapSort {

    public static void main(String[] args) {
        HeapObject[] objects = new HeapObject[10];
        objects[0] = new HeapObject(3);
        objects[1] = new HeapObject(2);
        objects[2] = new HeapObject(9);
        objects[3] = new HeapObject(4);
        objects[4] = new HeapObject(7);
        objects[5] = new HeapObject(8);
        objects[6] = new HeapObject(10);
        objects[7] = new HeapObject(5);
        objects[8] = new HeapObject(1);
        objects[9] = new HeapObject(6);

        //Unsorted
        for(HeapObject x : objects) {
            System.out.print(x.getData() + " ");
        }
        System.out.println();


        Heap heap = new MinHeap(16);

        //Add all objects from array to heap
        for(int i = 0; i < objects.length; i++) {
            heap.add(objects[i]);
        }

        //Remove all objects from heap and put them in the array
        for(int i = 0; i < objects.length; i++) {
            try {
                objects[i] = heap.remove();
            } catch(Exception e) {
                //Do nothing
            }
        }

        //Sorted
        for(HeapObject x : objects) {
            System.out.print(x.getData() + " ");
        }
        System.out.println();

    }

}
