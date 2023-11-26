class Heap{

    constructor() {
        this.heap = [];
    }

    heapify(arr) {
        for (ele in arr) {
            this.insert(ele);
        }
    }

    insert(val) {
        this.heap.push(val);
        this.bubbleUp(this.heap.length - 1);
    }

    bubbleUp(index) {
        while (this.hasParent(index) && this.getParent(index) > this.heap[index]) {
            this.swap(this.getParentIndex(index), index);
            index = this.getParentIndex(index);
        }
    }

    remove() {
        if (this.heap.length == 0) return null;
        const val = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return val;
    }

    bubbleDown(index) {
        while (this.hasLeftChild(index)) {

            let smallerChild = this.getLeftChildIndex(index);

            if (this.hasRightChild(index) && this.getRightChild(index) < this.getLeftChild(index)) {
                smallerChild = this.getRightChildIndex(index);
            }

            if (this.heap[index] < this.heap[smallerChild]) break;

            this.swap(index, smallerChild);
            index = smallerChild;
        }
    }

    swap(idx1, idx2) { 
        [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
    }

    peek() {
        if (this.heap.length == 0) return null;
        return this.heap[0];
    }

    getParentIndex(index) {
        return Math.floor((index - 1) / 2);
    }

    getLeftChildIndex(index) {
        return index * 2 + 1;
    }

    getRightChildIndex(index) {
        return index * 2 + 2;
    }

    hasLeftChild(index) {
        return this.getLeftChildIndex(index) < this.heap.length;
    }

    hasRightChild(index) {
        return this.getRightChildIndex(index) < this.heap.length;
    }

    hasParent(index) {
        return this.getParentIndex(index) >= 0;
    }

    getLeftChild(index) {
        return this.heap[this.getLeftChildIndex(index)];
    }

    getRightChild(index) {
        return this.heap[this.getRightChildIndex(index)];
    }

    getParent(index) {
        return this.heap[this.getParentIndex(index)];
    }

    printHeap(){
        console.log(this.heap);
    }
}

let heap = new Heap();

heap.insert(5);
heap.insert(3);
heap.insert(2);
heap.insert(4);
heap.insert(1);
heap.insert(6);
heap.insert(7);

heap.printHeap();

console.log("now lets see sorting");

for (let i = 0; i < 7; i++) {
    console.log(heap.peek());
    heap.remove();
}

