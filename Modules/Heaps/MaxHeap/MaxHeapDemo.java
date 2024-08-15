package MaxHeap;

import GenericHeap.Heap;
import GenericHeap.HeapObject;

public class MaxHeapDemo {

    public static void main(String[] args) {
        Heap heap = new MaxHeap(16);

        heap.add(new HeapObject(3));
        heap.add(new HeapObject(2));
        heap.add(new HeapObject(9));
        heap.add(new HeapObject(4));
        heap.add(new HeapObject(7));
        heap.add(new HeapObject(8));
        heap.add(new HeapObject(10));
        heap.add(new HeapObject(5));
        heap.add(new HeapObject(1));
        heap.add(new HeapObject(6));

        while(!heap.isEmpty()) {
            try {
                System.out.println(heap.remove().getData());
            } catch(Exception e) {
                //Do nothing
            }
        }
    }

}
