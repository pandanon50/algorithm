class MinHeap {
  constructor() {
    this.heap = [null];
  }
  _swap(a,b) {
    [this.heap[a], this.heap[b]] = [this.heap[b],this.heap[a]];
  }

  size() {
    return this.heap.length - 1;
  }

  _push(value) {
    this.heap.push(value);

    let curIdx = this.size();
    let parentIdx = Math.floor(curIdx / 2);
    while(this.heap[curIdx] < this.heap[parentIdx]) {
      this._swap(curIdx,parentIdx);

      curIdx = parentIdx;
      parentIdx = Math.floor(curIdx / 2);
    }
  }

  _pop() {
    if(!this.size()) {
      return null
    }
    if(this.size() === 1) {
      return this.heap.pop();
    }

    this._swap(1,this.size());
    const value  = this.heap.pop();

    let curIdx = 1;
    let leftChildIdx = curIdx * 2;
    let rightChildIdx = curIdx * 2 + 1;
    while(
      (this.heap[leftChildIdx] && this.heap[curIdx] > this.heap[leftChildIdx]) ||
      (this.heap[rightChildIdx] && this.heap[curIdx] > this.heap[rightChildIdx])) {
        const minIdx = this.heap[rightChildIdx] && this.heap[leftChildIdx] > this.heap[rightChildIdx] ? rightChildIdx : leftChildIdx;
        
        if(this.heap[curIdx] > this.heap[minIdx]) {
          this._swap(curIdx,minIdx);
          curIdx = minIdx;
        }
        leftChildIdx = curIdx * 2;
        rightChildIdx = curIdx * 2 + 1;
      }
      return value
  }
  _top() {
    if(!this.size()) {
      return null;
    }
    return this.heap[1];
  }
}

const pq = new MinHeap();

